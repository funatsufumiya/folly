#include <stdio.h>
#include <stdlib.h>

extern "C" {

// Stubs for jemalloc/tcmalloc functions referenced by Folly.
// These should _never_ be called if Folly is configured correctly via flags.
// If they are called, it indicates a critical configuration error.

// Indicate noreturn for compilers that support it.
#if defined(__GNUC__) || defined(__clang__)
#define FOLLY_STUB_NORETURN __attribute__((noreturn))
#elif defined(_MSC_VER)
#define FOLLY_STUB_NORETURN __declspec(noreturn)
#else
#define FOLLY_STUB_NORETURN
#endif

static void FOLLY_STUB_NORETURN folly_stub_abort(const char* func_name) {
  fprintf(
      stderr,
      "FATAL ERROR: Folly allocator stub function '%s' was called unexpectedly.\n"
      "This indicates a build configuration mismatch or an issue with Folly's preprocessor guards.\n"
      "Ensure Folly allocator usage is disabled correctly via CMake flags (e.g., FOLLY_HAVE_JEMALLOC=0).\n",
      func_name);
  abort();
}

void* mallocx(size_t size, int flags) {
  (void)size;
  (void)flags;
  folly_stub_abort("mallocx");
}

void* rallocx(void* ptr, size_t size, int flags) {
  (void)ptr;
  (void)size;
  (void)flags;
  folly_stub_abort("rallocx");
}

size_t xallocx(void* ptr, size_t size, size_t extra, int flags) {
  (void)ptr;
  (void)size;
  (void)extra;
  (void)flags;
  folly_stub_abort("xallocx");
}

size_t sallocx(const void* ptr, int flags) {
  (void)ptr;
  (void)flags;
  folly_stub_abort("sallocx");
}

void dallocx(void* ptr, int flags) {
  (void)ptr;
  (void)flags;
  folly_stub_abort("dallocx");
}

void sdallocx(void* ptr, size_t size, int flags) {
  (void)ptr;
  (void)size;
  (void)flags;
  folly_stub_abort("sdallocx");
}

size_t nallocx(size_t size, int flags) {
  (void)size;
  (void)flags;
  folly_stub_abort("nallocx");
}

int mallctl(
    const char* name, void* oldp, size_t* oldlenp, void* newp, size_t newlen) {
  (void)name;
  (void)oldp;
  (void)oldlenp;
  (void)newp;
  (void)newlen;
  folly_stub_abort("mallctl");
}

int mallctlnametomib(const char* name, size_t* mibp, size_t* miblenp) {
  (void)name;
  (void)mibp;
  (void)miblenp;
  folly_stub_abort("mallctlnametomib");
}

int mallctlbymib(
    const size_t* mib,
    size_t miblen,
    void* oldp,
    size_t* oldlenp,
    void* newp,
    size_t newlen) {
  (void)mib;
  (void)miblen;
  (void)oldp;
  (void)oldlenp;
  (void)newp;
  (void)newlen;
  folly_stub_abort("mallctlbymib");
}

int MallocExtension_Internal_GetNumericProperty(
    const char* name, size_t name_len, size_t* value) {
  (void)name;
  (void)name_len;
  (void)value;
  folly_stub_abort("MallocExtension_Internal_GetNumericProperty");
}
}
