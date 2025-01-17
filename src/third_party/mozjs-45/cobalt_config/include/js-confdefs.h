/* List of defines generated by configure. Included with preprocessor flag,
 * -include, to avoid long list of -D defines on the compile command-line.
 * Do not edit.
 */

#ifndef _JS_CONFDEFS_H_
#define _JS_CONFDEFS_H_

#include "starboard/configuration.h"

#if SB_HAS(64_BIT_POINTERS)
#define JS_BYTES_PER_WORD 8
#define JS_BITS_PER_WORD_LOG2 6
#else
#define JS_BYTES_PER_WORD 4
#define JS_BITS_PER_WORD_LOG2 5
#endif

#if defined(COBALT_BUILD_TYPE_QA) || defined(COBALT_BUILD_TYPE_GOLD)
#define RELEASE_BUILD 1
#endif

#if defined(COBALT_BUILD_TYPE_DEBUG)
#define DEBUG 1
#define JS_DEBUG 1
#endif

// Disabling this will fall back to js_sb_getenv for locale-
// specific number formatting.
// This can be removed when ENABLE_INTL_API is enabled, which requires a newer
// version of ICU.
#define HAVE_LOCALECONV 1

#define HAVE_VA_COPY 1
#define VA_COPY SB_VA_COPY

#define MOZILLA_UAVERSION "45.0"
#define MOZILLA_VERSION "45.0.2"
#define MOZILLA_VERSION_U 45.0.2
#define MOZJS_MAJOR_VERSION 0
#define MOZJS_MINOR_VERSION 2

// #include "js/RequiredDefines.h"

inline char* js_sb_getenv(const char* name) {
  return nullptr;
}

inline char* js_sb_secure_getenv(const char* name) {
  return nullptr;
}

#endif /* _JS_CONFDEFS_H_ */
