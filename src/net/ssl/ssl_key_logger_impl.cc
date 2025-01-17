// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "net/ssl/ssl_key_logger_impl.h"

#include <stdio.h>

#include "base/bind.h"
#include "base/files/file_util.h"
#include "base/files/scoped_file.h"
#include "base/location.h"
#include "base/logging.h"
#include "base/macros.h"
#include "base/sequence_checker.h"
#include "base/sequenced_task_runner.h"
#include "base/task/post_task.h"
#include "base/task/task_traits.h"
#include "starboard/types.h"

namespace net {

// An object which lives on the background SequencedTaskRunner and performs the
// blocking file operations.
class SSLKeyLoggerImpl::Core {
 public:
  Core() { DETACH_FROM_SEQUENCE(sequence_checker_); }
  ~Core() { DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_); }

  void OpenFile(const base::FilePath& path) {
    DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
    DCHECK(!file_);
#if defined(STARBOARD)
    file_.reset(
        new starboard::ScopedFile(path.value().c_str(), kSbFileCreateAlways));
#else
    file_.reset(base::OpenFile(path, "a"));
#endif
    if (!file_)
      LOG(WARNING) << "Could not open " << path.value();
  }

  void WriteLine(const std::string& line) {
    DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
    if (!file_)
      return;
#if defined(STARBOARD)
    file_->WriteAll(line.c_str(), line.length());
#else
    fprintf(file_.get(), "%s\n", line.c_str());
    fflush(file_.get());
#endif
  }

 private:
#if defined(STARBOARD)
  std::unique_ptr<starboard::ScopedFile> file_;
#else
  base::ScopedFILE file_;
#endif
  SEQUENCE_CHECKER(sequence_checker_);

  DISALLOW_COPY_AND_ASSIGN(Core);
};

SSLKeyLoggerImpl::SSLKeyLoggerImpl(const base::FilePath& path)
    : core_(new Core) {
  // The user explicitly asked for debugging information, so these tasks block
  // shutdown to avoid dropping some log entries.
  task_runner_ = base::CreateSequencedTaskRunnerWithTraits(
      {base::MayBlock(), base::TaskShutdownBehavior::BLOCK_SHUTDOWN});
  task_runner_->PostTask(
      FROM_HERE,
      base::BindOnce(&Core::OpenFile, base::Unretained(core_.get()), path));
}

SSLKeyLoggerImpl::~SSLKeyLoggerImpl() {
  task_runner_->DeleteSoon(FROM_HERE, core_.release());
}

void SSLKeyLoggerImpl::WriteLine(const std::string& line) {
  task_runner_->PostTask(
      FROM_HERE,
      base::BindOnce(&Core::WriteLine, base::Unretained(core_.get()), line));
}

}  // namespace net
