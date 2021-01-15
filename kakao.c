#define PY_SSIZE_T_CLEAN
#include "Python.h"
#ifndef Py_PYTHON_H
    #error Python headers needed to compile C extensions, please install development version of Python.
#elif PY_VERSION_HEX < 0x02060000 || (0x03000000 <= PY_VERSION_HEX && PY_VERSION_HEX < 0x03030000)
    #error Cython requires Python 2.6+ or Python 3.3+.
#else
#define CYTHON_ABI "0_29_21"
#define CYTHON_HEX_VERSION 0x001D15F0
#define CYTHON_FUTURE_DIVISION 1
#include <stddef.h>
#ifndef offsetof
  #define offsetof(type, member) ( (size_t) & ((type*)0) -> member )
#endif
#if !defined(WIN32) && !defined(MS_WINDOWS)
  #ifndef __stdcall
    #define __stdcall
  #endif
  #ifndef __cdecl
    #define __cdecl
  #endif
  #ifndef __fastcall
    #define __fastcall
  #endif
#endif
#ifndef DL_IMPORT
  #define DL_IMPORT(t) t
#endif
#ifndef DL_EXPORT
  #define DL_EXPORT(t) t
#endif
#define __PYX_COMMA ,
#ifndef HAVE_LONG_LONG
  #if PY_VERSION_HEX >= 0x02070000
    #define HAVE_LONG_LONG
  #endif
#endif
#ifndef PY_LONG_LONG
  #define PY_LONG_LONG LONG_LONG
#endif
#ifndef Py_HUGE_VAL
  #define Py_HUGE_VAL HUGE_VAL
#endif
#ifdef PYPY_VERSION
  #define CYTHON_COMPILING_IN_PYPY 1
  #define CYTHON_COMPILING_IN_PYSTON 0
  #define CYTHON_COMPILING_IN_CPYTHON 0
  #undef CYTHON_USE_TYPE_SLOTS
  #define CYTHON_USE_TYPE_SLOTS 0
  #undef CYTHON_USE_PYTYPE_LOOKUP
  #define CYTHON_USE_PYTYPE_LOOKUP 0
  #if PY_VERSION_HEX < 0x03050000
    #undef CYTHON_USE_ASYNC_SLOTS
    #define CYTHON_USE_ASYNC_SLOTS 0
  #elif !defined(CYTHON_USE_ASYNC_SLOTS)
    #define CYTHON_USE_ASYNC_SLOTS 1
  #endif
  #undef CYTHON_USE_PYLIST_INTERNALS
  #define CYTHON_USE_PYLIST_INTERNALS 0
  #undef CYTHON_USE_UNICODE_INTERNALS
  #define CYTHON_USE_UNICODE_INTERNALS 0
  #undef CYTHON_USE_UNICODE_WRITER
  #define CYTHON_USE_UNICODE_WRITER 0
  #undef CYTHON_USE_PYLONG_INTERNALS
  #define CYTHON_USE_PYLONG_INTERNALS 0
  #undef CYTHON_AVOID_BORROWED_REFS
  #define CYTHON_AVOID_BORROWED_REFS 1
  #undef CYTHON_ASSUME_SAFE_MACROS
  #define CYTHON_ASSUME_SAFE_MACROS 0
  #undef CYTHON_UNPACK_METHODS
  #define CYTHON_UNPACK_METHODS 0
  #undef CYTHON_FAST_THREAD_STATE
  #define CYTHON_FAST_THREAD_STATE 0
  #undef CYTHON_FAST_PYCALL
  #define CYTHON_FAST_PYCALL 0
  #undef CYTHON_PEP489_MULTI_PHASE_INIT
  #define CYTHON_PEP489_MULTI_PHASE_INIT 0
  #undef CYTHON_USE_TP_FINALIZE
  #define CYTHON_USE_TP_FINALIZE 0
  #undef CYTHON_USE_DICT_VERSIONS
  #define CYTHON_USE_DICT_VERSIONS 0
  #undef CYTHON_USE_EXC_INFO_STACK
  #define CYTHON_USE_EXC_INFO_STACK 0
#elif defined(PYSTON_VERSION)
  #define CYTHON_COMPILING_IN_PYPY 0
  #define CYTHON_COMPILING_IN_PYSTON 1
  #define CYTHON_COMPILING_IN_CPYTHON 0
  #ifndef CYTHON_USE_TYPE_SLOTS
    #define CYTHON_USE_TYPE_SLOTS 1
  #endif
  #undef CYTHON_USE_PYTYPE_LOOKUP
  #define CYTHON_USE_PYTYPE_LOOKUP 0
  #undef CYTHON_USE_ASYNC_SLOTS
  #define CYTHON_USE_ASYNC_SLOTS 0
  #undef CYTHON_USE_PYLIST_INTERNALS
  #define CYTHON_USE_PYLIST_INTERNALS 0
  #ifndef CYTHON_USE_UNICODE_INTERNALS
    #define CYTHON_USE_UNICODE_INTERNALS 1
  #endif
  #undef CYTHON_USE_UNICODE_WRITER
  #define CYTHON_USE_UNICODE_WRITER 0
  #undef CYTHON_USE_PYLONG_INTERNALS
  #define CYTHON_USE_PYLONG_INTERNALS 0
  #ifndef CYTHON_AVOID_BORROWED_REFS
    #define CYTHON_AVOID_BORROWED_REFS 0
  #endif
  #ifndef CYTHON_ASSUME_SAFE_MACROS
    #define CYTHON_ASSUME_SAFE_MACROS 1
  #endif
  #ifndef CYTHON_UNPACK_METHODS
    #define CYTHON_UNPACK_METHODS 1
  #endif
  #undef CYTHON_FAST_THREAD_STATE
  #define CYTHON_FAST_THREAD_STATE 0
  #undef CYTHON_FAST_PYCALL
  #define CYTHON_FAST_PYCALL 0
  #undef CYTHON_PEP489_MULTI_PHASE_INIT
  #define CYTHON_PEP489_MULTI_PHASE_INIT 0
  #undef CYTHON_USE_TP_FINALIZE
  #define CYTHON_USE_TP_FINALIZE 0
  #undef CYTHON_USE_DICT_VERSIONS
  #define CYTHON_USE_DICT_VERSIONS 0
  #undef CYTHON_USE_EXC_INFO_STACK
  #define CYTHON_USE_EXC_INFO_STACK 0
#else
  #define CYTHON_COMPILING_IN_PYPY 0
  #define CYTHON_COMPILING_IN_PYSTON 0
  #define CYTHON_COMPILING_IN_CPYTHON 1
  #ifndef CYTHON_USE_TYPE_SLOTS
    #define CYTHON_USE_TYPE_SLOTS 1
  #endif
  #if PY_VERSION_HEX < 0x02070000
    #undef CYTHON_USE_PYTYPE_LOOKUP
    #define CYTHON_USE_PYTYPE_LOOKUP 0
  #elif !defined(CYTHON_USE_PYTYPE_LOOKUP)
    #define CYTHON_USE_PYTYPE_LOOKUP 1
  #endif
  #if PY_MAJOR_VERSION < 3
    #undef CYTHON_USE_ASYNC_SLOTS
    #define CYTHON_USE_ASYNC_SLOTS 0
  #elif !defined(CYTHON_USE_ASYNC_SLOTS)
    #define CYTHON_USE_ASYNC_SLOTS 1
  #endif
  #if PY_VERSION_HEX < 0x02070000
    #undef CYTHON_USE_PYLONG_INTERNALS
    #define CYTHON_USE_PYLONG_INTERNALS 0
  #elif !defined(CYTHON_USE_PYLONG_INTERNALS)
    #define CYTHON_USE_PYLONG_INTERNALS 1
  #endif
  #ifndef CYTHON_USE_PYLIST_INTERNALS
    #define CYTHON_USE_PYLIST_INTERNALS 1
  #endif
  #ifndef CYTHON_USE_UNICODE_INTERNALS
    #define CYTHON_USE_UNICODE_INTERNALS 1
  #endif
  #if PY_VERSION_HEX < 0x030300F0
    #undef CYTHON_USE_UNICODE_WRITER
    #define CYTHON_USE_UNICODE_WRITER 0
  #elif !defined(CYTHON_USE_UNICODE_WRITER)
    #define CYTHON_USE_UNICODE_WRITER 1
  #endif
  #ifndef CYTHON_AVOID_BORROWED_REFS
    #define CYTHON_AVOID_BORROWED_REFS 0
  #endif
  #ifndef CYTHON_ASSUME_SAFE_MACROS
    #define CYTHON_ASSUME_SAFE_MACROS 1
  #endif
  #ifndef CYTHON_UNPACK_METHODS
    #define CYTHON_UNPACK_METHODS 1
  #endif
  #ifndef CYTHON_FAST_THREAD_STATE
    #define CYTHON_FAST_THREAD_STATE 1
  #endif
  #ifndef CYTHON_FAST_PYCALL
    #define CYTHON_FAST_PYCALL 1
  #endif
  #ifndef CYTHON_PEP489_MULTI_PHASE_INIT
    #define CYTHON_PEP489_MULTI_PHASE_INIT (PY_VERSION_HEX >= 0x03050000)
  #endif
  #ifndef CYTHON_USE_TP_FINALIZE
    #define CYTHON_USE_TP_FINALIZE (PY_VERSION_HEX >= 0x030400a1)
  #endif
  #ifndef CYTHON_USE_DICT_VERSIONS
    #define CYTHON_USE_DICT_VERSIONS (PY_VERSION_HEX >= 0x030600B1)
  #endif
  #ifndef CYTHON_USE_EXC_INFO_STACK
    #define CYTHON_USE_EXC_INFO_STACK (PY_VERSION_HEX >= 0x030700A3)
  #endif
#endif
#if !defined(CYTHON_FAST_PYCCALL)
#define CYTHON_FAST_PYCCALL  (CYTHON_FAST_PYCALL && PY_VERSION_HEX >= 0x030600B1)
#endif
#if CYTHON_USE_PYLONG_INTERNALS
  #include "longintrepr.h"
  #undef SHIFT
  #undef BASE
  #undef MASK
  #ifdef SIZEOF_VOID_P
    enum { __pyx_check_sizeof_voidp = 1 / (int)(SIZEOF_VOID_P == sizeof(void*)) };
  #endif
#endif
#ifndef __has_attribute
  #define __has_attribute(x) 0
#endif
#ifndef __has_cpp_attribute
  #define __has_cpp_attribute(x) 0
#endif
#ifndef CYTHON_RESTRICT
  #if defined(__GNUC__)
    #define CYTHON_RESTRICT __restrict__
  #elif defined(_MSC_VER) && _MSC_VER >= 1400
    #define CYTHON_RESTRICT __restrict
  #elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    #define CYTHON_RESTRICT restrict
  #else
    #define CYTHON_RESTRICT
  #endif
#endif
#ifndef CYTHON_UNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define CYTHON_UNUSED __attribute__ ((__unused__))
#   else
#     define CYTHON_UNUSED
#   endif
# elif defined(__ICC) || (defined(__INTEL_COMPILER) && !defined(_MSC_VER))
#   define CYTHON_UNUSED __attribute__ ((__unused__))
# else
#   define CYTHON_UNUSED
# endif
#endif
#ifndef CYTHON_MAYBE_UNUSED_VAR
#  if defined(__cplusplus)
     template<class T> void CYTHON_MAYBE_UNUSED_VAR( const T& ) { }
#  else
#    define CYTHON_MAYBE_UNUSED_VAR(x) (void)(x)
#  endif
#endif
#ifndef CYTHON_NCP_UNUSED
# if CYTHON_COMPILING_IN_CPYTHON
#  define CYTHON_NCP_UNUSED
# else
#  define CYTHON_NCP_UNUSED CYTHON_UNUSED
# endif
#endif
#define __Pyx_void_to_None(void_result) ((void)(void_result), Py_INCREF(Py_None), Py_None)
#ifdef _MSC_VER
    #ifndef _MSC_STDINT_H_
        #if _MSC_VER < 1300
           typedef unsigned char     uint8_t;
           typedef unsigned int      uint32_t;
        #else
           typedef unsigned __int8   uint8_t;
           typedef unsigned __int32  uint32_t;
        #endif
    #endif
#else
   #include <stdint.h>
#endif
#ifndef CYTHON_FALLTHROUGH
  #if defined(__cplusplus) && __cplusplus >= 201103L
    #if __has_cpp_attribute(fallthrough)
      #define CYTHON_FALLTHROUGH [[fallthrough]]
    #elif __has_cpp_attribute(clang::fallthrough)
      #define CYTHON_FALLTHROUGH [[clang::fallthrough]]
    #elif __has_cpp_attribute(gnu::fallthrough)
      #define CYTHON_FALLTHROUGH [[gnu::fallthrough]]
    #endif
  #endif
  #ifndef CYTHON_FALLTHROUGH
    #if __has_attribute(fallthrough)
      #define CYTHON_FALLTHROUGH __attribute__((fallthrough))
    #else
      #define CYTHON_FALLTHROUGH
    #endif
  #endif
  #if defined(__clang__ ) && defined(__apple_build_version__)
    #if __apple_build_version__ < 7000000
      #undef  CYTHON_FALLTHROUGH
      #define CYTHON_FALLTHROUGH
    #endif
  #endif
#endif

#ifndef CYTHON_INLINE
  #if defined(__clang__)
    #define CYTHON_INLINE __inline__ __attribute__ ((__unused__))
  #elif defined(__GNUC__)
    #define CYTHON_INLINE __inline__
  #elif defined(_MSC_VER)
    #define CYTHON_INLINE __inline
  #elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    #define CYTHON_INLINE inline
  #else
    #define CYTHON_INLINE
  #endif
#endif

#if CYTHON_COMPILING_IN_PYPY && PY_VERSION_HEX < 0x02070600 && !defined(Py_OptimizeFlag)
  #define Py_OptimizeFlag 0
#endif
#define __PYX_BUILD_PY_SSIZE_T "n"
#define CYTHON_FORMAT_SSIZE_T "z"
#if PY_MAJOR_VERSION < 3
  #define __Pyx_BUILTIN_MODULE_NAME "__builtin__"
  #define __Pyx_PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)\
          PyCode_New(a+k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)
  #define __Pyx_DefaultClassType PyClass_Type
#else
  #define __Pyx_BUILTIN_MODULE_NAME "builtins"
#if PY_VERSION_HEX >= 0x030800A4 && PY_VERSION_HEX < 0x030800B2
  #define __Pyx_PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)\
          PyCode_New(a, 0, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)
#else
  #define __Pyx_PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)\
          PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)
#endif
  #define __Pyx_DefaultClassType PyType_Type
#endif
#ifndef Py_TPFLAGS_CHECKTYPES
  #define Py_TPFLAGS_CHECKTYPES 0
#endif
#ifndef Py_TPFLAGS_HAVE_INDEX
  #define Py_TPFLAGS_HAVE_INDEX 0
#endif
#ifndef Py_TPFLAGS_HAVE_NEWBUFFER
  #define Py_TPFLAGS_HAVE_NEWBUFFER 0
#endif
#ifndef Py_TPFLAGS_HAVE_FINALIZE
  #define Py_TPFLAGS_HAVE_FINALIZE 0
#endif
#ifndef METH_STACKLESS
  #define METH_STACKLESS 0
#endif
#if PY_VERSION_HEX <= 0x030700A3 || !defined(METH_FASTCALL)
  #ifndef METH_FASTCALL
     #define METH_FASTCALL 0x80
  #endif
  typedef PyObject *(*__Pyx_PyCFunctionFast) (PyObject *self, PyObject *const *args, Py_ssize_t nargs);
  typedef PyObject *(*__Pyx_PyCFunctionFastWithKeywords) (PyObject *self, PyObject *const *args,
                                                          Py_ssize_t nargs, PyObject *kwnames);
#else
  #define __Pyx_PyCFunctionFast _PyCFunctionFast
  #define __Pyx_PyCFunctionFastWithKeywords _PyCFunctionFastWithKeywords
#endif
#if CYTHON_FAST_PYCCALL
#define __Pyx_PyFastCFunction_Check(func)\
    ((PyCFunction_Check(func) && (METH_FASTCALL == (PyCFunction_GET_FLAGS(func) & ~(METH_CLASS | METH_STATIC | METH_COEXIST | METH_KEYWORDS | METH_STACKLESS)))))
#else
#define __Pyx_PyFastCFunction_Check(func) 0
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyObject_Malloc)
  #define PyObject_Malloc(s)   PyMem_Malloc(s)
  #define PyObject_Free(p)     PyMem_Free(p)
  #define PyObject_Realloc(p)  PyMem_Realloc(p)
#endif
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX < 0x030400A1
  #define PyMem_RawMalloc(n)           PyMem_Malloc(n)
  #define PyMem_RawRealloc(p, n)       PyMem_Realloc(p, n)
  #define PyMem_RawFree(p)             PyMem_Free(p)
#endif
#if CYTHON_COMPILING_IN_PYSTON
  #define __Pyx_PyCode_HasFreeVars(co)  PyCode_HasFreeVars(co)
  #define __Pyx_PyFrame_SetLineNumber(frame, lineno) PyFrame_SetLineNumber(frame, lineno)
#else
  #define __Pyx_PyCode_HasFreeVars(co)  (PyCode_GetNumFree(co) > 0)
  #define __Pyx_PyFrame_SetLineNumber(frame, lineno)  (frame)->f_lineno = (lineno)
#endif
#if !CYTHON_FAST_THREAD_STATE || PY_VERSION_HEX < 0x02070000
  #define __Pyx_PyThreadState_Current PyThreadState_GET()
#elif PY_VERSION_HEX >= 0x03060000
  #define __Pyx_PyThreadState_Current _PyThreadState_UncheckedGet()
#elif PY_VERSION_HEX >= 0x03000000
  #define __Pyx_PyThreadState_Current PyThreadState_GET()
#else
  #define __Pyx_PyThreadState_Current _PyThreadState_Current
#endif
#if PY_VERSION_HEX < 0x030700A2 && !defined(PyThread_tss_create) && !defined(Py_tss_NEEDS_INIT)
#include "pythread.h"
#define Py_tss_NEEDS_INIT 0
typedef int Py_tss_t;
static CYTHON_INLINE int PyThread_tss_create(Py_tss_t *key) {
  *key = PyThread_create_key();
  return 0;
}
static CYTHON_INLINE Py_tss_t * PyThread_tss_alloc(void) {
  Py_tss_t *key = (Py_tss_t *)PyObject_Malloc(sizeof(Py_tss_t));
  *key = Py_tss_NEEDS_INIT;
  return key;
}
static CYTHON_INLINE void PyThread_tss_free(Py_tss_t *key) {
  PyObject_Free(key);
}
static CYTHON_INLINE int PyThread_tss_is_created(Py_tss_t *key) {
  return *key != Py_tss_NEEDS_INIT;
}
static CYTHON_INLINE void PyThread_tss_delete(Py_tss_t *key) {
  PyThread_delete_key(*key);
  *key = Py_tss_NEEDS_INIT;
}
static CYTHON_INLINE int PyThread_tss_set(Py_tss_t *key, void *value) {
  return PyThread_set_key_value(*key, value);
}
static CYTHON_INLINE void * PyThread_tss_get(Py_tss_t *key) {
  return PyThread_get_key_value(*key);
}
#endif
#if CYTHON_COMPILING_IN_CPYTHON || defined(_PyDict_NewPresized)
#define __Pyx_PyDict_NewPresized(n)  ((n <= 8) ? PyDict_New() : _PyDict_NewPresized(n))
#else
#define __Pyx_PyDict_NewPresized(n)  PyDict_New()
#endif
#if PY_MAJOR_VERSION >= 3 || CYTHON_FUTURE_DIVISION
  #define __Pyx_PyNumber_Divide(x,y)         PyNumber_TrueDivide(x,y)
  #define __Pyx_PyNumber_InPlaceDivide(x,y)  PyNumber_InPlaceTrueDivide(x,y)
#else
  #define __Pyx_PyNumber_Divide(x,y)         PyNumber_Divide(x,y)
  #define __Pyx_PyNumber_InPlaceDivide(x,y)  PyNumber_InPlaceDivide(x,y)
#endif
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030500A1 && CYTHON_USE_UNICODE_INTERNALS
#define __Pyx_PyDict_GetItemStr(dict, name)  _PyDict_GetItem_KnownHash(dict, name, ((PyASCIIObject *) name)->hash)
#else
#define __Pyx_PyDict_GetItemStr(dict, name)  PyDict_GetItem(dict, name)
#endif
#if PY_VERSION_HEX > 0x03030000 && defined(PyUnicode_KIND)
  #define CYTHON_PEP393_ENABLED 1
  #define __Pyx_PyUnicode_READY(op)       (likely(PyUnicode_IS_READY(op)) ?\
                                              0 : _PyUnicode_Ready((PyObject *)(op)))
  #define __Pyx_PyUnicode_GET_LENGTH(u)   PyUnicode_GET_LENGTH(u)
  #define __Pyx_PyUnicode_READ_CHAR(u, i) PyUnicode_READ_CHAR(u, i)
  #define __Pyx_PyUnicode_MAX_CHAR_VALUE(u)   PyUnicode_MAX_CHAR_VALUE(u)
  #define __Pyx_PyUnicode_KIND(u)         PyUnicode_KIND(u)
  #define __Pyx_PyUnicode_DATA(u)         PyUnicode_DATA(u)
  #define __Pyx_PyUnicode_READ(k, d, i)   PyUnicode_READ(k, d, i)
  #define __Pyx_PyUnicode_WRITE(k, d, i, ch)  PyUnicode_WRITE(k, d, i, ch)
  #if defined(PyUnicode_IS_READY) && defined(PyUnicode_GET_SIZE)
  #define __Pyx_PyUnicode_IS_TRUE(u)      (0 != (likely(PyUnicode_IS_READY(u)) ? PyUnicode_GET_LENGTH(u) : PyUnicode_GET_SIZE(u)))
  #else
  #define __Pyx_PyUnicode_IS_TRUE(u)      (0 != PyUnicode_GET_LENGTH(u))
  #endif
#else
  #define CYTHON_PEP393_ENABLED 0
  #define PyUnicode_1BYTE_KIND  1
  #define PyUnicode_2BYTE_KIND  2
  #define PyUnicode_4BYTE_KIND  4
  #define __Pyx_PyUnicode_READY(op)       (0)
  #define __Pyx_PyUnicode_GET_LENGTH(u)   PyUnicode_GET_SIZE(u)
  #define __Pyx_PyUnicode_READ_CHAR(u, i) ((Py_UCS4)(PyUnicode_AS_UNICODE(u)[i]))
  #define __Pyx_PyUnicode_MAX_CHAR_VALUE(u)   ((sizeof(Py_UNICODE) == 2) ? 65535 : 1114111)
  #define __Pyx_PyUnicode_KIND(u)         (sizeof(Py_UNICODE))
  #define __Pyx_PyUnicode_DATA(u)         ((void*)PyUnicode_AS_UNICODE(u))
  #define __Pyx_PyUnicode_READ(k, d, i)   ((void)(k), (Py_UCS4)(((Py_UNICODE*)d)[i]))
  #define __Pyx_PyUnicode_WRITE(k, d, i, ch)  (((void)(k)), ((Py_UNICODE*)d)[i] = ch)
  #define __Pyx_PyUnicode_IS_TRUE(u)      (0 != PyUnicode_GET_SIZE(u))
#endif
#if CYTHON_COMPILING_IN_PYPY
  #define __Pyx_PyUnicode_Concat(a, b)      PyNumber_Add(a, b)
  #define __Pyx_PyUnicode_ConcatSafe(a, b)  PyNumber_Add(a, b)
#else
  #define __Pyx_PyUnicode_Concat(a, b)      PyUnicode_Concat(a, b)
  #define __Pyx_PyUnicode_ConcatSafe(a, b)  ((unlikely((a) == Py_None) || unlikely((b) == Py_None)) ?\
      PyNumber_Add(a, b) : __Pyx_PyUnicode_Concat(a, b))
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyUnicode_Contains)
  #define PyUnicode_Contains(u, s)  PySequence_Contains(u, s)
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyByteArray_Check)
  #define PyByteArray_Check(obj)  PyObject_TypeCheck(obj, &PyByteArray_Type)
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyObject_Format)
  #define PyObject_Format(obj, fmt)  PyObject_CallMethod(obj, "__format__", "O", fmt)
#endif
#define __Pyx_PyString_FormatSafe(a, b)   ((unlikely((a) == Py_None || (PyString_Check(b) && !PyString_CheckExact(b)))) ? PyNumber_Remainder(a, b) : __Pyx_PyString_Format(a, b))
#define __Pyx_PyUnicode_FormatSafe(a, b)  ((unlikely((a) == Py_None || (PyUnicode_Check(b) && !PyUnicode_CheckExact(b)))) ? PyNumber_Remainder(a, b) : PyUnicode_Format(a, b))
#if PY_MAJOR_VERSION >= 3
  #define __Pyx_PyString_Format(a, b)  PyUnicode_Format(a, b)
#else
  #define __Pyx_PyString_Format(a, b)  PyString_Format(a, b)
#endif
#if PY_MAJOR_VERSION < 3 && !defined(PyObject_ASCII)
  #define PyObject_ASCII(o)            PyObject_Repr(o)
#endif
#if PY_MAJOR_VERSION >= 3
  #define PyBaseString_Type            PyUnicode_Type
  #define PyStringObject               PyUnicodeObject
  #define PyString_Type                PyUnicode_Type
  #define PyString_Check               PyUnicode_Check
  #define PyString_CheckExact          PyUnicode_CheckExact
#ifndef PyObject_Unicode
  #define PyObject_Unicode             PyObject_Str
#endif
#endif
#if PY_MAJOR_VERSION >= 3
  #define __Pyx_PyBaseString_Check(obj) PyUnicode_Check(obj)
  #define __Pyx_PyBaseString_CheckExact(obj) PyUnicode_CheckExact(obj)
#else
  #define __Pyx_PyBaseString_Check(obj) (PyString_Check(obj) || PyUnicode_Check(obj))
  #define __Pyx_PyBaseString_CheckExact(obj) (PyString_CheckExact(obj) || PyUnicode_CheckExact(obj))
#endif
#ifndef PySet_CheckExact
  #define PySet_CheckExact(obj)        (Py_TYPE(obj) == &PySet_Type)
#endif
#if PY_VERSION_HEX >= 0x030900A4
  #define __Pyx_SET_REFCNT(obj, refcnt) Py_SET_REFCNT(obj, refcnt)
  #define __Pyx_SET_SIZE(obj, size) Py_SET_SIZE(obj, size)
#else
  #define __Pyx_SET_REFCNT(obj, refcnt) Py_REFCNT(obj) = (refcnt)
  #define __Pyx_SET_SIZE(obj, size) Py_SIZE(obj) = (size)
#endif
#if CYTHON_ASSUME_SAFE_MACROS
  #define __Pyx_PySequence_SIZE(seq)  Py_SIZE(seq)
#else
  #define __Pyx_PySequence_SIZE(seq)  PySequence_Size(seq)
#endif
#if PY_MAJOR_VERSION >= 3
  #define PyIntObject                  PyLongObject
  #define PyInt_Type                   PyLong_Type
  #define PyInt_Check(op)              PyLong_Check(op)
  #define PyInt_CheckExact(op)         PyLong_CheckExact(op)
  #define PyInt_FromString             PyLong_FromString
  #define PyInt_FromUnicode            PyLong_FromUnicode
  #define PyInt_FromLong               PyLong_FromLong
  #define PyInt_FromSize_t             PyLong_FromSize_t
  #define PyInt_FromSsize_t            PyLong_FromSsize_t
  #define PyInt_AsLong                 PyLong_AsLong
  #define PyInt_AS_LONG                PyLong_AS_LONG
  #define PyInt_AsSsize_t              PyLong_AsSsize_t
  #define PyInt_AsUnsignedLongMask     PyLong_AsUnsignedLongMask
  #define PyInt_AsUnsignedLongLongMask PyLong_AsUnsignedLongLongMask
  #define PyNumber_Int                 PyNumber_Long
#endif
#if PY_MAJOR_VERSION >= 3
  #define PyBoolObject                 PyLongObject
#endif
#if PY_MAJOR_VERSION >= 3 && CYTHON_COMPILING_IN_PYPY
  #ifndef PyUnicode_InternFromString
    #define PyUnicode_InternFromString(s) PyUnicode_FromString(s)
  #endif
#endif
#if PY_VERSION_HEX < 0x030200A4
  typedef long Py_hash_t;
  #define __Pyx_PyInt_FromHash_t PyInt_FromLong
  #define __Pyx_PyInt_AsHash_t   PyInt_AsLong
#else
  #define __Pyx_PyInt_FromHash_t PyInt_FromSsize_t
  #define __Pyx_PyInt_AsHash_t   PyInt_AsSsize_t
#endif
#if PY_MAJOR_VERSION >= 3
  #define __Pyx_PyMethod_New(func, self, klass) ((self) ? ((void)(klass), PyMethod_New(func, self)) : __Pyx_NewRef(func))
#else
  #define __Pyx_PyMethod_New(func, self, klass) PyMethod_New(func, self, klass)
#endif
#if CYTHON_USE_ASYNC_SLOTS
  #if PY_VERSION_HEX >= 0x030500B1
    #define __Pyx_PyAsyncMethodsStruct PyAsyncMethods
    #define __Pyx_PyType_AsAsync(obj) (Py_TYPE(obj)->tp_as_async)
  #else
    #define __Pyx_PyType_AsAsync(obj) ((__Pyx_PyAsyncMethodsStruct*) (Py_TYPE(obj)->tp_reserved))
  #endif
#else
  #define __Pyx_PyType_AsAsync(obj) NULL
#endif
#ifndef __Pyx_PyAsyncMethodsStruct
    typedef struct {
        unaryfunc am_await;
        unaryfunc am_aiter;
        unaryfunc am_anext;
    } __Pyx_PyAsyncMethodsStruct;
#endif

#if defined(WIN32) || defined(MS_WINDOWS)
  #define _USE_MATH_DEFINES
#endif
#include <math.h>
#ifdef NAN
#define __PYX_NAN() ((float) NAN)
#else
static CYTHON_INLINE float __PYX_NAN() {
  float value;
  memset(&value, 0xFF, sizeof(value));
  return value;
}
#endif
#if defined(__CYGWIN__) && defined(_LDBL_EQ_DBL)
#define __Pyx_truncl trunc
#else
#define __Pyx_truncl truncl
#endif

#define __PYX_MARK_ERR_POS(f_index, lineno) \
    { __pyx_filename = __pyx_f[f_index]; (void)__pyx_filename; __pyx_lineno = lineno; (void)__pyx_lineno; __pyx_clineno = __LINE__; (void)__pyx_clineno; }
#define __PYX_ERR(f_index, lineno, Ln_error) \
    { __PYX_MARK_ERR_POS(f_index, lineno) goto Ln_error; }

#ifndef __PYX_EXTERN_C
  #ifdef __cplusplus
    #define __PYX_EXTERN_C extern "C"
  #else
    #define __PYX_EXTERN_C extern
  #endif
#endif

#define __PYX_HAVE__KakaoChat__kakao
#define __PYX_HAVE_API__KakaoChat__kakao
/* Early includes */
#ifdef _OPENMP
#include <omp.h>
#endif /* _OPENMP */

#if defined(PYREX_WITHOUT_ASSERTIONS) && !defined(CYTHON_WITHOUT_ASSERTIONS)
#define CYTHON_WITHOUT_ASSERTIONS
#endif

typedef struct {PyObject **p; const char *s; const Py_ssize_t n; const char* encoding;
                const char is_unicode; const char is_str; const char intern; } __Pyx_StringTabEntry;

#define __PYX_DEFAULT_STRING_ENCODING_IS_ASCII 0
#define __PYX_DEFAULT_STRING_ENCODING_IS_UTF8 1
#define __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT (PY_MAJOR_VERSION >= 3 && __PYX_DEFAULT_STRING_ENCODING_IS_UTF8)
#define __PYX_DEFAULT_STRING_ENCODING "utf-8"
#define __Pyx_PyObject_FromString __Pyx_PyBytes_FromString
#define __Pyx_PyObject_FromStringAndSize __Pyx_PyBytes_FromStringAndSize
#define __Pyx_uchar_cast(c) ((unsigned char)c)
#define __Pyx_long_cast(x) ((long)x)
#define __Pyx_fits_Py_ssize_t(v, type, is_signed)  (\
    (sizeof(type) < sizeof(Py_ssize_t))  ||\
    (sizeof(type) > sizeof(Py_ssize_t) &&\
          likely(v < (type)PY_SSIZE_T_MAX ||\
                 v == (type)PY_SSIZE_T_MAX)  &&\
          (!is_signed || likely(v > (type)PY_SSIZE_T_MIN ||\
                                v == (type)PY_SSIZE_T_MIN)))  ||\
    (sizeof(type) == sizeof(Py_ssize_t) &&\
          (is_signed || likely(v < (type)PY_SSIZE_T_MAX ||\
                               v == (type)PY_SSIZE_T_MAX)))  )
static CYTHON_INLINE int __Pyx_is_valid_index(Py_ssize_t i, Py_ssize_t limit) {
    return (size_t) i < (size_t) limit;
}
#if defined (__cplusplus) && __cplusplus >= 201103L
    #include <cstdlib>
    #define __Pyx_sst_abs(value) std::abs(value)
#elif SIZEOF_INT >= SIZEOF_SIZE_T
    #define __Pyx_sst_abs(value) abs(value)
#elif SIZEOF_LONG >= SIZEOF_SIZE_T
    #define __Pyx_sst_abs(value) labs(value)
#elif defined (_MSC_VER)
    #define __Pyx_sst_abs(value) ((Py_ssize_t)_abs64(value))
#elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    #define __Pyx_sst_abs(value) llabs(value)
#elif defined (__GNUC__)
    #define __Pyx_sst_abs(value) __builtin_llabs(value)
#else
    #define __Pyx_sst_abs(value) ((value<0) ? -value : value)
#endif
static CYTHON_INLINE const char* __Pyx_PyObject_AsString(PyObject*);
static CYTHON_INLINE const char* __Pyx_PyObject_AsStringAndSize(PyObject*, Py_ssize_t* length);
#define __Pyx_PyByteArray_FromString(s) PyByteArray_FromStringAndSize((const char*)s, strlen((const char*)s))
#define __Pyx_PyByteArray_FromStringAndSize(s, l) PyByteArray_FromStringAndSize((const char*)s, l)
#define __Pyx_PyBytes_FromString        PyBytes_FromString
#define __Pyx_PyBytes_FromStringAndSize PyBytes_FromStringAndSize
static CYTHON_INLINE PyObject* __Pyx_PyUnicode_FromString(const char*);
#if PY_MAJOR_VERSION < 3
    #define __Pyx_PyStr_FromString        __Pyx_PyBytes_FromString
    #define __Pyx_PyStr_FromStringAndSize __Pyx_PyBytes_FromStringAndSize
#else
    #define __Pyx_PyStr_FromString        __Pyx_PyUnicode_FromString
    #define __Pyx_PyStr_FromStringAndSize __Pyx_PyUnicode_FromStringAndSize
#endif
#define __Pyx_PyBytes_AsWritableString(s)     ((char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsWritableSString(s)    ((signed char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsWritableUString(s)    ((unsigned char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsString(s)     ((const char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsSString(s)    ((const signed char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsUString(s)    ((const unsigned char*) PyBytes_AS_STRING(s))
#define __Pyx_PyObject_AsWritableString(s)    ((char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsWritableSString(s)    ((signed char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsWritableUString(s)    ((unsigned char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsSString(s)    ((const signed char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsUString(s)    ((const unsigned char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_FromCString(s)  __Pyx_PyObject_FromString((const char*)s)
#define __Pyx_PyBytes_FromCString(s)   __Pyx_PyBytes_FromString((const char*)s)
#define __Pyx_PyByteArray_FromCString(s)   __Pyx_PyByteArray_FromString((const char*)s)
#define __Pyx_PyStr_FromCString(s)     __Pyx_PyStr_FromString((const char*)s)
#define __Pyx_PyUnicode_FromCString(s) __Pyx_PyUnicode_FromString((const char*)s)
static CYTHON_INLINE size_t __Pyx_Py_UNICODE_strlen(const Py_UNICODE *u) {
    const Py_UNICODE *u_end = u;
    while (*u_end++) ;
    return (size_t)(u_end - u - 1);
}
#define __Pyx_PyUnicode_FromUnicode(u)       PyUnicode_FromUnicode(u, __Pyx_Py_UNICODE_strlen(u))
#define __Pyx_PyUnicode_FromUnicodeAndLength PyUnicode_FromUnicode
#define __Pyx_PyUnicode_AsUnicode            PyUnicode_AsUnicode
#define __Pyx_NewRef(obj) (Py_INCREF(obj), obj)
#define __Pyx_Owned_Py_None(b) __Pyx_NewRef(Py_None)
static CYTHON_INLINE PyObject * __Pyx_PyBool_FromLong(long b);
static CYTHON_INLINE int __Pyx_PyObject_IsTrue(PyObject*);
static CYTHON_INLINE int __Pyx_PyObject_IsTrueAndDecref(PyObject*);
static CYTHON_INLINE PyObject* __Pyx_PyNumber_IntOrLong(PyObject* x);
#define __Pyx_PySequence_Tuple(obj)\
    (likely(PyTuple_CheckExact(obj)) ? __Pyx_NewRef(obj) : PySequence_Tuple(obj))
static CYTHON_INLINE Py_ssize_t __Pyx_PyIndex_AsSsize_t(PyObject*);
static CYTHON_INLINE PyObject * __Pyx_PyInt_FromSize_t(size_t);
#if CYTHON_ASSUME_SAFE_MACROS
#define __pyx_PyFloat_AsDouble(x) (PyFloat_CheckExact(x) ? PyFloat_AS_DOUBLE(x) : PyFloat_AsDouble(x))
#else
#define __pyx_PyFloat_AsDouble(x) PyFloat_AsDouble(x)
#endif
#define __pyx_PyFloat_AsFloat(x) ((float) __pyx_PyFloat_AsDouble(x))
#if PY_MAJOR_VERSION >= 3
#define __Pyx_PyNumber_Int(x) (PyLong_CheckExact(x) ? __Pyx_NewRef(x) : PyNumber_Long(x))
#else
#define __Pyx_PyNumber_Int(x) (PyInt_CheckExact(x) ? __Pyx_NewRef(x) : PyNumber_Int(x))
#endif
#define __Pyx_PyNumber_Float(x) (PyFloat_CheckExact(x) ? __Pyx_NewRef(x) : PyNumber_Float(x))
#if PY_MAJOR_VERSION < 3 && __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
static int __Pyx_sys_getdefaultencoding_not_ascii;
static int __Pyx_init_sys_getdefaultencoding_params(void) {
    PyObject* sys;
    PyObject* default_encoding = NULL;
    PyObject* ascii_chars_u = NULL;
    PyObject* ascii_chars_b = NULL;
    const char* default_encoding_c;
    sys = PyImport_ImportModule("sys");
    if (!sys) goto bad;
    default_encoding = PyObject_CallMethod(sys, (char*) "getdefaultencoding", NULL);
    Py_DECREF(sys);
    if (!default_encoding) goto bad;
    default_encoding_c = PyBytes_AsString(default_encoding);
    if (!default_encoding_c) goto bad;
    if (strcmp(default_encoding_c, "ascii") == 0) {
        __Pyx_sys_getdefaultencoding_not_ascii = 0;
    } else {
        char ascii_chars[128];
        int c;
        for (c = 0; c < 128; c++) {
            ascii_chars[c] = c;
        }
        __Pyx_sys_getdefaultencoding_not_ascii = 1;
        ascii_chars_u = PyUnicode_DecodeASCII(ascii_chars, 128, NULL);
        if (!ascii_chars_u) goto bad;
        ascii_chars_b = PyUnicode_AsEncodedString(ascii_chars_u, default_encoding_c, NULL);
        if (!ascii_chars_b || !PyBytes_Check(ascii_chars_b) || memcmp(ascii_chars, PyBytes_AS_STRING(ascii_chars_b), 128) != 0) {
            PyErr_Format(
                PyExc_ValueError,
                "This module compiled with c_string_encoding=ascii, but default encoding '%.200s' is not a superset of ascii.",
                default_encoding_c);
            goto bad;
        }
        Py_DECREF(ascii_chars_u);
        Py_DECREF(ascii_chars_b);
    }
    Py_DECREF(default_encoding);
    return 0;
bad:
    Py_XDECREF(default_encoding);
    Py_XDECREF(ascii_chars_u);
    Py_XDECREF(ascii_chars_b);
    return -1;
}
#endif
#if __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT && PY_MAJOR_VERSION >= 3
#define __Pyx_PyUnicode_FromStringAndSize(c_str, size) PyUnicode_DecodeUTF8(c_str, size, NULL)
#else
#define __Pyx_PyUnicode_FromStringAndSize(c_str, size) PyUnicode_Decode(c_str, size, __PYX_DEFAULT_STRING_ENCODING, NULL)
#if __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT
static char* __PYX_DEFAULT_STRING_ENCODING;
static int __Pyx_init_sys_getdefaultencoding_params(void) {
    PyObject* sys;
    PyObject* default_encoding = NULL;
    char* default_encoding_c;
    sys = PyImport_ImportModule("sys");
    if (!sys) goto bad;
    default_encoding = PyObject_CallMethod(sys, (char*) (const char*) "getdefaultencoding", NULL);
    Py_DECREF(sys);
    if (!default_encoding) goto bad;
    default_encoding_c = PyBytes_AsString(default_encoding);
    if (!default_encoding_c) goto bad;
    __PYX_DEFAULT_STRING_ENCODING = (char*) malloc(strlen(default_encoding_c) + 1);
    if (!__PYX_DEFAULT_STRING_ENCODING) goto bad;
    strcpy(__PYX_DEFAULT_STRING_ENCODING, default_encoding_c);
    Py_DECREF(default_encoding);
    return 0;
bad:
    Py_XDECREF(default_encoding);
    return -1;
}
#endif
#endif


/* Test for GCC > 2.95 */
#if defined(__GNUC__)     && (__GNUC__ > 2 || (__GNUC__ == 2 && (__GNUC_MINOR__ > 95)))
  #define likely(x)   __builtin_expect(!!(x), 1)
  #define unlikely(x) __builtin_expect(!!(x), 0)
#else /* !__GNUC__ or GCC < 2.95 */
  #define likely(x)   (x)
  #define unlikely(x) (x)
#endif /* __GNUC__ */
static CYTHON_INLINE void __Pyx_pretend_to_initialize(void* ptr) { (void)ptr; }

static PyObject *__pyx_m = NULL;
static PyObject *__pyx_d;
static PyObject *__pyx_b;
static PyObject *__pyx_cython_runtime = NULL;
static PyObject *__pyx_empty_tuple;
static PyObject *__pyx_empty_bytes;
static PyObject *__pyx_empty_unicode;
static int __pyx_lineno;
static int __pyx_clineno = 0;
static const char * __pyx_cfilenm= __FILE__;
static const char *__pyx_filename;


static const char *__pyx_f[] = {
  "kakao.py",
};

/*--- Type declarations ---*/
struct __pyx_obj_9KakaoChat_5kakao___pyx_scope_struct__get_db;
struct __pyx_defaults;
typedef struct __pyx_defaults __pyx_defaults;
struct __pyx_defaults1;
typedef struct __pyx_defaults1 __pyx_defaults1;
struct __pyx_defaults2;
typedef struct __pyx_defaults2 __pyx_defaults2;
struct __pyx_defaults3;
typedef struct __pyx_defaults3 __pyx_defaults3;
struct __pyx_defaults4;
typedef struct __pyx_defaults4 __pyx_defaults4;
struct __pyx_defaults {
  PyObject *__pyx_arg_db;
};
struct __pyx_defaults1 {
  PyObject *__pyx_arg_db;
};
struct __pyx_defaults2 {
  PyObject *__pyx_arg_db;
};
struct __pyx_defaults3 {
  PyObject *__pyx_arg_db;
};
struct __pyx_defaults4 {
  PyObject *__pyx_arg_db;
};

/* "KakaoChat/kakao.py":39
 * 
 * # Dependency
 * def get_db():             # <<<<<<<<<<<<<<
 *     db = db_model.database.SessionLocal()
 *     try:
 */
struct __pyx_obj_9KakaoChat_5kakao___pyx_scope_struct__get_db {
  PyObject_HEAD
  PyObject *__pyx_v_db;
};


/* --- Runtime support code (head) --- */
/* Refnanny.proto */
#ifndef CYTHON_REFNANNY
  #define CYTHON_REFNANNY 0
#endif
#if CYTHON_REFNANNY
  typedef struct {
    void (*INCREF)(void*, PyObject*, int);
    void (*DECREF)(void*, PyObject*, int);
    void (*GOTREF)(void*, PyObject*, int);
    void (*GIVEREF)(void*, PyObject*, int);
    void* (*SetupContext)(const char*, int, const char*);
    void (*FinishContext)(void**);
  } __Pyx_RefNannyAPIStruct;
  static __Pyx_RefNannyAPIStruct *__Pyx_RefNanny = NULL;
  static __Pyx_RefNannyAPIStruct *__Pyx_RefNannyImportAPI(const char *modname);
  #define __Pyx_RefNannyDeclarations void *__pyx_refnanny = NULL;
#ifdef WITH_THREAD
  #define __Pyx_RefNannySetupContext(name, acquire_gil)\
          if (acquire_gil) {\
              PyGILState_STATE __pyx_gilstate_save = PyGILState_Ensure();\
              __pyx_refnanny = __Pyx_RefNanny->SetupContext((name), __LINE__, __FILE__);\
              PyGILState_Release(__pyx_gilstate_save);\
          } else {\
              __pyx_refnanny = __Pyx_RefNanny->SetupContext((name), __LINE__, __FILE__);\
          }
#else
  #define __Pyx_RefNannySetupContext(name, acquire_gil)\
          __pyx_refnanny = __Pyx_RefNanny->SetupContext((name), __LINE__, __FILE__)
#endif
  #define __Pyx_RefNannyFinishContext()\
          __Pyx_RefNanny->FinishContext(&__pyx_refnanny)
  #define __Pyx_INCREF(r)  __Pyx_RefNanny->INCREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_DECREF(r)  __Pyx_RefNanny->DECREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_GOTREF(r)  __Pyx_RefNanny->GOTREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_GIVEREF(r) __Pyx_RefNanny->GIVEREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_XINCREF(r)  do { if((r) != NULL) {__Pyx_INCREF(r); }} while(0)
  #define __Pyx_XDECREF(r)  do { if((r) != NULL) {__Pyx_DECREF(r); }} while(0)
  #define __Pyx_XGOTREF(r)  do { if((r) != NULL) {__Pyx_GOTREF(r); }} while(0)
  #define __Pyx_XGIVEREF(r) do { if((r) != NULL) {__Pyx_GIVEREF(r);}} while(0)
#else
  #define __Pyx_RefNannyDeclarations
  #define __Pyx_RefNannySetupContext(name, acquire_gil)
  #define __Pyx_RefNannyFinishContext()
  #define __Pyx_INCREF(r) Py_INCREF(r)
  #define __Pyx_DECREF(r) Py_DECREF(r)
  #define __Pyx_GOTREF(r)
  #define __Pyx_GIVEREF(r)
  #define __Pyx_XINCREF(r) Py_XINCREF(r)
  #define __Pyx_XDECREF(r) Py_XDECREF(r)
  #define __Pyx_XGOTREF(r)
  #define __Pyx_XGIVEREF(r)
#endif
#define __Pyx_XDECREF_SET(r, v) do {\
        PyObject *tmp = (PyObject *) r;\
        r = v; __Pyx_XDECREF(tmp);\
    } while (0)
#define __Pyx_DECREF_SET(r, v) do {\
        PyObject *tmp = (PyObject *) r;\
        r = v; __Pyx_DECREF(tmp);\
    } while (0)
#define __Pyx_CLEAR(r)    do { PyObject* tmp = ((PyObject*)(r)); r = NULL; __Pyx_DECREF(tmp);} while(0)
#define __Pyx_XCLEAR(r)   do { if((r) != NULL) {PyObject* tmp = ((PyObject*)(r)); r = NULL; __Pyx_DECREF(tmp);}} while(0)

/* PyObjectGetAttrStr.proto */
#if CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PyObject* __Pyx_PyObject_GetAttrStr(PyObject* obj, PyObject* attr_name);
#else
#define __Pyx_PyObject_GetAttrStr(o,n) PyObject_GetAttr(o,n)
#endif

/* GetBuiltinName.proto */
static PyObject *__Pyx_GetBuiltinName(PyObject *name);

/* PyDictVersioning.proto */
#if CYTHON_USE_DICT_VERSIONS && CYTHON_USE_TYPE_SLOTS
#define __PYX_DICT_VERSION_INIT  ((PY_UINT64_T) -1)
#define __PYX_GET_DICT_VERSION(dict)  (((PyDictObject*)(dict))->ma_version_tag)
#define __PYX_UPDATE_DICT_CACHE(dict, value, cache_var, version_var)\
    (version_var) = __PYX_GET_DICT_VERSION(dict);\
    (cache_var) = (value);
#define __PYX_PY_DICT_LOOKUP_IF_MODIFIED(VAR, DICT, LOOKUP) {\
    static PY_UINT64_T __pyx_dict_version = 0;\
    static PyObject *__pyx_dict_cached_value = NULL;\
    if (likely(__PYX_GET_DICT_VERSION(DICT) == __pyx_dict_version)) {\
        (VAR) = __pyx_dict_cached_value;\
    } else {\
        (VAR) = __pyx_dict_cached_value = (LOOKUP);\
        __pyx_dict_version = __PYX_GET_DICT_VERSION(DICT);\
    }\
}
static CYTHON_INLINE PY_UINT64_T __Pyx_get_tp_dict_version(PyObject *obj);
static CYTHON_INLINE PY_UINT64_T __Pyx_get_object_dict_version(PyObject *obj);
static CYTHON_INLINE int __Pyx_object_dict_version_matches(PyObject* obj, PY_UINT64_T tp_dict_version, PY_UINT64_T obj_dict_version);
#else
#define __PYX_GET_DICT_VERSION(dict)  (0)
#define __PYX_UPDATE_DICT_CACHE(dict, value, cache_var, version_var)
#define __PYX_PY_DICT_LOOKUP_IF_MODIFIED(VAR, DICT, LOOKUP)  (VAR) = (LOOKUP);
#endif

/* GetModuleGlobalName.proto */
#if CYTHON_USE_DICT_VERSIONS
#define __Pyx_GetModuleGlobalName(var, name)  {\
    static PY_UINT64_T __pyx_dict_version = 0;\
    static PyObject *__pyx_dict_cached_value = NULL;\
    (var) = (likely(__pyx_dict_version == __PYX_GET_DICT_VERSION(__pyx_d))) ?\
        (likely(__pyx_dict_cached_value) ? __Pyx_NewRef(__pyx_dict_cached_value) : __Pyx_GetBuiltinName(name)) :\
        __Pyx__GetModuleGlobalName(name, &__pyx_dict_version, &__pyx_dict_cached_value);\
}
#define __Pyx_GetModuleGlobalNameUncached(var, name)  {\
    PY_UINT64_T __pyx_dict_version;\
    PyObject *__pyx_dict_cached_value;\
    (var) = __Pyx__GetModuleGlobalName(name, &__pyx_dict_version, &__pyx_dict_cached_value);\
}
static PyObject *__Pyx__GetModuleGlobalName(PyObject *name, PY_UINT64_T *dict_version, PyObject **dict_cached_value);
#else
#define __Pyx_GetModuleGlobalName(var, name)  (var) = __Pyx__GetModuleGlobalName(name)
#define __Pyx_GetModuleGlobalNameUncached(var, name)  (var) = __Pyx__GetModuleGlobalName(name)
static CYTHON_INLINE PyObject *__Pyx__GetModuleGlobalName(PyObject *name);
#endif

/* PyFunctionFastCall.proto */
#if CYTHON_FAST_PYCALL
#define __Pyx_PyFunction_FastCall(func, args, nargs)\
    __Pyx_PyFunction_FastCallDict((func), (args), (nargs), NULL)
#if 1 || PY_VERSION_HEX < 0x030600B1
static PyObject *__Pyx_PyFunction_FastCallDict(PyObject *func, PyObject **args, Py_ssize_t nargs, PyObject *kwargs);
#else
#define __Pyx_PyFunction_FastCallDict(func, args, nargs, kwargs) _PyFunction_FastCallDict(func, args, nargs, kwargs)
#endif
#define __Pyx_BUILD_ASSERT_EXPR(cond)\
    (sizeof(char [1 - 2*!(cond)]) - 1)
#ifndef Py_MEMBER_SIZE
#define Py_MEMBER_SIZE(type, member) sizeof(((type *)0)->member)
#endif
  static size_t __pyx_pyframe_localsplus_offset = 0;
  #include "frameobject.h"
  #define __Pxy_PyFrame_Initialize_Offsets()\
    ((void)__Pyx_BUILD_ASSERT_EXPR(sizeof(PyFrameObject) == offsetof(PyFrameObject, f_localsplus) + Py_MEMBER_SIZE(PyFrameObject, f_localsplus)),\
     (void)(__pyx_pyframe_localsplus_offset = ((size_t)PyFrame_Type.tp_basicsize) - Py_MEMBER_SIZE(PyFrameObject, f_localsplus)))
  #define __Pyx_PyFrame_GetLocalsplus(frame)\
    (assert(__pyx_pyframe_localsplus_offset), (PyObject **)(((char *)(frame)) + __pyx_pyframe_localsplus_offset))
#endif

/* PyObjectCall.proto */
#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_Call(PyObject *func, PyObject *arg, PyObject *kw);
#else
#define __Pyx_PyObject_Call(func, arg, kw) PyObject_Call(func, arg, kw)
#endif

/* PyObjectCallMethO.proto */
#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallMethO(PyObject *func, PyObject *arg);
#endif

/* PyObjectCallNoArg.proto */
#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallNoArg(PyObject *func);
#else
#define __Pyx_PyObject_CallNoArg(func) __Pyx_PyObject_Call(func, __pyx_empty_tuple, NULL)
#endif

/* PyCFunctionFastCall.proto */
#if CYTHON_FAST_PYCCALL
static CYTHON_INLINE PyObject *__Pyx_PyCFunction_FastCall(PyObject *func, PyObject **args, Py_ssize_t nargs);
#else
#define __Pyx_PyCFunction_FastCall(func, args, nargs)  (assert(0), NULL)
#endif

/* PyObjectCallOneArg.proto */
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallOneArg(PyObject *func, PyObject *arg);

/* PyThreadStateGet.proto */
#if CYTHON_FAST_THREAD_STATE
#define __Pyx_PyThreadState_declare  PyThreadState *__pyx_tstate;
#define __Pyx_PyThreadState_assign  __pyx_tstate = __Pyx_PyThreadState_Current;
#define __Pyx_PyErr_Occurred()  __pyx_tstate->curexc_type
#else
#define __Pyx_PyThreadState_declare
#define __Pyx_PyThreadState_assign
#define __Pyx_PyErr_Occurred()  PyErr_Occurred()
#endif

/* PyErrFetchRestore.proto */
#if CYTHON_FAST_THREAD_STATE
#define __Pyx_PyErr_Clear() __Pyx_ErrRestore(NULL, NULL, NULL)
#define __Pyx_ErrRestoreWithState(type, value, tb)  __Pyx_ErrRestoreInState(PyThreadState_GET(), type, value, tb)
#define __Pyx_ErrFetchWithState(type, value, tb)    __Pyx_ErrFetchInState(PyThreadState_GET(), type, value, tb)
#define __Pyx_ErrRestore(type, value, tb)  __Pyx_ErrRestoreInState(__pyx_tstate, type, value, tb)
#define __Pyx_ErrFetch(type, value, tb)    __Pyx_ErrFetchInState(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx_ErrRestoreInState(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb);
static CYTHON_INLINE void __Pyx_ErrFetchInState(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#if CYTHON_COMPILING_IN_CPYTHON
#define __Pyx_PyErr_SetNone(exc) (Py_INCREF(exc), __Pyx_ErrRestore((exc), NULL, NULL))
#else
#define __Pyx_PyErr_SetNone(exc) PyErr_SetNone(exc)
#endif
#else
#define __Pyx_PyErr_Clear() PyErr_Clear()
#define __Pyx_PyErr_SetNone(exc) PyErr_SetNone(exc)
#define __Pyx_ErrRestoreWithState(type, value, tb)  PyErr_Restore(type, value, tb)
#define __Pyx_ErrFetchWithState(type, value, tb)  PyErr_Fetch(type, value, tb)
#define __Pyx_ErrRestoreInState(tstate, type, value, tb)  PyErr_Restore(type, value, tb)
#define __Pyx_ErrFetchInState(tstate, type, value, tb)  PyErr_Fetch(type, value, tb)
#define __Pyx_ErrRestore(type, value, tb)  PyErr_Restore(type, value, tb)
#define __Pyx_ErrFetch(type, value, tb)  PyErr_Fetch(type, value, tb)
#endif

/* GetException.proto */
#if CYTHON_FAST_THREAD_STATE
#define __Pyx_GetException(type, value, tb)  __Pyx__GetException(__pyx_tstate, type, value, tb)
static int __Pyx__GetException(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#else
static int __Pyx_GetException(PyObject **type, PyObject **value, PyObject **tb);
#endif

/* SwapException.proto */
#if CYTHON_FAST_THREAD_STATE
#define __Pyx_ExceptionSwap(type, value, tb)  __Pyx__ExceptionSwap(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx__ExceptionSwap(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#else
static CYTHON_INLINE void __Pyx_ExceptionSwap(PyObject **type, PyObject **value, PyObject **tb);
#endif

/* GetTopmostException.proto */
#if CYTHON_USE_EXC_INFO_STACK
static _PyErr_StackItem * __Pyx_PyErr_GetTopmostException(PyThreadState *tstate);
#endif

/* SaveResetException.proto */
#if CYTHON_FAST_THREAD_STATE
#define __Pyx_ExceptionSave(type, value, tb)  __Pyx__ExceptionSave(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx__ExceptionSave(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#define __Pyx_ExceptionReset(type, value, tb)  __Pyx__ExceptionReset(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx__ExceptionReset(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb);
#else
#define __Pyx_ExceptionSave(type, value, tb)   PyErr_GetExcInfo(type, value, tb)
#define __Pyx_ExceptionReset(type, value, tb)  PyErr_SetExcInfo(type, value, tb)
#endif

/* RaiseArgTupleInvalid.proto */
static void __Pyx_RaiseArgtupleInvalid(const char* func_name, int exact,
    Py_ssize_t num_min, Py_ssize_t num_max, Py_ssize_t num_found);

/* RaiseDoubleKeywords.proto */
static void __Pyx_RaiseDoubleKeywordsError(const char* func_name, PyObject* kw_name);

/* ParseKeywords.proto */
static int __Pyx_ParseOptionalKeywords(PyObject *kwds, PyObject **argnames[],\
    PyObject *kwds2, PyObject *values[], Py_ssize_t num_pos_args,\
    const char* function_name);

/* ArgTypeTest.proto */
#define __Pyx_ArgTypeTest(obj, type, none_allowed, name, exact)\
    ((likely((Py_TYPE(obj) == type) | (none_allowed && (obj == Py_None)))) ? 1 :\
        __Pyx__ArgTypeTest(obj, type, name, exact))
static int __Pyx__ArgTypeTest(PyObject *obj, PyTypeObject *type, const char *name, int exact);

/* PyObjectFormatSimple.proto */
#if CYTHON_COMPILING_IN_PYPY
    #define __Pyx_PyObject_FormatSimple(s, f) (\
        likely(PyUnicode_CheckExact(s)) ? (Py_INCREF(s), s) :\
        PyObject_Format(s, f))
#elif PY_MAJOR_VERSION < 3
    #define __Pyx_PyObject_FormatSimple(s, f) (\
        likely(PyUnicode_CheckExact(s)) ? (Py_INCREF(s), s) :\
        likely(PyString_CheckExact(s)) ? PyUnicode_FromEncodedObject(s, NULL, "strict") :\
        PyObject_Format(s, f))
#elif CYTHON_USE_TYPE_SLOTS
    #define __Pyx_PyObject_FormatSimple(s, f) (\
        likely(PyUnicode_CheckExact(s)) ? (Py_INCREF(s), s) :\
        likely(PyLong_CheckExact(s)) ? PyLong_Type.tp_str(s) :\
        likely(PyFloat_CheckExact(s)) ? PyFloat_Type.tp_str(s) :\
        PyObject_Format(s, f))
#else
    #define __Pyx_PyObject_FormatSimple(s, f) (\
        likely(PyUnicode_CheckExact(s)) ? (Py_INCREF(s), s) :\
        PyObject_Format(s, f))
#endif

/* IncludeStringH.proto */
#include <string.h>

/* JoinPyUnicode.proto */
static PyObject* __Pyx_PyUnicode_Join(PyObject* value_tuple, Py_ssize_t value_count, Py_ssize_t result_ulength,
                                      Py_UCS4 max_char);

/* FastTypeChecks.proto */
#if CYTHON_COMPILING_IN_CPYTHON
#define __Pyx_TypeCheck(obj, type) __Pyx_IsSubtype(Py_TYPE(obj), (PyTypeObject *)type)
static CYTHON_INLINE int __Pyx_IsSubtype(PyTypeObject *a, PyTypeObject *b);
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches(PyObject *err, PyObject *type);
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches2(PyObject *err, PyObject *type1, PyObject *type2);
#else
#define __Pyx_TypeCheck(obj, type) PyObject_TypeCheck(obj, (PyTypeObject *)type)
#define __Pyx_PyErr_GivenExceptionMatches(err, type) PyErr_GivenExceptionMatches(err, type)
#define __Pyx_PyErr_GivenExceptionMatches2(err, type1, type2) (PyErr_GivenExceptionMatches(err, type1) || PyErr_GivenExceptionMatches(err, type2))
#endif
#define __Pyx_PyException_Check(obj) __Pyx_TypeCheck(obj, PyExc_Exception)

/* PyObjectCall2Args.proto */
static CYTHON_UNUSED PyObject* __Pyx_PyObject_Call2Args(PyObject* function, PyObject* arg1, PyObject* arg2);

/* PySequenceContains.proto */
static CYTHON_INLINE int __Pyx_PySequence_ContainsTF(PyObject* item, PyObject* seq, int eq) {
    int result = PySequence_Contains(seq, item);
    return unlikely(result < 0) ? result : (result == (eq == Py_EQ));
}

/* SliceObject.proto */
static CYTHON_INLINE PyObject* __Pyx_PyObject_GetSlice(
        PyObject* obj, Py_ssize_t cstart, Py_ssize_t cstop,
        PyObject** py_start, PyObject** py_stop, PyObject** py_slice,
        int has_cstart, int has_cstop, int wraparound);

/* RaiseTooManyValuesToUnpack.proto */
static CYTHON_INLINE void __Pyx_RaiseTooManyValuesError(Py_ssize_t expected);

/* RaiseNeedMoreValuesToUnpack.proto */
static CYTHON_INLINE void __Pyx_RaiseNeedMoreValuesError(Py_ssize_t index);

/* IterFinish.proto */
static CYTHON_INLINE int __Pyx_IterFinish(void);

/* UnpackItemEndCheck.proto */
static int __Pyx_IternextUnpackEndCheck(PyObject *retval, Py_ssize_t expected);

/* GetItemInt.proto */
#define __Pyx_GetItemInt(o, i, type, is_signed, to_py_func, is_list, wraparound, boundscheck)\
    (__Pyx_fits_Py_ssize_t(i, type, is_signed) ?\
    __Pyx_GetItemInt_Fast(o, (Py_ssize_t)i, is_list, wraparound, boundscheck) :\
    (is_list ? (PyErr_SetString(PyExc_IndexError, "list index out of range"), (PyObject*)NULL) :\
               __Pyx_GetItemInt_Generic(o, to_py_func(i))))
#define __Pyx_GetItemInt_List(o, i, type, is_signed, to_py_func, is_list, wraparound, boundscheck)\
    (__Pyx_fits_Py_ssize_t(i, type, is_signed) ?\
    __Pyx_GetItemInt_List_Fast(o, (Py_ssize_t)i, wraparound, boundscheck) :\
    (PyErr_SetString(PyExc_IndexError, "list index out of range"), (PyObject*)NULL))
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_List_Fast(PyObject *o, Py_ssize_t i,
                                                              int wraparound, int boundscheck);
#define __Pyx_GetItemInt_Tuple(o, i, type, is_signed, to_py_func, is_list, wraparound, boundscheck)\
    (__Pyx_fits_Py_ssize_t(i, type, is_signed) ?\
    __Pyx_GetItemInt_Tuple_Fast(o, (Py_ssize_t)i, wraparound, boundscheck) :\
    (PyErr_SetString(PyExc_IndexError, "tuple index out of range"), (PyObject*)NULL))
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Tuple_Fast(PyObject *o, Py_ssize_t i,
                                                              int wraparound, int boundscheck);
static PyObject *__Pyx_GetItemInt_Generic(PyObject *o, PyObject* j);
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Fast(PyObject *o, Py_ssize_t i,
                                                     int is_list, int wraparound, int boundscheck);

/* ObjectGetItem.proto */
#if CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PyObject *__Pyx_PyObject_GetItem(PyObject *obj, PyObject* key);
#else
#define __Pyx_PyObject_GetItem(obj, key)  PyObject_GetItem(obj, key)
#endif

/* DictGetItem.proto */
#if PY_MAJOR_VERSION >= 3 && !CYTHON_COMPILING_IN_PYPY
static PyObject *__Pyx_PyDict_GetItem(PyObject *d, PyObject* key);
#define __Pyx_PyObject_Dict_GetItem(obj, name)\
    (likely(PyDict_CheckExact(obj)) ?\
     __Pyx_PyDict_GetItem(obj, name) : PyObject_GetItem(obj, name))
#else
#define __Pyx_PyDict_GetItem(d, key) PyObject_GetItem(d, key)
#define __Pyx_PyObject_Dict_GetItem(obj, name)  PyObject_GetItem(obj, name)
#endif

/* ListAppend.proto */
#if CYTHON_USE_PYLIST_INTERNALS && CYTHON_ASSUME_SAFE_MACROS
static CYTHON_INLINE int __Pyx_PyList_Append(PyObject* list, PyObject* x) {
    PyListObject* L = (PyListObject*) list;
    Py_ssize_t len = Py_SIZE(list);
    if (likely(L->allocated > len) & likely(len > (L->allocated >> 1))) {
        Py_INCREF(x);
        PyList_SET_ITEM(list, len, x);
        __Pyx_SET_SIZE(list, len + 1);
        return 0;
    }
    return PyList_Append(list, x);
}
#else
#define __Pyx_PyList_Append(L,x) PyList_Append(L,x)
#endif

/* BytesEquals.proto */
static CYTHON_INLINE int __Pyx_PyBytes_Equals(PyObject* s1, PyObject* s2, int equals);

/* UnicodeEquals.proto */
static CYTHON_INLINE int __Pyx_PyUnicode_Equals(PyObject* s1, PyObject* s2, int equals);

/* PyUnicode_Unicode.proto */
static CYTHON_INLINE PyObject* __Pyx_PyUnicode_Unicode(PyObject *obj);

/* BuildPyUnicode.proto */
static PyObject* __Pyx_PyUnicode_BuildFromAscii(Py_ssize_t ulength, char* chars, int clength,
                                                int prepend_sign, char padding_char);

/* CIntToPyUnicode.proto */
static CYTHON_INLINE PyObject* __Pyx_PyUnicode_From_Py_ssize_t(Py_ssize_t value, Py_ssize_t width, char padding_char, char format_char);

/* ListCompAppend.proto */
#if CYTHON_USE_PYLIST_INTERNALS && CYTHON_ASSUME_SAFE_MACROS
static CYTHON_INLINE int __Pyx_ListComp_Append(PyObject* list, PyObject* x) {
    PyListObject* L = (PyListObject*) list;
    Py_ssize_t len = Py_SIZE(list);
    if (likely(L->allocated > len)) {
        Py_INCREF(x);
        PyList_SET_ITEM(list, len, x);
        __Pyx_SET_SIZE(list, len + 1);
        return 0;
    }
    return PyList_Append(list, x);
}
#else
#define __Pyx_ListComp_Append(L,x) PyList_Append(L,x)
#endif

/* CIntToPyUnicode.proto */
static CYTHON_INLINE PyObject* __Pyx_PyUnicode_From_long(long value, Py_ssize_t width, char padding_char, char format_char);

/* PyIntCompare.proto */
static CYTHON_INLINE PyObject* __Pyx_PyInt_EqObjC(PyObject *op1, PyObject *op2, long intval, long inplace);

/* SliceTupleAndList.proto */
#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyList_GetSlice(PyObject* src, Py_ssize_t start, Py_ssize_t stop);
static CYTHON_INLINE PyObject* __Pyx_PyTuple_GetSlice(PyObject* src, Py_ssize_t start, Py_ssize_t stop);
#else
#define __Pyx_PyList_GetSlice(seq, start, stop)   PySequence_GetSlice(seq, start, stop)
#define __Pyx_PyTuple_GetSlice(seq, start, stop)  PySequence_GetSlice(seq, start, stop)
#endif

/* PyObject_GenericGetAttrNoDict.proto */
#if CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP && PY_VERSION_HEX < 0x03070000
static CYTHON_INLINE PyObject* __Pyx_PyObject_GenericGetAttrNoDict(PyObject* obj, PyObject* attr_name);
#else
#define __Pyx_PyObject_GenericGetAttrNoDict PyObject_GenericGetAttr
#endif

/* Import.proto */
static PyObject *__Pyx_Import(PyObject *name, PyObject *from_list, int level);

/* ImportFrom.proto */
static PyObject* __Pyx_ImportFrom(PyObject* module, PyObject* name);

/* FetchCommonType.proto */
static PyTypeObject* __Pyx_FetchCommonType(PyTypeObject* type);

/* CythonFunctionShared.proto */
#define __Pyx_CyFunction_USED 1
#define __Pyx_CYFUNCTION_STATICMETHOD  0x01
#define __Pyx_CYFUNCTION_CLASSMETHOD   0x02
#define __Pyx_CYFUNCTION_CCLASS        0x04
#define __Pyx_CyFunction_GetClosure(f)\
    (((__pyx_CyFunctionObject *) (f))->func_closure)
#define __Pyx_CyFunction_GetClassObj(f)\
    (((__pyx_CyFunctionObject *) (f))->func_classobj)
#define __Pyx_CyFunction_Defaults(type, f)\
    ((type *)(((__pyx_CyFunctionObject *) (f))->defaults))
#define __Pyx_CyFunction_SetDefaultsGetter(f, g)\
    ((__pyx_CyFunctionObject *) (f))->defaults_getter = (g)
typedef struct {
    PyCFunctionObject func;
#if PY_VERSION_HEX < 0x030500A0
    PyObject *func_weakreflist;
#endif
    PyObject *func_dict;
    PyObject *func_name;
    PyObject *func_qualname;
    PyObject *func_doc;
    PyObject *func_globals;
    PyObject *func_code;
    PyObject *func_closure;
    PyObject *func_classobj;
    void *defaults;
    int defaults_pyobjects;
    size_t defaults_size;  // used by FusedFunction for copying defaults
    int flags;
    PyObject *defaults_tuple;
    PyObject *defaults_kwdict;
    PyObject *(*defaults_getter)(PyObject *);
    PyObject *func_annotations;
} __pyx_CyFunctionObject;
static PyTypeObject *__pyx_CyFunctionType = 0;
#define __Pyx_CyFunction_Check(obj)  (__Pyx_TypeCheck(obj, __pyx_CyFunctionType))
static PyObject *__Pyx_CyFunction_Init(__pyx_CyFunctionObject* op, PyMethodDef *ml,
                                      int flags, PyObject* qualname,
                                      PyObject *self,
                                      PyObject *module, PyObject *globals,
                                      PyObject* code);
static CYTHON_INLINE void *__Pyx_CyFunction_InitDefaults(PyObject *m,
                                                         size_t size,
                                                         int pyobjects);
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsTuple(PyObject *m,
                                                            PyObject *tuple);
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsKwDict(PyObject *m,
                                                             PyObject *dict);
static CYTHON_INLINE void __Pyx_CyFunction_SetAnnotationsDict(PyObject *m,
                                                              PyObject *dict);
static int __pyx_CyFunction_init(void);

/* CythonFunction.proto */
static PyObject *__Pyx_CyFunction_New(PyMethodDef *ml,
                                      int flags, PyObject* qualname,
                                      PyObject *closure,
                                      PyObject *module, PyObject *globals,
                                      PyObject* code);

/* CLineInTraceback.proto */
#ifdef CYTHON_CLINE_IN_TRACEBACK
#define __Pyx_CLineForTraceback(tstate, c_line)  (((CYTHON_CLINE_IN_TRACEBACK)) ? c_line : 0)
#else
static int __Pyx_CLineForTraceback(PyThreadState *tstate, int c_line);
#endif

/* CodeObjectCache.proto */
typedef struct {
    PyCodeObject* code_object;
    int code_line;
} __Pyx_CodeObjectCacheEntry;
struct __Pyx_CodeObjectCache {
    int count;
    int max_count;
    __Pyx_CodeObjectCacheEntry* entries;
};
static struct __Pyx_CodeObjectCache __pyx_code_cache = {0,0,NULL};
static int __pyx_bisect_code_objects(__Pyx_CodeObjectCacheEntry* entries, int count, int code_line);
static PyCodeObject *__pyx_find_code_object(int code_line);
static void __pyx_insert_code_object(int code_line, PyCodeObject* code_object);

/* AddTraceback.proto */
static void __Pyx_AddTraceback(const char *funcname, int c_line,
                               int py_line, const char *filename);

/* CIntToPy.proto */
static CYTHON_INLINE PyObject* __Pyx_PyInt_From_long(long value);

/* CIntFromPy.proto */
static CYTHON_INLINE long __Pyx_PyInt_As_long(PyObject *);

/* CIntFromPy.proto */
static CYTHON_INLINE int __Pyx_PyInt_As_int(PyObject *);

/* RaiseException.proto */
static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb, PyObject *cause);

/* PyObjectGetMethod.proto */
static int __Pyx_PyObject_GetMethod(PyObject *obj, PyObject *name, PyObject **method);

/* PyObjectCallMethod1.proto */
static PyObject* __Pyx_PyObject_CallMethod1(PyObject* obj, PyObject* method_name, PyObject* arg);

/* CoroutineBase.proto */
typedef PyObject *(*__pyx_coroutine_body_t)(PyObject *, PyThreadState *, PyObject *);
#if CYTHON_USE_EXC_INFO_STACK
#define __Pyx_ExcInfoStruct  _PyErr_StackItem
#else
typedef struct {
    PyObject *exc_type;
    PyObject *exc_value;
    PyObject *exc_traceback;
} __Pyx_ExcInfoStruct;
#endif
typedef struct {
    PyObject_HEAD
    __pyx_coroutine_body_t body;
    PyObject *closure;
    __Pyx_ExcInfoStruct gi_exc_state;
    PyObject *gi_weakreflist;
    PyObject *classobj;
    PyObject *yieldfrom;
    PyObject *gi_name;
    PyObject *gi_qualname;
    PyObject *gi_modulename;
    PyObject *gi_code;
    int resume_label;
    char is_running;
} __pyx_CoroutineObject;
static __pyx_CoroutineObject *__Pyx__Coroutine_New(
    PyTypeObject *type, __pyx_coroutine_body_t body, PyObject *code, PyObject *closure,
    PyObject *name, PyObject *qualname, PyObject *module_name);
static __pyx_CoroutineObject *__Pyx__Coroutine_NewInit(
            __pyx_CoroutineObject *gen, __pyx_coroutine_body_t body, PyObject *code, PyObject *closure,
            PyObject *name, PyObject *qualname, PyObject *module_name);
static CYTHON_INLINE void __Pyx_Coroutine_ExceptionClear(__Pyx_ExcInfoStruct *self);
static int __Pyx_Coroutine_clear(PyObject *self);
static PyObject *__Pyx_Coroutine_Send(PyObject *self, PyObject *value);
static PyObject *__Pyx_Coroutine_Close(PyObject *self);
static PyObject *__Pyx_Coroutine_Throw(PyObject *gen, PyObject *args);
#if CYTHON_USE_EXC_INFO_STACK
#define __Pyx_Coroutine_SwapException(self)
#define __Pyx_Coroutine_ResetAndClearException(self)  __Pyx_Coroutine_ExceptionClear(&(self)->gi_exc_state)
#else
#define __Pyx_Coroutine_SwapException(self) {\
    __Pyx_ExceptionSwap(&(self)->gi_exc_state.exc_type, &(self)->gi_exc_state.exc_value, &(self)->gi_exc_state.exc_traceback);\
    __Pyx_Coroutine_ResetFrameBackpointer(&(self)->gi_exc_state);\
    }
#define __Pyx_Coroutine_ResetAndClearException(self) {\
    __Pyx_ExceptionReset((self)->gi_exc_state.exc_type, (self)->gi_exc_state.exc_value, (self)->gi_exc_state.exc_traceback);\
    (self)->gi_exc_state.exc_type = (self)->gi_exc_state.exc_value = (self)->gi_exc_state.exc_traceback = NULL;\
    }
#endif
#if CYTHON_FAST_THREAD_STATE
#define __Pyx_PyGen_FetchStopIterationValue(pvalue)\
    __Pyx_PyGen__FetchStopIterationValue(__pyx_tstate, pvalue)
#else
#define __Pyx_PyGen_FetchStopIterationValue(pvalue)\
    __Pyx_PyGen__FetchStopIterationValue(__Pyx_PyThreadState_Current, pvalue)
#endif
static int __Pyx_PyGen__FetchStopIterationValue(PyThreadState *tstate, PyObject **pvalue);
static CYTHON_INLINE void __Pyx_Coroutine_ResetFrameBackpointer(__Pyx_ExcInfoStruct *exc_state);

/* PatchModuleWithCoroutine.proto */
static PyObject* __Pyx_Coroutine_patch_module(PyObject* module, const char* py_code);

/* PatchGeneratorABC.proto */
static int __Pyx_patch_abc(void);

/* Generator.proto */
#define __Pyx_Generator_USED
static PyTypeObject *__pyx_GeneratorType = 0;
#define __Pyx_Generator_CheckExact(obj) (Py_TYPE(obj) == __pyx_GeneratorType)
#define __Pyx_Generator_New(body, code, closure, name, qualname, module_name)\
    __Pyx__Coroutine_New(__pyx_GeneratorType, body, code, closure, name, qualname, module_name)
static PyObject *__Pyx_Generator_Next(PyObject *self);
static int __pyx_Generator_init(void);

/* CheckBinaryVersion.proto */
static int __Pyx_check_binary_version(void);

/* InitStrings.proto */
static int __Pyx_InitStrings(__Pyx_StringTabEntry *t);


/* Module declarations from 'KakaoChat.kakao' */
static PyTypeObject *__pyx_ptype_9KakaoChat_5kakao___pyx_scope_struct__get_db = 0;
#define __Pyx_MODULE_NAME "KakaoChat.kakao"
extern int __pyx_module_is_main_KakaoChat__kakao;
int __pyx_module_is_main_KakaoChat__kakao = 0;

/* Implementation of 'KakaoChat.kakao' */
static PyObject *__pyx_builtin_print;
static PyObject *__pyx_builtin_range;
static const char __pyx_k_i[] = "i";
static const char __pyx_k__6[] = "[";
static const char __pyx_k__7[] = "]";
static const char __pyx_k__8[] = "";
static const char __pyx_k_db[] = "db";
static const char __pyx_k_id[] = "id";
static const char __pyx_k_2_0[] = "2.0";
static const char __pyx_k_DAY[] = "DAY";
static const char __pyx_k__10[] = "...";
static const char __pyx_k__11[] = " ";
static const char __pyx_k__12[] = "\354\225\204\354\243\274\353\214\200\355\225\231\352\265\220 \355\231\210\355\216\230\354\235\264\354\247\200 \354\204\234\353\262\204 \353\260\230\354\235\221\354\235\264 \353\212\246\352\263\240 \354\236\210\353\204\244\354\232\224. \354\236\240\354\213\234 \355\233\204 \353\213\244\354\213\234 \354\213\234\353\217\204\355\225\264\353\263\264\354\204\270\354\232\224.";
static const char __pyx_k__13[] = "\354\230\244\353\212\230";
static const char __pyx_k__14[] = "\354\235\264\354\240\204";
static const char __pyx_k__15[] = "\352\263\265\354\247\200\352\260\200 \354\227\206\354\212\265\353\213\210\353\213\244!";
static const char __pyx_k__16[] = ") ";
static const char __pyx_k__17[] = " \352\263\265\354\247\200";
static const char __pyx_k__19[] = "\352\263\265\354\234\240\355\225\230\352\270\260";
static const char __pyx_k__20[] = "\352\260\234 \353\215\224\353\263\264\352\270\260";
static const char __pyx_k__21[] = "\354\225\204\354\243\274\353\214\200\355\225\231\352\265\220 \352\263\265\354\247\200";
static const char __pyx_k__22[] = "\354\226\264\354\240\234 \352\263\265\354\247\200 \353\263\264\354\227\254\354\244\230";
static const char __pyx_k__23[] = "\354\226\264\354\240\234";
static const char __pyx_k__24[] = "\354\230\244\353\212\230 \352\263\265\354\247\200 \353\263\264\354\227\254\354\244\230";
static const char __pyx_k__26[] = "\355\225\231\354\202\254";
static const char __pyx_k__27[] = "\355\225\231\354\202\254\354\235\274\354\240\225";
static const char __pyx_k__28[] = "\353\271\204\352\265\220\352\263\274";
static const char __pyx_k__29[] = "\354\236\245\355\225\231";
static const char __pyx_k__30[] = "\354\267\250\354\227\205";
static const char __pyx_k__31[] = "\354\202\254\353\254\264";
static const char __pyx_k__32[] = "\355\226\211\354\202\254";
static const char __pyx_k__33[] = "\355\214\214\353\236\200\355\225\231\352\270\260\354\240\234";
static const char __pyx_k__34[] = "\355\225\231\354\210\240";
static const char __pyx_k__35[] = "\354\236\205\355\225\231";
static const char __pyx_k__36[] = "\352\270\260\355\203\200";
static const char __pyx_k__37[] = "\353\254\264\354\212\250 \352\263\265\354\247\200\353\245\274 \353\263\264\352\263\240 \354\213\266\354\234\274\354\213\240\352\260\200\354\232\224?";
static const char __pyx_k__40[] = "\355\214\214\353\236\200\355\225\231\352\270\260";
static const char __pyx_k__44[] = "\354\227\220 \352\264\200\355\225\234 \352\270\200\354\235\264 \354\227\206\354\226\264\354\232\224.";
static const char __pyx_k__46[] = " \352\262\260\352\263\274";
static const char __pyx_k__47[] = "\353\215\224\353\263\264\352\270\260";
static const char __pyx_k__48[] = "\355\231\210\355\216\230\354\235\264\354\247\200 \353\263\264\352\270\260";
static const char __pyx_k__49[] = "\353\223\261\353\241\235\352\270\210 \352\262\200\354\203\211";
static const char __pyx_k__50[] = "\354\235\264\353\262\244\355\212\270 \352\262\200\354\203\211";
static const char __pyx_k__51[] = "\354\275\224\353\241\234\353\202\230 \352\262\200\354\203\211";
static const char __pyx_k__54[] = " ~ ";
static const char __pyx_k__55[] = "*";
static const char __pyx_k__81[] = "_";
static const char __pyx_k__86[] = "/";
static const char __pyx_k_ask[] = ">>> /ask";
static const char __pyx_k_css[] = "css";
static const char __pyx_k_get[] = "get";
static const char __pyx_k_ids[] = "ids";
static const char __pyx_k_int[] = "int";
static const char __pyx_k_now[] = "now";
static const char __pyx_k_png[] = ".png";
static const char __pyx_k_run[] = "run";
static const char __pyx_k_ssl[] = "ssl";
static const char __pyx_k_url[] = "url";
static const char __pyx_k_web[] = "web";
static const char __pyx_k_2021[] = "2021 \352\262\200\354\203\211\352\263\274 \352\260\231\354\235\264 \352\262\200\354\203\211\354\226\264\353\245\274 \352\260\231\354\235\264 \354\236\205\353\240\245\355\225\230\354\204\270\354\232\224.";
static const char __pyx_k_Base[] = "Base";
static const char __pyx_k_Dict[] = "Dict";
static const char __pyx_k_None[] = "None";
static const char __pyx_k_args[] = "args";
static const char __pyx_k_bind[] = "bind";
static const char __pyx_k_card[] = "card";
static const char __pyx_k_cate[] = "cate";
static const char __pyx_k_crud[] = "crud";
static const char __pyx_k_data[] = "data";
static const char __pyx_k_date[] = "date";
static const char __pyx_k_days[] = "days";
static const char __pyx_k_desc[] = "desc";
static const char __pyx_k_host[] = "host";
static const char __pyx_k_href[] = "href";
static const char __pyx_k_html[] = "html";
static const char __pyx_k_info[] = "info";
static const char __pyx_k_last[] = "/last";
static const char __pyx_k_link[] = "link";
static const char __pyx_k_main[] = "__main__";
static const char __pyx_k_name[] = "__name__";
static const char __pyx_k_port[] = "port";
static const char __pyx_k_post[] = "post";
static const char __pyx_k_read[] = "read";
static const char __pyx_k_send[] = "send";
static const char __pyx_k_soup[] = "soup";
static const char __pyx_k_test[] = "__test__";
static const char __pyx_k_text[] = "text";
static const char __pyx_k_type[] = "type";
static const char __pyx_k_user[] = "user";
static const char __pyx_k_when[] = "when";
static const char __pyx_k_1_0_0[] = "1.0.0";
static const char __pyx_k_ask_2[] = "/ask";
static const char __pyx_k_cards[] = "cards";
static const char __pyx_k_close[] = "close";
static const char __pyx_k_dates[] = "dates";
static const char __pyx_k_hello[] = "hello";
static const char __pyx_k_items[] = "items";
static const char __pyx_k_label[] = "label";
static const char __pyx_k_posts[] = "posts";
static const char __pyx_k_print[] = "print";
static const char __pyx_k_quote[] = "quote";
static const char __pyx_k_range[] = "range";
static const char __pyx_k_sched[] = "sched";
static const char __pyx_k_share[] = "share";
static const char __pyx_k_strip[] = "strip";
static const char __pyx_k_throw[] = "throw";
static const char __pyx_k_title[] = "title";
static const char __pyx_k_today[] = "today";
static const char __pyx_k_utf_8[] = "utf-8";
static const char __pyx_k_y_m_d[] = "%y.%m.%d";
static const char __pyx_k_2021_2[] = "2021 \352\262\200\354\203\211";
static const char __pyx_k_action[] = "action";
static const char __pyx_k_append[] = "append";
static const char __pyx_k_choice[] = "choice";
static const char __pyx_k_date_2[] = ">>> /date";
static const char __pyx_k_date_3[] = "/date";
static const char __pyx_k_decode[] = "decode";
static const char __pyx_k_engine[] = "engine";
static const char __pyx_k_get_db[] = "get_db";
static const char __pyx_k_header[] = "header";
static const char __pyx_k_import[] = "__import__";
static const char __pyx_k_length[] = "length";
static const char __pyx_k_models[] = "models";
static const char __pyx_k_notice[] = "notice";
static const char __pyx_k_params[] = "params";
static const char __pyx_k_postId[] = "postId";
static const char __pyx_k_random[] = "random";
static const char __pyx_k_result[] = "result";
static const char __pyx_k_scheds[] = "scheds";
static const char __pyx_k_search[] = ">>> /search";
static const char __pyx_k_switch[] = "switch";
static const char __pyx_k_typing[] = "typing";
static const char __pyx_k_writer[] = "writer";
static const char __pyx_k_0_0_0_0[] = "0.0.0.0";
static const char __pyx_k_ADDRESS[] = "ADDRESS";
static const char __pyx_k_Depends[] = "Depends";
static const char __pyx_k_FastAPI[] = "FastAPI";
static const char __pyx_k_Session[] = "Session";
static const char __pyx_k_buttons[] = "buttons";
static const char __pyx_k_content[] = "content";
static const char __pyx_k_context[] = "context";
static const char __pyx_k_fastapi[] = "fastapi";
static const char __pyx_k_keyword[] = "keyword";
static const char __pyx_k_last_id[] = "last_id";
static const char __pyx_k_message[] = "message";
static const char __pyx_k_no_post[] = "no_post";
static const char __pyx_k_notices[] = "notices";
static const char __pyx_k_outputs[] = "outputs";
static const char __pyx_k_replace[] = "replace";
static const char __pyx_k_replies[] = "replies";
static const char __pyx_k_timeout[] = "timeout";
static const char __pyx_k_unicode[] = "unicode";
static const char __pyx_k_urlopen[] = "urlopen";
static const char __pyx_k_user_id[] = "user_id";
static const char __pyx_k_uvicorn[] = "uvicorn";
static const char __pyx_k_version[] = "version";
static const char __pyx_k_webLink[] = "webLink";
static const char __pyx_k_writers[] = "writers";
static const char __pyx_k_URLError[] = "URLError";
static const char __pyx_k_carousel[] = "carousel";
static const char __pyx_k_category[] = "category";
static const char __pyx_k_database[] = "database";
static const char __pyx_k_datetime[] = "datetime";
static const char __pyx_k_db_model[] = "db_model";
static const char __pyx_k_end_date[] = "end_date";
static const char __pyx_k_imageUrl[] = "imageUrl";
static const char __pyx_k_kakao_py[] = "kakao.py";
static const char __pyx_k_listCard[] = "listCard";
static const char __pyx_k_makeJSON[] = "makeJSON";
static const char __pyx_k_metadata[] = "metadata";
static const char __pyx_k_parseOne[] = "parseOne";
static const char __pyx_k_postDate[] = "postDate";
static const char __pyx_k_postLink[] = "postLink";
static const char __pyx_k_schedule[] = ">>> /schedule";
static const char __pyx_k_search_2[] = "/search";
static const char __pyx_k_strftime[] = "strftime";
static const char __pyx_k_sys_text[] = "sys_text";
static const char __pyx_k_template[] = "template";
static const char __pyx_k_HTTPError[] = "HTTPError";
static const char __pyx_k_basicCard[] = "basicCard";
static const char __pyx_k_card_imgs[] = "card_imgs";
static const char __pyx_k_duplicate[] = "duplicate";
static const char __pyx_k_log_level[] = "log_level";
static const char __pyx_k_message_2[] = ">>> /message";
static const char __pyx_k_message_3[] = "/message";
static const char __pyx_k_notice_id[] = "notice_id";
static const char __pyx_k_postTitle[] = "postTitle";
static const char __pyx_k_thumbnail[] = "thumbnail";
static const char __pyx_k_timedelta[] = "timedelta";
static const char __pyx_k_yesterday[] = "yesterday";
static const char __pyx_k_HTMLParser[] = "HTMLParser";
static const char __pyx_k_askKeyword[] = "askKeyword";
static const char __pyx_k_ask_filter[] = ">>> /ask/filter";
static const char __pyx_k_attributes[] = "attributes";
static const char __pyx_k_categories[] = "categories";
static const char __pyx_k_create_all[] = "create_all";
static const char __pyx_k_db_notices[] = "db_notices";
static const char __pyx_k_postWriter[] = "postWriter";
static const char __pyx_k_schedule_2[] = "/schedule";
static const char __pyx_k_schedule_3[] = "schedule";
static const char __pyx_k_searchDate[] = "searchDate";
static const char __pyx_k_simpleText[] = "simpleText";
static const char __pyx_k_start_date[] = "start_date";
static const char __pyx_k_webLinkUrl[] = "webLinkUrl";
static const char __pyx_k_application[] = "application";
static const char __pyx_k_checkUserDB[] = "checkUserDB";
static const char __pyx_k_create_user[] = "create_user";
static const char __pyx_k_description[] = "description";
static const char __pyx_k_getSchedule[] = "getSchedule";
static const char __pyx_k_messageText[] = "messageText";
static const char __pyx_k_span_b_date[] = "span.b-date";
static const char __pyx_k_userRequest[] = "userRequest";
static const char __pyx_k_JSONResponse[] = "JSONResponse";
static const char __pyx_k_SessionLocal[] = "SessionLocal";
static const char __pyx_k_TimeoutError[] = "TimeoutError";
static const char __pyx_k_articleLimit[] = "&articleLimit=";
static const char __pyx_k_ask_filter_2[] = "/ask/filter";
static const char __pyx_k_noticeLength[] = "noticeLength";
static const char __pyx_k_noticesToday[] = "noticesToday";
static const char __pyx_k_parseNotices[] = "parseNotices";
static const char __pyx_k_quickReplies[] = "quickReplies";
static const char __pyx_k_searchNotice[] = "searchNotice";
static const char __pyx_k_td_b_no_post[] = "td.b-no-post";
static const char __pyx_k_td_b_num_box[] = "td.b-num-box";
static const char __pyx_k_urllib_error[] = "urllib.error";
static const char __pyx_k_urllib_parse[] = "urllib.parse";
static const char __pyx_k_ajou_carousel[] = "ajou_carousel";
static const char __pyx_k_allow_headers[] = "allow_headers";
static const char __pyx_k_allow_methods[] = "allow_methods";
static const char __pyx_k_allow_origins[] = "allow_origins";
static const char __pyx_k_db_model_crud[] = "db_model.crud";
static const char __pyx_k_getLastNotice[] = "getLastNotice";
static const char __pyx_k_get_all_sched[] = "get_all_sched";
static const char __pyx_k_response_data[] = "response_data";
static const char __pyx_k_searchKeyword[] = "searchKeyword";
static const char __pyx_k_span_b_writer[] = "span.b-writer";
static const char __pyx_k_user_category[] = "user_category";
static const char __pyx_k_CORSMiddleware[] = "CORSMiddleware";
static const char __pyx_k_add_middleware[] = "add_middleware";
static const char __pyx_k_last_notice_id[] = "last_notice_id";
static const char __pyx_k_sqlalchemy_orm[] = "sqlalchemy.orm";
static const char __pyx_k_urllib_request[] = "urllib.request";
static const char __pyx_k_KakaoChat_kakao[] = "KakaoChat.kakao";
static const char __pyx_k_ajou_carousel_1[] = "ajou_carousel_1";
static const char __pyx_k_ajou_carousel_2[] = "ajou_carousel_2";
static const char __pyx_k_checkConnection[] = "checkConnection";
static const char __pyx_k_checkLastNotice[] = "checkLastNotice";
static const char __pyx_k_db_model_models[] = "db_model.models";
static const char __pyx_k_getTodayNotices[] = "getTodayNotices";
static const char __pyx_k_article_offset_0[] = "&article.offset=0";
static const char __pyx_k_db_model_schemas[] = "db_model.schemas";
static const char __pyx_k_makeCarouselCard[] = "makeCarouselCard";
static const char __pyx_k_makeJSONwithDate[] = "makeJSONwithDate";
static const char __pyx_k_updateLastNotice[] = "updateLastNotice";
static const char __pyx_k_allow_credentials[] = "allow_credentials";
static const char __pyx_k_db_model_database[] = "db_model.database";
static const char __pyx_k_div_b_title_box_a[] = "div.b-title-box > a";
static const char __pyx_k_fastapi_responses[] = "fastapi.responses";
static const char __pyx_k_for_Kakao_Chatbot[] = "for Kakao Chatbot";
static const char __pyx_k_selectolax_parser[] = "selectolax.parser";
static const char __pyx_k_cline_in_traceback[] = "cline_in_traceback";
static const char __pyx_k_makeTimeoutMessage[] = "makeTimeoutMessage";
static const char __pyx_k_update_last_notice[] = "update_last_notice";
static const char __pyx_k_Ajou_notices_server[] = "Ajou notices server";
static const char __pyx_k_getYesterdayNotices[] = "getYesterdayNotices";
static const char __pyx_k_get_user_by_user_id[] = "get_user_by_user_id";
static const char __pyx_k_get_notices_with_date[] = "get_notices_with_date";
static const char __pyx_k_mode_list_articleLimit[] = "?mode=list&articleLimit=";
static const char __pyx_k_mode_list_srCategoryId[] = "?mode=list&srCategoryId=";
static const char __pyx_k_fastapi_middleware_cors[] = "fastapi.middleware.cors";
static const char __pyx_k_create_unverified_context[] = "_create_unverified_context";
static const char __pyx_k_Seems_like_the_url_is_wrong_now[] = "Seems like the url is wrong now.";
static const char __pyx_k_https_raw_githubusercontent_com[] = "https://raw.githubusercontent.com/Alfex4936/kakaoChatbot-Ajou/main/imgs/";
static const char __pyx_k_mode_list_srSearchKey_srSearchV[] = "?mode=list&srSearchKey=&srSearchVal=";
static const char __pyx_k_srSearchKey_srSearchVal_article[] = "&srSearchKey=&srSearchVal=&articleLimit=";
static const char __pyx_k_It_s_taking_too_long_to_load_web[] = "It's taking too long to load website.";
static const char __pyx_k_Seems_like_the_server_is_down_no[] = "Seems like the server is down now.";
static const char __pyx_k_Welcome_the_server_is_running_we[] = "Welcome, the server is running well.";
static const char __pyx_k_http_k_kakaocdn_net_dn_APR96_btq[] = "http://k.kakaocdn.net/dn/APR96/btqqH7zLanY/kD5mIPX7TdD2NAxgP29cC0/1x1.jpg";
static const char __pyx_k_https_www_ajou_ac_kr_kr_ajou_not[] = "https://www.ajou.ac.kr/kr/ajou/notice.do";
static const char __pyx_k_https_www_ajou_ac_kr_kr_ajou_not_2[] = "https://www.ajou.ac.kr/kr/ajou/notice.do&?mode=list&srCategoryId=";
static const char __pyx_k_https_www_ajou_ac_kr_kr_ajou_not_3[] = "https://www.ajou.ac.kr/kr/ajou/notice.do&?mode=list&srSearchKey=&srSearchVal=";
static PyObject *__pyx_kp_u_0_0_0_0;
static PyObject *__pyx_kp_u_1_0_0;
static PyObject *__pyx_kp_u_2021;
static PyObject *__pyx_kp_u_2021_2;
static PyObject *__pyx_kp_u_2_0;
static PyObject *__pyx_n_s_ADDRESS;
static PyObject *__pyx_kp_u_Ajou_notices_server;
static PyObject *__pyx_n_s_Base;
static PyObject *__pyx_n_s_CORSMiddleware;
static PyObject *__pyx_n_s_DAY;
static PyObject *__pyx_n_s_Depends;
static PyObject *__pyx_n_s_Dict;
static PyObject *__pyx_n_s_FastAPI;
static PyObject *__pyx_n_s_HTMLParser;
static PyObject *__pyx_n_s_HTTPError;
static PyObject *__pyx_kp_u_It_s_taking_too_long_to_load_web;
static PyObject *__pyx_n_s_JSONResponse;
static PyObject *__pyx_n_s_KakaoChat_kakao;
static PyObject *__pyx_kp_u_None;
static PyObject *__pyx_kp_u_Seems_like_the_server_is_down_no;
static PyObject *__pyx_kp_u_Seems_like_the_url_is_wrong_now;
static PyObject *__pyx_n_s_Session;
static PyObject *__pyx_n_s_SessionLocal;
static PyObject *__pyx_n_s_TimeoutError;
static PyObject *__pyx_n_s_URLError;
static PyObject *__pyx_kp_u_Welcome_the_server_is_running_we;
static PyObject *__pyx_kp_u__10;
static PyObject *__pyx_kp_u__11;
static PyObject *__pyx_kp_u__12;
static PyObject *__pyx_n_u__13;
static PyObject *__pyx_n_u__14;
static PyObject *__pyx_kp_u__15;
static PyObject *__pyx_kp_u__16;
static PyObject *__pyx_kp_u__17;
static PyObject *__pyx_n_u__19;
static PyObject *__pyx_kp_u__20;
static PyObject *__pyx_kp_u__21;
static PyObject *__pyx_kp_u__22;
static PyObject *__pyx_n_u__23;
static PyObject *__pyx_kp_u__24;
static PyObject *__pyx_n_u__26;
static PyObject *__pyx_n_u__27;
static PyObject *__pyx_n_u__28;
static PyObject *__pyx_n_u__29;
static PyObject *__pyx_n_u__30;
static PyObject *__pyx_n_u__31;
static PyObject *__pyx_n_u__32;
static PyObject *__pyx_n_u__33;
static PyObject *__pyx_n_u__34;
static PyObject *__pyx_n_u__35;
static PyObject *__pyx_n_u__36;
static PyObject *__pyx_kp_u__37;
static PyObject *__pyx_n_u__40;
static PyObject *__pyx_kp_u__44;
static PyObject *__pyx_kp_u__46;
static PyObject *__pyx_n_u__47;
static PyObject *__pyx_kp_u__48;
static PyObject *__pyx_kp_u__49;
static PyObject *__pyx_kp_u__50;
static PyObject *__pyx_kp_u__51;
static PyObject *__pyx_kp_u__54;
static PyObject *__pyx_kp_u__55;
static PyObject *__pyx_kp_u__6;
static PyObject *__pyx_kp_u__7;
static PyObject *__pyx_kp_u__8;
static PyObject *__pyx_n_s__81;
static PyObject *__pyx_kp_u__86;
static PyObject *__pyx_n_u_action;
static PyObject *__pyx_n_s_add_middleware;
static PyObject *__pyx_n_u_ajou_carousel;
static PyObject *__pyx_n_u_ajou_carousel_1;
static PyObject *__pyx_n_u_ajou_carousel_2;
static PyObject *__pyx_n_s_allow_credentials;
static PyObject *__pyx_n_s_allow_headers;
static PyObject *__pyx_n_s_allow_methods;
static PyObject *__pyx_n_s_allow_origins;
static PyObject *__pyx_n_s_append;
static PyObject *__pyx_n_s_application;
static PyObject *__pyx_n_s_args;
static PyObject *__pyx_kp_u_articleLimit;
static PyObject *__pyx_kp_u_article_offset_0;
static PyObject *__pyx_kp_u_ask;
static PyObject *__pyx_n_s_askKeyword;
static PyObject *__pyx_kp_u_ask_2;
static PyObject *__pyx_kp_u_ask_filter;
static PyObject *__pyx_kp_u_ask_filter_2;
static PyObject *__pyx_n_s_attributes;
static PyObject *__pyx_n_u_basicCard;
static PyObject *__pyx_n_s_bind;
static PyObject *__pyx_n_u_buttons;
static PyObject *__pyx_n_s_card;
static PyObject *__pyx_n_s_card_imgs;
static PyObject *__pyx_n_s_cards;
static PyObject *__pyx_n_u_carousel;
static PyObject *__pyx_n_u_cate;
static PyObject *__pyx_n_s_categories;
static PyObject *__pyx_n_s_category;
static PyObject *__pyx_n_s_checkConnection;
static PyObject *__pyx_n_s_checkLastNotice;
static PyObject *__pyx_n_s_checkUserDB;
static PyObject *__pyx_n_s_choice;
static PyObject *__pyx_n_s_cline_in_traceback;
static PyObject *__pyx_n_s_close;
static PyObject *__pyx_n_s_content;
static PyObject *__pyx_n_s_context;
static PyObject *__pyx_n_s_create_all;
static PyObject *__pyx_n_s_create_unverified_context;
static PyObject *__pyx_n_s_create_user;
static PyObject *__pyx_n_s_crud;
static PyObject *__pyx_n_s_css;
static PyObject *__pyx_n_s_data;
static PyObject *__pyx_n_s_database;
static PyObject *__pyx_n_s_date;
static PyObject *__pyx_kp_u_date_2;
static PyObject *__pyx_kp_u_date_3;
static PyObject *__pyx_n_s_dates;
static PyObject *__pyx_n_s_datetime;
static PyObject *__pyx_n_s_days;
static PyObject *__pyx_n_s_db;
static PyObject *__pyx_n_s_db_model;
static PyObject *__pyx_n_s_db_model_crud;
static PyObject *__pyx_n_s_db_model_database;
static PyObject *__pyx_n_s_db_model_models;
static PyObject *__pyx_n_s_db_model_schemas;
static PyObject *__pyx_n_s_db_notices;
static PyObject *__pyx_n_s_decode;
static PyObject *__pyx_n_s_desc;
static PyObject *__pyx_n_s_description;
static PyObject *__pyx_n_u_description;
static PyObject *__pyx_kp_u_div_b_title_box_a;
static PyObject *__pyx_n_s_duplicate;
static PyObject *__pyx_n_s_end_date;
static PyObject *__pyx_n_s_engine;
static PyObject *__pyx_n_s_fastapi;
static PyObject *__pyx_n_s_fastapi_middleware_cors;
static PyObject *__pyx_n_s_fastapi_responses;
static PyObject *__pyx_kp_u_for_Kakao_Chatbot;
static PyObject *__pyx_n_s_get;
static PyObject *__pyx_n_s_getLastNotice;
static PyObject *__pyx_n_s_getSchedule;
static PyObject *__pyx_n_s_getTodayNotices;
static PyObject *__pyx_n_s_getYesterdayNotices;
static PyObject *__pyx_n_s_get_all_sched;
static PyObject *__pyx_n_s_get_db;
static PyObject *__pyx_n_s_get_notices_with_date;
static PyObject *__pyx_n_s_get_user_by_user_id;
static PyObject *__pyx_n_u_header;
static PyObject *__pyx_n_s_hello;
static PyObject *__pyx_n_s_host;
static PyObject *__pyx_n_u_href;
static PyObject *__pyx_n_s_html;
static PyObject *__pyx_kp_u_http_k_kakaocdn_net_dn_APR96_btq;
static PyObject *__pyx_kp_u_https_raw_githubusercontent_com;
static PyObject *__pyx_kp_u_https_www_ajou_ac_kr_kr_ajou_not;
static PyObject *__pyx_kp_u_https_www_ajou_ac_kr_kr_ajou_not_2;
static PyObject *__pyx_kp_u_https_www_ajou_ac_kr_kr_ajou_not_3;
static PyObject *__pyx_n_s_i;
static PyObject *__pyx_n_s_id;
static PyObject *__pyx_n_u_id;
static PyObject *__pyx_n_s_ids;
static PyObject *__pyx_n_u_imageUrl;
static PyObject *__pyx_n_s_import;
static PyObject *__pyx_n_u_info;
static PyObject *__pyx_n_u_int;
static PyObject *__pyx_n_u_items;
static PyObject *__pyx_kp_s_kakao_py;
static PyObject *__pyx_n_s_keyword;
static PyObject *__pyx_n_u_label;
static PyObject *__pyx_kp_u_last;
static PyObject *__pyx_n_s_last_id;
static PyObject *__pyx_n_s_last_notice_id;
static PyObject *__pyx_n_s_length;
static PyObject *__pyx_n_s_link;
static PyObject *__pyx_n_u_link;
static PyObject *__pyx_n_u_listCard;
static PyObject *__pyx_n_s_log_level;
static PyObject *__pyx_n_s_main;
static PyObject *__pyx_n_u_main;
static PyObject *__pyx_n_s_makeCarouselCard;
static PyObject *__pyx_n_s_makeJSON;
static PyObject *__pyx_n_s_makeJSONwithDate;
static PyObject *__pyx_n_s_makeTimeoutMessage;
static PyObject *__pyx_n_s_message;
static PyObject *__pyx_n_u_message;
static PyObject *__pyx_n_u_messageText;
static PyObject *__pyx_kp_u_message_2;
static PyObject *__pyx_kp_u_message_3;
static PyObject *__pyx_n_s_metadata;
static PyObject *__pyx_kp_u_mode_list_articleLimit;
static PyObject *__pyx_kp_u_mode_list_srCategoryId;
static PyObject *__pyx_kp_u_mode_list_srSearchKey_srSearchV;
static PyObject *__pyx_n_s_models;
static PyObject *__pyx_n_s_name;
static PyObject *__pyx_n_s_no_post;
static PyObject *__pyx_n_s_notice;
static PyObject *__pyx_n_s_noticeLength;
static PyObject *__pyx_n_s_notice_id;
static PyObject *__pyx_n_s_notices;
static PyObject *__pyx_n_s_noticesToday;
static PyObject *__pyx_n_s_now;
static PyObject *__pyx_n_u_outputs;
static PyObject *__pyx_n_u_params;
static PyObject *__pyx_n_s_parseNotices;
static PyObject *__pyx_n_s_parseOne;
static PyObject *__pyx_kp_u_png;
static PyObject *__pyx_n_s_port;
static PyObject *__pyx_n_s_post;
static PyObject *__pyx_n_s_postDate;
static PyObject *__pyx_n_s_postId;
static PyObject *__pyx_n_s_postLink;
static PyObject *__pyx_n_s_postTitle;
static PyObject *__pyx_n_s_postWriter;
static PyObject *__pyx_n_s_posts;
static PyObject *__pyx_n_s_print;
static PyObject *__pyx_n_u_quickReplies;
static PyObject *__pyx_n_s_quote;
static PyObject *__pyx_n_s_random;
static PyObject *__pyx_n_s_range;
static PyObject *__pyx_n_s_read;
static PyObject *__pyx_n_s_replace;
static PyObject *__pyx_n_s_replies;
static PyObject *__pyx_n_s_response_data;
static PyObject *__pyx_n_s_result;
static PyObject *__pyx_n_s_run;
static PyObject *__pyx_n_s_sched;
static PyObject *__pyx_n_s_scheds;
static PyObject *__pyx_kp_u_schedule;
static PyObject *__pyx_kp_u_schedule_2;
static PyObject *__pyx_n_s_schedule_3;
static PyObject *__pyx_kp_u_search;
static PyObject *__pyx_n_s_searchDate;
static PyObject *__pyx_n_s_searchKeyword;
static PyObject *__pyx_n_s_searchNotice;
static PyObject *__pyx_kp_u_search_2;
static PyObject *__pyx_n_s_selectolax_parser;
static PyObject *__pyx_n_s_send;
static PyObject *__pyx_n_u_share;
static PyObject *__pyx_n_u_simpleText;
static PyObject *__pyx_n_s_soup;
static PyObject *__pyx_kp_u_span_b_date;
static PyObject *__pyx_kp_u_span_b_writer;
static PyObject *__pyx_n_s_sqlalchemy_orm;
static PyObject *__pyx_kp_u_srSearchKey_srSearchVal_article;
static PyObject *__pyx_n_s_ssl;
static PyObject *__pyx_n_s_start_date;
static PyObject *__pyx_n_s_strftime;
static PyObject *__pyx_n_s_strip;
static PyObject *__pyx_n_s_switch;
static PyObject *__pyx_n_u_sys_text;
static PyObject *__pyx_kp_u_td_b_no_post;
static PyObject *__pyx_kp_u_td_b_num_box;
static PyObject *__pyx_n_u_template;
static PyObject *__pyx_n_s_test;
static PyObject *__pyx_n_s_text;
static PyObject *__pyx_n_u_text;
static PyObject *__pyx_n_s_throw;
static PyObject *__pyx_n_u_thumbnail;
static PyObject *__pyx_n_s_timedelta;
static PyObject *__pyx_n_s_timeout;
static PyObject *__pyx_n_s_title;
static PyObject *__pyx_n_u_title;
static PyObject *__pyx_n_u_today;
static PyObject *__pyx_n_u_type;
static PyObject *__pyx_n_s_typing;
static PyObject *__pyx_n_u_unicode;
static PyObject *__pyx_n_s_updateLastNotice;
static PyObject *__pyx_n_s_update_last_notice;
static PyObject *__pyx_n_s_url;
static PyObject *__pyx_n_s_urllib_error;
static PyObject *__pyx_n_s_urllib_parse;
static PyObject *__pyx_n_s_urllib_request;
static PyObject *__pyx_n_s_urlopen;
static PyObject *__pyx_n_s_user;
static PyObject *__pyx_n_u_user;
static PyObject *__pyx_n_u_userRequest;
static PyObject *__pyx_n_s_user_category;
static PyObject *__pyx_n_s_user_id;
static PyObject *__pyx_kp_u_utf_8;
static PyObject *__pyx_n_s_uvicorn;
static PyObject *__pyx_n_s_version;
static PyObject *__pyx_n_u_version;
static PyObject *__pyx_n_u_web;
static PyObject *__pyx_n_u_webLink;
static PyObject *__pyx_n_u_webLinkUrl;
static PyObject *__pyx_n_s_when;
static PyObject *__pyx_n_u_when;
static PyObject *__pyx_n_s_writer;
static PyObject *__pyx_n_s_writers;
static PyObject *__pyx_kp_u_y_m_d;
static PyObject *__pyx_n_u_yesterday;
static PyObject *__pyx_pf_9KakaoChat_5kakao_get_db(CYTHON_UNUSED PyObject *__pyx_self); /* proto */
static PyObject *__pyx_pf_9KakaoChat_5kakao_3checkUserDB(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_db, PyObject *__pyx_v_user_id); /* proto */
static PyObject *__pyx_pf_9KakaoChat_5kakao_5checkLastNotice(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_db, PyObject *__pyx_v_user_id); /* proto */
static PyObject *__pyx_pf_9KakaoChat_5kakao_7getSchedule(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_db); /* proto */
static PyObject *__pyx_pf_9KakaoChat_5kakao_9updateLastNotice(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_db, PyObject *__pyx_v_user_id, PyObject *__pyx_v_notice_id); /* proto */
static PyObject *__pyx_pf_9KakaoChat_5kakao_11parseNotices(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_url, PyObject *__pyx_v_length); /* proto */
static PyObject *__pyx_pf_9KakaoChat_5kakao_13checkConnection(CYTHON_UNUSED PyObject *__pyx_self); /* proto */
static PyObject *__pyx_pf_9KakaoChat_5kakao_15makeJSON(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_postId, PyObject *__pyx_v_postTitle, CYTHON_UNUSED PyObject *__pyx_v_postDate, PyObject *__pyx_v_postLink, PyObject *__pyx_v_postWriter); /* proto */
static PyObject *__pyx_pf_9KakaoChat_5kakao_17makeJSONwithDate(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_postId, PyObject *__pyx_v_postTitle, PyObject *__pyx_v_postDate, PyObject *__pyx_v_postLink, PyObject *__pyx_v_postWriter); /* proto */
static PyObject *__pyx_pf_9KakaoChat_5kakao_19makeTimeoutMessage(CYTHON_UNUSED PyObject *__pyx_self); /* proto */
static PyObject *__pyx_pf_9KakaoChat_5kakao_21makeCarouselCard(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_title, PyObject *__pyx_v_desc); /* proto */
static PyObject *__pyx_pf_9KakaoChat_5kakao_23getTodayNotices(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_db, PyObject *__pyx_v_now, PyObject *__pyx_v_user_id); /* proto */
static PyObject *__pyx_pf_9KakaoChat_5kakao_25getYesterdayNotices(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_db, PyObject *__pyx_v_now); /* proto */
static PyObject *__pyx_pf_9KakaoChat_5kakao_27getLastNotice(CYTHON_UNUSED PyObject *__pyx_self); /* proto */
static PyObject *__pyx_pf_9KakaoChat_5kakao_29switch(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_db, PyObject *__pyx_v_when, PyObject *__pyx_v_now, PyObject *__pyx_v_user_id); /* proto */
static PyObject *__pyx_pf_9KakaoChat_5kakao_31hello(CYTHON_UNUSED PyObject *__pyx_self); /* proto */
static PyObject *__pyx_pf_9KakaoChat_5kakao_33askKeyword(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v__); /* proto */
static PyObject *__pyx_pf_9KakaoChat_5kakao_35searchDate(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_content); /* proto */
static PyObject *__pyx_pf_9KakaoChat_5kakao_47__defaults__(CYTHON_UNUSED PyObject *__pyx_self); /* proto */
static PyObject *__pyx_pf_9KakaoChat_5kakao_37searchKeyword(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_content, PyObject *__pyx_v_db); /* proto */
static PyObject *__pyx_pf_9KakaoChat_5kakao_49__defaults__(CYTHON_UNUSED PyObject *__pyx_self); /* proto */
static PyObject *__pyx_pf_9KakaoChat_5kakao_39parseOne(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_content, PyObject *__pyx_v_db); /* proto */
static PyObject *__pyx_pf_9KakaoChat_5kakao_51__defaults__(CYTHON_UNUSED PyObject *__pyx_self); /* proto */
static PyObject *__pyx_pf_9KakaoChat_5kakao_41searchNotice(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_content, PyObject *__pyx_v_db); /* proto */
static PyObject *__pyx_pf_9KakaoChat_5kakao_53__defaults__(CYTHON_UNUSED PyObject *__pyx_self); /* proto */
static PyObject *__pyx_pf_9KakaoChat_5kakao_43message(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_content, PyObject *__pyx_v_db); /* proto */
static PyObject *__pyx_pf_9KakaoChat_5kakao_55__defaults__(CYTHON_UNUSED PyObject *__pyx_self); /* proto */
static PyObject *__pyx_pf_9KakaoChat_5kakao_45schedule(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_content, PyObject *__pyx_v_db); /* proto */
static PyObject *__pyx_tp_new_9KakaoChat_5kakao___pyx_scope_struct__get_db(PyTypeObject *t, PyObject *a, PyObject *k); /*proto*/
static PyObject *__pyx_float_2_0;
static PyObject *__pyx_int_0;
static PyObject *__pyx_int_1;
static PyObject *__pyx_int_2;
static PyObject *__pyx_int_3;
static PyObject *__pyx_int_4;
static PyObject *__pyx_int_5;
static PyObject *__pyx_int_6;
static PyObject *__pyx_int_7;
static PyObject *__pyx_int_8;
static PyObject *__pyx_int_10;
static PyObject *__pyx_int_12;
static PyObject *__pyx_int_32;
static PyObject *__pyx_int_166;
static PyObject *__pyx_int_167;
static PyObject *__pyx_int_168;
static PyObject *__pyx_int_8000;
static PyObject *__pyx_codeobj_;
static PyObject *__pyx_slice__9;
static PyObject *__pyx_tuple__2;
static PyObject *__pyx_tuple__3;
static PyObject *__pyx_tuple__4;
static PyObject *__pyx_tuple__5;
static PyObject *__pyx_slice__18;
static PyObject *__pyx_slice__45;
static PyObject *__pyx_tuple__25;
static PyObject *__pyx_tuple__38;
static PyObject *__pyx_tuple__39;
static PyObject *__pyx_tuple__41;
static PyObject *__pyx_tuple__42;
static PyObject *__pyx_tuple__43;
static PyObject *__pyx_tuple__52;
static PyObject *__pyx_tuple__53;
static PyObject *__pyx_tuple__56;
static PyObject *__pyx_tuple__57;
static PyObject *__pyx_tuple__59;
static PyObject *__pyx_tuple__61;
static PyObject *__pyx_tuple__63;
static PyObject *__pyx_tuple__65;
static PyObject *__pyx_tuple__67;
static PyObject *__pyx_tuple__68;
static PyObject *__pyx_tuple__70;
static PyObject *__pyx_tuple__72;
static PyObject *__pyx_tuple__75;
static PyObject *__pyx_tuple__77;
static PyObject *__pyx_tuple__79;
static PyObject *__pyx_tuple__82;
static PyObject *__pyx_tuple__84;
static PyObject *__pyx_tuple__87;
static PyObject *__pyx_tuple__89;
static PyObject *__pyx_tuple__90;
static PyObject *__pyx_tuple__92;
static PyObject *__pyx_tuple__93;
static PyObject *__pyx_tuple__95;
static PyObject *__pyx_tuple__96;
static PyObject *__pyx_tuple__98;
static PyObject *__pyx_tuple__100;
static PyObject *__pyx_tuple__101;
static PyObject *__pyx_tuple__103;
static PyObject *__pyx_tuple__104;
static PyObject *__pyx_tuple__106;
static PyObject *__pyx_tuple__107;
static PyObject *__pyx_codeobj__58;
static PyObject *__pyx_codeobj__60;
static PyObject *__pyx_codeobj__62;
static PyObject *__pyx_codeobj__64;
static PyObject *__pyx_codeobj__66;
static PyObject *__pyx_codeobj__69;
static PyObject *__pyx_codeobj__71;
static PyObject *__pyx_codeobj__73;
static PyObject *__pyx_codeobj__74;
static PyObject *__pyx_codeobj__76;
static PyObject *__pyx_codeobj__78;
static PyObject *__pyx_codeobj__80;
static PyObject *__pyx_codeobj__83;
static PyObject *__pyx_codeobj__85;
static PyObject *__pyx_codeobj__88;
static PyObject *__pyx_codeobj__91;
static PyObject *__pyx_codeobj__94;
static PyObject *__pyx_codeobj__97;
static PyObject *__pyx_codeobj__99;
static PyObject *__pyx_codeobj__102;
static PyObject *__pyx_codeobj__105;
static PyObject *__pyx_codeobj__108;
/* Late includes */
static PyObject *__pyx_gb_9KakaoChat_5kakao_2generator(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value); /* proto */

/* "KakaoChat/kakao.py":39
 * 
 * # Dependency
 * def get_db():             # <<<<<<<<<<<<<<
 *     db = db_model.database.SessionLocal()
 *     try:
 */

/* Python wrapper */
static PyObject *__pyx_pw_9KakaoChat_5kakao_1get_db(PyObject *__pyx_self, CYTHON_UNUSED PyObject *unused); /*proto*/
static PyMethodDef __pyx_mdef_9KakaoChat_5kakao_1get_db = {"get_db", (PyCFunction)__pyx_pw_9KakaoChat_5kakao_1get_db, METH_NOARGS, 0};
static PyObject *__pyx_pw_9KakaoChat_5kakao_1get_db(PyObject *__pyx_self, CYTHON_UNUSED PyObject *unused) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("get_db (wrapper)", 0);
  __pyx_r = __pyx_pf_9KakaoChat_5kakao_get_db(__pyx_self);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_9KakaoChat_5kakao_get_db(CYTHON_UNUSED PyObject *__pyx_self) {
  struct __pyx_obj_9KakaoChat_5kakao___pyx_scope_struct__get_db *__pyx_cur_scope;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("get_db", 0);
  __pyx_cur_scope = (struct __pyx_obj_9KakaoChat_5kakao___pyx_scope_struct__get_db *)__pyx_tp_new_9KakaoChat_5kakao___pyx_scope_struct__get_db(__pyx_ptype_9KakaoChat_5kakao___pyx_scope_struct__get_db, __pyx_empty_tuple, NULL);
  if (unlikely(!__pyx_cur_scope)) {
    __pyx_cur_scope = ((struct __pyx_obj_9KakaoChat_5kakao___pyx_scope_struct__get_db *)Py_None);
    __Pyx_INCREF(Py_None);
    __PYX_ERR(0, 39, __pyx_L1_error)
  } else {
    __Pyx_GOTREF(__pyx_cur_scope);
  }
  {
    __pyx_CoroutineObject *gen = __Pyx_Generator_New((__pyx_coroutine_body_t) __pyx_gb_9KakaoChat_5kakao_2generator, __pyx_codeobj_, (PyObject *) __pyx_cur_scope, __pyx_n_s_get_db, __pyx_n_s_get_db, __pyx_n_s_KakaoChat_kakao); if (unlikely(!gen)) __PYX_ERR(0, 39, __pyx_L1_error)
    __Pyx_DECREF(__pyx_cur_scope);
    __Pyx_RefNannyFinishContext();
    return (PyObject *) gen;
  }

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_AddTraceback("KakaoChat.kakao.get_db", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __Pyx_DECREF(((PyObject *)__pyx_cur_scope));
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_gb_9KakaoChat_5kakao_2generator(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value) /* generator body */
{
  struct __pyx_obj_9KakaoChat_5kakao___pyx_scope_struct__get_db *__pyx_cur_scope = ((struct __pyx_obj_9KakaoChat_5kakao___pyx_scope_struct__get_db *)__pyx_generator->closure);
  PyObject *__pyx_r = NULL;
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_t_4;
  int __pyx_t_5;
  char const *__pyx_t_6;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  PyObject *__pyx_t_9 = NULL;
  PyObject *__pyx_t_10 = NULL;
  PyObject *__pyx_t_11 = NULL;
  PyObject *__pyx_t_12 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("get_db", 0);
  switch (__pyx_generator->resume_label) {
    case 0: goto __pyx_L3_first_run;
    case 1: goto __pyx_L7_resume_from_yield;
    default: /* CPython raises the right error here */
    __Pyx_RefNannyFinishContext();
    return NULL;
  }
  __pyx_L3_first_run:;
  if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 39, __pyx_L1_error)

  /* "KakaoChat/kakao.py":40
 * # Dependency
 * def get_db():
 *     db = db_model.database.SessionLocal()             # <<<<<<<<<<<<<<
 *     try:
 *         yield db
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_db_model); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 40, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_database); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 40, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_SessionLocal); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 40, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 40, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_GIVEREF(__pyx_t_1);
  __pyx_cur_scope->__pyx_v_db = __pyx_t_1;
  __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":41
 * def get_db():
 *     db = db_model.database.SessionLocal()
 *     try:             # <<<<<<<<<<<<<<
 *         yield db
 *     finally:
 */
  /*try:*/ {

    /* "KakaoChat/kakao.py":42
 *     db = db_model.database.SessionLocal()
 *     try:
 *         yield db             # <<<<<<<<<<<<<<
 *     finally:
 *         db.close()
 */
    __Pyx_INCREF(__pyx_cur_scope->__pyx_v_db);
    __pyx_r = __pyx_cur_scope->__pyx_v_db;
    __Pyx_XGIVEREF(__pyx_r);
    __Pyx_RefNannyFinishContext();
    __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
    /* return from generator, yielding value */
    __pyx_generator->resume_label = 1;
    return __pyx_r;
    __pyx_L7_resume_from_yield:;
    if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 42, __pyx_L5_error)
  }

  /* "KakaoChat/kakao.py":44
 *         yield db
 *     finally:
 *         db.close()             # <<<<<<<<<<<<<<
 * 
 * 
 */
  /*finally:*/ {
    /*normal exit:*/{
      __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_cur_scope->__pyx_v_db, __pyx_n_s_close); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 44, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __pyx_t_3 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
        __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
        if (likely(__pyx_t_3)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
          __Pyx_INCREF(__pyx_t_3);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_2, function);
        }
      }
      __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
      __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
      if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 44, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      goto __pyx_L6;
    }
    __pyx_L5_error:;
    /*exception exit:*/{
      __Pyx_PyThreadState_assign
      __pyx_t_7 = 0; __pyx_t_8 = 0; __pyx_t_9 = 0; __pyx_t_10 = 0; __pyx_t_11 = 0; __pyx_t_12 = 0;
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
      if (PY_MAJOR_VERSION >= 3) __Pyx_ExceptionSwap(&__pyx_t_10, &__pyx_t_11, &__pyx_t_12);
      if ((PY_MAJOR_VERSION < 3) || unlikely(__Pyx_GetException(&__pyx_t_7, &__pyx_t_8, &__pyx_t_9) < 0)) __Pyx_ErrFetch(&__pyx_t_7, &__pyx_t_8, &__pyx_t_9);
      __Pyx_XGOTREF(__pyx_t_7);
      __Pyx_XGOTREF(__pyx_t_8);
      __Pyx_XGOTREF(__pyx_t_9);
      __Pyx_XGOTREF(__pyx_t_10);
      __Pyx_XGOTREF(__pyx_t_11);
      __Pyx_XGOTREF(__pyx_t_12);
      __pyx_t_4 = __pyx_lineno; __pyx_t_5 = __pyx_clineno; __pyx_t_6 = __pyx_filename;
      {
        __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_cur_scope->__pyx_v_db, __pyx_n_s_close); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 44, __pyx_L9_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_3 = NULL;
        if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
          __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
          if (likely(__pyx_t_3)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
            __Pyx_INCREF(__pyx_t_3);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_2, function);
          }
        }
        __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
        __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
        if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 44, __pyx_L9_error)
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      }
      if (PY_MAJOR_VERSION >= 3) {
        __Pyx_XGIVEREF(__pyx_t_10);
        __Pyx_XGIVEREF(__pyx_t_11);
        __Pyx_XGIVEREF(__pyx_t_12);
        __Pyx_ExceptionReset(__pyx_t_10, __pyx_t_11, __pyx_t_12);
      }
      __Pyx_XGIVEREF(__pyx_t_7);
      __Pyx_XGIVEREF(__pyx_t_8);
      __Pyx_XGIVEREF(__pyx_t_9);
      __Pyx_ErrRestore(__pyx_t_7, __pyx_t_8, __pyx_t_9);
      __pyx_t_7 = 0; __pyx_t_8 = 0; __pyx_t_9 = 0; __pyx_t_10 = 0; __pyx_t_11 = 0; __pyx_t_12 = 0;
      __pyx_lineno = __pyx_t_4; __pyx_clineno = __pyx_t_5; __pyx_filename = __pyx_t_6;
      goto __pyx_L1_error;
      __pyx_L9_error:;
      if (PY_MAJOR_VERSION >= 3) {
        __Pyx_XGIVEREF(__pyx_t_10);
        __Pyx_XGIVEREF(__pyx_t_11);
        __Pyx_XGIVEREF(__pyx_t_12);
        __Pyx_ExceptionReset(__pyx_t_10, __pyx_t_11, __pyx_t_12);
      }
      __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
      __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
      __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
      __pyx_t_10 = 0; __pyx_t_11 = 0; __pyx_t_12 = 0;
      goto __pyx_L1_error;
    }
    __pyx_L6:;
  }
  CYTHON_MAYBE_UNUSED_VAR(__pyx_cur_scope);

  /* "KakaoChat/kakao.py":39
 * 
 * # Dependency
 * def get_db():             # <<<<<<<<<<<<<<
 *     db = db_model.database.SessionLocal()
 *     try:
 */

  /* function exit code */
  PyErr_SetNone(PyExc_StopIteration);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("get_db", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_r); __pyx_r = 0;
  #if !CYTHON_USE_EXC_INFO_STACK
  __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
  #endif
  __pyx_generator->resume_label = -1;
  __Pyx_Coroutine_clear((PyObject*)__pyx_generator);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "KakaoChat/kakao.py":47
 * 
 * 
 * def checkUserDB(db: Session, user_id: str):             # <<<<<<<<<<<<<<
 *     user = db_model.crud.get_user_by_user_id(db=db, user_id=user_id)
 *     if user is None:
 */

/* Python wrapper */
static PyObject *__pyx_pw_9KakaoChat_5kakao_4checkUserDB(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_9KakaoChat_5kakao_4checkUserDB = {"checkUserDB", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_9KakaoChat_5kakao_4checkUserDB, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_9KakaoChat_5kakao_4checkUserDB(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_db = 0;
  PyObject *__pyx_v_user_id = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("checkUserDB (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_db,&__pyx_n_s_user_id,0};
    PyObject* values[2] = {0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_db)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_user_id)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("checkUserDB", 1, 2, 2, 1); __PYX_ERR(0, 47, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "checkUserDB") < 0)) __PYX_ERR(0, 47, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_db = values[0];
    __pyx_v_user_id = ((PyObject*)values[1]);
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("checkUserDB", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 47, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("KakaoChat.kakao.checkUserDB", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  if (unlikely(!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_user_id), (&PyUnicode_Type), 1, "user_id", 1))) __PYX_ERR(0, 47, __pyx_L1_error)
  __pyx_r = __pyx_pf_9KakaoChat_5kakao_3checkUserDB(__pyx_self, __pyx_v_db, __pyx_v_user_id);

  /* function exit code */
  goto __pyx_L0;
  __pyx_L1_error:;
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_9KakaoChat_5kakao_3checkUserDB(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_db, PyObject *__pyx_v_user_id) {
  PyObject *__pyx_v_user = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_t_4;
  int __pyx_t_5;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("checkUserDB", 0);

  /* "KakaoChat/kakao.py":48
 * 
 * def checkUserDB(db: Session, user_id: str):
 *     user = db_model.crud.get_user_by_user_id(db=db, user_id=user_id)             # <<<<<<<<<<<<<<
 *     if user is None:
 *         user = db_model.crud.create_user(db=db, user_id=user_id)
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_db_model); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 48, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_crud); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 48, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_get_user_by_user_id); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 48, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 48, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_db, __pyx_v_db) < 0) __PYX_ERR(0, 48, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_user_id, __pyx_v_user_id) < 0) __PYX_ERR(0, 48, __pyx_L1_error)
  __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_empty_tuple, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 48, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_user = __pyx_t_3;
  __pyx_t_3 = 0;

  /* "KakaoChat/kakao.py":49
 * def checkUserDB(db: Session, user_id: str):
 *     user = db_model.crud.get_user_by_user_id(db=db, user_id=user_id)
 *     if user is None:             # <<<<<<<<<<<<<<
 *         user = db_model.crud.create_user(db=db, user_id=user_id)
 *     return user
 */
  __pyx_t_4 = (__pyx_v_user == Py_None);
  __pyx_t_5 = (__pyx_t_4 != 0);
  if (__pyx_t_5) {

    /* "KakaoChat/kakao.py":50
 *     user = db_model.crud.get_user_by_user_id(db=db, user_id=user_id)
 *     if user is None:
 *         user = db_model.crud.create_user(db=db, user_id=user_id)             # <<<<<<<<<<<<<<
 *     return user
 * 
 */
    __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_db_model); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 50, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_crud); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 50, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_create_user); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 50, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 50, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_db, __pyx_v_db) < 0) __PYX_ERR(0, 50, __pyx_L1_error)
    if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_user_id, __pyx_v_user_id) < 0) __PYX_ERR(0, 50, __pyx_L1_error)
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_empty_tuple, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 50, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_DECREF_SET(__pyx_v_user, __pyx_t_1);
    __pyx_t_1 = 0;

    /* "KakaoChat/kakao.py":49
 * def checkUserDB(db: Session, user_id: str):
 *     user = db_model.crud.get_user_by_user_id(db=db, user_id=user_id)
 *     if user is None:             # <<<<<<<<<<<<<<
 *         user = db_model.crud.create_user(db=db, user_id=user_id)
 *     return user
 */
  }

  /* "KakaoChat/kakao.py":51
 *     if user is None:
 *         user = db_model.crud.create_user(db=db, user_id=user_id)
 *     return user             # <<<<<<<<<<<<<<
 * 
 * 
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_user);
  __pyx_r = __pyx_v_user;
  goto __pyx_L0;

  /* "KakaoChat/kakao.py":47
 * 
 * 
 * def checkUserDB(db: Session, user_id: str):             # <<<<<<<<<<<<<<
 *     user = db_model.crud.get_user_by_user_id(db=db, user_id=user_id)
 *     if user is None:
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("KakaoChat.kakao.checkUserDB", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_user);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "KakaoChat/kakao.py":54
 * 
 * 
 * def checkLastNotice(db: Session, user_id: str):             # <<<<<<<<<<<<<<
 *     user = db_model.crud.get_user_by_user_id(db=db, user_id=user_id)
 *     if user is None:
 */

/* Python wrapper */
static PyObject *__pyx_pw_9KakaoChat_5kakao_6checkLastNotice(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_9KakaoChat_5kakao_6checkLastNotice = {"checkLastNotice", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_9KakaoChat_5kakao_6checkLastNotice, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_9KakaoChat_5kakao_6checkLastNotice(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_db = 0;
  PyObject *__pyx_v_user_id = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("checkLastNotice (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_db,&__pyx_n_s_user_id,0};
    PyObject* values[2] = {0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_db)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_user_id)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("checkLastNotice", 1, 2, 2, 1); __PYX_ERR(0, 54, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "checkLastNotice") < 0)) __PYX_ERR(0, 54, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_db = values[0];
    __pyx_v_user_id = ((PyObject*)values[1]);
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("checkLastNotice", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 54, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("KakaoChat.kakao.checkLastNotice", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  if (unlikely(!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_user_id), (&PyUnicode_Type), 1, "user_id", 1))) __PYX_ERR(0, 54, __pyx_L1_error)
  __pyx_r = __pyx_pf_9KakaoChat_5kakao_5checkLastNotice(__pyx_self, __pyx_v_db, __pyx_v_user_id);

  /* function exit code */
  goto __pyx_L0;
  __pyx_L1_error:;
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_9KakaoChat_5kakao_5checkLastNotice(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_db, PyObject *__pyx_v_user_id) {
  PyObject *__pyx_v_user = NULL;
  PyObject *__pyx_v_last_id = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_t_4;
  int __pyx_t_5;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("checkLastNotice", 0);

  /* "KakaoChat/kakao.py":55
 * 
 * def checkLastNotice(db: Session, user_id: str):
 *     user = db_model.crud.get_user_by_user_id(db=db, user_id=user_id)             # <<<<<<<<<<<<<<
 *     if user is None:
 *         user = db_model.crud.create_user(db=db, user_id=user_id)
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_db_model); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 55, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_crud); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 55, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_get_user_by_user_id); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 55, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 55, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_db, __pyx_v_db) < 0) __PYX_ERR(0, 55, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_user_id, __pyx_v_user_id) < 0) __PYX_ERR(0, 55, __pyx_L1_error)
  __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_empty_tuple, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 55, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_user = __pyx_t_3;
  __pyx_t_3 = 0;

  /* "KakaoChat/kakao.py":56
 * def checkLastNotice(db: Session, user_id: str):
 *     user = db_model.crud.get_user_by_user_id(db=db, user_id=user_id)
 *     if user is None:             # <<<<<<<<<<<<<<
 *         user = db_model.crud.create_user(db=db, user_id=user_id)
 *     last_id = user.last_notice_id
 */
  __pyx_t_4 = (__pyx_v_user == Py_None);
  __pyx_t_5 = (__pyx_t_4 != 0);
  if (__pyx_t_5) {

    /* "KakaoChat/kakao.py":57
 *     user = db_model.crud.get_user_by_user_id(db=db, user_id=user_id)
 *     if user is None:
 *         user = db_model.crud.create_user(db=db, user_id=user_id)             # <<<<<<<<<<<<<<
 *     last_id = user.last_notice_id
 *     return last_id
 */
    __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_db_model); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 57, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_crud); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 57, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_create_user); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 57, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 57, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_db, __pyx_v_db) < 0) __PYX_ERR(0, 57, __pyx_L1_error)
    if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_user_id, __pyx_v_user_id) < 0) __PYX_ERR(0, 57, __pyx_L1_error)
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_empty_tuple, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 57, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_DECREF_SET(__pyx_v_user, __pyx_t_1);
    __pyx_t_1 = 0;

    /* "KakaoChat/kakao.py":56
 * def checkLastNotice(db: Session, user_id: str):
 *     user = db_model.crud.get_user_by_user_id(db=db, user_id=user_id)
 *     if user is None:             # <<<<<<<<<<<<<<
 *         user = db_model.crud.create_user(db=db, user_id=user_id)
 *     last_id = user.last_notice_id
 */
  }

  /* "KakaoChat/kakao.py":58
 *     if user is None:
 *         user = db_model.crud.create_user(db=db, user_id=user_id)
 *     last_id = user.last_notice_id             # <<<<<<<<<<<<<<
 *     return last_id
 * 
 */
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_user, __pyx_n_s_last_notice_id); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 58, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v_last_id = __pyx_t_1;
  __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":59
 *         user = db_model.crud.create_user(db=db, user_id=user_id)
 *     last_id = user.last_notice_id
 *     return last_id             # <<<<<<<<<<<<<<
 * 
 * 
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_last_id);
  __pyx_r = __pyx_v_last_id;
  goto __pyx_L0;

  /* "KakaoChat/kakao.py":54
 * 
 * 
 * def checkLastNotice(db: Session, user_id: str):             # <<<<<<<<<<<<<<
 *     user = db_model.crud.get_user_by_user_id(db=db, user_id=user_id)
 *     if user is None:
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("KakaoChat.kakao.checkLastNotice", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_user);
  __Pyx_XDECREF(__pyx_v_last_id);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "KakaoChat/kakao.py":62
 * 
 * 
 * def getSchedule(db: Session):             # <<<<<<<<<<<<<<
 *     return db_model.crud.get_all_sched(db=db)
 * 
 */

/* Python wrapper */
static PyObject *__pyx_pw_9KakaoChat_5kakao_8getSchedule(PyObject *__pyx_self, PyObject *__pyx_v_db); /*proto*/
static PyMethodDef __pyx_mdef_9KakaoChat_5kakao_8getSchedule = {"getSchedule", (PyCFunction)__pyx_pw_9KakaoChat_5kakao_8getSchedule, METH_O, 0};
static PyObject *__pyx_pw_9KakaoChat_5kakao_8getSchedule(PyObject *__pyx_self, PyObject *__pyx_v_db) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("getSchedule (wrapper)", 0);
  __pyx_r = __pyx_pf_9KakaoChat_5kakao_7getSchedule(__pyx_self, ((PyObject *)__pyx_v_db));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_9KakaoChat_5kakao_7getSchedule(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_db) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("getSchedule", 0);

  /* "KakaoChat/kakao.py":63
 * 
 * def getSchedule(db: Session):
 *     return db_model.crud.get_all_sched(db=db)             # <<<<<<<<<<<<<<
 * 
 * 
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_db_model); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 63, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_crud); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 63, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_get_all_sched); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 63, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 63, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_db, __pyx_v_db) < 0) __PYX_ERR(0, 63, __pyx_L1_error)
  __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_empty_tuple, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 63, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_r = __pyx_t_3;
  __pyx_t_3 = 0;
  goto __pyx_L0;

  /* "KakaoChat/kakao.py":62
 * 
 * 
 * def getSchedule(db: Session):             # <<<<<<<<<<<<<<
 *     return db_model.crud.get_all_sched(db=db)
 * 
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("KakaoChat.kakao.getSchedule", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "KakaoChat/kakao.py":66
 * 
 * 
 * def updateLastNotice(db: Session, user_id: str, notice_id: int):             # <<<<<<<<<<<<<<
 *     user = db_model.crud.get_user_by_user_id(db=db, user_id=user_id)
 *     if user is None:
 */

/* Python wrapper */
static PyObject *__pyx_pw_9KakaoChat_5kakao_10updateLastNotice(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_9KakaoChat_5kakao_10updateLastNotice = {"updateLastNotice", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_9KakaoChat_5kakao_10updateLastNotice, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_9KakaoChat_5kakao_10updateLastNotice(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_db = 0;
  PyObject *__pyx_v_user_id = 0;
  PyObject *__pyx_v_notice_id = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("updateLastNotice (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_db,&__pyx_n_s_user_id,&__pyx_n_s_notice_id,0};
    PyObject* values[3] = {0,0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  3: values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
        CYTHON_FALLTHROUGH;
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_db)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_user_id)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("updateLastNotice", 1, 3, 3, 1); __PYX_ERR(0, 66, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (likely((values[2] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_notice_id)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("updateLastNotice", 1, 3, 3, 2); __PYX_ERR(0, 66, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "updateLastNotice") < 0)) __PYX_ERR(0, 66, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 3) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
      values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
    }
    __pyx_v_db = values[0];
    __pyx_v_user_id = ((PyObject*)values[1]);
    __pyx_v_notice_id = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("updateLastNotice", 1, 3, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 66, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("KakaoChat.kakao.updateLastNotice", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  if (unlikely(!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_user_id), (&PyUnicode_Type), 1, "user_id", 1))) __PYX_ERR(0, 66, __pyx_L1_error)
  __pyx_r = __pyx_pf_9KakaoChat_5kakao_9updateLastNotice(__pyx_self, __pyx_v_db, __pyx_v_user_id, __pyx_v_notice_id);

  /* function exit code */
  goto __pyx_L0;
  __pyx_L1_error:;
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_9KakaoChat_5kakao_9updateLastNotice(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_db, PyObject *__pyx_v_user_id, PyObject *__pyx_v_notice_id) {
  PyObject *__pyx_v_user = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_t_4;
  int __pyx_t_5;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("updateLastNotice", 0);

  /* "KakaoChat/kakao.py":67
 * 
 * def updateLastNotice(db: Session, user_id: str, notice_id: int):
 *     user = db_model.crud.get_user_by_user_id(db=db, user_id=user_id)             # <<<<<<<<<<<<<<
 *     if user is None:
 *         user = db_model.crud.create_user(db=db, user_id=user_id)
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_db_model); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 67, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_crud); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 67, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_get_user_by_user_id); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 67, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 67, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_db, __pyx_v_db) < 0) __PYX_ERR(0, 67, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_user_id, __pyx_v_user_id) < 0) __PYX_ERR(0, 67, __pyx_L1_error)
  __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_empty_tuple, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 67, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_user = __pyx_t_3;
  __pyx_t_3 = 0;

  /* "KakaoChat/kakao.py":68
 * def updateLastNotice(db: Session, user_id: str, notice_id: int):
 *     user = db_model.crud.get_user_by_user_id(db=db, user_id=user_id)
 *     if user is None:             # <<<<<<<<<<<<<<
 *         user = db_model.crud.create_user(db=db, user_id=user_id)
 *     user = db_model.crud.update_last_notice(
 */
  __pyx_t_4 = (__pyx_v_user == Py_None);
  __pyx_t_5 = (__pyx_t_4 != 0);
  if (__pyx_t_5) {

    /* "KakaoChat/kakao.py":69
 *     user = db_model.crud.get_user_by_user_id(db=db, user_id=user_id)
 *     if user is None:
 *         user = db_model.crud.create_user(db=db, user_id=user_id)             # <<<<<<<<<<<<<<
 *     user = db_model.crud.update_last_notice(
 *         db=db, user_id=user_id, last_notice_id=notice_id
 */
    __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_db_model); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 69, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_crud); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 69, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_create_user); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 69, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 69, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_db, __pyx_v_db) < 0) __PYX_ERR(0, 69, __pyx_L1_error)
    if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_user_id, __pyx_v_user_id) < 0) __PYX_ERR(0, 69, __pyx_L1_error)
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_empty_tuple, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 69, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_DECREF_SET(__pyx_v_user, __pyx_t_1);
    __pyx_t_1 = 0;

    /* "KakaoChat/kakao.py":68
 * def updateLastNotice(db: Session, user_id: str, notice_id: int):
 *     user = db_model.crud.get_user_by_user_id(db=db, user_id=user_id)
 *     if user is None:             # <<<<<<<<<<<<<<
 *         user = db_model.crud.create_user(db=db, user_id=user_id)
 *     user = db_model.crud.update_last_notice(
 */
  }

  /* "KakaoChat/kakao.py":70
 *     if user is None:
 *         user = db_model.crud.create_user(db=db, user_id=user_id)
 *     user = db_model.crud.update_last_notice(             # <<<<<<<<<<<<<<
 *         db=db, user_id=user_id, last_notice_id=notice_id
 *     )
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_db_model); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 70, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_crud); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 70, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_update_last_notice); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 70, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "KakaoChat/kakao.py":71
 *         user = db_model.crud.create_user(db=db, user_id=user_id)
 *     user = db_model.crud.update_last_notice(
 *         db=db, user_id=user_id, last_notice_id=notice_id             # <<<<<<<<<<<<<<
 *     )
 *     return user
 */
  __pyx_t_2 = __Pyx_PyDict_NewPresized(3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 71, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_db, __pyx_v_db) < 0) __PYX_ERR(0, 71, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_user_id, __pyx_v_user_id) < 0) __PYX_ERR(0, 71, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_last_notice_id, __pyx_v_notice_id) < 0) __PYX_ERR(0, 71, __pyx_L1_error)

  /* "KakaoChat/kakao.py":70
 *     if user is None:
 *         user = db_model.crud.create_user(db=db, user_id=user_id)
 *     user = db_model.crud.update_last_notice(             # <<<<<<<<<<<<<<
 *         db=db, user_id=user_id, last_notice_id=notice_id
 *     )
 */
  __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_empty_tuple, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 70, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF_SET(__pyx_v_user, __pyx_t_3);
  __pyx_t_3 = 0;

  /* "KakaoChat/kakao.py":73
 *         db=db, user_id=user_id, last_notice_id=notice_id
 *     )
 *     return user             # <<<<<<<<<<<<<<
 * 
 * 
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_user);
  __pyx_r = __pyx_v_user;
  goto __pyx_L0;

  /* "KakaoChat/kakao.py":66
 * 
 * 
 * def updateLastNotice(db: Session, user_id: str, notice_id: int):             # <<<<<<<<<<<<<<
 *     user = db_model.crud.get_user_by_user_id(db=db, user_id=user_id)
 *     if user is None:
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("KakaoChat.kakao.updateLastNotice", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_user);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "KakaoChat/kakao.py":79
 * 
 * 
 * def parseNotices(url=None, length=10):             # <<<<<<<<<<<<<<
 *     """
 * 
 */

/* Python wrapper */
static PyObject *__pyx_pw_9KakaoChat_5kakao_12parseNotices(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_9KakaoChat_5kakao_11parseNotices[] = "\352\263\265\354\247\200 \355\214\214\354\204\234 \353\251\224\354\235\270\n\n    Args:\n        url (str, optional): \355\231\210\355\216\230\354\235\264\354\247\200 URL (with admin options). Defaults to None.\n        length (int, optional): \353\252\207 \352\260\234\354\235\230 \352\263\265\354\247\200\353\245\274 \354\235\275\354\235\204 \352\262\203\354\235\270\352\260\200. Defaults to 10.\n\n    Returns:\n        ids, posts, dates, writers, length (list, optional): length\354\227\220 \353\224\260\353\245\270 \352\263\265\354\247\200 \353\252\251\353\241\235\354\235\204 \354\240\204\353\266\200 \353\266\210\353\237\254\354\230\250\353\213\244.\n    ";
static PyMethodDef __pyx_mdef_9KakaoChat_5kakao_12parseNotices = {"parseNotices", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_9KakaoChat_5kakao_12parseNotices, METH_VARARGS|METH_KEYWORDS, __pyx_doc_9KakaoChat_5kakao_11parseNotices};
static PyObject *__pyx_pw_9KakaoChat_5kakao_12parseNotices(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_url = 0;
  PyObject *__pyx_v_length = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("parseNotices (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_url,&__pyx_n_s_length,0};
    PyObject* values[2] = {0,0};
    values[0] = ((PyObject *)((PyObject *)Py_None));
    values[1] = ((PyObject *)((PyObject *)__pyx_int_10));
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_url);
          if (value) { values[0] = value; kw_args--; }
        }
        CYTHON_FALLTHROUGH;
        case  1:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_length);
          if (value) { values[1] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "parseNotices") < 0)) __PYX_ERR(0, 79, __pyx_L3_error)
      }
    } else {
      switch (PyTuple_GET_SIZE(__pyx_args)) {
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
    }
    __pyx_v_url = values[0];
    __pyx_v_length = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("parseNotices", 0, 0, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 79, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("KakaoChat.kakao.parseNotices", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_9KakaoChat_5kakao_11parseNotices(__pyx_self, __pyx_v_url, __pyx_v_length);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_9KakaoChat_5kakao_11parseNotices(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_url, PyObject *__pyx_v_length) {
  PyObject *__pyx_v_context = NULL;
  PyObject *__pyx_v_result = NULL;
  PyObject *__pyx_v_html = NULL;
  PyObject *__pyx_v_soup = NULL;
  PyObject *__pyx_v_no_post = NULL;
  PyObject *__pyx_v_ids = NULL;
  PyObject *__pyx_v_posts = NULL;
  PyObject *__pyx_v_dates = NULL;
  PyObject *__pyx_v_writers = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_t_1;
  int __pyx_t_2;
  PyObject *__pyx_t_3 = NULL;
  Py_ssize_t __pyx_t_4;
  Py_UCS4 __pyx_t_5;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  PyObject *__pyx_t_9 = NULL;
  PyObject *__pyx_t_10 = NULL;
  PyObject *__pyx_t_11 = NULL;
  int __pyx_t_12;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("parseNotices", 0);
  __Pyx_INCREF(__pyx_v_url);

  /* "KakaoChat/kakao.py":89
 *         ids, posts, dates, writers, length (list, optional): length     .
 *     """
 *     if url is None:             # <<<<<<<<<<<<<<
 *         url = f"{ADDRESS}?mode=list&articleLimit={length}&article.offset=0"
 * 
 */
  __pyx_t_1 = (__pyx_v_url == Py_None);
  __pyx_t_2 = (__pyx_t_1 != 0);
  if (__pyx_t_2) {

    /* "KakaoChat/kakao.py":90
 *     """
 *     if url is None:
 *         url = f"{ADDRESS}?mode=list&articleLimit={length}&article.offset=0"             # <<<<<<<<<<<<<<
 * 
 *     context = ssl._create_unverified_context()
 */
    __pyx_t_3 = PyTuple_New(4); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 90, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_4 = 0;
    __pyx_t_5 = 127;
    __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_ADDRESS); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 90, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __pyx_t_7 = __Pyx_PyObject_FormatSimple(__pyx_t_6, __pyx_empty_unicode); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 90, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) : __pyx_t_5;
    __pyx_t_4 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_7);
    __Pyx_GIVEREF(__pyx_t_7);
    PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_7);
    __pyx_t_7 = 0;
    __Pyx_INCREF(__pyx_kp_u_mode_list_articleLimit);
    __pyx_t_4 += 24;
    __Pyx_GIVEREF(__pyx_kp_u_mode_list_articleLimit);
    PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_kp_u_mode_list_articleLimit);
    __pyx_t_7 = __Pyx_PyObject_FormatSimple(__pyx_v_length, __pyx_empty_unicode); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 90, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) : __pyx_t_5;
    __pyx_t_4 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_7);
    __Pyx_GIVEREF(__pyx_t_7);
    PyTuple_SET_ITEM(__pyx_t_3, 2, __pyx_t_7);
    __pyx_t_7 = 0;
    __Pyx_INCREF(__pyx_kp_u_article_offset_0);
    __pyx_t_4 += 17;
    __Pyx_GIVEREF(__pyx_kp_u_article_offset_0);
    PyTuple_SET_ITEM(__pyx_t_3, 3, __pyx_kp_u_article_offset_0);
    __pyx_t_7 = __Pyx_PyUnicode_Join(__pyx_t_3, 4, __pyx_t_4, __pyx_t_5); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 90, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF_SET(__pyx_v_url, __pyx_t_7);
    __pyx_t_7 = 0;

    /* "KakaoChat/kakao.py":89
 *         ids, posts, dates, writers, length (list, optional): length     .
 *     """
 *     if url is None:             # <<<<<<<<<<<<<<
 *         url = f"{ADDRESS}?mode=list&articleLimit={length}&article.offset=0"
 * 
 */
  }

  /* "KakaoChat/kakao.py":92
 *         url = f"{ADDRESS}?mode=list&articleLimit={length}&article.offset=0"
 * 
 *     context = ssl._create_unverified_context()             # <<<<<<<<<<<<<<
 *     try:
 *         result = urlopen(url, timeout=2.0, context=context)
 */
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_ssl); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 92, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_create_unverified_context); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 92, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_6))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_6);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_6, function);
    }
  }
  __pyx_t_7 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_6, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 92, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_v_context = __pyx_t_7;
  __pyx_t_7 = 0;

  /* "KakaoChat/kakao.py":93
 * 
 *     context = ssl._create_unverified_context()
 *     try:             # <<<<<<<<<<<<<<
 *         result = urlopen(url, timeout=2.0, context=context)
 *     except HTTPError:
 */
  {
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ExceptionSave(&__pyx_t_8, &__pyx_t_9, &__pyx_t_10);
    __Pyx_XGOTREF(__pyx_t_8);
    __Pyx_XGOTREF(__pyx_t_9);
    __Pyx_XGOTREF(__pyx_t_10);
    /*try:*/ {

      /* "KakaoChat/kakao.py":94
 *     context = ssl._create_unverified_context()
 *     try:
 *         result = urlopen(url, timeout=2.0, context=context)             # <<<<<<<<<<<<<<
 *     except HTTPError:
 *         print("Seems like the server is down now.")
 */
      __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_urlopen); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 94, __pyx_L4_error)
      __Pyx_GOTREF(__pyx_t_7);
      __pyx_t_6 = PyTuple_New(1); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 94, __pyx_L4_error)
      __Pyx_GOTREF(__pyx_t_6);
      __Pyx_INCREF(__pyx_v_url);
      __Pyx_GIVEREF(__pyx_v_url);
      PyTuple_SET_ITEM(__pyx_t_6, 0, __pyx_v_url);
      __pyx_t_3 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 94, __pyx_L4_error)
      __Pyx_GOTREF(__pyx_t_3);
      if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_timeout, __pyx_float_2_0) < 0) __PYX_ERR(0, 94, __pyx_L4_error)
      if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_context, __pyx_v_context) < 0) __PYX_ERR(0, 94, __pyx_L4_error)
      __pyx_t_11 = __Pyx_PyObject_Call(__pyx_t_7, __pyx_t_6, __pyx_t_3); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 94, __pyx_L4_error)
      __Pyx_GOTREF(__pyx_t_11);
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_v_result = __pyx_t_11;
      __pyx_t_11 = 0;

      /* "KakaoChat/kakao.py":93
 * 
 *     context = ssl._create_unverified_context()
 *     try:             # <<<<<<<<<<<<<<
 *         result = urlopen(url, timeout=2.0, context=context)
 *     except HTTPError:
 */
    }
    __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
    __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
    __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
    goto __pyx_L9_try_end;
    __pyx_L4_error:;
    __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;

    /* "KakaoChat/kakao.py":95
 *     try:
 *         result = urlopen(url, timeout=2.0, context=context)
 *     except HTTPError:             # <<<<<<<<<<<<<<
 *         print("Seems like the server is down now.")
 *         return None, None, None, None, 0  # make entity
 */
    __Pyx_ErrFetch(&__pyx_t_11, &__pyx_t_3, &__pyx_t_6);
    __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_HTTPError); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 95, __pyx_L6_except_error)
    __Pyx_GOTREF(__pyx_t_7);
    __pyx_t_12 = __Pyx_PyErr_GivenExceptionMatches(__pyx_t_11, __pyx_t_7);
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_ErrRestore(__pyx_t_11, __pyx_t_3, __pyx_t_6);
    __pyx_t_11 = 0; __pyx_t_3 = 0; __pyx_t_6 = 0;
    if (__pyx_t_12) {
      __Pyx_AddTraceback("KakaoChat.kakao.parseNotices", __pyx_clineno, __pyx_lineno, __pyx_filename);
      if (__Pyx_GetException(&__pyx_t_6, &__pyx_t_3, &__pyx_t_11) < 0) __PYX_ERR(0, 95, __pyx_L6_except_error)
      __Pyx_GOTREF(__pyx_t_6);
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_GOTREF(__pyx_t_11);

      /* "KakaoChat/kakao.py":96
 *         result = urlopen(url, timeout=2.0, context=context)
 *     except HTTPError:
 *         print("Seems like the server is down now.")             # <<<<<<<<<<<<<<
 *         return None, None, None, None, 0  # make entity
 *     except TimeoutError:
 */
      __pyx_t_7 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__2, NULL); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 96, __pyx_L6_except_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;

      /* "KakaoChat/kakao.py":97
 *     except HTTPError:
 *         print("Seems like the server is down now.")
 *         return None, None, None, None, 0  # make entity             # <<<<<<<<<<<<<<
 *     except TimeoutError:
 *         print("It's taking too long to load website.")
 */
      __Pyx_XDECREF(__pyx_r);
      __Pyx_INCREF(__pyx_tuple__3);
      __pyx_r = __pyx_tuple__3;
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
      __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
      goto __pyx_L7_except_return;
    }

    /* "KakaoChat/kakao.py":98
 *         print("Seems like the server is down now.")
 *         return None, None, None, None, 0  # make entity
 *     except TimeoutError:             # <<<<<<<<<<<<<<
 *         print("It's taking too long to load website.")
 *         return None, None, None, None, 0  # make entity
 */
    __Pyx_ErrFetch(&__pyx_t_11, &__pyx_t_3, &__pyx_t_6);
    __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_TimeoutError); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 98, __pyx_L6_except_error)
    __Pyx_GOTREF(__pyx_t_7);
    __pyx_t_12 = __Pyx_PyErr_GivenExceptionMatches(__pyx_t_11, __pyx_t_7);
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_ErrRestore(__pyx_t_11, __pyx_t_3, __pyx_t_6);
    __pyx_t_11 = 0; __pyx_t_3 = 0; __pyx_t_6 = 0;
    if (__pyx_t_12) {
      __Pyx_AddTraceback("KakaoChat.kakao.parseNotices", __pyx_clineno, __pyx_lineno, __pyx_filename);
      if (__Pyx_GetException(&__pyx_t_6, &__pyx_t_3, &__pyx_t_11) < 0) __PYX_ERR(0, 98, __pyx_L6_except_error)
      __Pyx_GOTREF(__pyx_t_6);
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_GOTREF(__pyx_t_11);

      /* "KakaoChat/kakao.py":99
 *         return None, None, None, None, 0  # make entity
 *     except TimeoutError:
 *         print("It's taking too long to load website.")             # <<<<<<<<<<<<<<
 *         return None, None, None, None, 0  # make entity
 * 
 */
      __pyx_t_7 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__4, NULL); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 99, __pyx_L6_except_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;

      /* "KakaoChat/kakao.py":100
 *     except TimeoutError:
 *         print("It's taking too long to load website.")
 *         return None, None, None, None, 0  # make entity             # <<<<<<<<<<<<<<
 * 
 *     html = result.read().decode("utf-8")
 */
      __Pyx_XDECREF(__pyx_r);
      __Pyx_INCREF(__pyx_tuple__3);
      __pyx_r = __pyx_tuple__3;
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
      __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
      goto __pyx_L7_except_return;
    }
    goto __pyx_L6_except_error;
    __pyx_L6_except_error:;

    /* "KakaoChat/kakao.py":93
 * 
 *     context = ssl._create_unverified_context()
 *     try:             # <<<<<<<<<<<<<<
 *         result = urlopen(url, timeout=2.0, context=context)
 *     except HTTPError:
 */
    __Pyx_XGIVEREF(__pyx_t_8);
    __Pyx_XGIVEREF(__pyx_t_9);
    __Pyx_XGIVEREF(__pyx_t_10);
    __Pyx_ExceptionReset(__pyx_t_8, __pyx_t_9, __pyx_t_10);
    goto __pyx_L1_error;
    __pyx_L7_except_return:;
    __Pyx_XGIVEREF(__pyx_t_8);
    __Pyx_XGIVEREF(__pyx_t_9);
    __Pyx_XGIVEREF(__pyx_t_10);
    __Pyx_ExceptionReset(__pyx_t_8, __pyx_t_9, __pyx_t_10);
    goto __pyx_L0;
    __pyx_L9_try_end:;
  }

  /* "KakaoChat/kakao.py":102
 *         return None, None, None, None, 0  # make entity
 * 
 *     html = result.read().decode("utf-8")             # <<<<<<<<<<<<<<
 *     soup = HTMLParser(html)
 *     no_post = soup.css("td.b-no-post")
 */
  __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_v_result, __pyx_n_s_read); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 102, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_7 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_6))) {
    __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_6);
    if (likely(__pyx_t_7)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
      __Pyx_INCREF(__pyx_t_7);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_6, function);
    }
  }
  __pyx_t_3 = (__pyx_t_7) ? __Pyx_PyObject_CallOneArg(__pyx_t_6, __pyx_t_7) : __Pyx_PyObject_CallNoArg(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
  if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 102, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_decode); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 102, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_6))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_6);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_6, function);
    }
  }
  __pyx_t_11 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_6, __pyx_t_3, __pyx_kp_u_utf_8) : __Pyx_PyObject_CallOneArg(__pyx_t_6, __pyx_kp_u_utf_8);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 102, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_11);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_v_html = __pyx_t_11;
  __pyx_t_11 = 0;

  /* "KakaoChat/kakao.py":103
 * 
 *     html = result.read().decode("utf-8")
 *     soup = HTMLParser(html)             # <<<<<<<<<<<<<<
 *     no_post = soup.css("td.b-no-post")
 *     if no_post:
 */
  __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_HTMLParser); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 103, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_6))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_6);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_6, function);
    }
  }
  __pyx_t_11 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_6, __pyx_t_3, __pyx_v_html) : __Pyx_PyObject_CallOneArg(__pyx_t_6, __pyx_v_html);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 103, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_11);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_v_soup = __pyx_t_11;
  __pyx_t_11 = 0;

  /* "KakaoChat/kakao.py":104
 *     html = result.read().decode("utf-8")
 *     soup = HTMLParser(html)
 *     no_post = soup.css("td.b-no-post")             # <<<<<<<<<<<<<<
 *     if no_post:
 *         return None, None, None, None, 0  # make entity
 */
  __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_v_soup, __pyx_n_s_css); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 104, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_6))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_6);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_6, function);
    }
  }
  __pyx_t_11 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_6, __pyx_t_3, __pyx_kp_u_td_b_no_post) : __Pyx_PyObject_CallOneArg(__pyx_t_6, __pyx_kp_u_td_b_no_post);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 104, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_11);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_v_no_post = __pyx_t_11;
  __pyx_t_11 = 0;

  /* "KakaoChat/kakao.py":105
 *     soup = HTMLParser(html)
 *     no_post = soup.css("td.b-no-post")
 *     if no_post:             # <<<<<<<<<<<<<<
 *         return None, None, None, None, 0  # make entity
 * 
 */
  __pyx_t_2 = __Pyx_PyObject_IsTrue(__pyx_v_no_post); if (unlikely(__pyx_t_2 < 0)) __PYX_ERR(0, 105, __pyx_L1_error)
  if (__pyx_t_2) {

    /* "KakaoChat/kakao.py":106
 *     no_post = soup.css("td.b-no-post")
 *     if no_post:
 *         return None, None, None, None, 0  # make entity             # <<<<<<<<<<<<<<
 * 
 *     ids = soup.css("td.b-num-box")
 */
    __Pyx_XDECREF(__pyx_r);
    __Pyx_INCREF(__pyx_tuple__3);
    __pyx_r = __pyx_tuple__3;
    goto __pyx_L0;

    /* "KakaoChat/kakao.py":105
 *     soup = HTMLParser(html)
 *     no_post = soup.css("td.b-no-post")
 *     if no_post:             # <<<<<<<<<<<<<<
 *         return None, None, None, None, 0  # make entity
 * 
 */
  }

  /* "KakaoChat/kakao.py":108
 *         return None, None, None, None, 0  # make entity
 * 
 *     ids = soup.css("td.b-num-box")             # <<<<<<<<<<<<<<
 *     posts = soup.css("div.b-title-box > a")
 *     dates = soup.css("span.b-date")
 */
  __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_v_soup, __pyx_n_s_css); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_6))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_6);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_6, function);
    }
  }
  __pyx_t_11 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_6, __pyx_t_3, __pyx_kp_u_td_b_num_box) : __Pyx_PyObject_CallOneArg(__pyx_t_6, __pyx_kp_u_td_b_num_box);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_11);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_v_ids = __pyx_t_11;
  __pyx_t_11 = 0;

  /* "KakaoChat/kakao.py":109
 * 
 *     ids = soup.css("td.b-num-box")
 *     posts = soup.css("div.b-title-box > a")             # <<<<<<<<<<<<<<
 *     dates = soup.css("span.b-date")
 *     writers = soup.css("span.b-writer")
 */
  __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_v_soup, __pyx_n_s_css); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 109, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_6))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_6);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_6, function);
    }
  }
  __pyx_t_11 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_6, __pyx_t_3, __pyx_kp_u_div_b_title_box_a) : __Pyx_PyObject_CallOneArg(__pyx_t_6, __pyx_kp_u_div_b_title_box_a);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 109, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_11);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_v_posts = __pyx_t_11;
  __pyx_t_11 = 0;

  /* "KakaoChat/kakao.py":110
 *     ids = soup.css("td.b-num-box")
 *     posts = soup.css("div.b-title-box > a")
 *     dates = soup.css("span.b-date")             # <<<<<<<<<<<<<<
 *     writers = soup.css("span.b-writer")
 *     return ids, posts, dates, writers, len(ids)
 */
  __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_v_soup, __pyx_n_s_css); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 110, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_6))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_6);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_6, function);
    }
  }
  __pyx_t_11 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_6, __pyx_t_3, __pyx_kp_u_span_b_date) : __Pyx_PyObject_CallOneArg(__pyx_t_6, __pyx_kp_u_span_b_date);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 110, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_11);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_v_dates = __pyx_t_11;
  __pyx_t_11 = 0;

  /* "KakaoChat/kakao.py":111
 *     posts = soup.css("div.b-title-box > a")
 *     dates = soup.css("span.b-date")
 *     writers = soup.css("span.b-writer")             # <<<<<<<<<<<<<<
 *     return ids, posts, dates, writers, len(ids)
 * 
 */
  __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_v_soup, __pyx_n_s_css); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 111, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_6))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_6);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_6, function);
    }
  }
  __pyx_t_11 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_6, __pyx_t_3, __pyx_kp_u_span_b_writer) : __Pyx_PyObject_CallOneArg(__pyx_t_6, __pyx_kp_u_span_b_writer);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 111, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_11);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_v_writers = __pyx_t_11;
  __pyx_t_11 = 0;

  /* "KakaoChat/kakao.py":112
 *     dates = soup.css("span.b-date")
 *     writers = soup.css("span.b-writer")
 *     return ids, posts, dates, writers, len(ids)             # <<<<<<<<<<<<<<
 * 
 * 
 */
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_4 = PyObject_Length(__pyx_v_ids); if (unlikely(__pyx_t_4 == ((Py_ssize_t)-1))) __PYX_ERR(0, 112, __pyx_L1_error)
  __pyx_t_11 = PyInt_FromSsize_t(__pyx_t_4); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 112, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_11);
  __pyx_t_6 = PyTuple_New(5); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 112, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_INCREF(__pyx_v_ids);
  __Pyx_GIVEREF(__pyx_v_ids);
  PyTuple_SET_ITEM(__pyx_t_6, 0, __pyx_v_ids);
  __Pyx_INCREF(__pyx_v_posts);
  __Pyx_GIVEREF(__pyx_v_posts);
  PyTuple_SET_ITEM(__pyx_t_6, 1, __pyx_v_posts);
  __Pyx_INCREF(__pyx_v_dates);
  __Pyx_GIVEREF(__pyx_v_dates);
  PyTuple_SET_ITEM(__pyx_t_6, 2, __pyx_v_dates);
  __Pyx_INCREF(__pyx_v_writers);
  __Pyx_GIVEREF(__pyx_v_writers);
  PyTuple_SET_ITEM(__pyx_t_6, 3, __pyx_v_writers);
  __Pyx_GIVEREF(__pyx_t_11);
  PyTuple_SET_ITEM(__pyx_t_6, 4, __pyx_t_11);
  __pyx_t_11 = 0;
  __pyx_r = __pyx_t_6;
  __pyx_t_6 = 0;
  goto __pyx_L0;

  /* "KakaoChat/kakao.py":79
 * 
 * 
 * def parseNotices(url=None, length=10):             # <<<<<<<<<<<<<<
 *     """
 * 
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_11);
  __Pyx_AddTraceback("KakaoChat.kakao.parseNotices", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_context);
  __Pyx_XDECREF(__pyx_v_result);
  __Pyx_XDECREF(__pyx_v_html);
  __Pyx_XDECREF(__pyx_v_soup);
  __Pyx_XDECREF(__pyx_v_no_post);
  __Pyx_XDECREF(__pyx_v_ids);
  __Pyx_XDECREF(__pyx_v_posts);
  __Pyx_XDECREF(__pyx_v_dates);
  __Pyx_XDECREF(__pyx_v_writers);
  __Pyx_XDECREF(__pyx_v_url);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "KakaoChat/kakao.py":115
 * 
 * 
 * def checkConnection():             # <<<<<<<<<<<<<<
 *     """   . """
 *     context = ssl._create_unverified_context()
 */

/* Python wrapper */
static PyObject *__pyx_pw_9KakaoChat_5kakao_14checkConnection(PyObject *__pyx_self, CYTHON_UNUSED PyObject *unused); /*proto*/
static char __pyx_doc_9KakaoChat_5kakao_13checkConnection[] = " \355\231\210\355\216\230\354\235\264\354\247\200 \353\260\230\354\235\221\354\235\204 \354\262\264\355\201\254\355\225\234\353\213\244. ";
static PyMethodDef __pyx_mdef_9KakaoChat_5kakao_14checkConnection = {"checkConnection", (PyCFunction)__pyx_pw_9KakaoChat_5kakao_14checkConnection, METH_NOARGS, __pyx_doc_9KakaoChat_5kakao_13checkConnection};
static PyObject *__pyx_pw_9KakaoChat_5kakao_14checkConnection(PyObject *__pyx_self, CYTHON_UNUSED PyObject *unused) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("checkConnection (wrapper)", 0);
  __pyx_r = __pyx_pf_9KakaoChat_5kakao_13checkConnection(__pyx_self);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_9KakaoChat_5kakao_13checkConnection(CYTHON_UNUSED PyObject *__pyx_self) {
  PyObject *__pyx_v_context = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  int __pyx_t_8;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("checkConnection", 0);

  /* "KakaoChat/kakao.py":117
 * def checkConnection():
 *     """   . """
 *     context = ssl._create_unverified_context()             # <<<<<<<<<<<<<<
 *     try:
 *         urlopen(ADDRESS, timeout=2.0, context=context)
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_ssl); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 117, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_create_unverified_context); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 117, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
    __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_3);
    if (likely(__pyx_t_2)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_2);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_3, function);
    }
  }
  __pyx_t_1 = (__pyx_t_2) ? __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_2) : __Pyx_PyObject_CallNoArg(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 117, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_v_context = __pyx_t_1;
  __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":118
 *     """   . """
 *     context = ssl._create_unverified_context()
 *     try:             # <<<<<<<<<<<<<<
 *         urlopen(ADDRESS, timeout=2.0, context=context)
 *     except HTTPError:
 */
  {
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ExceptionSave(&__pyx_t_4, &__pyx_t_5, &__pyx_t_6);
    __Pyx_XGOTREF(__pyx_t_4);
    __Pyx_XGOTREF(__pyx_t_5);
    __Pyx_XGOTREF(__pyx_t_6);
    /*try:*/ {

      /* "KakaoChat/kakao.py":119
 *     context = ssl._create_unverified_context()
 *     try:
 *         urlopen(ADDRESS, timeout=2.0, context=context)             # <<<<<<<<<<<<<<
 *     except HTTPError:
 *         print("Seems like the server is down now.")
 */
      __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_urlopen); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 119, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_ADDRESS); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 119, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_2 = PyTuple_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 119, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_GIVEREF(__pyx_t_3);
      PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_3);
      __pyx_t_3 = 0;
      __pyx_t_3 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 119, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_3);
      if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_timeout, __pyx_float_2_0) < 0) __PYX_ERR(0, 119, __pyx_L3_error)
      if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_context, __pyx_v_context) < 0) __PYX_ERR(0, 119, __pyx_L3_error)
      __pyx_t_7 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_t_2, __pyx_t_3); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 119, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;

      /* "KakaoChat/kakao.py":118
 *     """   . """
 *     context = ssl._create_unverified_context()
 *     try:             # <<<<<<<<<<<<<<
 *         urlopen(ADDRESS, timeout=2.0, context=context)
 *     except HTTPError:
 */
    }
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    goto __pyx_L8_try_end;
    __pyx_L3_error:;
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;

    /* "KakaoChat/kakao.py":120
 *     try:
 *         urlopen(ADDRESS, timeout=2.0, context=context)
 *     except HTTPError:             # <<<<<<<<<<<<<<
 *         print("Seems like the server is down now.")
 *         return False
 */
    __Pyx_ErrFetch(&__pyx_t_7, &__pyx_t_3, &__pyx_t_2);
    __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_HTTPError); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 120, __pyx_L5_except_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_8 = __Pyx_PyErr_GivenExceptionMatches(__pyx_t_7, __pyx_t_1);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_ErrRestore(__pyx_t_7, __pyx_t_3, __pyx_t_2);
    __pyx_t_7 = 0; __pyx_t_3 = 0; __pyx_t_2 = 0;
    if (__pyx_t_8) {
      __Pyx_AddTraceback("KakaoChat.kakao.checkConnection", __pyx_clineno, __pyx_lineno, __pyx_filename);
      if (__Pyx_GetException(&__pyx_t_2, &__pyx_t_3, &__pyx_t_7) < 0) __PYX_ERR(0, 120, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_GOTREF(__pyx_t_7);

      /* "KakaoChat/kakao.py":121
 *         urlopen(ADDRESS, timeout=2.0, context=context)
 *     except HTTPError:
 *         print("Seems like the server is down now.")             # <<<<<<<<<<<<<<
 *         return False
 *     except URLError:
 */
      __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__2, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 121, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

      /* "KakaoChat/kakao.py":122
 *     except HTTPError:
 *         print("Seems like the server is down now.")
 *         return False             # <<<<<<<<<<<<<<
 *     except URLError:
 *         print("Seems like the url is wrong now.")
 */
      __Pyx_XDECREF(__pyx_r);
      __Pyx_INCREF(Py_False);
      __pyx_r = Py_False;
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      goto __pyx_L6_except_return;
    }

    /* "KakaoChat/kakao.py":123
 *         print("Seems like the server is down now.")
 *         return False
 *     except URLError:             # <<<<<<<<<<<<<<
 *         print("Seems like the url is wrong now.")
 *         return False
 */
    __Pyx_ErrFetch(&__pyx_t_7, &__pyx_t_3, &__pyx_t_2);
    __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_URLError); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 123, __pyx_L5_except_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_8 = __Pyx_PyErr_GivenExceptionMatches(__pyx_t_7, __pyx_t_1);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_ErrRestore(__pyx_t_7, __pyx_t_3, __pyx_t_2);
    __pyx_t_7 = 0; __pyx_t_3 = 0; __pyx_t_2 = 0;
    if (__pyx_t_8) {
      __Pyx_AddTraceback("KakaoChat.kakao.checkConnection", __pyx_clineno, __pyx_lineno, __pyx_filename);
      if (__Pyx_GetException(&__pyx_t_2, &__pyx_t_3, &__pyx_t_7) < 0) __PYX_ERR(0, 123, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_GOTREF(__pyx_t_7);

      /* "KakaoChat/kakao.py":124
 *         return False
 *     except URLError:
 *         print("Seems like the url is wrong now.")             # <<<<<<<<<<<<<<
 *         return False
 *     except TimeoutError:
 */
      __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__5, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 124, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

      /* "KakaoChat/kakao.py":125
 *     except URLError:
 *         print("Seems like the url is wrong now.")
 *         return False             # <<<<<<<<<<<<<<
 *     except TimeoutError:
 *         print("It's taking too long to load website.")
 */
      __Pyx_XDECREF(__pyx_r);
      __Pyx_INCREF(Py_False);
      __pyx_r = Py_False;
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      goto __pyx_L6_except_return;
    }

    /* "KakaoChat/kakao.py":126
 *         print("Seems like the url is wrong now.")
 *         return False
 *     except TimeoutError:             # <<<<<<<<<<<<<<
 *         print("It's taking too long to load website.")
 *         return False
 */
    __Pyx_ErrFetch(&__pyx_t_7, &__pyx_t_3, &__pyx_t_2);
    __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_TimeoutError); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 126, __pyx_L5_except_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_8 = __Pyx_PyErr_GivenExceptionMatches(__pyx_t_7, __pyx_t_1);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_ErrRestore(__pyx_t_7, __pyx_t_3, __pyx_t_2);
    __pyx_t_7 = 0; __pyx_t_3 = 0; __pyx_t_2 = 0;
    if (__pyx_t_8) {
      __Pyx_AddTraceback("KakaoChat.kakao.checkConnection", __pyx_clineno, __pyx_lineno, __pyx_filename);
      if (__Pyx_GetException(&__pyx_t_2, &__pyx_t_3, &__pyx_t_7) < 0) __PYX_ERR(0, 126, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_GOTREF(__pyx_t_7);

      /* "KakaoChat/kakao.py":127
 *         return False
 *     except TimeoutError:
 *         print("It's taking too long to load website.")             # <<<<<<<<<<<<<<
 *         return False
 *     return True  # the connection automatically is closed
 */
      __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__4, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 127, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

      /* "KakaoChat/kakao.py":128
 *     except TimeoutError:
 *         print("It's taking too long to load website.")
 *         return False             # <<<<<<<<<<<<<<
 *     return True  # the connection automatically is closed
 * 
 */
      __Pyx_XDECREF(__pyx_r);
      __Pyx_INCREF(Py_False);
      __pyx_r = Py_False;
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      goto __pyx_L6_except_return;
    }
    goto __pyx_L5_except_error;
    __pyx_L5_except_error:;

    /* "KakaoChat/kakao.py":118
 *     """   . """
 *     context = ssl._create_unverified_context()
 *     try:             # <<<<<<<<<<<<<<
 *         urlopen(ADDRESS, timeout=2.0, context=context)
 *     except HTTPError:
 */
    __Pyx_XGIVEREF(__pyx_t_4);
    __Pyx_XGIVEREF(__pyx_t_5);
    __Pyx_XGIVEREF(__pyx_t_6);
    __Pyx_ExceptionReset(__pyx_t_4, __pyx_t_5, __pyx_t_6);
    goto __pyx_L1_error;
    __pyx_L6_except_return:;
    __Pyx_XGIVEREF(__pyx_t_4);
    __Pyx_XGIVEREF(__pyx_t_5);
    __Pyx_XGIVEREF(__pyx_t_6);
    __Pyx_ExceptionReset(__pyx_t_4, __pyx_t_5, __pyx_t_6);
    goto __pyx_L0;
    __pyx_L8_try_end:;
  }

  /* "KakaoChat/kakao.py":129
 *         print("It's taking too long to load website.")
 *         return False
 *     return True  # the connection automatically is closed             # <<<<<<<<<<<<<<
 * 
 * 
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(Py_True);
  __pyx_r = Py_True;
  goto __pyx_L0;

  /* "KakaoChat/kakao.py":115
 * 
 * 
 * def checkConnection():             # <<<<<<<<<<<<<<
 *     """   . """
 *     context = ssl._create_unverified_context()
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_AddTraceback("KakaoChat.kakao.checkConnection", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_context);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "KakaoChat/kakao.py":132
 * 
 * 
 * def makeJSON(postId, postTitle, postDate, postLink, postWriter):             # <<<<<<<<<<<<<<
 *     """   """
 *     duplicate = "[" + postWriter + "]"
 */

/* Python wrapper */
static PyObject *__pyx_pw_9KakaoChat_5kakao_16makeJSON(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_9KakaoChat_5kakao_15makeJSON[] = "\353\246\254\354\212\244\355\212\270 \354\271\264\353\223\234\355\230\225\354\235\230 \354\271\264\353\223\234 \355\230\225\354\213\235";
static PyMethodDef __pyx_mdef_9KakaoChat_5kakao_16makeJSON = {"makeJSON", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_9KakaoChat_5kakao_16makeJSON, METH_VARARGS|METH_KEYWORDS, __pyx_doc_9KakaoChat_5kakao_15makeJSON};
static PyObject *__pyx_pw_9KakaoChat_5kakao_16makeJSON(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  CYTHON_UNUSED PyObject *__pyx_v_postId = 0;
  PyObject *__pyx_v_postTitle = 0;
  CYTHON_UNUSED PyObject *__pyx_v_postDate = 0;
  PyObject *__pyx_v_postLink = 0;
  PyObject *__pyx_v_postWriter = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("makeJSON (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_postId,&__pyx_n_s_postTitle,&__pyx_n_s_postDate,&__pyx_n_s_postLink,&__pyx_n_s_postWriter,0};
    PyObject* values[5] = {0,0,0,0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  5: values[4] = PyTuple_GET_ITEM(__pyx_args, 4);
        CYTHON_FALLTHROUGH;
        case  4: values[3] = PyTuple_GET_ITEM(__pyx_args, 3);
        CYTHON_FALLTHROUGH;
        case  3: values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
        CYTHON_FALLTHROUGH;
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_postId)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_postTitle)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("makeJSON", 1, 5, 5, 1); __PYX_ERR(0, 132, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (likely((values[2] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_postDate)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("makeJSON", 1, 5, 5, 2); __PYX_ERR(0, 132, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  3:
        if (likely((values[3] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_postLink)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("makeJSON", 1, 5, 5, 3); __PYX_ERR(0, 132, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  4:
        if (likely((values[4] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_postWriter)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("makeJSON", 1, 5, 5, 4); __PYX_ERR(0, 132, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "makeJSON") < 0)) __PYX_ERR(0, 132, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 5) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
      values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
      values[3] = PyTuple_GET_ITEM(__pyx_args, 3);
      values[4] = PyTuple_GET_ITEM(__pyx_args, 4);
    }
    __pyx_v_postId = values[0];
    __pyx_v_postTitle = values[1];
    __pyx_v_postDate = values[2];
    __pyx_v_postLink = values[3];
    __pyx_v_postWriter = values[4];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("makeJSON", 1, 5, 5, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 132, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("KakaoChat.kakao.makeJSON", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_9KakaoChat_5kakao_15makeJSON(__pyx_self, __pyx_v_postId, __pyx_v_postTitle, __pyx_v_postDate, __pyx_v_postLink, __pyx_v_postWriter);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_9KakaoChat_5kakao_15makeJSON(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_postId, PyObject *__pyx_v_postTitle, CYTHON_UNUSED PyObject *__pyx_v_postDate, PyObject *__pyx_v_postLink, PyObject *__pyx_v_postWriter) {
  PyObject *__pyx_v_duplicate = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  int __pyx_t_3;
  int __pyx_t_4;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  int __pyx_t_7;
  PyObject *__pyx_t_8 = NULL;
  Py_ssize_t __pyx_t_9;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("makeJSON", 0);
  __Pyx_INCREF(__pyx_v_postTitle);

  /* "KakaoChat/kakao.py":134
 * def makeJSON(postId, postTitle, postDate, postLink, postWriter):
 *     """   """
 *     duplicate = "[" + postWriter + "]"             # <<<<<<<<<<<<<<
 *     if duplicate in postTitle:  # writer: [writer] title
 *         postTitle = postTitle.replace(duplicate, "").strip()  # -> writer: title
 */
  __pyx_t_1 = PyNumber_Add(__pyx_kp_u__6, __pyx_v_postWriter); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 134, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyNumber_Add(__pyx_t_1, __pyx_kp_u__7); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 134, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_v_duplicate = __pyx_t_2;
  __pyx_t_2 = 0;

  /* "KakaoChat/kakao.py":135
 *     """   """
 *     duplicate = "[" + postWriter + "]"
 *     if duplicate in postTitle:  # writer: [writer] title             # <<<<<<<<<<<<<<
 *         postTitle = postTitle.replace(duplicate, "").strip()  # -> writer: title
 * 
 */
  __pyx_t_3 = (__Pyx_PySequence_ContainsTF(__pyx_v_duplicate, __pyx_v_postTitle, Py_EQ)); if (unlikely(__pyx_t_3 < 0)) __PYX_ERR(0, 135, __pyx_L1_error)
  __pyx_t_4 = (__pyx_t_3 != 0);
  if (__pyx_t_4) {

    /* "KakaoChat/kakao.py":136
 *     duplicate = "[" + postWriter + "]"
 *     if duplicate in postTitle:  # writer: [writer] title
 *         postTitle = postTitle.replace(duplicate, "").strip()  # -> writer: title             # <<<<<<<<<<<<<<
 * 
 *     return {
 */
    __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_v_postTitle, __pyx_n_s_replace); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 136, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_6 = NULL;
    __pyx_t_7 = 0;
    if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_5))) {
      __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_5);
      if (likely(__pyx_t_6)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
        __Pyx_INCREF(__pyx_t_6);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_5, function);
        __pyx_t_7 = 1;
      }
    }
    #if CYTHON_FAST_PYCALL
    if (PyFunction_Check(__pyx_t_5)) {
      PyObject *__pyx_temp[3] = {__pyx_t_6, __pyx_v_duplicate, __pyx_kp_u__8};
      __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_5, __pyx_temp+1-__pyx_t_7, 2+__pyx_t_7); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 136, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
      __Pyx_GOTREF(__pyx_t_1);
    } else
    #endif
    #if CYTHON_FAST_PYCCALL
    if (__Pyx_PyFastCFunction_Check(__pyx_t_5)) {
      PyObject *__pyx_temp[3] = {__pyx_t_6, __pyx_v_duplicate, __pyx_kp_u__8};
      __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_5, __pyx_temp+1-__pyx_t_7, 2+__pyx_t_7); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 136, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
      __Pyx_GOTREF(__pyx_t_1);
    } else
    #endif
    {
      __pyx_t_8 = PyTuple_New(2+__pyx_t_7); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 136, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_8);
      if (__pyx_t_6) {
        __Pyx_GIVEREF(__pyx_t_6); PyTuple_SET_ITEM(__pyx_t_8, 0, __pyx_t_6); __pyx_t_6 = NULL;
      }
      __Pyx_INCREF(__pyx_v_duplicate);
      __Pyx_GIVEREF(__pyx_v_duplicate);
      PyTuple_SET_ITEM(__pyx_t_8, 0+__pyx_t_7, __pyx_v_duplicate);
      __Pyx_INCREF(__pyx_kp_u__8);
      __Pyx_GIVEREF(__pyx_kp_u__8);
      PyTuple_SET_ITEM(__pyx_t_8, 1+__pyx_t_7, __pyx_kp_u__8);
      __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_5, __pyx_t_8, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 136, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
    }
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_strip); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 136, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = NULL;
    if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_5))) {
      __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_5);
      if (likely(__pyx_t_1)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
        __Pyx_INCREF(__pyx_t_1);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_5, function);
      }
    }
    __pyx_t_2 = (__pyx_t_1) ? __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_t_1) : __Pyx_PyObject_CallNoArg(__pyx_t_5);
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 136, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_DECREF_SET(__pyx_v_postTitle, __pyx_t_2);
    __pyx_t_2 = 0;

    /* "KakaoChat/kakao.py":135
 *     """   """
 *     duplicate = "[" + postWriter + "]"
 *     if duplicate in postTitle:  # writer: [writer] title             # <<<<<<<<<<<<<<
 *         postTitle = postTitle.replace(duplicate, "").strip()  # -> writer: title
 * 
 */
  }

  /* "KakaoChat/kakao.py":138
 *         postTitle = postTitle.replace(duplicate, "").strip()  # -> writer: title
 * 
 *     return {             # <<<<<<<<<<<<<<
 *         "title": (postTitle[:32] + "...") if len(postTitle) > 35 else postTitle,
 *         "description": postWriter,
 */
  __Pyx_XDECREF(__pyx_r);

  /* "KakaoChat/kakao.py":139
 * 
 *     return {
 *         "title": (postTitle[:32] + "...") if len(postTitle) > 35 else postTitle,             # <<<<<<<<<<<<<<
 *         "description": postWriter,
 *         # "imageUrl": "http://k.kakaocdn.net/dn/APR96/btqqH7zLanY/kD5mIPX7TdD2NAxgP29cC0/1x1.jpg",
 */
  __pyx_t_2 = __Pyx_PyDict_NewPresized(3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 139, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_9 = PyObject_Length(__pyx_v_postTitle); if (unlikely(__pyx_t_9 == ((Py_ssize_t)-1))) __PYX_ERR(0, 139, __pyx_L1_error)
  if (((__pyx_t_9 > 35) != 0)) {
    __pyx_t_1 = __Pyx_PyObject_GetSlice(__pyx_v_postTitle, 0, 32, NULL, NULL, &__pyx_slice__9, 0, 1, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 139, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_8 = PyNumber_Add(__pyx_t_1, __pyx_kp_u__10); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 139, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_5 = __pyx_t_8;
    __pyx_t_8 = 0;
  } else {
    __Pyx_INCREF(__pyx_v_postTitle);
    __pyx_t_5 = __pyx_v_postTitle;
  }
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_u_title, __pyx_t_5) < 0) __PYX_ERR(0, 139, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  /* "KakaoChat/kakao.py":140
 *     return {
 *         "title": (postTitle[:32] + "...") if len(postTitle) > 35 else postTitle,
 *         "description": postWriter,             # <<<<<<<<<<<<<<
 *         # "imageUrl": "http://k.kakaocdn.net/dn/APR96/btqqH7zLanY/kD5mIPX7TdD2NAxgP29cC0/1x1.jpg",
 *         "link": {"web": postLink},
 */
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_u_description, __pyx_v_postWriter) < 0) __PYX_ERR(0, 139, __pyx_L1_error)

  /* "KakaoChat/kakao.py":142
 *         "description": postWriter,
 *         # "imageUrl": "http://k.kakaocdn.net/dn/APR96/btqqH7zLanY/kD5mIPX7TdD2NAxgP29cC0/1x1.jpg",
 *         "link": {"web": postLink},             # <<<<<<<<<<<<<<
 *     }
 * 
 */
  __pyx_t_5 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 142, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (PyDict_SetItem(__pyx_t_5, __pyx_n_u_web, __pyx_v_postLink) < 0) __PYX_ERR(0, 142, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_u_link, __pyx_t_5) < 0) __PYX_ERR(0, 139, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_r = __pyx_t_2;
  __pyx_t_2 = 0;
  goto __pyx_L0;

  /* "KakaoChat/kakao.py":132
 * 
 * 
 * def makeJSON(postId, postTitle, postDate, postLink, postWriter):             # <<<<<<<<<<<<<<
 *     """   """
 *     duplicate = "[" + postWriter + "]"
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_AddTraceback("KakaoChat.kakao.makeJSON", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_duplicate);
  __Pyx_XDECREF(__pyx_v_postTitle);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "KakaoChat/kakao.py":146
 * 
 * 
 * def makeJSONwithDate(postId, postTitle, postDate, postLink, postWriter):             # <<<<<<<<<<<<<<
 *     """   , writer  ."""
 *     duplicate = "[" + postWriter + "]"
 */

/* Python wrapper */
static PyObject *__pyx_pw_9KakaoChat_5kakao_18makeJSONwithDate(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_9KakaoChat_5kakao_17makeJSONwithDate[] = "\353\246\254\354\212\244\355\212\270 \354\271\264\353\223\234\355\230\225\354\235\230 \354\271\264\353\223\234 \355\230\225\354\213\235, writer\353\222\244\354\227\220 \353\202\240\354\247\234\353\245\274 \353\204\243\354\226\264\354\244\200\353\213\244.";
static PyMethodDef __pyx_mdef_9KakaoChat_5kakao_18makeJSONwithDate = {"makeJSONwithDate", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_9KakaoChat_5kakao_18makeJSONwithDate, METH_VARARGS|METH_KEYWORDS, __pyx_doc_9KakaoChat_5kakao_17makeJSONwithDate};
static PyObject *__pyx_pw_9KakaoChat_5kakao_18makeJSONwithDate(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  CYTHON_UNUSED PyObject *__pyx_v_postId = 0;
  PyObject *__pyx_v_postTitle = 0;
  PyObject *__pyx_v_postDate = 0;
  PyObject *__pyx_v_postLink = 0;
  PyObject *__pyx_v_postWriter = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("makeJSONwithDate (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_postId,&__pyx_n_s_postTitle,&__pyx_n_s_postDate,&__pyx_n_s_postLink,&__pyx_n_s_postWriter,0};
    PyObject* values[5] = {0,0,0,0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  5: values[4] = PyTuple_GET_ITEM(__pyx_args, 4);
        CYTHON_FALLTHROUGH;
        case  4: values[3] = PyTuple_GET_ITEM(__pyx_args, 3);
        CYTHON_FALLTHROUGH;
        case  3: values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
        CYTHON_FALLTHROUGH;
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_postId)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_postTitle)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("makeJSONwithDate", 1, 5, 5, 1); __PYX_ERR(0, 146, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (likely((values[2] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_postDate)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("makeJSONwithDate", 1, 5, 5, 2); __PYX_ERR(0, 146, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  3:
        if (likely((values[3] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_postLink)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("makeJSONwithDate", 1, 5, 5, 3); __PYX_ERR(0, 146, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  4:
        if (likely((values[4] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_postWriter)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("makeJSONwithDate", 1, 5, 5, 4); __PYX_ERR(0, 146, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "makeJSONwithDate") < 0)) __PYX_ERR(0, 146, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 5) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
      values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
      values[3] = PyTuple_GET_ITEM(__pyx_args, 3);
      values[4] = PyTuple_GET_ITEM(__pyx_args, 4);
    }
    __pyx_v_postId = values[0];
    __pyx_v_postTitle = values[1];
    __pyx_v_postDate = values[2];
    __pyx_v_postLink = values[3];
    __pyx_v_postWriter = values[4];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("makeJSONwithDate", 1, 5, 5, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 146, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("KakaoChat.kakao.makeJSONwithDate", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_9KakaoChat_5kakao_17makeJSONwithDate(__pyx_self, __pyx_v_postId, __pyx_v_postTitle, __pyx_v_postDate, __pyx_v_postLink, __pyx_v_postWriter);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_9KakaoChat_5kakao_17makeJSONwithDate(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_postId, PyObject *__pyx_v_postTitle, PyObject *__pyx_v_postDate, PyObject *__pyx_v_postLink, PyObject *__pyx_v_postWriter) {
  PyObject *__pyx_v_duplicate = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  int __pyx_t_3;
  int __pyx_t_4;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  int __pyx_t_7;
  PyObject *__pyx_t_8 = NULL;
  Py_ssize_t __pyx_t_9;
  Py_UCS4 __pyx_t_10;
  Py_ssize_t __pyx_t_11;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("makeJSONwithDate", 0);
  __Pyx_INCREF(__pyx_v_postTitle);

  /* "KakaoChat/kakao.py":148
 * def makeJSONwithDate(postId, postTitle, postDate, postLink, postWriter):
 *     """   , writer  ."""
 *     duplicate = "[" + postWriter + "]"             # <<<<<<<<<<<<<<
 *     if duplicate in postTitle:  # writer: [writer] title
 *         postTitle = postTitle.replace(duplicate, "").strip()  # -> writer: title
 */
  __pyx_t_1 = PyNumber_Add(__pyx_kp_u__6, __pyx_v_postWriter); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 148, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyNumber_Add(__pyx_t_1, __pyx_kp_u__7); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 148, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_v_duplicate = __pyx_t_2;
  __pyx_t_2 = 0;

  /* "KakaoChat/kakao.py":149
 *     """   , writer  ."""
 *     duplicate = "[" + postWriter + "]"
 *     if duplicate in postTitle:  # writer: [writer] title             # <<<<<<<<<<<<<<
 *         postTitle = postTitle.replace(duplicate, "").strip()  # -> writer: title
 *     return {
 */
  __pyx_t_3 = (__Pyx_PySequence_ContainsTF(__pyx_v_duplicate, __pyx_v_postTitle, Py_EQ)); if (unlikely(__pyx_t_3 < 0)) __PYX_ERR(0, 149, __pyx_L1_error)
  __pyx_t_4 = (__pyx_t_3 != 0);
  if (__pyx_t_4) {

    /* "KakaoChat/kakao.py":150
 *     duplicate = "[" + postWriter + "]"
 *     if duplicate in postTitle:  # writer: [writer] title
 *         postTitle = postTitle.replace(duplicate, "").strip()  # -> writer: title             # <<<<<<<<<<<<<<
 *     return {
 *         "title": (postTitle[:32] + "...") if len(postTitle) > 35 else postTitle,
 */
    __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_v_postTitle, __pyx_n_s_replace); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 150, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_6 = NULL;
    __pyx_t_7 = 0;
    if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_5))) {
      __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_5);
      if (likely(__pyx_t_6)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
        __Pyx_INCREF(__pyx_t_6);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_5, function);
        __pyx_t_7 = 1;
      }
    }
    #if CYTHON_FAST_PYCALL
    if (PyFunction_Check(__pyx_t_5)) {
      PyObject *__pyx_temp[3] = {__pyx_t_6, __pyx_v_duplicate, __pyx_kp_u__8};
      __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_5, __pyx_temp+1-__pyx_t_7, 2+__pyx_t_7); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 150, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
      __Pyx_GOTREF(__pyx_t_1);
    } else
    #endif
    #if CYTHON_FAST_PYCCALL
    if (__Pyx_PyFastCFunction_Check(__pyx_t_5)) {
      PyObject *__pyx_temp[3] = {__pyx_t_6, __pyx_v_duplicate, __pyx_kp_u__8};
      __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_5, __pyx_temp+1-__pyx_t_7, 2+__pyx_t_7); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 150, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
      __Pyx_GOTREF(__pyx_t_1);
    } else
    #endif
    {
      __pyx_t_8 = PyTuple_New(2+__pyx_t_7); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 150, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_8);
      if (__pyx_t_6) {
        __Pyx_GIVEREF(__pyx_t_6); PyTuple_SET_ITEM(__pyx_t_8, 0, __pyx_t_6); __pyx_t_6 = NULL;
      }
      __Pyx_INCREF(__pyx_v_duplicate);
      __Pyx_GIVEREF(__pyx_v_duplicate);
      PyTuple_SET_ITEM(__pyx_t_8, 0+__pyx_t_7, __pyx_v_duplicate);
      __Pyx_INCREF(__pyx_kp_u__8);
      __Pyx_GIVEREF(__pyx_kp_u__8);
      PyTuple_SET_ITEM(__pyx_t_8, 1+__pyx_t_7, __pyx_kp_u__8);
      __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_5, __pyx_t_8, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 150, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
    }
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_strip); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 150, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = NULL;
    if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_5))) {
      __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_5);
      if (likely(__pyx_t_1)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
        __Pyx_INCREF(__pyx_t_1);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_5, function);
      }
    }
    __pyx_t_2 = (__pyx_t_1) ? __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_t_1) : __Pyx_PyObject_CallNoArg(__pyx_t_5);
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 150, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_DECREF_SET(__pyx_v_postTitle, __pyx_t_2);
    __pyx_t_2 = 0;

    /* "KakaoChat/kakao.py":149
 *     """   , writer  ."""
 *     duplicate = "[" + postWriter + "]"
 *     if duplicate in postTitle:  # writer: [writer] title             # <<<<<<<<<<<<<<
 *         postTitle = postTitle.replace(duplicate, "").strip()  # -> writer: title
 *     return {
 */
  }

  /* "KakaoChat/kakao.py":151
 *     if duplicate in postTitle:  # writer: [writer] title
 *         postTitle = postTitle.replace(duplicate, "").strip()  # -> writer: title
 *     return {             # <<<<<<<<<<<<<<
 *         "title": (postTitle[:32] + "...") if len(postTitle) > 35 else postTitle,
 *         "description": f"{postWriter} {postDate[len(postDate) -5:]}",  #  12.25 (maxLength=16)
 */
  __Pyx_XDECREF(__pyx_r);

  /* "KakaoChat/kakao.py":152
 *         postTitle = postTitle.replace(duplicate, "").strip()  # -> writer: title
 *     return {
 *         "title": (postTitle[:32] + "...") if len(postTitle) > 35 else postTitle,             # <<<<<<<<<<<<<<
 *         "description": f"{postWriter} {postDate[len(postDate) -5:]}",  #  12.25 (maxLength=16)
 *         # "imageUrl": "http://k.kakaocdn.net/dn/APR96/btqqH7zLanY/kD5mIPX7TdD2NAxgP29cC0/1x1.jpg",
 */
  __pyx_t_2 = __Pyx_PyDict_NewPresized(3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 152, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_9 = PyObject_Length(__pyx_v_postTitle); if (unlikely(__pyx_t_9 == ((Py_ssize_t)-1))) __PYX_ERR(0, 152, __pyx_L1_error)
  if (((__pyx_t_9 > 35) != 0)) {
    __pyx_t_1 = __Pyx_PyObject_GetSlice(__pyx_v_postTitle, 0, 32, NULL, NULL, &__pyx_slice__9, 0, 1, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 152, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_8 = PyNumber_Add(__pyx_t_1, __pyx_kp_u__10); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 152, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_5 = __pyx_t_8;
    __pyx_t_8 = 0;
  } else {
    __Pyx_INCREF(__pyx_v_postTitle);
    __pyx_t_5 = __pyx_v_postTitle;
  }
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_u_title, __pyx_t_5) < 0) __PYX_ERR(0, 152, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  /* "KakaoChat/kakao.py":153
 *     return {
 *         "title": (postTitle[:32] + "...") if len(postTitle) > 35 else postTitle,
 *         "description": f"{postWriter} {postDate[len(postDate) -5:]}",  #  12.25 (maxLength=16)             # <<<<<<<<<<<<<<
 *         # "imageUrl": "http://k.kakaocdn.net/dn/APR96/btqqH7zLanY/kD5mIPX7TdD2NAxgP29cC0/1x1.jpg",
 *         "link": {"web": postLink},
 */
  __pyx_t_5 = PyTuple_New(3); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 153, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_9 = 0;
  __pyx_t_10 = 127;
  __pyx_t_8 = __Pyx_PyObject_FormatSimple(__pyx_v_postWriter, __pyx_empty_unicode); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 153, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_10 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_8) > __pyx_t_10) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_8) : __pyx_t_10;
  __pyx_t_9 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_8);
  __Pyx_GIVEREF(__pyx_t_8);
  PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_8);
  __pyx_t_8 = 0;
  __Pyx_INCREF(__pyx_kp_u__11);
  __pyx_t_9 += 1;
  __Pyx_GIVEREF(__pyx_kp_u__11);
  PyTuple_SET_ITEM(__pyx_t_5, 1, __pyx_kp_u__11);
  __pyx_t_11 = PyObject_Length(__pyx_v_postDate); if (unlikely(__pyx_t_11 == ((Py_ssize_t)-1))) __PYX_ERR(0, 153, __pyx_L1_error)
  __pyx_t_8 = __Pyx_PyObject_GetSlice(__pyx_v_postDate, (__pyx_t_11 - 5), 0, NULL, NULL, NULL, 1, 0, 1); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 153, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_1 = __Pyx_PyObject_FormatSimple(__pyx_t_8, __pyx_empty_unicode); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 153, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_10 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_1) > __pyx_t_10) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_1) : __pyx_t_10;
  __pyx_t_9 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_5, 2, __pyx_t_1);
  __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyUnicode_Join(__pyx_t_5, 3, __pyx_t_9, __pyx_t_10); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 153, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_u_description, __pyx_t_1) < 0) __PYX_ERR(0, 152, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":155
 *         "description": f"{postWriter} {postDate[len(postDate) -5:]}",  #  12.25 (maxLength=16)
 *         # "imageUrl": "http://k.kakaocdn.net/dn/APR96/btqqH7zLanY/kD5mIPX7TdD2NAxgP29cC0/1x1.jpg",
 *         "link": {"web": postLink},             # <<<<<<<<<<<<<<
 *     }
 * 
 */
  __pyx_t_1 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 155, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u_web, __pyx_v_postLink) < 0) __PYX_ERR(0, 155, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_u_link, __pyx_t_1) < 0) __PYX_ERR(0, 152, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_r = __pyx_t_2;
  __pyx_t_2 = 0;
  goto __pyx_L0;

  /* "KakaoChat/kakao.py":146
 * 
 * 
 * def makeJSONwithDate(postId, postTitle, postDate, postLink, postWriter):             # <<<<<<<<<<<<<<
 *     """   , writer  ."""
 *     duplicate = "[" + postWriter + "]"
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_AddTraceback("KakaoChat.kakao.makeJSONwithDate", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_duplicate);
  __Pyx_XDECREF(__pyx_v_postTitle);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "KakaoChat/kakao.py":159
 * 
 * 
 * def makeTimeoutMessage():             # <<<<<<<<<<<<<<
 *     """ checkConnection()  False,  JSON  return"""
 *     return JSONResponse(
 */

/* Python wrapper */
static PyObject *__pyx_pw_9KakaoChat_5kakao_20makeTimeoutMessage(PyObject *__pyx_self, CYTHON_UNUSED PyObject *unused); /*proto*/
static char __pyx_doc_9KakaoChat_5kakao_19makeTimeoutMessage[] = " checkConnection() \352\262\260\352\263\274 False, \354\225\204\353\236\230 JSON \353\215\260\354\235\264\355\204\260\353\245\274 return";
static PyMethodDef __pyx_mdef_9KakaoChat_5kakao_20makeTimeoutMessage = {"makeTimeoutMessage", (PyCFunction)__pyx_pw_9KakaoChat_5kakao_20makeTimeoutMessage, METH_NOARGS, __pyx_doc_9KakaoChat_5kakao_19makeTimeoutMessage};
static PyObject *__pyx_pw_9KakaoChat_5kakao_20makeTimeoutMessage(PyObject *__pyx_self, CYTHON_UNUSED PyObject *unused) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("makeTimeoutMessage (wrapper)", 0);
  __pyx_r = __pyx_pf_9KakaoChat_5kakao_19makeTimeoutMessage(__pyx_self);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_9KakaoChat_5kakao_19makeTimeoutMessage(CYTHON_UNUSED PyObject *__pyx_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("makeTimeoutMessage", 0);

  /* "KakaoChat/kakao.py":161
 * def makeTimeoutMessage():
 *     """ checkConnection()  False,  JSON  return"""
 *     return JSONResponse(             # <<<<<<<<<<<<<<
 *         content={
 *             "version": "2.0",
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_JSONResponse); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 161, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);

  /* "KakaoChat/kakao.py":162
 *     """ checkConnection()  False,  JSON  return"""
 *     return JSONResponse(
 *         content={             # <<<<<<<<<<<<<<
 *             "version": "2.0",
 *             "template": {
 */
  __pyx_t_2 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 162, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);

  /* "KakaoChat/kakao.py":163
 *     return JSONResponse(
 *         content={
 *             "version": "2.0",             # <<<<<<<<<<<<<<
 *             "template": {
 *                 "outputs": [
 */
  __pyx_t_3 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 163, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_version, __pyx_kp_u_2_0) < 0) __PYX_ERR(0, 163, __pyx_L1_error)

  /* "KakaoChat/kakao.py":165
 *             "version": "2.0",
 *             "template": {
 *                 "outputs": [             # <<<<<<<<<<<<<<
 *                     {
 *                         "simpleText": {
 */
  __pyx_t_4 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 165, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);

  /* "KakaoChat/kakao.py":167
 *                 "outputs": [
 *                     {
 *                         "simpleText": {             # <<<<<<<<<<<<<<
 *                             "text": "     .    ."
 *                         }
 */
  __pyx_t_5 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 167, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);

  /* "KakaoChat/kakao.py":168
 *                     {
 *                         "simpleText": {
 *                             "text": "     .    ."             # <<<<<<<<<<<<<<
 *                         }
 *                     }
 */
  __pyx_t_6 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 168, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  if (PyDict_SetItem(__pyx_t_6, __pyx_n_u_text, __pyx_kp_u__12) < 0) __PYX_ERR(0, 168, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_5, __pyx_n_u_simpleText, __pyx_t_6) < 0) __PYX_ERR(0, 167, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;

  /* "KakaoChat/kakao.py":165
 *             "version": "2.0",
 *             "template": {
 *                 "outputs": [             # <<<<<<<<<<<<<<
 *                     {
 *                         "simpleText": {
 */
  __pyx_t_6 = PyList_New(1); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 165, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_GIVEREF(__pyx_t_5);
  PyList_SET_ITEM(__pyx_t_6, 0, __pyx_t_5);
  __pyx_t_5 = 0;
  if (PyDict_SetItem(__pyx_t_4, __pyx_n_u_outputs, __pyx_t_6) < 0) __PYX_ERR(0, 165, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_template, __pyx_t_4) < 0) __PYX_ERR(0, 163, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_content, __pyx_t_3) < 0) __PYX_ERR(0, 162, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "KakaoChat/kakao.py":161
 * def makeTimeoutMessage():
 *     """ checkConnection()  False,  JSON  return"""
 *     return JSONResponse(             # <<<<<<<<<<<<<<
 *         content={
 *             "version": "2.0",
 */
  __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_empty_tuple, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 161, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_r = __pyx_t_3;
  __pyx_t_3 = 0;
  goto __pyx_L0;

  /* "KakaoChat/kakao.py":159
 * 
 * 
 * def makeTimeoutMessage():             # <<<<<<<<<<<<<<
 *     """ checkConnection()  False,  JSON  return"""
 *     return JSONResponse(
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_AddTraceback("KakaoChat.kakao.makeTimeoutMessage", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "KakaoChat/kakao.py":177
 * 
 * 
 * def makeCarouselCard(title, desc):             # <<<<<<<<<<<<<<
 *     card_imgs = ["ajou_carousel", "ajou_carousel_1", "ajou_carousel_2"]
 *     card = {
 */

/* Python wrapper */
static PyObject *__pyx_pw_9KakaoChat_5kakao_22makeCarouselCard(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_9KakaoChat_5kakao_22makeCarouselCard = {"makeCarouselCard", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_9KakaoChat_5kakao_22makeCarouselCard, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_9KakaoChat_5kakao_22makeCarouselCard(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_title = 0;
  PyObject *__pyx_v_desc = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("makeCarouselCard (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_title,&__pyx_n_s_desc,0};
    PyObject* values[2] = {0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_title)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_desc)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("makeCarouselCard", 1, 2, 2, 1); __PYX_ERR(0, 177, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "makeCarouselCard") < 0)) __PYX_ERR(0, 177, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_title = values[0];
    __pyx_v_desc = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("makeCarouselCard", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 177, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("KakaoChat.kakao.makeCarouselCard", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_9KakaoChat_5kakao_21makeCarouselCard(__pyx_self, __pyx_v_title, __pyx_v_desc);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_9KakaoChat_5kakao_21makeCarouselCard(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_title, PyObject *__pyx_v_desc) {
  PyObject *__pyx_v_card_imgs = NULL;
  PyObject *__pyx_v_card = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  Py_ssize_t __pyx_t_4;
  Py_UCS4 __pyx_t_5;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("makeCarouselCard", 0);

  /* "KakaoChat/kakao.py":178
 * 
 * def makeCarouselCard(title, desc):
 *     card_imgs = ["ajou_carousel", "ajou_carousel_1", "ajou_carousel_2"]             # <<<<<<<<<<<<<<
 *     card = {
 *         "title": title,
 */
  __pyx_t_1 = PyList_New(3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 178, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_u_ajou_carousel);
  __Pyx_GIVEREF(__pyx_n_u_ajou_carousel);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_n_u_ajou_carousel);
  __Pyx_INCREF(__pyx_n_u_ajou_carousel_1);
  __Pyx_GIVEREF(__pyx_n_u_ajou_carousel_1);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_n_u_ajou_carousel_1);
  __Pyx_INCREF(__pyx_n_u_ajou_carousel_2);
  __Pyx_GIVEREF(__pyx_n_u_ajou_carousel_2);
  PyList_SET_ITEM(__pyx_t_1, 2, __pyx_n_u_ajou_carousel_2);
  __pyx_v_card_imgs = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":180
 *     card_imgs = ["ajou_carousel", "ajou_carousel_1", "ajou_carousel_2"]
 *     card = {
 *         "title": title,             # <<<<<<<<<<<<<<
 *         "description": desc,
 *         "thumbnail": {
 */
  __pyx_t_1 = __Pyx_PyDict_NewPresized(3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 180, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u_title, __pyx_v_title) < 0) __PYX_ERR(0, 180, __pyx_L1_error)

  /* "KakaoChat/kakao.py":181
 *     card = {
 *         "title": title,
 *         "description": desc,             # <<<<<<<<<<<<<<
 *         "thumbnail": {
 *             "imageUrl": f"https://raw.githubusercontent.com/Alfex4936/kakaoChatbot-Ajou/main/imgs/{choice(card_imgs)}.png"
 */
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u_description, __pyx_v_desc) < 0) __PYX_ERR(0, 180, __pyx_L1_error)

  /* "KakaoChat/kakao.py":183
 *         "description": desc,
 *         "thumbnail": {
 *             "imageUrl": f"https://raw.githubusercontent.com/Alfex4936/kakaoChatbot-Ajou/main/imgs/{choice(card_imgs)}.png"             # <<<<<<<<<<<<<<
 *         },
 *         #   "buttons": [  optional
 */
  __pyx_t_2 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 183, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = PyTuple_New(3); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 183, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = 0;
  __pyx_t_5 = 127;
  __Pyx_INCREF(__pyx_kp_u_https_raw_githubusercontent_com);
  __pyx_t_4 += 72;
  __Pyx_GIVEREF(__pyx_kp_u_https_raw_githubusercontent_com);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_kp_u_https_raw_githubusercontent_com);
  __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_choice); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 183, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __pyx_t_8 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_7))) {
    __pyx_t_8 = PyMethod_GET_SELF(__pyx_t_7);
    if (likely(__pyx_t_8)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_7);
      __Pyx_INCREF(__pyx_t_8);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_7, function);
    }
  }
  __pyx_t_6 = (__pyx_t_8) ? __Pyx_PyObject_Call2Args(__pyx_t_7, __pyx_t_8, __pyx_v_card_imgs) : __Pyx_PyObject_CallOneArg(__pyx_t_7, __pyx_v_card_imgs);
  __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
  if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 183, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_t_7 = __Pyx_PyObject_FormatSimple(__pyx_t_6, __pyx_empty_unicode); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 183, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) : __pyx_t_5;
  __pyx_t_4 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_7);
  __Pyx_GIVEREF(__pyx_t_7);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_7);
  __pyx_t_7 = 0;
  __Pyx_INCREF(__pyx_kp_u_png);
  __pyx_t_4 += 4;
  __Pyx_GIVEREF(__pyx_kp_u_png);
  PyTuple_SET_ITEM(__pyx_t_3, 2, __pyx_kp_u_png);
  __pyx_t_7 = __Pyx_PyUnicode_Join(__pyx_t_3, 3, __pyx_t_4, __pyx_t_5); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 183, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_u_imageUrl, __pyx_t_7) < 0) __PYX_ERR(0, 183, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u_thumbnail, __pyx_t_2) < 0) __PYX_ERR(0, 180, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_card = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":194
 *     }
 * 
 *     return card             # <<<<<<<<<<<<<<
 * 
 * 
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_card);
  __pyx_r = __pyx_v_card;
  goto __pyx_L0;

  /* "KakaoChat/kakao.py":177
 * 
 * 
 * def makeCarouselCard(title, desc):             # <<<<<<<<<<<<<<
 *     card_imgs = ["ajou_carousel", "ajou_carousel_1", "ajou_carousel_2"]
 *     card = {
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_AddTraceback("KakaoChat.kakao.makeCarouselCard", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_card_imgs);
  __Pyx_XDECREF(__pyx_v_card);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "KakaoChat/kakao.py":197
 * 
 * 
 * def getTodayNotices(db, now, user_id):             # <<<<<<<<<<<<<<
 *     """ 30    ,    return"""
 *     noticesToday = []
 */

/* Python wrapper */
static PyObject *__pyx_pw_9KakaoChat_5kakao_24getTodayNotices(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_9KakaoChat_5kakao_23getTodayNotices[] = " 30\352\260\234 \354\240\225\353\217\204\354\235\230 \352\263\265\354\247\200 \353\252\251\353\241\235\354\235\204 \354\235\275\352\263\240, \353\202\240\354\247\234\354\227\220 \353\247\236\353\212\224 \352\262\203\353\247\214 return";
static PyMethodDef __pyx_mdef_9KakaoChat_5kakao_24getTodayNotices = {"getTodayNotices", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_9KakaoChat_5kakao_24getTodayNotices, METH_VARARGS|METH_KEYWORDS, __pyx_doc_9KakaoChat_5kakao_23getTodayNotices};
static PyObject *__pyx_pw_9KakaoChat_5kakao_24getTodayNotices(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_db = 0;
  PyObject *__pyx_v_now = 0;
  PyObject *__pyx_v_user_id = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("getTodayNotices (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_db,&__pyx_n_s_now,&__pyx_n_s_user_id,0};
    PyObject* values[3] = {0,0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  3: values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
        CYTHON_FALLTHROUGH;
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_db)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_now)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("getTodayNotices", 1, 3, 3, 1); __PYX_ERR(0, 197, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (likely((values[2] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_user_id)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("getTodayNotices", 1, 3, 3, 2); __PYX_ERR(0, 197, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "getTodayNotices") < 0)) __PYX_ERR(0, 197, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 3) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
      values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
    }
    __pyx_v_db = values[0];
    __pyx_v_now = values[1];
    __pyx_v_user_id = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("getTodayNotices", 1, 3, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 197, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("KakaoChat.kakao.getTodayNotices", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_9KakaoChat_5kakao_23getTodayNotices(__pyx_self, __pyx_v_db, __pyx_v_now, __pyx_v_user_id);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_9KakaoChat_5kakao_23getTodayNotices(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_db, PyObject *__pyx_v_now, PyObject *__pyx_v_user_id) {
  PyObject *__pyx_v_noticesToday = NULL;
  long __pyx_v_length;
  PyObject *__pyx_v_ids = NULL;
  PyObject *__pyx_v_posts = NULL;
  PyObject *__pyx_v_dates = NULL;
  PyObject *__pyx_v_writers = NULL;
  PyObject *__pyx_v_noticeLength = NULL;
  PyObject *__pyx_v_i = NULL;
  PyObject *__pyx_v_postDate = NULL;
  PyObject *__pyx_v_postTitle = NULL;
  PyObject *__pyx_v_postId = NULL;
  PyObject *__pyx_v_postLink = NULL;
  PyObject *__pyx_v_postWriter = NULL;
  PyObject *__pyx_v_data = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  PyObject *(*__pyx_t_8)(PyObject *);
  Py_ssize_t __pyx_t_9;
  PyObject *(*__pyx_t_10)(PyObject *);
  int __pyx_t_11;
  int __pyx_t_12;
  int __pyx_t_13;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("getTodayNotices", 0);

  /* "KakaoChat/kakao.py":199
 * def getTodayNotices(db, now, user_id):
 *     """ 30    ,    return"""
 *     noticesToday = []             # <<<<<<<<<<<<<<
 *     length = 30
 * 
 */
  __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 199, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v_noticesToday = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":200
 *     """ 30    ,    return"""
 *     noticesToday = []
 *     length = 30             # <<<<<<<<<<<<<<
 * 
 *     ids, posts, dates, writers, noticeLength = parseNotices(
 */
  __pyx_v_length = 30;

  /* "KakaoChat/kakao.py":202
 *     length = 30
 * 
 *     ids, posts, dates, writers, noticeLength = parseNotices(             # <<<<<<<<<<<<<<
 *         length=length
 *     )  # Parse notices
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_parseNotices); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 202, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);

  /* "KakaoChat/kakao.py":203
 * 
 *     ids, posts, dates, writers, noticeLength = parseNotices(
 *         length=length             # <<<<<<<<<<<<<<
 *     )  # Parse notices
 * 
 */
  __pyx_t_2 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 203, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyInt_From_long(__pyx_v_length); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 203, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_length, __pyx_t_3) < 0) __PYX_ERR(0, 203, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "KakaoChat/kakao.py":202
 *     length = 30
 * 
 *     ids, posts, dates, writers, noticeLength = parseNotices(             # <<<<<<<<<<<<<<
 *         length=length
 *     )  # Parse notices
 */
  __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_empty_tuple, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 202, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if ((likely(PyTuple_CheckExact(__pyx_t_3))) || (PyList_CheckExact(__pyx_t_3))) {
    PyObject* sequence = __pyx_t_3;
    Py_ssize_t size = __Pyx_PySequence_SIZE(sequence);
    if (unlikely(size != 5)) {
      if (size > 5) __Pyx_RaiseTooManyValuesError(5);
      else if (size >= 0) __Pyx_RaiseNeedMoreValuesError(size);
      __PYX_ERR(0, 202, __pyx_L1_error)
    }
    #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    if (likely(PyTuple_CheckExact(sequence))) {
      __pyx_t_2 = PyTuple_GET_ITEM(sequence, 0); 
      __pyx_t_1 = PyTuple_GET_ITEM(sequence, 1); 
      __pyx_t_4 = PyTuple_GET_ITEM(sequence, 2); 
      __pyx_t_5 = PyTuple_GET_ITEM(sequence, 3); 
      __pyx_t_6 = PyTuple_GET_ITEM(sequence, 4); 
    } else {
      __pyx_t_2 = PyList_GET_ITEM(sequence, 0); 
      __pyx_t_1 = PyList_GET_ITEM(sequence, 1); 
      __pyx_t_4 = PyList_GET_ITEM(sequence, 2); 
      __pyx_t_5 = PyList_GET_ITEM(sequence, 3); 
      __pyx_t_6 = PyList_GET_ITEM(sequence, 4); 
    }
    __Pyx_INCREF(__pyx_t_2);
    __Pyx_INCREF(__pyx_t_1);
    __Pyx_INCREF(__pyx_t_4);
    __Pyx_INCREF(__pyx_t_5);
    __Pyx_INCREF(__pyx_t_6);
    #else
    {
      Py_ssize_t i;
      PyObject** temps[5] = {&__pyx_t_2,&__pyx_t_1,&__pyx_t_4,&__pyx_t_5,&__pyx_t_6};
      for (i=0; i < 5; i++) {
        PyObject* item = PySequence_ITEM(sequence, i); if (unlikely(!item)) __PYX_ERR(0, 202, __pyx_L1_error)
        __Pyx_GOTREF(item);
        *(temps[i]) = item;
      }
    }
    #endif
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  } else {
    Py_ssize_t index = -1;
    PyObject** temps[5] = {&__pyx_t_2,&__pyx_t_1,&__pyx_t_4,&__pyx_t_5,&__pyx_t_6};
    __pyx_t_7 = PyObject_GetIter(__pyx_t_3); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 202, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_8 = Py_TYPE(__pyx_t_7)->tp_iternext;
    for (index=0; index < 5; index++) {
      PyObject* item = __pyx_t_8(__pyx_t_7); if (unlikely(!item)) goto __pyx_L3_unpacking_failed;
      __Pyx_GOTREF(item);
      *(temps[index]) = item;
    }
    if (__Pyx_IternextUnpackEndCheck(__pyx_t_8(__pyx_t_7), 5) < 0) __PYX_ERR(0, 202, __pyx_L1_error)
    __pyx_t_8 = NULL;
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    goto __pyx_L4_unpacking_done;
    __pyx_L3_unpacking_failed:;
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    __pyx_t_8 = NULL;
    if (__Pyx_IterFinish() == 0) __Pyx_RaiseNeedMoreValuesError(index);
    __PYX_ERR(0, 202, __pyx_L1_error)
    __pyx_L4_unpacking_done:;
  }
  __pyx_v_ids = __pyx_t_2;
  __pyx_t_2 = 0;
  __pyx_v_posts = __pyx_t_1;
  __pyx_t_1 = 0;
  __pyx_v_dates = __pyx_t_4;
  __pyx_t_4 = 0;
  __pyx_v_writers = __pyx_t_5;
  __pyx_t_5 = 0;
  __pyx_v_noticeLength = __pyx_t_6;
  __pyx_t_6 = 0;

  /* "KakaoChat/kakao.py":206
 *     )  # Parse notices
 * 
 *     for i in range(noticeLength):             # <<<<<<<<<<<<<<
 *         postDate = dates[i].text(strip=True)
 *         if postDate != now:
 */
  __pyx_t_3 = __Pyx_PyObject_CallOneArg(__pyx_builtin_range, __pyx_v_noticeLength); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 206, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (likely(PyList_CheckExact(__pyx_t_3)) || PyTuple_CheckExact(__pyx_t_3)) {
    __pyx_t_6 = __pyx_t_3; __Pyx_INCREF(__pyx_t_6); __pyx_t_9 = 0;
    __pyx_t_10 = NULL;
  } else {
    __pyx_t_9 = -1; __pyx_t_6 = PyObject_GetIter(__pyx_t_3); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 206, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __pyx_t_10 = Py_TYPE(__pyx_t_6)->tp_iternext; if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 206, __pyx_L1_error)
  }
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  for (;;) {
    if (likely(!__pyx_t_10)) {
      if (likely(PyList_CheckExact(__pyx_t_6))) {
        if (__pyx_t_9 >= PyList_GET_SIZE(__pyx_t_6)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_3 = PyList_GET_ITEM(__pyx_t_6, __pyx_t_9); __Pyx_INCREF(__pyx_t_3); __pyx_t_9++; if (unlikely(0 < 0)) __PYX_ERR(0, 206, __pyx_L1_error)
        #else
        __pyx_t_3 = PySequence_ITEM(__pyx_t_6, __pyx_t_9); __pyx_t_9++; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 206, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        #endif
      } else {
        if (__pyx_t_9 >= PyTuple_GET_SIZE(__pyx_t_6)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_3 = PyTuple_GET_ITEM(__pyx_t_6, __pyx_t_9); __Pyx_INCREF(__pyx_t_3); __pyx_t_9++; if (unlikely(0 < 0)) __PYX_ERR(0, 206, __pyx_L1_error)
        #else
        __pyx_t_3 = PySequence_ITEM(__pyx_t_6, __pyx_t_9); __pyx_t_9++; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 206, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        #endif
      }
    } else {
      __pyx_t_3 = __pyx_t_10(__pyx_t_6);
      if (unlikely(!__pyx_t_3)) {
        PyObject* exc_type = PyErr_Occurred();
        if (exc_type) {
          if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
          else __PYX_ERR(0, 206, __pyx_L1_error)
        }
        break;
      }
      __Pyx_GOTREF(__pyx_t_3);
    }
    __Pyx_XDECREF_SET(__pyx_v_i, __pyx_t_3);
    __pyx_t_3 = 0;

    /* "KakaoChat/kakao.py":207
 * 
 *     for i in range(noticeLength):
 *         postDate = dates[i].text(strip=True)             # <<<<<<<<<<<<<<
 *         if postDate != now:
 *             break  # don't have to check other notices
 */
    __pyx_t_3 = __Pyx_PyObject_GetItem(__pyx_v_dates, __pyx_v_i); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 207, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_text); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 207, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_3 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 207, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_strip, Py_True) < 0) __PYX_ERR(0, 207, __pyx_L1_error)
    __pyx_t_4 = __Pyx_PyObject_Call(__pyx_t_5, __pyx_empty_tuple, __pyx_t_3); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 207, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_XDECREF_SET(__pyx_v_postDate, __pyx_t_4);
    __pyx_t_4 = 0;

    /* "KakaoChat/kakao.py":208
 *     for i in range(noticeLength):
 *         postDate = dates[i].text(strip=True)
 *         if postDate != now:             # <<<<<<<<<<<<<<
 *             break  # don't have to check other notices
 *         postTitle = posts[i].text(strip=True)
 */
    __pyx_t_4 = PyObject_RichCompare(__pyx_v_postDate, __pyx_v_now, Py_NE); __Pyx_XGOTREF(__pyx_t_4); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 208, __pyx_L1_error)
    __pyx_t_11 = __Pyx_PyObject_IsTrue(__pyx_t_4); if (unlikely(__pyx_t_11 < 0)) __PYX_ERR(0, 208, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    if (__pyx_t_11) {

      /* "KakaoChat/kakao.py":209
 *         postDate = dates[i].text(strip=True)
 *         if postDate != now:
 *             break  # don't have to check other notices             # <<<<<<<<<<<<<<
 *         postTitle = posts[i].text(strip=True)
 *         postId = ids[i].text(strip=True)
 */
      goto __pyx_L6_break;

      /* "KakaoChat/kakao.py":208
 *     for i in range(noticeLength):
 *         postDate = dates[i].text(strip=True)
 *         if postDate != now:             # <<<<<<<<<<<<<<
 *             break  # don't have to check other notices
 *         postTitle = posts[i].text(strip=True)
 */
    }

    /* "KakaoChat/kakao.py":210
 *         if postDate != now:
 *             break  # don't have to check other notices
 *         postTitle = posts[i].text(strip=True)             # <<<<<<<<<<<<<<
 *         postId = ids[i].text(strip=True)
 *         postLink = ADDRESS + posts[i].attributes["href"]
 */
    __pyx_t_4 = __Pyx_PyObject_GetItem(__pyx_v_posts, __pyx_v_i); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 210, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_4, __pyx_n_s_text); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 210, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_4 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 210, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_strip, Py_True) < 0) __PYX_ERR(0, 210, __pyx_L1_error)
    __pyx_t_5 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_empty_tuple, __pyx_t_4); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 210, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_XDECREF_SET(__pyx_v_postTitle, __pyx_t_5);
    __pyx_t_5 = 0;

    /* "KakaoChat/kakao.py":211
 *             break  # don't have to check other notices
 *         postTitle = posts[i].text(strip=True)
 *         postId = ids[i].text(strip=True)             # <<<<<<<<<<<<<<
 *         postLink = ADDRESS + posts[i].attributes["href"]
 *         postWriter = writers[i].text(strip=False)
 */
    __pyx_t_5 = __Pyx_PyObject_GetItem(__pyx_v_ids, __pyx_v_i); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 211, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_5, __pyx_n_s_text); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 211, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_5 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 211, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    if (PyDict_SetItem(__pyx_t_5, __pyx_n_s_strip, Py_True) < 0) __PYX_ERR(0, 211, __pyx_L1_error)
    __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_4, __pyx_empty_tuple, __pyx_t_5); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 211, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_XDECREF_SET(__pyx_v_postId, __pyx_t_3);
    __pyx_t_3 = 0;

    /* "KakaoChat/kakao.py":212
 *         postTitle = posts[i].text(strip=True)
 *         postId = ids[i].text(strip=True)
 *         postLink = ADDRESS + posts[i].attributes["href"]             # <<<<<<<<<<<<<<
 *         postWriter = writers[i].text(strip=False)
 * 
 */
    __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_ADDRESS); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 212, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_5 = __Pyx_PyObject_GetItem(__pyx_v_posts, __pyx_v_i); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 212, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_5, __pyx_n_s_attributes); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 212, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_5 = __Pyx_PyObject_Dict_GetItem(__pyx_t_4, __pyx_n_u_href); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 212, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_4 = PyNumber_Add(__pyx_t_3, __pyx_t_5); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 212, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_XDECREF_SET(__pyx_v_postLink, __pyx_t_4);
    __pyx_t_4 = 0;

    /* "KakaoChat/kakao.py":213
 *         postId = ids[i].text(strip=True)
 *         postLink = ADDRESS + posts[i].attributes["href"]
 *         postWriter = writers[i].text(strip=False)             # <<<<<<<<<<<<<<
 * 
 *         data = makeJSON(postId, postTitle, postDate, postLink, postWriter)
 */
    __pyx_t_4 = __Pyx_PyObject_GetItem(__pyx_v_writers, __pyx_v_i); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 213, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_4, __pyx_n_s_text); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 213, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_4 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 213, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_strip, Py_False) < 0) __PYX_ERR(0, 213, __pyx_L1_error)
    __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_5, __pyx_empty_tuple, __pyx_t_4); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 213, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_XDECREF_SET(__pyx_v_postWriter, __pyx_t_3);
    __pyx_t_3 = 0;

    /* "KakaoChat/kakao.py":215
 *         postWriter = writers[i].text(strip=False)
 * 
 *         data = makeJSON(postId, postTitle, postDate, postLink, postWriter)             # <<<<<<<<<<<<<<
 *         noticesToday.append(data)
 * 
 */
    __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_makeJSON); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 215, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_5 = NULL;
    __pyx_t_12 = 0;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_4))) {
      __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_4);
      if (likely(__pyx_t_5)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
        __Pyx_INCREF(__pyx_t_5);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_4, function);
        __pyx_t_12 = 1;
      }
    }
    #if CYTHON_FAST_PYCALL
    if (PyFunction_Check(__pyx_t_4)) {
      PyObject *__pyx_temp[6] = {__pyx_t_5, __pyx_v_postId, __pyx_v_postTitle, __pyx_v_postDate, __pyx_v_postLink, __pyx_v_postWriter};
      __pyx_t_3 = __Pyx_PyFunction_FastCall(__pyx_t_4, __pyx_temp+1-__pyx_t_12, 5+__pyx_t_12); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 215, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
      __Pyx_GOTREF(__pyx_t_3);
    } else
    #endif
    #if CYTHON_FAST_PYCCALL
    if (__Pyx_PyFastCFunction_Check(__pyx_t_4)) {
      PyObject *__pyx_temp[6] = {__pyx_t_5, __pyx_v_postId, __pyx_v_postTitle, __pyx_v_postDate, __pyx_v_postLink, __pyx_v_postWriter};
      __pyx_t_3 = __Pyx_PyCFunction_FastCall(__pyx_t_4, __pyx_temp+1-__pyx_t_12, 5+__pyx_t_12); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 215, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
      __Pyx_GOTREF(__pyx_t_3);
    } else
    #endif
    {
      __pyx_t_1 = PyTuple_New(5+__pyx_t_12); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 215, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      if (__pyx_t_5) {
        __Pyx_GIVEREF(__pyx_t_5); PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_t_5); __pyx_t_5 = NULL;
      }
      __Pyx_INCREF(__pyx_v_postId);
      __Pyx_GIVEREF(__pyx_v_postId);
      PyTuple_SET_ITEM(__pyx_t_1, 0+__pyx_t_12, __pyx_v_postId);
      __Pyx_INCREF(__pyx_v_postTitle);
      __Pyx_GIVEREF(__pyx_v_postTitle);
      PyTuple_SET_ITEM(__pyx_t_1, 1+__pyx_t_12, __pyx_v_postTitle);
      __Pyx_INCREF(__pyx_v_postDate);
      __Pyx_GIVEREF(__pyx_v_postDate);
      PyTuple_SET_ITEM(__pyx_t_1, 2+__pyx_t_12, __pyx_v_postDate);
      __Pyx_INCREF(__pyx_v_postLink);
      __Pyx_GIVEREF(__pyx_v_postLink);
      PyTuple_SET_ITEM(__pyx_t_1, 3+__pyx_t_12, __pyx_v_postLink);
      __Pyx_INCREF(__pyx_v_postWriter);
      __Pyx_GIVEREF(__pyx_v_postWriter);
      PyTuple_SET_ITEM(__pyx_t_1, 4+__pyx_t_12, __pyx_v_postWriter);
      __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_4, __pyx_t_1, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 215, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    }
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_XDECREF_SET(__pyx_v_data, __pyx_t_3);
    __pyx_t_3 = 0;

    /* "KakaoChat/kakao.py":216
 * 
 *         data = makeJSON(postId, postTitle, postDate, postLink, postWriter)
 *         noticesToday.append(data)             # <<<<<<<<<<<<<<
 * 
 *     updateLastNotice(db, user_id, int(ids[0].text(strip=True)))
 */
    __pyx_t_13 = __Pyx_PyList_Append(__pyx_v_noticesToday, __pyx_v_data); if (unlikely(__pyx_t_13 == ((int)-1))) __PYX_ERR(0, 216, __pyx_L1_error)

    /* "KakaoChat/kakao.py":206
 *     )  # Parse notices
 * 
 *     for i in range(noticeLength):             # <<<<<<<<<<<<<<
 *         postDate = dates[i].text(strip=True)
 *         if postDate != now:
 */
  }
  __pyx_L6_break:;
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;

  /* "KakaoChat/kakao.py":218
 *         noticesToday.append(data)
 * 
 *     updateLastNotice(db, user_id, int(ids[0].text(strip=True)))             # <<<<<<<<<<<<<<
 * 
 *     return noticesToday
 */
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_updateLastNotice); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 218, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = __Pyx_GetItemInt(__pyx_v_ids, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 218, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_4, __pyx_n_s_text); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 218, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 218, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_strip, Py_True) < 0) __PYX_ERR(0, 218, __pyx_L1_error)
  __pyx_t_5 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_empty_tuple, __pyx_t_4); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 218, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_PyNumber_Int(__pyx_t_5); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 218, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = NULL;
  __pyx_t_12 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
    __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_3);
    if (likely(__pyx_t_5)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_5);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_3, function);
      __pyx_t_12 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_3)) {
    PyObject *__pyx_temp[4] = {__pyx_t_5, __pyx_v_db, __pyx_v_user_id, __pyx_t_4};
    __pyx_t_6 = __Pyx_PyFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_12, 3+__pyx_t_12); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 218, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_3)) {
    PyObject *__pyx_temp[4] = {__pyx_t_5, __pyx_v_db, __pyx_v_user_id, __pyx_t_4};
    __pyx_t_6 = __Pyx_PyCFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_12, 3+__pyx_t_12); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 218, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  } else
  #endif
  {
    __pyx_t_1 = PyTuple_New(3+__pyx_t_12); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 218, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    if (__pyx_t_5) {
      __Pyx_GIVEREF(__pyx_t_5); PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_t_5); __pyx_t_5 = NULL;
    }
    __Pyx_INCREF(__pyx_v_db);
    __Pyx_GIVEREF(__pyx_v_db);
    PyTuple_SET_ITEM(__pyx_t_1, 0+__pyx_t_12, __pyx_v_db);
    __Pyx_INCREF(__pyx_v_user_id);
    __Pyx_GIVEREF(__pyx_v_user_id);
    PyTuple_SET_ITEM(__pyx_t_1, 1+__pyx_t_12, __pyx_v_user_id);
    __Pyx_GIVEREF(__pyx_t_4);
    PyTuple_SET_ITEM(__pyx_t_1, 2+__pyx_t_12, __pyx_t_4);
    __pyx_t_4 = 0;
    __pyx_t_6 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_t_1, NULL); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 218, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  }
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;

  /* "KakaoChat/kakao.py":220
 *     updateLastNotice(db, user_id, int(ids[0].text(strip=True)))
 * 
 *     return noticesToday             # <<<<<<<<<<<<<<
 * 
 * 
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_noticesToday);
  __pyx_r = __pyx_v_noticesToday;
  goto __pyx_L0;

  /* "KakaoChat/kakao.py":197
 * 
 * 
 * def getTodayNotices(db, now, user_id):             # <<<<<<<<<<<<<<
 *     """ 30    ,    return"""
 *     noticesToday = []
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_AddTraceback("KakaoChat.kakao.getTodayNotices", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_noticesToday);
  __Pyx_XDECREF(__pyx_v_ids);
  __Pyx_XDECREF(__pyx_v_posts);
  __Pyx_XDECREF(__pyx_v_dates);
  __Pyx_XDECREF(__pyx_v_writers);
  __Pyx_XDECREF(__pyx_v_noticeLength);
  __Pyx_XDECREF(__pyx_v_i);
  __Pyx_XDECREF(__pyx_v_postDate);
  __Pyx_XDECREF(__pyx_v_postTitle);
  __Pyx_XDECREF(__pyx_v_postId);
  __Pyx_XDECREF(__pyx_v_postLink);
  __Pyx_XDECREF(__pyx_v_postWriter);
  __Pyx_XDECREF(__pyx_v_data);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "KakaoChat/kakao.py":223
 * 
 * 
 * def getYesterdayNotices(db, now):             # <<<<<<<<<<<<<<
 *     """   MySQL   . """
 *     db_notices = db_model.crud.get_notices_with_date(db=db, date=now)
 */

/* Python wrapper */
static PyObject *__pyx_pw_9KakaoChat_5kakao_26getYesterdayNotices(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_9KakaoChat_5kakao_25getYesterdayNotices[] = " \354\226\264\354\240\234 \352\263\265\354\247\200\353\212\224 MySQL \353\215\260\354\235\264\355\204\260\353\262\240\354\235\264\354\212\244\353\245\274 \355\206\265\355\225\264 \354\235\275\354\226\264\354\230\250\353\213\244. ";
static PyMethodDef __pyx_mdef_9KakaoChat_5kakao_26getYesterdayNotices = {"getYesterdayNotices", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_9KakaoChat_5kakao_26getYesterdayNotices, METH_VARARGS|METH_KEYWORDS, __pyx_doc_9KakaoChat_5kakao_25getYesterdayNotices};
static PyObject *__pyx_pw_9KakaoChat_5kakao_26getYesterdayNotices(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_db = 0;
  PyObject *__pyx_v_now = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("getYesterdayNotices (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_db,&__pyx_n_s_now,0};
    PyObject* values[2] = {0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_db)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_now)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("getYesterdayNotices", 1, 2, 2, 1); __PYX_ERR(0, 223, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "getYesterdayNotices") < 0)) __PYX_ERR(0, 223, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_db = values[0];
    __pyx_v_now = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("getYesterdayNotices", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 223, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("KakaoChat.kakao.getYesterdayNotices", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_9KakaoChat_5kakao_25getYesterdayNotices(__pyx_self, __pyx_v_db, __pyx_v_now);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_9KakaoChat_5kakao_25getYesterdayNotices(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_db, PyObject *__pyx_v_now) {
  PyObject *__pyx_v_db_notices = NULL;
  PyObject *__pyx_v_notices = NULL;
  PyObject *__pyx_v_notice = NULL;
  PyObject *__pyx_v_data = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  Py_ssize_t __pyx_t_4;
  PyObject *(*__pyx_t_5)(PyObject *);
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  PyObject *__pyx_t_9 = NULL;
  PyObject *__pyx_t_10 = NULL;
  PyObject *__pyx_t_11 = NULL;
  int __pyx_t_12;
  PyObject *__pyx_t_13 = NULL;
  int __pyx_t_14;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("getYesterdayNotices", 0);

  /* "KakaoChat/kakao.py":225
 * def getYesterdayNotices(db, now):
 *     """   MySQL   . """
 *     db_notices = db_model.crud.get_notices_with_date(db=db, date=now)             # <<<<<<<<<<<<<<
 * 
 *     notices = []
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_db_model); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 225, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_crud); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 225, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_get_notices_with_date); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 225, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 225, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_db, __pyx_v_db) < 0) __PYX_ERR(0, 225, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_date, __pyx_v_now) < 0) __PYX_ERR(0, 225, __pyx_L1_error)
  __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_empty_tuple, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 225, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_db_notices = __pyx_t_3;
  __pyx_t_3 = 0;

  /* "KakaoChat/kakao.py":227
 *     db_notices = db_model.crud.get_notices_with_date(db=db, date=now)
 * 
 *     notices = []             # <<<<<<<<<<<<<<
 *     for notice in db_notices:
 *         data = makeJSON(
 */
  __pyx_t_3 = PyList_New(0); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 227, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_v_notices = ((PyObject*)__pyx_t_3);
  __pyx_t_3 = 0;

  /* "KakaoChat/kakao.py":228
 * 
 *     notices = []
 *     for notice in db_notices:             # <<<<<<<<<<<<<<
 *         data = makeJSON(
 *             notice.id, notice.title, notice.date, notice.link, notice.writer
 */
  if (likely(PyList_CheckExact(__pyx_v_db_notices)) || PyTuple_CheckExact(__pyx_v_db_notices)) {
    __pyx_t_3 = __pyx_v_db_notices; __Pyx_INCREF(__pyx_t_3); __pyx_t_4 = 0;
    __pyx_t_5 = NULL;
  } else {
    __pyx_t_4 = -1; __pyx_t_3 = PyObject_GetIter(__pyx_v_db_notices); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 228, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_5 = Py_TYPE(__pyx_t_3)->tp_iternext; if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 228, __pyx_L1_error)
  }
  for (;;) {
    if (likely(!__pyx_t_5)) {
      if (likely(PyList_CheckExact(__pyx_t_3))) {
        if (__pyx_t_4 >= PyList_GET_SIZE(__pyx_t_3)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_2 = PyList_GET_ITEM(__pyx_t_3, __pyx_t_4); __Pyx_INCREF(__pyx_t_2); __pyx_t_4++; if (unlikely(0 < 0)) __PYX_ERR(0, 228, __pyx_L1_error)
        #else
        __pyx_t_2 = PySequence_ITEM(__pyx_t_3, __pyx_t_4); __pyx_t_4++; if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 228, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        #endif
      } else {
        if (__pyx_t_4 >= PyTuple_GET_SIZE(__pyx_t_3)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_2 = PyTuple_GET_ITEM(__pyx_t_3, __pyx_t_4); __Pyx_INCREF(__pyx_t_2); __pyx_t_4++; if (unlikely(0 < 0)) __PYX_ERR(0, 228, __pyx_L1_error)
        #else
        __pyx_t_2 = PySequence_ITEM(__pyx_t_3, __pyx_t_4); __pyx_t_4++; if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 228, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        #endif
      }
    } else {
      __pyx_t_2 = __pyx_t_5(__pyx_t_3);
      if (unlikely(!__pyx_t_2)) {
        PyObject* exc_type = PyErr_Occurred();
        if (exc_type) {
          if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
          else __PYX_ERR(0, 228, __pyx_L1_error)
        }
        break;
      }
      __Pyx_GOTREF(__pyx_t_2);
    }
    __Pyx_XDECREF_SET(__pyx_v_notice, __pyx_t_2);
    __pyx_t_2 = 0;

    /* "KakaoChat/kakao.py":229
 *     notices = []
 *     for notice in db_notices:
 *         data = makeJSON(             # <<<<<<<<<<<<<<
 *             notice.id, notice.title, notice.date, notice.link, notice.writer
 *         )
 */
    __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_makeJSON); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 229, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);

    /* "KakaoChat/kakao.py":230
 *     for notice in db_notices:
 *         data = makeJSON(
 *             notice.id, notice.title, notice.date, notice.link, notice.writer             # <<<<<<<<<<<<<<
 *         )
 *         notices.append(data)
 */
    __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_v_notice, __pyx_n_s_id); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 230, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __pyx_t_7 = __Pyx_PyObject_GetAttrStr(__pyx_v_notice, __pyx_n_s_title); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 230, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __pyx_t_8 = __Pyx_PyObject_GetAttrStr(__pyx_v_notice, __pyx_n_s_date); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 230, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __pyx_t_9 = __Pyx_PyObject_GetAttrStr(__pyx_v_notice, __pyx_n_s_link); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 230, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_9);
    __pyx_t_10 = __Pyx_PyObject_GetAttrStr(__pyx_v_notice, __pyx_n_s_writer); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 230, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_10);
    __pyx_t_11 = NULL;
    __pyx_t_12 = 0;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_1))) {
      __pyx_t_11 = PyMethod_GET_SELF(__pyx_t_1);
      if (likely(__pyx_t_11)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
        __Pyx_INCREF(__pyx_t_11);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_1, function);
        __pyx_t_12 = 1;
      }
    }
    #if CYTHON_FAST_PYCALL
    if (PyFunction_Check(__pyx_t_1)) {
      PyObject *__pyx_temp[6] = {__pyx_t_11, __pyx_t_6, __pyx_t_7, __pyx_t_8, __pyx_t_9, __pyx_t_10};
      __pyx_t_2 = __Pyx_PyFunction_FastCall(__pyx_t_1, __pyx_temp+1-__pyx_t_12, 5+__pyx_t_12); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 229, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
    } else
    #endif
    #if CYTHON_FAST_PYCCALL
    if (__Pyx_PyFastCFunction_Check(__pyx_t_1)) {
      PyObject *__pyx_temp[6] = {__pyx_t_11, __pyx_t_6, __pyx_t_7, __pyx_t_8, __pyx_t_9, __pyx_t_10};
      __pyx_t_2 = __Pyx_PyCFunction_FastCall(__pyx_t_1, __pyx_temp+1-__pyx_t_12, 5+__pyx_t_12); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 229, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
    } else
    #endif
    {
      __pyx_t_13 = PyTuple_New(5+__pyx_t_12); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 229, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_13);
      if (__pyx_t_11) {
        __Pyx_GIVEREF(__pyx_t_11); PyTuple_SET_ITEM(__pyx_t_13, 0, __pyx_t_11); __pyx_t_11 = NULL;
      }
      __Pyx_GIVEREF(__pyx_t_6);
      PyTuple_SET_ITEM(__pyx_t_13, 0+__pyx_t_12, __pyx_t_6);
      __Pyx_GIVEREF(__pyx_t_7);
      PyTuple_SET_ITEM(__pyx_t_13, 1+__pyx_t_12, __pyx_t_7);
      __Pyx_GIVEREF(__pyx_t_8);
      PyTuple_SET_ITEM(__pyx_t_13, 2+__pyx_t_12, __pyx_t_8);
      __Pyx_GIVEREF(__pyx_t_9);
      PyTuple_SET_ITEM(__pyx_t_13, 3+__pyx_t_12, __pyx_t_9);
      __Pyx_GIVEREF(__pyx_t_10);
      PyTuple_SET_ITEM(__pyx_t_13, 4+__pyx_t_12, __pyx_t_10);
      __pyx_t_6 = 0;
      __pyx_t_7 = 0;
      __pyx_t_8 = 0;
      __pyx_t_9 = 0;
      __pyx_t_10 = 0;
      __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_t_13, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 229, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_13); __pyx_t_13 = 0;
    }
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_XDECREF_SET(__pyx_v_data, __pyx_t_2);
    __pyx_t_2 = 0;

    /* "KakaoChat/kakao.py":232
 *             notice.id, notice.title, notice.date, notice.link, notice.writer
 *         )
 *         notices.append(data)             # <<<<<<<<<<<<<<
 * 
 *     return notices  # descending ordered notices
 */
    __pyx_t_14 = __Pyx_PyList_Append(__pyx_v_notices, __pyx_v_data); if (unlikely(__pyx_t_14 == ((int)-1))) __PYX_ERR(0, 232, __pyx_L1_error)

    /* "KakaoChat/kakao.py":228
 * 
 *     notices = []
 *     for notice in db_notices:             # <<<<<<<<<<<<<<
 *         data = makeJSON(
 *             notice.id, notice.title, notice.date, notice.link, notice.writer
 */
  }
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "KakaoChat/kakao.py":234
 *         notices.append(data)
 * 
 *     return notices  # descending ordered notices             # <<<<<<<<<<<<<<
 * 
 * 
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_notices);
  __pyx_r = __pyx_v_notices;
  goto __pyx_L0;

  /* "KakaoChat/kakao.py":223
 * 
 * 
 * def getYesterdayNotices(db, now):             # <<<<<<<<<<<<<<
 *     """   MySQL   . """
 *     db_notices = db_model.crud.get_notices_with_date(db=db, date=now)
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_XDECREF(__pyx_t_9);
  __Pyx_XDECREF(__pyx_t_10);
  __Pyx_XDECREF(__pyx_t_11);
  __Pyx_XDECREF(__pyx_t_13);
  __Pyx_AddTraceback("KakaoChat.kakao.getYesterdayNotices", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_db_notices);
  __Pyx_XDECREF(__pyx_v_notices);
  __Pyx_XDECREF(__pyx_v_notice);
  __Pyx_XDECREF(__pyx_v_data);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "KakaoChat/kakao.py":237
 * 
 * 
 * def getLastNotice():             # <<<<<<<<<<<<<<
 *     """  1  . """
 *     ids, posts, dates, writers, _ = parseNotices(length=1)  # Parse one notice
 */

/* Python wrapper */
static PyObject *__pyx_pw_9KakaoChat_5kakao_28getLastNotice(PyObject *__pyx_self, CYTHON_UNUSED PyObject *unused); /*proto*/
static char __pyx_doc_9KakaoChat_5kakao_27getLastNotice[] = " \353\247\210\354\247\200\353\247\211 1\352\260\234\354\235\230 \352\263\265\354\247\200\353\247\214 \354\235\275\354\226\264\354\230\250\353\213\244. ";
static PyMethodDef __pyx_mdef_9KakaoChat_5kakao_28getLastNotice = {"getLastNotice", (PyCFunction)__pyx_pw_9KakaoChat_5kakao_28getLastNotice, METH_NOARGS, __pyx_doc_9KakaoChat_5kakao_27getLastNotice};
static PyObject *__pyx_pw_9KakaoChat_5kakao_28getLastNotice(PyObject *__pyx_self, CYTHON_UNUSED PyObject *unused) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("getLastNotice (wrapper)", 0);
  __pyx_r = __pyx_pf_9KakaoChat_5kakao_27getLastNotice(__pyx_self);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_9KakaoChat_5kakao_27getLastNotice(CYTHON_UNUSED PyObject *__pyx_self) {
  PyObject *__pyx_v_ids = NULL;
  PyObject *__pyx_v_posts = NULL;
  PyObject *__pyx_v_dates = NULL;
  PyObject *__pyx_v_writers = NULL;
  CYTHON_UNUSED PyObject *__pyx_v__ = NULL;
  PyObject *__pyx_v_postDate = NULL;
  PyObject *__pyx_v_postTitle = NULL;
  PyObject *__pyx_v_postId = NULL;
  PyObject *__pyx_v_postLink = NULL;
  PyObject *__pyx_v_postWriter = NULL;
  PyObject *__pyx_v_data = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  PyObject *(*__pyx_t_8)(PyObject *);
  int __pyx_t_9;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("getLastNotice", 0);

  /* "KakaoChat/kakao.py":239
 * def getLastNotice():
 *     """  1  . """
 *     ids, posts, dates, writers, _ = parseNotices(length=1)  # Parse one notice             # <<<<<<<<<<<<<<
 *     postDate = dates[0].text(strip=True)
 *     postTitle = posts[0].text(strip=True)
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_parseNotices); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 239, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 239, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_length, __pyx_int_1) < 0) __PYX_ERR(0, 239, __pyx_L1_error)
  __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_empty_tuple, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 239, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if ((likely(PyTuple_CheckExact(__pyx_t_3))) || (PyList_CheckExact(__pyx_t_3))) {
    PyObject* sequence = __pyx_t_3;
    Py_ssize_t size = __Pyx_PySequence_SIZE(sequence);
    if (unlikely(size != 5)) {
      if (size > 5) __Pyx_RaiseTooManyValuesError(5);
      else if (size >= 0) __Pyx_RaiseNeedMoreValuesError(size);
      __PYX_ERR(0, 239, __pyx_L1_error)
    }
    #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    if (likely(PyTuple_CheckExact(sequence))) {
      __pyx_t_2 = PyTuple_GET_ITEM(sequence, 0); 
      __pyx_t_1 = PyTuple_GET_ITEM(sequence, 1); 
      __pyx_t_4 = PyTuple_GET_ITEM(sequence, 2); 
      __pyx_t_5 = PyTuple_GET_ITEM(sequence, 3); 
      __pyx_t_6 = PyTuple_GET_ITEM(sequence, 4); 
    } else {
      __pyx_t_2 = PyList_GET_ITEM(sequence, 0); 
      __pyx_t_1 = PyList_GET_ITEM(sequence, 1); 
      __pyx_t_4 = PyList_GET_ITEM(sequence, 2); 
      __pyx_t_5 = PyList_GET_ITEM(sequence, 3); 
      __pyx_t_6 = PyList_GET_ITEM(sequence, 4); 
    }
    __Pyx_INCREF(__pyx_t_2);
    __Pyx_INCREF(__pyx_t_1);
    __Pyx_INCREF(__pyx_t_4);
    __Pyx_INCREF(__pyx_t_5);
    __Pyx_INCREF(__pyx_t_6);
    #else
    {
      Py_ssize_t i;
      PyObject** temps[5] = {&__pyx_t_2,&__pyx_t_1,&__pyx_t_4,&__pyx_t_5,&__pyx_t_6};
      for (i=0; i < 5; i++) {
        PyObject* item = PySequence_ITEM(sequence, i); if (unlikely(!item)) __PYX_ERR(0, 239, __pyx_L1_error)
        __Pyx_GOTREF(item);
        *(temps[i]) = item;
      }
    }
    #endif
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  } else {
    Py_ssize_t index = -1;
    PyObject** temps[5] = {&__pyx_t_2,&__pyx_t_1,&__pyx_t_4,&__pyx_t_5,&__pyx_t_6};
    __pyx_t_7 = PyObject_GetIter(__pyx_t_3); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 239, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_8 = Py_TYPE(__pyx_t_7)->tp_iternext;
    for (index=0; index < 5; index++) {
      PyObject* item = __pyx_t_8(__pyx_t_7); if (unlikely(!item)) goto __pyx_L3_unpacking_failed;
      __Pyx_GOTREF(item);
      *(temps[index]) = item;
    }
    if (__Pyx_IternextUnpackEndCheck(__pyx_t_8(__pyx_t_7), 5) < 0) __PYX_ERR(0, 239, __pyx_L1_error)
    __pyx_t_8 = NULL;
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    goto __pyx_L4_unpacking_done;
    __pyx_L3_unpacking_failed:;
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    __pyx_t_8 = NULL;
    if (__Pyx_IterFinish() == 0) __Pyx_RaiseNeedMoreValuesError(index);
    __PYX_ERR(0, 239, __pyx_L1_error)
    __pyx_L4_unpacking_done:;
  }
  __pyx_v_ids = __pyx_t_2;
  __pyx_t_2 = 0;
  __pyx_v_posts = __pyx_t_1;
  __pyx_t_1 = 0;
  __pyx_v_dates = __pyx_t_4;
  __pyx_t_4 = 0;
  __pyx_v_writers = __pyx_t_5;
  __pyx_t_5 = 0;
  __pyx_v__ = __pyx_t_6;
  __pyx_t_6 = 0;

  /* "KakaoChat/kakao.py":240
 *     """  1  . """
 *     ids, posts, dates, writers, _ = parseNotices(length=1)  # Parse one notice
 *     postDate = dates[0].text(strip=True)             # <<<<<<<<<<<<<<
 *     postTitle = posts[0].text(strip=True)
 *     postId = ids[0].text(strip=True)
 */
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_v_dates, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 240, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_text); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 240, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 240, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_strip, Py_True) < 0) __PYX_ERR(0, 240, __pyx_L1_error)
  __pyx_t_5 = __Pyx_PyObject_Call(__pyx_t_6, __pyx_empty_tuple, __pyx_t_3); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 240, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_v_postDate = __pyx_t_5;
  __pyx_t_5 = 0;

  /* "KakaoChat/kakao.py":241
 *     ids, posts, dates, writers, _ = parseNotices(length=1)  # Parse one notice
 *     postDate = dates[0].text(strip=True)
 *     postTitle = posts[0].text(strip=True)             # <<<<<<<<<<<<<<
 *     postId = ids[0].text(strip=True)
 *     postLink = ADDRESS + posts[0].attributes["href"]
 */
  __pyx_t_5 = __Pyx_GetItemInt(__pyx_v_posts, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 241, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_5, __pyx_n_s_text); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 241, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 241, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (PyDict_SetItem(__pyx_t_5, __pyx_n_s_strip, Py_True) < 0) __PYX_ERR(0, 241, __pyx_L1_error)
  __pyx_t_6 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_empty_tuple, __pyx_t_5); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 241, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_v_postTitle = __pyx_t_6;
  __pyx_t_6 = 0;

  /* "KakaoChat/kakao.py":242
 *     postDate = dates[0].text(strip=True)
 *     postTitle = posts[0].text(strip=True)
 *     postId = ids[0].text(strip=True)             # <<<<<<<<<<<<<<
 *     postLink = ADDRESS + posts[0].attributes["href"]
 *     postWriter = writers[0].text(strip=False)
 */
  __pyx_t_6 = __Pyx_GetItemInt(__pyx_v_ids, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 242, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_6, __pyx_n_s_text); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 242, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_6 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 242, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  if (PyDict_SetItem(__pyx_t_6, __pyx_n_s_strip, Py_True) < 0) __PYX_ERR(0, 242, __pyx_L1_error)
  __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_5, __pyx_empty_tuple, __pyx_t_6); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 242, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_v_postId = __pyx_t_3;
  __pyx_t_3 = 0;

  /* "KakaoChat/kakao.py":243
 *     postTitle = posts[0].text(strip=True)
 *     postId = ids[0].text(strip=True)
 *     postLink = ADDRESS + posts[0].attributes["href"]             # <<<<<<<<<<<<<<
 *     postWriter = writers[0].text(strip=False)
 * 
 */
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_ADDRESS); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 243, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_6 = __Pyx_GetItemInt(__pyx_v_posts, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 243, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_6, __pyx_n_s_attributes); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 243, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_6 = __Pyx_PyObject_Dict_GetItem(__pyx_t_5, __pyx_n_u_href); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 243, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = PyNumber_Add(__pyx_t_3, __pyx_t_6); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 243, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_v_postLink = __pyx_t_5;
  __pyx_t_5 = 0;

  /* "KakaoChat/kakao.py":244
 *     postId = ids[0].text(strip=True)
 *     postLink = ADDRESS + posts[0].attributes["href"]
 *     postWriter = writers[0].text(strip=False)             # <<<<<<<<<<<<<<
 * 
 *     data = makeJSON(postId, postTitle, postDate, postLink, postWriter)
 */
  __pyx_t_5 = __Pyx_GetItemInt(__pyx_v_writers, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 244, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_t_5, __pyx_n_s_text); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 244, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 244, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (PyDict_SetItem(__pyx_t_5, __pyx_n_s_strip, Py_False) < 0) __PYX_ERR(0, 244, __pyx_L1_error)
  __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_6, __pyx_empty_tuple, __pyx_t_5); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 244, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_v_postWriter = __pyx_t_3;
  __pyx_t_3 = 0;

  /* "KakaoChat/kakao.py":246
 *     postWriter = writers[0].text(strip=False)
 * 
 *     data = makeJSON(postId, postTitle, postDate, postLink, postWriter)             # <<<<<<<<<<<<<<
 *     return data, postDate
 * 
 */
  __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_makeJSON); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 246, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_6 = NULL;
  __pyx_t_9 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_5))) {
    __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_5);
    if (likely(__pyx_t_6)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
      __Pyx_INCREF(__pyx_t_6);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_5, function);
      __pyx_t_9 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_5)) {
    PyObject *__pyx_temp[6] = {__pyx_t_6, __pyx_v_postId, __pyx_v_postTitle, __pyx_v_postDate, __pyx_v_postLink, __pyx_v_postWriter};
    __pyx_t_3 = __Pyx_PyFunction_FastCall(__pyx_t_5, __pyx_temp+1-__pyx_t_9, 5+__pyx_t_9); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 246, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_GOTREF(__pyx_t_3);
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_5)) {
    PyObject *__pyx_temp[6] = {__pyx_t_6, __pyx_v_postId, __pyx_v_postTitle, __pyx_v_postDate, __pyx_v_postLink, __pyx_v_postWriter};
    __pyx_t_3 = __Pyx_PyCFunction_FastCall(__pyx_t_5, __pyx_temp+1-__pyx_t_9, 5+__pyx_t_9); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 246, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_GOTREF(__pyx_t_3);
  } else
  #endif
  {
    __pyx_t_4 = PyTuple_New(5+__pyx_t_9); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 246, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    if (__pyx_t_6) {
      __Pyx_GIVEREF(__pyx_t_6); PyTuple_SET_ITEM(__pyx_t_4, 0, __pyx_t_6); __pyx_t_6 = NULL;
    }
    __Pyx_INCREF(__pyx_v_postId);
    __Pyx_GIVEREF(__pyx_v_postId);
    PyTuple_SET_ITEM(__pyx_t_4, 0+__pyx_t_9, __pyx_v_postId);
    __Pyx_INCREF(__pyx_v_postTitle);
    __Pyx_GIVEREF(__pyx_v_postTitle);
    PyTuple_SET_ITEM(__pyx_t_4, 1+__pyx_t_9, __pyx_v_postTitle);
    __Pyx_INCREF(__pyx_v_postDate);
    __Pyx_GIVEREF(__pyx_v_postDate);
    PyTuple_SET_ITEM(__pyx_t_4, 2+__pyx_t_9, __pyx_v_postDate);
    __Pyx_INCREF(__pyx_v_postLink);
    __Pyx_GIVEREF(__pyx_v_postLink);
    PyTuple_SET_ITEM(__pyx_t_4, 3+__pyx_t_9, __pyx_v_postLink);
    __Pyx_INCREF(__pyx_v_postWriter);
    __Pyx_GIVEREF(__pyx_v_postWriter);
    PyTuple_SET_ITEM(__pyx_t_4, 4+__pyx_t_9, __pyx_v_postWriter);
    __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_5, __pyx_t_4, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 246, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  }
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_v_data = __pyx_t_3;
  __pyx_t_3 = 0;

  /* "KakaoChat/kakao.py":247
 * 
 *     data = makeJSON(postId, postTitle, postDate, postLink, postWriter)
 *     return data, postDate             # <<<<<<<<<<<<<<
 * 
 * 
 */
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 247, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_INCREF(__pyx_v_data);
  __Pyx_GIVEREF(__pyx_v_data);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_v_data);
  __Pyx_INCREF(__pyx_v_postDate);
  __Pyx_GIVEREF(__pyx_v_postDate);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_v_postDate);
  __pyx_r = __pyx_t_3;
  __pyx_t_3 = 0;
  goto __pyx_L0;

  /* "KakaoChat/kakao.py":237
 * 
 * 
 * def getLastNotice():             # <<<<<<<<<<<<<<
 *     """  1  . """
 *     ids, posts, dates, writers, _ = parseNotices(length=1)  # Parse one notice
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_AddTraceback("KakaoChat.kakao.getLastNotice", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_ids);
  __Pyx_XDECREF(__pyx_v_posts);
  __Pyx_XDECREF(__pyx_v_dates);
  __Pyx_XDECREF(__pyx_v_writers);
  __Pyx_XDECREF(__pyx_v__);
  __Pyx_XDECREF(__pyx_v_postDate);
  __Pyx_XDECREF(__pyx_v_postTitle);
  __Pyx_XDECREF(__pyx_v_postId);
  __Pyx_XDECREF(__pyx_v_postLink);
  __Pyx_XDECREF(__pyx_v_postWriter);
  __Pyx_XDECREF(__pyx_v_data);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "KakaoChat/kakao.py":250
 * 
 * 
 * def switch(db, when, now, user_id):             # <<<<<<<<<<<<<<
 *     """ /    switch """
 *     DAY = "" if when == "today" else ""
 */

/* Python wrapper */
static PyObject *__pyx_pw_9KakaoChat_5kakao_30switch(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_9KakaoChat_5kakao_29switch[] = " \354\230\244\353\212\230/\354\226\264\354\240\234 \352\263\265\354\247\200\354\227\220 \353\224\260\353\245\270 \354\230\265\354\205\230 switch ";
static PyMethodDef __pyx_mdef_9KakaoChat_5kakao_30switch = {"switch", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_9KakaoChat_5kakao_30switch, METH_VARARGS|METH_KEYWORDS, __pyx_doc_9KakaoChat_5kakao_29switch};
static PyObject *__pyx_pw_9KakaoChat_5kakao_30switch(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_db = 0;
  PyObject *__pyx_v_when = 0;
  PyObject *__pyx_v_now = 0;
  PyObject *__pyx_v_user_id = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("switch (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_db,&__pyx_n_s_when,&__pyx_n_s_now,&__pyx_n_s_user_id,0};
    PyObject* values[4] = {0,0,0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  4: values[3] = PyTuple_GET_ITEM(__pyx_args, 3);
        CYTHON_FALLTHROUGH;
        case  3: values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
        CYTHON_FALLTHROUGH;
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_db)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_when)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("switch", 1, 4, 4, 1); __PYX_ERR(0, 250, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (likely((values[2] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_now)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("switch", 1, 4, 4, 2); __PYX_ERR(0, 250, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  3:
        if (likely((values[3] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_user_id)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("switch", 1, 4, 4, 3); __PYX_ERR(0, 250, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "switch") < 0)) __PYX_ERR(0, 250, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 4) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
      values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
      values[3] = PyTuple_GET_ITEM(__pyx_args, 3);
    }
    __pyx_v_db = values[0];
    __pyx_v_when = values[1];
    __pyx_v_now = values[2];
    __pyx_v_user_id = values[3];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("switch", 1, 4, 4, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 250, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("KakaoChat.kakao.switch", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_9KakaoChat_5kakao_29switch(__pyx_self, __pyx_v_db, __pyx_v_when, __pyx_v_now, __pyx_v_user_id);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_9KakaoChat_5kakao_29switch(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_db, PyObject *__pyx_v_when, PyObject *__pyx_v_now, PyObject *__pyx_v_user_id) {
  PyObject *__pyx_v_DAY = NULL;
  PyObject *__pyx_v_notices = NULL;
  PyObject *__pyx_v_data = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  int __pyx_t_2;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  int __pyx_t_6;
  PyObject *__pyx_t_7 = NULL;
  int __pyx_t_8;
  PyObject *__pyx_t_9 = NULL;
  Py_ssize_t __pyx_t_10;
  Py_UCS4 __pyx_t_11;
  PyObject *__pyx_t_12 = NULL;
  Py_ssize_t __pyx_t_13;
  PyObject *__pyx_t_14 = NULL;
  PyObject *__pyx_t_15 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("switch", 0);

  /* "KakaoChat/kakao.py":252
 * def switch(db, when, now, user_id):
 *     """ /    switch """
 *     DAY = "" if when == "today" else ""             # <<<<<<<<<<<<<<
 *     notices = (
 *         getTodayNotices(db, now, user_id)
 */
  __pyx_t_2 = (__Pyx_PyUnicode_Equals(__pyx_v_when, __pyx_n_u_today, Py_EQ)); if (unlikely(__pyx_t_2 < 0)) __PYX_ERR(0, 252, __pyx_L1_error)
  if (__pyx_t_2) {
    __Pyx_INCREF(__pyx_n_u__13);
    __pyx_t_1 = __pyx_n_u__13;
  } else {
    __Pyx_INCREF(__pyx_n_u__14);
    __pyx_t_1 = __pyx_n_u__14;
  }
  __pyx_v_DAY = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":255
 *     notices = (
 *         getTodayNotices(db, now, user_id)
 *         if DAY == ""             # <<<<<<<<<<<<<<
 *         else getYesterdayNotices(db, now)
 *     )
 */
  __pyx_t_2 = (__Pyx_PyUnicode_Equals(__pyx_v_DAY, __pyx_n_u__13, Py_EQ)); if (unlikely(__pyx_t_2 < 0)) __PYX_ERR(0, 255, __pyx_L1_error)
  if ((__pyx_t_2 != 0)) {

    /* "KakaoChat/kakao.py":254
 *     DAY = "" if when == "today" else ""
 *     notices = (
 *         getTodayNotices(db, now, user_id)             # <<<<<<<<<<<<<<
 *         if DAY == ""
 *         else getYesterdayNotices(db, now)
 */
    __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_getTodayNotices); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 254, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_5 = NULL;
    __pyx_t_6 = 0;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_4))) {
      __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_4);
      if (likely(__pyx_t_5)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
        __Pyx_INCREF(__pyx_t_5);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_4, function);
        __pyx_t_6 = 1;
      }
    }
    #if CYTHON_FAST_PYCALL
    if (PyFunction_Check(__pyx_t_4)) {
      PyObject *__pyx_temp[4] = {__pyx_t_5, __pyx_v_db, __pyx_v_now, __pyx_v_user_id};
      __pyx_t_3 = __Pyx_PyFunction_FastCall(__pyx_t_4, __pyx_temp+1-__pyx_t_6, 3+__pyx_t_6); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 254, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
      __Pyx_GOTREF(__pyx_t_3);
    } else
    #endif
    #if CYTHON_FAST_PYCCALL
    if (__Pyx_PyFastCFunction_Check(__pyx_t_4)) {
      PyObject *__pyx_temp[4] = {__pyx_t_5, __pyx_v_db, __pyx_v_now, __pyx_v_user_id};
      __pyx_t_3 = __Pyx_PyCFunction_FastCall(__pyx_t_4, __pyx_temp+1-__pyx_t_6, 3+__pyx_t_6); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 254, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
      __Pyx_GOTREF(__pyx_t_3);
    } else
    #endif
    {
      __pyx_t_7 = PyTuple_New(3+__pyx_t_6); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 254, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      if (__pyx_t_5) {
        __Pyx_GIVEREF(__pyx_t_5); PyTuple_SET_ITEM(__pyx_t_7, 0, __pyx_t_5); __pyx_t_5 = NULL;
      }
      __Pyx_INCREF(__pyx_v_db);
      __Pyx_GIVEREF(__pyx_v_db);
      PyTuple_SET_ITEM(__pyx_t_7, 0+__pyx_t_6, __pyx_v_db);
      __Pyx_INCREF(__pyx_v_now);
      __Pyx_GIVEREF(__pyx_v_now);
      PyTuple_SET_ITEM(__pyx_t_7, 1+__pyx_t_6, __pyx_v_now);
      __Pyx_INCREF(__pyx_v_user_id);
      __Pyx_GIVEREF(__pyx_v_user_id);
      PyTuple_SET_ITEM(__pyx_t_7, 2+__pyx_t_6, __pyx_v_user_id);
      __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_4, __pyx_t_7, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 254, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    }
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_1 = __pyx_t_3;
    __pyx_t_3 = 0;
  } else {

    /* "KakaoChat/kakao.py":256
 *         getTodayNotices(db, now, user_id)
 *         if DAY == ""
 *         else getYesterdayNotices(db, now)             # <<<<<<<<<<<<<<
 *     )
 *     if not notices:
 */
    __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_getYesterdayNotices); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 256, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_7 = NULL;
    __pyx_t_6 = 0;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_4))) {
      __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_4);
      if (likely(__pyx_t_7)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
        __Pyx_INCREF(__pyx_t_7);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_4, function);
        __pyx_t_6 = 1;
      }
    }
    #if CYTHON_FAST_PYCALL
    if (PyFunction_Check(__pyx_t_4)) {
      PyObject *__pyx_temp[3] = {__pyx_t_7, __pyx_v_db, __pyx_v_now};
      __pyx_t_3 = __Pyx_PyFunction_FastCall(__pyx_t_4, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 256, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
      __Pyx_GOTREF(__pyx_t_3);
    } else
    #endif
    #if CYTHON_FAST_PYCCALL
    if (__Pyx_PyFastCFunction_Check(__pyx_t_4)) {
      PyObject *__pyx_temp[3] = {__pyx_t_7, __pyx_v_db, __pyx_v_now};
      __pyx_t_3 = __Pyx_PyCFunction_FastCall(__pyx_t_4, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 256, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
      __Pyx_GOTREF(__pyx_t_3);
    } else
    #endif
    {
      __pyx_t_5 = PyTuple_New(2+__pyx_t_6); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 256, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_5);
      if (__pyx_t_7) {
        __Pyx_GIVEREF(__pyx_t_7); PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_7); __pyx_t_7 = NULL;
      }
      __Pyx_INCREF(__pyx_v_db);
      __Pyx_GIVEREF(__pyx_v_db);
      PyTuple_SET_ITEM(__pyx_t_5, 0+__pyx_t_6, __pyx_v_db);
      __Pyx_INCREF(__pyx_v_now);
      __Pyx_GIVEREF(__pyx_v_now);
      PyTuple_SET_ITEM(__pyx_t_5, 1+__pyx_t_6, __pyx_v_now);
      __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_4, __pyx_t_5, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 256, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    }
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_1 = __pyx_t_3;
    __pyx_t_3 = 0;
  }
  __pyx_v_notices = __pyx_t_1;
  __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":258
 *         else getYesterdayNotices(db, now)
 *     )
 *     if not notices:             # <<<<<<<<<<<<<<
 *         notices = [
 *             {
 */
  __pyx_t_2 = __Pyx_PyObject_IsTrue(__pyx_v_notices); if (unlikely(__pyx_t_2 < 0)) __PYX_ERR(0, 258, __pyx_L1_error)
  __pyx_t_8 = ((!__pyx_t_2) != 0);
  if (__pyx_t_8) {

    /* "KakaoChat/kakao.py":261
 *         notices = [
 *             {
 *                 "title": " !",             # <<<<<<<<<<<<<<
 *                 "imageUrl": "http://k.kakaocdn.net/dn/APR96/btqqH7zLanY/kD5mIPX7TdD2NAxgP29cC0/1x1.jpg",
 *             }
 */
    __pyx_t_1 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 261, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    if (PyDict_SetItem(__pyx_t_1, __pyx_n_u_title, __pyx_kp_u__15) < 0) __PYX_ERR(0, 261, __pyx_L1_error)
    if (PyDict_SetItem(__pyx_t_1, __pyx_n_u_imageUrl, __pyx_kp_u_http_k_kakaocdn_net_dn_APR96_btq) < 0) __PYX_ERR(0, 261, __pyx_L1_error)

    /* "KakaoChat/kakao.py":259
 *     )
 *     if not notices:
 *         notices = [             # <<<<<<<<<<<<<<
 *             {
 *                 "title": " !",
 */
    __pyx_t_3 = PyList_New(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 259, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_GIVEREF(__pyx_t_1);
    PyList_SET_ITEM(__pyx_t_3, 0, __pyx_t_1);
    __pyx_t_1 = 0;
    __Pyx_DECREF_SET(__pyx_v_notices, __pyx_t_3);
    __pyx_t_3 = 0;

    /* "KakaoChat/kakao.py":258
 *         else getYesterdayNotices(db, now)
 *     )
 *     if not notices:             # <<<<<<<<<<<<<<
 *         notices = [
 *             {
 */
  }

  /* "KakaoChat/kakao.py":267
 * 
 *     data = {
 *         "version": "2.0",             # <<<<<<<<<<<<<<
 *         "template": {
 *             "outputs": [
 */
  __pyx_t_3 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 267, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_version, __pyx_kp_u_2_0) < 0) __PYX_ERR(0, 267, __pyx_L1_error)

  /* "KakaoChat/kakao.py":269
 *         "version": "2.0",
 *         "template": {
 *             "outputs": [             # <<<<<<<<<<<<<<
 *                 {
 *                     "listCard": {
 */
  __pyx_t_1 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 269, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);

  /* "KakaoChat/kakao.py":271
 *             "outputs": [
 *                 {
 *                     "listCard": {             # <<<<<<<<<<<<<<
 *                         "header": {"title": f"{now}) {DAY} "},
 *                         "items": notices[:5],
 */
  __pyx_t_4 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 271, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);

  /* "KakaoChat/kakao.py":272
 *                 {
 *                     "listCard": {
 *                         "header": {"title": f"{now}) {DAY} "},             # <<<<<<<<<<<<<<
 *                         "items": notices[:5],
 *                         "buttons": [
 */
  __pyx_t_5 = __Pyx_PyDict_NewPresized(3); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 272, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_7 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 272, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __pyx_t_9 = PyTuple_New(4); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 272, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_9);
  __pyx_t_10 = 0;
  __pyx_t_11 = 127;
  __pyx_t_12 = __Pyx_PyObject_FormatSimple(__pyx_v_now, __pyx_empty_unicode); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 272, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_12);
  __pyx_t_11 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_12) > __pyx_t_11) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_12) : __pyx_t_11;
  __pyx_t_10 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_12);
  __Pyx_GIVEREF(__pyx_t_12);
  PyTuple_SET_ITEM(__pyx_t_9, 0, __pyx_t_12);
  __pyx_t_12 = 0;
  __Pyx_INCREF(__pyx_kp_u__16);
  __pyx_t_10 += 2;
  __Pyx_GIVEREF(__pyx_kp_u__16);
  PyTuple_SET_ITEM(__pyx_t_9, 1, __pyx_kp_u__16);
  __pyx_t_12 = __Pyx_PyUnicode_Unicode(__pyx_v_DAY); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 272, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_12);
  __pyx_t_11 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_12) > __pyx_t_11) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_12) : __pyx_t_11;
  __pyx_t_10 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_12);
  __Pyx_GIVEREF(__pyx_t_12);
  PyTuple_SET_ITEM(__pyx_t_9, 2, __pyx_t_12);
  __pyx_t_12 = 0;
  __Pyx_INCREF(__pyx_kp_u__17);
  __pyx_t_11 = (65535 > __pyx_t_11) ? 65535 : __pyx_t_11;
  __pyx_t_10 += 3;
  __Pyx_GIVEREF(__pyx_kp_u__17);
  PyTuple_SET_ITEM(__pyx_t_9, 3, __pyx_kp_u__17);
  __pyx_t_12 = __Pyx_PyUnicode_Join(__pyx_t_9, 4, __pyx_t_10, __pyx_t_11); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 272, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_12);
  __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  if (PyDict_SetItem(__pyx_t_7, __pyx_n_u_title, __pyx_t_12) < 0) __PYX_ERR(0, 272, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
  if (PyDict_SetItem(__pyx_t_5, __pyx_n_u_header, __pyx_t_7) < 0) __PYX_ERR(0, 272, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;

  /* "KakaoChat/kakao.py":273
 *                     "listCard": {
 *                         "header": {"title": f"{now}) {DAY} "},
 *                         "items": notices[:5],             # <<<<<<<<<<<<<<
 *                         "buttons": [
 *                             {"label": "", "action": "share"},
 */
  __pyx_t_7 = __Pyx_PyObject_GetSlice(__pyx_v_notices, 0, 5, NULL, NULL, &__pyx_slice__18, 0, 1, 1); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 273, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  if (PyDict_SetItem(__pyx_t_5, __pyx_n_u_items, __pyx_t_7) < 0) __PYX_ERR(0, 272, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;

  /* "KakaoChat/kakao.py":275
 *                         "items": notices[:5],
 *                         "buttons": [
 *                             {"label": "", "action": "share"},             # <<<<<<<<<<<<<<
 *                             {
 *                                 "label": f"{len(notices) - 5} "
 */
  __pyx_t_7 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 275, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  if (PyDict_SetItem(__pyx_t_7, __pyx_n_u_label, __pyx_n_u__19) < 0) __PYX_ERR(0, 275, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_7, __pyx_n_u_action, __pyx_n_u_share) < 0) __PYX_ERR(0, 275, __pyx_L1_error)

  /* "KakaoChat/kakao.py":277
 *                             {"label": "", "action": "share"},
 *                             {
 *                                 "label": f"{len(notices) - 5} "             # <<<<<<<<<<<<<<
 *                                 if len(notices) > 5
 *                                 else " ",
 */
  __pyx_t_12 = __Pyx_PyDict_NewPresized(3); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 277, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_12);

  /* "KakaoChat/kakao.py":278
 *                             {
 *                                 "label": f"{len(notices) - 5} "
 *                                 if len(notices) > 5             # <<<<<<<<<<<<<<
 *                                 else " ",
 *                                 "action": "webLink",
 */
  __pyx_t_10 = PyObject_Length(__pyx_v_notices); if (unlikely(__pyx_t_10 == ((Py_ssize_t)-1))) __PYX_ERR(0, 278, __pyx_L1_error)
  if (((__pyx_t_10 > 5) != 0)) {

    /* "KakaoChat/kakao.py":277
 *                             {"label": "", "action": "share"},
 *                             {
 *                                 "label": f"{len(notices) - 5} "             # <<<<<<<<<<<<<<
 *                                 if len(notices) > 5
 *                                 else " ",
 */
    __pyx_t_13 = PyObject_Length(__pyx_v_notices); if (unlikely(__pyx_t_13 == ((Py_ssize_t)-1))) __PYX_ERR(0, 277, __pyx_L1_error)
    __pyx_t_14 = __Pyx_PyUnicode_From_Py_ssize_t((__pyx_t_13 - 5), 0, ' ', 'd'); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 277, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_14);
    __pyx_t_15 = __Pyx_PyUnicode_Concat(__pyx_t_14, __pyx_kp_u__20); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 277, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_15);
    __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
    __pyx_t_9 = __pyx_t_15;
    __pyx_t_15 = 0;
  } else {
    __Pyx_INCREF(__pyx_kp_u__21);
    __pyx_t_9 = __pyx_kp_u__21;
  }
  if (PyDict_SetItem(__pyx_t_12, __pyx_n_u_label, __pyx_t_9) < 0) __PYX_ERR(0, 277, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  if (PyDict_SetItem(__pyx_t_12, __pyx_n_u_action, __pyx_n_u_webLink) < 0) __PYX_ERR(0, 277, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_12, __pyx_n_u_webLinkUrl, __pyx_kp_u_https_www_ajou_ac_kr_kr_ajou_not) < 0) __PYX_ERR(0, 277, __pyx_L1_error)

  /* "KakaoChat/kakao.py":274
 *                         "header": {"title": f"{now}) {DAY} "},
 *                         "items": notices[:5],
 *                         "buttons": [             # <<<<<<<<<<<<<<
 *                             {"label": "", "action": "share"},
 *                             {
 */
  __pyx_t_9 = PyList_New(2); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 274, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_9);
  __Pyx_GIVEREF(__pyx_t_7);
  PyList_SET_ITEM(__pyx_t_9, 0, __pyx_t_7);
  __Pyx_GIVEREF(__pyx_t_12);
  PyList_SET_ITEM(__pyx_t_9, 1, __pyx_t_12);
  __pyx_t_7 = 0;
  __pyx_t_12 = 0;
  if (PyDict_SetItem(__pyx_t_5, __pyx_n_u_buttons, __pyx_t_9) < 0) __PYX_ERR(0, 272, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  if (PyDict_SetItem(__pyx_t_4, __pyx_n_u_listCard, __pyx_t_5) < 0) __PYX_ERR(0, 271, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  /* "KakaoChat/kakao.py":269
 *         "version": "2.0",
 *         "template": {
 *             "outputs": [             # <<<<<<<<<<<<<<
 *                 {
 *                     "listCard": {
 */
  __pyx_t_5 = PyList_New(1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 269, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_GIVEREF(__pyx_t_4);
  PyList_SET_ITEM(__pyx_t_5, 0, __pyx_t_4);
  __pyx_t_4 = 0;
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u_outputs, __pyx_t_5) < 0) __PYX_ERR(0, 269, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  /* "KakaoChat/kakao.py":288
 *             ],
 *             "quickReplies": [
 *                 {"messageText": "  ", "action": "message", "label": ""},             # <<<<<<<<<<<<<<
 *                 {"messageText": "  ", "action": "message", "label": ""},
 *             ],
 */
  __pyx_t_5 = __Pyx_PyDict_NewPresized(3); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 288, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (PyDict_SetItem(__pyx_t_5, __pyx_n_u_messageText, __pyx_kp_u__22) < 0) __PYX_ERR(0, 288, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_5, __pyx_n_u_action, __pyx_n_u_message) < 0) __PYX_ERR(0, 288, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_5, __pyx_n_u_label, __pyx_n_u__23) < 0) __PYX_ERR(0, 288, __pyx_L1_error)

  /* "KakaoChat/kakao.py":289
 *             "quickReplies": [
 *                 {"messageText": "  ", "action": "message", "label": ""},
 *                 {"messageText": "  ", "action": "message", "label": ""},             # <<<<<<<<<<<<<<
 *             ],
 *         },
 */
  __pyx_t_4 = __Pyx_PyDict_NewPresized(3); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 289, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_t_4, __pyx_n_u_messageText, __pyx_kp_u__24) < 0) __PYX_ERR(0, 289, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_4, __pyx_n_u_action, __pyx_n_u_message) < 0) __PYX_ERR(0, 289, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_4, __pyx_n_u_label, __pyx_n_u__13) < 0) __PYX_ERR(0, 289, __pyx_L1_error)

  /* "KakaoChat/kakao.py":287
 *                 }
 *             ],
 *             "quickReplies": [             # <<<<<<<<<<<<<<
 *                 {"messageText": "  ", "action": "message", "label": ""},
 *                 {"messageText": "  ", "action": "message", "label": ""},
 */
  __pyx_t_9 = PyList_New(2); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 287, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_9);
  __Pyx_GIVEREF(__pyx_t_5);
  PyList_SET_ITEM(__pyx_t_9, 0, __pyx_t_5);
  __Pyx_GIVEREF(__pyx_t_4);
  PyList_SET_ITEM(__pyx_t_9, 1, __pyx_t_4);
  __pyx_t_5 = 0;
  __pyx_t_4 = 0;
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u_quickReplies, __pyx_t_9) < 0) __PYX_ERR(0, 269, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_template, __pyx_t_1) < 0) __PYX_ERR(0, 267, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_v_data = ((PyObject*)__pyx_t_3);
  __pyx_t_3 = 0;

  /* "KakaoChat/kakao.py":293
 *         },
 *     }
 *     return data             # <<<<<<<<<<<<<<
 * 
 * 
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_data);
  __pyx_r = __pyx_v_data;
  goto __pyx_L0;

  /* "KakaoChat/kakao.py":250
 * 
 * 
 * def switch(db, when, now, user_id):             # <<<<<<<<<<<<<<
 *     """ /    switch """
 *     DAY = "" if when == "today" else ""
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_9);
  __Pyx_XDECREF(__pyx_t_12);
  __Pyx_XDECREF(__pyx_t_14);
  __Pyx_XDECREF(__pyx_t_15);
  __Pyx_AddTraceback("KakaoChat.kakao.switch", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_DAY);
  __Pyx_XDECREF(__pyx_v_notices);
  __Pyx_XDECREF(__pyx_v_data);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "KakaoChat/kakao.py":297
 * 
 * @application.get("/")
 * def hello():             # <<<<<<<<<<<<<<
 *     return "Welcome, the server is running well."
 * 
 */

/* Python wrapper */
static PyObject *__pyx_pw_9KakaoChat_5kakao_32hello(PyObject *__pyx_self, CYTHON_UNUSED PyObject *unused); /*proto*/
static PyMethodDef __pyx_mdef_9KakaoChat_5kakao_32hello = {"hello", (PyCFunction)__pyx_pw_9KakaoChat_5kakao_32hello, METH_NOARGS, 0};
static PyObject *__pyx_pw_9KakaoChat_5kakao_32hello(PyObject *__pyx_self, CYTHON_UNUSED PyObject *unused) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("hello (wrapper)", 0);
  __pyx_r = __pyx_pf_9KakaoChat_5kakao_31hello(__pyx_self);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_9KakaoChat_5kakao_31hello(CYTHON_UNUSED PyObject *__pyx_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("hello", 0);

  /* "KakaoChat/kakao.py":298
 * @application.get("/")
 * def hello():
 *     return "Welcome, the server is running well."             # <<<<<<<<<<<<<<
 * 
 * 
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_kp_u_Welcome_the_server_is_running_we);
  __pyx_r = __pyx_kp_u_Welcome_the_server_is_running_we;
  goto __pyx_L0;

  /* "KakaoChat/kakao.py":297
 * 
 * @application.get("/")
 * def hello():             # <<<<<<<<<<<<<<
 *     return "Welcome, the server is running well."
 * 
 */

  /* function exit code */
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "KakaoChat/kakao.py":302
 * 
 * @application.post("/ask")
 * def askKeyword(_: Dict):             # <<<<<<<<<<<<<<
 *     """    """
 *     # user_id = content["userRequest"]["user"]["id"]  # user Id
 */

/* Python wrapper */
static PyObject *__pyx_pw_9KakaoChat_5kakao_34askKeyword(PyObject *__pyx_self, PyObject *__pyx_v__); /*proto*/
static char __pyx_doc_9KakaoChat_5kakao_33askKeyword[] = "\354\233\220\355\225\230\353\212\224 \352\263\265\354\247\200 \353\266\204\353\245\230\353\245\274 \354\204\240\355\203\235\355\225\230\353\217\204\353\241\235 \354\234\240\353\217\204";
static PyMethodDef __pyx_mdef_9KakaoChat_5kakao_34askKeyword = {"askKeyword", (PyCFunction)__pyx_pw_9KakaoChat_5kakao_34askKeyword, METH_O, __pyx_doc_9KakaoChat_5kakao_33askKeyword};
static PyObject *__pyx_pw_9KakaoChat_5kakao_34askKeyword(PyObject *__pyx_self, PyObject *__pyx_v__) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("askKeyword (wrapper)", 0);
  __pyx_r = __pyx_pf_9KakaoChat_5kakao_33askKeyword(__pyx_self, ((PyObject *)__pyx_v__));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_9KakaoChat_5kakao_33askKeyword(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v__) {
  PyObject *__pyx_v_categories = NULL;
  PyObject *__pyx_v_replies = NULL;
  PyObject *__pyx_v_data = NULL;
  PyObject *__pyx_7genexpr__pyx_v_category = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  Py_ssize_t __pyx_t_3;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("askKeyword", 0);

  /* "KakaoChat/kakao.py":306
 *     # user_id = content["userRequest"]["user"]["id"]  # user Id
 *     # checkUserDB(user_id)
 *     print(">>> /ask")             # <<<<<<<<<<<<<<
 * 
 *     categories = [
 */
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__25, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 306, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":308
 *     print(">>> /ask")
 * 
 *     categories = [             # <<<<<<<<<<<<<<
 *         "",
 *         "",
 */
  __pyx_t_1 = PyList_New(11); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 308, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_u__26);
  __Pyx_GIVEREF(__pyx_n_u__26);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_n_u__26);
  __Pyx_INCREF(__pyx_n_u__27);
  __Pyx_GIVEREF(__pyx_n_u__27);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_n_u__27);
  __Pyx_INCREF(__pyx_n_u__28);
  __Pyx_GIVEREF(__pyx_n_u__28);
  PyList_SET_ITEM(__pyx_t_1, 2, __pyx_n_u__28);
  __Pyx_INCREF(__pyx_n_u__29);
  __Pyx_GIVEREF(__pyx_n_u__29);
  PyList_SET_ITEM(__pyx_t_1, 3, __pyx_n_u__29);
  __Pyx_INCREF(__pyx_n_u__30);
  __Pyx_GIVEREF(__pyx_n_u__30);
  PyList_SET_ITEM(__pyx_t_1, 4, __pyx_n_u__30);
  __Pyx_INCREF(__pyx_n_u__31);
  __Pyx_GIVEREF(__pyx_n_u__31);
  PyList_SET_ITEM(__pyx_t_1, 5, __pyx_n_u__31);
  __Pyx_INCREF(__pyx_n_u__32);
  __Pyx_GIVEREF(__pyx_n_u__32);
  PyList_SET_ITEM(__pyx_t_1, 6, __pyx_n_u__32);
  __Pyx_INCREF(__pyx_n_u__33);
  __Pyx_GIVEREF(__pyx_n_u__33);
  PyList_SET_ITEM(__pyx_t_1, 7, __pyx_n_u__33);
  __Pyx_INCREF(__pyx_n_u__34);
  __Pyx_GIVEREF(__pyx_n_u__34);
  PyList_SET_ITEM(__pyx_t_1, 8, __pyx_n_u__34);
  __Pyx_INCREF(__pyx_n_u__35);
  __Pyx_GIVEREF(__pyx_n_u__35);
  PyList_SET_ITEM(__pyx_t_1, 9, __pyx_n_u__35);
  __Pyx_INCREF(__pyx_n_u__36);
  __Pyx_GIVEREF(__pyx_n_u__36);
  PyList_SET_ITEM(__pyx_t_1, 10, __pyx_n_u__36);
  __pyx_v_categories = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":321
 *         "",
 *     ]
 *     replies = [             # <<<<<<<<<<<<<<
 *         {"messageText": category, "action": "message", "label": category}
 *         for category in categories
 */
  { /* enter inner scope */
    __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 321, __pyx_L5_error)
    __Pyx_GOTREF(__pyx_t_1);

    /* "KakaoChat/kakao.py":323
 *     replies = [
 *         {"messageText": category, "action": "message", "label": category}
 *         for category in categories             # <<<<<<<<<<<<<<
 *     ]
 * 
 */
    __pyx_t_2 = __pyx_v_categories; __Pyx_INCREF(__pyx_t_2); __pyx_t_3 = 0;
    for (;;) {
      if (__pyx_t_3 >= PyList_GET_SIZE(__pyx_t_2)) break;
      #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
      __pyx_t_4 = PyList_GET_ITEM(__pyx_t_2, __pyx_t_3); __Pyx_INCREF(__pyx_t_4); __pyx_t_3++; if (unlikely(0 < 0)) __PYX_ERR(0, 323, __pyx_L5_error)
      #else
      __pyx_t_4 = PySequence_ITEM(__pyx_t_2, __pyx_t_3); __pyx_t_3++; if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 323, __pyx_L5_error)
      __Pyx_GOTREF(__pyx_t_4);
      #endif
      __Pyx_XDECREF_SET(__pyx_7genexpr__pyx_v_category, __pyx_t_4);
      __pyx_t_4 = 0;

      /* "KakaoChat/kakao.py":322
 *     ]
 *     replies = [
 *         {"messageText": category, "action": "message", "label": category}             # <<<<<<<<<<<<<<
 *         for category in categories
 *     ]
 */
      __pyx_t_4 = __Pyx_PyDict_NewPresized(3); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 322, __pyx_L5_error)
      __Pyx_GOTREF(__pyx_t_4);
      if (PyDict_SetItem(__pyx_t_4, __pyx_n_u_messageText, __pyx_7genexpr__pyx_v_category) < 0) __PYX_ERR(0, 322, __pyx_L5_error)
      if (PyDict_SetItem(__pyx_t_4, __pyx_n_u_action, __pyx_n_u_message) < 0) __PYX_ERR(0, 322, __pyx_L5_error)
      if (PyDict_SetItem(__pyx_t_4, __pyx_n_u_label, __pyx_7genexpr__pyx_v_category) < 0) __PYX_ERR(0, 322, __pyx_L5_error)
      if (unlikely(__Pyx_ListComp_Append(__pyx_t_1, (PyObject*)__pyx_t_4))) __PYX_ERR(0, 321, __pyx_L5_error)
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

      /* "KakaoChat/kakao.py":323
 *     replies = [
 *         {"messageText": category, "action": "message", "label": category}
 *         for category in categories             # <<<<<<<<<<<<<<
 *     ]
 * 
 */
    }
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_XDECREF(__pyx_7genexpr__pyx_v_category); __pyx_7genexpr__pyx_v_category = 0;
    goto __pyx_L8_exit_scope;
    __pyx_L5_error:;
    __Pyx_XDECREF(__pyx_7genexpr__pyx_v_category); __pyx_7genexpr__pyx_v_category = 0;
    goto __pyx_L1_error;
    __pyx_L8_exit_scope:;
  } /* exit inner scope */
  __pyx_v_replies = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":327
 * 
 *     data = {
 *         "version": "2.0",             # <<<<<<<<<<<<<<
 *         "template": {
 *             "outputs": [{"simpleText": {"text": "   ?"}}],
 */
  __pyx_t_1 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 327, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u_version, __pyx_kp_u_2_0) < 0) __PYX_ERR(0, 327, __pyx_L1_error)

  /* "KakaoChat/kakao.py":329
 *         "version": "2.0",
 *         "template": {
 *             "outputs": [{"simpleText": {"text": "   ?"}}],             # <<<<<<<<<<<<<<
 *             "quickReplies": replies,
 *         },
 */
  __pyx_t_2 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 329, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_4 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 329, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_5 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 329, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (PyDict_SetItem(__pyx_t_5, __pyx_n_u_text, __pyx_kp_u__37) < 0) __PYX_ERR(0, 329, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_4, __pyx_n_u_simpleText, __pyx_t_5) < 0) __PYX_ERR(0, 329, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = PyList_New(1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 329, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_GIVEREF(__pyx_t_4);
  PyList_SET_ITEM(__pyx_t_5, 0, __pyx_t_4);
  __pyx_t_4 = 0;
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_u_outputs, __pyx_t_5) < 0) __PYX_ERR(0, 329, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  /* "KakaoChat/kakao.py":330
 *         "template": {
 *             "outputs": [{"simpleText": {"text": "   ?"}}],
 *             "quickReplies": replies,             # <<<<<<<<<<<<<<
 *         },
 *     }
 */
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_u_quickReplies, __pyx_v_replies) < 0) __PYX_ERR(0, 329, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u_template, __pyx_t_2) < 0) __PYX_ERR(0, 327, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_data = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":334
 *     }
 * 
 *     return JSONResponse(content=data)             # <<<<<<<<<<<<<<
 * 
 * 
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_JSONResponse); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 334, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 334, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_content, __pyx_v_data) < 0) __PYX_ERR(0, 334, __pyx_L1_error)
  __pyx_t_5 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_empty_tuple, __pyx_t_2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 334, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_r = __pyx_t_5;
  __pyx_t_5 = 0;
  goto __pyx_L0;

  /* "KakaoChat/kakao.py":302
 * 
 * @application.post("/ask")
 * def askKeyword(_: Dict):             # <<<<<<<<<<<<<<
 *     """    """
 *     # user_id = content["userRequest"]["user"]["id"]  # user Id
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_AddTraceback("KakaoChat.kakao.askKeyword", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_categories);
  __Pyx_XDECREF(__pyx_v_replies);
  __Pyx_XDECREF(__pyx_v_data);
  __Pyx_XDECREF(__pyx_7genexpr__pyx_v_category);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "KakaoChat/kakao.py":338
 * 
 * @application.post("/date")
 * def searchDate(content: Dict):             # <<<<<<<<<<<<<<
 *     """WIP"""
 *     print(">>> /date")
 */

/* Python wrapper */
static PyObject *__pyx_pw_9KakaoChat_5kakao_36searchDate(PyObject *__pyx_self, PyObject *__pyx_v_content); /*proto*/
static char __pyx_doc_9KakaoChat_5kakao_35searchDate[] = "WIP";
static PyMethodDef __pyx_mdef_9KakaoChat_5kakao_36searchDate = {"searchDate", (PyCFunction)__pyx_pw_9KakaoChat_5kakao_36searchDate, METH_O, __pyx_doc_9KakaoChat_5kakao_35searchDate};
static PyObject *__pyx_pw_9KakaoChat_5kakao_36searchDate(PyObject *__pyx_self, PyObject *__pyx_v_content) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("searchDate (wrapper)", 0);
  __pyx_r = __pyx_pf_9KakaoChat_5kakao_35searchDate(__pyx_self, ((PyObject *)__pyx_v_content));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_9KakaoChat_5kakao_35searchDate(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_content) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("searchDate", 0);

  /* "KakaoChat/kakao.py":340
 * def searchDate(content: Dict):
 *     """WIP"""
 *     print(">>> /date")             # <<<<<<<<<<<<<<
 *     # print(content["action"]["params"]["date"])
 *     return JSONResponse(content={})
 */
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__38, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 340, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":342
 *     print(">>> /date")
 *     # print(content["action"]["params"]["date"])
 *     return JSONResponse(content={})             # <<<<<<<<<<<<<<
 * 
 * 
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_JSONResponse); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 342, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 342, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyDict_NewPresized(0); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 342, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_content, __pyx_t_3) < 0) __PYX_ERR(0, 342, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_empty_tuple, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 342, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_r = __pyx_t_3;
  __pyx_t_3 = 0;
  goto __pyx_L0;

  /* "KakaoChat/kakao.py":338
 * 
 * @application.post("/date")
 * def searchDate(content: Dict):             # <<<<<<<<<<<<<<
 *     """WIP"""
 *     print(">>> /date")
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("KakaoChat.kakao.searchDate", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "KakaoChat/kakao.py":346
 * 
 * @application.post("/ask/filter")
 * def searchKeyword(content: Dict, db: Session = Depends(get_db)):             # <<<<<<<<<<<<<<
 *     """   .  type: ListCard"""
 *     user_id = content["userRequest"]["user"]["id"]  # user Id
 */

static PyObject *__pyx_pf_9KakaoChat_5kakao_47__defaults__(CYTHON_UNUSED PyObject *__pyx_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__defaults__", 0);
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = PyTuple_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 346, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__Pyx_CyFunction_Defaults(__pyx_defaults, __pyx_self)->__pyx_arg_db);
  __Pyx_GIVEREF(__Pyx_CyFunction_Defaults(__pyx_defaults, __pyx_self)->__pyx_arg_db);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __Pyx_CyFunction_Defaults(__pyx_defaults, __pyx_self)->__pyx_arg_db);
  __pyx_t_2 = PyTuple_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 346, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_1);
  __Pyx_INCREF(Py_None);
  __Pyx_GIVEREF(Py_None);
  PyTuple_SET_ITEM(__pyx_t_2, 1, Py_None);
  __pyx_t_1 = 0;
  __pyx_r = __pyx_t_2;
  __pyx_t_2 = 0;
  goto __pyx_L0;

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_AddTraceback("KakaoChat.kakao.__defaults__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* Python wrapper */
static PyObject *__pyx_pw_9KakaoChat_5kakao_38searchKeyword(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_9KakaoChat_5kakao_37searchKeyword[] = "\354\234\240\354\240\200\352\260\200 \354\271\264\355\205\214\352\263\240\353\246\254\353\245\274 \354\204\240\355\203\235\355\225\230\353\217\204\353\241\235 \354\234\240\353\217\204\355\225\234\353\213\244. \353\251\224\354\213\234\354\247\200 type: ListCard";
static PyMethodDef __pyx_mdef_9KakaoChat_5kakao_38searchKeyword = {"searchKeyword", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_9KakaoChat_5kakao_38searchKeyword, METH_VARARGS|METH_KEYWORDS, __pyx_doc_9KakaoChat_5kakao_37searchKeyword};
static PyObject *__pyx_pw_9KakaoChat_5kakao_38searchKeyword(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_content = 0;
  PyObject *__pyx_v_db = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("searchKeyword (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_content,&__pyx_n_s_db,0};
    PyObject* values[2] = {0,0};
    __pyx_defaults *__pyx_dynamic_args = __Pyx_CyFunction_Defaults(__pyx_defaults, __pyx_self);
    values[1] = __pyx_dynamic_args->__pyx_arg_db;
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_content)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_db);
          if (value) { values[1] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "searchKeyword") < 0)) __PYX_ERR(0, 346, __pyx_L3_error)
      }
    } else {
      switch (PyTuple_GET_SIZE(__pyx_args)) {
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        break;
        default: goto __pyx_L5_argtuple_error;
      }
    }
    __pyx_v_content = values[0];
    __pyx_v_db = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("searchKeyword", 0, 1, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 346, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("KakaoChat.kakao.searchKeyword", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_9KakaoChat_5kakao_37searchKeyword(__pyx_self, __pyx_v_content, __pyx_v_db);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_9KakaoChat_5kakao_37searchKeyword(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_content, PyObject *__pyx_v_db) {
  PyObject *__pyx_v_user_id = NULL;
  long __pyx_v_length;
  PyObject *__pyx_v_categories = NULL;
  PyObject *__pyx_v_user_category = NULL;
  PyObject *__pyx_v_url = NULL;
  PyObject *__pyx_v_ids = NULL;
  PyObject *__pyx_v_posts = NULL;
  PyObject *__pyx_v_dates = NULL;
  PyObject *__pyx_v_writers = NULL;
  PyObject *__pyx_v_noticeLength = NULL;
  PyObject *__pyx_v_notices = NULL;
  PyObject *__pyx_v_i = NULL;
  PyObject *__pyx_v_postDate = NULL;
  PyObject *__pyx_v_postTitle = NULL;
  PyObject *__pyx_v_postId = NULL;
  PyObject *__pyx_v_postLink = NULL;
  PyObject *__pyx_v_postWriter = NULL;
  PyObject *__pyx_v_data = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_t_4;
  PyObject *__pyx_t_5 = NULL;
  int __pyx_t_6;
  int __pyx_t_7;
  Py_ssize_t __pyx_t_8;
  Py_UCS4 __pyx_t_9;
  PyObject *__pyx_t_10 = NULL;
  PyObject *__pyx_t_11 = NULL;
  PyObject *__pyx_t_12 = NULL;
  PyObject *(*__pyx_t_13)(PyObject *);
  PyObject *(*__pyx_t_14)(PyObject *);
  int __pyx_t_15;
  PyObject *__pyx_t_16 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("searchKeyword", 0);

  /* "KakaoChat/kakao.py":348
 * def searchKeyword(content: Dict, db: Session = Depends(get_db)):
 *     """   .  type: ListCard"""
 *     user_id = content["userRequest"]["user"]["id"]  # user Id             # <<<<<<<<<<<<<<
 *     checkUserDB(db, user_id)
 *     print(">>> /ask/filter")
 */
  __pyx_t_1 = __Pyx_PyObject_Dict_GetItem(__pyx_v_content, __pyx_n_u_userRequest); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 348, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_Dict_GetItem(__pyx_t_1, __pyx_n_u_user); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 348, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_Dict_GetItem(__pyx_t_2, __pyx_n_u_id); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 348, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_user_id = __pyx_t_1;
  __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":349
 *     """   .  type: ListCard"""
 *     user_id = content["userRequest"]["user"]["id"]  # user Id
 *     checkUserDB(db, user_id)             # <<<<<<<<<<<<<<
 *     print(">>> /ask/filter")
 *     # pprint(content)
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_checkUserDB); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 349, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  __pyx_t_4 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
      __pyx_t_4 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_v_db, __pyx_v_user_id};
    __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_4, 2+__pyx_t_4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 349, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_1);
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_v_db, __pyx_v_user_id};
    __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_4, 2+__pyx_t_4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 349, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_1);
  } else
  #endif
  {
    __pyx_t_5 = PyTuple_New(2+__pyx_t_4); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 349, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    if (__pyx_t_3) {
      __Pyx_GIVEREF(__pyx_t_3); PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_3); __pyx_t_3 = NULL;
    }
    __Pyx_INCREF(__pyx_v_db);
    __Pyx_GIVEREF(__pyx_v_db);
    PyTuple_SET_ITEM(__pyx_t_5, 0+__pyx_t_4, __pyx_v_db);
    __Pyx_INCREF(__pyx_v_user_id);
    __Pyx_GIVEREF(__pyx_v_user_id);
    PyTuple_SET_ITEM(__pyx_t_5, 1+__pyx_t_4, __pyx_v_user_id);
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_5, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 349, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":350
 *     user_id = content["userRequest"]["user"]["id"]  # user Id
 *     checkUserDB(db, user_id)
 *     print(">>> /ask/filter")             # <<<<<<<<<<<<<<
 *     # pprint(content)
 *     # print(content["action"]["params"]["cate"])
 */
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__39, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 350, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":354
 *     # print(content["action"]["params"]["cate"])
 * 
 *     if not checkConnection():             # <<<<<<<<<<<<<<
 *         return makeTimeoutMessage()
 * 
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_checkConnection); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 354, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_5 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_5)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_5);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_5) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_5) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 354, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_6 < 0)) __PYX_ERR(0, 354, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_7 = ((!__pyx_t_6) != 0);
  if (__pyx_t_7) {

    /* "KakaoChat/kakao.py":355
 * 
 *     if not checkConnection():
 *         return makeTimeoutMessage()             # <<<<<<<<<<<<<<
 * 
 *     length = 5
 */
    __Pyx_XDECREF(__pyx_r);
    __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_makeTimeoutMessage); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 355, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_5 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
      __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_2);
      if (likely(__pyx_t_5)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
        __Pyx_INCREF(__pyx_t_5);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_2, function);
      }
    }
    __pyx_t_1 = (__pyx_t_5) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_5) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 355, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_r = __pyx_t_1;
    __pyx_t_1 = 0;
    goto __pyx_L0;

    /* "KakaoChat/kakao.py":354
 *     # print(content["action"]["params"]["cate"])
 * 
 *     if not checkConnection():             # <<<<<<<<<<<<<<
 *         return makeTimeoutMessage()
 * 
 */
  }

  /* "KakaoChat/kakao.py":357
 *         return makeTimeoutMessage()
 * 
 *     length = 5             # <<<<<<<<<<<<<<
 * 
 *     categories = {
 */
  __pyx_v_length = 5;

  /* "KakaoChat/kakao.py":360
 * 
 *     categories = {
 *         "": 1,             # <<<<<<<<<<<<<<
 *         "": 168,
 *         "": 2,
 */
  __pyx_t_1 = __Pyx_PyDict_NewPresized(12); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 360, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__26, __pyx_int_1) < 0) __PYX_ERR(0, 360, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__27, __pyx_int_168) < 0) __PYX_ERR(0, 360, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__28, __pyx_int_2) < 0) __PYX_ERR(0, 360, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__29, __pyx_int_3) < 0) __PYX_ERR(0, 360, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__30, __pyx_int_6) < 0) __PYX_ERR(0, 360, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__31, __pyx_int_7) < 0) __PYX_ERR(0, 360, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__32, __pyx_int_166) < 0) __PYX_ERR(0, 360, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__33, __pyx_int_167) < 0) __PYX_ERR(0, 360, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__40, __pyx_int_167) < 0) __PYX_ERR(0, 360, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__34, __pyx_int_4) < 0) __PYX_ERR(0, 360, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__35, __pyx_int_5) < 0) __PYX_ERR(0, 360, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__36, __pyx_int_8) < 0) __PYX_ERR(0, 360, __pyx_L1_error)
  __pyx_v_categories = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":374
 *     }
 * 
 *     user_category = content["action"]["params"]["cate"].replace(             # <<<<<<<<<<<<<<
 *         " ", ""
 *     )  # remove whitespace
 */
  __pyx_t_1 = __Pyx_PyObject_Dict_GetItem(__pyx_v_content, __pyx_n_u_action); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 374, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_Dict_GetItem(__pyx_t_1, __pyx_n_u_params); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 374, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_Dict_GetItem(__pyx_t_2, __pyx_n_u_cate); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 374, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_replace); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 374, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_tuple__41, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 374, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_user_category = __pyx_t_1;
  __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":378
 *     )  # remove whitespace
 * 
 *     url = f"{ADDRESS}?mode=list&srCategoryId={categories[user_category]}&srSearchKey=&srSearchVal=&articleLimit={length}&article.offset=0"             # <<<<<<<<<<<<<<
 * 
 *     ids, posts, dates, writers, noticeLength = parseNotices(
 */
  __pyx_t_1 = PyTuple_New(6); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 378, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_8 = 0;
  __pyx_t_9 = 127;
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_ADDRESS); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 378, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_5 = __Pyx_PyObject_FormatSimple(__pyx_t_2, __pyx_empty_unicode); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 378, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_9 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_5) > __pyx_t_9) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_5) : __pyx_t_9;
  __pyx_t_8 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_5);
  __Pyx_GIVEREF(__pyx_t_5);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_t_5);
  __pyx_t_5 = 0;
  __Pyx_INCREF(__pyx_kp_u_mode_list_srCategoryId);
  __pyx_t_8 += 24;
  __Pyx_GIVEREF(__pyx_kp_u_mode_list_srCategoryId);
  PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_kp_u_mode_list_srCategoryId);
  __pyx_t_5 = __Pyx_PyDict_GetItem(__pyx_v_categories, __pyx_v_user_category); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 378, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_2 = __Pyx_PyObject_FormatSimple(__pyx_t_5, __pyx_empty_unicode); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 378, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_9 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_2) > __pyx_t_9) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_2) : __pyx_t_9;
  __pyx_t_8 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_1, 2, __pyx_t_2);
  __pyx_t_2 = 0;
  __Pyx_INCREF(__pyx_kp_u_srSearchKey_srSearchVal_article);
  __pyx_t_8 += 40;
  __Pyx_GIVEREF(__pyx_kp_u_srSearchKey_srSearchVal_article);
  PyTuple_SET_ITEM(__pyx_t_1, 3, __pyx_kp_u_srSearchKey_srSearchVal_article);
  __pyx_t_2 = __Pyx_PyUnicode_From_long(__pyx_v_length, 0, ' ', 'd'); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 378, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_8 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_1, 4, __pyx_t_2);
  __pyx_t_2 = 0;
  __Pyx_INCREF(__pyx_kp_u_article_offset_0);
  __pyx_t_8 += 17;
  __Pyx_GIVEREF(__pyx_kp_u_article_offset_0);
  PyTuple_SET_ITEM(__pyx_t_1, 5, __pyx_kp_u_article_offset_0);
  __pyx_t_2 = __Pyx_PyUnicode_Join(__pyx_t_1, 6, __pyx_t_8, __pyx_t_9); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 378, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_v_url = ((PyObject*)__pyx_t_2);
  __pyx_t_2 = 0;

  /* "KakaoChat/kakao.py":380
 *     url = f"{ADDRESS}?mode=list&srCategoryId={categories[user_category]}&srSearchKey=&srSearchVal=&articleLimit={length}&article.offset=0"
 * 
 *     ids, posts, dates, writers, noticeLength = parseNotices(             # <<<<<<<<<<<<<<
 *         url, length
 *     )  # Parse notices
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_parseNotices); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 380, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);

  /* "KakaoChat/kakao.py":381
 * 
 *     ids, posts, dates, writers, noticeLength = parseNotices(
 *         url, length             # <<<<<<<<<<<<<<
 *     )  # Parse notices
 *     if noticeLength == 0:
 */
  __pyx_t_5 = __Pyx_PyInt_From_long(__pyx_v_length); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 381, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_3 = NULL;
  __pyx_t_4 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_1))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_1);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_1, function);
      __pyx_t_4 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_1)) {
    PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_v_url, __pyx_t_5};
    __pyx_t_2 = __Pyx_PyFunction_FastCall(__pyx_t_1, __pyx_temp+1-__pyx_t_4, 2+__pyx_t_4); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 380, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_1)) {
    PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_v_url, __pyx_t_5};
    __pyx_t_2 = __Pyx_PyCFunction_FastCall(__pyx_t_1, __pyx_temp+1-__pyx_t_4, 2+__pyx_t_4); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 380, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  } else
  #endif
  {
    __pyx_t_10 = PyTuple_New(2+__pyx_t_4); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 380, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_10);
    if (__pyx_t_3) {
      __Pyx_GIVEREF(__pyx_t_3); PyTuple_SET_ITEM(__pyx_t_10, 0, __pyx_t_3); __pyx_t_3 = NULL;
    }
    __Pyx_INCREF(__pyx_v_url);
    __Pyx_GIVEREF(__pyx_v_url);
    PyTuple_SET_ITEM(__pyx_t_10, 0+__pyx_t_4, __pyx_v_url);
    __Pyx_GIVEREF(__pyx_t_5);
    PyTuple_SET_ITEM(__pyx_t_10, 1+__pyx_t_4, __pyx_t_5);
    __pyx_t_5 = 0;
    __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_t_10, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 380, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
  }
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if ((likely(PyTuple_CheckExact(__pyx_t_2))) || (PyList_CheckExact(__pyx_t_2))) {
    PyObject* sequence = __pyx_t_2;
    Py_ssize_t size = __Pyx_PySequence_SIZE(sequence);
    if (unlikely(size != 5)) {
      if (size > 5) __Pyx_RaiseTooManyValuesError(5);
      else if (size >= 0) __Pyx_RaiseNeedMoreValuesError(size);
      __PYX_ERR(0, 380, __pyx_L1_error)
    }
    #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    if (likely(PyTuple_CheckExact(sequence))) {
      __pyx_t_1 = PyTuple_GET_ITEM(sequence, 0); 
      __pyx_t_10 = PyTuple_GET_ITEM(sequence, 1); 
      __pyx_t_5 = PyTuple_GET_ITEM(sequence, 2); 
      __pyx_t_3 = PyTuple_GET_ITEM(sequence, 3); 
      __pyx_t_11 = PyTuple_GET_ITEM(sequence, 4); 
    } else {
      __pyx_t_1 = PyList_GET_ITEM(sequence, 0); 
      __pyx_t_10 = PyList_GET_ITEM(sequence, 1); 
      __pyx_t_5 = PyList_GET_ITEM(sequence, 2); 
      __pyx_t_3 = PyList_GET_ITEM(sequence, 3); 
      __pyx_t_11 = PyList_GET_ITEM(sequence, 4); 
    }
    __Pyx_INCREF(__pyx_t_1);
    __Pyx_INCREF(__pyx_t_10);
    __Pyx_INCREF(__pyx_t_5);
    __Pyx_INCREF(__pyx_t_3);
    __Pyx_INCREF(__pyx_t_11);
    #else
    {
      Py_ssize_t i;
      PyObject** temps[5] = {&__pyx_t_1,&__pyx_t_10,&__pyx_t_5,&__pyx_t_3,&__pyx_t_11};
      for (i=0; i < 5; i++) {
        PyObject* item = PySequence_ITEM(sequence, i); if (unlikely(!item)) __PYX_ERR(0, 380, __pyx_L1_error)
        __Pyx_GOTREF(item);
        *(temps[i]) = item;
      }
    }
    #endif
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  } else {
    Py_ssize_t index = -1;
    PyObject** temps[5] = {&__pyx_t_1,&__pyx_t_10,&__pyx_t_5,&__pyx_t_3,&__pyx_t_11};
    __pyx_t_12 = PyObject_GetIter(__pyx_t_2); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 380, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_12);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_13 = Py_TYPE(__pyx_t_12)->tp_iternext;
    for (index=0; index < 5; index++) {
      PyObject* item = __pyx_t_13(__pyx_t_12); if (unlikely(!item)) goto __pyx_L4_unpacking_failed;
      __Pyx_GOTREF(item);
      *(temps[index]) = item;
    }
    if (__Pyx_IternextUnpackEndCheck(__pyx_t_13(__pyx_t_12), 5) < 0) __PYX_ERR(0, 380, __pyx_L1_error)
    __pyx_t_13 = NULL;
    __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
    goto __pyx_L5_unpacking_done;
    __pyx_L4_unpacking_failed:;
    __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
    __pyx_t_13 = NULL;
    if (__Pyx_IterFinish() == 0) __Pyx_RaiseNeedMoreValuesError(index);
    __PYX_ERR(0, 380, __pyx_L1_error)
    __pyx_L5_unpacking_done:;
  }

  /* "KakaoChat/kakao.py":380
 *     url = f"{ADDRESS}?mode=list&srCategoryId={categories[user_category]}&srSearchKey=&srSearchVal=&articleLimit={length}&article.offset=0"
 * 
 *     ids, posts, dates, writers, noticeLength = parseNotices(             # <<<<<<<<<<<<<<
 *         url, length
 *     )  # Parse notices
 */
  __pyx_v_ids = __pyx_t_1;
  __pyx_t_1 = 0;
  __pyx_v_posts = __pyx_t_10;
  __pyx_t_10 = 0;
  __pyx_v_dates = __pyx_t_5;
  __pyx_t_5 = 0;
  __pyx_v_writers = __pyx_t_3;
  __pyx_t_3 = 0;
  __pyx_v_noticeLength = __pyx_t_11;
  __pyx_t_11 = 0;

  /* "KakaoChat/kakao.py":383
 *         url, length
 *     )  # Parse notices
 *     if noticeLength == 0:             # <<<<<<<<<<<<<<
 *         return makeTimeoutMessage()
 *     notices = []
 */
  __pyx_t_2 = __Pyx_PyInt_EqObjC(__pyx_v_noticeLength, __pyx_int_0, 0, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 383, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_7 = __Pyx_PyObject_IsTrue(__pyx_t_2); if (unlikely(__pyx_t_7 < 0)) __PYX_ERR(0, 383, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (__pyx_t_7) {

    /* "KakaoChat/kakao.py":384
 *     )  # Parse notices
 *     if noticeLength == 0:
 *         return makeTimeoutMessage()             # <<<<<<<<<<<<<<
 *     notices = []
 * 
 */
    __Pyx_XDECREF(__pyx_r);
    __Pyx_GetModuleGlobalName(__pyx_t_11, __pyx_n_s_makeTimeoutMessage); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 384, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_11);
    __pyx_t_3 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_11))) {
      __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_11);
      if (likely(__pyx_t_3)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_11);
        __Pyx_INCREF(__pyx_t_3);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_11, function);
      }
    }
    __pyx_t_2 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_11, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_11);
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 384, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
    __pyx_r = __pyx_t_2;
    __pyx_t_2 = 0;
    goto __pyx_L0;

    /* "KakaoChat/kakao.py":383
 *         url, length
 *     )  # Parse notices
 *     if noticeLength == 0:             # <<<<<<<<<<<<<<
 *         return makeTimeoutMessage()
 *     notices = []
 */
  }

  /* "KakaoChat/kakao.py":385
 *     if noticeLength == 0:
 *         return makeTimeoutMessage()
 *     notices = []             # <<<<<<<<<<<<<<
 * 
 *     for i in range(noticeLength):
 */
  __pyx_t_2 = PyList_New(0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 385, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_v_notices = ((PyObject*)__pyx_t_2);
  __pyx_t_2 = 0;

  /* "KakaoChat/kakao.py":387
 *     notices = []
 * 
 *     for i in range(noticeLength):             # <<<<<<<<<<<<<<
 *         postDate = dates[i].text(strip=True)
 *         postTitle = posts[i].text(strip=True)
 */
  __pyx_t_2 = __Pyx_PyObject_CallOneArg(__pyx_builtin_range, __pyx_v_noticeLength); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 387, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (likely(PyList_CheckExact(__pyx_t_2)) || PyTuple_CheckExact(__pyx_t_2)) {
    __pyx_t_11 = __pyx_t_2; __Pyx_INCREF(__pyx_t_11); __pyx_t_8 = 0;
    __pyx_t_14 = NULL;
  } else {
    __pyx_t_8 = -1; __pyx_t_11 = PyObject_GetIter(__pyx_t_2); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 387, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_11);
    __pyx_t_14 = Py_TYPE(__pyx_t_11)->tp_iternext; if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 387, __pyx_L1_error)
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  for (;;) {
    if (likely(!__pyx_t_14)) {
      if (likely(PyList_CheckExact(__pyx_t_11))) {
        if (__pyx_t_8 >= PyList_GET_SIZE(__pyx_t_11)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_2 = PyList_GET_ITEM(__pyx_t_11, __pyx_t_8); __Pyx_INCREF(__pyx_t_2); __pyx_t_8++; if (unlikely(0 < 0)) __PYX_ERR(0, 387, __pyx_L1_error)
        #else
        __pyx_t_2 = PySequence_ITEM(__pyx_t_11, __pyx_t_8); __pyx_t_8++; if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 387, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        #endif
      } else {
        if (__pyx_t_8 >= PyTuple_GET_SIZE(__pyx_t_11)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_2 = PyTuple_GET_ITEM(__pyx_t_11, __pyx_t_8); __Pyx_INCREF(__pyx_t_2); __pyx_t_8++; if (unlikely(0 < 0)) __PYX_ERR(0, 387, __pyx_L1_error)
        #else
        __pyx_t_2 = PySequence_ITEM(__pyx_t_11, __pyx_t_8); __pyx_t_8++; if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 387, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        #endif
      }
    } else {
      __pyx_t_2 = __pyx_t_14(__pyx_t_11);
      if (unlikely(!__pyx_t_2)) {
        PyObject* exc_type = PyErr_Occurred();
        if (exc_type) {
          if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
          else __PYX_ERR(0, 387, __pyx_L1_error)
        }
        break;
      }
      __Pyx_GOTREF(__pyx_t_2);
    }
    __Pyx_XDECREF_SET(__pyx_v_i, __pyx_t_2);
    __pyx_t_2 = 0;

    /* "KakaoChat/kakao.py":388
 * 
 *     for i in range(noticeLength):
 *         postDate = dates[i].text(strip=True)             # <<<<<<<<<<<<<<
 *         postTitle = posts[i].text(strip=True)
 *         postId = ids[i].text(strip=True)
 */
    __pyx_t_2 = __Pyx_PyObject_GetItem(__pyx_v_dates, __pyx_v_i); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 388, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_text); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 388, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 388, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_strip, Py_True) < 0) __PYX_ERR(0, 388, __pyx_L1_error)
    __pyx_t_5 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_empty_tuple, __pyx_t_2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 388, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_XDECREF_SET(__pyx_v_postDate, __pyx_t_5);
    __pyx_t_5 = 0;

    /* "KakaoChat/kakao.py":389
 *     for i in range(noticeLength):
 *         postDate = dates[i].text(strip=True)
 *         postTitle = posts[i].text(strip=True)             # <<<<<<<<<<<<<<
 *         postId = ids[i].text(strip=True)
 *         postLink = ADDRESS + posts[i].attributes["href"]
 */
    __pyx_t_5 = __Pyx_PyObject_GetItem(__pyx_v_posts, __pyx_v_i); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 389, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_5, __pyx_n_s_text); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 389, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_5 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 389, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    if (PyDict_SetItem(__pyx_t_5, __pyx_n_s_strip, Py_True) < 0) __PYX_ERR(0, 389, __pyx_L1_error)
    __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_empty_tuple, __pyx_t_5); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 389, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_XDECREF_SET(__pyx_v_postTitle, __pyx_t_3);
    __pyx_t_3 = 0;

    /* "KakaoChat/kakao.py":390
 *         postDate = dates[i].text(strip=True)
 *         postTitle = posts[i].text(strip=True)
 *         postId = ids[i].text(strip=True)             # <<<<<<<<<<<<<<
 *         postLink = ADDRESS + posts[i].attributes["href"]
 *         postWriter = writers[i].text(strip=False)
 */
    __pyx_t_3 = __Pyx_PyObject_GetItem(__pyx_v_ids, __pyx_v_i); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 390, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_text); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 390, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_3 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 390, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_strip, Py_True) < 0) __PYX_ERR(0, 390, __pyx_L1_error)
    __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_5, __pyx_empty_tuple, __pyx_t_3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 390, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_XDECREF_SET(__pyx_v_postId, __pyx_t_2);
    __pyx_t_2 = 0;

    /* "KakaoChat/kakao.py":391
 *         postTitle = posts[i].text(strip=True)
 *         postId = ids[i].text(strip=True)
 *         postLink = ADDRESS + posts[i].attributes["href"]             # <<<<<<<<<<<<<<
 *         postWriter = writers[i].text(strip=False)
 * 
 */
    __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_ADDRESS); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 391, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_3 = __Pyx_PyObject_GetItem(__pyx_v_posts, __pyx_v_i); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 391, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_attributes); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 391, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_3 = __Pyx_PyObject_Dict_GetItem(__pyx_t_5, __pyx_n_u_href); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 391, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_5 = PyNumber_Add(__pyx_t_2, __pyx_t_3); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 391, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_XDECREF_SET(__pyx_v_postLink, __pyx_t_5);
    __pyx_t_5 = 0;

    /* "KakaoChat/kakao.py":392
 *         postId = ids[i].text(strip=True)
 *         postLink = ADDRESS + posts[i].attributes["href"]
 *         postWriter = writers[i].text(strip=False)             # <<<<<<<<<<<<<<
 * 
 *         data = makeJSONwithDate(postId, postTitle, postDate, postLink, postWriter)
 */
    __pyx_t_5 = __Pyx_PyObject_GetItem(__pyx_v_writers, __pyx_v_i); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 392, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_5, __pyx_n_s_text); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 392, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_5 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 392, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    if (PyDict_SetItem(__pyx_t_5, __pyx_n_s_strip, Py_False) < 0) __PYX_ERR(0, 392, __pyx_L1_error)
    __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_empty_tuple, __pyx_t_5); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 392, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_XDECREF_SET(__pyx_v_postWriter, __pyx_t_2);
    __pyx_t_2 = 0;

    /* "KakaoChat/kakao.py":394
 *         postWriter = writers[i].text(strip=False)
 * 
 *         data = makeJSONwithDate(postId, postTitle, postDate, postLink, postWriter)             # <<<<<<<<<<<<<<
 *         notices.append(data)
 * 
 */
    __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_makeJSONwithDate); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 394, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_3 = NULL;
    __pyx_t_4 = 0;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_5))) {
      __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_5);
      if (likely(__pyx_t_3)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
        __Pyx_INCREF(__pyx_t_3);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_5, function);
        __pyx_t_4 = 1;
      }
    }
    #if CYTHON_FAST_PYCALL
    if (PyFunction_Check(__pyx_t_5)) {
      PyObject *__pyx_temp[6] = {__pyx_t_3, __pyx_v_postId, __pyx_v_postTitle, __pyx_v_postDate, __pyx_v_postLink, __pyx_v_postWriter};
      __pyx_t_2 = __Pyx_PyFunction_FastCall(__pyx_t_5, __pyx_temp+1-__pyx_t_4, 5+__pyx_t_4); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 394, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
      __Pyx_GOTREF(__pyx_t_2);
    } else
    #endif
    #if CYTHON_FAST_PYCCALL
    if (__Pyx_PyFastCFunction_Check(__pyx_t_5)) {
      PyObject *__pyx_temp[6] = {__pyx_t_3, __pyx_v_postId, __pyx_v_postTitle, __pyx_v_postDate, __pyx_v_postLink, __pyx_v_postWriter};
      __pyx_t_2 = __Pyx_PyCFunction_FastCall(__pyx_t_5, __pyx_temp+1-__pyx_t_4, 5+__pyx_t_4); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 394, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
      __Pyx_GOTREF(__pyx_t_2);
    } else
    #endif
    {
      __pyx_t_10 = PyTuple_New(5+__pyx_t_4); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 394, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_10);
      if (__pyx_t_3) {
        __Pyx_GIVEREF(__pyx_t_3); PyTuple_SET_ITEM(__pyx_t_10, 0, __pyx_t_3); __pyx_t_3 = NULL;
      }
      __Pyx_INCREF(__pyx_v_postId);
      __Pyx_GIVEREF(__pyx_v_postId);
      PyTuple_SET_ITEM(__pyx_t_10, 0+__pyx_t_4, __pyx_v_postId);
      __Pyx_INCREF(__pyx_v_postTitle);
      __Pyx_GIVEREF(__pyx_v_postTitle);
      PyTuple_SET_ITEM(__pyx_t_10, 1+__pyx_t_4, __pyx_v_postTitle);
      __Pyx_INCREF(__pyx_v_postDate);
      __Pyx_GIVEREF(__pyx_v_postDate);
      PyTuple_SET_ITEM(__pyx_t_10, 2+__pyx_t_4, __pyx_v_postDate);
      __Pyx_INCREF(__pyx_v_postLink);
      __Pyx_GIVEREF(__pyx_v_postLink);
      PyTuple_SET_ITEM(__pyx_t_10, 3+__pyx_t_4, __pyx_v_postLink);
      __Pyx_INCREF(__pyx_v_postWriter);
      __Pyx_GIVEREF(__pyx_v_postWriter);
      PyTuple_SET_ITEM(__pyx_t_10, 4+__pyx_t_4, __pyx_v_postWriter);
      __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_5, __pyx_t_10, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 394, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
    }
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_XDECREF_SET(__pyx_v_data, __pyx_t_2);
    __pyx_t_2 = 0;

    /* "KakaoChat/kakao.py":395
 * 
 *         data = makeJSONwithDate(postId, postTitle, postDate, postLink, postWriter)
 *         notices.append(data)             # <<<<<<<<<<<<<<
 * 
 *     updateLastNotice(db, user_id, int(ids[0].text(strip=True)))
 */
    __pyx_t_15 = __Pyx_PyList_Append(__pyx_v_notices, __pyx_v_data); if (unlikely(__pyx_t_15 == ((int)-1))) __PYX_ERR(0, 395, __pyx_L1_error)

    /* "KakaoChat/kakao.py":387
 *     notices = []
 * 
 *     for i in range(noticeLength):             # <<<<<<<<<<<<<<
 *         postDate = dates[i].text(strip=True)
 *         postTitle = posts[i].text(strip=True)
 */
  }
  __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;

  /* "KakaoChat/kakao.py":397
 *         notices.append(data)
 * 
 *     updateLastNotice(db, user_id, int(ids[0].text(strip=True)))             # <<<<<<<<<<<<<<
 * 
 *     data = {
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_updateLastNotice); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 397, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_5 = __Pyx_GetItemInt(__pyx_v_ids, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 397, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_10 = __Pyx_PyObject_GetAttrStr(__pyx_t_5, __pyx_n_s_text); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 397, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_10);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 397, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (PyDict_SetItem(__pyx_t_5, __pyx_n_s_strip, Py_True) < 0) __PYX_ERR(0, 397, __pyx_L1_error)
  __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_10, __pyx_empty_tuple, __pyx_t_5); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 397, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = __Pyx_PyNumber_Int(__pyx_t_3); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 397, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = NULL;
  __pyx_t_4 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
      __pyx_t_4 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[4] = {__pyx_t_3, __pyx_v_db, __pyx_v_user_id, __pyx_t_5};
    __pyx_t_11 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_4, 3+__pyx_t_4); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 397, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_11);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[4] = {__pyx_t_3, __pyx_v_db, __pyx_v_user_id, __pyx_t_5};
    __pyx_t_11 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_4, 3+__pyx_t_4); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 397, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_11);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  } else
  #endif
  {
    __pyx_t_10 = PyTuple_New(3+__pyx_t_4); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 397, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_10);
    if (__pyx_t_3) {
      __Pyx_GIVEREF(__pyx_t_3); PyTuple_SET_ITEM(__pyx_t_10, 0, __pyx_t_3); __pyx_t_3 = NULL;
    }
    __Pyx_INCREF(__pyx_v_db);
    __Pyx_GIVEREF(__pyx_v_db);
    PyTuple_SET_ITEM(__pyx_t_10, 0+__pyx_t_4, __pyx_v_db);
    __Pyx_INCREF(__pyx_v_user_id);
    __Pyx_GIVEREF(__pyx_v_user_id);
    PyTuple_SET_ITEM(__pyx_t_10, 1+__pyx_t_4, __pyx_v_user_id);
    __Pyx_GIVEREF(__pyx_t_5);
    PyTuple_SET_ITEM(__pyx_t_10, 2+__pyx_t_4, __pyx_t_5);
    __pyx_t_5 = 0;
    __pyx_t_11 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_10, NULL); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 397, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_11);
    __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;

  /* "KakaoChat/kakao.py":400
 * 
 *     data = {
 *         "version": "2.0",             # <<<<<<<<<<<<<<
 *         "template": {
 *             "outputs": [
 */
  __pyx_t_11 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 400, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_11);
  if (PyDict_SetItem(__pyx_t_11, __pyx_n_u_version, __pyx_kp_u_2_0) < 0) __PYX_ERR(0, 400, __pyx_L1_error)

  /* "KakaoChat/kakao.py":402
 *         "version": "2.0",
 *         "template": {
 *             "outputs": [             # <<<<<<<<<<<<<<
 *                 {
 *                     "listCard": {
 */
  __pyx_t_2 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 402, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);

  /* "KakaoChat/kakao.py":404
 *             "outputs": [
 *                 {
 *                     "listCard": {             # <<<<<<<<<<<<<<
 *                         "header": {"title": f"{user_category} "},
 *                         "items": notices[:5],
 */
  __pyx_t_10 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 404, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_10);

  /* "KakaoChat/kakao.py":405
 *                 {
 *                     "listCard": {
 *                         "header": {"title": f"{user_category} "},             # <<<<<<<<<<<<<<
 *                         "items": notices[:5],
 *                         "buttons": [
 */
  __pyx_t_5 = __Pyx_PyDict_NewPresized(3); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 405, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_3 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 405, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_1 = __Pyx_PyObject_FormatSimple(__pyx_v_user_category, __pyx_empty_unicode); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 405, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_12 = __Pyx_PyUnicode_Concat(__pyx_t_1, __pyx_kp_u__17); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 405, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_12);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_title, __pyx_t_12) < 0) __PYX_ERR(0, 405, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
  if (PyDict_SetItem(__pyx_t_5, __pyx_n_u_header, __pyx_t_3) < 0) __PYX_ERR(0, 405, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "KakaoChat/kakao.py":406
 *                     "listCard": {
 *                         "header": {"title": f"{user_category} "},
 *                         "items": notices[:5],             # <<<<<<<<<<<<<<
 *                         "buttons": [
 *                             {"label": "", "action": "share"},
 */
  __pyx_t_3 = __Pyx_PyList_GetSlice(__pyx_v_notices, 0, 5); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 406, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (PyDict_SetItem(__pyx_t_5, __pyx_n_u_items, __pyx_t_3) < 0) __PYX_ERR(0, 405, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "KakaoChat/kakao.py":408
 *                         "items": notices[:5],
 *                         "buttons": [
 *                             {"label": "", "action": "share"},             # <<<<<<<<<<<<<<
 *                             {
 *                                 "label": user_category,
 */
  __pyx_t_3 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 408, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_label, __pyx_n_u__19) < 0) __PYX_ERR(0, 408, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_action, __pyx_n_u_share) < 0) __PYX_ERR(0, 408, __pyx_L1_error)

  /* "KakaoChat/kakao.py":410
 *                             {"label": "", "action": "share"},
 *                             {
 *                                 "label": user_category,             # <<<<<<<<<<<<<<
 *                                 "action": "webLink",
 *                                 "webLinkUrl": f"https://www.ajou.ac.kr/kr/ajou/notice.do&?mode=list&srCategoryId={categories[user_category]}",
 */
  __pyx_t_12 = __Pyx_PyDict_NewPresized(3); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 410, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_12);
  if (PyDict_SetItem(__pyx_t_12, __pyx_n_u_label, __pyx_v_user_category) < 0) __PYX_ERR(0, 410, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_12, __pyx_n_u_action, __pyx_n_u_webLink) < 0) __PYX_ERR(0, 410, __pyx_L1_error)

  /* "KakaoChat/kakao.py":412
 *                                 "label": user_category,
 *                                 "action": "webLink",
 *                                 "webLinkUrl": f"https://www.ajou.ac.kr/kr/ajou/notice.do&?mode=list&srCategoryId={categories[user_category]}",             # <<<<<<<<<<<<<<
 *                             },
 *                         ],
 */
  __pyx_t_1 = __Pyx_PyDict_GetItem(__pyx_v_categories, __pyx_v_user_category); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 412, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_16 = __Pyx_PyObject_FormatSimple(__pyx_t_1, __pyx_empty_unicode); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 412, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_16);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyUnicode_Concat(__pyx_kp_u_https_www_ajou_ac_kr_kr_ajou_not_2, __pyx_t_16); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 412, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
  if (PyDict_SetItem(__pyx_t_12, __pyx_n_u_webLinkUrl, __pyx_t_1) < 0) __PYX_ERR(0, 410, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":407
 *                         "header": {"title": f"{user_category} "},
 *                         "items": notices[:5],
 *                         "buttons": [             # <<<<<<<<<<<<<<
 *                             {"label": "", "action": "share"},
 *                             {
 */
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 407, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_3);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_12);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_t_12);
  __pyx_t_3 = 0;
  __pyx_t_12 = 0;
  if (PyDict_SetItem(__pyx_t_5, __pyx_n_u_buttons, __pyx_t_1) < 0) __PYX_ERR(0, 405, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (PyDict_SetItem(__pyx_t_10, __pyx_n_u_listCard, __pyx_t_5) < 0) __PYX_ERR(0, 404, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  /* "KakaoChat/kakao.py":402
 *         "version": "2.0",
 *         "template": {
 *             "outputs": [             # <<<<<<<<<<<<<<
 *                 {
 *                     "listCard": {
 */
  __pyx_t_5 = PyList_New(1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 402, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_GIVEREF(__pyx_t_10);
  PyList_SET_ITEM(__pyx_t_5, 0, __pyx_t_10);
  __pyx_t_10 = 0;
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_u_outputs, __pyx_t_5) < 0) __PYX_ERR(0, 402, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  if (PyDict_SetItem(__pyx_t_11, __pyx_n_u_template, __pyx_t_2) < 0) __PYX_ERR(0, 400, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_XDECREF_SET(__pyx_v_data, __pyx_t_11);
  __pyx_t_11 = 0;

  /* "KakaoChat/kakao.py":425
 *     }
 * 
 *     return JSONResponse(content=data)             # <<<<<<<<<<<<<<
 * 
 * 
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_GetModuleGlobalName(__pyx_t_11, __pyx_n_s_JSONResponse); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 425, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_11);
  __pyx_t_2 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 425, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_content, __pyx_v_data) < 0) __PYX_ERR(0, 425, __pyx_L1_error)
  __pyx_t_5 = __Pyx_PyObject_Call(__pyx_t_11, __pyx_empty_tuple, __pyx_t_2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 425, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_r = __pyx_t_5;
  __pyx_t_5 = 0;
  goto __pyx_L0;

  /* "KakaoChat/kakao.py":346
 * 
 * @application.post("/ask/filter")
 * def searchKeyword(content: Dict, db: Session = Depends(get_db)):             # <<<<<<<<<<<<<<
 *     """   .  type: ListCard"""
 *     user_id = content["userRequest"]["user"]["id"]  # user Id
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_10);
  __Pyx_XDECREF(__pyx_t_11);
  __Pyx_XDECREF(__pyx_t_12);
  __Pyx_XDECREF(__pyx_t_16);
  __Pyx_AddTraceback("KakaoChat.kakao.searchKeyword", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_user_id);
  __Pyx_XDECREF(__pyx_v_categories);
  __Pyx_XDECREF(__pyx_v_user_category);
  __Pyx_XDECREF(__pyx_v_url);
  __Pyx_XDECREF(__pyx_v_ids);
  __Pyx_XDECREF(__pyx_v_posts);
  __Pyx_XDECREF(__pyx_v_dates);
  __Pyx_XDECREF(__pyx_v_writers);
  __Pyx_XDECREF(__pyx_v_noticeLength);
  __Pyx_XDECREF(__pyx_v_notices);
  __Pyx_XDECREF(__pyx_v_i);
  __Pyx_XDECREF(__pyx_v_postDate);
  __Pyx_XDECREF(__pyx_v_postTitle);
  __Pyx_XDECREF(__pyx_v_postId);
  __Pyx_XDECREF(__pyx_v_postLink);
  __Pyx_XDECREF(__pyx_v_postWriter);
  __Pyx_XDECREF(__pyx_v_data);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "KakaoChat/kakao.py":429
 * 
 * @application.post("/last")
 * def parseOne(content: Dict, db: Session = Depends(get_db)):             # <<<<<<<<<<<<<<
 *     """    1 .  type: ListCard"""
 *     user_id = content["userRequest"]["user"]["id"]  # user Id
 */

static PyObject *__pyx_pf_9KakaoChat_5kakao_49__defaults__(CYTHON_UNUSED PyObject *__pyx_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__defaults__", 0);
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = PyTuple_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 429, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__Pyx_CyFunction_Defaults(__pyx_defaults1, __pyx_self)->__pyx_arg_db);
  __Pyx_GIVEREF(__Pyx_CyFunction_Defaults(__pyx_defaults1, __pyx_self)->__pyx_arg_db);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __Pyx_CyFunction_Defaults(__pyx_defaults1, __pyx_self)->__pyx_arg_db);
  __pyx_t_2 = PyTuple_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 429, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_1);
  __Pyx_INCREF(Py_None);
  __Pyx_GIVEREF(Py_None);
  PyTuple_SET_ITEM(__pyx_t_2, 1, Py_None);
  __pyx_t_1 = 0;
  __pyx_r = __pyx_t_2;
  __pyx_t_2 = 0;
  goto __pyx_L0;

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_AddTraceback("KakaoChat.kakao.__defaults__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* Python wrapper */
static PyObject *__pyx_pw_9KakaoChat_5kakao_40parseOne(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_9KakaoChat_5kakao_39parseOne[] = "\354\247\200\353\202\234 \354\265\234\352\267\274 \353\247\210\354\247\200\353\247\211 \352\263\265\354\247\200 1\352\260\234\353\247\214 \354\235\275\354\226\264\354\230\250\353\213\244. \353\251\224\354\213\234\354\247\200 type: ListCard";
static PyMethodDef __pyx_mdef_9KakaoChat_5kakao_40parseOne = {"parseOne", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_9KakaoChat_5kakao_40parseOne, METH_VARARGS|METH_KEYWORDS, __pyx_doc_9KakaoChat_5kakao_39parseOne};
static PyObject *__pyx_pw_9KakaoChat_5kakao_40parseOne(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_content = 0;
  PyObject *__pyx_v_db = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("parseOne (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_content,&__pyx_n_s_db,0};
    PyObject* values[2] = {0,0};
    __pyx_defaults1 *__pyx_dynamic_args = __Pyx_CyFunction_Defaults(__pyx_defaults1, __pyx_self);
    values[1] = __pyx_dynamic_args->__pyx_arg_db;
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_content)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_db);
          if (value) { values[1] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "parseOne") < 0)) __PYX_ERR(0, 429, __pyx_L3_error)
      }
    } else {
      switch (PyTuple_GET_SIZE(__pyx_args)) {
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        break;
        default: goto __pyx_L5_argtuple_error;
      }
    }
    __pyx_v_content = values[0];
    __pyx_v_db = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("parseOne", 0, 1, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 429, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("KakaoChat.kakao.parseOne", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_9KakaoChat_5kakao_39parseOne(__pyx_self, __pyx_v_content, __pyx_v_db);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_9KakaoChat_5kakao_39parseOne(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_content, PyObject *__pyx_v_db) {
  PyObject *__pyx_v_user_id = NULL;
  PyObject *__pyx_v_notice = NULL;
  PyObject *__pyx_v_date = NULL;
  PyObject *__pyx_v_data = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_t_4;
  PyObject *__pyx_t_5 = NULL;
  int __pyx_t_6;
  int __pyx_t_7;
  PyObject *(*__pyx_t_8)(PyObject *);
  PyObject *__pyx_t_9 = NULL;
  PyObject *__pyx_t_10 = NULL;
  PyObject *__pyx_t_11 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("parseOne", 0);

  /* "KakaoChat/kakao.py":431
 * def parseOne(content: Dict, db: Session = Depends(get_db)):
 *     """    1 .  type: ListCard"""
 *     user_id = content["userRequest"]["user"]["id"]  # user Id             # <<<<<<<<<<<<<<
 *     checkUserDB(db, user_id)
 *     print("/last")
 */
  __pyx_t_1 = __Pyx_PyObject_Dict_GetItem(__pyx_v_content, __pyx_n_u_userRequest); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 431, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_Dict_GetItem(__pyx_t_1, __pyx_n_u_user); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 431, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_Dict_GetItem(__pyx_t_2, __pyx_n_u_id); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 431, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_user_id = __pyx_t_1;
  __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":432
 *     """    1 .  type: ListCard"""
 *     user_id = content["userRequest"]["user"]["id"]  # user Id
 *     checkUserDB(db, user_id)             # <<<<<<<<<<<<<<
 *     print("/last")
 *     if not checkConnection():
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_checkUserDB); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 432, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  __pyx_t_4 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
      __pyx_t_4 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_v_db, __pyx_v_user_id};
    __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_4, 2+__pyx_t_4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 432, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_1);
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_v_db, __pyx_v_user_id};
    __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_4, 2+__pyx_t_4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 432, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_1);
  } else
  #endif
  {
    __pyx_t_5 = PyTuple_New(2+__pyx_t_4); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 432, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    if (__pyx_t_3) {
      __Pyx_GIVEREF(__pyx_t_3); PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_3); __pyx_t_3 = NULL;
    }
    __Pyx_INCREF(__pyx_v_db);
    __Pyx_GIVEREF(__pyx_v_db);
    PyTuple_SET_ITEM(__pyx_t_5, 0+__pyx_t_4, __pyx_v_db);
    __Pyx_INCREF(__pyx_v_user_id);
    __Pyx_GIVEREF(__pyx_v_user_id);
    PyTuple_SET_ITEM(__pyx_t_5, 1+__pyx_t_4, __pyx_v_user_id);
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_5, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 432, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":433
 *     user_id = content["userRequest"]["user"]["id"]  # user Id
 *     checkUserDB(db, user_id)
 *     print("/last")             # <<<<<<<<<<<<<<
 *     if not checkConnection():
 *         return makeTimeoutMessage()
 */
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__42, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 433, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":434
 *     checkUserDB(db, user_id)
 *     print("/last")
 *     if not checkConnection():             # <<<<<<<<<<<<<<
 *         return makeTimeoutMessage()
 * 
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_checkConnection); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 434, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_5 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_5)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_5);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_5) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_5) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 434, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_6 < 0)) __PYX_ERR(0, 434, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_7 = ((!__pyx_t_6) != 0);
  if (__pyx_t_7) {

    /* "KakaoChat/kakao.py":435
 *     print("/last")
 *     if not checkConnection():
 *         return makeTimeoutMessage()             # <<<<<<<<<<<<<<
 * 
 *     notice, date = getLastNotice()
 */
    __Pyx_XDECREF(__pyx_r);
    __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_makeTimeoutMessage); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 435, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_5 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
      __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_2);
      if (likely(__pyx_t_5)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
        __Pyx_INCREF(__pyx_t_5);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_2, function);
      }
    }
    __pyx_t_1 = (__pyx_t_5) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_5) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 435, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_r = __pyx_t_1;
    __pyx_t_1 = 0;
    goto __pyx_L0;

    /* "KakaoChat/kakao.py":434
 *     checkUserDB(db, user_id)
 *     print("/last")
 *     if not checkConnection():             # <<<<<<<<<<<<<<
 *         return makeTimeoutMessage()
 * 
 */
  }

  /* "KakaoChat/kakao.py":437
 *         return makeTimeoutMessage()
 * 
 *     notice, date = getLastNotice()             # <<<<<<<<<<<<<<
 * 
 *     data = {
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_getLastNotice); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 437, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_5 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_5)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_5);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_5) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_5) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 437, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if ((likely(PyTuple_CheckExact(__pyx_t_1))) || (PyList_CheckExact(__pyx_t_1))) {
    PyObject* sequence = __pyx_t_1;
    Py_ssize_t size = __Pyx_PySequence_SIZE(sequence);
    if (unlikely(size != 2)) {
      if (size > 2) __Pyx_RaiseTooManyValuesError(2);
      else if (size >= 0) __Pyx_RaiseNeedMoreValuesError(size);
      __PYX_ERR(0, 437, __pyx_L1_error)
    }
    #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    if (likely(PyTuple_CheckExact(sequence))) {
      __pyx_t_2 = PyTuple_GET_ITEM(sequence, 0); 
      __pyx_t_5 = PyTuple_GET_ITEM(sequence, 1); 
    } else {
      __pyx_t_2 = PyList_GET_ITEM(sequence, 0); 
      __pyx_t_5 = PyList_GET_ITEM(sequence, 1); 
    }
    __Pyx_INCREF(__pyx_t_2);
    __Pyx_INCREF(__pyx_t_5);
    #else
    __pyx_t_2 = PySequence_ITEM(sequence, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 437, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_5 = PySequence_ITEM(sequence, 1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 437, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    #endif
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  } else {
    Py_ssize_t index = -1;
    __pyx_t_3 = PyObject_GetIter(__pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 437, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_8 = Py_TYPE(__pyx_t_3)->tp_iternext;
    index = 0; __pyx_t_2 = __pyx_t_8(__pyx_t_3); if (unlikely(!__pyx_t_2)) goto __pyx_L4_unpacking_failed;
    __Pyx_GOTREF(__pyx_t_2);
    index = 1; __pyx_t_5 = __pyx_t_8(__pyx_t_3); if (unlikely(!__pyx_t_5)) goto __pyx_L4_unpacking_failed;
    __Pyx_GOTREF(__pyx_t_5);
    if (__Pyx_IternextUnpackEndCheck(__pyx_t_8(__pyx_t_3), 2) < 0) __PYX_ERR(0, 437, __pyx_L1_error)
    __pyx_t_8 = NULL;
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    goto __pyx_L5_unpacking_done;
    __pyx_L4_unpacking_failed:;
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_8 = NULL;
    if (__Pyx_IterFinish() == 0) __Pyx_RaiseNeedMoreValuesError(index);
    __PYX_ERR(0, 437, __pyx_L1_error)
    __pyx_L5_unpacking_done:;
  }
  __pyx_v_notice = __pyx_t_2;
  __pyx_t_2 = 0;
  __pyx_v_date = __pyx_t_5;
  __pyx_t_5 = 0;

  /* "KakaoChat/kakao.py":440
 * 
 *     data = {
 *         "version": "2.0",             # <<<<<<<<<<<<<<
 *         "template": {
 *             "outputs": [
 */
  __pyx_t_1 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 440, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u_version, __pyx_kp_u_2_0) < 0) __PYX_ERR(0, 440, __pyx_L1_error)

  /* "KakaoChat/kakao.py":442
 *         "version": "2.0",
 *         "template": {
 *             "outputs": [             # <<<<<<<<<<<<<<
 *                 {
 *                     "listCard": {
 */
  __pyx_t_5 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 442, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);

  /* "KakaoChat/kakao.py":444
 *             "outputs": [
 *                 {
 *                     "listCard": {             # <<<<<<<<<<<<<<
 *                         "header": {"title": f"{date} "},
 *                         "items": [notice],
 */
  __pyx_t_2 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 444, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);

  /* "KakaoChat/kakao.py":445
 *                 {
 *                     "listCard": {
 *                         "header": {"title": f"{date} "},             # <<<<<<<<<<<<<<
 *                         "items": [notice],
 *                         "buttons": [{"label": "", "action": "share"},],
 */
  __pyx_t_3 = __Pyx_PyDict_NewPresized(3); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 445, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_9 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 445, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_9);
  __pyx_t_10 = __Pyx_PyObject_FormatSimple(__pyx_v_date, __pyx_empty_unicode); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 445, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_10);
  __pyx_t_11 = __Pyx_PyUnicode_Concat(__pyx_t_10, __pyx_kp_u__17); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 445, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_11);
  __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
  if (PyDict_SetItem(__pyx_t_9, __pyx_n_u_title, __pyx_t_11) < 0) __PYX_ERR(0, 445, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_header, __pyx_t_9) < 0) __PYX_ERR(0, 445, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;

  /* "KakaoChat/kakao.py":446
 *                     "listCard": {
 *                         "header": {"title": f"{date} "},
 *                         "items": [notice],             # <<<<<<<<<<<<<<
 *                         "buttons": [{"label": "", "action": "share"},],
 *                     }
 */
  __pyx_t_9 = PyList_New(1); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 446, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_9);
  __Pyx_INCREF(__pyx_v_notice);
  __Pyx_GIVEREF(__pyx_v_notice);
  PyList_SET_ITEM(__pyx_t_9, 0, __pyx_v_notice);
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_items, __pyx_t_9) < 0) __PYX_ERR(0, 445, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;

  /* "KakaoChat/kakao.py":447
 *                         "header": {"title": f"{date} "},
 *                         "items": [notice],
 *                         "buttons": [{"label": "", "action": "share"},],             # <<<<<<<<<<<<<<
 *                     }
 *                 }
 */
  __pyx_t_9 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 447, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_9);
  if (PyDict_SetItem(__pyx_t_9, __pyx_n_u_label, __pyx_n_u__19) < 0) __PYX_ERR(0, 447, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_9, __pyx_n_u_action, __pyx_n_u_share) < 0) __PYX_ERR(0, 447, __pyx_L1_error)
  __pyx_t_11 = PyList_New(1); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 447, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_11);
  __Pyx_GIVEREF(__pyx_t_9);
  PyList_SET_ITEM(__pyx_t_11, 0, __pyx_t_9);
  __pyx_t_9 = 0;
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_buttons, __pyx_t_11) < 0) __PYX_ERR(0, 445, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_u_listCard, __pyx_t_3) < 0) __PYX_ERR(0, 444, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "KakaoChat/kakao.py":442
 *         "version": "2.0",
 *         "template": {
 *             "outputs": [             # <<<<<<<<<<<<<<
 *                 {
 *                     "listCard": {
 */
  __pyx_t_3 = PyList_New(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 442, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_2);
  PyList_SET_ITEM(__pyx_t_3, 0, __pyx_t_2);
  __pyx_t_2 = 0;
  if (PyDict_SetItem(__pyx_t_5, __pyx_n_u_outputs, __pyx_t_3) < 0) __PYX_ERR(0, 442, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u_template, __pyx_t_5) < 0) __PYX_ERR(0, 440, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_v_data = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":457
 *         },
 *     }
 *     return JSONResponse(content=data)             # <<<<<<<<<<<<<<
 * 
 * 
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_JSONResponse); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 457, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_5 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 457, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (PyDict_SetItem(__pyx_t_5, __pyx_n_s_content, __pyx_v_data) < 0) __PYX_ERR(0, 457, __pyx_L1_error)
  __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_empty_tuple, __pyx_t_5); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 457, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_r = __pyx_t_3;
  __pyx_t_3 = 0;
  goto __pyx_L0;

  /* "KakaoChat/kakao.py":429
 * 
 * @application.post("/last")
 * def parseOne(content: Dict, db: Session = Depends(get_db)):             # <<<<<<<<<<<<<<
 *     """    1 .  type: ListCard"""
 *     user_id = content["userRequest"]["user"]["id"]  # user Id
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_9);
  __Pyx_XDECREF(__pyx_t_10);
  __Pyx_XDECREF(__pyx_t_11);
  __Pyx_AddTraceback("KakaoChat.kakao.parseOne", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_user_id);
  __Pyx_XDECREF(__pyx_v_notice);
  __Pyx_XDECREF(__pyx_v_date);
  __Pyx_XDECREF(__pyx_v_data);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "KakaoChat/kakao.py":461
 * 
 * @application.post("/search")
 * def searchNotice(content: Dict, db: Session = Depends(get_db)):             # <<<<<<<<<<<<<<
 *     """    .  type: simpleText | ListCard"""
 *     user_id = content["userRequest"]["user"]["id"]  # user Id
 */

static PyObject *__pyx_pf_9KakaoChat_5kakao_51__defaults__(CYTHON_UNUSED PyObject *__pyx_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__defaults__", 0);
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = PyTuple_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 461, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__Pyx_CyFunction_Defaults(__pyx_defaults2, __pyx_self)->__pyx_arg_db);
  __Pyx_GIVEREF(__Pyx_CyFunction_Defaults(__pyx_defaults2, __pyx_self)->__pyx_arg_db);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __Pyx_CyFunction_Defaults(__pyx_defaults2, __pyx_self)->__pyx_arg_db);
  __pyx_t_2 = PyTuple_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 461, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_1);
  __Pyx_INCREF(Py_None);
  __Pyx_GIVEREF(Py_None);
  PyTuple_SET_ITEM(__pyx_t_2, 1, Py_None);
  __pyx_t_1 = 0;
  __pyx_r = __pyx_t_2;
  __pyx_t_2 = 0;
  goto __pyx_L0;

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_AddTraceback("KakaoChat.kakao.__defaults__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* Python wrapper */
static PyObject *__pyx_pw_9KakaoChat_5kakao_42searchNotice(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_9KakaoChat_5kakao_41searchNotice[] = "\354\234\240\354\240\200\354\235\230 \355\202\244\354\233\214\353\223\234\354\227\220 \353\247\236\353\212\224 \352\263\265\354\247\200\353\245\274 \353\266\210\353\237\254\354\230\250\353\213\244. \353\251\224\354\213\234\354\247\200 type: simpleText | ListCard";
static PyMethodDef __pyx_mdef_9KakaoChat_5kakao_42searchNotice = {"searchNotice", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_9KakaoChat_5kakao_42searchNotice, METH_VARARGS|METH_KEYWORDS, __pyx_doc_9KakaoChat_5kakao_41searchNotice};
static PyObject *__pyx_pw_9KakaoChat_5kakao_42searchNotice(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_content = 0;
  PyObject *__pyx_v_db = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("searchNotice (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_content,&__pyx_n_s_db,0};
    PyObject* values[2] = {0,0};
    __pyx_defaults2 *__pyx_dynamic_args = __Pyx_CyFunction_Defaults(__pyx_defaults2, __pyx_self);
    values[1] = __pyx_dynamic_args->__pyx_arg_db;
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_content)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_db);
          if (value) { values[1] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "searchNotice") < 0)) __PYX_ERR(0, 461, __pyx_L3_error)
      }
    } else {
      switch (PyTuple_GET_SIZE(__pyx_args)) {
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        break;
        default: goto __pyx_L5_argtuple_error;
      }
    }
    __pyx_v_content = values[0];
    __pyx_v_db = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("searchNotice", 0, 1, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 461, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("KakaoChat.kakao.searchNotice", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_9KakaoChat_5kakao_41searchNotice(__pyx_self, __pyx_v_content, __pyx_v_db);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_9KakaoChat_5kakao_41searchNotice(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_content, PyObject *__pyx_v_db) {
  PyObject *__pyx_v_user_id = NULL;
  PyObject *__pyx_v_keyword = NULL;
  long __pyx_v_length;
  PyObject *__pyx_v_url = NULL;
  PyObject *__pyx_v_ids = NULL;
  PyObject *__pyx_v_posts = NULL;
  PyObject *__pyx_v_dates = NULL;
  PyObject *__pyx_v_writers = NULL;
  PyObject *__pyx_v_noticeLength = NULL;
  PyObject *__pyx_v_notices = NULL;
  PyObject *__pyx_v_i = NULL;
  PyObject *__pyx_v_postDate = NULL;
  PyObject *__pyx_v_postTitle = NULL;
  PyObject *__pyx_v_postId = NULL;
  PyObject *__pyx_v_postLink = NULL;
  PyObject *__pyx_v_postWriter = NULL;
  PyObject *__pyx_v_data = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_t_4;
  PyObject *__pyx_t_5 = NULL;
  int __pyx_t_6;
  int __pyx_t_7;
  PyObject *__pyx_t_8 = NULL;
  PyObject *__pyx_t_9 = NULL;
  Py_ssize_t __pyx_t_10;
  Py_UCS4 __pyx_t_11;
  PyObject *__pyx_t_12 = NULL;
  PyObject *(*__pyx_t_13)(PyObject *);
  PyObject *__pyx_t_14 = NULL;
  PyObject *(*__pyx_t_15)(PyObject *);
  int __pyx_t_16;
  PyObject *__pyx_t_17 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("searchNotice", 0);
  __Pyx_INCREF(__pyx_v_content);

  /* "KakaoChat/kakao.py":463
 * def searchNotice(content: Dict, db: Session = Depends(get_db)):
 *     """    .  type: simpleText | ListCard"""
 *     user_id = content["userRequest"]["user"]["id"]  # user Id             # <<<<<<<<<<<<<<
 *     checkUserDB(db, user_id)
 * 
 */
  __pyx_t_1 = __Pyx_PyObject_Dict_GetItem(__pyx_v_content, __pyx_n_u_userRequest); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 463, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_Dict_GetItem(__pyx_t_1, __pyx_n_u_user); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 463, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_Dict_GetItem(__pyx_t_2, __pyx_n_u_id); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 463, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_user_id = __pyx_t_1;
  __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":464
 *     """    .  type: simpleText | ListCard"""
 *     user_id = content["userRequest"]["user"]["id"]  # user Id
 *     checkUserDB(db, user_id)             # <<<<<<<<<<<<<<
 * 
 *     print(">>> /search")
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_checkUserDB); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 464, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  __pyx_t_4 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
      __pyx_t_4 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_v_db, __pyx_v_user_id};
    __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_4, 2+__pyx_t_4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 464, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_1);
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_v_db, __pyx_v_user_id};
    __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_4, 2+__pyx_t_4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 464, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_1);
  } else
  #endif
  {
    __pyx_t_5 = PyTuple_New(2+__pyx_t_4); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 464, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    if (__pyx_t_3) {
      __Pyx_GIVEREF(__pyx_t_3); PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_3); __pyx_t_3 = NULL;
    }
    __Pyx_INCREF(__pyx_v_db);
    __Pyx_GIVEREF(__pyx_v_db);
    PyTuple_SET_ITEM(__pyx_t_5, 0+__pyx_t_4, __pyx_v_db);
    __Pyx_INCREF(__pyx_v_user_id);
    __Pyx_GIVEREF(__pyx_v_user_id);
    PyTuple_SET_ITEM(__pyx_t_5, 1+__pyx_t_4, __pyx_v_user_id);
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_5, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 464, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":466
 *     checkUserDB(db, user_id)
 * 
 *     print(">>> /search")             # <<<<<<<<<<<<<<
 *     if not checkConnection():
 *         return makeTimeoutMessage()
 */
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__43, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 466, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":467
 * 
 *     print(">>> /search")
 *     if not checkConnection():             # <<<<<<<<<<<<<<
 *         return makeTimeoutMessage()
 * 
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_checkConnection); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 467, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_5 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_5)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_5);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_5) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_5) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 467, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_6 < 0)) __PYX_ERR(0, 467, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_7 = ((!__pyx_t_6) != 0);
  if (__pyx_t_7) {

    /* "KakaoChat/kakao.py":468
 *     print(">>> /search")
 *     if not checkConnection():
 *         return makeTimeoutMessage()             # <<<<<<<<<<<<<<
 * 
 *     # pprint(content)
 */
    __Pyx_XDECREF(__pyx_r);
    __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_makeTimeoutMessage); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 468, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_5 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
      __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_2);
      if (likely(__pyx_t_5)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
        __Pyx_INCREF(__pyx_t_5);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_2, function);
      }
    }
    __pyx_t_1 = (__pyx_t_5) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_5) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 468, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_r = __pyx_t_1;
    __pyx_t_1 = 0;
    goto __pyx_L0;

    /* "KakaoChat/kakao.py":467
 * 
 *     print(">>> /search")
 *     if not checkConnection():             # <<<<<<<<<<<<<<
 *         return makeTimeoutMessage()
 * 
 */
  }

  /* "KakaoChat/kakao.py":471
 * 
 *     # pprint(content)
 *     content = content["action"]["params"]             # <<<<<<<<<<<<<<
 *     if not "sys_text" in content:
 *         return JSONResponse(
 */
  __pyx_t_1 = __Pyx_PyObject_Dict_GetItem(__pyx_v_content, __pyx_n_u_action); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 471, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_Dict_GetItem(__pyx_t_1, __pyx_n_u_params); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 471, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF_SET(__pyx_v_content, __pyx_t_2);
  __pyx_t_2 = 0;

  /* "KakaoChat/kakao.py":472
 *     # pprint(content)
 *     content = content["action"]["params"]
 *     if not "sys_text" in content:             # <<<<<<<<<<<<<<
 *         return JSONResponse(
 *             content={
 */
  __pyx_t_7 = (__Pyx_PySequence_ContainsTF(__pyx_n_u_sys_text, __pyx_v_content, Py_NE)); if (unlikely(__pyx_t_7 < 0)) __PYX_ERR(0, 472, __pyx_L1_error)
  __pyx_t_6 = (__pyx_t_7 != 0);
  if (__pyx_t_6) {

    /* "KakaoChat/kakao.py":473
 *     content = content["action"]["params"]
 *     if not "sys_text" in content:
 *         return JSONResponse(             # <<<<<<<<<<<<<<
 *             content={
 *                 "version": "2.0",
 */
    __Pyx_XDECREF(__pyx_r);
    __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_JSONResponse); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 473, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);

    /* "KakaoChat/kakao.py":474
 *     if not "sys_text" in content:
 *         return JSONResponse(
 *             content={             # <<<<<<<<<<<<<<
 *                 "version": "2.0",
 *                 "template": {
 */
    __pyx_t_1 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 474, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);

    /* "KakaoChat/kakao.py":475
 *         return JSONResponse(
 *             content={
 *                 "version": "2.0",             # <<<<<<<<<<<<<<
 *                 "template": {
 *                     "outputs": [{"simpleText": {"text": "2021     ."}}],
 */
    __pyx_t_5 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 475, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    if (PyDict_SetItem(__pyx_t_5, __pyx_n_u_version, __pyx_kp_u_2_0) < 0) __PYX_ERR(0, 475, __pyx_L1_error)

    /* "KakaoChat/kakao.py":477
 *                 "version": "2.0",
 *                 "template": {
 *                     "outputs": [{"simpleText": {"text": "2021     ."}}],             # <<<<<<<<<<<<<<
 *                     "quickReplies": [
 *                         {
 */
    __pyx_t_3 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 477, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_8 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 477, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __pyx_t_9 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 477, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_9);
    if (PyDict_SetItem(__pyx_t_9, __pyx_n_u_text, __pyx_kp_u_2021) < 0) __PYX_ERR(0, 477, __pyx_L1_error)
    if (PyDict_SetItem(__pyx_t_8, __pyx_n_u_simpleText, __pyx_t_9) < 0) __PYX_ERR(0, 477, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
    __pyx_t_9 = PyList_New(1); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 477, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_9);
    __Pyx_GIVEREF(__pyx_t_8);
    PyList_SET_ITEM(__pyx_t_9, 0, __pyx_t_8);
    __pyx_t_8 = 0;
    if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_outputs, __pyx_t_9) < 0) __PYX_ERR(0, 477, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;

    /* "KakaoChat/kakao.py":480
 *                     "quickReplies": [
 *                         {
 *                             "messageText": "2021 ",             # <<<<<<<<<<<<<<
 *                             "action": "message",
 *                             "label": "2021 ",
 */
    __pyx_t_9 = __Pyx_PyDict_NewPresized(3); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 480, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_9);
    if (PyDict_SetItem(__pyx_t_9, __pyx_n_u_messageText, __pyx_kp_u_2021_2) < 0) __PYX_ERR(0, 480, __pyx_L1_error)
    if (PyDict_SetItem(__pyx_t_9, __pyx_n_u_action, __pyx_n_u_message) < 0) __PYX_ERR(0, 480, __pyx_L1_error)
    if (PyDict_SetItem(__pyx_t_9, __pyx_n_u_label, __pyx_kp_u_2021_2) < 0) __PYX_ERR(0, 480, __pyx_L1_error)

    /* "KakaoChat/kakao.py":478
 *                 "template": {
 *                     "outputs": [{"simpleText": {"text": "2021     ."}}],
 *                     "quickReplies": [             # <<<<<<<<<<<<<<
 *                         {
 *                             "messageText": "2021 ",
 */
    __pyx_t_8 = PyList_New(1); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 478, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __Pyx_GIVEREF(__pyx_t_9);
    PyList_SET_ITEM(__pyx_t_8, 0, __pyx_t_9);
    __pyx_t_9 = 0;
    if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_quickReplies, __pyx_t_8) < 0) __PYX_ERR(0, 477, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
    if (PyDict_SetItem(__pyx_t_5, __pyx_n_u_template, __pyx_t_3) < 0) __PYX_ERR(0, 475, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_content, __pyx_t_5) < 0) __PYX_ERR(0, 474, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

    /* "KakaoChat/kakao.py":473
 *     content = content["action"]["params"]
 *     if not "sys_text" in content:
 *         return JSONResponse(             # <<<<<<<<<<<<<<
 *             content={
 *                 "version": "2.0",
 */
    __pyx_t_5 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_empty_tuple, __pyx_t_1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 473, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_r = __pyx_t_5;
    __pyx_t_5 = 0;
    goto __pyx_L0;

    /* "KakaoChat/kakao.py":472
 *     # pprint(content)
 *     content = content["action"]["params"]
 *     if not "sys_text" in content:             # <<<<<<<<<<<<<<
 *         return JSONResponse(
 *             content={
 */
  }

  /* "KakaoChat/kakao.py":488
 *             }
 *         )
 *     keyword = content["sys_text"]             # <<<<<<<<<<<<<<
 *     length = 7
 *     url = f"{ADDRESS}?mode=list&srSearchKey=&srSearchVal={quote(keyword.strip())}&articleLimit={length}&article.offset=0"
 */
  __pyx_t_5 = __Pyx_PyObject_Dict_GetItem(__pyx_v_content, __pyx_n_u_sys_text); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 488, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_v_keyword = __pyx_t_5;
  __pyx_t_5 = 0;

  /* "KakaoChat/kakao.py":489
 *         )
 *     keyword = content["sys_text"]
 *     length = 7             # <<<<<<<<<<<<<<
 *     url = f"{ADDRESS}?mode=list&srSearchKey=&srSearchVal={quote(keyword.strip())}&articleLimit={length}&article.offset=0"
 * 
 */
  __pyx_v_length = 7;

  /* "KakaoChat/kakao.py":490
 *     keyword = content["sys_text"]
 *     length = 7
 *     url = f"{ADDRESS}?mode=list&srSearchKey=&srSearchVal={quote(keyword.strip())}&articleLimit={length}&article.offset=0"             # <<<<<<<<<<<<<<
 * 
 *     ids, posts, dates, writers, noticeLength = parseNotices(
 */
  __pyx_t_5 = PyTuple_New(6); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 490, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_10 = 0;
  __pyx_t_11 = 127;
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_ADDRESS); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 490, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_FormatSimple(__pyx_t_1, __pyx_empty_unicode); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 490, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_11 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_2) > __pyx_t_11) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_2) : __pyx_t_11;
  __pyx_t_10 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_2);
  __pyx_t_2 = 0;
  __Pyx_INCREF(__pyx_kp_u_mode_list_srSearchKey_srSearchV);
  __pyx_t_10 += 36;
  __Pyx_GIVEREF(__pyx_kp_u_mode_list_srSearchKey_srSearchV);
  PyTuple_SET_ITEM(__pyx_t_5, 1, __pyx_kp_u_mode_list_srSearchKey_srSearchV);
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_quote); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 490, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_8 = __Pyx_PyObject_GetAttrStr(__pyx_v_keyword, __pyx_n_s_strip); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 490, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_9 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_8))) {
    __pyx_t_9 = PyMethod_GET_SELF(__pyx_t_8);
    if (likely(__pyx_t_9)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_8);
      __Pyx_INCREF(__pyx_t_9);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_8, function);
    }
  }
  __pyx_t_3 = (__pyx_t_9) ? __Pyx_PyObject_CallOneArg(__pyx_t_8, __pyx_t_9) : __Pyx_PyObject_CallNoArg(__pyx_t_8);
  __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
  if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 490, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_8 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_1))) {
    __pyx_t_8 = PyMethod_GET_SELF(__pyx_t_1);
    if (likely(__pyx_t_8)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
      __Pyx_INCREF(__pyx_t_8);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_1, function);
    }
  }
  __pyx_t_2 = (__pyx_t_8) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_8, __pyx_t_3) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_3);
  __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 490, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_FormatSimple(__pyx_t_2, __pyx_empty_unicode); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 490, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_11 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_1) > __pyx_t_11) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_1) : __pyx_t_11;
  __pyx_t_10 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_5, 2, __pyx_t_1);
  __pyx_t_1 = 0;
  __Pyx_INCREF(__pyx_kp_u_articleLimit);
  __pyx_t_10 += 14;
  __Pyx_GIVEREF(__pyx_kp_u_articleLimit);
  PyTuple_SET_ITEM(__pyx_t_5, 3, __pyx_kp_u_articleLimit);
  __pyx_t_1 = __Pyx_PyUnicode_From_long(__pyx_v_length, 0, ' ', 'd'); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 490, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_10 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_5, 4, __pyx_t_1);
  __pyx_t_1 = 0;
  __Pyx_INCREF(__pyx_kp_u_article_offset_0);
  __pyx_t_10 += 17;
  __Pyx_GIVEREF(__pyx_kp_u_article_offset_0);
  PyTuple_SET_ITEM(__pyx_t_5, 5, __pyx_kp_u_article_offset_0);
  __pyx_t_1 = __Pyx_PyUnicode_Join(__pyx_t_5, 6, __pyx_t_10, __pyx_t_11); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 490, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_v_url = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":492
 *     url = f"{ADDRESS}?mode=list&srSearchKey=&srSearchVal={quote(keyword.strip())}&articleLimit={length}&article.offset=0"
 * 
 *     ids, posts, dates, writers, noticeLength = parseNotices(             # <<<<<<<<<<<<<<
 *         url, length
 *     )  # Parse notices
 */
  __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_parseNotices); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 492, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);

  /* "KakaoChat/kakao.py":493
 * 
 *     ids, posts, dates, writers, noticeLength = parseNotices(
 *         url, length             # <<<<<<<<<<<<<<
 *     )  # Parse notices
 *     if noticeLength == 0:
 */
  __pyx_t_2 = __Pyx_PyInt_From_long(__pyx_v_length); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 493, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  __pyx_t_4 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_5))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_5);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_5, function);
      __pyx_t_4 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_5)) {
    PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_v_url, __pyx_t_2};
    __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_5, __pyx_temp+1-__pyx_t_4, 2+__pyx_t_4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 492, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_5)) {
    PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_v_url, __pyx_t_2};
    __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_5, __pyx_temp+1-__pyx_t_4, 2+__pyx_t_4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 492, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  } else
  #endif
  {
    __pyx_t_8 = PyTuple_New(2+__pyx_t_4); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 492, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    if (__pyx_t_3) {
      __Pyx_GIVEREF(__pyx_t_3); PyTuple_SET_ITEM(__pyx_t_8, 0, __pyx_t_3); __pyx_t_3 = NULL;
    }
    __Pyx_INCREF(__pyx_v_url);
    __Pyx_GIVEREF(__pyx_v_url);
    PyTuple_SET_ITEM(__pyx_t_8, 0+__pyx_t_4, __pyx_v_url);
    __Pyx_GIVEREF(__pyx_t_2);
    PyTuple_SET_ITEM(__pyx_t_8, 1+__pyx_t_4, __pyx_t_2);
    __pyx_t_2 = 0;
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_5, __pyx_t_8, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 492, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  }
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  if ((likely(PyTuple_CheckExact(__pyx_t_1))) || (PyList_CheckExact(__pyx_t_1))) {
    PyObject* sequence = __pyx_t_1;
    Py_ssize_t size = __Pyx_PySequence_SIZE(sequence);
    if (unlikely(size != 5)) {
      if (size > 5) __Pyx_RaiseTooManyValuesError(5);
      else if (size >= 0) __Pyx_RaiseNeedMoreValuesError(size);
      __PYX_ERR(0, 492, __pyx_L1_error)
    }
    #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    if (likely(PyTuple_CheckExact(sequence))) {
      __pyx_t_5 = PyTuple_GET_ITEM(sequence, 0); 
      __pyx_t_8 = PyTuple_GET_ITEM(sequence, 1); 
      __pyx_t_2 = PyTuple_GET_ITEM(sequence, 2); 
      __pyx_t_3 = PyTuple_GET_ITEM(sequence, 3); 
      __pyx_t_9 = PyTuple_GET_ITEM(sequence, 4); 
    } else {
      __pyx_t_5 = PyList_GET_ITEM(sequence, 0); 
      __pyx_t_8 = PyList_GET_ITEM(sequence, 1); 
      __pyx_t_2 = PyList_GET_ITEM(sequence, 2); 
      __pyx_t_3 = PyList_GET_ITEM(sequence, 3); 
      __pyx_t_9 = PyList_GET_ITEM(sequence, 4); 
    }
    __Pyx_INCREF(__pyx_t_5);
    __Pyx_INCREF(__pyx_t_8);
    __Pyx_INCREF(__pyx_t_2);
    __Pyx_INCREF(__pyx_t_3);
    __Pyx_INCREF(__pyx_t_9);
    #else
    {
      Py_ssize_t i;
      PyObject** temps[5] = {&__pyx_t_5,&__pyx_t_8,&__pyx_t_2,&__pyx_t_3,&__pyx_t_9};
      for (i=0; i < 5; i++) {
        PyObject* item = PySequence_ITEM(sequence, i); if (unlikely(!item)) __PYX_ERR(0, 492, __pyx_L1_error)
        __Pyx_GOTREF(item);
        *(temps[i]) = item;
      }
    }
    #endif
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  } else {
    Py_ssize_t index = -1;
    PyObject** temps[5] = {&__pyx_t_5,&__pyx_t_8,&__pyx_t_2,&__pyx_t_3,&__pyx_t_9};
    __pyx_t_12 = PyObject_GetIter(__pyx_t_1); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 492, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_12);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_13 = Py_TYPE(__pyx_t_12)->tp_iternext;
    for (index=0; index < 5; index++) {
      PyObject* item = __pyx_t_13(__pyx_t_12); if (unlikely(!item)) goto __pyx_L5_unpacking_failed;
      __Pyx_GOTREF(item);
      *(temps[index]) = item;
    }
    if (__Pyx_IternextUnpackEndCheck(__pyx_t_13(__pyx_t_12), 5) < 0) __PYX_ERR(0, 492, __pyx_L1_error)
    __pyx_t_13 = NULL;
    __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
    goto __pyx_L6_unpacking_done;
    __pyx_L5_unpacking_failed:;
    __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
    __pyx_t_13 = NULL;
    if (__Pyx_IterFinish() == 0) __Pyx_RaiseNeedMoreValuesError(index);
    __PYX_ERR(0, 492, __pyx_L1_error)
    __pyx_L6_unpacking_done:;
  }

  /* "KakaoChat/kakao.py":492
 *     url = f"{ADDRESS}?mode=list&srSearchKey=&srSearchVal={quote(keyword.strip())}&articleLimit={length}&article.offset=0"
 * 
 *     ids, posts, dates, writers, noticeLength = parseNotices(             # <<<<<<<<<<<<<<
 *         url, length
 *     )  # Parse notices
 */
  __pyx_v_ids = __pyx_t_5;
  __pyx_t_5 = 0;
  __pyx_v_posts = __pyx_t_8;
  __pyx_t_8 = 0;
  __pyx_v_dates = __pyx_t_2;
  __pyx_t_2 = 0;
  __pyx_v_writers = __pyx_t_3;
  __pyx_t_3 = 0;
  __pyx_v_noticeLength = __pyx_t_9;
  __pyx_t_9 = 0;

  /* "KakaoChat/kakao.py":495
 *         url, length
 *     )  # Parse notices
 *     if noticeLength == 0:             # <<<<<<<<<<<<<<
 *         return JSONResponse(
 *             content={
 */
  __pyx_t_1 = __Pyx_PyInt_EqObjC(__pyx_v_noticeLength, __pyx_int_0, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 495, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_6 < 0)) __PYX_ERR(0, 495, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (__pyx_t_6) {

    /* "KakaoChat/kakao.py":496
 *     )  # Parse notices
 *     if noticeLength == 0:
 *         return JSONResponse(             # <<<<<<<<<<<<<<
 *             content={
 *                 "version": "2.0",
 */
    __Pyx_XDECREF(__pyx_r);
    __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_JSONResponse); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 496, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);

    /* "KakaoChat/kakao.py":497
 *     if noticeLength == 0:
 *         return JSONResponse(
 *             content={             # <<<<<<<<<<<<<<
 *                 "version": "2.0",
 *                 "template": {
 */
    __pyx_t_9 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 497, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_9);

    /* "KakaoChat/kakao.py":498
 *         return JSONResponse(
 *             content={
 *                 "version": "2.0",             # <<<<<<<<<<<<<<
 *                 "template": {
 *                     "outputs": [{"simpleText": {"text": f"{keyword}   ."}}],
 */
    __pyx_t_3 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 498, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_version, __pyx_kp_u_2_0) < 0) __PYX_ERR(0, 498, __pyx_L1_error)

    /* "KakaoChat/kakao.py":500
 *                 "version": "2.0",
 *                 "template": {
 *                     "outputs": [{"simpleText": {"text": f"{keyword}   ."}}],             # <<<<<<<<<<<<<<
 *                 },
 *             }
 */
    __pyx_t_2 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 500, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_8 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 500, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __pyx_t_5 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 500, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_12 = __Pyx_PyObject_FormatSimple(__pyx_v_keyword, __pyx_empty_unicode); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 500, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_12);
    __pyx_t_14 = __Pyx_PyUnicode_Concat(__pyx_t_12, __pyx_kp_u__44); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 500, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_14);
    __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
    if (PyDict_SetItem(__pyx_t_5, __pyx_n_u_text, __pyx_t_14) < 0) __PYX_ERR(0, 500, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
    if (PyDict_SetItem(__pyx_t_8, __pyx_n_u_simpleText, __pyx_t_5) < 0) __PYX_ERR(0, 500, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_5 = PyList_New(1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 500, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_GIVEREF(__pyx_t_8);
    PyList_SET_ITEM(__pyx_t_5, 0, __pyx_t_8);
    __pyx_t_8 = 0;
    if (PyDict_SetItem(__pyx_t_2, __pyx_n_u_outputs, __pyx_t_5) < 0) __PYX_ERR(0, 500, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_template, __pyx_t_2) < 0) __PYX_ERR(0, 498, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    if (PyDict_SetItem(__pyx_t_9, __pyx_n_s_content, __pyx_t_3) < 0) __PYX_ERR(0, 497, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

    /* "KakaoChat/kakao.py":496
 *     )  # Parse notices
 *     if noticeLength == 0:
 *         return JSONResponse(             # <<<<<<<<<<<<<<
 *             content={
 *                 "version": "2.0",
 */
    __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_empty_tuple, __pyx_t_9); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 496, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
    __pyx_r = __pyx_t_3;
    __pyx_t_3 = 0;
    goto __pyx_L0;

    /* "KakaoChat/kakao.py":495
 *         url, length
 *     )  # Parse notices
 *     if noticeLength == 0:             # <<<<<<<<<<<<<<
 *         return JSONResponse(
 *             content={
 */
  }

  /* "KakaoChat/kakao.py":504
 *             }
 *         )
 *     notices = []             # <<<<<<<<<<<<<<
 * 
 *     for i in range(noticeLength):
 */
  __pyx_t_3 = PyList_New(0); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 504, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_v_notices = ((PyObject*)__pyx_t_3);
  __pyx_t_3 = 0;

  /* "KakaoChat/kakao.py":506
 *     notices = []
 * 
 *     for i in range(noticeLength):             # <<<<<<<<<<<<<<
 *         postDate = dates[i].text(strip=True)
 *         postTitle = posts[i].text(strip=True)
 */
  __pyx_t_3 = __Pyx_PyObject_CallOneArg(__pyx_builtin_range, __pyx_v_noticeLength); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 506, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (likely(PyList_CheckExact(__pyx_t_3)) || PyTuple_CheckExact(__pyx_t_3)) {
    __pyx_t_9 = __pyx_t_3; __Pyx_INCREF(__pyx_t_9); __pyx_t_10 = 0;
    __pyx_t_15 = NULL;
  } else {
    __pyx_t_10 = -1; __pyx_t_9 = PyObject_GetIter(__pyx_t_3); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 506, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_9);
    __pyx_t_15 = Py_TYPE(__pyx_t_9)->tp_iternext; if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 506, __pyx_L1_error)
  }
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  for (;;) {
    if (likely(!__pyx_t_15)) {
      if (likely(PyList_CheckExact(__pyx_t_9))) {
        if (__pyx_t_10 >= PyList_GET_SIZE(__pyx_t_9)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_3 = PyList_GET_ITEM(__pyx_t_9, __pyx_t_10); __Pyx_INCREF(__pyx_t_3); __pyx_t_10++; if (unlikely(0 < 0)) __PYX_ERR(0, 506, __pyx_L1_error)
        #else
        __pyx_t_3 = PySequence_ITEM(__pyx_t_9, __pyx_t_10); __pyx_t_10++; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 506, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        #endif
      } else {
        if (__pyx_t_10 >= PyTuple_GET_SIZE(__pyx_t_9)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_3 = PyTuple_GET_ITEM(__pyx_t_9, __pyx_t_10); __Pyx_INCREF(__pyx_t_3); __pyx_t_10++; if (unlikely(0 < 0)) __PYX_ERR(0, 506, __pyx_L1_error)
        #else
        __pyx_t_3 = PySequence_ITEM(__pyx_t_9, __pyx_t_10); __pyx_t_10++; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 506, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        #endif
      }
    } else {
      __pyx_t_3 = __pyx_t_15(__pyx_t_9);
      if (unlikely(!__pyx_t_3)) {
        PyObject* exc_type = PyErr_Occurred();
        if (exc_type) {
          if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
          else __PYX_ERR(0, 506, __pyx_L1_error)
        }
        break;
      }
      __Pyx_GOTREF(__pyx_t_3);
    }
    __Pyx_XDECREF_SET(__pyx_v_i, __pyx_t_3);
    __pyx_t_3 = 0;

    /* "KakaoChat/kakao.py":507
 * 
 *     for i in range(noticeLength):
 *         postDate = dates[i].text(strip=True)             # <<<<<<<<<<<<<<
 *         postTitle = posts[i].text(strip=True)
 *         postId = ids[i].text(strip=True)
 */
    __pyx_t_3 = __Pyx_PyObject_GetItem(__pyx_v_dates, __pyx_v_i); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 507, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_text); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 507, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_3 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 507, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_strip, Py_True) < 0) __PYX_ERR(0, 507, __pyx_L1_error)
    __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_empty_tuple, __pyx_t_3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 507, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_XDECREF_SET(__pyx_v_postDate, __pyx_t_2);
    __pyx_t_2 = 0;

    /* "KakaoChat/kakao.py":508
 *     for i in range(noticeLength):
 *         postDate = dates[i].text(strip=True)
 *         postTitle = posts[i].text(strip=True)             # <<<<<<<<<<<<<<
 *         postId = ids[i].text(strip=True)
 *         postLink = ADDRESS + posts[i].attributes["href"]
 */
    __pyx_t_2 = __Pyx_PyObject_GetItem(__pyx_v_posts, __pyx_v_i); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 508, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_text); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 508, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 508, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_strip, Py_True) < 0) __PYX_ERR(0, 508, __pyx_L1_error)
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_empty_tuple, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 508, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_XDECREF_SET(__pyx_v_postTitle, __pyx_t_1);
    __pyx_t_1 = 0;

    /* "KakaoChat/kakao.py":509
 *         postDate = dates[i].text(strip=True)
 *         postTitle = posts[i].text(strip=True)
 *         postId = ids[i].text(strip=True)             # <<<<<<<<<<<<<<
 *         postLink = ADDRESS + posts[i].attributes["href"]
 *         postWriter = writers[i].text(strip=False)
 */
    __pyx_t_1 = __Pyx_PyObject_GetItem(__pyx_v_ids, __pyx_v_i); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 509, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_text); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 509, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 509, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_strip, Py_True) < 0) __PYX_ERR(0, 509, __pyx_L1_error)
    __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_empty_tuple, __pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 509, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_XDECREF_SET(__pyx_v_postId, __pyx_t_3);
    __pyx_t_3 = 0;

    /* "KakaoChat/kakao.py":510
 *         postTitle = posts[i].text(strip=True)
 *         postId = ids[i].text(strip=True)
 *         postLink = ADDRESS + posts[i].attributes["href"]             # <<<<<<<<<<<<<<
 *         postWriter = writers[i].text(strip=False)
 * 
 */
    __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_ADDRESS); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 510, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_1 = __Pyx_PyObject_GetItem(__pyx_v_posts, __pyx_v_i); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 510, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_attributes); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 510, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = __Pyx_PyObject_Dict_GetItem(__pyx_t_2, __pyx_n_u_href); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 510, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = PyNumber_Add(__pyx_t_3, __pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 510, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_XDECREF_SET(__pyx_v_postLink, __pyx_t_2);
    __pyx_t_2 = 0;

    /* "KakaoChat/kakao.py":511
 *         postId = ids[i].text(strip=True)
 *         postLink = ADDRESS + posts[i].attributes["href"]
 *         postWriter = writers[i].text(strip=False)             # <<<<<<<<<<<<<<
 * 
 *         data = makeJSONwithDate(postId, postTitle, postDate, postLink, postWriter)
 */
    __pyx_t_2 = __Pyx_PyObject_GetItem(__pyx_v_writers, __pyx_v_i); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 511, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_text); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 511, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 511, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_strip, Py_False) < 0) __PYX_ERR(0, 511, __pyx_L1_error)
    __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_empty_tuple, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 511, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_XDECREF_SET(__pyx_v_postWriter, __pyx_t_3);
    __pyx_t_3 = 0;

    /* "KakaoChat/kakao.py":513
 *         postWriter = writers[i].text(strip=False)
 * 
 *         data = makeJSONwithDate(postId, postTitle, postDate, postLink, postWriter)             # <<<<<<<<<<<<<<
 *         notices.append(data)
 * 
 */
    __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_makeJSONwithDate); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 513, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_1 = NULL;
    __pyx_t_4 = 0;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
      __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_2);
      if (likely(__pyx_t_1)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
        __Pyx_INCREF(__pyx_t_1);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_2, function);
        __pyx_t_4 = 1;
      }
    }
    #if CYTHON_FAST_PYCALL
    if (PyFunction_Check(__pyx_t_2)) {
      PyObject *__pyx_temp[6] = {__pyx_t_1, __pyx_v_postId, __pyx_v_postTitle, __pyx_v_postDate, __pyx_v_postLink, __pyx_v_postWriter};
      __pyx_t_3 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_4, 5+__pyx_t_4); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 513, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_GOTREF(__pyx_t_3);
    } else
    #endif
    #if CYTHON_FAST_PYCCALL
    if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
      PyObject *__pyx_temp[6] = {__pyx_t_1, __pyx_v_postId, __pyx_v_postTitle, __pyx_v_postDate, __pyx_v_postLink, __pyx_v_postWriter};
      __pyx_t_3 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_4, 5+__pyx_t_4); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 513, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_GOTREF(__pyx_t_3);
    } else
    #endif
    {
      __pyx_t_5 = PyTuple_New(5+__pyx_t_4); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 513, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_5);
      if (__pyx_t_1) {
        __Pyx_GIVEREF(__pyx_t_1); PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_1); __pyx_t_1 = NULL;
      }
      __Pyx_INCREF(__pyx_v_postId);
      __Pyx_GIVEREF(__pyx_v_postId);
      PyTuple_SET_ITEM(__pyx_t_5, 0+__pyx_t_4, __pyx_v_postId);
      __Pyx_INCREF(__pyx_v_postTitle);
      __Pyx_GIVEREF(__pyx_v_postTitle);
      PyTuple_SET_ITEM(__pyx_t_5, 1+__pyx_t_4, __pyx_v_postTitle);
      __Pyx_INCREF(__pyx_v_postDate);
      __Pyx_GIVEREF(__pyx_v_postDate);
      PyTuple_SET_ITEM(__pyx_t_5, 2+__pyx_t_4, __pyx_v_postDate);
      __Pyx_INCREF(__pyx_v_postLink);
      __Pyx_GIVEREF(__pyx_v_postLink);
      PyTuple_SET_ITEM(__pyx_t_5, 3+__pyx_t_4, __pyx_v_postLink);
      __Pyx_INCREF(__pyx_v_postWriter);
      __Pyx_GIVEREF(__pyx_v_postWriter);
      PyTuple_SET_ITEM(__pyx_t_5, 4+__pyx_t_4, __pyx_v_postWriter);
      __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_5, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 513, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    }
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_XDECREF_SET(__pyx_v_data, __pyx_t_3);
    __pyx_t_3 = 0;

    /* "KakaoChat/kakao.py":514
 * 
 *         data = makeJSONwithDate(postId, postTitle, postDate, postLink, postWriter)
 *         notices.append(data)             # <<<<<<<<<<<<<<
 * 
 *     updateLastNotice(db, user_id, int(ids[0].text(strip=True)))
 */
    __pyx_t_16 = __Pyx_PyList_Append(__pyx_v_notices, __pyx_v_data); if (unlikely(__pyx_t_16 == ((int)-1))) __PYX_ERR(0, 514, __pyx_L1_error)

    /* "KakaoChat/kakao.py":506
 *     notices = []
 * 
 *     for i in range(noticeLength):             # <<<<<<<<<<<<<<
 *         postDate = dates[i].text(strip=True)
 *         postTitle = posts[i].text(strip=True)
 */
  }
  __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;

  /* "KakaoChat/kakao.py":516
 *         notices.append(data)
 * 
 *     updateLastNotice(db, user_id, int(ids[0].text(strip=True)))             # <<<<<<<<<<<<<<
 * 
 *     data = {
 */
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_updateLastNotice); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 516, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_v_ids, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 516, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_text); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 516, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 516, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_strip, Py_True) < 0) __PYX_ERR(0, 516, __pyx_L1_error)
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_5, __pyx_empty_tuple, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 516, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyNumber_Int(__pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 516, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = NULL;
  __pyx_t_4 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
    __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_3);
    if (likely(__pyx_t_1)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_1);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_3, function);
      __pyx_t_4 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_3)) {
    PyObject *__pyx_temp[4] = {__pyx_t_1, __pyx_v_db, __pyx_v_user_id, __pyx_t_2};
    __pyx_t_9 = __Pyx_PyFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_4, 3+__pyx_t_4); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 516, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_GOTREF(__pyx_t_9);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_3)) {
    PyObject *__pyx_temp[4] = {__pyx_t_1, __pyx_v_db, __pyx_v_user_id, __pyx_t_2};
    __pyx_t_9 = __Pyx_PyCFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_4, 3+__pyx_t_4); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 516, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_GOTREF(__pyx_t_9);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  } else
  #endif
  {
    __pyx_t_5 = PyTuple_New(3+__pyx_t_4); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 516, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    if (__pyx_t_1) {
      __Pyx_GIVEREF(__pyx_t_1); PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_1); __pyx_t_1 = NULL;
    }
    __Pyx_INCREF(__pyx_v_db);
    __Pyx_GIVEREF(__pyx_v_db);
    PyTuple_SET_ITEM(__pyx_t_5, 0+__pyx_t_4, __pyx_v_db);
    __Pyx_INCREF(__pyx_v_user_id);
    __Pyx_GIVEREF(__pyx_v_user_id);
    PyTuple_SET_ITEM(__pyx_t_5, 1+__pyx_t_4, __pyx_v_user_id);
    __Pyx_GIVEREF(__pyx_t_2);
    PyTuple_SET_ITEM(__pyx_t_5, 2+__pyx_t_4, __pyx_t_2);
    __pyx_t_2 = 0;
    __pyx_t_9 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_t_5, NULL); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 516, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_9);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  }
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;

  /* "KakaoChat/kakao.py":519
 * 
 *     data = {
 *         "version": "2.0",             # <<<<<<<<<<<<<<
 *         "template": {
 *             "outputs": [
 */
  __pyx_t_9 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 519, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_9);
  if (PyDict_SetItem(__pyx_t_9, __pyx_n_u_version, __pyx_kp_u_2_0) < 0) __PYX_ERR(0, 519, __pyx_L1_error)

  /* "KakaoChat/kakao.py":521
 *         "version": "2.0",
 *         "template": {
 *             "outputs": [             # <<<<<<<<<<<<<<
 *                 {
 *                     "listCard": {
 */
  __pyx_t_3 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 521, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);

  /* "KakaoChat/kakao.py":523
 *             "outputs": [
 *                 {
 *                     "listCard": {             # <<<<<<<<<<<<<<
 *                         "header": {"title": f"{keyword[:12]} "},
 *                         "items": notices[:5],
 */
  __pyx_t_5 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 523, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);

  /* "KakaoChat/kakao.py":524
 *                 {
 *                     "listCard": {
 *                         "header": {"title": f"{keyword[:12]} "},             # <<<<<<<<<<<<<<
 *                         "items": notices[:5],
 *                         "buttons": [
 */
  __pyx_t_2 = __Pyx_PyDict_NewPresized(3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 524, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 524, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_8 = __Pyx_PyObject_GetSlice(__pyx_v_keyword, 0, 12, NULL, NULL, &__pyx_slice__45, 0, 1, 1); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 524, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_14 = __Pyx_PyObject_FormatSimple(__pyx_t_8, __pyx_empty_unicode); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 524, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_14);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_8 = __Pyx_PyUnicode_Concat(__pyx_t_14, __pyx_kp_u__46); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 524, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u_title, __pyx_t_8) < 0) __PYX_ERR(0, 524, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_u_header, __pyx_t_1) < 0) __PYX_ERR(0, 524, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":525
 *                     "listCard": {
 *                         "header": {"title": f"{keyword[:12]} "},
 *                         "items": notices[:5],             # <<<<<<<<<<<<<<
 *                         "buttons": [
 *                             {"label": "", "action": "share"},
 */
  __pyx_t_1 = __Pyx_PyList_GetSlice(__pyx_v_notices, 0, 5); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 525, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_u_items, __pyx_t_1) < 0) __PYX_ERR(0, 524, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":527
 *                         "items": notices[:5],
 *                         "buttons": [
 *                             {"label": "", "action": "share"},             # <<<<<<<<<<<<<<
 *                             {
 *                                 "label": "" if len(notices) > 5 else " ",
 */
  __pyx_t_1 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 527, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u_label, __pyx_n_u__19) < 0) __PYX_ERR(0, 527, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u_action, __pyx_n_u_share) < 0) __PYX_ERR(0, 527, __pyx_L1_error)

  /* "KakaoChat/kakao.py":529
 *                             {"label": "", "action": "share"},
 *                             {
 *                                 "label": "" if len(notices) > 5 else " ",             # <<<<<<<<<<<<<<
 *                                 "action": "webLink",
 *                                 "webLinkUrl": f"https://www.ajou.ac.kr/kr/ajou/notice.do&?mode=list&srSearchKey=&srSearchVal={quote(keyword)}",
 */
  __pyx_t_8 = __Pyx_PyDict_NewPresized(3); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 529, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_10 = PyList_GET_SIZE(__pyx_v_notices); if (unlikely(__pyx_t_10 == ((Py_ssize_t)-1))) __PYX_ERR(0, 529, __pyx_L1_error)
  if (((__pyx_t_10 > 5) != 0)) {
    __Pyx_INCREF(__pyx_n_u__47);
    __pyx_t_14 = __pyx_n_u__47;
  } else {
    __Pyx_INCREF(__pyx_kp_u__48);
    __pyx_t_14 = __pyx_kp_u__48;
  }
  if (PyDict_SetItem(__pyx_t_8, __pyx_n_u_label, __pyx_t_14) < 0) __PYX_ERR(0, 529, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
  if (PyDict_SetItem(__pyx_t_8, __pyx_n_u_action, __pyx_n_u_webLink) < 0) __PYX_ERR(0, 529, __pyx_L1_error)

  /* "KakaoChat/kakao.py":531
 *                                 "label": "" if len(notices) > 5 else " ",
 *                                 "action": "webLink",
 *                                 "webLinkUrl": f"https://www.ajou.ac.kr/kr/ajou/notice.do&?mode=list&srSearchKey=&srSearchVal={quote(keyword)}",             # <<<<<<<<<<<<<<
 *                             },
 *                         ],
 */
  __Pyx_GetModuleGlobalName(__pyx_t_12, __pyx_n_s_quote); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 531, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_12);
  __pyx_t_17 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_12))) {
    __pyx_t_17 = PyMethod_GET_SELF(__pyx_t_12);
    if (likely(__pyx_t_17)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_12);
      __Pyx_INCREF(__pyx_t_17);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_12, function);
    }
  }
  __pyx_t_14 = (__pyx_t_17) ? __Pyx_PyObject_Call2Args(__pyx_t_12, __pyx_t_17, __pyx_v_keyword) : __Pyx_PyObject_CallOneArg(__pyx_t_12, __pyx_v_keyword);
  __Pyx_XDECREF(__pyx_t_17); __pyx_t_17 = 0;
  if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 531, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_14);
  __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
  __pyx_t_12 = __Pyx_PyObject_FormatSimple(__pyx_t_14, __pyx_empty_unicode); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 531, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_12);
  __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
  __pyx_t_14 = __Pyx_PyUnicode_Concat(__pyx_kp_u_https_www_ajou_ac_kr_kr_ajou_not_3, __pyx_t_12); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 531, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_14);
  __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
  if (PyDict_SetItem(__pyx_t_8, __pyx_n_u_webLinkUrl, __pyx_t_14) < 0) __PYX_ERR(0, 529, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

  /* "KakaoChat/kakao.py":526
 *                         "header": {"title": f"{keyword[:12]} "},
 *                         "items": notices[:5],
 *                         "buttons": [             # <<<<<<<<<<<<<<
 *                             {"label": "", "action": "share"},
 *                             {
 */
  __pyx_t_14 = PyList_New(2); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 526, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_14);
  __Pyx_GIVEREF(__pyx_t_1);
  PyList_SET_ITEM(__pyx_t_14, 0, __pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_8);
  PyList_SET_ITEM(__pyx_t_14, 1, __pyx_t_8);
  __pyx_t_1 = 0;
  __pyx_t_8 = 0;
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_u_buttons, __pyx_t_14) < 0) __PYX_ERR(0, 524, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
  if (PyDict_SetItem(__pyx_t_5, __pyx_n_u_listCard, __pyx_t_2) < 0) __PYX_ERR(0, 523, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "KakaoChat/kakao.py":521
 *         "version": "2.0",
 *         "template": {
 *             "outputs": [             # <<<<<<<<<<<<<<
 *                 {
 *                     "listCard": {
 */
  __pyx_t_2 = PyList_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 521, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_5);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_t_5);
  __pyx_t_5 = 0;
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_outputs, __pyx_t_2) < 0) __PYX_ERR(0, 521, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "KakaoChat/kakao.py":538
 *             ],
 *             "quickReplies": [
 *                 {"messageText": " ", "action": "message", "label": " "},             # <<<<<<<<<<<<<<
 *                 {"messageText": " ", "action": "message", "label": " "},
 *                 {"messageText": " ", "action": "message", "label": " "},
 */
  __pyx_t_2 = __Pyx_PyDict_NewPresized(3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 538, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_u_messageText, __pyx_kp_u__49) < 0) __PYX_ERR(0, 538, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_u_action, __pyx_n_u_message) < 0) __PYX_ERR(0, 538, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_u_label, __pyx_kp_u__49) < 0) __PYX_ERR(0, 538, __pyx_L1_error)

  /* "KakaoChat/kakao.py":539
 *             "quickReplies": [
 *                 {"messageText": " ", "action": "message", "label": " "},
 *                 {"messageText": " ", "action": "message", "label": " "},             # <<<<<<<<<<<<<<
 *                 {"messageText": " ", "action": "message", "label": " "},
 *             ],
 */
  __pyx_t_5 = __Pyx_PyDict_NewPresized(3); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 539, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (PyDict_SetItem(__pyx_t_5, __pyx_n_u_messageText, __pyx_kp_u__50) < 0) __PYX_ERR(0, 539, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_5, __pyx_n_u_action, __pyx_n_u_message) < 0) __PYX_ERR(0, 539, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_5, __pyx_n_u_label, __pyx_kp_u__50) < 0) __PYX_ERR(0, 539, __pyx_L1_error)

  /* "KakaoChat/kakao.py":540
 *                 {"messageText": " ", "action": "message", "label": " "},
 *                 {"messageText": " ", "action": "message", "label": " "},
 *                 {"messageText": " ", "action": "message", "label": " "},             # <<<<<<<<<<<<<<
 *             ],
 *         },
 */
  __pyx_t_14 = __Pyx_PyDict_NewPresized(3); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 540, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_14);
  if (PyDict_SetItem(__pyx_t_14, __pyx_n_u_messageText, __pyx_kp_u__51) < 0) __PYX_ERR(0, 540, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_14, __pyx_n_u_action, __pyx_n_u_message) < 0) __PYX_ERR(0, 540, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_14, __pyx_n_u_label, __pyx_kp_u__51) < 0) __PYX_ERR(0, 540, __pyx_L1_error)

  /* "KakaoChat/kakao.py":537
 *                 }
 *             ],
 *             "quickReplies": [             # <<<<<<<<<<<<<<
 *                 {"messageText": " ", "action": "message", "label": " "},
 *                 {"messageText": " ", "action": "message", "label": " "},
 */
  __pyx_t_8 = PyList_New(3); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 537, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_GIVEREF(__pyx_t_2);
  PyList_SET_ITEM(__pyx_t_8, 0, __pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_5);
  PyList_SET_ITEM(__pyx_t_8, 1, __pyx_t_5);
  __Pyx_GIVEREF(__pyx_t_14);
  PyList_SET_ITEM(__pyx_t_8, 2, __pyx_t_14);
  __pyx_t_2 = 0;
  __pyx_t_5 = 0;
  __pyx_t_14 = 0;
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_quickReplies, __pyx_t_8) < 0) __PYX_ERR(0, 521, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  if (PyDict_SetItem(__pyx_t_9, __pyx_n_u_template, __pyx_t_3) < 0) __PYX_ERR(0, 519, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_XDECREF_SET(__pyx_v_data, __pyx_t_9);
  __pyx_t_9 = 0;

  /* "KakaoChat/kakao.py":545
 *     }
 * 
 *     return JSONResponse(content=data)             # <<<<<<<<<<<<<<
 * 
 * 
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_GetModuleGlobalName(__pyx_t_9, __pyx_n_s_JSONResponse); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 545, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_9);
  __pyx_t_3 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 545, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_content, __pyx_v_data) < 0) __PYX_ERR(0, 545, __pyx_L1_error)
  __pyx_t_8 = __Pyx_PyObject_Call(__pyx_t_9, __pyx_empty_tuple, __pyx_t_3); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 545, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_r = __pyx_t_8;
  __pyx_t_8 = 0;
  goto __pyx_L0;

  /* "KakaoChat/kakao.py":461
 * 
 * @application.post("/search")
 * def searchNotice(content: Dict, db: Session = Depends(get_db)):             # <<<<<<<<<<<<<<
 *     """    .  type: simpleText | ListCard"""
 *     user_id = content["userRequest"]["user"]["id"]  # user Id
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_XDECREF(__pyx_t_9);
  __Pyx_XDECREF(__pyx_t_12);
  __Pyx_XDECREF(__pyx_t_14);
  __Pyx_XDECREF(__pyx_t_17);
  __Pyx_AddTraceback("KakaoChat.kakao.searchNotice", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_user_id);
  __Pyx_XDECREF(__pyx_v_keyword);
  __Pyx_XDECREF(__pyx_v_url);
  __Pyx_XDECREF(__pyx_v_ids);
  __Pyx_XDECREF(__pyx_v_posts);
  __Pyx_XDECREF(__pyx_v_dates);
  __Pyx_XDECREF(__pyx_v_writers);
  __Pyx_XDECREF(__pyx_v_noticeLength);
  __Pyx_XDECREF(__pyx_v_notices);
  __Pyx_XDECREF(__pyx_v_i);
  __Pyx_XDECREF(__pyx_v_postDate);
  __Pyx_XDECREF(__pyx_v_postTitle);
  __Pyx_XDECREF(__pyx_v_postId);
  __Pyx_XDECREF(__pyx_v_postLink);
  __Pyx_XDECREF(__pyx_v_postWriter);
  __Pyx_XDECREF(__pyx_v_data);
  __Pyx_XDECREF(__pyx_v_content);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "KakaoChat/kakao.py":549
 * 
 * @application.post("/message")
 * def message(content: Dict, db: Session = Depends(get_db)):             # <<<<<<<<<<<<<<
 *     """/    route |  type: ListCard """
 *     user_id = content["userRequest"]["user"]["id"]  # user Id
 */

static PyObject *__pyx_pf_9KakaoChat_5kakao_53__defaults__(CYTHON_UNUSED PyObject *__pyx_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__defaults__", 0);
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = PyTuple_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 549, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__Pyx_CyFunction_Defaults(__pyx_defaults3, __pyx_self)->__pyx_arg_db);
  __Pyx_GIVEREF(__Pyx_CyFunction_Defaults(__pyx_defaults3, __pyx_self)->__pyx_arg_db);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __Pyx_CyFunction_Defaults(__pyx_defaults3, __pyx_self)->__pyx_arg_db);
  __pyx_t_2 = PyTuple_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 549, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_1);
  __Pyx_INCREF(Py_None);
  __Pyx_GIVEREF(Py_None);
  PyTuple_SET_ITEM(__pyx_t_2, 1, Py_None);
  __pyx_t_1 = 0;
  __pyx_r = __pyx_t_2;
  __pyx_t_2 = 0;
  goto __pyx_L0;

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_AddTraceback("KakaoChat.kakao.__defaults__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* Python wrapper */
static PyObject *__pyx_pw_9KakaoChat_5kakao_44message(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_9KakaoChat_5kakao_43message[] = "\354\226\264\354\240\234/\354\230\244\353\212\230 \352\263\265\354\247\200 \353\266\210\353\237\254\354\230\244\352\270\260 \354\234\204\355\225\234 route | \353\251\224\354\213\234\354\247\200 type: ListCard ";
static PyMethodDef __pyx_mdef_9KakaoChat_5kakao_44message = {"message", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_9KakaoChat_5kakao_44message, METH_VARARGS|METH_KEYWORDS, __pyx_doc_9KakaoChat_5kakao_43message};
static PyObject *__pyx_pw_9KakaoChat_5kakao_44message(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_content = 0;
  PyObject *__pyx_v_db = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("message (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_content,&__pyx_n_s_db,0};
    PyObject* values[2] = {0,0};
    __pyx_defaults3 *__pyx_dynamic_args = __Pyx_CyFunction_Defaults(__pyx_defaults3, __pyx_self);
    values[1] = __pyx_dynamic_args->__pyx_arg_db;
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_content)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_db);
          if (value) { values[1] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "message") < 0)) __PYX_ERR(0, 549, __pyx_L3_error)
      }
    } else {
      switch (PyTuple_GET_SIZE(__pyx_args)) {
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        break;
        default: goto __pyx_L5_argtuple_error;
      }
    }
    __pyx_v_content = values[0];
    __pyx_v_db = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("message", 0, 1, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 549, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("KakaoChat.kakao.message", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_9KakaoChat_5kakao_43message(__pyx_self, __pyx_v_content, __pyx_v_db);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_9KakaoChat_5kakao_43message(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_content, PyObject *__pyx_v_db) {
  PyObject *__pyx_v_user_id = NULL;
  PyObject *__pyx_v_when = NULL;
  PyObject *__pyx_v_now = NULL;
  PyObject *__pyx_v_response_data = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_t_4;
  PyObject *__pyx_t_5 = NULL;
  int __pyx_t_6;
  int __pyx_t_7;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("message", 0);

  /* "KakaoChat/kakao.py":551
 * def message(content: Dict, db: Session = Depends(get_db)):
 *     """/    route |  type: ListCard """
 *     user_id = content["userRequest"]["user"]["id"]  # user Id             # <<<<<<<<<<<<<<
 *     checkUserDB(db, user_id)
 *     print(">>> /message")
 */
  __pyx_t_1 = __Pyx_PyObject_Dict_GetItem(__pyx_v_content, __pyx_n_u_userRequest); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 551, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_Dict_GetItem(__pyx_t_1, __pyx_n_u_user); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 551, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_Dict_GetItem(__pyx_t_2, __pyx_n_u_id); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 551, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_user_id = __pyx_t_1;
  __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":552
 *     """/    route |  type: ListCard """
 *     user_id = content["userRequest"]["user"]["id"]  # user Id
 *     checkUserDB(db, user_id)             # <<<<<<<<<<<<<<
 *     print(">>> /message")
 *     if not checkConnection():
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_checkUserDB); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 552, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  __pyx_t_4 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
      __pyx_t_4 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_v_db, __pyx_v_user_id};
    __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_4, 2+__pyx_t_4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 552, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_1);
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_v_db, __pyx_v_user_id};
    __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_4, 2+__pyx_t_4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 552, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_1);
  } else
  #endif
  {
    __pyx_t_5 = PyTuple_New(2+__pyx_t_4); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 552, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    if (__pyx_t_3) {
      __Pyx_GIVEREF(__pyx_t_3); PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_3); __pyx_t_3 = NULL;
    }
    __Pyx_INCREF(__pyx_v_db);
    __Pyx_GIVEREF(__pyx_v_db);
    PyTuple_SET_ITEM(__pyx_t_5, 0+__pyx_t_4, __pyx_v_db);
    __Pyx_INCREF(__pyx_v_user_id);
    __Pyx_GIVEREF(__pyx_v_user_id);
    PyTuple_SET_ITEM(__pyx_t_5, 1+__pyx_t_4, __pyx_v_user_id);
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_5, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 552, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":553
 *     user_id = content["userRequest"]["user"]["id"]  # user Id
 *     checkUserDB(db, user_id)
 *     print(">>> /message")             # <<<<<<<<<<<<<<
 *     if not checkConnection():
 *         return makeTimeoutMessage()
 */
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__52, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 553, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":554
 *     checkUserDB(db, user_id)
 *     print(">>> /message")
 *     if not checkConnection():             # <<<<<<<<<<<<<<
 *         return makeTimeoutMessage()
 * 
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_checkConnection); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 554, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_5 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_5)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_5);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_5) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_5) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 554, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_6 < 0)) __PYX_ERR(0, 554, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_7 = ((!__pyx_t_6) != 0);
  if (__pyx_t_7) {

    /* "KakaoChat/kakao.py":555
 *     print(">>> /message")
 *     if not checkConnection():
 *         return makeTimeoutMessage()             # <<<<<<<<<<<<<<
 * 
 *     # data = content["userRequest"]["utterance"]
 */
    __Pyx_XDECREF(__pyx_r);
    __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_makeTimeoutMessage); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 555, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_5 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
      __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_2);
      if (likely(__pyx_t_5)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
        __Pyx_INCREF(__pyx_t_5);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_2, function);
      }
    }
    __pyx_t_1 = (__pyx_t_5) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_5) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 555, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_r = __pyx_t_1;
    __pyx_t_1 = 0;
    goto __pyx_L0;

    /* "KakaoChat/kakao.py":554
 *     checkUserDB(db, user_id)
 *     print(">>> /message")
 *     if not checkConnection():             # <<<<<<<<<<<<<<
 *         return makeTimeoutMessage()
 * 
 */
  }

  /* "KakaoChat/kakao.py":558
 * 
 *     # data = content["userRequest"]["utterance"]
 *     when = content["action"]["params"]["when"]             # <<<<<<<<<<<<<<
 * 
 *     now = datetime.now()
 */
  __pyx_t_1 = __Pyx_PyObject_Dict_GetItem(__pyx_v_content, __pyx_n_u_action); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 558, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_Dict_GetItem(__pyx_t_1, __pyx_n_u_params); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 558, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_Dict_GetItem(__pyx_t_2, __pyx_n_u_when); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 558, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_when = __pyx_t_1;
  __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":560
 *     when = content["action"]["params"]["when"]
 * 
 *     now = datetime.now()             # <<<<<<<<<<<<<<
 *     if when == "today":
 *         now = now.strftime("%y.%m.%d")
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_datetime); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 560, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_now); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 560, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_5))) {
    __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_5);
    if (likely(__pyx_t_2)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
      __Pyx_INCREF(__pyx_t_2);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_5, function);
    }
  }
  __pyx_t_1 = (__pyx_t_2) ? __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_t_2) : __Pyx_PyObject_CallNoArg(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 560, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_v_now = __pyx_t_1;
  __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":561
 * 
 *     now = datetime.now()
 *     if when == "today":             # <<<<<<<<<<<<<<
 *         now = now.strftime("%y.%m.%d")
 *     elif when == "yesterday":
 */
  __pyx_t_7 = (__Pyx_PyUnicode_Equals(__pyx_v_when, __pyx_n_u_today, Py_EQ)); if (unlikely(__pyx_t_7 < 0)) __PYX_ERR(0, 561, __pyx_L1_error)
  if (__pyx_t_7) {

    /* "KakaoChat/kakao.py":562
 *     now = datetime.now()
 *     if when == "today":
 *         now = now.strftime("%y.%m.%d")             # <<<<<<<<<<<<<<
 *     elif when == "yesterday":
 *         now = now - timedelta(days=1)
 */
    __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_v_now, __pyx_n_s_strftime); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 562, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_2 = NULL;
    if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_5))) {
      __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_5);
      if (likely(__pyx_t_2)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
        __Pyx_INCREF(__pyx_t_2);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_5, function);
      }
    }
    __pyx_t_1 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_5, __pyx_t_2, __pyx_kp_u_y_m_d) : __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_kp_u_y_m_d);
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
    if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 562, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_DECREF_SET(__pyx_v_now, __pyx_t_1);
    __pyx_t_1 = 0;

    /* "KakaoChat/kakao.py":561
 * 
 *     now = datetime.now()
 *     if when == "today":             # <<<<<<<<<<<<<<
 *         now = now.strftime("%y.%m.%d")
 *     elif when == "yesterday":
 */
    goto __pyx_L4;
  }

  /* "KakaoChat/kakao.py":563
 *     if when == "today":
 *         now = now.strftime("%y.%m.%d")
 *     elif when == "yesterday":             # <<<<<<<<<<<<<<
 *         now = now - timedelta(days=1)
 *         now = now.strftime("%y.%m.%d")
 */
  __pyx_t_7 = (__Pyx_PyUnicode_Equals(__pyx_v_when, __pyx_n_u_yesterday, Py_EQ)); if (unlikely(__pyx_t_7 < 0)) __PYX_ERR(0, 563, __pyx_L1_error)
  if (__pyx_t_7) {

    /* "KakaoChat/kakao.py":564
 *         now = now.strftime("%y.%m.%d")
 *     elif when == "yesterday":
 *         now = now - timedelta(days=1)             # <<<<<<<<<<<<<<
 *         now = now.strftime("%y.%m.%d")
 * 
 */
    __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_timedelta); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 564, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_5 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 564, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    if (PyDict_SetItem(__pyx_t_5, __pyx_n_s_days, __pyx_int_1) < 0) __PYX_ERR(0, 564, __pyx_L1_error)
    __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_empty_tuple, __pyx_t_5); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 564, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_5 = PyNumber_Subtract(__pyx_v_now, __pyx_t_2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 564, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_DECREF_SET(__pyx_v_now, __pyx_t_5);
    __pyx_t_5 = 0;

    /* "KakaoChat/kakao.py":565
 *     elif when == "yesterday":
 *         now = now - timedelta(days=1)
 *         now = now.strftime("%y.%m.%d")             # <<<<<<<<<<<<<<
 * 
 *     response_data = switch(db, when, now, user_id)
 */
    __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_now, __pyx_n_s_strftime); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 565, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_1 = NULL;
    if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
      __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_2);
      if (likely(__pyx_t_1)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
        __Pyx_INCREF(__pyx_t_1);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_2, function);
      }
    }
    __pyx_t_5 = (__pyx_t_1) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_1, __pyx_kp_u_y_m_d) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_kp_u_y_m_d);
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 565, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_DECREF_SET(__pyx_v_now, __pyx_t_5);
    __pyx_t_5 = 0;

    /* "KakaoChat/kakao.py":563
 *     if when == "today":
 *         now = now.strftime("%y.%m.%d")
 *     elif when == "yesterday":             # <<<<<<<<<<<<<<
 *         now = now - timedelta(days=1)
 *         now = now.strftime("%y.%m.%d")
 */
  }
  __pyx_L4:;

  /* "KakaoChat/kakao.py":567
 *         now = now.strftime("%y.%m.%d")
 * 
 *     response_data = switch(db, when, now, user_id)             # <<<<<<<<<<<<<<
 * 
 *     return JSONResponse(content=response_data)
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_switch); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 567, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = NULL;
  __pyx_t_4 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_1)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_1);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
      __pyx_t_4 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[5] = {__pyx_t_1, __pyx_v_db, __pyx_v_when, __pyx_v_now, __pyx_v_user_id};
    __pyx_t_5 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_4, 4+__pyx_t_4); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 567, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_GOTREF(__pyx_t_5);
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[5] = {__pyx_t_1, __pyx_v_db, __pyx_v_when, __pyx_v_now, __pyx_v_user_id};
    __pyx_t_5 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_4, 4+__pyx_t_4); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 567, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_GOTREF(__pyx_t_5);
  } else
  #endif
  {
    __pyx_t_3 = PyTuple_New(4+__pyx_t_4); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 567, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    if (__pyx_t_1) {
      __Pyx_GIVEREF(__pyx_t_1); PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_1); __pyx_t_1 = NULL;
    }
    __Pyx_INCREF(__pyx_v_db);
    __Pyx_GIVEREF(__pyx_v_db);
    PyTuple_SET_ITEM(__pyx_t_3, 0+__pyx_t_4, __pyx_v_db);
    __Pyx_INCREF(__pyx_v_when);
    __Pyx_GIVEREF(__pyx_v_when);
    PyTuple_SET_ITEM(__pyx_t_3, 1+__pyx_t_4, __pyx_v_when);
    __Pyx_INCREF(__pyx_v_now);
    __Pyx_GIVEREF(__pyx_v_now);
    PyTuple_SET_ITEM(__pyx_t_3, 2+__pyx_t_4, __pyx_v_now);
    __Pyx_INCREF(__pyx_v_user_id);
    __Pyx_GIVEREF(__pyx_v_user_id);
    PyTuple_SET_ITEM(__pyx_t_3, 3+__pyx_t_4, __pyx_v_user_id);
    __pyx_t_5 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_3, NULL); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 567, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_response_data = __pyx_t_5;
  __pyx_t_5 = 0;

  /* "KakaoChat/kakao.py":569
 *     response_data = switch(db, when, now, user_id)
 * 
 *     return JSONResponse(content=response_data)             # <<<<<<<<<<<<<<
 * 
 * 
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_JSONResponse); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 569, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_2 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 569, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_content, __pyx_v_response_data) < 0) __PYX_ERR(0, 569, __pyx_L1_error)
  __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_5, __pyx_empty_tuple, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 569, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_r = __pyx_t_3;
  __pyx_t_3 = 0;
  goto __pyx_L0;

  /* "KakaoChat/kakao.py":549
 * 
 * @application.post("/message")
 * def message(content: Dict, db: Session = Depends(get_db)):             # <<<<<<<<<<<<<<
 *     """/    route |  type: ListCard """
 *     user_id = content["userRequest"]["user"]["id"]  # user Id
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_AddTraceback("KakaoChat.kakao.message", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_user_id);
  __Pyx_XDECREF(__pyx_v_when);
  __Pyx_XDECREF(__pyx_v_now);
  __Pyx_XDECREF(__pyx_v_response_data);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "KakaoChat/kakao.py":573
 * 
 * @application.post("/schedule")
 * def schedule(content: Dict, db: Session = Depends(get_db)):             # <<<<<<<<<<<<<<
 *     """MySQL DB   |  type: Carousel BasicCards """
 *     user_id = content["userRequest"]["user"]["id"]  # user Id
 */

static PyObject *__pyx_pf_9KakaoChat_5kakao_55__defaults__(CYTHON_UNUSED PyObject *__pyx_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__defaults__", 0);
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = PyTuple_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 573, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__Pyx_CyFunction_Defaults(__pyx_defaults4, __pyx_self)->__pyx_arg_db);
  __Pyx_GIVEREF(__Pyx_CyFunction_Defaults(__pyx_defaults4, __pyx_self)->__pyx_arg_db);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __Pyx_CyFunction_Defaults(__pyx_defaults4, __pyx_self)->__pyx_arg_db);
  __pyx_t_2 = PyTuple_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 573, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_1);
  __Pyx_INCREF(Py_None);
  __Pyx_GIVEREF(Py_None);
  PyTuple_SET_ITEM(__pyx_t_2, 1, Py_None);
  __pyx_t_1 = 0;
  __pyx_r = __pyx_t_2;
  __pyx_t_2 = 0;
  goto __pyx_L0;

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_AddTraceback("KakaoChat.kakao.__defaults__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* Python wrapper */
static PyObject *__pyx_pw_9KakaoChat_5kakao_46schedule(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_9KakaoChat_5kakao_45schedule[] = "MySQL DB \355\225\231\354\202\254\354\235\274\354\240\225 \353\266\210\353\237\254\354\230\244\352\270\260 | \353\251\224\354\213\234\354\247\200 type: Carousel BasicCards ";
static PyMethodDef __pyx_mdef_9KakaoChat_5kakao_46schedule = {"schedule", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_9KakaoChat_5kakao_46schedule, METH_VARARGS|METH_KEYWORDS, __pyx_doc_9KakaoChat_5kakao_45schedule};
static PyObject *__pyx_pw_9KakaoChat_5kakao_46schedule(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_content = 0;
  PyObject *__pyx_v_db = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("schedule (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_content,&__pyx_n_s_db,0};
    PyObject* values[2] = {0,0};
    __pyx_defaults4 *__pyx_dynamic_args = __Pyx_CyFunction_Defaults(__pyx_defaults4, __pyx_self);
    values[1] = __pyx_dynamic_args->__pyx_arg_db;
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_content)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_db);
          if (value) { values[1] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "schedule") < 0)) __PYX_ERR(0, 573, __pyx_L3_error)
      }
    } else {
      switch (PyTuple_GET_SIZE(__pyx_args)) {
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        break;
        default: goto __pyx_L5_argtuple_error;
      }
    }
    __pyx_v_content = values[0];
    __pyx_v_db = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("schedule", 0, 1, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 573, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("KakaoChat.kakao.schedule", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_9KakaoChat_5kakao_45schedule(__pyx_self, __pyx_v_content, __pyx_v_db);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_9KakaoChat_5kakao_45schedule(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_content, PyObject *__pyx_v_db) {
  PyObject *__pyx_v_user_id = NULL;
  PyObject *__pyx_v_cards = NULL;
  PyObject *__pyx_v_append = NULL;
  PyObject *__pyx_v_scheds = NULL;
  PyObject *__pyx_v_sched = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_t_4;
  PyObject *__pyx_t_5 = NULL;
  Py_ssize_t __pyx_t_6;
  PyObject *(*__pyx_t_7)(PyObject *);
  PyObject *__pyx_t_8 = NULL;
  Py_ssize_t __pyx_t_9;
  Py_UCS4 __pyx_t_10;
  PyObject *__pyx_t_11 = NULL;
  PyObject *__pyx_t_12 = NULL;
  int __pyx_t_13;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("schedule", 0);
  __Pyx_INCREF(__pyx_v_content);

  /* "KakaoChat/kakao.py":575
 * def schedule(content: Dict, db: Session = Depends(get_db)):
 *     """MySQL DB   |  type: Carousel BasicCards """
 *     user_id = content["userRequest"]["user"]["id"]  # user Id             # <<<<<<<<<<<<<<
 *     checkUserDB(db, user_id)
 *     print(">>> /schedule")
 */
  __pyx_t_1 = __Pyx_PyObject_Dict_GetItem(__pyx_v_content, __pyx_n_u_userRequest); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 575, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_Dict_GetItem(__pyx_t_1, __pyx_n_u_user); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 575, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_Dict_GetItem(__pyx_t_2, __pyx_n_u_id); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 575, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_user_id = __pyx_t_1;
  __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":576
 *     """MySQL DB   |  type: Carousel BasicCards """
 *     user_id = content["userRequest"]["user"]["id"]  # user Id
 *     checkUserDB(db, user_id)             # <<<<<<<<<<<<<<
 *     print(">>> /schedule")
 *     cards = []
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_checkUserDB); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 576, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  __pyx_t_4 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
      __pyx_t_4 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_v_db, __pyx_v_user_id};
    __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_4, 2+__pyx_t_4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 576, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_1);
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_v_db, __pyx_v_user_id};
    __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_4, 2+__pyx_t_4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 576, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_1);
  } else
  #endif
  {
    __pyx_t_5 = PyTuple_New(2+__pyx_t_4); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 576, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    if (__pyx_t_3) {
      __Pyx_GIVEREF(__pyx_t_3); PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_3); __pyx_t_3 = NULL;
    }
    __Pyx_INCREF(__pyx_v_db);
    __Pyx_GIVEREF(__pyx_v_db);
    PyTuple_SET_ITEM(__pyx_t_5, 0+__pyx_t_4, __pyx_v_db);
    __Pyx_INCREF(__pyx_v_user_id);
    __Pyx_GIVEREF(__pyx_v_user_id);
    PyTuple_SET_ITEM(__pyx_t_5, 1+__pyx_t_4, __pyx_v_user_id);
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_5, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 576, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":577
 *     user_id = content["userRequest"]["user"]["id"]  # user Id
 *     checkUserDB(db, user_id)
 *     print(">>> /schedule")             # <<<<<<<<<<<<<<
 *     cards = []
 *     append = cards.append
 */
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__53, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 577, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":578
 *     checkUserDB(db, user_id)
 *     print(">>> /schedule")
 *     cards = []             # <<<<<<<<<<<<<<
 *     append = cards.append
 * 
 */
  __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 578, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v_cards = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":579
 *     print(">>> /schedule")
 *     cards = []
 *     append = cards.append             # <<<<<<<<<<<<<<
 * 
 *     scheds = getSchedule(db=db)
 */
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_cards, __pyx_n_s_append); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 579, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v_append = __pyx_t_1;
  __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":581
 *     append = cards.append
 * 
 *     scheds = getSchedule(db=db)             # <<<<<<<<<<<<<<
 *     for sched in scheds:
 *         append(
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_getSchedule); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 581, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 581, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_db, __pyx_v_db) < 0) __PYX_ERR(0, 581, __pyx_L1_error)
  __pyx_t_5 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_empty_tuple, __pyx_t_2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 581, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_scheds = __pyx_t_5;
  __pyx_t_5 = 0;

  /* "KakaoChat/kakao.py":582
 * 
 *     scheds = getSchedule(db=db)
 *     for sched in scheds:             # <<<<<<<<<<<<<<
 *         append(
 *             makeCarouselCard(sched.content, f"{sched.start_date} ~ {sched.end_date}")
 */
  if (likely(PyList_CheckExact(__pyx_v_scheds)) || PyTuple_CheckExact(__pyx_v_scheds)) {
    __pyx_t_5 = __pyx_v_scheds; __Pyx_INCREF(__pyx_t_5); __pyx_t_6 = 0;
    __pyx_t_7 = NULL;
  } else {
    __pyx_t_6 = -1; __pyx_t_5 = PyObject_GetIter(__pyx_v_scheds); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 582, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_7 = Py_TYPE(__pyx_t_5)->tp_iternext; if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 582, __pyx_L1_error)
  }
  for (;;) {
    if (likely(!__pyx_t_7)) {
      if (likely(PyList_CheckExact(__pyx_t_5))) {
        if (__pyx_t_6 >= PyList_GET_SIZE(__pyx_t_5)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_2 = PyList_GET_ITEM(__pyx_t_5, __pyx_t_6); __Pyx_INCREF(__pyx_t_2); __pyx_t_6++; if (unlikely(0 < 0)) __PYX_ERR(0, 582, __pyx_L1_error)
        #else
        __pyx_t_2 = PySequence_ITEM(__pyx_t_5, __pyx_t_6); __pyx_t_6++; if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 582, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        #endif
      } else {
        if (__pyx_t_6 >= PyTuple_GET_SIZE(__pyx_t_5)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_2 = PyTuple_GET_ITEM(__pyx_t_5, __pyx_t_6); __Pyx_INCREF(__pyx_t_2); __pyx_t_6++; if (unlikely(0 < 0)) __PYX_ERR(0, 582, __pyx_L1_error)
        #else
        __pyx_t_2 = PySequence_ITEM(__pyx_t_5, __pyx_t_6); __pyx_t_6++; if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 582, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        #endif
      }
    } else {
      __pyx_t_2 = __pyx_t_7(__pyx_t_5);
      if (unlikely(!__pyx_t_2)) {
        PyObject* exc_type = PyErr_Occurred();
        if (exc_type) {
          if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
          else __PYX_ERR(0, 582, __pyx_L1_error)
        }
        break;
      }
      __Pyx_GOTREF(__pyx_t_2);
    }
    __Pyx_XDECREF_SET(__pyx_v_sched, __pyx_t_2);
    __pyx_t_2 = 0;

    /* "KakaoChat/kakao.py":584
 *     for sched in scheds:
 *         append(
 *             makeCarouselCard(sched.content, f"{sched.start_date} ~ {sched.end_date}")             # <<<<<<<<<<<<<<
 *         )
 * 
 */
    __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_makeCarouselCard); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 584, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_v_sched, __pyx_n_s_content); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 584, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_8 = PyTuple_New(3); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 584, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __pyx_t_9 = 0;
    __pyx_t_10 = 127;
    __pyx_t_11 = __Pyx_PyObject_GetAttrStr(__pyx_v_sched, __pyx_n_s_start_date); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 584, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_11);
    __pyx_t_12 = __Pyx_PyObject_FormatSimple(__pyx_t_11, __pyx_empty_unicode); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 584, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_12);
    __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
    __pyx_t_10 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_12) > __pyx_t_10) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_12) : __pyx_t_10;
    __pyx_t_9 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_12);
    __Pyx_GIVEREF(__pyx_t_12);
    PyTuple_SET_ITEM(__pyx_t_8, 0, __pyx_t_12);
    __pyx_t_12 = 0;
    __Pyx_INCREF(__pyx_kp_u__54);
    __pyx_t_9 += 3;
    __Pyx_GIVEREF(__pyx_kp_u__54);
    PyTuple_SET_ITEM(__pyx_t_8, 1, __pyx_kp_u__54);
    __pyx_t_12 = __Pyx_PyObject_GetAttrStr(__pyx_v_sched, __pyx_n_s_end_date); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 584, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_12);
    __pyx_t_11 = __Pyx_PyObject_FormatSimple(__pyx_t_12, __pyx_empty_unicode); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 584, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_11);
    __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
    __pyx_t_10 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_11) > __pyx_t_10) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_11) : __pyx_t_10;
    __pyx_t_9 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_11);
    __Pyx_GIVEREF(__pyx_t_11);
    PyTuple_SET_ITEM(__pyx_t_8, 2, __pyx_t_11);
    __pyx_t_11 = 0;
    __pyx_t_11 = __Pyx_PyUnicode_Join(__pyx_t_8, 3, __pyx_t_9, __pyx_t_10); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 584, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_11);
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
    __pyx_t_8 = NULL;
    __pyx_t_4 = 0;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_1))) {
      __pyx_t_8 = PyMethod_GET_SELF(__pyx_t_1);
      if (likely(__pyx_t_8)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
        __Pyx_INCREF(__pyx_t_8);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_1, function);
        __pyx_t_4 = 1;
      }
    }
    #if CYTHON_FAST_PYCALL
    if (PyFunction_Check(__pyx_t_1)) {
      PyObject *__pyx_temp[3] = {__pyx_t_8, __pyx_t_3, __pyx_t_11};
      __pyx_t_2 = __Pyx_PyFunction_FastCall(__pyx_t_1, __pyx_temp+1-__pyx_t_4, 2+__pyx_t_4); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 584, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
    } else
    #endif
    #if CYTHON_FAST_PYCCALL
    if (__Pyx_PyFastCFunction_Check(__pyx_t_1)) {
      PyObject *__pyx_temp[3] = {__pyx_t_8, __pyx_t_3, __pyx_t_11};
      __pyx_t_2 = __Pyx_PyCFunction_FastCall(__pyx_t_1, __pyx_temp+1-__pyx_t_4, 2+__pyx_t_4); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 584, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
    } else
    #endif
    {
      __pyx_t_12 = PyTuple_New(2+__pyx_t_4); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 584, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_12);
      if (__pyx_t_8) {
        __Pyx_GIVEREF(__pyx_t_8); PyTuple_SET_ITEM(__pyx_t_12, 0, __pyx_t_8); __pyx_t_8 = NULL;
      }
      __Pyx_GIVEREF(__pyx_t_3);
      PyTuple_SET_ITEM(__pyx_t_12, 0+__pyx_t_4, __pyx_t_3);
      __Pyx_GIVEREF(__pyx_t_11);
      PyTuple_SET_ITEM(__pyx_t_12, 1+__pyx_t_4, __pyx_t_11);
      __pyx_t_3 = 0;
      __pyx_t_11 = 0;
      __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_t_12, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 584, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
    }
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

    /* "KakaoChat/kakao.py":583
 *     scheds = getSchedule(db=db)
 *     for sched in scheds:
 *         append(             # <<<<<<<<<<<<<<
 *             makeCarouselCard(sched.content, f"{sched.start_date} ~ {sched.end_date}")
 *         )
 */
    __pyx_t_13 = __Pyx_PyList_Append(__pyx_v_cards, __pyx_t_2); if (unlikely(__pyx_t_13 == ((int)-1))) __PYX_ERR(0, 583, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

    /* "KakaoChat/kakao.py":582
 * 
 *     scheds = getSchedule(db=db)
 *     for sched in scheds:             # <<<<<<<<<<<<<<
 *         append(
 *             makeCarouselCard(sched.content, f"{sched.start_date} ~ {sched.end_date}")
 */
  }
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  /* "KakaoChat/kakao.py":588
 * 
 *     content = {
 *         "version": "2.0",             # <<<<<<<<<<<<<<
 *         "template": {
 *             "outputs": [{"carousel": {"type": "basicCard", "items": cards[:10]}}],
 */
  __pyx_t_5 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 588, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (PyDict_SetItem(__pyx_t_5, __pyx_n_u_version, __pyx_kp_u_2_0) < 0) __PYX_ERR(0, 588, __pyx_L1_error)

  /* "KakaoChat/kakao.py":590
 *         "version": "2.0",
 *         "template": {
 *             "outputs": [{"carousel": {"type": "basicCard", "items": cards[:10]}}],             # <<<<<<<<<<<<<<
 *         },
 *     }
 */
  __pyx_t_2 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 590, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 590, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_12 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 590, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_12);
  if (PyDict_SetItem(__pyx_t_12, __pyx_n_u_type, __pyx_n_u_basicCard) < 0) __PYX_ERR(0, 590, __pyx_L1_error)
  __pyx_t_11 = __Pyx_PyList_GetSlice(__pyx_v_cards, 0, 10); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 590, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_11);
  if (PyDict_SetItem(__pyx_t_12, __pyx_n_u_items, __pyx_t_11) < 0) __PYX_ERR(0, 590, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u_carousel, __pyx_t_12) < 0) __PYX_ERR(0, 590, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
  __pyx_t_12 = PyList_New(1); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 590, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_12);
  __Pyx_GIVEREF(__pyx_t_1);
  PyList_SET_ITEM(__pyx_t_12, 0, __pyx_t_1);
  __pyx_t_1 = 0;
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_u_outputs, __pyx_t_12) < 0) __PYX_ERR(0, 590, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
  if (PyDict_SetItem(__pyx_t_5, __pyx_n_u_template, __pyx_t_2) < 0) __PYX_ERR(0, 588, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF_SET(__pyx_v_content, __pyx_t_5);
  __pyx_t_5 = 0;

  /* "KakaoChat/kakao.py":594
 *     }
 * 
 *     return JSONResponse(content=content)             # <<<<<<<<<<<<<<
 * 
 * 
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_JSONResponse); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 594, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_2 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 594, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_content, __pyx_v_content) < 0) __PYX_ERR(0, 594, __pyx_L1_error)
  __pyx_t_12 = __Pyx_PyObject_Call(__pyx_t_5, __pyx_empty_tuple, __pyx_t_2); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 594, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_12);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_r = __pyx_t_12;
  __pyx_t_12 = 0;
  goto __pyx_L0;

  /* "KakaoChat/kakao.py":573
 * 
 * @application.post("/schedule")
 * def schedule(content: Dict, db: Session = Depends(get_db)):             # <<<<<<<<<<<<<<
 *     """MySQL DB   |  type: Carousel BasicCards """
 *     user_id = content["userRequest"]["user"]["id"]  # user Id
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_XDECREF(__pyx_t_11);
  __Pyx_XDECREF(__pyx_t_12);
  __Pyx_AddTraceback("KakaoChat.kakao.schedule", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_user_id);
  __Pyx_XDECREF(__pyx_v_cards);
  __Pyx_XDECREF(__pyx_v_append);
  __Pyx_XDECREF(__pyx_v_scheds);
  __Pyx_XDECREF(__pyx_v_sched);
  __Pyx_XDECREF(__pyx_v_content);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static struct __pyx_obj_9KakaoChat_5kakao___pyx_scope_struct__get_db *__pyx_freelist_9KakaoChat_5kakao___pyx_scope_struct__get_db[8];
static int __pyx_freecount_9KakaoChat_5kakao___pyx_scope_struct__get_db = 0;

static PyObject *__pyx_tp_new_9KakaoChat_5kakao___pyx_scope_struct__get_db(PyTypeObject *t, CYTHON_UNUSED PyObject *a, CYTHON_UNUSED PyObject *k) {
  PyObject *o;
  if (CYTHON_COMPILING_IN_CPYTHON && likely((__pyx_freecount_9KakaoChat_5kakao___pyx_scope_struct__get_db > 0) & (t->tp_basicsize == sizeof(struct __pyx_obj_9KakaoChat_5kakao___pyx_scope_struct__get_db)))) {
    o = (PyObject*)__pyx_freelist_9KakaoChat_5kakao___pyx_scope_struct__get_db[--__pyx_freecount_9KakaoChat_5kakao___pyx_scope_struct__get_db];
    memset(o, 0, sizeof(struct __pyx_obj_9KakaoChat_5kakao___pyx_scope_struct__get_db));
    (void) PyObject_INIT(o, t);
    PyObject_GC_Track(o);
  } else {
    o = (*t->tp_alloc)(t, 0);
    if (unlikely(!o)) return 0;
  }
  return o;
}

static void __pyx_tp_dealloc_9KakaoChat_5kakao___pyx_scope_struct__get_db(PyObject *o) {
  struct __pyx_obj_9KakaoChat_5kakao___pyx_scope_struct__get_db *p = (struct __pyx_obj_9KakaoChat_5kakao___pyx_scope_struct__get_db *)o;
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->__pyx_v_db);
  if (CYTHON_COMPILING_IN_CPYTHON && ((__pyx_freecount_9KakaoChat_5kakao___pyx_scope_struct__get_db < 8) & (Py_TYPE(o)->tp_basicsize == sizeof(struct __pyx_obj_9KakaoChat_5kakao___pyx_scope_struct__get_db)))) {
    __pyx_freelist_9KakaoChat_5kakao___pyx_scope_struct__get_db[__pyx_freecount_9KakaoChat_5kakao___pyx_scope_struct__get_db++] = ((struct __pyx_obj_9KakaoChat_5kakao___pyx_scope_struct__get_db *)o);
  } else {
    (*Py_TYPE(o)->tp_free)(o);
  }
}

static int __pyx_tp_traverse_9KakaoChat_5kakao___pyx_scope_struct__get_db(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_9KakaoChat_5kakao___pyx_scope_struct__get_db *p = (struct __pyx_obj_9KakaoChat_5kakao___pyx_scope_struct__get_db *)o;
  if (p->__pyx_v_db) {
    e = (*v)(p->__pyx_v_db, a); if (e) return e;
  }
  return 0;
}

static PyTypeObject __pyx_type_9KakaoChat_5kakao___pyx_scope_struct__get_db = {
  PyVarObject_HEAD_INIT(0, 0)
  "KakaoChat.kakao.__pyx_scope_struct__get_db", /*tp_name*/
  sizeof(struct __pyx_obj_9KakaoChat_5kakao___pyx_scope_struct__get_db), /*tp_basicsize*/
  0, /*tp_itemsize*/
  __pyx_tp_dealloc_9KakaoChat_5kakao___pyx_scope_struct__get_db, /*tp_dealloc*/
  #if PY_VERSION_HEX < 0x030800b4
  0, /*tp_print*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b4
  0, /*tp_vectorcall_offset*/
  #endif
  0, /*tp_getattr*/
  0, /*tp_setattr*/
  #if PY_MAJOR_VERSION < 3
  0, /*tp_compare*/
  #endif
  #if PY_MAJOR_VERSION >= 3
  0, /*tp_as_async*/
  #endif
  0, /*tp_repr*/
  0, /*tp_as_number*/
  0, /*tp_as_sequence*/
  0, /*tp_as_mapping*/
  0, /*tp_hash*/
  0, /*tp_call*/
  0, /*tp_str*/
  0, /*tp_getattro*/
  0, /*tp_setattro*/
  0, /*tp_as_buffer*/
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC, /*tp_flags*/
  0, /*tp_doc*/
  __pyx_tp_traverse_9KakaoChat_5kakao___pyx_scope_struct__get_db, /*tp_traverse*/
  0, /*tp_clear*/
  0, /*tp_richcompare*/
  0, /*tp_weaklistoffset*/
  0, /*tp_iter*/
  0, /*tp_iternext*/
  0, /*tp_methods*/
  0, /*tp_members*/
  0, /*tp_getset*/
  0, /*tp_base*/
  0, /*tp_dict*/
  0, /*tp_descr_get*/
  0, /*tp_descr_set*/
  0, /*tp_dictoffset*/
  0, /*tp_init*/
  0, /*tp_alloc*/
  __pyx_tp_new_9KakaoChat_5kakao___pyx_scope_struct__get_db, /*tp_new*/
  0, /*tp_free*/
  0, /*tp_is_gc*/
  0, /*tp_bases*/
  0, /*tp_mro*/
  0, /*tp_cache*/
  0, /*tp_subclasses*/
  0, /*tp_weaklist*/
  0, /*tp_del*/
  0, /*tp_version_tag*/
  #if PY_VERSION_HEX >= 0x030400a1
  0, /*tp_finalize*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b1
  0, /*tp_vectorcall*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
  0, /*tp_print*/
  #endif
};

static PyMethodDef __pyx_methods[] = {
  {0, 0, 0, 0}
};

#if PY_MAJOR_VERSION >= 3
#if CYTHON_PEP489_MULTI_PHASE_INIT
static PyObject* __pyx_pymod_create(PyObject *spec, PyModuleDef *def); /*proto*/
static int __pyx_pymod_exec_kakao(PyObject* module); /*proto*/
static PyModuleDef_Slot __pyx_moduledef_slots[] = {
  {Py_mod_create, (void*)__pyx_pymod_create},
  {Py_mod_exec, (void*)__pyx_pymod_exec_kakao},
  {0, NULL}
};
#endif

static struct PyModuleDef __pyx_moduledef = {
    PyModuleDef_HEAD_INIT,
    "kakao",
    0, /* m_doc */
  #if CYTHON_PEP489_MULTI_PHASE_INIT
    0, /* m_size */
  #else
    -1, /* m_size */
  #endif
    __pyx_methods /* m_methods */,
  #if CYTHON_PEP489_MULTI_PHASE_INIT
    __pyx_moduledef_slots, /* m_slots */
  #else
    NULL, /* m_reload */
  #endif
    NULL, /* m_traverse */
    NULL, /* m_clear */
    NULL /* m_free */
};
#endif
#ifndef CYTHON_SMALL_CODE
#if defined(__clang__)
    #define CYTHON_SMALL_CODE
#elif defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 3))
    #define CYTHON_SMALL_CODE __attribute__((cold))
#else
    #define CYTHON_SMALL_CODE
#endif
#endif

static __Pyx_StringTabEntry __pyx_string_tab[] = {
  {&__pyx_kp_u_0_0_0_0, __pyx_k_0_0_0_0, sizeof(__pyx_k_0_0_0_0), 0, 1, 0, 0},
  {&__pyx_kp_u_1_0_0, __pyx_k_1_0_0, sizeof(__pyx_k_1_0_0), 0, 1, 0, 0},
  {&__pyx_kp_u_2021, __pyx_k_2021, sizeof(__pyx_k_2021), 0, 1, 0, 0},
  {&__pyx_kp_u_2021_2, __pyx_k_2021_2, sizeof(__pyx_k_2021_2), 0, 1, 0, 0},
  {&__pyx_kp_u_2_0, __pyx_k_2_0, sizeof(__pyx_k_2_0), 0, 1, 0, 0},
  {&__pyx_n_s_ADDRESS, __pyx_k_ADDRESS, sizeof(__pyx_k_ADDRESS), 0, 0, 1, 1},
  {&__pyx_kp_u_Ajou_notices_server, __pyx_k_Ajou_notices_server, sizeof(__pyx_k_Ajou_notices_server), 0, 1, 0, 0},
  {&__pyx_n_s_Base, __pyx_k_Base, sizeof(__pyx_k_Base), 0, 0, 1, 1},
  {&__pyx_n_s_CORSMiddleware, __pyx_k_CORSMiddleware, sizeof(__pyx_k_CORSMiddleware), 0, 0, 1, 1},
  {&__pyx_n_s_DAY, __pyx_k_DAY, sizeof(__pyx_k_DAY), 0, 0, 1, 1},
  {&__pyx_n_s_Depends, __pyx_k_Depends, sizeof(__pyx_k_Depends), 0, 0, 1, 1},
  {&__pyx_n_s_Dict, __pyx_k_Dict, sizeof(__pyx_k_Dict), 0, 0, 1, 1},
  {&__pyx_n_s_FastAPI, __pyx_k_FastAPI, sizeof(__pyx_k_FastAPI), 0, 0, 1, 1},
  {&__pyx_n_s_HTMLParser, __pyx_k_HTMLParser, sizeof(__pyx_k_HTMLParser), 0, 0, 1, 1},
  {&__pyx_n_s_HTTPError, __pyx_k_HTTPError, sizeof(__pyx_k_HTTPError), 0, 0, 1, 1},
  {&__pyx_kp_u_It_s_taking_too_long_to_load_web, __pyx_k_It_s_taking_too_long_to_load_web, sizeof(__pyx_k_It_s_taking_too_long_to_load_web), 0, 1, 0, 0},
  {&__pyx_n_s_JSONResponse, __pyx_k_JSONResponse, sizeof(__pyx_k_JSONResponse), 0, 0, 1, 1},
  {&__pyx_n_s_KakaoChat_kakao, __pyx_k_KakaoChat_kakao, sizeof(__pyx_k_KakaoChat_kakao), 0, 0, 1, 1},
  {&__pyx_kp_u_None, __pyx_k_None, sizeof(__pyx_k_None), 0, 1, 0, 0},
  {&__pyx_kp_u_Seems_like_the_server_is_down_no, __pyx_k_Seems_like_the_server_is_down_no, sizeof(__pyx_k_Seems_like_the_server_is_down_no), 0, 1, 0, 0},
  {&__pyx_kp_u_Seems_like_the_url_is_wrong_now, __pyx_k_Seems_like_the_url_is_wrong_now, sizeof(__pyx_k_Seems_like_the_url_is_wrong_now), 0, 1, 0, 0},
  {&__pyx_n_s_Session, __pyx_k_Session, sizeof(__pyx_k_Session), 0, 0, 1, 1},
  {&__pyx_n_s_SessionLocal, __pyx_k_SessionLocal, sizeof(__pyx_k_SessionLocal), 0, 0, 1, 1},
  {&__pyx_n_s_TimeoutError, __pyx_k_TimeoutError, sizeof(__pyx_k_TimeoutError), 0, 0, 1, 1},
  {&__pyx_n_s_URLError, __pyx_k_URLError, sizeof(__pyx_k_URLError), 0, 0, 1, 1},
  {&__pyx_kp_u_Welcome_the_server_is_running_we, __pyx_k_Welcome_the_server_is_running_we, sizeof(__pyx_k_Welcome_the_server_is_running_we), 0, 1, 0, 0},
  {&__pyx_kp_u__10, __pyx_k__10, sizeof(__pyx_k__10), 0, 1, 0, 0},
  {&__pyx_kp_u__11, __pyx_k__11, sizeof(__pyx_k__11), 0, 1, 0, 0},
  {&__pyx_kp_u__12, __pyx_k__12, sizeof(__pyx_k__12), 0, 1, 0, 0},
  {&__pyx_n_u__13, __pyx_k__13, sizeof(__pyx_k__13), 0, 1, 0, 1},
  {&__pyx_n_u__14, __pyx_k__14, sizeof(__pyx_k__14), 0, 1, 0, 1},
  {&__pyx_kp_u__15, __pyx_k__15, sizeof(__pyx_k__15), 0, 1, 0, 0},
  {&__pyx_kp_u__16, __pyx_k__16, sizeof(__pyx_k__16), 0, 1, 0, 0},
  {&__pyx_kp_u__17, __pyx_k__17, sizeof(__pyx_k__17), 0, 1, 0, 0},
  {&__pyx_n_u__19, __pyx_k__19, sizeof(__pyx_k__19), 0, 1, 0, 1},
  {&__pyx_kp_u__20, __pyx_k__20, sizeof(__pyx_k__20), 0, 1, 0, 0},
  {&__pyx_kp_u__21, __pyx_k__21, sizeof(__pyx_k__21), 0, 1, 0, 0},
  {&__pyx_kp_u__22, __pyx_k__22, sizeof(__pyx_k__22), 0, 1, 0, 0},
  {&__pyx_n_u__23, __pyx_k__23, sizeof(__pyx_k__23), 0, 1, 0, 1},
  {&__pyx_kp_u__24, __pyx_k__24, sizeof(__pyx_k__24), 0, 1, 0, 0},
  {&__pyx_n_u__26, __pyx_k__26, sizeof(__pyx_k__26), 0, 1, 0, 1},
  {&__pyx_n_u__27, __pyx_k__27, sizeof(__pyx_k__27), 0, 1, 0, 1},
  {&__pyx_n_u__28, __pyx_k__28, sizeof(__pyx_k__28), 0, 1, 0, 1},
  {&__pyx_n_u__29, __pyx_k__29, sizeof(__pyx_k__29), 0, 1, 0, 1},
  {&__pyx_n_u__30, __pyx_k__30, sizeof(__pyx_k__30), 0, 1, 0, 1},
  {&__pyx_n_u__31, __pyx_k__31, sizeof(__pyx_k__31), 0, 1, 0, 1},
  {&__pyx_n_u__32, __pyx_k__32, sizeof(__pyx_k__32), 0, 1, 0, 1},
  {&__pyx_n_u__33, __pyx_k__33, sizeof(__pyx_k__33), 0, 1, 0, 1},
  {&__pyx_n_u__34, __pyx_k__34, sizeof(__pyx_k__34), 0, 1, 0, 1},
  {&__pyx_n_u__35, __pyx_k__35, sizeof(__pyx_k__35), 0, 1, 0, 1},
  {&__pyx_n_u__36, __pyx_k__36, sizeof(__pyx_k__36), 0, 1, 0, 1},
  {&__pyx_kp_u__37, __pyx_k__37, sizeof(__pyx_k__37), 0, 1, 0, 0},
  {&__pyx_n_u__40, __pyx_k__40, sizeof(__pyx_k__40), 0, 1, 0, 1},
  {&__pyx_kp_u__44, __pyx_k__44, sizeof(__pyx_k__44), 0, 1, 0, 0},
  {&__pyx_kp_u__46, __pyx_k__46, sizeof(__pyx_k__46), 0, 1, 0, 0},
  {&__pyx_n_u__47, __pyx_k__47, sizeof(__pyx_k__47), 0, 1, 0, 1},
  {&__pyx_kp_u__48, __pyx_k__48, sizeof(__pyx_k__48), 0, 1, 0, 0},
  {&__pyx_kp_u__49, __pyx_k__49, sizeof(__pyx_k__49), 0, 1, 0, 0},
  {&__pyx_kp_u__50, __pyx_k__50, sizeof(__pyx_k__50), 0, 1, 0, 0},
  {&__pyx_kp_u__51, __pyx_k__51, sizeof(__pyx_k__51), 0, 1, 0, 0},
  {&__pyx_kp_u__54, __pyx_k__54, sizeof(__pyx_k__54), 0, 1, 0, 0},
  {&__pyx_kp_u__55, __pyx_k__55, sizeof(__pyx_k__55), 0, 1, 0, 0},
  {&__pyx_kp_u__6, __pyx_k__6, sizeof(__pyx_k__6), 0, 1, 0, 0},
  {&__pyx_kp_u__7, __pyx_k__7, sizeof(__pyx_k__7), 0, 1, 0, 0},
  {&__pyx_kp_u__8, __pyx_k__8, sizeof(__pyx_k__8), 0, 1, 0, 0},
  {&__pyx_n_s__81, __pyx_k__81, sizeof(__pyx_k__81), 0, 0, 1, 1},
  {&__pyx_kp_u__86, __pyx_k__86, sizeof(__pyx_k__86), 0, 1, 0, 0},
  {&__pyx_n_u_action, __pyx_k_action, sizeof(__pyx_k_action), 0, 1, 0, 1},
  {&__pyx_n_s_add_middleware, __pyx_k_add_middleware, sizeof(__pyx_k_add_middleware), 0, 0, 1, 1},
  {&__pyx_n_u_ajou_carousel, __pyx_k_ajou_carousel, sizeof(__pyx_k_ajou_carousel), 0, 1, 0, 1},
  {&__pyx_n_u_ajou_carousel_1, __pyx_k_ajou_carousel_1, sizeof(__pyx_k_ajou_carousel_1), 0, 1, 0, 1},
  {&__pyx_n_u_ajou_carousel_2, __pyx_k_ajou_carousel_2, sizeof(__pyx_k_ajou_carousel_2), 0, 1, 0, 1},
  {&__pyx_n_s_allow_credentials, __pyx_k_allow_credentials, sizeof(__pyx_k_allow_credentials), 0, 0, 1, 1},
  {&__pyx_n_s_allow_headers, __pyx_k_allow_headers, sizeof(__pyx_k_allow_headers), 0, 0, 1, 1},
  {&__pyx_n_s_allow_methods, __pyx_k_allow_methods, sizeof(__pyx_k_allow_methods), 0, 0, 1, 1},
  {&__pyx_n_s_allow_origins, __pyx_k_allow_origins, sizeof(__pyx_k_allow_origins), 0, 0, 1, 1},
  {&__pyx_n_s_append, __pyx_k_append, sizeof(__pyx_k_append), 0, 0, 1, 1},
  {&__pyx_n_s_application, __pyx_k_application, sizeof(__pyx_k_application), 0, 0, 1, 1},
  {&__pyx_n_s_args, __pyx_k_args, sizeof(__pyx_k_args), 0, 0, 1, 1},
  {&__pyx_kp_u_articleLimit, __pyx_k_articleLimit, sizeof(__pyx_k_articleLimit), 0, 1, 0, 0},
  {&__pyx_kp_u_article_offset_0, __pyx_k_article_offset_0, sizeof(__pyx_k_article_offset_0), 0, 1, 0, 0},
  {&__pyx_kp_u_ask, __pyx_k_ask, sizeof(__pyx_k_ask), 0, 1, 0, 0},
  {&__pyx_n_s_askKeyword, __pyx_k_askKeyword, sizeof(__pyx_k_askKeyword), 0, 0, 1, 1},
  {&__pyx_kp_u_ask_2, __pyx_k_ask_2, sizeof(__pyx_k_ask_2), 0, 1, 0, 0},
  {&__pyx_kp_u_ask_filter, __pyx_k_ask_filter, sizeof(__pyx_k_ask_filter), 0, 1, 0, 0},
  {&__pyx_kp_u_ask_filter_2, __pyx_k_ask_filter_2, sizeof(__pyx_k_ask_filter_2), 0, 1, 0, 0},
  {&__pyx_n_s_attributes, __pyx_k_attributes, sizeof(__pyx_k_attributes), 0, 0, 1, 1},
  {&__pyx_n_u_basicCard, __pyx_k_basicCard, sizeof(__pyx_k_basicCard), 0, 1, 0, 1},
  {&__pyx_n_s_bind, __pyx_k_bind, sizeof(__pyx_k_bind), 0, 0, 1, 1},
  {&__pyx_n_u_buttons, __pyx_k_buttons, sizeof(__pyx_k_buttons), 0, 1, 0, 1},
  {&__pyx_n_s_card, __pyx_k_card, sizeof(__pyx_k_card), 0, 0, 1, 1},
  {&__pyx_n_s_card_imgs, __pyx_k_card_imgs, sizeof(__pyx_k_card_imgs), 0, 0, 1, 1},
  {&__pyx_n_s_cards, __pyx_k_cards, sizeof(__pyx_k_cards), 0, 0, 1, 1},
  {&__pyx_n_u_carousel, __pyx_k_carousel, sizeof(__pyx_k_carousel), 0, 1, 0, 1},
  {&__pyx_n_u_cate, __pyx_k_cate, sizeof(__pyx_k_cate), 0, 1, 0, 1},
  {&__pyx_n_s_categories, __pyx_k_categories, sizeof(__pyx_k_categories), 0, 0, 1, 1},
  {&__pyx_n_s_category, __pyx_k_category, sizeof(__pyx_k_category), 0, 0, 1, 1},
  {&__pyx_n_s_checkConnection, __pyx_k_checkConnection, sizeof(__pyx_k_checkConnection), 0, 0, 1, 1},
  {&__pyx_n_s_checkLastNotice, __pyx_k_checkLastNotice, sizeof(__pyx_k_checkLastNotice), 0, 0, 1, 1},
  {&__pyx_n_s_checkUserDB, __pyx_k_checkUserDB, sizeof(__pyx_k_checkUserDB), 0, 0, 1, 1},
  {&__pyx_n_s_choice, __pyx_k_choice, sizeof(__pyx_k_choice), 0, 0, 1, 1},
  {&__pyx_n_s_cline_in_traceback, __pyx_k_cline_in_traceback, sizeof(__pyx_k_cline_in_traceback), 0, 0, 1, 1},
  {&__pyx_n_s_close, __pyx_k_close, sizeof(__pyx_k_close), 0, 0, 1, 1},
  {&__pyx_n_s_content, __pyx_k_content, sizeof(__pyx_k_content), 0, 0, 1, 1},
  {&__pyx_n_s_context, __pyx_k_context, sizeof(__pyx_k_context), 0, 0, 1, 1},
  {&__pyx_n_s_create_all, __pyx_k_create_all, sizeof(__pyx_k_create_all), 0, 0, 1, 1},
  {&__pyx_n_s_create_unverified_context, __pyx_k_create_unverified_context, sizeof(__pyx_k_create_unverified_context), 0, 0, 1, 1},
  {&__pyx_n_s_create_user, __pyx_k_create_user, sizeof(__pyx_k_create_user), 0, 0, 1, 1},
  {&__pyx_n_s_crud, __pyx_k_crud, sizeof(__pyx_k_crud), 0, 0, 1, 1},
  {&__pyx_n_s_css, __pyx_k_css, sizeof(__pyx_k_css), 0, 0, 1, 1},
  {&__pyx_n_s_data, __pyx_k_data, sizeof(__pyx_k_data), 0, 0, 1, 1},
  {&__pyx_n_s_database, __pyx_k_database, sizeof(__pyx_k_database), 0, 0, 1, 1},
  {&__pyx_n_s_date, __pyx_k_date, sizeof(__pyx_k_date), 0, 0, 1, 1},
  {&__pyx_kp_u_date_2, __pyx_k_date_2, sizeof(__pyx_k_date_2), 0, 1, 0, 0},
  {&__pyx_kp_u_date_3, __pyx_k_date_3, sizeof(__pyx_k_date_3), 0, 1, 0, 0},
  {&__pyx_n_s_dates, __pyx_k_dates, sizeof(__pyx_k_dates), 0, 0, 1, 1},
  {&__pyx_n_s_datetime, __pyx_k_datetime, sizeof(__pyx_k_datetime), 0, 0, 1, 1},
  {&__pyx_n_s_days, __pyx_k_days, sizeof(__pyx_k_days), 0, 0, 1, 1},
  {&__pyx_n_s_db, __pyx_k_db, sizeof(__pyx_k_db), 0, 0, 1, 1},
  {&__pyx_n_s_db_model, __pyx_k_db_model, sizeof(__pyx_k_db_model), 0, 0, 1, 1},
  {&__pyx_n_s_db_model_crud, __pyx_k_db_model_crud, sizeof(__pyx_k_db_model_crud), 0, 0, 1, 1},
  {&__pyx_n_s_db_model_database, __pyx_k_db_model_database, sizeof(__pyx_k_db_model_database), 0, 0, 1, 1},
  {&__pyx_n_s_db_model_models, __pyx_k_db_model_models, sizeof(__pyx_k_db_model_models), 0, 0, 1, 1},
  {&__pyx_n_s_db_model_schemas, __pyx_k_db_model_schemas, sizeof(__pyx_k_db_model_schemas), 0, 0, 1, 1},
  {&__pyx_n_s_db_notices, __pyx_k_db_notices, sizeof(__pyx_k_db_notices), 0, 0, 1, 1},
  {&__pyx_n_s_decode, __pyx_k_decode, sizeof(__pyx_k_decode), 0, 0, 1, 1},
  {&__pyx_n_s_desc, __pyx_k_desc, sizeof(__pyx_k_desc), 0, 0, 1, 1},
  {&__pyx_n_s_description, __pyx_k_description, sizeof(__pyx_k_description), 0, 0, 1, 1},
  {&__pyx_n_u_description, __pyx_k_description, sizeof(__pyx_k_description), 0, 1, 0, 1},
  {&__pyx_kp_u_div_b_title_box_a, __pyx_k_div_b_title_box_a, sizeof(__pyx_k_div_b_title_box_a), 0, 1, 0, 0},
  {&__pyx_n_s_duplicate, __pyx_k_duplicate, sizeof(__pyx_k_duplicate), 0, 0, 1, 1},
  {&__pyx_n_s_end_date, __pyx_k_end_date, sizeof(__pyx_k_end_date), 0, 0, 1, 1},
  {&__pyx_n_s_engine, __pyx_k_engine, sizeof(__pyx_k_engine), 0, 0, 1, 1},
  {&__pyx_n_s_fastapi, __pyx_k_fastapi, sizeof(__pyx_k_fastapi), 0, 0, 1, 1},
  {&__pyx_n_s_fastapi_middleware_cors, __pyx_k_fastapi_middleware_cors, sizeof(__pyx_k_fastapi_middleware_cors), 0, 0, 1, 1},
  {&__pyx_n_s_fastapi_responses, __pyx_k_fastapi_responses, sizeof(__pyx_k_fastapi_responses), 0, 0, 1, 1},
  {&__pyx_kp_u_for_Kakao_Chatbot, __pyx_k_for_Kakao_Chatbot, sizeof(__pyx_k_for_Kakao_Chatbot), 0, 1, 0, 0},
  {&__pyx_n_s_get, __pyx_k_get, sizeof(__pyx_k_get), 0, 0, 1, 1},
  {&__pyx_n_s_getLastNotice, __pyx_k_getLastNotice, sizeof(__pyx_k_getLastNotice), 0, 0, 1, 1},
  {&__pyx_n_s_getSchedule, __pyx_k_getSchedule, sizeof(__pyx_k_getSchedule), 0, 0, 1, 1},
  {&__pyx_n_s_getTodayNotices, __pyx_k_getTodayNotices, sizeof(__pyx_k_getTodayNotices), 0, 0, 1, 1},
  {&__pyx_n_s_getYesterdayNotices, __pyx_k_getYesterdayNotices, sizeof(__pyx_k_getYesterdayNotices), 0, 0, 1, 1},
  {&__pyx_n_s_get_all_sched, __pyx_k_get_all_sched, sizeof(__pyx_k_get_all_sched), 0, 0, 1, 1},
  {&__pyx_n_s_get_db, __pyx_k_get_db, sizeof(__pyx_k_get_db), 0, 0, 1, 1},
  {&__pyx_n_s_get_notices_with_date, __pyx_k_get_notices_with_date, sizeof(__pyx_k_get_notices_with_date), 0, 0, 1, 1},
  {&__pyx_n_s_get_user_by_user_id, __pyx_k_get_user_by_user_id, sizeof(__pyx_k_get_user_by_user_id), 0, 0, 1, 1},
  {&__pyx_n_u_header, __pyx_k_header, sizeof(__pyx_k_header), 0, 1, 0, 1},
  {&__pyx_n_s_hello, __pyx_k_hello, sizeof(__pyx_k_hello), 0, 0, 1, 1},
  {&__pyx_n_s_host, __pyx_k_host, sizeof(__pyx_k_host), 0, 0, 1, 1},
  {&__pyx_n_u_href, __pyx_k_href, sizeof(__pyx_k_href), 0, 1, 0, 1},
  {&__pyx_n_s_html, __pyx_k_html, sizeof(__pyx_k_html), 0, 0, 1, 1},
  {&__pyx_kp_u_http_k_kakaocdn_net_dn_APR96_btq, __pyx_k_http_k_kakaocdn_net_dn_APR96_btq, sizeof(__pyx_k_http_k_kakaocdn_net_dn_APR96_btq), 0, 1, 0, 0},
  {&__pyx_kp_u_https_raw_githubusercontent_com, __pyx_k_https_raw_githubusercontent_com, sizeof(__pyx_k_https_raw_githubusercontent_com), 0, 1, 0, 0},
  {&__pyx_kp_u_https_www_ajou_ac_kr_kr_ajou_not, __pyx_k_https_www_ajou_ac_kr_kr_ajou_not, sizeof(__pyx_k_https_www_ajou_ac_kr_kr_ajou_not), 0, 1, 0, 0},
  {&__pyx_kp_u_https_www_ajou_ac_kr_kr_ajou_not_2, __pyx_k_https_www_ajou_ac_kr_kr_ajou_not_2, sizeof(__pyx_k_https_www_ajou_ac_kr_kr_ajou_not_2), 0, 1, 0, 0},
  {&__pyx_kp_u_https_www_ajou_ac_kr_kr_ajou_not_3, __pyx_k_https_www_ajou_ac_kr_kr_ajou_not_3, sizeof(__pyx_k_https_www_ajou_ac_kr_kr_ajou_not_3), 0, 1, 0, 0},
  {&__pyx_n_s_i, __pyx_k_i, sizeof(__pyx_k_i), 0, 0, 1, 1},
  {&__pyx_n_s_id, __pyx_k_id, sizeof(__pyx_k_id), 0, 0, 1, 1},
  {&__pyx_n_u_id, __pyx_k_id, sizeof(__pyx_k_id), 0, 1, 0, 1},
  {&__pyx_n_s_ids, __pyx_k_ids, sizeof(__pyx_k_ids), 0, 0, 1, 1},
  {&__pyx_n_u_imageUrl, __pyx_k_imageUrl, sizeof(__pyx_k_imageUrl), 0, 1, 0, 1},
  {&__pyx_n_s_import, __pyx_k_import, sizeof(__pyx_k_import), 0, 0, 1, 1},
  {&__pyx_n_u_info, __pyx_k_info, sizeof(__pyx_k_info), 0, 1, 0, 1},
  {&__pyx_n_u_int, __pyx_k_int, sizeof(__pyx_k_int), 0, 1, 0, 1},
  {&__pyx_n_u_items, __pyx_k_items, sizeof(__pyx_k_items), 0, 1, 0, 1},
  {&__pyx_kp_s_kakao_py, __pyx_k_kakao_py, sizeof(__pyx_k_kakao_py), 0, 0, 1, 0},
  {&__pyx_n_s_keyword, __pyx_k_keyword, sizeof(__pyx_k_keyword), 0, 0, 1, 1},
  {&__pyx_n_u_label, __pyx_k_label, sizeof(__pyx_k_label), 0, 1, 0, 1},
  {&__pyx_kp_u_last, __pyx_k_last, sizeof(__pyx_k_last), 0, 1, 0, 0},
  {&__pyx_n_s_last_id, __pyx_k_last_id, sizeof(__pyx_k_last_id), 0, 0, 1, 1},
  {&__pyx_n_s_last_notice_id, __pyx_k_last_notice_id, sizeof(__pyx_k_last_notice_id), 0, 0, 1, 1},
  {&__pyx_n_s_length, __pyx_k_length, sizeof(__pyx_k_length), 0, 0, 1, 1},
  {&__pyx_n_s_link, __pyx_k_link, sizeof(__pyx_k_link), 0, 0, 1, 1},
  {&__pyx_n_u_link, __pyx_k_link, sizeof(__pyx_k_link), 0, 1, 0, 1},
  {&__pyx_n_u_listCard, __pyx_k_listCard, sizeof(__pyx_k_listCard), 0, 1, 0, 1},
  {&__pyx_n_s_log_level, __pyx_k_log_level, sizeof(__pyx_k_log_level), 0, 0, 1, 1},
  {&__pyx_n_s_main, __pyx_k_main, sizeof(__pyx_k_main), 0, 0, 1, 1},
  {&__pyx_n_u_main, __pyx_k_main, sizeof(__pyx_k_main), 0, 1, 0, 1},
  {&__pyx_n_s_makeCarouselCard, __pyx_k_makeCarouselCard, sizeof(__pyx_k_makeCarouselCard), 0, 0, 1, 1},
  {&__pyx_n_s_makeJSON, __pyx_k_makeJSON, sizeof(__pyx_k_makeJSON), 0, 0, 1, 1},
  {&__pyx_n_s_makeJSONwithDate, __pyx_k_makeJSONwithDate, sizeof(__pyx_k_makeJSONwithDate), 0, 0, 1, 1},
  {&__pyx_n_s_makeTimeoutMessage, __pyx_k_makeTimeoutMessage, sizeof(__pyx_k_makeTimeoutMessage), 0, 0, 1, 1},
  {&__pyx_n_s_message, __pyx_k_message, sizeof(__pyx_k_message), 0, 0, 1, 1},
  {&__pyx_n_u_message, __pyx_k_message, sizeof(__pyx_k_message), 0, 1, 0, 1},
  {&__pyx_n_u_messageText, __pyx_k_messageText, sizeof(__pyx_k_messageText), 0, 1, 0, 1},
  {&__pyx_kp_u_message_2, __pyx_k_message_2, sizeof(__pyx_k_message_2), 0, 1, 0, 0},
  {&__pyx_kp_u_message_3, __pyx_k_message_3, sizeof(__pyx_k_message_3), 0, 1, 0, 0},
  {&__pyx_n_s_metadata, __pyx_k_metadata, sizeof(__pyx_k_metadata), 0, 0, 1, 1},
  {&__pyx_kp_u_mode_list_articleLimit, __pyx_k_mode_list_articleLimit, sizeof(__pyx_k_mode_list_articleLimit), 0, 1, 0, 0},
  {&__pyx_kp_u_mode_list_srCategoryId, __pyx_k_mode_list_srCategoryId, sizeof(__pyx_k_mode_list_srCategoryId), 0, 1, 0, 0},
  {&__pyx_kp_u_mode_list_srSearchKey_srSearchV, __pyx_k_mode_list_srSearchKey_srSearchV, sizeof(__pyx_k_mode_list_srSearchKey_srSearchV), 0, 1, 0, 0},
  {&__pyx_n_s_models, __pyx_k_models, sizeof(__pyx_k_models), 0, 0, 1, 1},
  {&__pyx_n_s_name, __pyx_k_name, sizeof(__pyx_k_name), 0, 0, 1, 1},
  {&__pyx_n_s_no_post, __pyx_k_no_post, sizeof(__pyx_k_no_post), 0, 0, 1, 1},
  {&__pyx_n_s_notice, __pyx_k_notice, sizeof(__pyx_k_notice), 0, 0, 1, 1},
  {&__pyx_n_s_noticeLength, __pyx_k_noticeLength, sizeof(__pyx_k_noticeLength), 0, 0, 1, 1},
  {&__pyx_n_s_notice_id, __pyx_k_notice_id, sizeof(__pyx_k_notice_id), 0, 0, 1, 1},
  {&__pyx_n_s_notices, __pyx_k_notices, sizeof(__pyx_k_notices), 0, 0, 1, 1},
  {&__pyx_n_s_noticesToday, __pyx_k_noticesToday, sizeof(__pyx_k_noticesToday), 0, 0, 1, 1},
  {&__pyx_n_s_now, __pyx_k_now, sizeof(__pyx_k_now), 0, 0, 1, 1},
  {&__pyx_n_u_outputs, __pyx_k_outputs, sizeof(__pyx_k_outputs), 0, 1, 0, 1},
  {&__pyx_n_u_params, __pyx_k_params, sizeof(__pyx_k_params), 0, 1, 0, 1},
  {&__pyx_n_s_parseNotices, __pyx_k_parseNotices, sizeof(__pyx_k_parseNotices), 0, 0, 1, 1},
  {&__pyx_n_s_parseOne, __pyx_k_parseOne, sizeof(__pyx_k_parseOne), 0, 0, 1, 1},
  {&__pyx_kp_u_png, __pyx_k_png, sizeof(__pyx_k_png), 0, 1, 0, 0},
  {&__pyx_n_s_port, __pyx_k_port, sizeof(__pyx_k_port), 0, 0, 1, 1},
  {&__pyx_n_s_post, __pyx_k_post, sizeof(__pyx_k_post), 0, 0, 1, 1},
  {&__pyx_n_s_postDate, __pyx_k_postDate, sizeof(__pyx_k_postDate), 0, 0, 1, 1},
  {&__pyx_n_s_postId, __pyx_k_postId, sizeof(__pyx_k_postId), 0, 0, 1, 1},
  {&__pyx_n_s_postLink, __pyx_k_postLink, sizeof(__pyx_k_postLink), 0, 0, 1, 1},
  {&__pyx_n_s_postTitle, __pyx_k_postTitle, sizeof(__pyx_k_postTitle), 0, 0, 1, 1},
  {&__pyx_n_s_postWriter, __pyx_k_postWriter, sizeof(__pyx_k_postWriter), 0, 0, 1, 1},
  {&__pyx_n_s_posts, __pyx_k_posts, sizeof(__pyx_k_posts), 0, 0, 1, 1},
  {&__pyx_n_s_print, __pyx_k_print, sizeof(__pyx_k_print), 0, 0, 1, 1},
  {&__pyx_n_u_quickReplies, __pyx_k_quickReplies, sizeof(__pyx_k_quickReplies), 0, 1, 0, 1},
  {&__pyx_n_s_quote, __pyx_k_quote, sizeof(__pyx_k_quote), 0, 0, 1, 1},
  {&__pyx_n_s_random, __pyx_k_random, sizeof(__pyx_k_random), 0, 0, 1, 1},
  {&__pyx_n_s_range, __pyx_k_range, sizeof(__pyx_k_range), 0, 0, 1, 1},
  {&__pyx_n_s_read, __pyx_k_read, sizeof(__pyx_k_read), 0, 0, 1, 1},
  {&__pyx_n_s_replace, __pyx_k_replace, sizeof(__pyx_k_replace), 0, 0, 1, 1},
  {&__pyx_n_s_replies, __pyx_k_replies, sizeof(__pyx_k_replies), 0, 0, 1, 1},
  {&__pyx_n_s_response_data, __pyx_k_response_data, sizeof(__pyx_k_response_data), 0, 0, 1, 1},
  {&__pyx_n_s_result, __pyx_k_result, sizeof(__pyx_k_result), 0, 0, 1, 1},
  {&__pyx_n_s_run, __pyx_k_run, sizeof(__pyx_k_run), 0, 0, 1, 1},
  {&__pyx_n_s_sched, __pyx_k_sched, sizeof(__pyx_k_sched), 0, 0, 1, 1},
  {&__pyx_n_s_scheds, __pyx_k_scheds, sizeof(__pyx_k_scheds), 0, 0, 1, 1},
  {&__pyx_kp_u_schedule, __pyx_k_schedule, sizeof(__pyx_k_schedule), 0, 1, 0, 0},
  {&__pyx_kp_u_schedule_2, __pyx_k_schedule_2, sizeof(__pyx_k_schedule_2), 0, 1, 0, 0},
  {&__pyx_n_s_schedule_3, __pyx_k_schedule_3, sizeof(__pyx_k_schedule_3), 0, 0, 1, 1},
  {&__pyx_kp_u_search, __pyx_k_search, sizeof(__pyx_k_search), 0, 1, 0, 0},
  {&__pyx_n_s_searchDate, __pyx_k_searchDate, sizeof(__pyx_k_searchDate), 0, 0, 1, 1},
  {&__pyx_n_s_searchKeyword, __pyx_k_searchKeyword, sizeof(__pyx_k_searchKeyword), 0, 0, 1, 1},
  {&__pyx_n_s_searchNotice, __pyx_k_searchNotice, sizeof(__pyx_k_searchNotice), 0, 0, 1, 1},
  {&__pyx_kp_u_search_2, __pyx_k_search_2, sizeof(__pyx_k_search_2), 0, 1, 0, 0},
  {&__pyx_n_s_selectolax_parser, __pyx_k_selectolax_parser, sizeof(__pyx_k_selectolax_parser), 0, 0, 1, 1},
  {&__pyx_n_s_send, __pyx_k_send, sizeof(__pyx_k_send), 0, 0, 1, 1},
  {&__pyx_n_u_share, __pyx_k_share, sizeof(__pyx_k_share), 0, 1, 0, 1},
  {&__pyx_n_u_simpleText, __pyx_k_simpleText, sizeof(__pyx_k_simpleText), 0, 1, 0, 1},
  {&__pyx_n_s_soup, __pyx_k_soup, sizeof(__pyx_k_soup), 0, 0, 1, 1},
  {&__pyx_kp_u_span_b_date, __pyx_k_span_b_date, sizeof(__pyx_k_span_b_date), 0, 1, 0, 0},
  {&__pyx_kp_u_span_b_writer, __pyx_k_span_b_writer, sizeof(__pyx_k_span_b_writer), 0, 1, 0, 0},
  {&__pyx_n_s_sqlalchemy_orm, __pyx_k_sqlalchemy_orm, sizeof(__pyx_k_sqlalchemy_orm), 0, 0, 1, 1},
  {&__pyx_kp_u_srSearchKey_srSearchVal_article, __pyx_k_srSearchKey_srSearchVal_article, sizeof(__pyx_k_srSearchKey_srSearchVal_article), 0, 1, 0, 0},
  {&__pyx_n_s_ssl, __pyx_k_ssl, sizeof(__pyx_k_ssl), 0, 0, 1, 1},
  {&__pyx_n_s_start_date, __pyx_k_start_date, sizeof(__pyx_k_start_date), 0, 0, 1, 1},
  {&__pyx_n_s_strftime, __pyx_k_strftime, sizeof(__pyx_k_strftime), 0, 0, 1, 1},
  {&__pyx_n_s_strip, __pyx_k_strip, sizeof(__pyx_k_strip), 0, 0, 1, 1},
  {&__pyx_n_s_switch, __pyx_k_switch, sizeof(__pyx_k_switch), 0, 0, 1, 1},
  {&__pyx_n_u_sys_text, __pyx_k_sys_text, sizeof(__pyx_k_sys_text), 0, 1, 0, 1},
  {&__pyx_kp_u_td_b_no_post, __pyx_k_td_b_no_post, sizeof(__pyx_k_td_b_no_post), 0, 1, 0, 0},
  {&__pyx_kp_u_td_b_num_box, __pyx_k_td_b_num_box, sizeof(__pyx_k_td_b_num_box), 0, 1, 0, 0},
  {&__pyx_n_u_template, __pyx_k_template, sizeof(__pyx_k_template), 0, 1, 0, 1},
  {&__pyx_n_s_test, __pyx_k_test, sizeof(__pyx_k_test), 0, 0, 1, 1},
  {&__pyx_n_s_text, __pyx_k_text, sizeof(__pyx_k_text), 0, 0, 1, 1},
  {&__pyx_n_u_text, __pyx_k_text, sizeof(__pyx_k_text), 0, 1, 0, 1},
  {&__pyx_n_s_throw, __pyx_k_throw, sizeof(__pyx_k_throw), 0, 0, 1, 1},
  {&__pyx_n_u_thumbnail, __pyx_k_thumbnail, sizeof(__pyx_k_thumbnail), 0, 1, 0, 1},
  {&__pyx_n_s_timedelta, __pyx_k_timedelta, sizeof(__pyx_k_timedelta), 0, 0, 1, 1},
  {&__pyx_n_s_timeout, __pyx_k_timeout, sizeof(__pyx_k_timeout), 0, 0, 1, 1},
  {&__pyx_n_s_title, __pyx_k_title, sizeof(__pyx_k_title), 0, 0, 1, 1},
  {&__pyx_n_u_title, __pyx_k_title, sizeof(__pyx_k_title), 0, 1, 0, 1},
  {&__pyx_n_u_today, __pyx_k_today, sizeof(__pyx_k_today), 0, 1, 0, 1},
  {&__pyx_n_u_type, __pyx_k_type, sizeof(__pyx_k_type), 0, 1, 0, 1},
  {&__pyx_n_s_typing, __pyx_k_typing, sizeof(__pyx_k_typing), 0, 0, 1, 1},
  {&__pyx_n_u_unicode, __pyx_k_unicode, sizeof(__pyx_k_unicode), 0, 1, 0, 1},
  {&__pyx_n_s_updateLastNotice, __pyx_k_updateLastNotice, sizeof(__pyx_k_updateLastNotice), 0, 0, 1, 1},
  {&__pyx_n_s_update_last_notice, __pyx_k_update_last_notice, sizeof(__pyx_k_update_last_notice), 0, 0, 1, 1},
  {&__pyx_n_s_url, __pyx_k_url, sizeof(__pyx_k_url), 0, 0, 1, 1},
  {&__pyx_n_s_urllib_error, __pyx_k_urllib_error, sizeof(__pyx_k_urllib_error), 0, 0, 1, 1},
  {&__pyx_n_s_urllib_parse, __pyx_k_urllib_parse, sizeof(__pyx_k_urllib_parse), 0, 0, 1, 1},
  {&__pyx_n_s_urllib_request, __pyx_k_urllib_request, sizeof(__pyx_k_urllib_request), 0, 0, 1, 1},
  {&__pyx_n_s_urlopen, __pyx_k_urlopen, sizeof(__pyx_k_urlopen), 0, 0, 1, 1},
  {&__pyx_n_s_user, __pyx_k_user, sizeof(__pyx_k_user), 0, 0, 1, 1},
  {&__pyx_n_u_user, __pyx_k_user, sizeof(__pyx_k_user), 0, 1, 0, 1},
  {&__pyx_n_u_userRequest, __pyx_k_userRequest, sizeof(__pyx_k_userRequest), 0, 1, 0, 1},
  {&__pyx_n_s_user_category, __pyx_k_user_category, sizeof(__pyx_k_user_category), 0, 0, 1, 1},
  {&__pyx_n_s_user_id, __pyx_k_user_id, sizeof(__pyx_k_user_id), 0, 0, 1, 1},
  {&__pyx_kp_u_utf_8, __pyx_k_utf_8, sizeof(__pyx_k_utf_8), 0, 1, 0, 0},
  {&__pyx_n_s_uvicorn, __pyx_k_uvicorn, sizeof(__pyx_k_uvicorn), 0, 0, 1, 1},
  {&__pyx_n_s_version, __pyx_k_version, sizeof(__pyx_k_version), 0, 0, 1, 1},
  {&__pyx_n_u_version, __pyx_k_version, sizeof(__pyx_k_version), 0, 1, 0, 1},
  {&__pyx_n_u_web, __pyx_k_web, sizeof(__pyx_k_web), 0, 1, 0, 1},
  {&__pyx_n_u_webLink, __pyx_k_webLink, sizeof(__pyx_k_webLink), 0, 1, 0, 1},
  {&__pyx_n_u_webLinkUrl, __pyx_k_webLinkUrl, sizeof(__pyx_k_webLinkUrl), 0, 1, 0, 1},
  {&__pyx_n_s_when, __pyx_k_when, sizeof(__pyx_k_when), 0, 0, 1, 1},
  {&__pyx_n_u_when, __pyx_k_when, sizeof(__pyx_k_when), 0, 1, 0, 1},
  {&__pyx_n_s_writer, __pyx_k_writer, sizeof(__pyx_k_writer), 0, 0, 1, 1},
  {&__pyx_n_s_writers, __pyx_k_writers, sizeof(__pyx_k_writers), 0, 0, 1, 1},
  {&__pyx_kp_u_y_m_d, __pyx_k_y_m_d, sizeof(__pyx_k_y_m_d), 0, 1, 0, 0},
  {&__pyx_n_u_yesterday, __pyx_k_yesterday, sizeof(__pyx_k_yesterday), 0, 1, 0, 1},
  {0, 0, 0, 0, 0, 0, 0}
};
static CYTHON_SMALL_CODE int __Pyx_InitCachedBuiltins(void) {
  __pyx_builtin_print = __Pyx_GetBuiltinName(__pyx_n_s_print); if (!__pyx_builtin_print) __PYX_ERR(0, 96, __pyx_L1_error)
  __pyx_builtin_range = __Pyx_GetBuiltinName(__pyx_n_s_range); if (!__pyx_builtin_range) __PYX_ERR(0, 206, __pyx_L1_error)
  return 0;
  __pyx_L1_error:;
  return -1;
}

static CYTHON_SMALL_CODE int __Pyx_InitCachedConstants(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_InitCachedConstants", 0);

  /* "KakaoChat/kakao.py":96
 *         result = urlopen(url, timeout=2.0, context=context)
 *     except HTTPError:
 *         print("Seems like the server is down now.")             # <<<<<<<<<<<<<<
 *         return None, None, None, None, 0  # make entity
 *     except TimeoutError:
 */
  __pyx_tuple__2 = PyTuple_Pack(1, __pyx_kp_u_Seems_like_the_server_is_down_no); if (unlikely(!__pyx_tuple__2)) __PYX_ERR(0, 96, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__2);
  __Pyx_GIVEREF(__pyx_tuple__2);

  /* "KakaoChat/kakao.py":97
 *     except HTTPError:
 *         print("Seems like the server is down now.")
 *         return None, None, None, None, 0  # make entity             # <<<<<<<<<<<<<<
 *     except TimeoutError:
 *         print("It's taking too long to load website.")
 */
  __pyx_tuple__3 = PyTuple_Pack(5, Py_None, Py_None, Py_None, Py_None, __pyx_int_0); if (unlikely(!__pyx_tuple__3)) __PYX_ERR(0, 97, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__3);
  __Pyx_GIVEREF(__pyx_tuple__3);

  /* "KakaoChat/kakao.py":99
 *         return None, None, None, None, 0  # make entity
 *     except TimeoutError:
 *         print("It's taking too long to load website.")             # <<<<<<<<<<<<<<
 *         return None, None, None, None, 0  # make entity
 * 
 */
  __pyx_tuple__4 = PyTuple_Pack(1, __pyx_kp_u_It_s_taking_too_long_to_load_web); if (unlikely(!__pyx_tuple__4)) __PYX_ERR(0, 99, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__4);
  __Pyx_GIVEREF(__pyx_tuple__4);

  /* "KakaoChat/kakao.py":124
 *         return False
 *     except URLError:
 *         print("Seems like the url is wrong now.")             # <<<<<<<<<<<<<<
 *         return False
 *     except TimeoutError:
 */
  __pyx_tuple__5 = PyTuple_Pack(1, __pyx_kp_u_Seems_like_the_url_is_wrong_now); if (unlikely(!__pyx_tuple__5)) __PYX_ERR(0, 124, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__5);
  __Pyx_GIVEREF(__pyx_tuple__5);

  /* "KakaoChat/kakao.py":139
 * 
 *     return {
 *         "title": (postTitle[:32] + "...") if len(postTitle) > 35 else postTitle,             # <<<<<<<<<<<<<<
 *         "description": postWriter,
 *         # "imageUrl": "http://k.kakaocdn.net/dn/APR96/btqqH7zLanY/kD5mIPX7TdD2NAxgP29cC0/1x1.jpg",
 */
  __pyx_slice__9 = PySlice_New(Py_None, __pyx_int_32, Py_None); if (unlikely(!__pyx_slice__9)) __PYX_ERR(0, 139, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_slice__9);
  __Pyx_GIVEREF(__pyx_slice__9);

  /* "KakaoChat/kakao.py":273
 *                     "listCard": {
 *                         "header": {"title": f"{now}) {DAY} "},
 *                         "items": notices[:5],             # <<<<<<<<<<<<<<
 *                         "buttons": [
 *                             {"label": "", "action": "share"},
 */
  __pyx_slice__18 = PySlice_New(Py_None, __pyx_int_5, Py_None); if (unlikely(!__pyx_slice__18)) __PYX_ERR(0, 273, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_slice__18);
  __Pyx_GIVEREF(__pyx_slice__18);

  /* "KakaoChat/kakao.py":306
 *     # user_id = content["userRequest"]["user"]["id"]  # user Id
 *     # checkUserDB(user_id)
 *     print(">>> /ask")             # <<<<<<<<<<<<<<
 * 
 *     categories = [
 */
  __pyx_tuple__25 = PyTuple_Pack(1, __pyx_kp_u_ask); if (unlikely(!__pyx_tuple__25)) __PYX_ERR(0, 306, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__25);
  __Pyx_GIVEREF(__pyx_tuple__25);

  /* "KakaoChat/kakao.py":340
 * def searchDate(content: Dict):
 *     """WIP"""
 *     print(">>> /date")             # <<<<<<<<<<<<<<
 *     # print(content["action"]["params"]["date"])
 *     return JSONResponse(content={})
 */
  __pyx_tuple__38 = PyTuple_Pack(1, __pyx_kp_u_date_2); if (unlikely(!__pyx_tuple__38)) __PYX_ERR(0, 340, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__38);
  __Pyx_GIVEREF(__pyx_tuple__38);

  /* "KakaoChat/kakao.py":350
 *     user_id = content["userRequest"]["user"]["id"]  # user Id
 *     checkUserDB(db, user_id)
 *     print(">>> /ask/filter")             # <<<<<<<<<<<<<<
 *     # pprint(content)
 *     # print(content["action"]["params"]["cate"])
 */
  __pyx_tuple__39 = PyTuple_Pack(1, __pyx_kp_u_ask_filter); if (unlikely(!__pyx_tuple__39)) __PYX_ERR(0, 350, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__39);
  __Pyx_GIVEREF(__pyx_tuple__39);

  /* "KakaoChat/kakao.py":374
 *     }
 * 
 *     user_category = content["action"]["params"]["cate"].replace(             # <<<<<<<<<<<<<<
 *         " ", ""
 *     )  # remove whitespace
 */
  __pyx_tuple__41 = PyTuple_Pack(2, __pyx_kp_u__11, __pyx_kp_u__8); if (unlikely(!__pyx_tuple__41)) __PYX_ERR(0, 374, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__41);
  __Pyx_GIVEREF(__pyx_tuple__41);

  /* "KakaoChat/kakao.py":433
 *     user_id = content["userRequest"]["user"]["id"]  # user Id
 *     checkUserDB(db, user_id)
 *     print("/last")             # <<<<<<<<<<<<<<
 *     if not checkConnection():
 *         return makeTimeoutMessage()
 */
  __pyx_tuple__42 = PyTuple_Pack(1, __pyx_kp_u_last); if (unlikely(!__pyx_tuple__42)) __PYX_ERR(0, 433, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__42);
  __Pyx_GIVEREF(__pyx_tuple__42);

  /* "KakaoChat/kakao.py":466
 *     checkUserDB(db, user_id)
 * 
 *     print(">>> /search")             # <<<<<<<<<<<<<<
 *     if not checkConnection():
 *         return makeTimeoutMessage()
 */
  __pyx_tuple__43 = PyTuple_Pack(1, __pyx_kp_u_search); if (unlikely(!__pyx_tuple__43)) __PYX_ERR(0, 466, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__43);
  __Pyx_GIVEREF(__pyx_tuple__43);

  /* "KakaoChat/kakao.py":524
 *                 {
 *                     "listCard": {
 *                         "header": {"title": f"{keyword[:12]} "},             # <<<<<<<<<<<<<<
 *                         "items": notices[:5],
 *                         "buttons": [
 */
  __pyx_slice__45 = PySlice_New(Py_None, __pyx_int_12, Py_None); if (unlikely(!__pyx_slice__45)) __PYX_ERR(0, 524, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_slice__45);
  __Pyx_GIVEREF(__pyx_slice__45);

  /* "KakaoChat/kakao.py":553
 *     user_id = content["userRequest"]["user"]["id"]  # user Id
 *     checkUserDB(db, user_id)
 *     print(">>> /message")             # <<<<<<<<<<<<<<
 *     if not checkConnection():
 *         return makeTimeoutMessage()
 */
  __pyx_tuple__52 = PyTuple_Pack(1, __pyx_kp_u_message_2); if (unlikely(!__pyx_tuple__52)) __PYX_ERR(0, 553, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__52);
  __Pyx_GIVEREF(__pyx_tuple__52);

  /* "KakaoChat/kakao.py":577
 *     user_id = content["userRequest"]["user"]["id"]  # user Id
 *     checkUserDB(db, user_id)
 *     print(">>> /schedule")             # <<<<<<<<<<<<<<
 *     cards = []
 *     append = cards.append
 */
  __pyx_tuple__53 = PyTuple_Pack(1, __pyx_kp_u_schedule); if (unlikely(!__pyx_tuple__53)) __PYX_ERR(0, 577, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__53);
  __Pyx_GIVEREF(__pyx_tuple__53);

  /* "KakaoChat/kakao.py":39
 * 
 * # Dependency
 * def get_db():             # <<<<<<<<<<<<<<
 *     db = db_model.database.SessionLocal()
 *     try:
 */
  __pyx_tuple__56 = PyTuple_Pack(1, __pyx_n_s_db); if (unlikely(!__pyx_tuple__56)) __PYX_ERR(0, 39, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__56);
  __Pyx_GIVEREF(__pyx_tuple__56);
  __pyx_codeobj_ = (PyObject*)__Pyx_PyCode_New(0, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__56, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_kakao_py, __pyx_n_s_get_db, 39, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj_)) __PYX_ERR(0, 39, __pyx_L1_error)

  /* "KakaoChat/kakao.py":47
 * 
 * 
 * def checkUserDB(db: Session, user_id: str):             # <<<<<<<<<<<<<<
 *     user = db_model.crud.get_user_by_user_id(db=db, user_id=user_id)
 *     if user is None:
 */
  __pyx_tuple__57 = PyTuple_Pack(3, __pyx_n_s_db, __pyx_n_s_user_id, __pyx_n_s_user); if (unlikely(!__pyx_tuple__57)) __PYX_ERR(0, 47, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__57);
  __Pyx_GIVEREF(__pyx_tuple__57);
  __pyx_codeobj__58 = (PyObject*)__Pyx_PyCode_New(2, 0, 3, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__57, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_kakao_py, __pyx_n_s_checkUserDB, 47, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__58)) __PYX_ERR(0, 47, __pyx_L1_error)

  /* "KakaoChat/kakao.py":54
 * 
 * 
 * def checkLastNotice(db: Session, user_id: str):             # <<<<<<<<<<<<<<
 *     user = db_model.crud.get_user_by_user_id(db=db, user_id=user_id)
 *     if user is None:
 */
  __pyx_tuple__59 = PyTuple_Pack(4, __pyx_n_s_db, __pyx_n_s_user_id, __pyx_n_s_user, __pyx_n_s_last_id); if (unlikely(!__pyx_tuple__59)) __PYX_ERR(0, 54, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__59);
  __Pyx_GIVEREF(__pyx_tuple__59);
  __pyx_codeobj__60 = (PyObject*)__Pyx_PyCode_New(2, 0, 4, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__59, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_kakao_py, __pyx_n_s_checkLastNotice, 54, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__60)) __PYX_ERR(0, 54, __pyx_L1_error)

  /* "KakaoChat/kakao.py":62
 * 
 * 
 * def getSchedule(db: Session):             # <<<<<<<<<<<<<<
 *     return db_model.crud.get_all_sched(db=db)
 * 
 */
  __pyx_tuple__61 = PyTuple_Pack(1, __pyx_n_s_db); if (unlikely(!__pyx_tuple__61)) __PYX_ERR(0, 62, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__61);
  __Pyx_GIVEREF(__pyx_tuple__61);
  __pyx_codeobj__62 = (PyObject*)__Pyx_PyCode_New(1, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__61, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_kakao_py, __pyx_n_s_getSchedule, 62, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__62)) __PYX_ERR(0, 62, __pyx_L1_error)

  /* "KakaoChat/kakao.py":66
 * 
 * 
 * def updateLastNotice(db: Session, user_id: str, notice_id: int):             # <<<<<<<<<<<<<<
 *     user = db_model.crud.get_user_by_user_id(db=db, user_id=user_id)
 *     if user is None:
 */
  __pyx_tuple__63 = PyTuple_Pack(4, __pyx_n_s_db, __pyx_n_s_user_id, __pyx_n_s_notice_id, __pyx_n_s_user); if (unlikely(!__pyx_tuple__63)) __PYX_ERR(0, 66, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__63);
  __Pyx_GIVEREF(__pyx_tuple__63);
  __pyx_codeobj__64 = (PyObject*)__Pyx_PyCode_New(3, 0, 4, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__63, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_kakao_py, __pyx_n_s_updateLastNotice, 66, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__64)) __PYX_ERR(0, 66, __pyx_L1_error)

  /* "KakaoChat/kakao.py":79
 * 
 * 
 * def parseNotices(url=None, length=10):             # <<<<<<<<<<<<<<
 *     """
 * 
 */
  __pyx_tuple__65 = PyTuple_Pack(11, __pyx_n_s_url, __pyx_n_s_length, __pyx_n_s_context, __pyx_n_s_result, __pyx_n_s_html, __pyx_n_s_soup, __pyx_n_s_no_post, __pyx_n_s_ids, __pyx_n_s_posts, __pyx_n_s_dates, __pyx_n_s_writers); if (unlikely(!__pyx_tuple__65)) __PYX_ERR(0, 79, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__65);
  __Pyx_GIVEREF(__pyx_tuple__65);
  __pyx_codeobj__66 = (PyObject*)__Pyx_PyCode_New(2, 0, 11, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__65, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_kakao_py, __pyx_n_s_parseNotices, 79, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__66)) __PYX_ERR(0, 79, __pyx_L1_error)
  __pyx_tuple__67 = PyTuple_Pack(2, ((PyObject *)Py_None), ((PyObject *)__pyx_int_10)); if (unlikely(!__pyx_tuple__67)) __PYX_ERR(0, 79, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__67);
  __Pyx_GIVEREF(__pyx_tuple__67);

  /* "KakaoChat/kakao.py":115
 * 
 * 
 * def checkConnection():             # <<<<<<<<<<<<<<
 *     """   . """
 *     context = ssl._create_unverified_context()
 */
  __pyx_tuple__68 = PyTuple_Pack(1, __pyx_n_s_context); if (unlikely(!__pyx_tuple__68)) __PYX_ERR(0, 115, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__68);
  __Pyx_GIVEREF(__pyx_tuple__68);
  __pyx_codeobj__69 = (PyObject*)__Pyx_PyCode_New(0, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__68, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_kakao_py, __pyx_n_s_checkConnection, 115, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__69)) __PYX_ERR(0, 115, __pyx_L1_error)

  /* "KakaoChat/kakao.py":132
 * 
 * 
 * def makeJSON(postId, postTitle, postDate, postLink, postWriter):             # <<<<<<<<<<<<<<
 *     """   """
 *     duplicate = "[" + postWriter + "]"
 */
  __pyx_tuple__70 = PyTuple_Pack(6, __pyx_n_s_postId, __pyx_n_s_postTitle, __pyx_n_s_postDate, __pyx_n_s_postLink, __pyx_n_s_postWriter, __pyx_n_s_duplicate); if (unlikely(!__pyx_tuple__70)) __PYX_ERR(0, 132, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__70);
  __Pyx_GIVEREF(__pyx_tuple__70);
  __pyx_codeobj__71 = (PyObject*)__Pyx_PyCode_New(5, 0, 6, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__70, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_kakao_py, __pyx_n_s_makeJSON, 132, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__71)) __PYX_ERR(0, 132, __pyx_L1_error)

  /* "KakaoChat/kakao.py":146
 * 
 * 
 * def makeJSONwithDate(postId, postTitle, postDate, postLink, postWriter):             # <<<<<<<<<<<<<<
 *     """   , writer  ."""
 *     duplicate = "[" + postWriter + "]"
 */
  __pyx_tuple__72 = PyTuple_Pack(6, __pyx_n_s_postId, __pyx_n_s_postTitle, __pyx_n_s_postDate, __pyx_n_s_postLink, __pyx_n_s_postWriter, __pyx_n_s_duplicate); if (unlikely(!__pyx_tuple__72)) __PYX_ERR(0, 146, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__72);
  __Pyx_GIVEREF(__pyx_tuple__72);
  __pyx_codeobj__73 = (PyObject*)__Pyx_PyCode_New(5, 0, 6, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__72, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_kakao_py, __pyx_n_s_makeJSONwithDate, 146, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__73)) __PYX_ERR(0, 146, __pyx_L1_error)

  /* "KakaoChat/kakao.py":159
 * 
 * 
 * def makeTimeoutMessage():             # <<<<<<<<<<<<<<
 *     """ checkConnection()  False,  JSON  return"""
 *     return JSONResponse(
 */
  __pyx_codeobj__74 = (PyObject*)__Pyx_PyCode_New(0, 0, 0, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_kakao_py, __pyx_n_s_makeTimeoutMessage, 159, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__74)) __PYX_ERR(0, 159, __pyx_L1_error)

  /* "KakaoChat/kakao.py":177
 * 
 * 
 * def makeCarouselCard(title, desc):             # <<<<<<<<<<<<<<
 *     card_imgs = ["ajou_carousel", "ajou_carousel_1", "ajou_carousel_2"]
 *     card = {
 */
  __pyx_tuple__75 = PyTuple_Pack(4, __pyx_n_s_title, __pyx_n_s_desc, __pyx_n_s_card_imgs, __pyx_n_s_card); if (unlikely(!__pyx_tuple__75)) __PYX_ERR(0, 177, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__75);
  __Pyx_GIVEREF(__pyx_tuple__75);
  __pyx_codeobj__76 = (PyObject*)__Pyx_PyCode_New(2, 0, 4, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__75, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_kakao_py, __pyx_n_s_makeCarouselCard, 177, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__76)) __PYX_ERR(0, 177, __pyx_L1_error)

  /* "KakaoChat/kakao.py":197
 * 
 * 
 * def getTodayNotices(db, now, user_id):             # <<<<<<<<<<<<<<
 *     """ 30    ,    return"""
 *     noticesToday = []
 */
  __pyx_tuple__77 = PyTuple_Pack(17, __pyx_n_s_db, __pyx_n_s_now, __pyx_n_s_user_id, __pyx_n_s_noticesToday, __pyx_n_s_length, __pyx_n_s_ids, __pyx_n_s_posts, __pyx_n_s_dates, __pyx_n_s_writers, __pyx_n_s_noticeLength, __pyx_n_s_i, __pyx_n_s_postDate, __pyx_n_s_postTitle, __pyx_n_s_postId, __pyx_n_s_postLink, __pyx_n_s_postWriter, __pyx_n_s_data); if (unlikely(!__pyx_tuple__77)) __PYX_ERR(0, 197, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__77);
  __Pyx_GIVEREF(__pyx_tuple__77);
  __pyx_codeobj__78 = (PyObject*)__Pyx_PyCode_New(3, 0, 17, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__77, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_kakao_py, __pyx_n_s_getTodayNotices, 197, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__78)) __PYX_ERR(0, 197, __pyx_L1_error)

  /* "KakaoChat/kakao.py":223
 * 
 * 
 * def getYesterdayNotices(db, now):             # <<<<<<<<<<<<<<
 *     """   MySQL   . """
 *     db_notices = db_model.crud.get_notices_with_date(db=db, date=now)
 */
  __pyx_tuple__79 = PyTuple_Pack(6, __pyx_n_s_db, __pyx_n_s_now, __pyx_n_s_db_notices, __pyx_n_s_notices, __pyx_n_s_notice, __pyx_n_s_data); if (unlikely(!__pyx_tuple__79)) __PYX_ERR(0, 223, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__79);
  __Pyx_GIVEREF(__pyx_tuple__79);
  __pyx_codeobj__80 = (PyObject*)__Pyx_PyCode_New(2, 0, 6, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__79, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_kakao_py, __pyx_n_s_getYesterdayNotices, 223, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__80)) __PYX_ERR(0, 223, __pyx_L1_error)

  /* "KakaoChat/kakao.py":237
 * 
 * 
 * def getLastNotice():             # <<<<<<<<<<<<<<
 *     """  1  . """
 *     ids, posts, dates, writers, _ = parseNotices(length=1)  # Parse one notice
 */
  __pyx_tuple__82 = PyTuple_Pack(11, __pyx_n_s_ids, __pyx_n_s_posts, __pyx_n_s_dates, __pyx_n_s_writers, __pyx_n_s__81, __pyx_n_s_postDate, __pyx_n_s_postTitle, __pyx_n_s_postId, __pyx_n_s_postLink, __pyx_n_s_postWriter, __pyx_n_s_data); if (unlikely(!__pyx_tuple__82)) __PYX_ERR(0, 237, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__82);
  __Pyx_GIVEREF(__pyx_tuple__82);
  __pyx_codeobj__83 = (PyObject*)__Pyx_PyCode_New(0, 0, 11, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__82, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_kakao_py, __pyx_n_s_getLastNotice, 237, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__83)) __PYX_ERR(0, 237, __pyx_L1_error)

  /* "KakaoChat/kakao.py":250
 * 
 * 
 * def switch(db, when, now, user_id):             # <<<<<<<<<<<<<<
 *     """ /    switch """
 *     DAY = "" if when == "today" else ""
 */
  __pyx_tuple__84 = PyTuple_Pack(7, __pyx_n_s_db, __pyx_n_s_when, __pyx_n_s_now, __pyx_n_s_user_id, __pyx_n_s_DAY, __pyx_n_s_notices, __pyx_n_s_data); if (unlikely(!__pyx_tuple__84)) __PYX_ERR(0, 250, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__84);
  __Pyx_GIVEREF(__pyx_tuple__84);
  __pyx_codeobj__85 = (PyObject*)__Pyx_PyCode_New(4, 0, 7, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__84, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_kakao_py, __pyx_n_s_switch, 250, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__85)) __PYX_ERR(0, 250, __pyx_L1_error)

  /* "KakaoChat/kakao.py":296
 * 
 * 
 * @application.get("/")             # <<<<<<<<<<<<<<
 * def hello():
 *     return "Welcome, the server is running well."
 */
  __pyx_tuple__87 = PyTuple_Pack(1, __pyx_kp_u__86); if (unlikely(!__pyx_tuple__87)) __PYX_ERR(0, 296, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__87);
  __Pyx_GIVEREF(__pyx_tuple__87);

  /* "KakaoChat/kakao.py":297
 * 
 * @application.get("/")
 * def hello():             # <<<<<<<<<<<<<<
 *     return "Welcome, the server is running well."
 * 
 */
  __pyx_codeobj__88 = (PyObject*)__Pyx_PyCode_New(0, 0, 0, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_kakao_py, __pyx_n_s_hello, 297, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__88)) __PYX_ERR(0, 297, __pyx_L1_error)

  /* "KakaoChat/kakao.py":301
 * 
 * 
 * @application.post("/ask")             # <<<<<<<<<<<<<<
 * def askKeyword(_: Dict):
 *     """    """
 */
  __pyx_tuple__89 = PyTuple_Pack(1, __pyx_kp_u_ask_2); if (unlikely(!__pyx_tuple__89)) __PYX_ERR(0, 301, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__89);
  __Pyx_GIVEREF(__pyx_tuple__89);

  /* "KakaoChat/kakao.py":302
 * 
 * @application.post("/ask")
 * def askKeyword(_: Dict):             # <<<<<<<<<<<<<<
 *     """    """
 *     # user_id = content["userRequest"]["user"]["id"]  # user Id
 */
  __pyx_tuple__90 = PyTuple_Pack(5, __pyx_n_s__81, __pyx_n_s_categories, __pyx_n_s_replies, __pyx_n_s_data, __pyx_n_s_category); if (unlikely(!__pyx_tuple__90)) __PYX_ERR(0, 302, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__90);
  __Pyx_GIVEREF(__pyx_tuple__90);
  __pyx_codeobj__91 = (PyObject*)__Pyx_PyCode_New(1, 0, 5, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__90, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_kakao_py, __pyx_n_s_askKeyword, 302, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__91)) __PYX_ERR(0, 302, __pyx_L1_error)

  /* "KakaoChat/kakao.py":337
 * 
 * 
 * @application.post("/date")             # <<<<<<<<<<<<<<
 * def searchDate(content: Dict):
 *     """WIP"""
 */
  __pyx_tuple__92 = PyTuple_Pack(1, __pyx_kp_u_date_3); if (unlikely(!__pyx_tuple__92)) __PYX_ERR(0, 337, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__92);
  __Pyx_GIVEREF(__pyx_tuple__92);

  /* "KakaoChat/kakao.py":338
 * 
 * @application.post("/date")
 * def searchDate(content: Dict):             # <<<<<<<<<<<<<<
 *     """WIP"""
 *     print(">>> /date")
 */
  __pyx_tuple__93 = PyTuple_Pack(1, __pyx_n_s_content); if (unlikely(!__pyx_tuple__93)) __PYX_ERR(0, 338, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__93);
  __Pyx_GIVEREF(__pyx_tuple__93);
  __pyx_codeobj__94 = (PyObject*)__Pyx_PyCode_New(1, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__93, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_kakao_py, __pyx_n_s_searchDate, 338, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__94)) __PYX_ERR(0, 338, __pyx_L1_error)

  /* "KakaoChat/kakao.py":345
 * 
 * 
 * @application.post("/ask/filter")             # <<<<<<<<<<<<<<
 * def searchKeyword(content: Dict, db: Session = Depends(get_db)):
 *     """   .  type: ListCard"""
 */
  __pyx_tuple__95 = PyTuple_Pack(1, __pyx_kp_u_ask_filter_2); if (unlikely(!__pyx_tuple__95)) __PYX_ERR(0, 345, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__95);
  __Pyx_GIVEREF(__pyx_tuple__95);

  /* "KakaoChat/kakao.py":346
 * 
 * @application.post("/ask/filter")
 * def searchKeyword(content: Dict, db: Session = Depends(get_db)):             # <<<<<<<<<<<<<<
 *     """   .  type: ListCard"""
 *     user_id = content["userRequest"]["user"]["id"]  # user Id
 */
  __pyx_tuple__96 = PyTuple_Pack(20, __pyx_n_s_content, __pyx_n_s_db, __pyx_n_s_user_id, __pyx_n_s_length, __pyx_n_s_categories, __pyx_n_s_user_category, __pyx_n_s_url, __pyx_n_s_ids, __pyx_n_s_posts, __pyx_n_s_dates, __pyx_n_s_writers, __pyx_n_s_noticeLength, __pyx_n_s_notices, __pyx_n_s_i, __pyx_n_s_postDate, __pyx_n_s_postTitle, __pyx_n_s_postId, __pyx_n_s_postLink, __pyx_n_s_postWriter, __pyx_n_s_data); if (unlikely(!__pyx_tuple__96)) __PYX_ERR(0, 346, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__96);
  __Pyx_GIVEREF(__pyx_tuple__96);
  __pyx_codeobj__97 = (PyObject*)__Pyx_PyCode_New(2, 0, 20, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__96, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_kakao_py, __pyx_n_s_searchKeyword, 346, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__97)) __PYX_ERR(0, 346, __pyx_L1_error)

  /* "KakaoChat/kakao.py":429
 * 
 * @application.post("/last")
 * def parseOne(content: Dict, db: Session = Depends(get_db)):             # <<<<<<<<<<<<<<
 *     """    1 .  type: ListCard"""
 *     user_id = content["userRequest"]["user"]["id"]  # user Id
 */
  __pyx_tuple__98 = PyTuple_Pack(6, __pyx_n_s_content, __pyx_n_s_db, __pyx_n_s_user_id, __pyx_n_s_notice, __pyx_n_s_date, __pyx_n_s_data); if (unlikely(!__pyx_tuple__98)) __PYX_ERR(0, 429, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__98);
  __Pyx_GIVEREF(__pyx_tuple__98);
  __pyx_codeobj__99 = (PyObject*)__Pyx_PyCode_New(2, 0, 6, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__98, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_kakao_py, __pyx_n_s_parseOne, 429, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__99)) __PYX_ERR(0, 429, __pyx_L1_error)

  /* "KakaoChat/kakao.py":460
 * 
 * 
 * @application.post("/search")             # <<<<<<<<<<<<<<
 * def searchNotice(content: Dict, db: Session = Depends(get_db)):
 *     """    .  type: simpleText | ListCard"""
 */
  __pyx_tuple__100 = PyTuple_Pack(1, __pyx_kp_u_search_2); if (unlikely(!__pyx_tuple__100)) __PYX_ERR(0, 460, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__100);
  __Pyx_GIVEREF(__pyx_tuple__100);

  /* "KakaoChat/kakao.py":461
 * 
 * @application.post("/search")
 * def searchNotice(content: Dict, db: Session = Depends(get_db)):             # <<<<<<<<<<<<<<
 *     """    .  type: simpleText | ListCard"""
 *     user_id = content["userRequest"]["user"]["id"]  # user Id
 */
  __pyx_tuple__101 = PyTuple_Pack(19, __pyx_n_s_content, __pyx_n_s_db, __pyx_n_s_user_id, __pyx_n_s_keyword, __pyx_n_s_length, __pyx_n_s_url, __pyx_n_s_ids, __pyx_n_s_posts, __pyx_n_s_dates, __pyx_n_s_writers, __pyx_n_s_noticeLength, __pyx_n_s_notices, __pyx_n_s_i, __pyx_n_s_postDate, __pyx_n_s_postTitle, __pyx_n_s_postId, __pyx_n_s_postLink, __pyx_n_s_postWriter, __pyx_n_s_data); if (unlikely(!__pyx_tuple__101)) __PYX_ERR(0, 461, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__101);
  __Pyx_GIVEREF(__pyx_tuple__101);
  __pyx_codeobj__102 = (PyObject*)__Pyx_PyCode_New(2, 0, 19, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__101, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_kakao_py, __pyx_n_s_searchNotice, 461, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__102)) __PYX_ERR(0, 461, __pyx_L1_error)

  /* "KakaoChat/kakao.py":548
 * 
 * 
 * @application.post("/message")             # <<<<<<<<<<<<<<
 * def message(content: Dict, db: Session = Depends(get_db)):
 *     """/    route |  type: ListCard """
 */
  __pyx_tuple__103 = PyTuple_Pack(1, __pyx_kp_u_message_3); if (unlikely(!__pyx_tuple__103)) __PYX_ERR(0, 548, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__103);
  __Pyx_GIVEREF(__pyx_tuple__103);

  /* "KakaoChat/kakao.py":549
 * 
 * @application.post("/message")
 * def message(content: Dict, db: Session = Depends(get_db)):             # <<<<<<<<<<<<<<
 *     """/    route |  type: ListCard """
 *     user_id = content["userRequest"]["user"]["id"]  # user Id
 */
  __pyx_tuple__104 = PyTuple_Pack(6, __pyx_n_s_content, __pyx_n_s_db, __pyx_n_s_user_id, __pyx_n_s_when, __pyx_n_s_now, __pyx_n_s_response_data); if (unlikely(!__pyx_tuple__104)) __PYX_ERR(0, 549, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__104);
  __Pyx_GIVEREF(__pyx_tuple__104);
  __pyx_codeobj__105 = (PyObject*)__Pyx_PyCode_New(2, 0, 6, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__104, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_kakao_py, __pyx_n_s_message, 549, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__105)) __PYX_ERR(0, 549, __pyx_L1_error)

  /* "KakaoChat/kakao.py":572
 * 
 * 
 * @application.post("/schedule")             # <<<<<<<<<<<<<<
 * def schedule(content: Dict, db: Session = Depends(get_db)):
 *     """MySQL DB   |  type: Carousel BasicCards """
 */
  __pyx_tuple__106 = PyTuple_Pack(1, __pyx_kp_u_schedule_2); if (unlikely(!__pyx_tuple__106)) __PYX_ERR(0, 572, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__106);
  __Pyx_GIVEREF(__pyx_tuple__106);

  /* "KakaoChat/kakao.py":573
 * 
 * @application.post("/schedule")
 * def schedule(content: Dict, db: Session = Depends(get_db)):             # <<<<<<<<<<<<<<
 *     """MySQL DB   |  type: Carousel BasicCards """
 *     user_id = content["userRequest"]["user"]["id"]  # user Id
 */
  __pyx_tuple__107 = PyTuple_Pack(7, __pyx_n_s_content, __pyx_n_s_db, __pyx_n_s_user_id, __pyx_n_s_cards, __pyx_n_s_append, __pyx_n_s_scheds, __pyx_n_s_sched); if (unlikely(!__pyx_tuple__107)) __PYX_ERR(0, 573, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__107);
  __Pyx_GIVEREF(__pyx_tuple__107);
  __pyx_codeobj__108 = (PyObject*)__Pyx_PyCode_New(2, 0, 7, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__107, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_kakao_py, __pyx_n_s_schedule_3, 573, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__108)) __PYX_ERR(0, 573, __pyx_L1_error)
  __Pyx_RefNannyFinishContext();
  return 0;
  __pyx_L1_error:;
  __Pyx_RefNannyFinishContext();
  return -1;
}

static CYTHON_SMALL_CODE int __Pyx_InitGlobals(void) {
  if (__Pyx_InitStrings(__pyx_string_tab) < 0) __PYX_ERR(0, 1, __pyx_L1_error);
  __pyx_float_2_0 = PyFloat_FromDouble(2.0); if (unlikely(!__pyx_float_2_0)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_0 = PyInt_FromLong(0); if (unlikely(!__pyx_int_0)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_1 = PyInt_FromLong(1); if (unlikely(!__pyx_int_1)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_2 = PyInt_FromLong(2); if (unlikely(!__pyx_int_2)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_3 = PyInt_FromLong(3); if (unlikely(!__pyx_int_3)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_4 = PyInt_FromLong(4); if (unlikely(!__pyx_int_4)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_5 = PyInt_FromLong(5); if (unlikely(!__pyx_int_5)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_6 = PyInt_FromLong(6); if (unlikely(!__pyx_int_6)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_7 = PyInt_FromLong(7); if (unlikely(!__pyx_int_7)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_8 = PyInt_FromLong(8); if (unlikely(!__pyx_int_8)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_10 = PyInt_FromLong(10); if (unlikely(!__pyx_int_10)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_12 = PyInt_FromLong(12); if (unlikely(!__pyx_int_12)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_32 = PyInt_FromLong(32); if (unlikely(!__pyx_int_32)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_166 = PyInt_FromLong(166); if (unlikely(!__pyx_int_166)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_167 = PyInt_FromLong(167); if (unlikely(!__pyx_int_167)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_168 = PyInt_FromLong(168); if (unlikely(!__pyx_int_168)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_8000 = PyInt_FromLong(8000); if (unlikely(!__pyx_int_8000)) __PYX_ERR(0, 1, __pyx_L1_error)
  return 0;
  __pyx_L1_error:;
  return -1;
}

static CYTHON_SMALL_CODE int __Pyx_modinit_global_init_code(void); /*proto*/
static CYTHON_SMALL_CODE int __Pyx_modinit_variable_export_code(void); /*proto*/
static CYTHON_SMALL_CODE int __Pyx_modinit_function_export_code(void); /*proto*/
static CYTHON_SMALL_CODE int __Pyx_modinit_type_init_code(void); /*proto*/
static CYTHON_SMALL_CODE int __Pyx_modinit_type_import_code(void); /*proto*/
static CYTHON_SMALL_CODE int __Pyx_modinit_variable_import_code(void); /*proto*/
static CYTHON_SMALL_CODE int __Pyx_modinit_function_import_code(void); /*proto*/

static int __Pyx_modinit_global_init_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_global_init_code", 0);
  /*--- Global init code ---*/
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_variable_export_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_variable_export_code", 0);
  /*--- Variable export code ---*/
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_function_export_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_function_export_code", 0);
  /*--- Function export code ---*/
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_type_init_code(void) {
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__Pyx_modinit_type_init_code", 0);
  /*--- Type init code ---*/
  if (PyType_Ready(&__pyx_type_9KakaoChat_5kakao___pyx_scope_struct__get_db) < 0) __PYX_ERR(0, 39, __pyx_L1_error)
  #if PY_VERSION_HEX < 0x030800B1
  __pyx_type_9KakaoChat_5kakao___pyx_scope_struct__get_db.tp_print = 0;
  #endif
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type_9KakaoChat_5kakao___pyx_scope_struct__get_db.tp_dictoffset && __pyx_type_9KakaoChat_5kakao___pyx_scope_struct__get_db.tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_type_9KakaoChat_5kakao___pyx_scope_struct__get_db.tp_getattro = __Pyx_PyObject_GenericGetAttrNoDict;
  }
  __pyx_ptype_9KakaoChat_5kakao___pyx_scope_struct__get_db = &__pyx_type_9KakaoChat_5kakao___pyx_scope_struct__get_db;
  __Pyx_RefNannyFinishContext();
  return 0;
  __pyx_L1_error:;
  __Pyx_RefNannyFinishContext();
  return -1;
}

static int __Pyx_modinit_type_import_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_type_import_code", 0);
  /*--- Type import code ---*/
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_variable_import_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_variable_import_code", 0);
  /*--- Variable import code ---*/
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_function_import_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_function_import_code", 0);
  /*--- Function import code ---*/
  __Pyx_RefNannyFinishContext();
  return 0;
}


#ifndef CYTHON_NO_PYINIT_EXPORT
#define __Pyx_PyMODINIT_FUNC PyMODINIT_FUNC
#elif PY_MAJOR_VERSION < 3
#ifdef __cplusplus
#define __Pyx_PyMODINIT_FUNC extern "C" void
#else
#define __Pyx_PyMODINIT_FUNC void
#endif
#else
#ifdef __cplusplus
#define __Pyx_PyMODINIT_FUNC extern "C" PyObject *
#else
#define __Pyx_PyMODINIT_FUNC PyObject *
#endif
#endif


#if PY_MAJOR_VERSION < 3
__Pyx_PyMODINIT_FUNC initkakao(void) CYTHON_SMALL_CODE; /*proto*/
__Pyx_PyMODINIT_FUNC initkakao(void)
#else
__Pyx_PyMODINIT_FUNC PyInit_kakao(void) CYTHON_SMALL_CODE; /*proto*/
__Pyx_PyMODINIT_FUNC PyInit_kakao(void)
#if CYTHON_PEP489_MULTI_PHASE_INIT
{
  return PyModuleDef_Init(&__pyx_moduledef);
}
static CYTHON_SMALL_CODE int __Pyx_check_single_interpreter(void) {
    #if PY_VERSION_HEX >= 0x030700A1
    static PY_INT64_T main_interpreter_id = -1;
    PY_INT64_T current_id = PyInterpreterState_GetID(PyThreadState_Get()->interp);
    if (main_interpreter_id == -1) {
        main_interpreter_id = current_id;
        return (unlikely(current_id == -1)) ? -1 : 0;
    } else if (unlikely(main_interpreter_id != current_id))
    #else
    static PyInterpreterState *main_interpreter = NULL;
    PyInterpreterState *current_interpreter = PyThreadState_Get()->interp;
    if (!main_interpreter) {
        main_interpreter = current_interpreter;
    } else if (unlikely(main_interpreter != current_interpreter))
    #endif
    {
        PyErr_SetString(
            PyExc_ImportError,
            "Interpreter change detected - this module can only be loaded into one interpreter per process.");
        return -1;
    }
    return 0;
}
static CYTHON_SMALL_CODE int __Pyx_copy_spec_to_module(PyObject *spec, PyObject *moddict, const char* from_name, const char* to_name, int allow_none) {
    PyObject *value = PyObject_GetAttrString(spec, from_name);
    int result = 0;
    if (likely(value)) {
        if (allow_none || value != Py_None) {
            result = PyDict_SetItemString(moddict, to_name, value);
        }
        Py_DECREF(value);
    } else if (PyErr_ExceptionMatches(PyExc_AttributeError)) {
        PyErr_Clear();
    } else {
        result = -1;
    }
    return result;
}
static CYTHON_SMALL_CODE PyObject* __pyx_pymod_create(PyObject *spec, CYTHON_UNUSED PyModuleDef *def) {
    PyObject *module = NULL, *moddict, *modname;
    if (__Pyx_check_single_interpreter())
        return NULL;
    if (__pyx_m)
        return __Pyx_NewRef(__pyx_m);
    modname = PyObject_GetAttrString(spec, "name");
    if (unlikely(!modname)) goto bad;
    module = PyModule_NewObject(modname);
    Py_DECREF(modname);
    if (unlikely(!module)) goto bad;
    moddict = PyModule_GetDict(module);
    if (unlikely(!moddict)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "loader", "__loader__", 1) < 0)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "origin", "__file__", 1) < 0)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "parent", "__package__", 1) < 0)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "submodule_search_locations", "__path__", 0) < 0)) goto bad;
    return module;
bad:
    Py_XDECREF(module);
    return NULL;
}


static CYTHON_SMALL_CODE int __pyx_pymod_exec_kakao(PyObject *__pyx_pyinit_module)
#endif
#endif
{
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  int __pyx_t_7;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannyDeclarations
  #if CYTHON_PEP489_MULTI_PHASE_INIT
  if (__pyx_m) {
    if (__pyx_m == __pyx_pyinit_module) return 0;
    PyErr_SetString(PyExc_RuntimeError, "Module 'kakao' has already been imported. Re-initialisation is not supported.");
    return -1;
  }
  #elif PY_MAJOR_VERSION >= 3
  if (__pyx_m) return __Pyx_NewRef(__pyx_m);
  #endif
  #if CYTHON_REFNANNY
__Pyx_RefNanny = __Pyx_RefNannyImportAPI("refnanny");
if (!__Pyx_RefNanny) {
  PyErr_Clear();
  __Pyx_RefNanny = __Pyx_RefNannyImportAPI("Cython.Runtime.refnanny");
  if (!__Pyx_RefNanny)
      Py_FatalError("failed to import 'refnanny' module");
}
#endif
  __Pyx_RefNannySetupContext("__Pyx_PyMODINIT_FUNC PyInit_kakao(void)", 0);
  if (__Pyx_check_binary_version() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #ifdef __Pxy_PyFrame_Initialize_Offsets
  __Pxy_PyFrame_Initialize_Offsets();
  #endif
  __pyx_empty_tuple = PyTuple_New(0); if (unlikely(!__pyx_empty_tuple)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_empty_bytes = PyBytes_FromStringAndSize("", 0); if (unlikely(!__pyx_empty_bytes)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_empty_unicode = PyUnicode_FromStringAndSize("", 0); if (unlikely(!__pyx_empty_unicode)) __PYX_ERR(0, 1, __pyx_L1_error)
  #ifdef __Pyx_CyFunction_USED
  if (__pyx_CyFunction_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_FusedFunction_USED
  if (__pyx_FusedFunction_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_Coroutine_USED
  if (__pyx_Coroutine_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_Generator_USED
  if (__pyx_Generator_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_AsyncGen_USED
  if (__pyx_AsyncGen_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_StopAsyncIteration_USED
  if (__pyx_StopAsyncIteration_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  /*--- Library function declarations ---*/
  /*--- Threads initialization code ---*/
  #if defined(__PYX_FORCE_INIT_THREADS) && __PYX_FORCE_INIT_THREADS
  #ifdef WITH_THREAD /* Python build with threading support? */
  PyEval_InitThreads();
  #endif
  #endif
  /*--- Module creation code ---*/
  #if CYTHON_PEP489_MULTI_PHASE_INIT
  __pyx_m = __pyx_pyinit_module;
  Py_INCREF(__pyx_m);
  #else
  #if PY_MAJOR_VERSION < 3
  __pyx_m = Py_InitModule4("kakao", __pyx_methods, 0, 0, PYTHON_API_VERSION); Py_XINCREF(__pyx_m);
  #else
  __pyx_m = PyModule_Create(&__pyx_moduledef);
  #endif
  if (unlikely(!__pyx_m)) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  __pyx_d = PyModule_GetDict(__pyx_m); if (unlikely(!__pyx_d)) __PYX_ERR(0, 1, __pyx_L1_error)
  Py_INCREF(__pyx_d);
  __pyx_b = PyImport_AddModule(__Pyx_BUILTIN_MODULE_NAME); if (unlikely(!__pyx_b)) __PYX_ERR(0, 1, __pyx_L1_error)
  Py_INCREF(__pyx_b);
  __pyx_cython_runtime = PyImport_AddModule((char *) "cython_runtime"); if (unlikely(!__pyx_cython_runtime)) __PYX_ERR(0, 1, __pyx_L1_error)
  Py_INCREF(__pyx_cython_runtime);
  if (PyObject_SetAttrString(__pyx_m, "__builtins__", __pyx_b) < 0) __PYX_ERR(0, 1, __pyx_L1_error);
  /*--- Initialize various global constants etc. ---*/
  if (__Pyx_InitGlobals() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #if PY_MAJOR_VERSION < 3 && (__PYX_DEFAULT_STRING_ENCODING_IS_ASCII || __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT)
  if (__Pyx_init_sys_getdefaultencoding_params() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  if (__pyx_module_is_main_KakaoChat__kakao) {
    if (PyObject_SetAttr(__pyx_m, __pyx_n_s_name, __pyx_n_s_main) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  }
  #if PY_MAJOR_VERSION >= 3
  {
    PyObject *modules = PyImport_GetModuleDict(); if (unlikely(!modules)) __PYX_ERR(0, 1, __pyx_L1_error)
    if (!PyDict_GetItemString(modules, "KakaoChat.kakao")) {
      if (unlikely(PyDict_SetItemString(modules, "KakaoChat.kakao", __pyx_m) < 0)) __PYX_ERR(0, 1, __pyx_L1_error)
    }
  }
  #endif
  /*--- Builtin init code ---*/
  if (__Pyx_InitCachedBuiltins() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  /*--- Constants init code ---*/
  if (__Pyx_InitCachedConstants() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  /*--- Global type/function init code ---*/
  (void)__Pyx_modinit_global_init_code();
  (void)__Pyx_modinit_variable_export_code();
  (void)__Pyx_modinit_function_export_code();
  if (unlikely(__Pyx_modinit_type_init_code() < 0)) __PYX_ERR(0, 1, __pyx_L1_error)
  (void)__Pyx_modinit_type_import_code();
  (void)__Pyx_modinit_variable_import_code();
  (void)__Pyx_modinit_function_import_code();
  /*--- Execution code ---*/
  #if defined(__Pyx_Generator_USED) || defined(__Pyx_Coroutine_USED)
  if (__Pyx_patch_abc() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif

  /* "KakaoChat/kakao.py":1
 * import ssl             # <<<<<<<<<<<<<<
 * from datetime import datetime, timedelta
 * from random import choice
 */
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_ssl, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_ssl, __pyx_t_1) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":2
 * import ssl
 * from datetime import datetime, timedelta             # <<<<<<<<<<<<<<
 * from random import choice
 * from typing import Dict
 */
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 2, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_s_datetime);
  __Pyx_GIVEREF(__pyx_n_s_datetime);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_n_s_datetime);
  __Pyx_INCREF(__pyx_n_s_timedelta);
  __Pyx_GIVEREF(__pyx_n_s_timedelta);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_n_s_timedelta);
  __pyx_t_2 = __Pyx_Import(__pyx_n_s_datetime, __pyx_t_1, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 2, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_datetime); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 2, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_datetime, __pyx_t_1) < 0) __PYX_ERR(0, 2, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_timedelta); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 2, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_timedelta, __pyx_t_1) < 0) __PYX_ERR(0, 2, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "KakaoChat/kakao.py":3
 * import ssl
 * from datetime import datetime, timedelta
 * from random import choice             # <<<<<<<<<<<<<<
 * from typing import Dict
 * from urllib.error import HTTPError, URLError
 */
  __pyx_t_2 = PyList_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 3, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_n_s_choice);
  __Pyx_GIVEREF(__pyx_n_s_choice);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_n_s_choice);
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_random, __pyx_t_2, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 3, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_1, __pyx_n_s_choice); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 3, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_choice, __pyx_t_2) < 0) __PYX_ERR(0, 3, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":4
 * from datetime import datetime, timedelta
 * from random import choice
 * from typing import Dict             # <<<<<<<<<<<<<<
 * from urllib.error import HTTPError, URLError
 * from urllib.parse import quote
 */
  __pyx_t_1 = PyList_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 4, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_s_Dict);
  __Pyx_GIVEREF(__pyx_n_s_Dict);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_n_s_Dict);
  __pyx_t_2 = __Pyx_Import(__pyx_n_s_typing, __pyx_t_1, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 4, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_Dict); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 4, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Dict, __pyx_t_1) < 0) __PYX_ERR(0, 4, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "KakaoChat/kakao.py":5
 * from random import choice
 * from typing import Dict
 * from urllib.error import HTTPError, URLError             # <<<<<<<<<<<<<<
 * from urllib.parse import quote
 * from urllib.request import urlopen
 */
  __pyx_t_2 = PyList_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 5, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_n_s_HTTPError);
  __Pyx_GIVEREF(__pyx_n_s_HTTPError);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_n_s_HTTPError);
  __Pyx_INCREF(__pyx_n_s_URLError);
  __Pyx_GIVEREF(__pyx_n_s_URLError);
  PyList_SET_ITEM(__pyx_t_2, 1, __pyx_n_s_URLError);
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_urllib_error, __pyx_t_2, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 5, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_1, __pyx_n_s_HTTPError); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 5, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_HTTPError, __pyx_t_2) < 0) __PYX_ERR(0, 5, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_1, __pyx_n_s_URLError); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 5, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_URLError, __pyx_t_2) < 0) __PYX_ERR(0, 5, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":6
 * from typing import Dict
 * from urllib.error import HTTPError, URLError
 * from urllib.parse import quote             # <<<<<<<<<<<<<<
 * from urllib.request import urlopen
 * 
 */
  __pyx_t_1 = PyList_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 6, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_s_quote);
  __Pyx_GIVEREF(__pyx_n_s_quote);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_n_s_quote);
  __pyx_t_2 = __Pyx_Import(__pyx_n_s_urllib_parse, __pyx_t_1, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 6, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_quote); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 6, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_quote, __pyx_t_1) < 0) __PYX_ERR(0, 6, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "KakaoChat/kakao.py":7
 * from urllib.error import HTTPError, URLError
 * from urllib.parse import quote
 * from urllib.request import urlopen             # <<<<<<<<<<<<<<
 * 
 * import db_model.crud
 */
  __pyx_t_2 = PyList_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 7, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_n_s_urlopen);
  __Pyx_GIVEREF(__pyx_n_s_urlopen);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_n_s_urlopen);
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_urllib_request, __pyx_t_2, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 7, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_1, __pyx_n_s_urlopen); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 7, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_urlopen, __pyx_t_2) < 0) __PYX_ERR(0, 7, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":9
 * from urllib.request import urlopen
 * 
 * import db_model.crud             # <<<<<<<<<<<<<<
 * import db_model.database
 * import db_model.models
 */
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_db_model_crud, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 9, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_db_model, __pyx_t_1) < 0) __PYX_ERR(0, 9, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":10
 * 
 * import db_model.crud
 * import db_model.database             # <<<<<<<<<<<<<<
 * import db_model.models
 * import db_model.schemas
 */
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_db_model_database, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 10, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_db_model, __pyx_t_1) < 0) __PYX_ERR(0, 10, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":11
 * import db_model.crud
 * import db_model.database
 * import db_model.models             # <<<<<<<<<<<<<<
 * import db_model.schemas
 * import uvicorn
 */
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_db_model_models, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 11, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_db_model, __pyx_t_1) < 0) __PYX_ERR(0, 11, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":12
 * import db_model.database
 * import db_model.models
 * import db_model.schemas             # <<<<<<<<<<<<<<
 * import uvicorn
 * from fastapi import Depends, FastAPI
 */
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_db_model_schemas, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 12, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_db_model, __pyx_t_1) < 0) __PYX_ERR(0, 12, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":13
 * import db_model.models
 * import db_model.schemas
 * import uvicorn             # <<<<<<<<<<<<<<
 * from fastapi import Depends, FastAPI
 * from fastapi.middleware.cors import CORSMiddleware
 */
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_uvicorn, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 13, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_uvicorn, __pyx_t_1) < 0) __PYX_ERR(0, 13, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":14
 * import db_model.schemas
 * import uvicorn
 * from fastapi import Depends, FastAPI             # <<<<<<<<<<<<<<
 * from fastapi.middleware.cors import CORSMiddleware
 * from fastapi.responses import JSONResponse
 */
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 14, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_s_Depends);
  __Pyx_GIVEREF(__pyx_n_s_Depends);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_n_s_Depends);
  __Pyx_INCREF(__pyx_n_s_FastAPI);
  __Pyx_GIVEREF(__pyx_n_s_FastAPI);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_n_s_FastAPI);
  __pyx_t_2 = __Pyx_Import(__pyx_n_s_fastapi, __pyx_t_1, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 14, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_Depends); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 14, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Depends, __pyx_t_1) < 0) __PYX_ERR(0, 14, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_FastAPI); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 14, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_FastAPI, __pyx_t_1) < 0) __PYX_ERR(0, 14, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "KakaoChat/kakao.py":15
 * import uvicorn
 * from fastapi import Depends, FastAPI
 * from fastapi.middleware.cors import CORSMiddleware             # <<<<<<<<<<<<<<
 * from fastapi.responses import JSONResponse
 * from selectolax.parser import HTMLParser
 */
  __pyx_t_2 = PyList_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 15, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_n_s_CORSMiddleware);
  __Pyx_GIVEREF(__pyx_n_s_CORSMiddleware);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_n_s_CORSMiddleware);
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_fastapi_middleware_cors, __pyx_t_2, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 15, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_1, __pyx_n_s_CORSMiddleware); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 15, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_CORSMiddleware, __pyx_t_2) < 0) __PYX_ERR(0, 15, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":16
 * from fastapi import Depends, FastAPI
 * from fastapi.middleware.cors import CORSMiddleware
 * from fastapi.responses import JSONResponse             # <<<<<<<<<<<<<<
 * from selectolax.parser import HTMLParser
 * from sqlalchemy.orm import Session
 */
  __pyx_t_1 = PyList_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 16, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_s_JSONResponse);
  __Pyx_GIVEREF(__pyx_n_s_JSONResponse);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_n_s_JSONResponse);
  __pyx_t_2 = __Pyx_Import(__pyx_n_s_fastapi_responses, __pyx_t_1, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 16, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_JSONResponse); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 16, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_JSONResponse, __pyx_t_1) < 0) __PYX_ERR(0, 16, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "KakaoChat/kakao.py":17
 * from fastapi.middleware.cors import CORSMiddleware
 * from fastapi.responses import JSONResponse
 * from selectolax.parser import HTMLParser             # <<<<<<<<<<<<<<
 * from sqlalchemy.orm import Session
 * 
 */
  __pyx_t_2 = PyList_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 17, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_n_s_HTMLParser);
  __Pyx_GIVEREF(__pyx_n_s_HTMLParser);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_n_s_HTMLParser);
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_selectolax_parser, __pyx_t_2, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 17, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_1, __pyx_n_s_HTMLParser); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 17, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_HTMLParser, __pyx_t_2) < 0) __PYX_ERR(0, 17, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "KakaoChat/kakao.py":18
 * from fastapi.responses import JSONResponse
 * from selectolax.parser import HTMLParser
 * from sqlalchemy.orm import Session             # <<<<<<<<<<<<<<
 * 
 * 
 */
  __pyx_t_1 = PyList_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 18, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_s_Session);
  __Pyx_GIVEREF(__pyx_n_s_Session);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_n_s_Session);
  __pyx_t_2 = __Pyx_Import(__pyx_n_s_sqlalchemy_orm, __pyx_t_1, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 18, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_Session); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 18, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Session, __pyx_t_1) < 0) __PYX_ERR(0, 18, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "KakaoChat/kakao.py":21
 * 
 * 
 * ADDRESS = "https://www.ajou.ac.kr/kr/ajou/notice.do"             # <<<<<<<<<<<<<<
 * 
 * db_model.models.Base.metadata.create_all(bind=db_model.database.engine)
 */
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_ADDRESS, __pyx_kp_u_https_www_ajou_ac_kr_kr_ajou_not) < 0) __PYX_ERR(0, 21, __pyx_L1_error)

  /* "KakaoChat/kakao.py":23
 * ADDRESS = "https://www.ajou.ac.kr/kr/ajou/notice.do"
 * 
 * db_model.models.Base.metadata.create_all(bind=db_model.database.engine)             # <<<<<<<<<<<<<<
 * application = FastAPI(
 *     title="Ajou notices server", description="for Kakao Chatbot", version="1.0.0"
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_db_model); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 23, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_models); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 23, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_Base); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 23, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_metadata); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 23, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_create_all); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 23, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 23, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_db_model); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 23, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_database); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 23, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_4, __pyx_n_s_engine); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 23, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_bind, __pyx_t_3) < 0) __PYX_ERR(0, 23, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_empty_tuple, __pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 23, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "KakaoChat/kakao.py":24
 * 
 * db_model.models.Base.metadata.create_all(bind=db_model.database.engine)
 * application = FastAPI(             # <<<<<<<<<<<<<<
 *     title="Ajou notices server", description="for Kakao Chatbot", version="1.0.0"
 * )
 */
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_FastAPI); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 24, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);

  /* "KakaoChat/kakao.py":25
 * db_model.models.Base.metadata.create_all(bind=db_model.database.engine)
 * application = FastAPI(
 *     title="Ajou notices server", description="for Kakao Chatbot", version="1.0.0"             # <<<<<<<<<<<<<<
 * )
 * application.add_middleware(
 */
  __pyx_t_1 = __Pyx_PyDict_NewPresized(3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 25, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_title, __pyx_kp_u_Ajou_notices_server) < 0) __PYX_ERR(0, 25, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_description, __pyx_kp_u_for_Kakao_Chatbot) < 0) __PYX_ERR(0, 25, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_version, __pyx_kp_u_1_0_0) < 0) __PYX_ERR(0, 25, __pyx_L1_error)

  /* "KakaoChat/kakao.py":24
 * 
 * db_model.models.Base.metadata.create_all(bind=db_model.database.engine)
 * application = FastAPI(             # <<<<<<<<<<<<<<
 *     title="Ajou notices server", description="for Kakao Chatbot", version="1.0.0"
 * )
 */
  __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_empty_tuple, __pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 24, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_application, __pyx_t_2) < 0) __PYX_ERR(0, 24, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "KakaoChat/kakao.py":27
 *     title="Ajou notices server", description="for Kakao Chatbot", version="1.0.0"
 * )
 * application.add_middleware(             # <<<<<<<<<<<<<<
 *     CORSMiddleware,
 *     allow_origins=["*"],
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_application); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 27, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_add_middleware); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 27, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "KakaoChat/kakao.py":28
 * )
 * application.add_middleware(
 *     CORSMiddleware,             # <<<<<<<<<<<<<<
 *     allow_origins=["*"],
 *     allow_methods=["*"],
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_CORSMiddleware); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 28, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);

  /* "KakaoChat/kakao.py":27
 *     title="Ajou notices server", description="for Kakao Chatbot", version="1.0.0"
 * )
 * application.add_middleware(             # <<<<<<<<<<<<<<
 *     CORSMiddleware,
 *     allow_origins=["*"],
 */
  __pyx_t_3 = PyTuple_New(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 27, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_2);
  __pyx_t_2 = 0;

  /* "KakaoChat/kakao.py":29
 * application.add_middleware(
 *     CORSMiddleware,
 *     allow_origins=["*"],             # <<<<<<<<<<<<<<
 *     allow_methods=["*"],
 *     allow_headers=["*"],
 */
  __pyx_t_2 = __Pyx_PyDict_NewPresized(4); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 29, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_4 = PyList_New(1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 29, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_INCREF(__pyx_kp_u__55);
  __Pyx_GIVEREF(__pyx_kp_u__55);
  PyList_SET_ITEM(__pyx_t_4, 0, __pyx_kp_u__55);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_allow_origins, __pyx_t_4) < 0) __PYX_ERR(0, 29, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "KakaoChat/kakao.py":30
 *     CORSMiddleware,
 *     allow_origins=["*"],
 *     allow_methods=["*"],             # <<<<<<<<<<<<<<
 *     allow_headers=["*"],
 *     allow_credentials=True,
 */
  __pyx_t_4 = PyList_New(1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 30, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_INCREF(__pyx_kp_u__55);
  __Pyx_GIVEREF(__pyx_kp_u__55);
  PyList_SET_ITEM(__pyx_t_4, 0, __pyx_kp_u__55);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_allow_methods, __pyx_t_4) < 0) __PYX_ERR(0, 29, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "KakaoChat/kakao.py":31
 *     allow_origins=["*"],
 *     allow_methods=["*"],
 *     allow_headers=["*"],             # <<<<<<<<<<<<<<
 *     allow_credentials=True,
 * )
 */
  __pyx_t_4 = PyList_New(1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 31, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_INCREF(__pyx_kp_u__55);
  __Pyx_GIVEREF(__pyx_kp_u__55);
  PyList_SET_ITEM(__pyx_t_4, 0, __pyx_kp_u__55);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_allow_headers, __pyx_t_4) < 0) __PYX_ERR(0, 29, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "KakaoChat/kakao.py":32
 *     allow_methods=["*"],
 *     allow_headers=["*"],
 *     allow_credentials=True,             # <<<<<<<<<<<<<<
 * )
 * 
 */
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_allow_credentials, Py_True) < 0) __PYX_ERR(0, 29, __pyx_L1_error)

  /* "KakaoChat/kakao.py":27
 *     title="Ajou notices server", description="for Kakao Chatbot", version="1.0.0"
 * )
 * application.add_middleware(             # <<<<<<<<<<<<<<
 *     CORSMiddleware,
 *     allow_origins=["*"],
 */
  __pyx_t_4 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_t_3, __pyx_t_2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 27, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "KakaoChat/kakao.py":39
 * 
 * # Dependency
 * def get_db():             # <<<<<<<<<<<<<<
 *     db = db_model.database.SessionLocal()
 *     try:
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_9KakaoChat_5kakao_1get_db, 0, __pyx_n_s_get_db, NULL, __pyx_n_s_KakaoChat_kakao, __pyx_d, ((PyObject *)__pyx_codeobj_)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 39, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_get_db, __pyx_t_4) < 0) __PYX_ERR(0, 39, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "KakaoChat/kakao.py":47
 * 
 * 
 * def checkUserDB(db: Session, user_id: str):             # <<<<<<<<<<<<<<
 *     user = db_model.crud.get_user_by_user_id(db=db, user_id=user_id)
 *     if user is None:
 */
  __pyx_t_4 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 47, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Session); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 47, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_db, __pyx_t_2) < 0) __PYX_ERR(0, 47, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_user_id, __pyx_n_u_unicode) < 0) __PYX_ERR(0, 47, __pyx_L1_error)
  __pyx_t_2 = __Pyx_CyFunction_New(&__pyx_mdef_9KakaoChat_5kakao_4checkUserDB, 0, __pyx_n_s_checkUserDB, NULL, __pyx_n_s_KakaoChat_kakao, __pyx_d, ((PyObject *)__pyx_codeobj__58)); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 47, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_2, __pyx_t_4);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_checkUserDB, __pyx_t_2) < 0) __PYX_ERR(0, 47, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "KakaoChat/kakao.py":54
 * 
 * 
 * def checkLastNotice(db: Session, user_id: str):             # <<<<<<<<<<<<<<
 *     user = db_model.crud.get_user_by_user_id(db=db, user_id=user_id)
 *     if user is None:
 */
  __pyx_t_2 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 54, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_Session); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 54, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_db, __pyx_t_4) < 0) __PYX_ERR(0, 54, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_user_id, __pyx_n_u_unicode) < 0) __PYX_ERR(0, 54, __pyx_L1_error)
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_9KakaoChat_5kakao_6checkLastNotice, 0, __pyx_n_s_checkLastNotice, NULL, __pyx_n_s_KakaoChat_kakao, __pyx_d, ((PyObject *)__pyx_codeobj__60)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 54, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_4, __pyx_t_2);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_checkLastNotice, __pyx_t_4) < 0) __PYX_ERR(0, 54, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "KakaoChat/kakao.py":62
 * 
 * 
 * def getSchedule(db: Session):             # <<<<<<<<<<<<<<
 *     return db_model.crud.get_all_sched(db=db)
 * 
 */
  __pyx_t_4 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 62, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Session); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 62, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_db, __pyx_t_2) < 0) __PYX_ERR(0, 62, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_CyFunction_New(&__pyx_mdef_9KakaoChat_5kakao_8getSchedule, 0, __pyx_n_s_getSchedule, NULL, __pyx_n_s_KakaoChat_kakao, __pyx_d, ((PyObject *)__pyx_codeobj__62)); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 62, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_2, __pyx_t_4);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_getSchedule, __pyx_t_2) < 0) __PYX_ERR(0, 62, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "KakaoChat/kakao.py":66
 * 
 * 
 * def updateLastNotice(db: Session, user_id: str, notice_id: int):             # <<<<<<<<<<<<<<
 *     user = db_model.crud.get_user_by_user_id(db=db, user_id=user_id)
 *     if user is None:
 */
  __pyx_t_2 = __Pyx_PyDict_NewPresized(3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 66, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_Session); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 66, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_db, __pyx_t_4) < 0) __PYX_ERR(0, 66, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_user_id, __pyx_n_u_unicode) < 0) __PYX_ERR(0, 66, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_notice_id, __pyx_n_u_int) < 0) __PYX_ERR(0, 66, __pyx_L1_error)
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_9KakaoChat_5kakao_10updateLastNotice, 0, __pyx_n_s_updateLastNotice, NULL, __pyx_n_s_KakaoChat_kakao, __pyx_d, ((PyObject *)__pyx_codeobj__64)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 66, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_4, __pyx_t_2);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_updateLastNotice, __pyx_t_4) < 0) __PYX_ERR(0, 66, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "KakaoChat/kakao.py":79
 * 
 * 
 * def parseNotices(url=None, length=10):             # <<<<<<<<<<<<<<
 *     """
 * 
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_9KakaoChat_5kakao_12parseNotices, 0, __pyx_n_s_parseNotices, NULL, __pyx_n_s_KakaoChat_kakao, __pyx_d, ((PyObject *)__pyx_codeobj__66)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 79, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_4, __pyx_tuple__67);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_parseNotices, __pyx_t_4) < 0) __PYX_ERR(0, 79, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "KakaoChat/kakao.py":115
 * 
 * 
 * def checkConnection():             # <<<<<<<<<<<<<<
 *     """   . """
 *     context = ssl._create_unverified_context()
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_9KakaoChat_5kakao_14checkConnection, 0, __pyx_n_s_checkConnection, NULL, __pyx_n_s_KakaoChat_kakao, __pyx_d, ((PyObject *)__pyx_codeobj__69)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 115, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_checkConnection, __pyx_t_4) < 0) __PYX_ERR(0, 115, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "KakaoChat/kakao.py":132
 * 
 * 
 * def makeJSON(postId, postTitle, postDate, postLink, postWriter):             # <<<<<<<<<<<<<<
 *     """   """
 *     duplicate = "[" + postWriter + "]"
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_9KakaoChat_5kakao_16makeJSON, 0, __pyx_n_s_makeJSON, NULL, __pyx_n_s_KakaoChat_kakao, __pyx_d, ((PyObject *)__pyx_codeobj__71)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 132, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_makeJSON, __pyx_t_4) < 0) __PYX_ERR(0, 132, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "KakaoChat/kakao.py":146
 * 
 * 
 * def makeJSONwithDate(postId, postTitle, postDate, postLink, postWriter):             # <<<<<<<<<<<<<<
 *     """   , writer  ."""
 *     duplicate = "[" + postWriter + "]"
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_9KakaoChat_5kakao_18makeJSONwithDate, 0, __pyx_n_s_makeJSONwithDate, NULL, __pyx_n_s_KakaoChat_kakao, __pyx_d, ((PyObject *)__pyx_codeobj__73)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 146, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_makeJSONwithDate, __pyx_t_4) < 0) __PYX_ERR(0, 146, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "KakaoChat/kakao.py":159
 * 
 * 
 * def makeTimeoutMessage():             # <<<<<<<<<<<<<<
 *     """ checkConnection()  False,  JSON  return"""
 *     return JSONResponse(
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_9KakaoChat_5kakao_20makeTimeoutMessage, 0, __pyx_n_s_makeTimeoutMessage, NULL, __pyx_n_s_KakaoChat_kakao, __pyx_d, ((PyObject *)__pyx_codeobj__74)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 159, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_makeTimeoutMessage, __pyx_t_4) < 0) __PYX_ERR(0, 159, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "KakaoChat/kakao.py":177
 * 
 * 
 * def makeCarouselCard(title, desc):             # <<<<<<<<<<<<<<
 *     card_imgs = ["ajou_carousel", "ajou_carousel_1", "ajou_carousel_2"]
 *     card = {
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_9KakaoChat_5kakao_22makeCarouselCard, 0, __pyx_n_s_makeCarouselCard, NULL, __pyx_n_s_KakaoChat_kakao, __pyx_d, ((PyObject *)__pyx_codeobj__76)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 177, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_makeCarouselCard, __pyx_t_4) < 0) __PYX_ERR(0, 177, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "KakaoChat/kakao.py":197
 * 
 * 
 * def getTodayNotices(db, now, user_id):             # <<<<<<<<<<<<<<
 *     """ 30    ,    return"""
 *     noticesToday = []
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_9KakaoChat_5kakao_24getTodayNotices, 0, __pyx_n_s_getTodayNotices, NULL, __pyx_n_s_KakaoChat_kakao, __pyx_d, ((PyObject *)__pyx_codeobj__78)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 197, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_getTodayNotices, __pyx_t_4) < 0) __PYX_ERR(0, 197, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "KakaoChat/kakao.py":223
 * 
 * 
 * def getYesterdayNotices(db, now):             # <<<<<<<<<<<<<<
 *     """   MySQL   . """
 *     db_notices = db_model.crud.get_notices_with_date(db=db, date=now)
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_9KakaoChat_5kakao_26getYesterdayNotices, 0, __pyx_n_s_getYesterdayNotices, NULL, __pyx_n_s_KakaoChat_kakao, __pyx_d, ((PyObject *)__pyx_codeobj__80)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 223, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_getYesterdayNotices, __pyx_t_4) < 0) __PYX_ERR(0, 223, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "KakaoChat/kakao.py":237
 * 
 * 
 * def getLastNotice():             # <<<<<<<<<<<<<<
 *     """  1  . """
 *     ids, posts, dates, writers, _ = parseNotices(length=1)  # Parse one notice
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_9KakaoChat_5kakao_28getLastNotice, 0, __pyx_n_s_getLastNotice, NULL, __pyx_n_s_KakaoChat_kakao, __pyx_d, ((PyObject *)__pyx_codeobj__83)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 237, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_getLastNotice, __pyx_t_4) < 0) __PYX_ERR(0, 237, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "KakaoChat/kakao.py":250
 * 
 * 
 * def switch(db, when, now, user_id):             # <<<<<<<<<<<<<<
 *     """ /    switch """
 *     DAY = "" if when == "today" else ""
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_9KakaoChat_5kakao_30switch, 0, __pyx_n_s_switch, NULL, __pyx_n_s_KakaoChat_kakao, __pyx_d, ((PyObject *)__pyx_codeobj__85)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 250, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_switch, __pyx_t_4) < 0) __PYX_ERR(0, 250, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "KakaoChat/kakao.py":296
 * 
 * 
 * @application.get("/")             # <<<<<<<<<<<<<<
 * def hello():
 *     return "Welcome, the server is running well."
 */
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_application); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 296, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_4, __pyx_n_s_get); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 296, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_tuple__87, NULL); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 296, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "KakaoChat/kakao.py":297
 * 
 * @application.get("/")
 * def hello():             # <<<<<<<<<<<<<<
 *     return "Welcome, the server is running well."
 * 
 */
  __pyx_t_2 = __Pyx_CyFunction_New(&__pyx_mdef_9KakaoChat_5kakao_32hello, 0, __pyx_n_s_hello, NULL, __pyx_n_s_KakaoChat_kakao, __pyx_d, ((PyObject *)__pyx_codeobj__88)); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 297, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);

  /* "KakaoChat/kakao.py":296
 * 
 * 
 * @application.get("/")             # <<<<<<<<<<<<<<
 * def hello():
 *     return "Welcome, the server is running well."
 */
  __pyx_t_3 = __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 296, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_hello, __pyx_t_3) < 0) __PYX_ERR(0, 297, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "KakaoChat/kakao.py":301
 * 
 * 
 * @application.post("/ask")             # <<<<<<<<<<<<<<
 * def askKeyword(_: Dict):
 *     """    """
 */
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_application); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 301, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_post); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 301, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_tuple__89, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 301, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "KakaoChat/kakao.py":302
 * 
 * @application.post("/ask")
 * def askKeyword(_: Dict):             # <<<<<<<<<<<<<<
 *     """    """
 *     # user_id = content["userRequest"]["user"]["id"]  # user Id
 */
  __pyx_t_2 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 302, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_Dict); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 302, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s__81, __pyx_t_4) < 0) __PYX_ERR(0, 302, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_9KakaoChat_5kakao_34askKeyword, 0, __pyx_n_s_askKeyword, NULL, __pyx_n_s_KakaoChat_kakao, __pyx_d, ((PyObject *)__pyx_codeobj__91)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 302, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_4, __pyx_t_2);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "KakaoChat/kakao.py":301
 * 
 * 
 * @application.post("/ask")             # <<<<<<<<<<<<<<
 * def askKeyword(_: Dict):
 *     """    """
 */
  __pyx_t_2 = __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_4); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 301, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_askKeyword, __pyx_t_2) < 0) __PYX_ERR(0, 302, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "KakaoChat/kakao.py":337
 * 
 * 
 * @application.post("/date")             # <<<<<<<<<<<<<<
 * def searchDate(content: Dict):
 *     """WIP"""
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_application); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 337, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_post); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 337, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_4, __pyx_tuple__92, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 337, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "KakaoChat/kakao.py":338
 * 
 * @application.post("/date")
 * def searchDate(content: Dict):             # <<<<<<<<<<<<<<
 *     """WIP"""
 *     print(">>> /date")
 */
  __pyx_t_4 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 338, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_Dict); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 338, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_content, __pyx_t_3) < 0) __PYX_ERR(0, 338, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_9KakaoChat_5kakao_36searchDate, 0, __pyx_n_s_searchDate, NULL, __pyx_n_s_KakaoChat_kakao, __pyx_d, ((PyObject *)__pyx_codeobj__94)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 338, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_3, __pyx_t_4);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "KakaoChat/kakao.py":337
 * 
 * 
 * @application.post("/date")             # <<<<<<<<<<<<<<
 * def searchDate(content: Dict):
 *     """WIP"""
 */
  __pyx_t_4 = __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 337, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_searchDate, __pyx_t_4) < 0) __PYX_ERR(0, 338, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "KakaoChat/kakao.py":345
 * 
 * 
 * @application.post("/ask/filter")             # <<<<<<<<<<<<<<
 * def searchKeyword(content: Dict, db: Session = Depends(get_db)):
 *     """   .  type: ListCard"""
 */
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_application); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 345, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_4, __pyx_n_s_post); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 345, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_tuple__95, NULL); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 345, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "KakaoChat/kakao.py":346
 * 
 * @application.post("/ask/filter")
 * def searchKeyword(content: Dict, db: Session = Depends(get_db)):             # <<<<<<<<<<<<<<
 *     """   .  type: ListCard"""
 *     user_id = content["userRequest"]["user"]["id"]  # user Id
 */
  __pyx_t_3 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 346, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Dict); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 346, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_content, __pyx_t_2) < 0) __PYX_ERR(0, 346, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Session); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 346, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_db, __pyx_t_2) < 0) __PYX_ERR(0, 346, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_CyFunction_New(&__pyx_mdef_9KakaoChat_5kakao_38searchKeyword, 0, __pyx_n_s_searchKeyword, NULL, __pyx_n_s_KakaoChat_kakao, __pyx_d, ((PyObject *)__pyx_codeobj__97)); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 346, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (!__Pyx_CyFunction_InitDefaults(__pyx_t_2, sizeof(__pyx_defaults), 1)) __PYX_ERR(0, 346, __pyx_L1_error)
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_Depends); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 346, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_get_db); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 346, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_6 = __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_5); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 346, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_CyFunction_Defaults(__pyx_defaults, __pyx_t_2)->__pyx_arg_db = __pyx_t_6;
  __Pyx_GIVEREF(__pyx_t_6);
  __pyx_t_6 = 0;
  __Pyx_CyFunction_SetDefaultsGetter(__pyx_t_2, __pyx_pf_9KakaoChat_5kakao_47__defaults__);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_2, __pyx_t_3);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "KakaoChat/kakao.py":345
 * 
 * 
 * @application.post("/ask/filter")             # <<<<<<<<<<<<<<
 * def searchKeyword(content: Dict, db: Session = Depends(get_db)):
 *     """   .  type: ListCard"""
 */
  __pyx_t_3 = __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 345, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_searchKeyword, __pyx_t_3) < 0) __PYX_ERR(0, 346, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "KakaoChat/kakao.py":428
 * 
 * 
 * @application.post("/last")             # <<<<<<<<<<<<<<
 * def parseOne(content: Dict, db: Session = Depends(get_db)):
 *     """    1 .  type: ListCard"""
 */
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_application); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 428, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_post); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 428, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_tuple__42, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 428, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "KakaoChat/kakao.py":429
 * 
 * @application.post("/last")
 * def parseOne(content: Dict, db: Session = Depends(get_db)):             # <<<<<<<<<<<<<<
 *     """    1 .  type: ListCard"""
 *     user_id = content["userRequest"]["user"]["id"]  # user Id
 */
  __pyx_t_2 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 429, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_Dict); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 429, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_content, __pyx_t_4) < 0) __PYX_ERR(0, 429, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_Session); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 429, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_db, __pyx_t_4) < 0) __PYX_ERR(0, 429, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_9KakaoChat_5kakao_40parseOne, 0, __pyx_n_s_parseOne, NULL, __pyx_n_s_KakaoChat_kakao, __pyx_d, ((PyObject *)__pyx_codeobj__99)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 429, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (!__Pyx_CyFunction_InitDefaults(__pyx_t_4, sizeof(__pyx_defaults1), 1)) __PYX_ERR(0, 429, __pyx_L1_error)
  __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_Depends); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 429, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_get_db); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 429, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_1 = __Pyx_PyObject_CallOneArg(__pyx_t_6, __pyx_t_5); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 429, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_CyFunction_Defaults(__pyx_defaults1, __pyx_t_4)->__pyx_arg_db = __pyx_t_1;
  __Pyx_GIVEREF(__pyx_t_1);
  __pyx_t_1 = 0;
  __Pyx_CyFunction_SetDefaultsGetter(__pyx_t_4, __pyx_pf_9KakaoChat_5kakao_49__defaults__);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_4, __pyx_t_2);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "KakaoChat/kakao.py":428
 * 
 * 
 * @application.post("/last")             # <<<<<<<<<<<<<<
 * def parseOne(content: Dict, db: Session = Depends(get_db)):
 *     """    1 .  type: ListCard"""
 */
  __pyx_t_2 = __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_4); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 428, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_parseOne, __pyx_t_2) < 0) __PYX_ERR(0, 429, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "KakaoChat/kakao.py":460
 * 
 * 
 * @application.post("/search")             # <<<<<<<<<<<<<<
 * def searchNotice(content: Dict, db: Session = Depends(get_db)):
 *     """    .  type: simpleText | ListCard"""
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_application); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 460, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_post); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 460, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_4, __pyx_tuple__100, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 460, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "KakaoChat/kakao.py":461
 * 
 * @application.post("/search")
 * def searchNotice(content: Dict, db: Session = Depends(get_db)):             # <<<<<<<<<<<<<<
 *     """    .  type: simpleText | ListCard"""
 *     user_id = content["userRequest"]["user"]["id"]  # user Id
 */
  __pyx_t_4 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 461, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_Dict); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 461, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_content, __pyx_t_3) < 0) __PYX_ERR(0, 461, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_Session); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 461, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_db, __pyx_t_3) < 0) __PYX_ERR(0, 461, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_9KakaoChat_5kakao_42searchNotice, 0, __pyx_n_s_searchNotice, NULL, __pyx_n_s_KakaoChat_kakao, __pyx_d, ((PyObject *)__pyx_codeobj__102)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 461, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (!__Pyx_CyFunction_InitDefaults(__pyx_t_3, sizeof(__pyx_defaults2), 1)) __PYX_ERR(0, 461, __pyx_L1_error)
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_Depends); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 461, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_get_db); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 461, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_6 = __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_5); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 461, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_CyFunction_Defaults(__pyx_defaults2, __pyx_t_3)->__pyx_arg_db = __pyx_t_6;
  __Pyx_GIVEREF(__pyx_t_6);
  __pyx_t_6 = 0;
  __Pyx_CyFunction_SetDefaultsGetter(__pyx_t_3, __pyx_pf_9KakaoChat_5kakao_51__defaults__);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_3, __pyx_t_4);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "KakaoChat/kakao.py":460
 * 
 * 
 * @application.post("/search")             # <<<<<<<<<<<<<<
 * def searchNotice(content: Dict, db: Session = Depends(get_db)):
 *     """    .  type: simpleText | ListCard"""
 */
  __pyx_t_4 = __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 460, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_searchNotice, __pyx_t_4) < 0) __PYX_ERR(0, 461, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "KakaoChat/kakao.py":548
 * 
 * 
 * @application.post("/message")             # <<<<<<<<<<<<<<
 * def message(content: Dict, db: Session = Depends(get_db)):
 *     """/    route |  type: ListCard """
 */
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_application); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 548, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_4, __pyx_n_s_post); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 548, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_tuple__103, NULL); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 548, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "KakaoChat/kakao.py":549
 * 
 * @application.post("/message")
 * def message(content: Dict, db: Session = Depends(get_db)):             # <<<<<<<<<<<<<<
 *     """/    route |  type: ListCard """
 *     user_id = content["userRequest"]["user"]["id"]  # user Id
 */
  __pyx_t_3 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 549, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Dict); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 549, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_content, __pyx_t_2) < 0) __PYX_ERR(0, 549, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Session); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 549, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_db, __pyx_t_2) < 0) __PYX_ERR(0, 549, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_CyFunction_New(&__pyx_mdef_9KakaoChat_5kakao_44message, 0, __pyx_n_s_message, NULL, __pyx_n_s_KakaoChat_kakao, __pyx_d, ((PyObject *)__pyx_codeobj__105)); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 549, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (!__Pyx_CyFunction_InitDefaults(__pyx_t_2, sizeof(__pyx_defaults3), 1)) __PYX_ERR(0, 549, __pyx_L1_error)
  __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_Depends); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 549, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_get_db); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 549, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_1 = __Pyx_PyObject_CallOneArg(__pyx_t_6, __pyx_t_5); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 549, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_CyFunction_Defaults(__pyx_defaults3, __pyx_t_2)->__pyx_arg_db = __pyx_t_1;
  __Pyx_GIVEREF(__pyx_t_1);
  __pyx_t_1 = 0;
  __Pyx_CyFunction_SetDefaultsGetter(__pyx_t_2, __pyx_pf_9KakaoChat_5kakao_53__defaults__);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_2, __pyx_t_3);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "KakaoChat/kakao.py":548
 * 
 * 
 * @application.post("/message")             # <<<<<<<<<<<<<<
 * def message(content: Dict, db: Session = Depends(get_db)):
 *     """/    route |  type: ListCard """
 */
  __pyx_t_3 = __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 548, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_message, __pyx_t_3) < 0) __PYX_ERR(0, 549, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "KakaoChat/kakao.py":572
 * 
 * 
 * @application.post("/schedule")             # <<<<<<<<<<<<<<
 * def schedule(content: Dict, db: Session = Depends(get_db)):
 *     """MySQL DB   |  type: Carousel BasicCards """
 */
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_application); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 572, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_post); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 572, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_tuple__106, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 572, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "KakaoChat/kakao.py":573
 * 
 * @application.post("/schedule")
 * def schedule(content: Dict, db: Session = Depends(get_db)):             # <<<<<<<<<<<<<<
 *     """MySQL DB   |  type: Carousel BasicCards """
 *     user_id = content["userRequest"]["user"]["id"]  # user Id
 */
  __pyx_t_2 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 573, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_Dict); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 573, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_content, __pyx_t_4) < 0) __PYX_ERR(0, 573, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_Session); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 573, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_db, __pyx_t_4) < 0) __PYX_ERR(0, 573, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_9KakaoChat_5kakao_46schedule, 0, __pyx_n_s_schedule_3, NULL, __pyx_n_s_KakaoChat_kakao, __pyx_d, ((PyObject *)__pyx_codeobj__108)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 573, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (!__Pyx_CyFunction_InitDefaults(__pyx_t_4, sizeof(__pyx_defaults4), 1)) __PYX_ERR(0, 573, __pyx_L1_error)
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_Depends); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 573, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_get_db); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 573, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_6 = __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_5); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 573, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_CyFunction_Defaults(__pyx_defaults4, __pyx_t_4)->__pyx_arg_db = __pyx_t_6;
  __Pyx_GIVEREF(__pyx_t_6);
  __pyx_t_6 = 0;
  __Pyx_CyFunction_SetDefaultsGetter(__pyx_t_4, __pyx_pf_9KakaoChat_5kakao_55__defaults__);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_4, __pyx_t_2);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "KakaoChat/kakao.py":572
 * 
 * 
 * @application.post("/schedule")             # <<<<<<<<<<<<<<
 * def schedule(content: Dict, db: Session = Depends(get_db)):
 *     """MySQL DB   |  type: Carousel BasicCards """
 */
  __pyx_t_2 = __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_4); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 572, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_schedule_3, __pyx_t_2) < 0) __PYX_ERR(0, 573, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "KakaoChat/kakao.py":597
 * 
 * 
 * if __name__ == "__main__":             # <<<<<<<<<<<<<<
 *     uvicorn.run(application, host="0.0.0.0", port=8000, log_level="info")
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_name); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 597, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_7 = (__Pyx_PyUnicode_Equals(__pyx_t_2, __pyx_n_u_main, Py_EQ)); if (unlikely(__pyx_t_7 < 0)) __PYX_ERR(0, 597, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (__pyx_t_7) {

    /* "KakaoChat/kakao.py":598
 * 
 * if __name__ == "__main__":
 *     uvicorn.run(application, host="0.0.0.0", port=8000, log_level="info")             # <<<<<<<<<<<<<<
 */
    __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_uvicorn); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 598, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_run); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 598, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_application); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 598, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_3 = PyTuple_New(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 598, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_GIVEREF(__pyx_t_2);
    PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_2);
    __pyx_t_2 = 0;
    __pyx_t_2 = __Pyx_PyDict_NewPresized(3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 598, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_host, __pyx_kp_u_0_0_0_0) < 0) __PYX_ERR(0, 598, __pyx_L1_error)
    if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_port, __pyx_int_8000) < 0) __PYX_ERR(0, 598, __pyx_L1_error)
    if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_log_level, __pyx_n_u_info) < 0) __PYX_ERR(0, 598, __pyx_L1_error)
    __pyx_t_6 = __Pyx_PyObject_Call(__pyx_t_4, __pyx_t_3, __pyx_t_2); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 598, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;

    /* "KakaoChat/kakao.py":597
 * 
 * 
 * if __name__ == "__main__":             # <<<<<<<<<<<<<<
 *     uvicorn.run(application, host="0.0.0.0", port=8000, log_level="info")
 */
  }

  /* "KakaoChat/kakao.py":1
 * import ssl             # <<<<<<<<<<<<<<
 * from datetime import datetime, timedelta
 * from random import choice
 */
  __pyx_t_6 = __Pyx_PyDict_NewPresized(0); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_test, __pyx_t_6) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;

  /*--- Wrapped vars code ---*/

  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  if (__pyx_m) {
    if (__pyx_d) {
      __Pyx_AddTraceback("init KakaoChat.kakao", __pyx_clineno, __pyx_lineno, __pyx_filename);
    }
    Py_CLEAR(__pyx_m);
  } else if (!PyErr_Occurred()) {
    PyErr_SetString(PyExc_ImportError, "init KakaoChat.kakao");
  }
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  #if CYTHON_PEP489_MULTI_PHASE_INIT
  return (__pyx_m != NULL) ? 0 : -1;
  #elif PY_MAJOR_VERSION >= 3
  return __pyx_m;
  #else
  return;
  #endif
}

/* --- Runtime support code --- */
/* Refnanny */
#if CYTHON_REFNANNY
static __Pyx_RefNannyAPIStruct *__Pyx_RefNannyImportAPI(const char *modname) {
    PyObject *m = NULL, *p = NULL;
    void *r = NULL;
    m = PyImport_ImportModule(modname);
    if (!m) goto end;
    p = PyObject_GetAttrString(m, "RefNannyAPI");
    if (!p) goto end;
    r = PyLong_AsVoidPtr(p);
end:
    Py_XDECREF(p);
    Py_XDECREF(m);
    return (__Pyx_RefNannyAPIStruct *)r;
}
#endif

/* PyObjectGetAttrStr */
#if CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PyObject* __Pyx_PyObject_GetAttrStr(PyObject* obj, PyObject* attr_name) {
    PyTypeObject* tp = Py_TYPE(obj);
    if (likely(tp->tp_getattro))
        return tp->tp_getattro(obj, attr_name);
#if PY_MAJOR_VERSION < 3
    if (likely(tp->tp_getattr))
        return tp->tp_getattr(obj, PyString_AS_STRING(attr_name));
#endif
    return PyObject_GetAttr(obj, attr_name);
}
#endif

/* GetBuiltinName */
static PyObject *__Pyx_GetBuiltinName(PyObject *name) {
    PyObject* result = __Pyx_PyObject_GetAttrStr(__pyx_b, name);
    if (unlikely(!result)) {
        PyErr_Format(PyExc_NameError,
#if PY_MAJOR_VERSION >= 3
            "name '%U' is not defined", name);
#else
            "name '%.200s' is not defined", PyString_AS_STRING(name));
#endif
    }
    return result;
}

/* PyDictVersioning */
#if CYTHON_USE_DICT_VERSIONS && CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PY_UINT64_T __Pyx_get_tp_dict_version(PyObject *obj) {
    PyObject *dict = Py_TYPE(obj)->tp_dict;
    return likely(dict) ? __PYX_GET_DICT_VERSION(dict) : 0;
}
static CYTHON_INLINE PY_UINT64_T __Pyx_get_object_dict_version(PyObject *obj) {
    PyObject **dictptr = NULL;
    Py_ssize_t offset = Py_TYPE(obj)->tp_dictoffset;
    if (offset) {
#if CYTHON_COMPILING_IN_CPYTHON
        dictptr = (likely(offset > 0)) ? (PyObject **) ((char *)obj + offset) : _PyObject_GetDictPtr(obj);
#else
        dictptr = _PyObject_GetDictPtr(obj);
#endif
    }
    return (dictptr && *dictptr) ? __PYX_GET_DICT_VERSION(*dictptr) : 0;
}
static CYTHON_INLINE int __Pyx_object_dict_version_matches(PyObject* obj, PY_UINT64_T tp_dict_version, PY_UINT64_T obj_dict_version) {
    PyObject *dict = Py_TYPE(obj)->tp_dict;
    if (unlikely(!dict) || unlikely(tp_dict_version != __PYX_GET_DICT_VERSION(dict)))
        return 0;
    return obj_dict_version == __Pyx_get_object_dict_version(obj);
}
#endif

/* GetModuleGlobalName */
#if CYTHON_USE_DICT_VERSIONS
static PyObject *__Pyx__GetModuleGlobalName(PyObject *name, PY_UINT64_T *dict_version, PyObject **dict_cached_value)
#else
static CYTHON_INLINE PyObject *__Pyx__GetModuleGlobalName(PyObject *name)
#endif
{
    PyObject *result;
#if !CYTHON_AVOID_BORROWED_REFS
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030500A1
    result = _PyDict_GetItem_KnownHash(__pyx_d, name, ((PyASCIIObject *) name)->hash);
    __PYX_UPDATE_DICT_CACHE(__pyx_d, result, *dict_cached_value, *dict_version)
    if (likely(result)) {
        return __Pyx_NewRef(result);
    } else if (unlikely(PyErr_Occurred())) {
        return NULL;
    }
#else
    result = PyDict_GetItem(__pyx_d, name);
    __PYX_UPDATE_DICT_CACHE(__pyx_d, result, *dict_cached_value, *dict_version)
    if (likely(result)) {
        return __Pyx_NewRef(result);
    }
#endif
#else
    result = PyObject_GetItem(__pyx_d, name);
    __PYX_UPDATE_DICT_CACHE(__pyx_d, result, *dict_cached_value, *dict_version)
    if (likely(result)) {
        return __Pyx_NewRef(result);
    }
    PyErr_Clear();
#endif
    return __Pyx_GetBuiltinName(name);
}

/* PyFunctionFastCall */
#if CYTHON_FAST_PYCALL
static PyObject* __Pyx_PyFunction_FastCallNoKw(PyCodeObject *co, PyObject **args, Py_ssize_t na,
                                               PyObject *globals) {
    PyFrameObject *f;
    PyThreadState *tstate = __Pyx_PyThreadState_Current;
    PyObject **fastlocals;
    Py_ssize_t i;
    PyObject *result;
    assert(globals != NULL);
    /* XXX Perhaps we should create a specialized
       PyFrame_New() that doesn't take locals, but does
       take builtins without sanity checking them.
       */
    assert(tstate != NULL);
    f = PyFrame_New(tstate, co, globals, NULL);
    if (f == NULL) {
        return NULL;
    }
    fastlocals = __Pyx_PyFrame_GetLocalsplus(f);
    for (i = 0; i < na; i++) {
        Py_INCREF(*args);
        fastlocals[i] = *args++;
    }
    result = PyEval_EvalFrameEx(f,0);
    ++tstate->recursion_depth;
    Py_DECREF(f);
    --tstate->recursion_depth;
    return result;
}
#if 1 || PY_VERSION_HEX < 0x030600B1
static PyObject *__Pyx_PyFunction_FastCallDict(PyObject *func, PyObject **args, Py_ssize_t nargs, PyObject *kwargs) {
    PyCodeObject *co = (PyCodeObject *)PyFunction_GET_CODE(func);
    PyObject *globals = PyFunction_GET_GLOBALS(func);
    PyObject *argdefs = PyFunction_GET_DEFAULTS(func);
    PyObject *closure;
#if PY_MAJOR_VERSION >= 3
    PyObject *kwdefs;
#endif
    PyObject *kwtuple, **k;
    PyObject **d;
    Py_ssize_t nd;
    Py_ssize_t nk;
    PyObject *result;
    assert(kwargs == NULL || PyDict_Check(kwargs));
    nk = kwargs ? PyDict_Size(kwargs) : 0;
    if (Py_EnterRecursiveCall((char*)" while calling a Python object")) {
        return NULL;
    }
    if (
#if PY_MAJOR_VERSION >= 3
            co->co_kwonlyargcount == 0 &&
#endif
            likely(kwargs == NULL || nk == 0) &&
            co->co_flags == (CO_OPTIMIZED | CO_NEWLOCALS | CO_NOFREE)) {
        if (argdefs == NULL && co->co_argcount == nargs) {
            result = __Pyx_PyFunction_FastCallNoKw(co, args, nargs, globals);
            goto done;
        }
        else if (nargs == 0 && argdefs != NULL
                 && co->co_argcount == Py_SIZE(argdefs)) {
            /* function called with no arguments, but all parameters have
               a default value: use default values as arguments .*/
            args = &PyTuple_GET_ITEM(argdefs, 0);
            result =__Pyx_PyFunction_FastCallNoKw(co, args, Py_SIZE(argdefs), globals);
            goto done;
        }
    }
    if (kwargs != NULL) {
        Py_ssize_t pos, i;
        kwtuple = PyTuple_New(2 * nk);
        if (kwtuple == NULL) {
            result = NULL;
            goto done;
        }
        k = &PyTuple_GET_ITEM(kwtuple, 0);
        pos = i = 0;
        while (PyDict_Next(kwargs, &pos, &k[i], &k[i+1])) {
            Py_INCREF(k[i]);
            Py_INCREF(k[i+1]);
            i += 2;
        }
        nk = i / 2;
    }
    else {
        kwtuple = NULL;
        k = NULL;
    }
    closure = PyFunction_GET_CLOSURE(func);
#if PY_MAJOR_VERSION >= 3
    kwdefs = PyFunction_GET_KW_DEFAULTS(func);
#endif
    if (argdefs != NULL) {
        d = &PyTuple_GET_ITEM(argdefs, 0);
        nd = Py_SIZE(argdefs);
    }
    else {
        d = NULL;
        nd = 0;
    }
#if PY_MAJOR_VERSION >= 3
    result = PyEval_EvalCodeEx((PyObject*)co, globals, (PyObject *)NULL,
                               args, (int)nargs,
                               k, (int)nk,
                               d, (int)nd, kwdefs, closure);
#else
    result = PyEval_EvalCodeEx(co, globals, (PyObject *)NULL,
                               args, (int)nargs,
                               k, (int)nk,
                               d, (int)nd, closure);
#endif
    Py_XDECREF(kwtuple);
done:
    Py_LeaveRecursiveCall();
    return result;
}
#endif
#endif

/* PyObjectCall */
#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_Call(PyObject *func, PyObject *arg, PyObject *kw) {
    PyObject *result;
    ternaryfunc call = func->ob_type->tp_call;
    if (unlikely(!call))
        return PyObject_Call(func, arg, kw);
    if (unlikely(Py_EnterRecursiveCall((char*)" while calling a Python object")))
        return NULL;
    result = (*call)(func, arg, kw);
    Py_LeaveRecursiveCall();
    if (unlikely(!result) && unlikely(!PyErr_Occurred())) {
        PyErr_SetString(
            PyExc_SystemError,
            "NULL result without error in PyObject_Call");
    }
    return result;
}
#endif

/* PyObjectCallMethO */
#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallMethO(PyObject *func, PyObject *arg) {
    PyObject *self, *result;
    PyCFunction cfunc;
    cfunc = PyCFunction_GET_FUNCTION(func);
    self = PyCFunction_GET_SELF(func);
    if (unlikely(Py_EnterRecursiveCall((char*)" while calling a Python object")))
        return NULL;
    result = cfunc(self, arg);
    Py_LeaveRecursiveCall();
    if (unlikely(!result) && unlikely(!PyErr_Occurred())) {
        PyErr_SetString(
            PyExc_SystemError,
            "NULL result without error in PyObject_Call");
    }
    return result;
}
#endif

/* PyObjectCallNoArg */
#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallNoArg(PyObject *func) {
#if CYTHON_FAST_PYCALL
    if (PyFunction_Check(func)) {
        return __Pyx_PyFunction_FastCall(func, NULL, 0);
    }
#endif
#ifdef __Pyx_CyFunction_USED
    if (likely(PyCFunction_Check(func) || __Pyx_CyFunction_Check(func)))
#else
    if (likely(PyCFunction_Check(func)))
#endif
    {
        if (likely(PyCFunction_GET_FLAGS(func) & METH_NOARGS)) {
            return __Pyx_PyObject_CallMethO(func, NULL);
        }
    }
    return __Pyx_PyObject_Call(func, __pyx_empty_tuple, NULL);
}
#endif

/* PyCFunctionFastCall */
#if CYTHON_FAST_PYCCALL
static CYTHON_INLINE PyObject * __Pyx_PyCFunction_FastCall(PyObject *func_obj, PyObject **args, Py_ssize_t nargs) {
    PyCFunctionObject *func = (PyCFunctionObject*)func_obj;
    PyCFunction meth = PyCFunction_GET_FUNCTION(func);
    PyObject *self = PyCFunction_GET_SELF(func);
    int flags = PyCFunction_GET_FLAGS(func);
    assert(PyCFunction_Check(func));
    assert(METH_FASTCALL == (flags & ~(METH_CLASS | METH_STATIC | METH_COEXIST | METH_KEYWORDS | METH_STACKLESS)));
    assert(nargs >= 0);
    assert(nargs == 0 || args != NULL);
    /* _PyCFunction_FastCallDict() must not be called with an exception set,
       because it may clear it (directly or indirectly) and so the
       caller loses its exception */
    assert(!PyErr_Occurred());
    if ((PY_VERSION_HEX < 0x030700A0) || unlikely(flags & METH_KEYWORDS)) {
        return (*((__Pyx_PyCFunctionFastWithKeywords)(void*)meth)) (self, args, nargs, NULL);
    } else {
        return (*((__Pyx_PyCFunctionFast)(void*)meth)) (self, args, nargs);
    }
}
#endif

/* PyObjectCallOneArg */
#if CYTHON_COMPILING_IN_CPYTHON
static PyObject* __Pyx__PyObject_CallOneArg(PyObject *func, PyObject *arg) {
    PyObject *result;
    PyObject *args = PyTuple_New(1);
    if (unlikely(!args)) return NULL;
    Py_INCREF(arg);
    PyTuple_SET_ITEM(args, 0, arg);
    result = __Pyx_PyObject_Call(func, args, NULL);
    Py_DECREF(args);
    return result;
}
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallOneArg(PyObject *func, PyObject *arg) {
#if CYTHON_FAST_PYCALL
    if (PyFunction_Check(func)) {
        return __Pyx_PyFunction_FastCall(func, &arg, 1);
    }
#endif
    if (likely(PyCFunction_Check(func))) {
        if (likely(PyCFunction_GET_FLAGS(func) & METH_O)) {
            return __Pyx_PyObject_CallMethO(func, arg);
#if CYTHON_FAST_PYCCALL
        } else if (PyCFunction_GET_FLAGS(func) & METH_FASTCALL) {
            return __Pyx_PyCFunction_FastCall(func, &arg, 1);
#endif
        }
    }
    return __Pyx__PyObject_CallOneArg(func, arg);
}
#else
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallOneArg(PyObject *func, PyObject *arg) {
    PyObject *result;
    PyObject *args = PyTuple_Pack(1, arg);
    if (unlikely(!args)) return NULL;
    result = __Pyx_PyObject_Call(func, args, NULL);
    Py_DECREF(args);
    return result;
}
#endif

/* PyErrFetchRestore */
#if CYTHON_FAST_THREAD_STATE
static CYTHON_INLINE void __Pyx_ErrRestoreInState(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb) {
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    tmp_type = tstate->curexc_type;
    tmp_value = tstate->curexc_value;
    tmp_tb = tstate->curexc_traceback;
    tstate->curexc_type = type;
    tstate->curexc_value = value;
    tstate->curexc_traceback = tb;
    Py_XDECREF(tmp_type);
    Py_XDECREF(tmp_value);
    Py_XDECREF(tmp_tb);
}
static CYTHON_INLINE void __Pyx_ErrFetchInState(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb) {
    *type = tstate->curexc_type;
    *value = tstate->curexc_value;
    *tb = tstate->curexc_traceback;
    tstate->curexc_type = 0;
    tstate->curexc_value = 0;
    tstate->curexc_traceback = 0;
}
#endif

/* GetException */
#if CYTHON_FAST_THREAD_STATE
static int __Pyx__GetException(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb)
#else
static int __Pyx_GetException(PyObject **type, PyObject **value, PyObject **tb)
#endif
{
    PyObject *local_type, *local_value, *local_tb;
#if CYTHON_FAST_THREAD_STATE
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    local_type = tstate->curexc_type;
    local_value = tstate->curexc_value;
    local_tb = tstate->curexc_traceback;
    tstate->curexc_type = 0;
    tstate->curexc_value = 0;
    tstate->curexc_traceback = 0;
#else
    PyErr_Fetch(&local_type, &local_value, &local_tb);
#endif
    PyErr_NormalizeException(&local_type, &local_value, &local_tb);
#if CYTHON_FAST_THREAD_STATE
    if (unlikely(tstate->curexc_type))
#else
    if (unlikely(PyErr_Occurred()))
#endif
        goto bad;
    #if PY_MAJOR_VERSION >= 3
    if (local_tb) {
        if (unlikely(PyException_SetTraceback(local_value, local_tb) < 0))
            goto bad;
    }
    #endif
    Py_XINCREF(local_tb);
    Py_XINCREF(local_type);
    Py_XINCREF(local_value);
    *type = local_type;
    *value = local_value;
    *tb = local_tb;
#if CYTHON_FAST_THREAD_STATE
    #if CYTHON_USE_EXC_INFO_STACK
    {
        _PyErr_StackItem *exc_info = tstate->exc_info;
        tmp_type = exc_info->exc_type;
        tmp_value = exc_info->exc_value;
        tmp_tb = exc_info->exc_traceback;
        exc_info->exc_type = local_type;
        exc_info->exc_value = local_value;
        exc_info->exc_traceback = local_tb;
    }
    #else
    tmp_type = tstate->exc_type;
    tmp_value = tstate->exc_value;
    tmp_tb = tstate->exc_traceback;
    tstate->exc_type = local_type;
    tstate->exc_value = local_value;
    tstate->exc_traceback = local_tb;
    #endif
    Py_XDECREF(tmp_type);
    Py_XDECREF(tmp_value);
    Py_XDECREF(tmp_tb);
#else
    PyErr_SetExcInfo(local_type, local_value, local_tb);
#endif
    return 0;
bad:
    *type = 0;
    *value = 0;
    *tb = 0;
    Py_XDECREF(local_type);
    Py_XDECREF(local_value);
    Py_XDECREF(local_tb);
    return -1;
}

/* SwapException */
#if CYTHON_FAST_THREAD_STATE
static CYTHON_INLINE void __Pyx__ExceptionSwap(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb) {
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    #if CYTHON_USE_EXC_INFO_STACK
    _PyErr_StackItem *exc_info = tstate->exc_info;
    tmp_type = exc_info->exc_type;
    tmp_value = exc_info->exc_value;
    tmp_tb = exc_info->exc_traceback;
    exc_info->exc_type = *type;
    exc_info->exc_value = *value;
    exc_info->exc_traceback = *tb;
    #else
    tmp_type = tstate->exc_type;
    tmp_value = tstate->exc_value;
    tmp_tb = tstate->exc_traceback;
    tstate->exc_type = *type;
    tstate->exc_value = *value;
    tstate->exc_traceback = *tb;
    #endif
    *type = tmp_type;
    *value = tmp_value;
    *tb = tmp_tb;
}
#else
static CYTHON_INLINE void __Pyx_ExceptionSwap(PyObject **type, PyObject **value, PyObject **tb) {
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    PyErr_GetExcInfo(&tmp_type, &tmp_value, &tmp_tb);
    PyErr_SetExcInfo(*type, *value, *tb);
    *type = tmp_type;
    *value = tmp_value;
    *tb = tmp_tb;
}
#endif

/* GetTopmostException */
#if CYTHON_USE_EXC_INFO_STACK
static _PyErr_StackItem *
__Pyx_PyErr_GetTopmostException(PyThreadState *tstate)
{
    _PyErr_StackItem *exc_info = tstate->exc_info;
    while ((exc_info->exc_type == NULL || exc_info->exc_type == Py_None) &&
           exc_info->previous_item != NULL)
    {
        exc_info = exc_info->previous_item;
    }
    return exc_info;
}
#endif

/* SaveResetException */
#if CYTHON_FAST_THREAD_STATE
static CYTHON_INLINE void __Pyx__ExceptionSave(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb) {
    #if CYTHON_USE_EXC_INFO_STACK
    _PyErr_StackItem *exc_info = __Pyx_PyErr_GetTopmostException(tstate);
    *type = exc_info->exc_type;
    *value = exc_info->exc_value;
    *tb = exc_info->exc_traceback;
    #else
    *type = tstate->exc_type;
    *value = tstate->exc_value;
    *tb = tstate->exc_traceback;
    #endif
    Py_XINCREF(*type);
    Py_XINCREF(*value);
    Py_XINCREF(*tb);
}
static CYTHON_INLINE void __Pyx__ExceptionReset(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb) {
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    #if CYTHON_USE_EXC_INFO_STACK
    _PyErr_StackItem *exc_info = tstate->exc_info;
    tmp_type = exc_info->exc_type;
    tmp_value = exc_info->exc_value;
    tmp_tb = exc_info->exc_traceback;
    exc_info->exc_type = type;
    exc_info->exc_value = value;
    exc_info->exc_traceback = tb;
    #else
    tmp_type = tstate->exc_type;
    tmp_value = tstate->exc_value;
    tmp_tb = tstate->exc_traceback;
    tstate->exc_type = type;
    tstate->exc_value = value;
    tstate->exc_traceback = tb;
    #endif
    Py_XDECREF(tmp_type);
    Py_XDECREF(tmp_value);
    Py_XDECREF(tmp_tb);
}
#endif

/* RaiseArgTupleInvalid */
static void __Pyx_RaiseArgtupleInvalid(
    const char* func_name,
    int exact,
    Py_ssize_t num_min,
    Py_ssize_t num_max,
    Py_ssize_t num_found)
{
    Py_ssize_t num_expected;
    const char *more_or_less;
    if (num_found < num_min) {
        num_expected = num_min;
        more_or_less = "at least";
    } else {
        num_expected = num_max;
        more_or_less = "at most";
    }
    if (exact) {
        more_or_less = "exactly";
    }
    PyErr_Format(PyExc_TypeError,
                 "%.200s() takes %.8s %" CYTHON_FORMAT_SSIZE_T "d positional argument%.1s (%" CYTHON_FORMAT_SSIZE_T "d given)",
                 func_name, more_or_less, num_expected,
                 (num_expected == 1) ? "" : "s", num_found);
}

/* RaiseDoubleKeywords */
static void __Pyx_RaiseDoubleKeywordsError(
    const char* func_name,
    PyObject* kw_name)
{
    PyErr_Format(PyExc_TypeError,
        #if PY_MAJOR_VERSION >= 3
        "%s() got multiple values for keyword argument '%U'", func_name, kw_name);
        #else
        "%s() got multiple values for keyword argument '%s'", func_name,
        PyString_AsString(kw_name));
        #endif
}

/* ParseKeywords */
static int __Pyx_ParseOptionalKeywords(
    PyObject *kwds,
    PyObject **argnames[],
    PyObject *kwds2,
    PyObject *values[],
    Py_ssize_t num_pos_args,
    const char* function_name)
{
    PyObject *key = 0, *value = 0;
    Py_ssize_t pos = 0;
    PyObject*** name;
    PyObject*** first_kw_arg = argnames + num_pos_args;
    while (PyDict_Next(kwds, &pos, &key, &value)) {
        name = first_kw_arg;
        while (*name && (**name != key)) name++;
        if (*name) {
            values[name-argnames] = value;
            continue;
        }
        name = first_kw_arg;
        #if PY_MAJOR_VERSION < 3
        if (likely(PyString_Check(key))) {
            while (*name) {
                if ((CYTHON_COMPILING_IN_PYPY || PyString_GET_SIZE(**name) == PyString_GET_SIZE(key))
                        && _PyString_Eq(**name, key)) {
                    values[name-argnames] = value;
                    break;
                }
                name++;
            }
            if (*name) continue;
            else {
                PyObject*** argname = argnames;
                while (argname != first_kw_arg) {
                    if ((**argname == key) || (
                            (CYTHON_COMPILING_IN_PYPY || PyString_GET_SIZE(**argname) == PyString_GET_SIZE(key))
                             && _PyString_Eq(**argname, key))) {
                        goto arg_passed_twice;
                    }
                    argname++;
                }
            }
        } else
        #endif
        if (likely(PyUnicode_Check(key))) {
            while (*name) {
                int cmp = (**name == key) ? 0 :
                #if !CYTHON_COMPILING_IN_PYPY && PY_MAJOR_VERSION >= 3
                    (__Pyx_PyUnicode_GET_LENGTH(**name) != __Pyx_PyUnicode_GET_LENGTH(key)) ? 1 :
                #endif
                    PyUnicode_Compare(**name, key);
                if (cmp < 0 && unlikely(PyErr_Occurred())) goto bad;
                if (cmp == 0) {
                    values[name-argnames] = value;
                    break;
                }
                name++;
            }
            if (*name) continue;
            else {
                PyObject*** argname = argnames;
                while (argname != first_kw_arg) {
                    int cmp = (**argname == key) ? 0 :
                    #if !CYTHON_COMPILING_IN_PYPY && PY_MAJOR_VERSION >= 3
                        (__Pyx_PyUnicode_GET_LENGTH(**argname) != __Pyx_PyUnicode_GET_LENGTH(key)) ? 1 :
                    #endif
                        PyUnicode_Compare(**argname, key);
                    if (cmp < 0 && unlikely(PyErr_Occurred())) goto bad;
                    if (cmp == 0) goto arg_passed_twice;
                    argname++;
                }
            }
        } else
            goto invalid_keyword_type;
        if (kwds2) {
            if (unlikely(PyDict_SetItem(kwds2, key, value))) goto bad;
        } else {
            goto invalid_keyword;
        }
    }
    return 0;
arg_passed_twice:
    __Pyx_RaiseDoubleKeywordsError(function_name, key);
    goto bad;
invalid_keyword_type:
    PyErr_Format(PyExc_TypeError,
        "%.200s() keywords must be strings", function_name);
    goto bad;
invalid_keyword:
    PyErr_Format(PyExc_TypeError,
    #if PY_MAJOR_VERSION < 3
        "%.200s() got an unexpected keyword argument '%.200s'",
        function_name, PyString_AsString(key));
    #else
        "%s() got an unexpected keyword argument '%U'",
        function_name, key);
    #endif
bad:
    return -1;
}

/* ArgTypeTest */
static int __Pyx__ArgTypeTest(PyObject *obj, PyTypeObject *type, const char *name, int exact)
{
    if (unlikely(!type)) {
        PyErr_SetString(PyExc_SystemError, "Missing type object");
        return 0;
    }
    else if (exact) {
        #if PY_MAJOR_VERSION == 2
        if ((type == &PyBaseString_Type) && likely(__Pyx_PyBaseString_CheckExact(obj))) return 1;
        #endif
    }
    else {
        if (likely(__Pyx_TypeCheck(obj, type))) return 1;
    }
    PyErr_Format(PyExc_TypeError,
        "Argument '%.200s' has incorrect type (expected %.200s, got %.200s)",
        name, type->tp_name, Py_TYPE(obj)->tp_name);
    return 0;
}

/* JoinPyUnicode */
static PyObject* __Pyx_PyUnicode_Join(PyObject* value_tuple, Py_ssize_t value_count, Py_ssize_t result_ulength,
                                      CYTHON_UNUSED Py_UCS4 max_char) {
#if CYTHON_USE_UNICODE_INTERNALS && CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    PyObject *result_uval;
    int result_ukind;
    Py_ssize_t i, char_pos;
    void *result_udata;
#if CYTHON_PEP393_ENABLED
    result_uval = PyUnicode_New(result_ulength, max_char);
    if (unlikely(!result_uval)) return NULL;
    result_ukind = (max_char <= 255) ? PyUnicode_1BYTE_KIND : (max_char <= 65535) ? PyUnicode_2BYTE_KIND : PyUnicode_4BYTE_KIND;
    result_udata = PyUnicode_DATA(result_uval);
#else
    result_uval = PyUnicode_FromUnicode(NULL, result_ulength);
    if (unlikely(!result_uval)) return NULL;
    result_ukind = sizeof(Py_UNICODE);
    result_udata = PyUnicode_AS_UNICODE(result_uval);
#endif
    char_pos = 0;
    for (i=0; i < value_count; i++) {
        int ukind;
        Py_ssize_t ulength;
        void *udata;
        PyObject *uval = PyTuple_GET_ITEM(value_tuple, i);
        if (unlikely(__Pyx_PyUnicode_READY(uval)))
            goto bad;
        ulength = __Pyx_PyUnicode_GET_LENGTH(uval);
        if (unlikely(!ulength))
            continue;
        if (unlikely(char_pos + ulength < 0))
            goto overflow;
        ukind = __Pyx_PyUnicode_KIND(uval);
        udata = __Pyx_PyUnicode_DATA(uval);
        if (!CYTHON_PEP393_ENABLED || ukind == result_ukind) {
            memcpy((char *)result_udata + char_pos * result_ukind, udata, (size_t) (ulength * result_ukind));
        } else {
            #if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030300F0 || defined(_PyUnicode_FastCopyCharacters)
            _PyUnicode_FastCopyCharacters(result_uval, char_pos, uval, 0, ulength);
            #else
            Py_ssize_t j;
            for (j=0; j < ulength; j++) {
                Py_UCS4 uchar = __Pyx_PyUnicode_READ(ukind, udata, j);
                __Pyx_PyUnicode_WRITE(result_ukind, result_udata, char_pos+j, uchar);
            }
            #endif
        }
        char_pos += ulength;
    }
    return result_uval;
overflow:
    PyErr_SetString(PyExc_OverflowError, "join() result is too long for a Python string");
bad:
    Py_DECREF(result_uval);
    return NULL;
#else
    result_ulength++;
    value_count++;
    return PyUnicode_Join(__pyx_empty_unicode, value_tuple);
#endif
}

/* FastTypeChecks */
#if CYTHON_COMPILING_IN_CPYTHON
static int __Pyx_InBases(PyTypeObject *a, PyTypeObject *b) {
    while (a) {
        a = a->tp_base;
        if (a == b)
            return 1;
    }
    return b == &PyBaseObject_Type;
}
static CYTHON_INLINE int __Pyx_IsSubtype(PyTypeObject *a, PyTypeObject *b) {
    PyObject *mro;
    if (a == b) return 1;
    mro = a->tp_mro;
    if (likely(mro)) {
        Py_ssize_t i, n;
        n = PyTuple_GET_SIZE(mro);
        for (i = 0; i < n; i++) {
            if (PyTuple_GET_ITEM(mro, i) == (PyObject *)b)
                return 1;
        }
        return 0;
    }
    return __Pyx_InBases(a, b);
}
#if PY_MAJOR_VERSION == 2
static int __Pyx_inner_PyErr_GivenExceptionMatches2(PyObject *err, PyObject* exc_type1, PyObject* exc_type2) {
    PyObject *exception, *value, *tb;
    int res;
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ErrFetch(&exception, &value, &tb);
    res = exc_type1 ? PyObject_IsSubclass(err, exc_type1) : 0;
    if (unlikely(res == -1)) {
        PyErr_WriteUnraisable(err);
        res = 0;
    }
    if (!res) {
        res = PyObject_IsSubclass(err, exc_type2);
        if (unlikely(res == -1)) {
            PyErr_WriteUnraisable(err);
            res = 0;
        }
    }
    __Pyx_ErrRestore(exception, value, tb);
    return res;
}
#else
static CYTHON_INLINE int __Pyx_inner_PyErr_GivenExceptionMatches2(PyObject *err, PyObject* exc_type1, PyObject *exc_type2) {
    int res = exc_type1 ? __Pyx_IsSubtype((PyTypeObject*)err, (PyTypeObject*)exc_type1) : 0;
    if (!res) {
        res = __Pyx_IsSubtype((PyTypeObject*)err, (PyTypeObject*)exc_type2);
    }
    return res;
}
#endif
static int __Pyx_PyErr_GivenExceptionMatchesTuple(PyObject *exc_type, PyObject *tuple) {
    Py_ssize_t i, n;
    assert(PyExceptionClass_Check(exc_type));
    n = PyTuple_GET_SIZE(tuple);
#if PY_MAJOR_VERSION >= 3
    for (i=0; i<n; i++) {
        if (exc_type == PyTuple_GET_ITEM(tuple, i)) return 1;
    }
#endif
    for (i=0; i<n; i++) {
        PyObject *t = PyTuple_GET_ITEM(tuple, i);
        #if PY_MAJOR_VERSION < 3
        if (likely(exc_type == t)) return 1;
        #endif
        if (likely(PyExceptionClass_Check(t))) {
            if (__Pyx_inner_PyErr_GivenExceptionMatches2(exc_type, NULL, t)) return 1;
        } else {
        }
    }
    return 0;
}
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches(PyObject *err, PyObject* exc_type) {
    if (likely(err == exc_type)) return 1;
    if (likely(PyExceptionClass_Check(err))) {
        if (likely(PyExceptionClass_Check(exc_type))) {
            return __Pyx_inner_PyErr_GivenExceptionMatches2(err, NULL, exc_type);
        } else if (likely(PyTuple_Check(exc_type))) {
            return __Pyx_PyErr_GivenExceptionMatchesTuple(err, exc_type);
        } else {
        }
    }
    return PyErr_GivenExceptionMatches(err, exc_type);
}
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches2(PyObject *err, PyObject *exc_type1, PyObject *exc_type2) {
    assert(PyExceptionClass_Check(exc_type1));
    assert(PyExceptionClass_Check(exc_type2));
    if (likely(err == exc_type1 || err == exc_type2)) return 1;
    if (likely(PyExceptionClass_Check(err))) {
        return __Pyx_inner_PyErr_GivenExceptionMatches2(err, exc_type1, exc_type2);
    }
    return (PyErr_GivenExceptionMatches(err, exc_type1) || PyErr_GivenExceptionMatches(err, exc_type2));
}
#endif

/* PyObjectCall2Args */
static CYTHON_UNUSED PyObject* __Pyx_PyObject_Call2Args(PyObject* function, PyObject* arg1, PyObject* arg2) {
    PyObject *args, *result = NULL;
    #if CYTHON_FAST_PYCALL
    if (PyFunction_Check(function)) {
        PyObject *args[2] = {arg1, arg2};
        return __Pyx_PyFunction_FastCall(function, args, 2);
    }
    #endif
    #if CYTHON_FAST_PYCCALL
    if (__Pyx_PyFastCFunction_Check(function)) {
        PyObject *args[2] = {arg1, arg2};
        return __Pyx_PyCFunction_FastCall(function, args, 2);
    }
    #endif
    args = PyTuple_New(2);
    if (unlikely(!args)) goto done;
    Py_INCREF(arg1);
    PyTuple_SET_ITEM(args, 0, arg1);
    Py_INCREF(arg2);
    PyTuple_SET_ITEM(args, 1, arg2);
    Py_INCREF(function);
    result = __Pyx_PyObject_Call(function, args, NULL);
    Py_DECREF(args);
    Py_DECREF(function);
done:
    return result;
}

/* SliceObject */
static CYTHON_INLINE PyObject* __Pyx_PyObject_GetSlice(PyObject* obj,
        Py_ssize_t cstart, Py_ssize_t cstop,
        PyObject** _py_start, PyObject** _py_stop, PyObject** _py_slice,
        int has_cstart, int has_cstop, CYTHON_UNUSED int wraparound) {
#if CYTHON_USE_TYPE_SLOTS
    PyMappingMethods* mp;
#if PY_MAJOR_VERSION < 3
    PySequenceMethods* ms = Py_TYPE(obj)->tp_as_sequence;
    if (likely(ms && ms->sq_slice)) {
        if (!has_cstart) {
            if (_py_start && (*_py_start != Py_None)) {
                cstart = __Pyx_PyIndex_AsSsize_t(*_py_start);
                if ((cstart == (Py_ssize_t)-1) && PyErr_Occurred()) goto bad;
            } else
                cstart = 0;
        }
        if (!has_cstop) {
            if (_py_stop && (*_py_stop != Py_None)) {
                cstop = __Pyx_PyIndex_AsSsize_t(*_py_stop);
                if ((cstop == (Py_ssize_t)-1) && PyErr_Occurred()) goto bad;
            } else
                cstop = PY_SSIZE_T_MAX;
        }
        if (wraparound && unlikely((cstart < 0) | (cstop < 0)) && likely(ms->sq_length)) {
            Py_ssize_t l = ms->sq_length(obj);
            if (likely(l >= 0)) {
                if (cstop < 0) {
                    cstop += l;
                    if (cstop < 0) cstop = 0;
                }
                if (cstart < 0) {
                    cstart += l;
                    if (cstart < 0) cstart = 0;
                }
            } else {
                if (!PyErr_ExceptionMatches(PyExc_OverflowError))
                    goto bad;
                PyErr_Clear();
            }
        }
        return ms->sq_slice(obj, cstart, cstop);
    }
#endif
    mp = Py_TYPE(obj)->tp_as_mapping;
    if (likely(mp && mp->mp_subscript))
#endif
    {
        PyObject* result;
        PyObject *py_slice, *py_start, *py_stop;
        if (_py_slice) {
            py_slice = *_py_slice;
        } else {
            PyObject* owned_start = NULL;
            PyObject* owned_stop = NULL;
            if (_py_start) {
                py_start = *_py_start;
            } else {
                if (has_cstart) {
                    owned_start = py_start = PyInt_FromSsize_t(cstart);
                    if (unlikely(!py_start)) goto bad;
                } else
                    py_start = Py_None;
            }
            if (_py_stop) {
                py_stop = *_py_stop;
            } else {
                if (has_cstop) {
                    owned_stop = py_stop = PyInt_FromSsize_t(cstop);
                    if (unlikely(!py_stop)) {
                        Py_XDECREF(owned_start);
                        goto bad;
                    }
                } else
                    py_stop = Py_None;
            }
            py_slice = PySlice_New(py_start, py_stop, Py_None);
            Py_XDECREF(owned_start);
            Py_XDECREF(owned_stop);
            if (unlikely(!py_slice)) goto bad;
        }
#if CYTHON_USE_TYPE_SLOTS
        result = mp->mp_subscript(obj, py_slice);
#else
        result = PyObject_GetItem(obj, py_slice);
#endif
        if (!_py_slice) {
            Py_DECREF(py_slice);
        }
        return result;
    }
    PyErr_Format(PyExc_TypeError,
        "'%.200s' object is unsliceable", Py_TYPE(obj)->tp_name);
bad:
    return NULL;
}

/* RaiseTooManyValuesToUnpack */
static CYTHON_INLINE void __Pyx_RaiseTooManyValuesError(Py_ssize_t expected) {
    PyErr_Format(PyExc_ValueError,
                 "too many values to unpack (expected %" CYTHON_FORMAT_SSIZE_T "d)", expected);
}

/* RaiseNeedMoreValuesToUnpack */
static CYTHON_INLINE void __Pyx_RaiseNeedMoreValuesError(Py_ssize_t index) {
    PyErr_Format(PyExc_ValueError,
                 "need more than %" CYTHON_FORMAT_SSIZE_T "d value%.1s to unpack",
                 index, (index == 1) ? "" : "s");
}

/* IterFinish */
static CYTHON_INLINE int __Pyx_IterFinish(void) {
#if CYTHON_FAST_THREAD_STATE
    PyThreadState *tstate = __Pyx_PyThreadState_Current;
    PyObject* exc_type = tstate->curexc_type;
    if (unlikely(exc_type)) {
        if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) {
            PyObject *exc_value, *exc_tb;
            exc_value = tstate->curexc_value;
            exc_tb = tstate->curexc_traceback;
            tstate->curexc_type = 0;
            tstate->curexc_value = 0;
            tstate->curexc_traceback = 0;
            Py_DECREF(exc_type);
            Py_XDECREF(exc_value);
            Py_XDECREF(exc_tb);
            return 0;
        } else {
            return -1;
        }
    }
    return 0;
#else
    if (unlikely(PyErr_Occurred())) {
        if (likely(PyErr_ExceptionMatches(PyExc_StopIteration))) {
            PyErr_Clear();
            return 0;
        } else {
            return -1;
        }
    }
    return 0;
#endif
}

/* UnpackItemEndCheck */
static int __Pyx_IternextUnpackEndCheck(PyObject *retval, Py_ssize_t expected) {
    if (unlikely(retval)) {
        Py_DECREF(retval);
        __Pyx_RaiseTooManyValuesError(expected);
        return -1;
    } else {
        return __Pyx_IterFinish();
    }
    return 0;
}

/* GetItemInt */
static PyObject *__Pyx_GetItemInt_Generic(PyObject *o, PyObject* j) {
    PyObject *r;
    if (!j) return NULL;
    r = PyObject_GetItem(o, j);
    Py_DECREF(j);
    return r;
}
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_List_Fast(PyObject *o, Py_ssize_t i,
                                                              CYTHON_NCP_UNUSED int wraparound,
                                                              CYTHON_NCP_UNUSED int boundscheck) {
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    Py_ssize_t wrapped_i = i;
    if (wraparound & unlikely(i < 0)) {
        wrapped_i += PyList_GET_SIZE(o);
    }
    if ((!boundscheck) || likely(__Pyx_is_valid_index(wrapped_i, PyList_GET_SIZE(o)))) {
        PyObject *r = PyList_GET_ITEM(o, wrapped_i);
        Py_INCREF(r);
        return r;
    }
    return __Pyx_GetItemInt_Generic(o, PyInt_FromSsize_t(i));
#else
    return PySequence_GetItem(o, i);
#endif
}
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Tuple_Fast(PyObject *o, Py_ssize_t i,
                                                              CYTHON_NCP_UNUSED int wraparound,
                                                              CYTHON_NCP_UNUSED int boundscheck) {
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    Py_ssize_t wrapped_i = i;
    if (wraparound & unlikely(i < 0)) {
        wrapped_i += PyTuple_GET_SIZE(o);
    }
    if ((!boundscheck) || likely(__Pyx_is_valid_index(wrapped_i, PyTuple_GET_SIZE(o)))) {
        PyObject *r = PyTuple_GET_ITEM(o, wrapped_i);
        Py_INCREF(r);
        return r;
    }
    return __Pyx_GetItemInt_Generic(o, PyInt_FromSsize_t(i));
#else
    return PySequence_GetItem(o, i);
#endif
}
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Fast(PyObject *o, Py_ssize_t i, int is_list,
                                                     CYTHON_NCP_UNUSED int wraparound,
                                                     CYTHON_NCP_UNUSED int boundscheck) {
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS && CYTHON_USE_TYPE_SLOTS
    if (is_list || PyList_CheckExact(o)) {
        Py_ssize_t n = ((!wraparound) | likely(i >= 0)) ? i : i + PyList_GET_SIZE(o);
        if ((!boundscheck) || (likely(__Pyx_is_valid_index(n, PyList_GET_SIZE(o))))) {
            PyObject *r = PyList_GET_ITEM(o, n);
            Py_INCREF(r);
            return r;
        }
    }
    else if (PyTuple_CheckExact(o)) {
        Py_ssize_t n = ((!wraparound) | likely(i >= 0)) ? i : i + PyTuple_GET_SIZE(o);
        if ((!boundscheck) || likely(__Pyx_is_valid_index(n, PyTuple_GET_SIZE(o)))) {
            PyObject *r = PyTuple_GET_ITEM(o, n);
            Py_INCREF(r);
            return r;
        }
    } else {
        PySequenceMethods *m = Py_TYPE(o)->tp_as_sequence;
        if (likely(m && m->sq_item)) {
            if (wraparound && unlikely(i < 0) && likely(m->sq_length)) {
                Py_ssize_t l = m->sq_length(o);
                if (likely(l >= 0)) {
                    i += l;
                } else {
                    if (!PyErr_ExceptionMatches(PyExc_OverflowError))
                        return NULL;
                    PyErr_Clear();
                }
            }
            return m->sq_item(o, i);
        }
    }
#else
    if (is_list || PySequence_Check(o)) {
        return PySequence_GetItem(o, i);
    }
#endif
    return __Pyx_GetItemInt_Generic(o, PyInt_FromSsize_t(i));
}

/* ObjectGetItem */
#if CYTHON_USE_TYPE_SLOTS
static PyObject *__Pyx_PyObject_GetIndex(PyObject *obj, PyObject* index) {
    PyObject *runerr;
    Py_ssize_t key_value;
    PySequenceMethods *m = Py_TYPE(obj)->tp_as_sequence;
    if (unlikely(!(m && m->sq_item))) {
        PyErr_Format(PyExc_TypeError, "'%.200s' object is not subscriptable", Py_TYPE(obj)->tp_name);
        return NULL;
    }
    key_value = __Pyx_PyIndex_AsSsize_t(index);
    if (likely(key_value != -1 || !(runerr = PyErr_Occurred()))) {
        return __Pyx_GetItemInt_Fast(obj, key_value, 0, 1, 1);
    }
    if (PyErr_GivenExceptionMatches(runerr, PyExc_OverflowError)) {
        PyErr_Clear();
        PyErr_Format(PyExc_IndexError, "cannot fit '%.200s' into an index-sized integer", Py_TYPE(index)->tp_name);
    }
    return NULL;
}
static PyObject *__Pyx_PyObject_GetItem(PyObject *obj, PyObject* key) {
    PyMappingMethods *m = Py_TYPE(obj)->tp_as_mapping;
    if (likely(m && m->mp_subscript)) {
        return m->mp_subscript(obj, key);
    }
    return __Pyx_PyObject_GetIndex(obj, key);
}
#endif

/* DictGetItem */
#if PY_MAJOR_VERSION >= 3 && !CYTHON_COMPILING_IN_PYPY
static PyObject *__Pyx_PyDict_GetItem(PyObject *d, PyObject* key) {
    PyObject *value;
    value = PyDict_GetItemWithError(d, key);
    if (unlikely(!value)) {
        if (!PyErr_Occurred()) {
            if (unlikely(PyTuple_Check(key))) {
                PyObject* args = PyTuple_Pack(1, key);
                if (likely(args)) {
                    PyErr_SetObject(PyExc_KeyError, args);
                    Py_DECREF(args);
                }
            } else {
                PyErr_SetObject(PyExc_KeyError, key);
            }
        }
        return NULL;
    }
    Py_INCREF(value);
    return value;
}
#endif

/* BytesEquals */
static CYTHON_INLINE int __Pyx_PyBytes_Equals(PyObject* s1, PyObject* s2, int equals) {
#if CYTHON_COMPILING_IN_PYPY
    return PyObject_RichCompareBool(s1, s2, equals);
#else
    if (s1 == s2) {
        return (equals == Py_EQ);
    } else if (PyBytes_CheckExact(s1) & PyBytes_CheckExact(s2)) {
        const char *ps1, *ps2;
        Py_ssize_t length = PyBytes_GET_SIZE(s1);
        if (length != PyBytes_GET_SIZE(s2))
            return (equals == Py_NE);
        ps1 = PyBytes_AS_STRING(s1);
        ps2 = PyBytes_AS_STRING(s2);
        if (ps1[0] != ps2[0]) {
            return (equals == Py_NE);
        } else if (length == 1) {
            return (equals == Py_EQ);
        } else {
            int result;
#if CYTHON_USE_UNICODE_INTERNALS
            Py_hash_t hash1, hash2;
            hash1 = ((PyBytesObject*)s1)->ob_shash;
            hash2 = ((PyBytesObject*)s2)->ob_shash;
            if (hash1 != hash2 && hash1 != -1 && hash2 != -1) {
                return (equals == Py_NE);
            }
#endif
            result = memcmp(ps1, ps2, (size_t)length);
            return (equals == Py_EQ) ? (result == 0) : (result != 0);
        }
    } else if ((s1 == Py_None) & PyBytes_CheckExact(s2)) {
        return (equals == Py_NE);
    } else if ((s2 == Py_None) & PyBytes_CheckExact(s1)) {
        return (equals == Py_NE);
    } else {
        int result;
        PyObject* py_result = PyObject_RichCompare(s1, s2, equals);
        if (!py_result)
            return -1;
        result = __Pyx_PyObject_IsTrue(py_result);
        Py_DECREF(py_result);
        return result;
    }
#endif
}

/* UnicodeEquals */
static CYTHON_INLINE int __Pyx_PyUnicode_Equals(PyObject* s1, PyObject* s2, int equals) {
#if CYTHON_COMPILING_IN_PYPY
    return PyObject_RichCompareBool(s1, s2, equals);
#else
#if PY_MAJOR_VERSION < 3
    PyObject* owned_ref = NULL;
#endif
    int s1_is_unicode, s2_is_unicode;
    if (s1 == s2) {
        goto return_eq;
    }
    s1_is_unicode = PyUnicode_CheckExact(s1);
    s2_is_unicode = PyUnicode_CheckExact(s2);
#if PY_MAJOR_VERSION < 3
    if ((s1_is_unicode & (!s2_is_unicode)) && PyString_CheckExact(s2)) {
        owned_ref = PyUnicode_FromObject(s2);
        if (unlikely(!owned_ref))
            return -1;
        s2 = owned_ref;
        s2_is_unicode = 1;
    } else if ((s2_is_unicode & (!s1_is_unicode)) && PyString_CheckExact(s1)) {
        owned_ref = PyUnicode_FromObject(s1);
        if (unlikely(!owned_ref))
            return -1;
        s1 = owned_ref;
        s1_is_unicode = 1;
    } else if (((!s2_is_unicode) & (!s1_is_unicode))) {
        return __Pyx_PyBytes_Equals(s1, s2, equals);
    }
#endif
    if (s1_is_unicode & s2_is_unicode) {
        Py_ssize_t length;
        int kind;
        void *data1, *data2;
        if (unlikely(__Pyx_PyUnicode_READY(s1) < 0) || unlikely(__Pyx_PyUnicode_READY(s2) < 0))
            return -1;
        length = __Pyx_PyUnicode_GET_LENGTH(s1);
        if (length != __Pyx_PyUnicode_GET_LENGTH(s2)) {
            goto return_ne;
        }
#if CYTHON_USE_UNICODE_INTERNALS
        {
            Py_hash_t hash1, hash2;
        #if CYTHON_PEP393_ENABLED
            hash1 = ((PyASCIIObject*)s1)->hash;
            hash2 = ((PyASCIIObject*)s2)->hash;
        #else
            hash1 = ((PyUnicodeObject*)s1)->hash;
            hash2 = ((PyUnicodeObject*)s2)->hash;
        #endif
            if (hash1 != hash2 && hash1 != -1 && hash2 != -1) {
                goto return_ne;
            }
        }
#endif
        kind = __Pyx_PyUnicode_KIND(s1);
        if (kind != __Pyx_PyUnicode_KIND(s2)) {
            goto return_ne;
        }
        data1 = __Pyx_PyUnicode_DATA(s1);
        data2 = __Pyx_PyUnicode_DATA(s2);
        if (__Pyx_PyUnicode_READ(kind, data1, 0) != __Pyx_PyUnicode_READ(kind, data2, 0)) {
            goto return_ne;
        } else if (length == 1) {
            goto return_eq;
        } else {
            int result = memcmp(data1, data2, (size_t)(length * kind));
            #if PY_MAJOR_VERSION < 3
            Py_XDECREF(owned_ref);
            #endif
            return (equals == Py_EQ) ? (result == 0) : (result != 0);
        }
    } else if ((s1 == Py_None) & s2_is_unicode) {
        goto return_ne;
    } else if ((s2 == Py_None) & s1_is_unicode) {
        goto return_ne;
    } else {
        int result;
        PyObject* py_result = PyObject_RichCompare(s1, s2, equals);
        #if PY_MAJOR_VERSION < 3
        Py_XDECREF(owned_ref);
        #endif
        if (!py_result)
            return -1;
        result = __Pyx_PyObject_IsTrue(py_result);
        Py_DECREF(py_result);
        return result;
    }
return_eq:
    #if PY_MAJOR_VERSION < 3
    Py_XDECREF(owned_ref);
    #endif
    return (equals == Py_EQ);
return_ne:
    #if PY_MAJOR_VERSION < 3
    Py_XDECREF(owned_ref);
    #endif
    return (equals == Py_NE);
#endif
}

/* PyUnicode_Unicode */
static CYTHON_INLINE PyObject* __Pyx_PyUnicode_Unicode(PyObject *obj) {
    if (unlikely(obj == Py_None))
        obj = __pyx_kp_u_None;
    return __Pyx_NewRef(obj);
}

/* CIntToDigits */
static const char DIGIT_PAIRS_10[2*10*10+1] = {
    "00010203040506070809"
    "10111213141516171819"
    "20212223242526272829"
    "30313233343536373839"
    "40414243444546474849"
    "50515253545556575859"
    "60616263646566676869"
    "70717273747576777879"
    "80818283848586878889"
    "90919293949596979899"
};
static const char DIGIT_PAIRS_8[2*8*8+1] = {
    "0001020304050607"
    "1011121314151617"
    "2021222324252627"
    "3031323334353637"
    "4041424344454647"
    "5051525354555657"
    "6061626364656667"
    "7071727374757677"
};
static const char DIGITS_HEX[2*16+1] = {
    "0123456789abcdef"
    "0123456789ABCDEF"
};

/* BuildPyUnicode */
static PyObject* __Pyx_PyUnicode_BuildFromAscii(Py_ssize_t ulength, char* chars, int clength,
                                                int prepend_sign, char padding_char) {
    PyObject *uval;
    Py_ssize_t uoffset = ulength - clength;
#if CYTHON_USE_UNICODE_INTERNALS
    Py_ssize_t i;
#if CYTHON_PEP393_ENABLED
    void *udata;
    uval = PyUnicode_New(ulength, 127);
    if (unlikely(!uval)) return NULL;
    udata = PyUnicode_DATA(uval);
#else
    Py_UNICODE *udata;
    uval = PyUnicode_FromUnicode(NULL, ulength);
    if (unlikely(!uval)) return NULL;
    udata = PyUnicode_AS_UNICODE(uval);
#endif
    if (uoffset > 0) {
        i = 0;
        if (prepend_sign) {
            __Pyx_PyUnicode_WRITE(PyUnicode_1BYTE_KIND, udata, 0, '-');
            i++;
        }
        for (; i < uoffset; i++) {
            __Pyx_PyUnicode_WRITE(PyUnicode_1BYTE_KIND, udata, i, padding_char);
        }
    }
    for (i=0; i < clength; i++) {
        __Pyx_PyUnicode_WRITE(PyUnicode_1BYTE_KIND, udata, uoffset+i, chars[i]);
    }
#else
    {
        PyObject *sign = NULL, *padding = NULL;
        uval = NULL;
        if (uoffset > 0) {
            prepend_sign = !!prepend_sign;
            if (uoffset > prepend_sign) {
                padding = PyUnicode_FromOrdinal(padding_char);
                if (likely(padding) && uoffset > prepend_sign + 1) {
                    PyObject *tmp;
                    PyObject *repeat = PyInt_FromSize_t(uoffset - prepend_sign);
                    if (unlikely(!repeat)) goto done_or_error;
                    tmp = PyNumber_Multiply(padding, repeat);
                    Py_DECREF(repeat);
                    Py_DECREF(padding);
                    padding = tmp;
                }
                if (unlikely(!padding)) goto done_or_error;
            }
            if (prepend_sign) {
                sign = PyUnicode_FromOrdinal('-');
                if (unlikely(!sign)) goto done_or_error;
            }
        }
        uval = PyUnicode_DecodeASCII(chars, clength, NULL);
        if (likely(uval) && padding) {
            PyObject *tmp = PyNumber_Add(padding, uval);
            Py_DECREF(uval);
            uval = tmp;
        }
        if (likely(uval) && sign) {
            PyObject *tmp = PyNumber_Add(sign, uval);
            Py_DECREF(uval);
            uval = tmp;
        }
done_or_error:
        Py_XDECREF(padding);
        Py_XDECREF(sign);
    }
#endif
    return uval;
}

/* CIntToPyUnicode */
#ifdef _MSC_VER
    #ifndef _MSC_STDINT_H_
        #if _MSC_VER < 1300
           typedef unsigned short    uint16_t;
        #else
           typedef unsigned __int16  uint16_t;
        #endif
    #endif
#else
   #include <stdint.h>
#endif
#if defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6))
#define GCC_DIAGNOSTIC
#endif
static CYTHON_INLINE PyObject* __Pyx_PyUnicode_From_Py_ssize_t(Py_ssize_t value, Py_ssize_t width, char padding_char, char format_char) {
    char digits[sizeof(Py_ssize_t)*3+2];
    char *dpos, *end = digits + sizeof(Py_ssize_t)*3+2;
    const char *hex_digits = DIGITS_HEX;
    Py_ssize_t length, ulength;
    int prepend_sign, last_one_off;
    Py_ssize_t remaining;
#ifdef GCC_DIAGNOSTIC
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#endif
    const Py_ssize_t neg_one = (Py_ssize_t) -1, const_zero = (Py_ssize_t) 0;
#ifdef GCC_DIAGNOSTIC
#pragma GCC diagnostic pop
#endif
    const int is_unsigned = neg_one > const_zero;
    if (format_char == 'X') {
        hex_digits += 16;
        format_char = 'x';
    }
    remaining = value;
    last_one_off = 0;
    dpos = end;
    do {
        int digit_pos;
        switch (format_char) {
        case 'o':
            digit_pos = abs((int)(remaining % (8*8)));
            remaining = (Py_ssize_t) (remaining / (8*8));
            dpos -= 2;
            *(uint16_t*)dpos = ((const uint16_t*)DIGIT_PAIRS_8)[digit_pos];
            last_one_off = (digit_pos < 8);
            break;
        case 'd':
            digit_pos = abs((int)(remaining % (10*10)));
            remaining = (Py_ssize_t) (remaining / (10*10));
            dpos -= 2;
            *(uint16_t*)dpos = ((const uint16_t*)DIGIT_PAIRS_10)[digit_pos];
            last_one_off = (digit_pos < 10);
            break;
        case 'x':
            *(--dpos) = hex_digits[abs((int)(remaining % 16))];
            remaining = (Py_ssize_t) (remaining / 16);
            break;
        default:
            assert(0);
            break;
        }
    } while (unlikely(remaining != 0));
    if (last_one_off) {
        assert(*dpos == '0');
        dpos++;
    }
    length = end - dpos;
    ulength = length;
    prepend_sign = 0;
    if (!is_unsigned && value <= neg_one) {
        if (padding_char == ' ' || width <= length + 1) {
            *(--dpos) = '-';
            ++length;
        } else {
            prepend_sign = 1;
        }
        ++ulength;
    }
    if (width > ulength) {
        ulength = width;
    }
    if (ulength == 1) {
        return PyUnicode_FromOrdinal(*dpos);
    }
    return __Pyx_PyUnicode_BuildFromAscii(ulength, dpos, (int) length, prepend_sign, padding_char);
}

/* CIntToPyUnicode */
#ifdef _MSC_VER
    #ifndef _MSC_STDINT_H_
        #if _MSC_VER < 1300
           typedef unsigned short    uint16_t;
        #else
           typedef unsigned __int16  uint16_t;
        #endif
    #endif
#else
   #include <stdint.h>
#endif
#if defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6))
#define GCC_DIAGNOSTIC
#endif
static CYTHON_INLINE PyObject* __Pyx_PyUnicode_From_long(long value, Py_ssize_t width, char padding_char, char format_char) {
    char digits[sizeof(long)*3+2];
    char *dpos, *end = digits + sizeof(long)*3+2;
    const char *hex_digits = DIGITS_HEX;
    Py_ssize_t length, ulength;
    int prepend_sign, last_one_off;
    long remaining;
#ifdef GCC_DIAGNOSTIC
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#endif
    const long neg_one = (long) -1, const_zero = (long) 0;
#ifdef GCC_DIAGNOSTIC
#pragma GCC diagnostic pop
#endif
    const int is_unsigned = neg_one > const_zero;
    if (format_char == 'X') {
        hex_digits += 16;
        format_char = 'x';
    }
    remaining = value;
    last_one_off = 0;
    dpos = end;
    do {
        int digit_pos;
        switch (format_char) {
        case 'o':
            digit_pos = abs((int)(remaining % (8*8)));
            remaining = (long) (remaining / (8*8));
            dpos -= 2;
            *(uint16_t*)dpos = ((const uint16_t*)DIGIT_PAIRS_8)[digit_pos];
            last_one_off = (digit_pos < 8);
            break;
        case 'd':
            digit_pos = abs((int)(remaining % (10*10)));
            remaining = (long) (remaining / (10*10));
            dpos -= 2;
            *(uint16_t*)dpos = ((const uint16_t*)DIGIT_PAIRS_10)[digit_pos];
            last_one_off = (digit_pos < 10);
            break;
        case 'x':
            *(--dpos) = hex_digits[abs((int)(remaining % 16))];
            remaining = (long) (remaining / 16);
            break;
        default:
            assert(0);
            break;
        }
    } while (unlikely(remaining != 0));
    if (last_one_off) {
        assert(*dpos == '0');
        dpos++;
    }
    length = end - dpos;
    ulength = length;
    prepend_sign = 0;
    if (!is_unsigned && value <= neg_one) {
        if (padding_char == ' ' || width <= length + 1) {
            *(--dpos) = '-';
            ++length;
        } else {
            prepend_sign = 1;
        }
        ++ulength;
    }
    if (width > ulength) {
        ulength = width;
    }
    if (ulength == 1) {
        return PyUnicode_FromOrdinal(*dpos);
    }
    return __Pyx_PyUnicode_BuildFromAscii(ulength, dpos, (int) length, prepend_sign, padding_char);
}

/* PyIntCompare */
static CYTHON_INLINE PyObject* __Pyx_PyInt_EqObjC(PyObject *op1, PyObject *op2, CYTHON_UNUSED long intval, CYTHON_UNUSED long inplace) {
    if (op1 == op2) {
        Py_RETURN_TRUE;
    }
    #if PY_MAJOR_VERSION < 3
    if (likely(PyInt_CheckExact(op1))) {
        const long b = intval;
        long a = PyInt_AS_LONG(op1);
        if (a == b) Py_RETURN_TRUE; else Py_RETURN_FALSE;
    }
    #endif
    #if CYTHON_USE_PYLONG_INTERNALS
    if (likely(PyLong_CheckExact(op1))) {
        int unequal;
        unsigned long uintval;
        Py_ssize_t size = Py_SIZE(op1);
        const digit* digits = ((PyLongObject*)op1)->ob_digit;
        if (intval == 0) {
            if (size == 0) Py_RETURN_TRUE; else Py_RETURN_FALSE;
        } else if (intval < 0) {
            if (size >= 0)
                Py_RETURN_FALSE;
            intval = -intval;
            size = -size;
        } else {
            if (size <= 0)
                Py_RETURN_FALSE;
        }
        uintval = (unsigned long) intval;
#if PyLong_SHIFT * 4 < SIZEOF_LONG*8
        if (uintval >> (PyLong_SHIFT * 4)) {
            unequal = (size != 5) || (digits[0] != (uintval & (unsigned long) PyLong_MASK))
                 | (digits[1] != ((uintval >> (1 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK)) | (digits[2] != ((uintval >> (2 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK)) | (digits[3] != ((uintval >> (3 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK)) | (digits[4] != ((uintval >> (4 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK));
        } else
#endif
#if PyLong_SHIFT * 3 < SIZEOF_LONG*8
        if (uintval >> (PyLong_SHIFT * 3)) {
            unequal = (size != 4) || (digits[0] != (uintval & (unsigned long) PyLong_MASK))
                 | (digits[1] != ((uintval >> (1 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK)) | (digits[2] != ((uintval >> (2 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK)) | (digits[3] != ((uintval >> (3 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK));
        } else
#endif
#if PyLong_SHIFT * 2 < SIZEOF_LONG*8
        if (uintval >> (PyLong_SHIFT * 2)) {
            unequal = (size != 3) || (digits[0] != (uintval & (unsigned long) PyLong_MASK))
                 | (digits[1] != ((uintval >> (1 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK)) | (digits[2] != ((uintval >> (2 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK));
        } else
#endif
#if PyLong_SHIFT * 1 < SIZEOF_LONG*8
        if (uintval >> (PyLong_SHIFT * 1)) {
            unequal = (size != 2) || (digits[0] != (uintval & (unsigned long) PyLong_MASK))
                 | (digits[1] != ((uintval >> (1 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK));
        } else
#endif
            unequal = (size != 1) || (((unsigned long) digits[0]) != (uintval & (unsigned long) PyLong_MASK));
        if (unequal == 0) Py_RETURN_TRUE; else Py_RETURN_FALSE;
    }
    #endif
    if (PyFloat_CheckExact(op1)) {
        const long b = intval;
        double a = PyFloat_AS_DOUBLE(op1);
        if ((double)a == (double)b) Py_RETURN_TRUE; else Py_RETURN_FALSE;
    }
    return (
        PyObject_RichCompare(op1, op2, Py_EQ));
}

/* SliceTupleAndList */
#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE void __Pyx_crop_slice(Py_ssize_t* _start, Py_ssize_t* _stop, Py_ssize_t* _length) {
    Py_ssize_t start = *_start, stop = *_stop, length = *_length;
    if (start < 0) {
        start += length;
        if (start < 0)
            start = 0;
    }
    if (stop < 0)
        stop += length;
    else if (stop > length)
        stop = length;
    *_length = stop - start;
    *_start = start;
    *_stop = stop;
}
static CYTHON_INLINE void __Pyx_copy_object_array(PyObject** CYTHON_RESTRICT src, PyObject** CYTHON_RESTRICT dest, Py_ssize_t length) {
    PyObject *v;
    Py_ssize_t i;
    for (i = 0; i < length; i++) {
        v = dest[i] = src[i];
        Py_INCREF(v);
    }
}
static CYTHON_INLINE PyObject* __Pyx_PyList_GetSlice(
            PyObject* src, Py_ssize_t start, Py_ssize_t stop) {
    PyObject* dest;
    Py_ssize_t length = PyList_GET_SIZE(src);
    __Pyx_crop_slice(&start, &stop, &length);
    if (unlikely(length <= 0))
        return PyList_New(0);
    dest = PyList_New(length);
    if (unlikely(!dest))
        return NULL;
    __Pyx_copy_object_array(
        ((PyListObject*)src)->ob_item + start,
        ((PyListObject*)dest)->ob_item,
        length);
    return dest;
}
static CYTHON_INLINE PyObject* __Pyx_PyTuple_GetSlice(
            PyObject* src, Py_ssize_t start, Py_ssize_t stop) {
    PyObject* dest;
    Py_ssize_t length = PyTuple_GET_SIZE(src);
    __Pyx_crop_slice(&start, &stop, &length);
    if (unlikely(length <= 0))
        return PyTuple_New(0);
    dest = PyTuple_New(length);
    if (unlikely(!dest))
        return NULL;
    __Pyx_copy_object_array(
        ((PyTupleObject*)src)->ob_item + start,
        ((PyTupleObject*)dest)->ob_item,
        length);
    return dest;
}
#endif

/* PyObject_GenericGetAttrNoDict */
#if CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP && PY_VERSION_HEX < 0x03070000
static PyObject *__Pyx_RaiseGenericGetAttributeError(PyTypeObject *tp, PyObject *attr_name) {
    PyErr_Format(PyExc_AttributeError,
#if PY_MAJOR_VERSION >= 3
                 "'%.50s' object has no attribute '%U'",
                 tp->tp_name, attr_name);
#else
                 "'%.50s' object has no attribute '%.400s'",
                 tp->tp_name, PyString_AS_STRING(attr_name));
#endif
    return NULL;
}
static CYTHON_INLINE PyObject* __Pyx_PyObject_GenericGetAttrNoDict(PyObject* obj, PyObject* attr_name) {
    PyObject *descr;
    PyTypeObject *tp = Py_TYPE(obj);
    if (unlikely(!PyString_Check(attr_name))) {
        return PyObject_GenericGetAttr(obj, attr_name);
    }
    assert(!tp->tp_dictoffset);
    descr = _PyType_Lookup(tp, attr_name);
    if (unlikely(!descr)) {
        return __Pyx_RaiseGenericGetAttributeError(tp, attr_name);
    }
    Py_INCREF(descr);
    #if PY_MAJOR_VERSION < 3
    if (likely(PyType_HasFeature(Py_TYPE(descr), Py_TPFLAGS_HAVE_CLASS)))
    #endif
    {
        descrgetfunc f = Py_TYPE(descr)->tp_descr_get;
        if (unlikely(f)) {
            PyObject *res = f(descr, obj, (PyObject *)tp);
            Py_DECREF(descr);
            return res;
        }
    }
    return descr;
}
#endif

/* Import */
static PyObject *__Pyx_Import(PyObject *name, PyObject *from_list, int level) {
    PyObject *empty_list = 0;
    PyObject *module = 0;
    PyObject *global_dict = 0;
    PyObject *empty_dict = 0;
    PyObject *list;
    #if PY_MAJOR_VERSION < 3
    PyObject *py_import;
    py_import = __Pyx_PyObject_GetAttrStr(__pyx_b, __pyx_n_s_import);
    if (!py_import)
        goto bad;
    #endif
    if (from_list)
        list = from_list;
    else {
        empty_list = PyList_New(0);
        if (!empty_list)
            goto bad;
        list = empty_list;
    }
    global_dict = PyModule_GetDict(__pyx_m);
    if (!global_dict)
        goto bad;
    empty_dict = PyDict_New();
    if (!empty_dict)
        goto bad;
    {
        #if PY_MAJOR_VERSION >= 3
        if (level == -1) {
            if ((1) && (strchr(__Pyx_MODULE_NAME, '.'))) {
                module = PyImport_ImportModuleLevelObject(
                    name, global_dict, empty_dict, list, 1);
                if (!module) {
                    if (!PyErr_ExceptionMatches(PyExc_ImportError))
                        goto bad;
                    PyErr_Clear();
                }
            }
            level = 0;
        }
        #endif
        if (!module) {
            #if PY_MAJOR_VERSION < 3
            PyObject *py_level = PyInt_FromLong(level);
            if (!py_level)
                goto bad;
            module = PyObject_CallFunctionObjArgs(py_import,
                name, global_dict, empty_dict, list, py_level, (PyObject *)NULL);
            Py_DECREF(py_level);
            #else
            module = PyImport_ImportModuleLevelObject(
                name, global_dict, empty_dict, list, level);
            #endif
        }
    }
bad:
    #if PY_MAJOR_VERSION < 3
    Py_XDECREF(py_import);
    #endif
    Py_XDECREF(empty_list);
    Py_XDECREF(empty_dict);
    return module;
}

/* ImportFrom */
static PyObject* __Pyx_ImportFrom(PyObject* module, PyObject* name) {
    PyObject* value = __Pyx_PyObject_GetAttrStr(module, name);
    if (unlikely(!value) && PyErr_ExceptionMatches(PyExc_AttributeError)) {
        PyErr_Format(PyExc_ImportError,
        #if PY_MAJOR_VERSION < 3
            "cannot import name %.230s", PyString_AS_STRING(name));
        #else
            "cannot import name %S", name);
        #endif
    }
    return value;
}

/* FetchCommonType */
static PyTypeObject* __Pyx_FetchCommonType(PyTypeObject* type) {
    PyObject* fake_module;
    PyTypeObject* cached_type = NULL;
    fake_module = PyImport_AddModule((char*) "_cython_" CYTHON_ABI);
    if (!fake_module) return NULL;
    Py_INCREF(fake_module);
    cached_type = (PyTypeObject*) PyObject_GetAttrString(fake_module, type->tp_name);
    if (cached_type) {
        if (!PyType_Check((PyObject*)cached_type)) {
            PyErr_Format(PyExc_TypeError,
                "Shared Cython type %.200s is not a type object",
                type->tp_name);
            goto bad;
        }
        if (cached_type->tp_basicsize != type->tp_basicsize) {
            PyErr_Format(PyExc_TypeError,
                "Shared Cython type %.200s has the wrong size, try recompiling",
                type->tp_name);
            goto bad;
        }
    } else {
        if (!PyErr_ExceptionMatches(PyExc_AttributeError)) goto bad;
        PyErr_Clear();
        if (PyType_Ready(type) < 0) goto bad;
        if (PyObject_SetAttrString(fake_module, type->tp_name, (PyObject*) type) < 0)
            goto bad;
        Py_INCREF(type);
        cached_type = type;
    }
done:
    Py_DECREF(fake_module);
    return cached_type;
bad:
    Py_XDECREF(cached_type);
    cached_type = NULL;
    goto done;
}

/* CythonFunctionShared */
#include <structmember.h>
static PyObject *
__Pyx_CyFunction_get_doc(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *closure)
{
    if (unlikely(op->func_doc == NULL)) {
        if (op->func.m_ml->ml_doc) {
#if PY_MAJOR_VERSION >= 3
            op->func_doc = PyUnicode_FromString(op->func.m_ml->ml_doc);
#else
            op->func_doc = PyString_FromString(op->func.m_ml->ml_doc);
#endif
            if (unlikely(op->func_doc == NULL))
                return NULL;
        } else {
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    Py_INCREF(op->func_doc);
    return op->func_doc;
}
static int
__Pyx_CyFunction_set_doc(__pyx_CyFunctionObject *op, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp = op->func_doc;
    if (value == NULL) {
        value = Py_None;
    }
    Py_INCREF(value);
    op->func_doc = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_name(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    if (unlikely(op->func_name == NULL)) {
#if PY_MAJOR_VERSION >= 3
        op->func_name = PyUnicode_InternFromString(op->func.m_ml->ml_name);
#else
        op->func_name = PyString_InternFromString(op->func.m_ml->ml_name);
#endif
        if (unlikely(op->func_name == NULL))
            return NULL;
    }
    Py_INCREF(op->func_name);
    return op->func_name;
}
static int
__Pyx_CyFunction_set_name(__pyx_CyFunctionObject *op, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp;
#if PY_MAJOR_VERSION >= 3
    if (unlikely(value == NULL || !PyUnicode_Check(value)))
#else
    if (unlikely(value == NULL || !PyString_Check(value)))
#endif
    {
        PyErr_SetString(PyExc_TypeError,
                        "__name__ must be set to a string object");
        return -1;
    }
    tmp = op->func_name;
    Py_INCREF(value);
    op->func_name = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_qualname(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    Py_INCREF(op->func_qualname);
    return op->func_qualname;
}
static int
__Pyx_CyFunction_set_qualname(__pyx_CyFunctionObject *op, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp;
#if PY_MAJOR_VERSION >= 3
    if (unlikely(value == NULL || !PyUnicode_Check(value)))
#else
    if (unlikely(value == NULL || !PyString_Check(value)))
#endif
    {
        PyErr_SetString(PyExc_TypeError,
                        "__qualname__ must be set to a string object");
        return -1;
    }
    tmp = op->func_qualname;
    Py_INCREF(value);
    op->func_qualname = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_self(__pyx_CyFunctionObject *m, CYTHON_UNUSED void *closure)
{
    PyObject *self;
    self = m->func_closure;
    if (self == NULL)
        self = Py_None;
    Py_INCREF(self);
    return self;
}
static PyObject *
__Pyx_CyFunction_get_dict(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    if (unlikely(op->func_dict == NULL)) {
        op->func_dict = PyDict_New();
        if (unlikely(op->func_dict == NULL))
            return NULL;
    }
    Py_INCREF(op->func_dict);
    return op->func_dict;
}
static int
__Pyx_CyFunction_set_dict(__pyx_CyFunctionObject *op, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp;
    if (unlikely(value == NULL)) {
        PyErr_SetString(PyExc_TypeError,
               "function's dictionary may not be deleted");
        return -1;
    }
    if (unlikely(!PyDict_Check(value))) {
        PyErr_SetString(PyExc_TypeError,
               "setting function's dictionary to a non-dict");
        return -1;
    }
    tmp = op->func_dict;
    Py_INCREF(value);
    op->func_dict = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_globals(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    Py_INCREF(op->func_globals);
    return op->func_globals;
}
static PyObject *
__Pyx_CyFunction_get_closure(CYTHON_UNUSED __pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    Py_INCREF(Py_None);
    return Py_None;
}
static PyObject *
__Pyx_CyFunction_get_code(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    PyObject* result = (op->func_code) ? op->func_code : Py_None;
    Py_INCREF(result);
    return result;
}
static int
__Pyx_CyFunction_init_defaults(__pyx_CyFunctionObject *op) {
    int result = 0;
    PyObject *res = op->defaults_getter((PyObject *) op);
    if (unlikely(!res))
        return -1;
    #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    op->defaults_tuple = PyTuple_GET_ITEM(res, 0);
    Py_INCREF(op->defaults_tuple);
    op->defaults_kwdict = PyTuple_GET_ITEM(res, 1);
    Py_INCREF(op->defaults_kwdict);
    #else
    op->defaults_tuple = PySequence_ITEM(res, 0);
    if (unlikely(!op->defaults_tuple)) result = -1;
    else {
        op->defaults_kwdict = PySequence_ITEM(res, 1);
        if (unlikely(!op->defaults_kwdict)) result = -1;
    }
    #endif
    Py_DECREF(res);
    return result;
}
static int
__Pyx_CyFunction_set_defaults(__pyx_CyFunctionObject *op, PyObject* value, CYTHON_UNUSED void *context) {
    PyObject* tmp;
    if (!value) {
        value = Py_None;
    } else if (value != Py_None && !PyTuple_Check(value)) {
        PyErr_SetString(PyExc_TypeError,
                        "__defaults__ must be set to a tuple object");
        return -1;
    }
    Py_INCREF(value);
    tmp = op->defaults_tuple;
    op->defaults_tuple = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_defaults(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context) {
    PyObject* result = op->defaults_tuple;
    if (unlikely(!result)) {
        if (op->defaults_getter) {
            if (__Pyx_CyFunction_init_defaults(op) < 0) return NULL;
            result = op->defaults_tuple;
        } else {
            result = Py_None;
        }
    }
    Py_INCREF(result);
    return result;
}
static int
__Pyx_CyFunction_set_kwdefaults(__pyx_CyFunctionObject *op, PyObject* value, CYTHON_UNUSED void *context) {
    PyObject* tmp;
    if (!value) {
        value = Py_None;
    } else if (value != Py_None && !PyDict_Check(value)) {
        PyErr_SetString(PyExc_TypeError,
                        "__kwdefaults__ must be set to a dict object");
        return -1;
    }
    Py_INCREF(value);
    tmp = op->defaults_kwdict;
    op->defaults_kwdict = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_kwdefaults(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context) {
    PyObject* result = op->defaults_kwdict;
    if (unlikely(!result)) {
        if (op->defaults_getter) {
            if (__Pyx_CyFunction_init_defaults(op) < 0) return NULL;
            result = op->defaults_kwdict;
        } else {
            result = Py_None;
        }
    }
    Py_INCREF(result);
    return result;
}
static int
__Pyx_CyFunction_set_annotations(__pyx_CyFunctionObject *op, PyObject* value, CYTHON_UNUSED void *context) {
    PyObject* tmp;
    if (!value || value == Py_None) {
        value = NULL;
    } else if (!PyDict_Check(value)) {
        PyErr_SetString(PyExc_TypeError,
                        "__annotations__ must be set to a dict object");
        return -1;
    }
    Py_XINCREF(value);
    tmp = op->func_annotations;
    op->func_annotations = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_annotations(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context) {
    PyObject* result = op->func_annotations;
    if (unlikely(!result)) {
        result = PyDict_New();
        if (unlikely(!result)) return NULL;
        op->func_annotations = result;
    }
    Py_INCREF(result);
    return result;
}
static PyGetSetDef __pyx_CyFunction_getsets[] = {
    {(char *) "func_doc", (getter)__Pyx_CyFunction_get_doc, (setter)__Pyx_CyFunction_set_doc, 0, 0},
    {(char *) "__doc__",  (getter)__Pyx_CyFunction_get_doc, (setter)__Pyx_CyFunction_set_doc, 0, 0},
    {(char *) "func_name", (getter)__Pyx_CyFunction_get_name, (setter)__Pyx_CyFunction_set_name, 0, 0},
    {(char *) "__name__", (getter)__Pyx_CyFunction_get_name, (setter)__Pyx_CyFunction_set_name, 0, 0},
    {(char *) "__qualname__", (getter)__Pyx_CyFunction_get_qualname, (setter)__Pyx_CyFunction_set_qualname, 0, 0},
    {(char *) "__self__", (getter)__Pyx_CyFunction_get_self, 0, 0, 0},
    {(char *) "func_dict", (getter)__Pyx_CyFunction_get_dict, (setter)__Pyx_CyFunction_set_dict, 0, 0},
    {(char *) "__dict__", (getter)__Pyx_CyFunction_get_dict, (setter)__Pyx_CyFunction_set_dict, 0, 0},
    {(char *) "func_globals", (getter)__Pyx_CyFunction_get_globals, 0, 0, 0},
    {(char *) "__globals__", (getter)__Pyx_CyFunction_get_globals, 0, 0, 0},
    {(char *) "func_closure", (getter)__Pyx_CyFunction_get_closure, 0, 0, 0},
    {(char *) "__closure__", (getter)__Pyx_CyFunction_get_closure, 0, 0, 0},
    {(char *) "func_code", (getter)__Pyx_CyFunction_get_code, 0, 0, 0},
    {(char *) "__code__", (getter)__Pyx_CyFunction_get_code, 0, 0, 0},
    {(char *) "func_defaults", (getter)__Pyx_CyFunction_get_defaults, (setter)__Pyx_CyFunction_set_defaults, 0, 0},
    {(char *) "__defaults__", (getter)__Pyx_CyFunction_get_defaults, (setter)__Pyx_CyFunction_set_defaults, 0, 0},
    {(char *) "__kwdefaults__", (getter)__Pyx_CyFunction_get_kwdefaults, (setter)__Pyx_CyFunction_set_kwdefaults, 0, 0},
    {(char *) "__annotations__", (getter)__Pyx_CyFunction_get_annotations, (setter)__Pyx_CyFunction_set_annotations, 0, 0},
    {0, 0, 0, 0, 0}
};
static PyMemberDef __pyx_CyFunction_members[] = {
    {(char *) "__module__", T_OBJECT, offsetof(PyCFunctionObject, m_module), PY_WRITE_RESTRICTED, 0},
    {0, 0, 0,  0, 0}
};
static PyObject *
__Pyx_CyFunction_reduce(__pyx_CyFunctionObject *m, CYTHON_UNUSED PyObject *args)
{
#if PY_MAJOR_VERSION >= 3
    return PyUnicode_FromString(m->func.m_ml->ml_name);
#else
    return PyString_FromString(m->func.m_ml->ml_name);
#endif
}
static PyMethodDef __pyx_CyFunction_methods[] = {
    {"__reduce__", (PyCFunction)__Pyx_CyFunction_reduce, METH_VARARGS, 0},
    {0, 0, 0, 0}
};
#if PY_VERSION_HEX < 0x030500A0
#define __Pyx_CyFunction_weakreflist(cyfunc) ((cyfunc)->func_weakreflist)
#else
#define __Pyx_CyFunction_weakreflist(cyfunc) ((cyfunc)->func.m_weakreflist)
#endif
static PyObject *__Pyx_CyFunction_Init(__pyx_CyFunctionObject *op, PyMethodDef *ml, int flags, PyObject* qualname,
                                       PyObject *closure, PyObject *module, PyObject* globals, PyObject* code) {
    if (unlikely(op == NULL))
        return NULL;
    op->flags = flags;
    __Pyx_CyFunction_weakreflist(op) = NULL;
    op->func.m_ml = ml;
    op->func.m_self = (PyObject *) op;
    Py_XINCREF(closure);
    op->func_closure = closure;
    Py_XINCREF(module);
    op->func.m_module = module;
    op->func_dict = NULL;
    op->func_name = NULL;
    Py_INCREF(qualname);
    op->func_qualname = qualname;
    op->func_doc = NULL;
    op->func_classobj = NULL;
    op->func_globals = globals;
    Py_INCREF(op->func_globals);
    Py_XINCREF(code);
    op->func_code = code;
    op->defaults_pyobjects = 0;
    op->defaults_size = 0;
    op->defaults = NULL;
    op->defaults_tuple = NULL;
    op->defaults_kwdict = NULL;
    op->defaults_getter = NULL;
    op->func_annotations = NULL;
    return (PyObject *) op;
}
static int
__Pyx_CyFunction_clear(__pyx_CyFunctionObject *m)
{
    Py_CLEAR(m->func_closure);
    Py_CLEAR(m->func.m_module);
    Py_CLEAR(m->func_dict);
    Py_CLEAR(m->func_name);
    Py_CLEAR(m->func_qualname);
    Py_CLEAR(m->func_doc);
    Py_CLEAR(m->func_globals);
    Py_CLEAR(m->func_code);
    Py_CLEAR(m->func_classobj);
    Py_CLEAR(m->defaults_tuple);
    Py_CLEAR(m->defaults_kwdict);
    Py_CLEAR(m->func_annotations);
    if (m->defaults) {
        PyObject **pydefaults = __Pyx_CyFunction_Defaults(PyObject *, m);
        int i;
        for (i = 0; i < m->defaults_pyobjects; i++)
            Py_XDECREF(pydefaults[i]);
        PyObject_Free(m->defaults);
        m->defaults = NULL;
    }
    return 0;
}
static void __Pyx__CyFunction_dealloc(__pyx_CyFunctionObject *m)
{
    if (__Pyx_CyFunction_weakreflist(m) != NULL)
        PyObject_ClearWeakRefs((PyObject *) m);
    __Pyx_CyFunction_clear(m);
    PyObject_GC_Del(m);
}
static void __Pyx_CyFunction_dealloc(__pyx_CyFunctionObject *m)
{
    PyObject_GC_UnTrack(m);
    __Pyx__CyFunction_dealloc(m);
}
static int __Pyx_CyFunction_traverse(__pyx_CyFunctionObject *m, visitproc visit, void *arg)
{
    Py_VISIT(m->func_closure);
    Py_VISIT(m->func.m_module);
    Py_VISIT(m->func_dict);
    Py_VISIT(m->func_name);
    Py_VISIT(m->func_qualname);
    Py_VISIT(m->func_doc);
    Py_VISIT(m->func_globals);
    Py_VISIT(m->func_code);
    Py_VISIT(m->func_classobj);
    Py_VISIT(m->defaults_tuple);
    Py_VISIT(m->defaults_kwdict);
    if (m->defaults) {
        PyObject **pydefaults = __Pyx_CyFunction_Defaults(PyObject *, m);
        int i;
        for (i = 0; i < m->defaults_pyobjects; i++)
            Py_VISIT(pydefaults[i]);
    }
    return 0;
}
static PyObject *__Pyx_CyFunction_descr_get(PyObject *func, PyObject *obj, PyObject *type)
{
#if PY_MAJOR_VERSION < 3
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    if (m->flags & __Pyx_CYFUNCTION_STATICMETHOD) {
        Py_INCREF(func);
        return func;
    }
    if (m->flags & __Pyx_CYFUNCTION_CLASSMETHOD) {
        if (type == NULL)
            type = (PyObject *)(Py_TYPE(obj));
        return __Pyx_PyMethod_New(func, type, (PyObject *)(Py_TYPE(type)));
    }
    if (obj == Py_None)
        obj = NULL;
#endif
    return __Pyx_PyMethod_New(func, obj, type);
}
static PyObject*
__Pyx_CyFunction_repr(__pyx_CyFunctionObject *op)
{
#if PY_MAJOR_VERSION >= 3
    return PyUnicode_FromFormat("<cyfunction %U at %p>",
                                op->func_qualname, (void *)op);
#else
    return PyString_FromFormat("<cyfunction %s at %p>",
                               PyString_AsString(op->func_qualname), (void *)op);
#endif
}
static PyObject * __Pyx_CyFunction_CallMethod(PyObject *func, PyObject *self, PyObject *arg, PyObject *kw) {
    PyCFunctionObject* f = (PyCFunctionObject*)func;
    PyCFunction meth = f->m_ml->ml_meth;
    Py_ssize_t size;
    switch (f->m_ml->ml_flags & (METH_VARARGS | METH_KEYWORDS | METH_NOARGS | METH_O)) {
    case METH_VARARGS:
        if (likely(kw == NULL || PyDict_Size(kw) == 0))
            return (*meth)(self, arg);
        break;
    case METH_VARARGS | METH_KEYWORDS:
        return (*(PyCFunctionWithKeywords)(void*)meth)(self, arg, kw);
    case METH_NOARGS:
        if (likely(kw == NULL || PyDict_Size(kw) == 0)) {
            size = PyTuple_GET_SIZE(arg);
            if (likely(size == 0))
                return (*meth)(self, NULL);
            PyErr_Format(PyExc_TypeError,
                "%.200s() takes no arguments (%" CYTHON_FORMAT_SSIZE_T "d given)",
                f->m_ml->ml_name, size);
            return NULL;
        }
        break;
    case METH_O:
        if (likely(kw == NULL || PyDict_Size(kw) == 0)) {
            size = PyTuple_GET_SIZE(arg);
            if (likely(size == 1)) {
                PyObject *result, *arg0;
                #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
                arg0 = PyTuple_GET_ITEM(arg, 0);
                #else
                arg0 = PySequence_ITEM(arg, 0); if (unlikely(!arg0)) return NULL;
                #endif
                result = (*meth)(self, arg0);
                #if !(CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS)
                Py_DECREF(arg0);
                #endif
                return result;
            }
            PyErr_Format(PyExc_TypeError,
                "%.200s() takes exactly one argument (%" CYTHON_FORMAT_SSIZE_T "d given)",
                f->m_ml->ml_name, size);
            return NULL;
        }
        break;
    default:
        PyErr_SetString(PyExc_SystemError, "Bad call flags in "
                        "__Pyx_CyFunction_Call. METH_OLDARGS is no "
                        "longer supported!");
        return NULL;
    }
    PyErr_Format(PyExc_TypeError, "%.200s() takes no keyword arguments",
                 f->m_ml->ml_name);
    return NULL;
}
static CYTHON_INLINE PyObject *__Pyx_CyFunction_Call(PyObject *func, PyObject *arg, PyObject *kw) {
    return __Pyx_CyFunction_CallMethod(func, ((PyCFunctionObject*)func)->m_self, arg, kw);
}
static PyObject *__Pyx_CyFunction_CallAsMethod(PyObject *func, PyObject *args, PyObject *kw) {
    PyObject *result;
    __pyx_CyFunctionObject *cyfunc = (__pyx_CyFunctionObject *) func;
    if ((cyfunc->flags & __Pyx_CYFUNCTION_CCLASS) && !(cyfunc->flags & __Pyx_CYFUNCTION_STATICMETHOD)) {
        Py_ssize_t argc;
        PyObject *new_args;
        PyObject *self;
        argc = PyTuple_GET_SIZE(args);
        new_args = PyTuple_GetSlice(args, 1, argc);
        if (unlikely(!new_args))
            return NULL;
        self = PyTuple_GetItem(args, 0);
        if (unlikely(!self)) {
            Py_DECREF(new_args);
            return NULL;
        }
        result = __Pyx_CyFunction_CallMethod(func, self, new_args, kw);
        Py_DECREF(new_args);
    } else {
        result = __Pyx_CyFunction_Call(func, args, kw);
    }
    return result;
}
static PyTypeObject __pyx_CyFunctionType_type = {
    PyVarObject_HEAD_INIT(0, 0)
    "cython_function_or_method",
    sizeof(__pyx_CyFunctionObject),
    0,
    (destructor) __Pyx_CyFunction_dealloc,
    0,
    0,
    0,
#if PY_MAJOR_VERSION < 3
    0,
#else
    0,
#endif
    (reprfunc) __Pyx_CyFunction_repr,
    0,
    0,
    0,
    0,
    __Pyx_CyFunction_CallAsMethod,
    0,
    0,
    0,
    0,
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HAVE_GC,
    0,
    (traverseproc) __Pyx_CyFunction_traverse,
    (inquiry) __Pyx_CyFunction_clear,
    0,
#if PY_VERSION_HEX < 0x030500A0
    offsetof(__pyx_CyFunctionObject, func_weakreflist),
#else
    offsetof(PyCFunctionObject, m_weakreflist),
#endif
    0,
    0,
    __pyx_CyFunction_methods,
    __pyx_CyFunction_members,
    __pyx_CyFunction_getsets,
    0,
    0,
    __Pyx_CyFunction_descr_get,
    0,
    offsetof(__pyx_CyFunctionObject, func_dict),
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
#if PY_VERSION_HEX >= 0x030400a1
    0,
#endif
#if PY_VERSION_HEX >= 0x030800b1
    0,
#endif
#if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
    0,
#endif
};
static int __pyx_CyFunction_init(void) {
    __pyx_CyFunctionType = __Pyx_FetchCommonType(&__pyx_CyFunctionType_type);
    if (unlikely(__pyx_CyFunctionType == NULL)) {
        return -1;
    }
    return 0;
}
static CYTHON_INLINE void *__Pyx_CyFunction_InitDefaults(PyObject *func, size_t size, int pyobjects) {
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->defaults = PyObject_Malloc(size);
    if (unlikely(!m->defaults))
        return PyErr_NoMemory();
    memset(m->defaults, 0, size);
    m->defaults_pyobjects = pyobjects;
    m->defaults_size = size;
    return m->defaults;
}
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsTuple(PyObject *func, PyObject *tuple) {
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->defaults_tuple = tuple;
    Py_INCREF(tuple);
}
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsKwDict(PyObject *func, PyObject *dict) {
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->defaults_kwdict = dict;
    Py_INCREF(dict);
}
static CYTHON_INLINE void __Pyx_CyFunction_SetAnnotationsDict(PyObject *func, PyObject *dict) {
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->func_annotations = dict;
    Py_INCREF(dict);
}

/* CythonFunction */
static PyObject *__Pyx_CyFunction_New(PyMethodDef *ml, int flags, PyObject* qualname,
                                      PyObject *closure, PyObject *module, PyObject* globals, PyObject* code) {
    PyObject *op = __Pyx_CyFunction_Init(
        PyObject_GC_New(__pyx_CyFunctionObject, __pyx_CyFunctionType),
        ml, flags, qualname, closure, module, globals, code
    );
    if (likely(op)) {
        PyObject_GC_Track(op);
    }
    return op;
}

/* CLineInTraceback */
#ifndef CYTHON_CLINE_IN_TRACEBACK
static int __Pyx_CLineForTraceback(CYTHON_NCP_UNUSED PyThreadState *tstate, int c_line) {
    PyObject *use_cline;
    PyObject *ptype, *pvalue, *ptraceback;
#if CYTHON_COMPILING_IN_CPYTHON
    PyObject **cython_runtime_dict;
#endif
    if (unlikely(!__pyx_cython_runtime)) {
        return c_line;
    }
    __Pyx_ErrFetchInState(tstate, &ptype, &pvalue, &ptraceback);
#if CYTHON_COMPILING_IN_CPYTHON
    cython_runtime_dict = _PyObject_GetDictPtr(__pyx_cython_runtime);
    if (likely(cython_runtime_dict)) {
        __PYX_PY_DICT_LOOKUP_IF_MODIFIED(
            use_cline, *cython_runtime_dict,
            __Pyx_PyDict_GetItemStr(*cython_runtime_dict, __pyx_n_s_cline_in_traceback))
    } else
#endif
    {
      PyObject *use_cline_obj = __Pyx_PyObject_GetAttrStr(__pyx_cython_runtime, __pyx_n_s_cline_in_traceback);
      if (use_cline_obj) {
        use_cline = PyObject_Not(use_cline_obj) ? Py_False : Py_True;
        Py_DECREF(use_cline_obj);
      } else {
        PyErr_Clear();
        use_cline = NULL;
      }
    }
    if (!use_cline) {
        c_line = 0;
        PyObject_SetAttr(__pyx_cython_runtime, __pyx_n_s_cline_in_traceback, Py_False);
    }
    else if (use_cline == Py_False || (use_cline != Py_True && PyObject_Not(use_cline) != 0)) {
        c_line = 0;
    }
    __Pyx_ErrRestoreInState(tstate, ptype, pvalue, ptraceback);
    return c_line;
}
#endif

/* CodeObjectCache */
static int __pyx_bisect_code_objects(__Pyx_CodeObjectCacheEntry* entries, int count, int code_line) {
    int start = 0, mid = 0, end = count - 1;
    if (end >= 0 && code_line > entries[end].code_line) {
        return count;
    }
    while (start < end) {
        mid = start + (end - start) / 2;
        if (code_line < entries[mid].code_line) {
            end = mid;
        } else if (code_line > entries[mid].code_line) {
             start = mid + 1;
        } else {
            return mid;
        }
    }
    if (code_line <= entries[mid].code_line) {
        return mid;
    } else {
        return mid + 1;
    }
}
static PyCodeObject *__pyx_find_code_object(int code_line) {
    PyCodeObject* code_object;
    int pos;
    if (unlikely(!code_line) || unlikely(!__pyx_code_cache.entries)) {
        return NULL;
    }
    pos = __pyx_bisect_code_objects(__pyx_code_cache.entries, __pyx_code_cache.count, code_line);
    if (unlikely(pos >= __pyx_code_cache.count) || unlikely(__pyx_code_cache.entries[pos].code_line != code_line)) {
        return NULL;
    }
    code_object = __pyx_code_cache.entries[pos].code_object;
    Py_INCREF(code_object);
    return code_object;
}
static void __pyx_insert_code_object(int code_line, PyCodeObject* code_object) {
    int pos, i;
    __Pyx_CodeObjectCacheEntry* entries = __pyx_code_cache.entries;
    if (unlikely(!code_line)) {
        return;
    }
    if (unlikely(!entries)) {
        entries = (__Pyx_CodeObjectCacheEntry*)PyMem_Malloc(64*sizeof(__Pyx_CodeObjectCacheEntry));
        if (likely(entries)) {
            __pyx_code_cache.entries = entries;
            __pyx_code_cache.max_count = 64;
            __pyx_code_cache.count = 1;
            entries[0].code_line = code_line;
            entries[0].code_object = code_object;
            Py_INCREF(code_object);
        }
        return;
    }
    pos = __pyx_bisect_code_objects(__pyx_code_cache.entries, __pyx_code_cache.count, code_line);
    if ((pos < __pyx_code_cache.count) && unlikely(__pyx_code_cache.entries[pos].code_line == code_line)) {
        PyCodeObject* tmp = entries[pos].code_object;
        entries[pos].code_object = code_object;
        Py_DECREF(tmp);
        return;
    }
    if (__pyx_code_cache.count == __pyx_code_cache.max_count) {
        int new_max = __pyx_code_cache.max_count + 64;
        entries = (__Pyx_CodeObjectCacheEntry*)PyMem_Realloc(
            __pyx_code_cache.entries, ((size_t)new_max) * sizeof(__Pyx_CodeObjectCacheEntry));
        if (unlikely(!entries)) {
            return;
        }
        __pyx_code_cache.entries = entries;
        __pyx_code_cache.max_count = new_max;
    }
    for (i=__pyx_code_cache.count; i>pos; i--) {
        entries[i] = entries[i-1];
    }
    entries[pos].code_line = code_line;
    entries[pos].code_object = code_object;
    __pyx_code_cache.count++;
    Py_INCREF(code_object);
}

/* AddTraceback */
#include "compile.h"
#include "frameobject.h"
#include "traceback.h"
static PyCodeObject* __Pyx_CreateCodeObjectForTraceback(
            const char *funcname, int c_line,
            int py_line, const char *filename) {
    PyCodeObject *py_code = 0;
    PyObject *py_srcfile = 0;
    PyObject *py_funcname = 0;
    #if PY_MAJOR_VERSION < 3
    py_srcfile = PyString_FromString(filename);
    #else
    py_srcfile = PyUnicode_FromString(filename);
    #endif
    if (!py_srcfile) goto bad;
    if (c_line) {
        #if PY_MAJOR_VERSION < 3
        py_funcname = PyString_FromFormat( "%s (%s:%d)", funcname, __pyx_cfilenm, c_line);
        #else
        py_funcname = PyUnicode_FromFormat( "%s (%s:%d)", funcname, __pyx_cfilenm, c_line);
        #endif
    }
    else {
        #if PY_MAJOR_VERSION < 3
        py_funcname = PyString_FromString(funcname);
        #else
        py_funcname = PyUnicode_FromString(funcname);
        #endif
    }
    if (!py_funcname) goto bad;
    py_code = __Pyx_PyCode_New(
        0,
        0,
        0,
        0,
        0,
        __pyx_empty_bytes, /*PyObject *code,*/
        __pyx_empty_tuple, /*PyObject *consts,*/
        __pyx_empty_tuple, /*PyObject *names,*/
        __pyx_empty_tuple, /*PyObject *varnames,*/
        __pyx_empty_tuple, /*PyObject *freevars,*/
        __pyx_empty_tuple, /*PyObject *cellvars,*/
        py_srcfile,   /*PyObject *filename,*/
        py_funcname,  /*PyObject *name,*/
        py_line,
        __pyx_empty_bytes  /*PyObject *lnotab*/
    );
    Py_DECREF(py_srcfile);
    Py_DECREF(py_funcname);
    return py_code;
bad:
    Py_XDECREF(py_srcfile);
    Py_XDECREF(py_funcname);
    return NULL;
}
static void __Pyx_AddTraceback(const char *funcname, int c_line,
                               int py_line, const char *filename) {
    PyCodeObject *py_code = 0;
    PyFrameObject *py_frame = 0;
    PyThreadState *tstate = __Pyx_PyThreadState_Current;
    if (c_line) {
        c_line = __Pyx_CLineForTraceback(tstate, c_line);
    }
    py_code = __pyx_find_code_object(c_line ? -c_line : py_line);
    if (!py_code) {
        py_code = __Pyx_CreateCodeObjectForTraceback(
            funcname, c_line, py_line, filename);
        if (!py_code) goto bad;
        __pyx_insert_code_object(c_line ? -c_line : py_line, py_code);
    }
    py_frame = PyFrame_New(
        tstate,            /*PyThreadState *tstate,*/
        py_code,           /*PyCodeObject *code,*/
        __pyx_d,    /*PyObject *globals,*/
        0                  /*PyObject *locals*/
    );
    if (!py_frame) goto bad;
    __Pyx_PyFrame_SetLineNumber(py_frame, py_line);
    PyTraceBack_Here(py_frame);
bad:
    Py_XDECREF(py_code);
    Py_XDECREF(py_frame);
}

/* CIntToPy */
static CYTHON_INLINE PyObject* __Pyx_PyInt_From_long(long value) {
    const long neg_one = (long) ((long) 0 - (long) 1), const_zero = (long) 0;
    const int is_unsigned = neg_one > const_zero;
    if (is_unsigned) {
        if (sizeof(long) < sizeof(long)) {
            return PyInt_FromLong((long) value);
        } else if (sizeof(long) <= sizeof(unsigned long)) {
            return PyLong_FromUnsignedLong((unsigned long) value);
#ifdef HAVE_LONG_LONG
        } else if (sizeof(long) <= sizeof(unsigned PY_LONG_LONG)) {
            return PyLong_FromUnsignedLongLong((unsigned PY_LONG_LONG) value);
#endif
        }
    } else {
        if (sizeof(long) <= sizeof(long)) {
            return PyInt_FromLong((long) value);
#ifdef HAVE_LONG_LONG
        } else if (sizeof(long) <= sizeof(PY_LONG_LONG)) {
            return PyLong_FromLongLong((PY_LONG_LONG) value);
#endif
        }
    }
    {
        int one = 1; int little = (int)*(unsigned char *)&one;
        unsigned char *bytes = (unsigned char *)&value;
        return _PyLong_FromByteArray(bytes, sizeof(long),
                                     little, !is_unsigned);
    }
}

/* CIntFromPyVerify */
#define __PYX_VERIFY_RETURN_INT(target_type, func_type, func_value)\
    __PYX__VERIFY_RETURN_INT(target_type, func_type, func_value, 0)
#define __PYX_VERIFY_RETURN_INT_EXC(target_type, func_type, func_value)\
    __PYX__VERIFY_RETURN_INT(target_type, func_type, func_value, 1)
#define __PYX__VERIFY_RETURN_INT(target_type, func_type, func_value, exc)\
    {\
        func_type value = func_value;\
        if (sizeof(target_type) < sizeof(func_type)) {\
            if (unlikely(value != (func_type) (target_type) value)) {\
                func_type zero = 0;\
                if (exc && unlikely(value == (func_type)-1 && PyErr_Occurred()))\
                    return (target_type) -1;\
                if (is_unsigned && unlikely(value < zero))\
                    goto raise_neg_overflow;\
                else\
                    goto raise_overflow;\
            }\
        }\
        return (target_type) value;\
    }

/* CIntFromPy */
static CYTHON_INLINE long __Pyx_PyInt_As_long(PyObject *x) {
    const long neg_one = (long) ((long) 0 - (long) 1), const_zero = (long) 0;
    const int is_unsigned = neg_one > const_zero;
#if PY_MAJOR_VERSION < 3
    if (likely(PyInt_Check(x))) {
        if (sizeof(long) < sizeof(long)) {
            __PYX_VERIFY_RETURN_INT(long, long, PyInt_AS_LONG(x))
        } else {
            long val = PyInt_AS_LONG(x);
            if (is_unsigned && unlikely(val < 0)) {
                goto raise_neg_overflow;
            }
            return (long) val;
        }
    } else
#endif
    if (likely(PyLong_Check(x))) {
        if (is_unsigned) {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (long) 0;
                case  1: __PYX_VERIFY_RETURN_INT(long, digit, digits[0])
                case 2:
                    if (8 * sizeof(long) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) >= 2 * PyLong_SHIFT) {
                            return (long) (((((long)digits[1]) << PyLong_SHIFT) | (long)digits[0]));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(long) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) >= 3 * PyLong_SHIFT) {
                            return (long) (((((((long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0]));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(long) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) >= 4 * PyLong_SHIFT) {
                            return (long) (((((((((long)digits[3]) << PyLong_SHIFT) | (long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0]));
                        }
                    }
                    break;
            }
#endif
#if CYTHON_COMPILING_IN_CPYTHON
            if (unlikely(Py_SIZE(x) < 0)) {
                goto raise_neg_overflow;
            }
#else
            {
                int result = PyObject_RichCompareBool(x, Py_False, Py_LT);
                if (unlikely(result < 0))
                    return (long) -1;
                if (unlikely(result == 1))
                    goto raise_neg_overflow;
            }
#endif
            if (sizeof(long) <= sizeof(unsigned long)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, unsigned long, PyLong_AsUnsignedLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(long) <= sizeof(unsigned PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, unsigned PY_LONG_LONG, PyLong_AsUnsignedLongLong(x))
#endif
            }
        } else {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (long) 0;
                case -1: __PYX_VERIFY_RETURN_INT(long, sdigit, (sdigit) (-(sdigit)digits[0]))
                case  1: __PYX_VERIFY_RETURN_INT(long,  digit, +digits[0])
                case -2:
                    if (8 * sizeof(long) - 1 > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, long, -(long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                            return (long) (((long)-1)*(((((long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case 2:
                    if (8 * sizeof(long) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                            return (long) ((((((long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case -3:
                    if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, long, -(long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                            return (long) (((long)-1)*(((((((long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(long) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                            return (long) ((((((((long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case -4:
                    if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, long, -(long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                            return (long) (((long)-1)*(((((((((long)digits[3]) << PyLong_SHIFT) | (long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(long) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                            return (long) ((((((((((long)digits[3]) << PyLong_SHIFT) | (long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
            }
#endif
            if (sizeof(long) <= sizeof(long)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, long, PyLong_AsLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(long) <= sizeof(PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, PY_LONG_LONG, PyLong_AsLongLong(x))
#endif
            }
        }
        {
#if CYTHON_COMPILING_IN_PYPY && !defined(_PyLong_AsByteArray)
            PyErr_SetString(PyExc_RuntimeError,
                            "_PyLong_AsByteArray() not available in PyPy, cannot convert large numbers");
#else
            long val;
            PyObject *v = __Pyx_PyNumber_IntOrLong(x);
 #if PY_MAJOR_VERSION < 3
            if (likely(v) && !PyLong_Check(v)) {
                PyObject *tmp = v;
                v = PyNumber_Long(tmp);
                Py_DECREF(tmp);
            }
 #endif
            if (likely(v)) {
                int one = 1; int is_little = (int)*(unsigned char *)&one;
                unsigned char *bytes = (unsigned char *)&val;
                int ret = _PyLong_AsByteArray((PyLongObject *)v,
                                              bytes, sizeof(val),
                                              is_little, !is_unsigned);
                Py_DECREF(v);
                if (likely(!ret))
                    return val;
            }
#endif
            return (long) -1;
        }
    } else {
        long val;
        PyObject *tmp = __Pyx_PyNumber_IntOrLong(x);
        if (!tmp) return (long) -1;
        val = __Pyx_PyInt_As_long(tmp);
        Py_DECREF(tmp);
        return val;
    }
raise_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "value too large to convert to long");
    return (long) -1;
raise_neg_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "can't convert negative value to long");
    return (long) -1;
}

/* CIntFromPy */
static CYTHON_INLINE int __Pyx_PyInt_As_int(PyObject *x) {
    const int neg_one = (int) ((int) 0 - (int) 1), const_zero = (int) 0;
    const int is_unsigned = neg_one > const_zero;
#if PY_MAJOR_VERSION < 3
    if (likely(PyInt_Check(x))) {
        if (sizeof(int) < sizeof(long)) {
            __PYX_VERIFY_RETURN_INT(int, long, PyInt_AS_LONG(x))
        } else {
            long val = PyInt_AS_LONG(x);
            if (is_unsigned && unlikely(val < 0)) {
                goto raise_neg_overflow;
            }
            return (int) val;
        }
    } else
#endif
    if (likely(PyLong_Check(x))) {
        if (is_unsigned) {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (int) 0;
                case  1: __PYX_VERIFY_RETURN_INT(int, digit, digits[0])
                case 2:
                    if (8 * sizeof(int) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) >= 2 * PyLong_SHIFT) {
                            return (int) (((((int)digits[1]) << PyLong_SHIFT) | (int)digits[0]));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(int) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) >= 3 * PyLong_SHIFT) {
                            return (int) (((((((int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0]));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(int) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) >= 4 * PyLong_SHIFT) {
                            return (int) (((((((((int)digits[3]) << PyLong_SHIFT) | (int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0]));
                        }
                    }
                    break;
            }
#endif
#if CYTHON_COMPILING_IN_CPYTHON
            if (unlikely(Py_SIZE(x) < 0)) {
                goto raise_neg_overflow;
            }
#else
            {
                int result = PyObject_RichCompareBool(x, Py_False, Py_LT);
                if (unlikely(result < 0))
                    return (int) -1;
                if (unlikely(result == 1))
                    goto raise_neg_overflow;
            }
#endif
            if (sizeof(int) <= sizeof(unsigned long)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, unsigned long, PyLong_AsUnsignedLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(int) <= sizeof(unsigned PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, unsigned PY_LONG_LONG, PyLong_AsUnsignedLongLong(x))
#endif
            }
        } else {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (int) 0;
                case -1: __PYX_VERIFY_RETURN_INT(int, sdigit, (sdigit) (-(sdigit)digits[0]))
                case  1: __PYX_VERIFY_RETURN_INT(int,  digit, +digits[0])
                case -2:
                    if (8 * sizeof(int) - 1 > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, long, -(long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 2 * PyLong_SHIFT) {
                            return (int) (((int)-1)*(((((int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case 2:
                    if (8 * sizeof(int) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 2 * PyLong_SHIFT) {
                            return (int) ((((((int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case -3:
                    if (8 * sizeof(int) - 1 > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, long, -(long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 3 * PyLong_SHIFT) {
                            return (int) (((int)-1)*(((((((int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(int) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 3 * PyLong_SHIFT) {
                            return (int) ((((((((int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case -4:
                    if (8 * sizeof(int) - 1 > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, long, -(long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 4 * PyLong_SHIFT) {
                            return (int) (((int)-1)*(((((((((int)digits[3]) << PyLong_SHIFT) | (int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(int) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 4 * PyLong_SHIFT) {
                            return (int) ((((((((((int)digits[3]) << PyLong_SHIFT) | (int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
            }
#endif
            if (sizeof(int) <= sizeof(long)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, long, PyLong_AsLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(int) <= sizeof(PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, PY_LONG_LONG, PyLong_AsLongLong(x))
#endif
            }
        }
        {
#if CYTHON_COMPILING_IN_PYPY && !defined(_PyLong_AsByteArray)
            PyErr_SetString(PyExc_RuntimeError,
                            "_PyLong_AsByteArray() not available in PyPy, cannot convert large numbers");
#else
            int val;
            PyObject *v = __Pyx_PyNumber_IntOrLong(x);
 #if PY_MAJOR_VERSION < 3
            if (likely(v) && !PyLong_Check(v)) {
                PyObject *tmp = v;
                v = PyNumber_Long(tmp);
                Py_DECREF(tmp);
            }
 #endif
            if (likely(v)) {
                int one = 1; int is_little = (int)*(unsigned char *)&one;
                unsigned char *bytes = (unsigned char *)&val;
                int ret = _PyLong_AsByteArray((PyLongObject *)v,
                                              bytes, sizeof(val),
                                              is_little, !is_unsigned);
                Py_DECREF(v);
                if (likely(!ret))
                    return val;
            }
#endif
            return (int) -1;
        }
    } else {
        int val;
        PyObject *tmp = __Pyx_PyNumber_IntOrLong(x);
        if (!tmp) return (int) -1;
        val = __Pyx_PyInt_As_int(tmp);
        Py_DECREF(tmp);
        return val;
    }
raise_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "value too large to convert to int");
    return (int) -1;
raise_neg_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "can't convert negative value to int");
    return (int) -1;
}

/* RaiseException */
#if PY_MAJOR_VERSION < 3
static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb,
                        CYTHON_UNUSED PyObject *cause) {
    __Pyx_PyThreadState_declare
    Py_XINCREF(type);
    if (!value || value == Py_None)
        value = NULL;
    else
        Py_INCREF(value);
    if (!tb || tb == Py_None)
        tb = NULL;
    else {
        Py_INCREF(tb);
        if (!PyTraceBack_Check(tb)) {
            PyErr_SetString(PyExc_TypeError,
                "raise: arg 3 must be a traceback or None");
            goto raise_error;
        }
    }
    if (PyType_Check(type)) {
#if CYTHON_COMPILING_IN_PYPY
        if (!value) {
            Py_INCREF(Py_None);
            value = Py_None;
        }
#endif
        PyErr_NormalizeException(&type, &value, &tb);
    } else {
        if (value) {
            PyErr_SetString(PyExc_TypeError,
                "instance exception may not have a separate value");
            goto raise_error;
        }
        value = type;
        type = (PyObject*) Py_TYPE(type);
        Py_INCREF(type);
        if (!PyType_IsSubtype((PyTypeObject *)type, (PyTypeObject *)PyExc_BaseException)) {
            PyErr_SetString(PyExc_TypeError,
                "raise: exception class must be a subclass of BaseException");
            goto raise_error;
        }
    }
    __Pyx_PyThreadState_assign
    __Pyx_ErrRestore(type, value, tb);
    return;
raise_error:
    Py_XDECREF(value);
    Py_XDECREF(type);
    Py_XDECREF(tb);
    return;
}
#else
static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb, PyObject *cause) {
    PyObject* owned_instance = NULL;
    if (tb == Py_None) {
        tb = 0;
    } else if (tb && !PyTraceBack_Check(tb)) {
        PyErr_SetString(PyExc_TypeError,
            "raise: arg 3 must be a traceback or None");
        goto bad;
    }
    if (value == Py_None)
        value = 0;
    if (PyExceptionInstance_Check(type)) {
        if (value) {
            PyErr_SetString(PyExc_TypeError,
                "instance exception may not have a separate value");
            goto bad;
        }
        value = type;
        type = (PyObject*) Py_TYPE(value);
    } else if (PyExceptionClass_Check(type)) {
        PyObject *instance_class = NULL;
        if (value && PyExceptionInstance_Check(value)) {
            instance_class = (PyObject*) Py_TYPE(value);
            if (instance_class != type) {
                int is_subclass = PyObject_IsSubclass(instance_class, type);
                if (!is_subclass) {
                    instance_class = NULL;
                } else if (unlikely(is_subclass == -1)) {
                    goto bad;
                } else {
                    type = instance_class;
                }
            }
        }
        if (!instance_class) {
            PyObject *args;
            if (!value)
                args = PyTuple_New(0);
            else if (PyTuple_Check(value)) {
                Py_INCREF(value);
                args = value;
            } else
                args = PyTuple_Pack(1, value);
            if (!args)
                goto bad;
            owned_instance = PyObject_Call(type, args, NULL);
            Py_DECREF(args);
            if (!owned_instance)
                goto bad;
            value = owned_instance;
            if (!PyExceptionInstance_Check(value)) {
                PyErr_Format(PyExc_TypeError,
                             "calling %R should have returned an instance of "
                             "BaseException, not %R",
                             type, Py_TYPE(value));
                goto bad;
            }
        }
    } else {
        PyErr_SetString(PyExc_TypeError,
            "raise: exception class must be a subclass of BaseException");
        goto bad;
    }
    if (cause) {
        PyObject *fixed_cause;
        if (cause == Py_None) {
            fixed_cause = NULL;
        } else if (PyExceptionClass_Check(cause)) {
            fixed_cause = PyObject_CallObject(cause, NULL);
            if (fixed_cause == NULL)
                goto bad;
        } else if (PyExceptionInstance_Check(cause)) {
            fixed_cause = cause;
            Py_INCREF(fixed_cause);
        } else {
            PyErr_SetString(PyExc_TypeError,
                            "exception causes must derive from "
                            "BaseException");
            goto bad;
        }
        PyException_SetCause(value, fixed_cause);
    }
    PyErr_SetObject(type, value);
    if (tb) {
#if CYTHON_COMPILING_IN_PYPY
        PyObject *tmp_type, *tmp_value, *tmp_tb;
        PyErr_Fetch(&tmp_type, &tmp_value, &tmp_tb);
        Py_INCREF(tb);
        PyErr_Restore(tmp_type, tmp_value, tb);
        Py_XDECREF(tmp_tb);
#else
        PyThreadState *tstate = __Pyx_PyThreadState_Current;
        PyObject* tmp_tb = tstate->curexc_traceback;
        if (tb != tmp_tb) {
            Py_INCREF(tb);
            tstate->curexc_traceback = tb;
            Py_XDECREF(tmp_tb);
        }
#endif
    }
bad:
    Py_XDECREF(owned_instance);
    return;
}
#endif

/* PyObjectGetMethod */
static int __Pyx_PyObject_GetMethod(PyObject *obj, PyObject *name, PyObject **method) {
    PyObject *attr;
#if CYTHON_UNPACK_METHODS && CYTHON_COMPILING_IN_CPYTHON && CYTHON_USE_PYTYPE_LOOKUP
    PyTypeObject *tp = Py_TYPE(obj);
    PyObject *descr;
    descrgetfunc f = NULL;
    PyObject **dictptr, *dict;
    int meth_found = 0;
    assert (*method == NULL);
    if (unlikely(tp->tp_getattro != PyObject_GenericGetAttr)) {
        attr = __Pyx_PyObject_GetAttrStr(obj, name);
        goto try_unpack;
    }
    if (unlikely(tp->tp_dict == NULL) && unlikely(PyType_Ready(tp) < 0)) {
        return 0;
    }
    descr = _PyType_Lookup(tp, name);
    if (likely(descr != NULL)) {
        Py_INCREF(descr);
#if PY_MAJOR_VERSION >= 3
        #ifdef __Pyx_CyFunction_USED
        if (likely(PyFunction_Check(descr) || (Py_TYPE(descr) == &PyMethodDescr_Type) || __Pyx_CyFunction_Check(descr)))
        #else
        if (likely(PyFunction_Check(descr) || (Py_TYPE(descr) == &PyMethodDescr_Type)))
        #endif
#else
        #ifdef __Pyx_CyFunction_USED
        if (likely(PyFunction_Check(descr) || __Pyx_CyFunction_Check(descr)))
        #else
        if (likely(PyFunction_Check(descr)))
        #endif
#endif
        {
            meth_found = 1;
        } else {
            f = Py_TYPE(descr)->tp_descr_get;
            if (f != NULL && PyDescr_IsData(descr)) {
                attr = f(descr, obj, (PyObject *)Py_TYPE(obj));
                Py_DECREF(descr);
                goto try_unpack;
            }
        }
    }
    dictptr = _PyObject_GetDictPtr(obj);
    if (dictptr != NULL && (dict = *dictptr) != NULL) {
        Py_INCREF(dict);
        attr = __Pyx_PyDict_GetItemStr(dict, name);
        if (attr != NULL) {
            Py_INCREF(attr);
            Py_DECREF(dict);
            Py_XDECREF(descr);
            goto try_unpack;
        }
        Py_DECREF(dict);
    }
    if (meth_found) {
        *method = descr;
        return 1;
    }
    if (f != NULL) {
        attr = f(descr, obj, (PyObject *)Py_TYPE(obj));
        Py_DECREF(descr);
        goto try_unpack;
    }
    if (descr != NULL) {
        *method = descr;
        return 0;
    }
    PyErr_Format(PyExc_AttributeError,
#if PY_MAJOR_VERSION >= 3
                 "'%.50s' object has no attribute '%U'",
                 tp->tp_name, name);
#else
                 "'%.50s' object has no attribute '%.400s'",
                 tp->tp_name, PyString_AS_STRING(name));
#endif
    return 0;
#else
    attr = __Pyx_PyObject_GetAttrStr(obj, name);
    goto try_unpack;
#endif
try_unpack:
#if CYTHON_UNPACK_METHODS
    if (likely(attr) && PyMethod_Check(attr) && likely(PyMethod_GET_SELF(attr) == obj)) {
        PyObject *function = PyMethod_GET_FUNCTION(attr);
        Py_INCREF(function);
        Py_DECREF(attr);
        *method = function;
        return 1;
    }
#endif
    *method = attr;
    return 0;
}

/* PyObjectCallMethod1 */
static PyObject* __Pyx__PyObject_CallMethod1(PyObject* method, PyObject* arg) {
    PyObject *result = __Pyx_PyObject_CallOneArg(method, arg);
    Py_DECREF(method);
    return result;
}
static PyObject* __Pyx_PyObject_CallMethod1(PyObject* obj, PyObject* method_name, PyObject* arg) {
    PyObject *method = NULL, *result;
    int is_method = __Pyx_PyObject_GetMethod(obj, method_name, &method);
    if (likely(is_method)) {
        result = __Pyx_PyObject_Call2Args(method, obj, arg);
        Py_DECREF(method);
        return result;
    }
    if (unlikely(!method)) return NULL;
    return __Pyx__PyObject_CallMethod1(method, arg);
}

/* CoroutineBase */
#include <structmember.h>
#include <frameobject.h>
#define __Pyx_Coroutine_Undelegate(gen) Py_CLEAR((gen)->yieldfrom)
static int __Pyx_PyGen__FetchStopIterationValue(CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject **pvalue) {
    PyObject *et, *ev, *tb;
    PyObject *value = NULL;
    __Pyx_ErrFetch(&et, &ev, &tb);
    if (!et) {
        Py_XDECREF(tb);
        Py_XDECREF(ev);
        Py_INCREF(Py_None);
        *pvalue = Py_None;
        return 0;
    }
    if (likely(et == PyExc_StopIteration)) {
        if (!ev) {
            Py_INCREF(Py_None);
            value = Py_None;
        }
#if PY_VERSION_HEX >= 0x030300A0
        else if (Py_TYPE(ev) == (PyTypeObject*)PyExc_StopIteration) {
            value = ((PyStopIterationObject *)ev)->value;
            Py_INCREF(value);
            Py_DECREF(ev);
        }
#endif
        else if (unlikely(PyTuple_Check(ev))) {
            if (PyTuple_GET_SIZE(ev) >= 1) {
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
                value = PyTuple_GET_ITEM(ev, 0);
                Py_INCREF(value);
#else
                value = PySequence_ITEM(ev, 0);
#endif
            } else {
                Py_INCREF(Py_None);
                value = Py_None;
            }
            Py_DECREF(ev);
        }
        else if (!__Pyx_TypeCheck(ev, (PyTypeObject*)PyExc_StopIteration)) {
            value = ev;
        }
        if (likely(value)) {
            Py_XDECREF(tb);
            Py_DECREF(et);
            *pvalue = value;
            return 0;
        }
    } else if (!__Pyx_PyErr_GivenExceptionMatches(et, PyExc_StopIteration)) {
        __Pyx_ErrRestore(et, ev, tb);
        return -1;
    }
    PyErr_NormalizeException(&et, &ev, &tb);
    if (unlikely(!PyObject_TypeCheck(ev, (PyTypeObject*)PyExc_StopIteration))) {
        __Pyx_ErrRestore(et, ev, tb);
        return -1;
    }
    Py_XDECREF(tb);
    Py_DECREF(et);
#if PY_VERSION_HEX >= 0x030300A0
    value = ((PyStopIterationObject *)ev)->value;
    Py_INCREF(value);
    Py_DECREF(ev);
#else
    {
        PyObject* args = __Pyx_PyObject_GetAttrStr(ev, __pyx_n_s_args);
        Py_DECREF(ev);
        if (likely(args)) {
            value = PySequence_GetItem(args, 0);
            Py_DECREF(args);
        }
        if (unlikely(!value)) {
            __Pyx_ErrRestore(NULL, NULL, NULL);
            Py_INCREF(Py_None);
            value = Py_None;
        }
    }
#endif
    *pvalue = value;
    return 0;
}
static CYTHON_INLINE
void __Pyx_Coroutine_ExceptionClear(__Pyx_ExcInfoStruct *exc_state) {
    PyObject *t, *v, *tb;
    t = exc_state->exc_type;
    v = exc_state->exc_value;
    tb = exc_state->exc_traceback;
    exc_state->exc_type = NULL;
    exc_state->exc_value = NULL;
    exc_state->exc_traceback = NULL;
    Py_XDECREF(t);
    Py_XDECREF(v);
    Py_XDECREF(tb);
}
#define __Pyx_Coroutine_AlreadyRunningError(gen)  (__Pyx__Coroutine_AlreadyRunningError(gen), (PyObject*)NULL)
static void __Pyx__Coroutine_AlreadyRunningError(CYTHON_UNUSED __pyx_CoroutineObject *gen) {
    const char *msg;
    if ((0)) {
    #ifdef __Pyx_Coroutine_USED
    } else if (__Pyx_Coroutine_Check((PyObject*)gen)) {
        msg = "coroutine already executing";
    #endif
    #ifdef __Pyx_AsyncGen_USED
    } else if (__Pyx_AsyncGen_CheckExact((PyObject*)gen)) {
        msg = "async generator already executing";
    #endif
    } else {
        msg = "generator already executing";
    }
    PyErr_SetString(PyExc_ValueError, msg);
}
#define __Pyx_Coroutine_NotStartedError(gen)  (__Pyx__Coroutine_NotStartedError(gen), (PyObject*)NULL)
static void __Pyx__Coroutine_NotStartedError(CYTHON_UNUSED PyObject *gen) {
    const char *msg;
    if ((0)) {
    #ifdef __Pyx_Coroutine_USED
    } else if (__Pyx_Coroutine_Check(gen)) {
        msg = "can't send non-None value to a just-started coroutine";
    #endif
    #ifdef __Pyx_AsyncGen_USED
    } else if (__Pyx_AsyncGen_CheckExact(gen)) {
        msg = "can't send non-None value to a just-started async generator";
    #endif
    } else {
        msg = "can't send non-None value to a just-started generator";
    }
    PyErr_SetString(PyExc_TypeError, msg);
}
#define __Pyx_Coroutine_AlreadyTerminatedError(gen, value, closing)  (__Pyx__Coroutine_AlreadyTerminatedError(gen, value, closing), (PyObject*)NULL)
static void __Pyx__Coroutine_AlreadyTerminatedError(CYTHON_UNUSED PyObject *gen, PyObject *value, CYTHON_UNUSED int closing) {
    #ifdef __Pyx_Coroutine_USED
    if (!closing && __Pyx_Coroutine_Check(gen)) {
        PyErr_SetString(PyExc_RuntimeError, "cannot reuse already awaited coroutine");
    } else
    #endif
    if (value) {
        #ifdef __Pyx_AsyncGen_USED
        if (__Pyx_AsyncGen_CheckExact(gen))
            PyErr_SetNone(__Pyx_PyExc_StopAsyncIteration);
        else
        #endif
        PyErr_SetNone(PyExc_StopIteration);
    }
}
static
PyObject *__Pyx_Coroutine_SendEx(__pyx_CoroutineObject *self, PyObject *value, int closing) {
    __Pyx_PyThreadState_declare
    PyThreadState *tstate;
    __Pyx_ExcInfoStruct *exc_state;
    PyObject *retval;
    assert(!self->is_running);
    if (unlikely(self->resume_label == 0)) {
        if (unlikely(value && value != Py_None)) {
            return __Pyx_Coroutine_NotStartedError((PyObject*)self);
        }
    }
    if (unlikely(self->resume_label == -1)) {
        return __Pyx_Coroutine_AlreadyTerminatedError((PyObject*)self, value, closing);
    }
#if CYTHON_FAST_THREAD_STATE
    __Pyx_PyThreadState_assign
    tstate = __pyx_tstate;
#else
    tstate = __Pyx_PyThreadState_Current;
#endif
    exc_state = &self->gi_exc_state;
    if (exc_state->exc_type) {
        #if CYTHON_COMPILING_IN_PYPY || CYTHON_COMPILING_IN_PYSTON
        #else
        if (exc_state->exc_traceback) {
            PyTracebackObject *tb = (PyTracebackObject *) exc_state->exc_traceback;
            PyFrameObject *f = tb->tb_frame;
            Py_XINCREF(tstate->frame);
            assert(f->f_back == NULL);
            f->f_back = tstate->frame;
        }
        #endif
    }
#if CYTHON_USE_EXC_INFO_STACK
    exc_state->previous_item = tstate->exc_info;
    tstate->exc_info = exc_state;
#else
    if (exc_state->exc_type) {
        __Pyx_ExceptionSwap(&exc_state->exc_type, &exc_state->exc_value, &exc_state->exc_traceback);
    } else {
        __Pyx_Coroutine_ExceptionClear(exc_state);
        __Pyx_ExceptionSave(&exc_state->exc_type, &exc_state->exc_value, &exc_state->exc_traceback);
    }
#endif
    self->is_running = 1;
    retval = self->body((PyObject *) self, tstate, value);
    self->is_running = 0;
#if CYTHON_USE_EXC_INFO_STACK
    exc_state = &self->gi_exc_state;
    tstate->exc_info = exc_state->previous_item;
    exc_state->previous_item = NULL;
    __Pyx_Coroutine_ResetFrameBackpointer(exc_state);
#endif
    return retval;
}
static CYTHON_INLINE void __Pyx_Coroutine_ResetFrameBackpointer(__Pyx_ExcInfoStruct *exc_state) {
    PyObject *exc_tb = exc_state->exc_traceback;
    if (likely(exc_tb)) {
#if CYTHON_COMPILING_IN_PYPY || CYTHON_COMPILING_IN_PYSTON
#else
        PyTracebackObject *tb = (PyTracebackObject *) exc_tb;
        PyFrameObject *f = tb->tb_frame;
        Py_CLEAR(f->f_back);
#endif
    }
}
static CYTHON_INLINE
PyObject *__Pyx_Coroutine_MethodReturn(CYTHON_UNUSED PyObject* gen, PyObject *retval) {
    if (unlikely(!retval)) {
        __Pyx_PyThreadState_declare
        __Pyx_PyThreadState_assign
        if (!__Pyx_PyErr_Occurred()) {
            PyObject *exc = PyExc_StopIteration;
            #ifdef __Pyx_AsyncGen_USED
            if (__Pyx_AsyncGen_CheckExact(gen))
                exc = __Pyx_PyExc_StopAsyncIteration;
            #endif
            __Pyx_PyErr_SetNone(exc);
        }
    }
    return retval;
}
static CYTHON_INLINE
PyObject *__Pyx_Coroutine_FinishDelegation(__pyx_CoroutineObject *gen) {
    PyObject *ret;
    PyObject *val = NULL;
    __Pyx_Coroutine_Undelegate(gen);
    __Pyx_PyGen__FetchStopIterationValue(__Pyx_PyThreadState_Current, &val);
    ret = __Pyx_Coroutine_SendEx(gen, val, 0);
    Py_XDECREF(val);
    return ret;
}
static PyObject *__Pyx_Coroutine_Send(PyObject *self, PyObject *value) {
    PyObject *retval;
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject*) self;
    PyObject *yf = gen->yieldfrom;
    if (unlikely(gen->is_running))
        return __Pyx_Coroutine_AlreadyRunningError(gen);
    if (yf) {
        PyObject *ret;
        gen->is_running = 1;
        #ifdef __Pyx_Generator_USED
        if (__Pyx_Generator_CheckExact(yf)) {
            ret = __Pyx_Coroutine_Send(yf, value);
        } else
        #endif
        #ifdef __Pyx_Coroutine_USED
        if (__Pyx_Coroutine_Check(yf)) {
            ret = __Pyx_Coroutine_Send(yf, value);
        } else
        #endif
        #ifdef __Pyx_AsyncGen_USED
        if (__pyx_PyAsyncGenASend_CheckExact(yf)) {
            ret = __Pyx_async_gen_asend_send(yf, value);
        } else
        #endif
        #if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x03030000 && (defined(__linux__) || PY_VERSION_HEX >= 0x030600B3)
        if (PyGen_CheckExact(yf)) {
            ret = _PyGen_Send((PyGenObject*)yf, value == Py_None ? NULL : value);
        } else
        #endif
        #if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x03050000 && defined(PyCoro_CheckExact) && (defined(__linux__) || PY_VERSION_HEX >= 0x030600B3)
        if (PyCoro_CheckExact(yf)) {
            ret = _PyGen_Send((PyGenObject*)yf, value == Py_None ? NULL : value);
        } else
        #endif
        {
            if (value == Py_None)
                ret = Py_TYPE(yf)->tp_iternext(yf);
            else
                ret = __Pyx_PyObject_CallMethod1(yf, __pyx_n_s_send, value);
        }
        gen->is_running = 0;
        if (likely(ret)) {
            return ret;
        }
        retval = __Pyx_Coroutine_FinishDelegation(gen);
    } else {
        retval = __Pyx_Coroutine_SendEx(gen, value, 0);
    }
    return __Pyx_Coroutine_MethodReturn(self, retval);
}
static int __Pyx_Coroutine_CloseIter(__pyx_CoroutineObject *gen, PyObject *yf) {
    PyObject *retval = NULL;
    int err = 0;
    #ifdef __Pyx_Generator_USED
    if (__Pyx_Generator_CheckExact(yf)) {
        retval = __Pyx_Coroutine_Close(yf);
        if (!retval)
            return -1;
    } else
    #endif
    #ifdef __Pyx_Coroutine_USED
    if (__Pyx_Coroutine_Check(yf)) {
        retval = __Pyx_Coroutine_Close(yf);
        if (!retval)
            return -1;
    } else
    if (__Pyx_CoroutineAwait_CheckExact(yf)) {
        retval = __Pyx_CoroutineAwait_Close((__pyx_CoroutineAwaitObject*)yf, NULL);
        if (!retval)
            return -1;
    } else
    #endif
    #ifdef __Pyx_AsyncGen_USED
    if (__pyx_PyAsyncGenASend_CheckExact(yf)) {
        retval = __Pyx_async_gen_asend_close(yf, NULL);
    } else
    if (__pyx_PyAsyncGenAThrow_CheckExact(yf)) {
        retval = __Pyx_async_gen_athrow_close(yf, NULL);
    } else
    #endif
    {
        PyObject *meth;
        gen->is_running = 1;
        meth = __Pyx_PyObject_GetAttrStr(yf, __pyx_n_s_close);
        if (unlikely(!meth)) {
            if (!PyErr_ExceptionMatches(PyExc_AttributeError)) {
                PyErr_WriteUnraisable(yf);
            }
            PyErr_Clear();
        } else {
            retval = PyObject_CallFunction(meth, NULL);
            Py_DECREF(meth);
            if (!retval)
                err = -1;
        }
        gen->is_running = 0;
    }
    Py_XDECREF(retval);
    return err;
}
static PyObject *__Pyx_Generator_Next(PyObject *self) {
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject*) self;
    PyObject *yf = gen->yieldfrom;
    if (unlikely(gen->is_running))
        return __Pyx_Coroutine_AlreadyRunningError(gen);
    if (yf) {
        PyObject *ret;
        gen->is_running = 1;
        #ifdef __Pyx_Generator_USED
        if (__Pyx_Generator_CheckExact(yf)) {
            ret = __Pyx_Generator_Next(yf);
        } else
        #endif
        #if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x03030000 && (defined(__linux__) || PY_VERSION_HEX >= 0x030600B3)
        if (PyGen_CheckExact(yf)) {
            ret = _PyGen_Send((PyGenObject*)yf, NULL);
        } else
        #endif
        #ifdef __Pyx_Coroutine_USED
        if (__Pyx_Coroutine_Check(yf)) {
            ret = __Pyx_Coroutine_Send(yf, Py_None);
        } else
        #endif
            ret = Py_TYPE(yf)->tp_iternext(yf);
        gen->is_running = 0;
        if (likely(ret)) {
            return ret;
        }
        return __Pyx_Coroutine_FinishDelegation(gen);
    }
    return __Pyx_Coroutine_SendEx(gen, Py_None, 0);
}
static PyObject *__Pyx_Coroutine_Close_Method(PyObject *self, CYTHON_UNUSED PyObject *arg) {
    return __Pyx_Coroutine_Close(self);
}
static PyObject *__Pyx_Coroutine_Close(PyObject *self) {
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject *) self;
    PyObject *retval, *raised_exception;
    PyObject *yf = gen->yieldfrom;
    int err = 0;
    if (unlikely(gen->is_running))
        return __Pyx_Coroutine_AlreadyRunningError(gen);
    if (yf) {
        Py_INCREF(yf);
        err = __Pyx_Coroutine_CloseIter(gen, yf);
        __Pyx_Coroutine_Undelegate(gen);
        Py_DECREF(yf);
    }
    if (err == 0)
        PyErr_SetNone(PyExc_GeneratorExit);
    retval = __Pyx_Coroutine_SendEx(gen, NULL, 1);
    if (unlikely(retval)) {
        const char *msg;
        Py_DECREF(retval);
        if ((0)) {
        #ifdef __Pyx_Coroutine_USED
        } else if (__Pyx_Coroutine_Check(self)) {
            msg = "coroutine ignored GeneratorExit";
        #endif
        #ifdef __Pyx_AsyncGen_USED
        } else if (__Pyx_AsyncGen_CheckExact(self)) {
#if PY_VERSION_HEX < 0x03060000
            msg = "async generator ignored GeneratorExit - might require Python 3.6+ finalisation (PEP 525)";
#else
            msg = "async generator ignored GeneratorExit";
#endif
        #endif
        } else {
            msg = "generator ignored GeneratorExit";
        }
        PyErr_SetString(PyExc_RuntimeError, msg);
        return NULL;
    }
    raised_exception = PyErr_Occurred();
    if (likely(!raised_exception || __Pyx_PyErr_GivenExceptionMatches2(raised_exception, PyExc_GeneratorExit, PyExc_StopIteration))) {
        if (raised_exception) PyErr_Clear();
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
}
static PyObject *__Pyx__Coroutine_Throw(PyObject *self, PyObject *typ, PyObject *val, PyObject *tb,
                                        PyObject *args, int close_on_genexit) {
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject *) self;
    PyObject *yf = gen->yieldfrom;
    if (unlikely(gen->is_running))
        return __Pyx_Coroutine_AlreadyRunningError(gen);
    if (yf) {
        PyObject *ret;
        Py_INCREF(yf);
        if (__Pyx_PyErr_GivenExceptionMatches(typ, PyExc_GeneratorExit) && close_on_genexit) {
            int err = __Pyx_Coroutine_CloseIter(gen, yf);
            Py_DECREF(yf);
            __Pyx_Coroutine_Undelegate(gen);
            if (err < 0)
                return __Pyx_Coroutine_MethodReturn(self, __Pyx_Coroutine_SendEx(gen, NULL, 0));
            goto throw_here;
        }
        gen->is_running = 1;
        if (0
        #ifdef __Pyx_Generator_USED
            || __Pyx_Generator_CheckExact(yf)
        #endif
        #ifdef __Pyx_Coroutine_USED
            || __Pyx_Coroutine_Check(yf)
        #endif
            ) {
            ret = __Pyx__Coroutine_Throw(yf, typ, val, tb, args, close_on_genexit);
        #ifdef __Pyx_Coroutine_USED
        } else if (__Pyx_CoroutineAwait_CheckExact(yf)) {
            ret = __Pyx__Coroutine_Throw(((__pyx_CoroutineAwaitObject*)yf)->coroutine, typ, val, tb, args, close_on_genexit);
        #endif
        } else {
            PyObject *meth = __Pyx_PyObject_GetAttrStr(yf, __pyx_n_s_throw);
            if (unlikely(!meth)) {
                Py_DECREF(yf);
                if (!PyErr_ExceptionMatches(PyExc_AttributeError)) {
                    gen->is_running = 0;
                    return NULL;
                }
                PyErr_Clear();
                __Pyx_Coroutine_Undelegate(gen);
                gen->is_running = 0;
                goto throw_here;
            }
            if (likely(args)) {
                ret = PyObject_CallObject(meth, args);
            } else {
                ret = PyObject_CallFunctionObjArgs(meth, typ, val, tb, NULL);
            }
            Py_DECREF(meth);
        }
        gen->is_running = 0;
        Py_DECREF(yf);
        if (!ret) {
            ret = __Pyx_Coroutine_FinishDelegation(gen);
        }
        return __Pyx_Coroutine_MethodReturn(self, ret);
    }
throw_here:
    __Pyx_Raise(typ, val, tb, NULL);
    return __Pyx_Coroutine_MethodReturn(self, __Pyx_Coroutine_SendEx(gen, NULL, 0));
}
static PyObject *__Pyx_Coroutine_Throw(PyObject *self, PyObject *args) {
    PyObject *typ;
    PyObject *val = NULL;
    PyObject *tb = NULL;
    if (!PyArg_UnpackTuple(args, (char *)"throw", 1, 3, &typ, &val, &tb))
        return NULL;
    return __Pyx__Coroutine_Throw(self, typ, val, tb, args, 1);
}
static CYTHON_INLINE int __Pyx_Coroutine_traverse_excstate(__Pyx_ExcInfoStruct *exc_state, visitproc visit, void *arg) {
    Py_VISIT(exc_state->exc_type);
    Py_VISIT(exc_state->exc_value);
    Py_VISIT(exc_state->exc_traceback);
    return 0;
}
static int __Pyx_Coroutine_traverse(__pyx_CoroutineObject *gen, visitproc visit, void *arg) {
    Py_VISIT(gen->closure);
    Py_VISIT(gen->classobj);
    Py_VISIT(gen->yieldfrom);
    return __Pyx_Coroutine_traverse_excstate(&gen->gi_exc_state, visit, arg);
}
static int __Pyx_Coroutine_clear(PyObject *self) {
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject *) self;
    Py_CLEAR(gen->closure);
    Py_CLEAR(gen->classobj);
    Py_CLEAR(gen->yieldfrom);
    __Pyx_Coroutine_ExceptionClear(&gen->gi_exc_state);
#ifdef __Pyx_AsyncGen_USED
    if (__Pyx_AsyncGen_CheckExact(self)) {
        Py_CLEAR(((__pyx_PyAsyncGenObject*)gen)->ag_finalizer);
    }
#endif
    Py_CLEAR(gen->gi_code);
    Py_CLEAR(gen->gi_name);
    Py_CLEAR(gen->gi_qualname);
    Py_CLEAR(gen->gi_modulename);
    return 0;
}
static void __Pyx_Coroutine_dealloc(PyObject *self) {
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject *) self;
    PyObject_GC_UnTrack(gen);
    if (gen->gi_weakreflist != NULL)
        PyObject_ClearWeakRefs(self);
    if (gen->resume_label >= 0) {
        PyObject_GC_Track(self);
#if PY_VERSION_HEX >= 0x030400a1 && CYTHON_USE_TP_FINALIZE
        if (PyObject_CallFinalizerFromDealloc(self))
#else
        Py_TYPE(gen)->tp_del(self);
        if (self->ob_refcnt > 0)
#endif
        {
            return;
        }
        PyObject_GC_UnTrack(self);
    }
#ifdef __Pyx_AsyncGen_USED
    if (__Pyx_AsyncGen_CheckExact(self)) {
        /* We have to handle this case for asynchronous generators
           right here, because this code has to be between UNTRACK
           and GC_Del. */
        Py_CLEAR(((__pyx_PyAsyncGenObject*)self)->ag_finalizer);
    }
#endif
    __Pyx_Coroutine_clear(self);
    PyObject_GC_Del(gen);
}
static void __Pyx_Coroutine_del(PyObject *self) {
    PyObject *error_type, *error_value, *error_traceback;
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject *) self;
    __Pyx_PyThreadState_declare
    if (gen->resume_label < 0) {
        return;
    }
#if !CYTHON_USE_TP_FINALIZE
    assert(self->ob_refcnt == 0);
    self->ob_refcnt = 1;
#endif
    __Pyx_PyThreadState_assign
    __Pyx_ErrFetch(&error_type, &error_value, &error_traceback);
#ifdef __Pyx_AsyncGen_USED
    if (__Pyx_AsyncGen_CheckExact(self)) {
        __pyx_PyAsyncGenObject *agen = (__pyx_PyAsyncGenObject*)self;
        PyObject *finalizer = agen->ag_finalizer;
        if (finalizer && !agen->ag_closed) {
            PyObject *res = __Pyx_PyObject_CallOneArg(finalizer, self);
            if (unlikely(!res)) {
                PyErr_WriteUnraisable(self);
            } else {
                Py_DECREF(res);
            }
            __Pyx_ErrRestore(error_type, error_value, error_traceback);
            return;
        }
    }
#endif
    if (unlikely(gen->resume_label == 0 && !error_value)) {
#ifdef __Pyx_Coroutine_USED
#ifdef __Pyx_Generator_USED
    if (!__Pyx_Generator_CheckExact(self))
#endif
        {
        PyObject_GC_UnTrack(self);
#if PY_MAJOR_VERSION >= 3  || defined(PyErr_WarnFormat)
        if (unlikely(PyErr_WarnFormat(PyExc_RuntimeWarning, 1, "coroutine '%.50S' was never awaited", gen->gi_qualname) < 0))
            PyErr_WriteUnraisable(self);
#else
        {PyObject *msg;
        char *cmsg;
        #if CYTHON_COMPILING_IN_PYPY
        msg = NULL;
        cmsg = (char*) "coroutine was never awaited";
        #else
        char *cname;
        PyObject *qualname;
        qualname = gen->gi_qualname;
        cname = PyString_AS_STRING(qualname);
        msg = PyString_FromFormat("coroutine '%.50s' was never awaited", cname);
        if (unlikely(!msg)) {
            PyErr_Clear();
            cmsg = (char*) "coroutine was never awaited";
        } else {
            cmsg = PyString_AS_STRING(msg);
        }
        #endif
        if (unlikely(PyErr_WarnEx(PyExc_RuntimeWarning, cmsg, 1) < 0))
            PyErr_WriteUnraisable(self);
        Py_XDECREF(msg);}
#endif
        PyObject_GC_Track(self);
        }
#endif
    } else {
        PyObject *res = __Pyx_Coroutine_Close(self);
        if (unlikely(!res)) {
            if (PyErr_Occurred())
                PyErr_WriteUnraisable(self);
        } else {
            Py_DECREF(res);
        }
    }
    __Pyx_ErrRestore(error_type, error_value, error_traceback);
#if !CYTHON_USE_TP_FINALIZE
    assert(self->ob_refcnt > 0);
    if (--self->ob_refcnt == 0) {
        return;
    }
    {
        Py_ssize_t refcnt = self->ob_refcnt;
        _Py_NewReference(self);
        self->ob_refcnt = refcnt;
    }
#if CYTHON_COMPILING_IN_CPYTHON
    assert(PyType_IS_GC(self->ob_type) &&
           _Py_AS_GC(self)->gc.gc_refs != _PyGC_REFS_UNTRACKED);
    _Py_DEC_REFTOTAL;
#endif
#ifdef COUNT_ALLOCS
    --Py_TYPE(self)->tp_frees;
    --Py_TYPE(self)->tp_allocs;
#endif
#endif
}
static PyObject *
__Pyx_Coroutine_get_name(__pyx_CoroutineObject *self, CYTHON_UNUSED void *context)
{
    PyObject *name = self->gi_name;
    if (unlikely(!name)) name = Py_None;
    Py_INCREF(name);
    return name;
}
static int
__Pyx_Coroutine_set_name(__pyx_CoroutineObject *self, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp;
#if PY_MAJOR_VERSION >= 3
    if (unlikely(value == NULL || !PyUnicode_Check(value)))
#else
    if (unlikely(value == NULL || !PyString_Check(value)))
#endif
    {
        PyErr_SetString(PyExc_TypeError,
                        "__name__ must be set to a string object");
        return -1;
    }
    tmp = self->gi_name;
    Py_INCREF(value);
    self->gi_name = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_Coroutine_get_qualname(__pyx_CoroutineObject *self, CYTHON_UNUSED void *context)
{
    PyObject *name = self->gi_qualname;
    if (unlikely(!name)) name = Py_None;
    Py_INCREF(name);
    return name;
}
static int
__Pyx_Coroutine_set_qualname(__pyx_CoroutineObject *self, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp;
#if PY_MAJOR_VERSION >= 3
    if (unlikely(value == NULL || !PyUnicode_Check(value)))
#else
    if (unlikely(value == NULL || !PyString_Check(value)))
#endif
    {
        PyErr_SetString(PyExc_TypeError,
                        "__qualname__ must be set to a string object");
        return -1;
    }
    tmp = self->gi_qualname;
    Py_INCREF(value);
    self->gi_qualname = value;
    Py_XDECREF(tmp);
    return 0;
}
static __pyx_CoroutineObject *__Pyx__Coroutine_New(
            PyTypeObject* type, __pyx_coroutine_body_t body, PyObject *code, PyObject *closure,
            PyObject *name, PyObject *qualname, PyObject *module_name) {
    __pyx_CoroutineObject *gen = PyObject_GC_New(__pyx_CoroutineObject, type);
    if (unlikely(!gen))
        return NULL;
    return __Pyx__Coroutine_NewInit(gen, body, code, closure, name, qualname, module_name);
}
static __pyx_CoroutineObject *__Pyx__Coroutine_NewInit(
            __pyx_CoroutineObject *gen, __pyx_coroutine_body_t body, PyObject *code, PyObject *closure,
            PyObject *name, PyObject *qualname, PyObject *module_name) {
    gen->body = body;
    gen->closure = closure;
    Py_XINCREF(closure);
    gen->is_running = 0;
    gen->resume_label = 0;
    gen->classobj = NULL;
    gen->yieldfrom = NULL;
    gen->gi_exc_state.exc_type = NULL;
    gen->gi_exc_state.exc_value = NULL;
    gen->gi_exc_state.exc_traceback = NULL;
#if CYTHON_USE_EXC_INFO_STACK
    gen->gi_exc_state.previous_item = NULL;
#endif
    gen->gi_weakreflist = NULL;
    Py_XINCREF(qualname);
    gen->gi_qualname = qualname;
    Py_XINCREF(name);
    gen->gi_name = name;
    Py_XINCREF(module_name);
    gen->gi_modulename = module_name;
    Py_XINCREF(code);
    gen->gi_code = code;
    PyObject_GC_Track(gen);
    return gen;
}

/* PatchModuleWithCoroutine */
static PyObject* __Pyx_Coroutine_patch_module(PyObject* module, const char* py_code) {
#if defined(__Pyx_Generator_USED) || defined(__Pyx_Coroutine_USED)
    int result;
    PyObject *globals, *result_obj;
    globals = PyDict_New();  if (unlikely(!globals)) goto ignore;
    result = PyDict_SetItemString(globals, "_cython_coroutine_type",
    #ifdef __Pyx_Coroutine_USED
        (PyObject*)__pyx_CoroutineType);
    #else
        Py_None);
    #endif
    if (unlikely(result < 0)) goto ignore;
    result = PyDict_SetItemString(globals, "_cython_generator_type",
    #ifdef __Pyx_Generator_USED
        (PyObject*)__pyx_GeneratorType);
    #else
        Py_None);
    #endif
    if (unlikely(result < 0)) goto ignore;
    if (unlikely(PyDict_SetItemString(globals, "_module", module) < 0)) goto ignore;
    if (unlikely(PyDict_SetItemString(globals, "__builtins__", __pyx_b) < 0)) goto ignore;
    result_obj = PyRun_String(py_code, Py_file_input, globals, globals);
    if (unlikely(!result_obj)) goto ignore;
    Py_DECREF(result_obj);
    Py_DECREF(globals);
    return module;
ignore:
    Py_XDECREF(globals);
    PyErr_WriteUnraisable(module);
    if (unlikely(PyErr_WarnEx(PyExc_RuntimeWarning, "Cython module failed to patch module with custom type", 1) < 0)) {
        Py_DECREF(module);
        module = NULL;
    }
#else
    py_code++;
#endif
    return module;
}

/* PatchGeneratorABC */
#ifndef CYTHON_REGISTER_ABCS
#define CYTHON_REGISTER_ABCS 1
#endif
#if defined(__Pyx_Generator_USED) || defined(__Pyx_Coroutine_USED)
static PyObject* __Pyx_patch_abc_module(PyObject *module);
static PyObject* __Pyx_patch_abc_module(PyObject *module) {
    module = __Pyx_Coroutine_patch_module(
        module, ""
"if _cython_generator_type is not None:\n"
"    try: Generator = _module.Generator\n"
"    except AttributeError: pass\n"
"    else: Generator.register(_cython_generator_type)\n"
"if _cython_coroutine_type is not None:\n"
"    try: Coroutine = _module.Coroutine\n"
"    except AttributeError: pass\n"
"    else: Coroutine.register(_cython_coroutine_type)\n"
    );
    return module;
}
#endif
static int __Pyx_patch_abc(void) {
#if defined(__Pyx_Generator_USED) || defined(__Pyx_Coroutine_USED)
    static int abc_patched = 0;
    if (CYTHON_REGISTER_ABCS && !abc_patched) {
        PyObject *module;
        module = PyImport_ImportModule((PY_MAJOR_VERSION >= 3) ? "collections.abc" : "collections");
        if (!module) {
            PyErr_WriteUnraisable(NULL);
            if (unlikely(PyErr_WarnEx(PyExc_RuntimeWarning,
                    ((PY_MAJOR_VERSION >= 3) ?
                        "Cython module failed to register with collections.abc module" :
                        "Cython module failed to register with collections module"), 1) < 0)) {
                return -1;
            }
        } else {
            module = __Pyx_patch_abc_module(module);
            abc_patched = 1;
            if (unlikely(!module))
                return -1;
            Py_DECREF(module);
        }
        module = PyImport_ImportModule("backports_abc");
        if (module) {
            module = __Pyx_patch_abc_module(module);
            Py_XDECREF(module);
        }
        if (!module) {
            PyErr_Clear();
        }
    }
#else
    if ((0)) __Pyx_Coroutine_patch_module(NULL, NULL);
#endif
    return 0;
}

/* Generator */
static PyMethodDef __pyx_Generator_methods[] = {
    {"send", (PyCFunction) __Pyx_Coroutine_Send, METH_O,
     (char*) PyDoc_STR("send(arg) -> send 'arg' into generator,\nreturn next yielded value or raise StopIteration.")},
    {"throw", (PyCFunction) __Pyx_Coroutine_Throw, METH_VARARGS,
     (char*) PyDoc_STR("throw(typ[,val[,tb]]) -> raise exception in generator,\nreturn next yielded value or raise StopIteration.")},
    {"close", (PyCFunction) __Pyx_Coroutine_Close_Method, METH_NOARGS,
     (char*) PyDoc_STR("close() -> raise GeneratorExit inside generator.")},
    {0, 0, 0, 0}
};
static PyMemberDef __pyx_Generator_memberlist[] = {
    {(char *) "gi_running", T_BOOL, offsetof(__pyx_CoroutineObject, is_running), READONLY, NULL},
    {(char*) "gi_yieldfrom", T_OBJECT, offsetof(__pyx_CoroutineObject, yieldfrom), READONLY,
     (char*) PyDoc_STR("object being iterated by 'yield from', or None")},
    {(char*) "gi_code", T_OBJECT, offsetof(__pyx_CoroutineObject, gi_code), READONLY, NULL},
    {0, 0, 0, 0, 0}
};
static PyGetSetDef __pyx_Generator_getsets[] = {
    {(char *) "__name__", (getter)__Pyx_Coroutine_get_name, (setter)__Pyx_Coroutine_set_name,
     (char*) PyDoc_STR("name of the generator"), 0},
    {(char *) "__qualname__", (getter)__Pyx_Coroutine_get_qualname, (setter)__Pyx_Coroutine_set_qualname,
     (char*) PyDoc_STR("qualified name of the generator"), 0},
    {0, 0, 0, 0, 0}
};
static PyTypeObject __pyx_GeneratorType_type = {
    PyVarObject_HEAD_INIT(0, 0)
    "generator",
    sizeof(__pyx_CoroutineObject),
    0,
    (destructor) __Pyx_Coroutine_dealloc,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HAVE_GC | Py_TPFLAGS_HAVE_FINALIZE,
    0,
    (traverseproc) __Pyx_Coroutine_traverse,
    0,
    0,
    offsetof(__pyx_CoroutineObject, gi_weakreflist),
    0,
    (iternextfunc) __Pyx_Generator_Next,
    __pyx_Generator_methods,
    __pyx_Generator_memberlist,
    __pyx_Generator_getsets,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
#if CYTHON_USE_TP_FINALIZE
    0,
#else
    __Pyx_Coroutine_del,
#endif
    0,
#if CYTHON_USE_TP_FINALIZE
    __Pyx_Coroutine_del,
#elif PY_VERSION_HEX >= 0x030400a1
    0,
#endif
#if PY_VERSION_HEX >= 0x030800b1
    0,
#endif
#if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
    0,
#endif
};
static int __pyx_Generator_init(void) {
    __pyx_GeneratorType_type.tp_getattro = __Pyx_PyObject_GenericGetAttrNoDict;
    __pyx_GeneratorType_type.tp_iter = PyObject_SelfIter;
    __pyx_GeneratorType = __Pyx_FetchCommonType(&__pyx_GeneratorType_type);
    if (unlikely(!__pyx_GeneratorType)) {
        return -1;
    }
    return 0;
}

/* CheckBinaryVersion */
static int __Pyx_check_binary_version(void) {
    char ctversion[4], rtversion[4];
    PyOS_snprintf(ctversion, 4, "%d.%d", PY_MAJOR_VERSION, PY_MINOR_VERSION);
    PyOS_snprintf(rtversion, 4, "%s", Py_GetVersion());
    if (ctversion[0] != rtversion[0] || ctversion[2] != rtversion[2]) {
        char message[200];
        PyOS_snprintf(message, sizeof(message),
                      "compiletime version %s of module '%.100s' "
                      "does not match runtime version %s",
                      ctversion, __Pyx_MODULE_NAME, rtversion);
        return PyErr_WarnEx(NULL, message, 1);
    }
    return 0;
}

/* InitStrings */
static int __Pyx_InitStrings(__Pyx_StringTabEntry *t) {
    while (t->p) {
        #if PY_MAJOR_VERSION < 3
        if (t->is_unicode) {
            *t->p = PyUnicode_DecodeUTF8(t->s, t->n - 1, NULL);
        } else if (t->intern) {
            *t->p = PyString_InternFromString(t->s);
        } else {
            *t->p = PyString_FromStringAndSize(t->s, t->n - 1);
        }
        #else
        if (t->is_unicode | t->is_str) {
            if (t->intern) {
                *t->p = PyUnicode_InternFromString(t->s);
            } else if (t->encoding) {
                *t->p = PyUnicode_Decode(t->s, t->n - 1, t->encoding, NULL);
            } else {
                *t->p = PyUnicode_FromStringAndSize(t->s, t->n - 1);
            }
        } else {
            *t->p = PyBytes_FromStringAndSize(t->s, t->n - 1);
        }
        #endif
        if (!*t->p)
            return -1;
        if (PyObject_Hash(*t->p) == -1)
            return -1;
        ++t;
    }
    return 0;
}

static CYTHON_INLINE PyObject* __Pyx_PyUnicode_FromString(const char* c_str) {
    return __Pyx_PyUnicode_FromStringAndSize(c_str, (Py_ssize_t)strlen(c_str));
}
static CYTHON_INLINE const char* __Pyx_PyObject_AsString(PyObject* o) {
    Py_ssize_t ignore;
    return __Pyx_PyObject_AsStringAndSize(o, &ignore);
}
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII || __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT
#if !CYTHON_PEP393_ENABLED
static const char* __Pyx_PyUnicode_AsStringAndSize(PyObject* o, Py_ssize_t *length) {
    char* defenc_c;
    PyObject* defenc = _PyUnicode_AsDefaultEncodedString(o, NULL);
    if (!defenc) return NULL;
    defenc_c = PyBytes_AS_STRING(defenc);
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
    {
        char* end = defenc_c + PyBytes_GET_SIZE(defenc);
        char* c;
        for (c = defenc_c; c < end; c++) {
            if ((unsigned char) (*c) >= 128) {
                PyUnicode_AsASCIIString(o);
                return NULL;
            }
        }
    }
#endif
    *length = PyBytes_GET_SIZE(defenc);
    return defenc_c;
}
#else
static CYTHON_INLINE const char* __Pyx_PyUnicode_AsStringAndSize(PyObject* o, Py_ssize_t *length) {
    if (unlikely(__Pyx_PyUnicode_READY(o) == -1)) return NULL;
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
    if (likely(PyUnicode_IS_ASCII(o))) {
        *length = PyUnicode_GET_LENGTH(o);
        return PyUnicode_AsUTF8(o);
    } else {
        PyUnicode_AsASCIIString(o);
        return NULL;
    }
#else
    return PyUnicode_AsUTF8AndSize(o, length);
#endif
}
#endif
#endif
static CYTHON_INLINE const char* __Pyx_PyObject_AsStringAndSize(PyObject* o, Py_ssize_t *length) {
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII || __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT
    if (
#if PY_MAJOR_VERSION < 3 && __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
            __Pyx_sys_getdefaultencoding_not_ascii &&
#endif
            PyUnicode_Check(o)) {
        return __Pyx_PyUnicode_AsStringAndSize(o, length);
    } else
#endif
#if (!CYTHON_COMPILING_IN_PYPY) || (defined(PyByteArray_AS_STRING) && defined(PyByteArray_GET_SIZE))
    if (PyByteArray_Check(o)) {
        *length = PyByteArray_GET_SIZE(o);
        return PyByteArray_AS_STRING(o);
    } else
#endif
    {
        char* result;
        int r = PyBytes_AsStringAndSize(o, &result, length);
        if (unlikely(r < 0)) {
            return NULL;
        } else {
            return result;
        }
    }
}
static CYTHON_INLINE int __Pyx_PyObject_IsTrue(PyObject* x) {
   int is_true = x == Py_True;
   if (is_true | (x == Py_False) | (x == Py_None)) return is_true;
   else return PyObject_IsTrue(x);
}
static CYTHON_INLINE int __Pyx_PyObject_IsTrueAndDecref(PyObject* x) {
    int retval;
    if (unlikely(!x)) return -1;
    retval = __Pyx_PyObject_IsTrue(x);
    Py_DECREF(x);
    return retval;
}
static PyObject* __Pyx_PyNumber_IntOrLongWrongResultType(PyObject* result, const char* type_name) {
#if PY_MAJOR_VERSION >= 3
    if (PyLong_Check(result)) {
        if (PyErr_WarnFormat(PyExc_DeprecationWarning, 1,
                "__int__ returned non-int (type %.200s).  "
                "The ability to return an instance of a strict subclass of int "
                "is deprecated, and may be removed in a future version of Python.",
                Py_TYPE(result)->tp_name)) {
            Py_DECREF(result);
            return NULL;
        }
        return result;
    }
#endif
    PyErr_Format(PyExc_TypeError,
                 "__%.4s__ returned non-%.4s (type %.200s)",
                 type_name, type_name, Py_TYPE(result)->tp_name);
    Py_DECREF(result);
    return NULL;
}
static CYTHON_INLINE PyObject* __Pyx_PyNumber_IntOrLong(PyObject* x) {
#if CYTHON_USE_TYPE_SLOTS
  PyNumberMethods *m;
#endif
  const char *name = NULL;
  PyObject *res = NULL;
#if PY_MAJOR_VERSION < 3
  if (likely(PyInt_Check(x) || PyLong_Check(x)))
#else
  if (likely(PyLong_Check(x)))
#endif
    return __Pyx_NewRef(x);
#if CYTHON_USE_TYPE_SLOTS
  m = Py_TYPE(x)->tp_as_number;
  #if PY_MAJOR_VERSION < 3
  if (m && m->nb_int) {
    name = "int";
    res = m->nb_int(x);
  }
  else if (m && m->nb_long) {
    name = "long";
    res = m->nb_long(x);
  }
  #else
  if (likely(m && m->nb_int)) {
    name = "int";
    res = m->nb_int(x);
  }
  #endif
#else
  if (!PyBytes_CheckExact(x) && !PyUnicode_CheckExact(x)) {
    res = PyNumber_Int(x);
  }
#endif
  if (likely(res)) {
#if PY_MAJOR_VERSION < 3
    if (unlikely(!PyInt_Check(res) && !PyLong_Check(res))) {
#else
    if (unlikely(!PyLong_CheckExact(res))) {
#endif
        return __Pyx_PyNumber_IntOrLongWrongResultType(res, name);
    }
  }
  else if (!PyErr_Occurred()) {
    PyErr_SetString(PyExc_TypeError,
                    "an integer is required");
  }
  return res;
}
static CYTHON_INLINE Py_ssize_t __Pyx_PyIndex_AsSsize_t(PyObject* b) {
  Py_ssize_t ival;
  PyObject *x;
#if PY_MAJOR_VERSION < 3
  if (likely(PyInt_CheckExact(b))) {
    if (sizeof(Py_ssize_t) >= sizeof(long))
        return PyInt_AS_LONG(b);
    else
        return PyInt_AsSsize_t(b);
  }
#endif
  if (likely(PyLong_CheckExact(b))) {
    #if CYTHON_USE_PYLONG_INTERNALS
    const digit* digits = ((PyLongObject*)b)->ob_digit;
    const Py_ssize_t size = Py_SIZE(b);
    if (likely(__Pyx_sst_abs(size) <= 1)) {
        ival = likely(size) ? digits[0] : 0;
        if (size == -1) ival = -ival;
        return ival;
    } else {
      switch (size) {
         case 2:
           if (8 * sizeof(Py_ssize_t) > 2 * PyLong_SHIFT) {
             return (Py_ssize_t) (((((size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case -2:
           if (8 * sizeof(Py_ssize_t) > 2 * PyLong_SHIFT) {
             return -(Py_ssize_t) (((((size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case 3:
           if (8 * sizeof(Py_ssize_t) > 3 * PyLong_SHIFT) {
             return (Py_ssize_t) (((((((size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case -3:
           if (8 * sizeof(Py_ssize_t) > 3 * PyLong_SHIFT) {
             return -(Py_ssize_t) (((((((size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case 4:
           if (8 * sizeof(Py_ssize_t) > 4 * PyLong_SHIFT) {
             return (Py_ssize_t) (((((((((size_t)digits[3]) << PyLong_SHIFT) | (size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case -4:
           if (8 * sizeof(Py_ssize_t) > 4 * PyLong_SHIFT) {
             return -(Py_ssize_t) (((((((((size_t)digits[3]) << PyLong_SHIFT) | (size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
      }
    }
    #endif
    return PyLong_AsSsize_t(b);
  }
  x = PyNumber_Index(b);
  if (!x) return -1;
  ival = PyInt_AsSsize_t(x);
  Py_DECREF(x);
  return ival;
}
static CYTHON_INLINE PyObject * __Pyx_PyBool_FromLong(long b) {
  return b ? __Pyx_NewRef(Py_True) : __Pyx_NewRef(Py_False);
}
static CYTHON_INLINE PyObject * __Pyx_PyInt_FromSize_t(size_t ival) {
    return PyInt_FromSize_t(ival);
}


#endif /* Py_PYTHON_H */
