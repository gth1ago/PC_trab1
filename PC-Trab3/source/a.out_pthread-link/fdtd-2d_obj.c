/* --- UPCR system headers --- */ 
#include "upcr.h" 
#include "whirl2c.h"
#include "upcr_proxy.h"
/*******************************************************
 * C file translated from WHIRL Mon Dec  6 09:57:45 2021
 *******************************************************/

/* UPC Runtime specification expected: 3.6 */
#define UPCR_WANT_MAJOR 3
#define UPCR_WANT_MINOR 6
/* UPC translator version: release 2.28.2, built on Dec 11 2020 at 14:19:36, host aphid.lbl.gov linux-x86_64/64, gcc v9.3.0 */
/* Included code from the initialization script */
#include</usr/local/berkeley_upc/opt/include/upcr_config.h>
#include</usr/local/berkeley_upc/opt/include/gasnet_portable_platform.h>
#include "upcr_geninclude/stdio.h"
#include</usr/include/unistd.h>
#include "upcr_geninclude/string.h"
#include "upcr_geninclude/math.h"
#include</home/gth1ago/Documentos/UEM/4ano/prog_concorrente/PC_trab1/PC-Trab3/source/polybench-c-4.2.1-beta/utilities/polybench.h>
#include</home/gth1ago/Documentos/UEM/4ano/prog_concorrente/PC_trab1/PC-Trab3/source/polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.h>
#line 1 "fdtd-2d.w2c.h"
/* Include builtin types and operators */

#ifndef UPCR_TRANS_EXTRA_INCL
#define UPCR_TRANS_EXTRA_INCL
extern int upcrt_gcd (int _a, int _b);
extern int _upcrt_forall_start(int _start_thread, int _step, int _lo, int _scale);
#define upcrt_forall_start(start_thread, step, lo, scale)  \
       _upcrt_forall_start(start_thread, step, lo, scale)
int32_t UPCR_TLD_DEFINE_TENTATIVE(upcrt_forall_control, 4, 4);
#define upcr_forall_control upcrt_forall_control
#ifndef UPCR_EXIT_FUNCTION
#define UPCR_EXIT_FUNCTION() ((void)0)
#endif
#if UPCR_RUNTIME_SPEC_MAJOR > 3 || (UPCR_RUNTIME_SPEC_MAJOR == 3 && UPCR_RUNTIME_SPEC_MINOR >= 8)
  #define UPCRT_STARTUP_SHALLOC(sptr, blockbytes, numblocks, mult_by_threads, elemsz, typestr) \
      { &(sptr), (blockbytes), (numblocks), (mult_by_threads), (elemsz), #sptr, (typestr) }
#else
  #define UPCRT_STARTUP_SHALLOC(sptr, blockbytes, numblocks, mult_by_threads, elemsz, typestr) \
      { &(sptr), (blockbytes), (numblocks), (mult_by_threads) }
#endif
#define UPCRT_STARTUP_PSHALLOC UPCRT_STARTUP_SHALLOC

/**** Autonb optimization ********/

extern void _upcrt_memput_nb(upcr_shared_ptr_t _dst, const void *_src, size_t _n);
#define upcrt_memput_nb(dst, src, n) \
       (upcri_srcpos(), _upcrt_memput_nb(dst, src, n))

#endif


/* Types */
/* File-level vars and routines */
static void init_array(int, int, int, _IEEE64(*)[2600LL], _IEEE64(*)[2600LL], _IEEE64(*)[2600LL], _IEEE64 *);

static void print_array(int, int, _IEEE64(*)[2600LL], _IEEE64(*)[2600LL], _IEEE64(*)[2600LL]);

static void kernel_fdtd_2d(int, int, int, _IEEE64(*)[2600LL], _IEEE64(*)[2600LL], _IEEE64(*)[2600LL], _IEEE64 *);

extern int user_main(int, char **);


#define UPCR_SHARED_SIZE_ 8
#define UPCR_PSHARED_SIZE_ 8

void UPCRI_ALLOC_fdtd_2d_249888066869364897(void) { 
UPCR_BEGIN_FUNCTION();

UPCR_SET_SRCPOS("_fdtd_2d_249888066869364897_ALLOC",0);
}

void UPCRI_INIT_fdtd_2d_249888066869364897(void) { 
UPCR_BEGIN_FUNCTION();
UPCR_SET_SRCPOS("_fdtd_2d_249888066869364897_INIT",0);
}

#line 33 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
static void init_array(
  int tmax,
  int nx,
  int ny,
  _IEEE64(*ex)[2600LL],
  _IEEE64(*ey)[2600LL],
  _IEEE64(*hz)[2600LL],
  _IEEE64 * _fict_)
#line 33 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
{
#line 33 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  UPCR_BEGIN_FUNCTION();
  int i;
  int j;
  
#line 36 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  i = 0;
#line 36 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  while(i < tmax)
#line 36 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  {
#line 37 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
    * (_fict_ + i) = (_IEEE64)(i);
#line 37 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
    _1 :;
#line 37 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
    i = i + 1;
  }
#line 38 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  i = 0;
#line 38 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  while(i < nx)
#line 38 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  {
#line 39 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
    j = 0;
#line 39 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
    while(j < ny)
#line 39 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
    {
#line 41 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      * ((_IEEE64 *)(ex) + (j + (i * 2600))) = ((_IEEE64)(i) * (_IEEE64)((j + 1))) / (_IEEE64)(nx);
#line 42 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      * ((_IEEE64 *)(ey) + (j + (i * 2600))) = ((_IEEE64)(i) * (_IEEE64)((j + 2))) / (_IEEE64)(ny);
#line 43 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      * ((_IEEE64 *)(hz) + (j + (i * 2600))) = ((_IEEE64)(i) * (_IEEE64)((j + 3))) / (_IEEE64)(nx);
#line 44 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      _3 :;
#line 44 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      j = j + 1;
    }
#line 44 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
    _2 :;
#line 44 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
    i = i + 1;
  }
  UPCR_EXIT_FUNCTION();
  return;
} /* init_array */


#line 56 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
static void print_array(
  int nx,
  int ny,
  _IEEE64(*ex)[2600LL],
  _IEEE64(*ey)[2600LL],
  _IEEE64(*hz)[2600LL])
#line 56 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
{
#line 56 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  UPCR_BEGIN_FUNCTION();
  int i;
  int j;
  
#line 59 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  fprintf(stderr, "==BEGIN DUMP_ARRAYS==\n");
#line 60 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  fprintf(stderr, "begin dump: %s", "ex");
#line 61 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  i = 0;
#line 61 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  while(i < nx)
#line 61 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  {
#line 62 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
    j = 0;
#line 62 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
    while(j < ny)
#line 62 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
    {
#line 63 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      if(((j + (i * nx)) % 20) == 0)
#line 63 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      {
#line 63 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
        fprintf(stderr, "\n");
      }
#line 64 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      fprintf(stderr, "%0.2lf ", *((_IEEE64 *)(ex) + (j + (i * 2600))));
#line 65 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      _2 :;
#line 65 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      j = j + 1;
    }
#line 65 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
    _1 :;
#line 65 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
    i = i + 1;
  }
#line 66 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  fprintf(stderr, "\nend   dump: %s\n", "ex");
#line 67 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  fprintf(stderr, "==END   DUMP_ARRAYS==\n");
#line 69 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  fprintf(stderr, "begin dump: %s", "ey");
#line 70 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  i = 0;
#line 70 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  while(i < nx)
#line 70 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  {
#line 71 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
    j = 0;
#line 71 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
    while(j < ny)
#line 71 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
    {
#line 72 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      if(((j + (i * nx)) % 20) == 0)
#line 72 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      {
#line 72 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
        fprintf(stderr, "\n");
      }
#line 73 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      fprintf(stderr, "%0.2lf ", *((_IEEE64 *)(ey) + (j + (i * 2600))));
#line 74 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      _4 :;
#line 74 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      j = j + 1;
    }
#line 74 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
    _3 :;
#line 74 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
    i = i + 1;
  }
#line 75 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  fprintf(stderr, "\nend   dump: %s\n", "ey");
#line 77 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  fprintf(stderr, "begin dump: %s", "hz");
#line 78 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  i = 0;
#line 78 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  while(i < nx)
#line 78 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  {
#line 79 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
    j = 0;
#line 79 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
    while(j < ny)
#line 79 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
    {
#line 80 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      if(((j + (i * nx)) % 20) == 0)
#line 80 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      {
#line 80 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
        fprintf(stderr, "\n");
      }
#line 81 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      fprintf(stderr, "%0.2lf ", *((_IEEE64 *)(hz) + (j + (i * 2600))));
#line 82 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      _6 :;
#line 82 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      j = j + 1;
    }
#line 82 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
    _5 :;
#line 82 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
    i = i + 1;
  }
#line 83 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  fprintf(stderr, "\nend   dump: %s\n", "hz");
  UPCR_EXIT_FUNCTION();
  return;
} /* print_array */


#line 97 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
static void kernel_fdtd_2d(
  int tmax,
  int nx,
  int ny,
  _IEEE64(*ex)[2600LL],
  _IEEE64(*ey)[2600LL],
  _IEEE64(*hz)[2600LL],
  _IEEE64 * _fict_)
#line 97 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
{
#line 97 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  UPCR_BEGIN_FUNCTION();
  int t;
  int j;
  int i;
  
#line 102 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  t = 0;
#line 102 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  #pragma scop
#line 102 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  while(t < tmax)
#line 102 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  {
#line 104 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
    j = 0;
#line 104 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
    while(j < ny)
#line 104 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
    {
#line 105 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      * (*(_IEEE64 **)(&ey) + j) = *(_fict_ + t);
#line 105 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      _2 :;
#line 105 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      j = j + 1;
    }
#line 106 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
    i = 1;
#line 106 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
    while(i < nx)
#line 106 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
    {
#line 107 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      j = 0;
#line 107 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      while(j < ny)
#line 107 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      {
#line 108 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
        * ((_IEEE64 *)(ey) + (j + (i * 2600))) = *((_IEEE64 *)(ey) + (j + (i * 2600))) - ((*((_IEEE64 *)(hz) + (j + (i * 2600))) - *((_IEEE64 *)((((_UINT64)(j) + ((_UINT64)(i) * (_UINT64)(2600))) * (_UINT64)(8)) + ((_UINT64)(hz) - (_UINT64)(20800))))) * 0.5);
#line 108 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
        _4 :;
#line 108 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
        j = j + 1;
      }
#line 108 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      _3 :;
#line 108 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      i = i + 1;
    }
#line 109 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
    i = 0;
#line 109 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
    while(i < nx)
#line 109 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
    {
#line 110 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      j = 1;
#line 110 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      while(j < ny)
#line 110 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      {
#line 111 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
        * ((_IEEE64 *)(ex) + (j + (i * 2600))) = *((_IEEE64 *)(ex) + (j + (i * 2600))) - ((*((_IEEE64 *)(hz) + (j + (i * 2600))) - *((_IEEE64 *)(((_UINT64)((_IEEE64(*)[2600LL])((_UINT8 *)(hz) + (i * 20800))) - (_UINT64)(8)) + (_UINT64)((j * 8))))) * 0.5);
#line 111 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
        _6 :;
#line 111 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
        j = j + 1;
      }
#line 111 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      _5 :;
#line 111 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      i = i + 1;
    }
#line 112 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
    i = 0;
#line 112 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
    while(i < (nx + -1))
#line 112 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
    {
#line 113 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      j = 0;
#line 113 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      while(j < (ny + -1))
#line 113 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      {
#line 115 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
        * ((_IEEE64 *)(hz) + (j + (i * 2600))) = *((_IEEE64 *)(hz) + (j + (i * 2600))) - (((*(((_IEEE64 *)(ey) + (j + (i * 2600))) + 2600LL) + (*(((_IEEE64 *)(((_IEEE64 *)(ex) + (i * 2600))) + j) + 1LL) - *((_IEEE64 *)(ex) + (j + (i * 2600))))) - *((_IEEE64 *)(ey) + (j + (i * 2600)))) * 0.7);
#line 115 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
        _8 :;
#line 115 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
        j = j + 1;
      }
#line 115 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      _7 :;
#line 115 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
      i = i + 1;
    }
#line 116 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
    _1 :;
#line 116 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
    t = t + 1;
  }
#line 118 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  #pragma endscop
  UPCR_EXIT_FUNCTION();
  return;
} /* kernel_fdtd_2d */


#line 123 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
extern int user_main(
  int argc,
  char ** argv)
#line 123 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
{
#line 123 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  UPCR_BEGIN_FUNCTION();
  register _INT32 _bupc_comma;
  int tmax;
  int nx;
  int ny;
  _IEEE64(*_bupc__casttmp0)[2000LL][2600LL];
  _IEEE64(*ex)[2000LL][2600LL];
  _IEEE64(*_bupc__casttmp1)[2000LL][2600LL];
  _IEEE64(*ey)[2000LL][2600LL];
  _IEEE64(*_bupc__casttmp2)[2000LL][2600LL];
  _IEEE64(*hz)[2000LL][2600LL];
  _IEEE64(*_bupc__casttmp3)[1000LL];
  _IEEE64(*_fict_)[1000LL];
  int _bupc__spilleq4;
  void * _bupc_call0;
  void * _bupc_call1;
  void * _bupc_call2;
  void * _bupc_call3;
  
#line 125 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  tmax = 1000;
#line 126 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  nx = 2000;
#line 127 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  ny = 2600;
#line 130 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  _bupc_call0 = polybench_alloc_data((unsigned long long) 5200000ULL, (int) 8);
#line 130 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  _bupc__casttmp0 = _bupc_call0;
#line 130 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  ex = _bupc__casttmp0;
#line 131 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  _bupc_call1 = polybench_alloc_data((unsigned long long) 5200000ULL, (int) 8);
#line 131 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  _bupc__casttmp1 = _bupc_call1;
#line 131 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  ey = _bupc__casttmp1;
#line 132 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  _bupc_call2 = polybench_alloc_data((unsigned long long) 5200000ULL, (int) 8);
#line 132 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  _bupc__casttmp2 = _bupc_call2;
#line 132 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  hz = _bupc__casttmp2;
#line 133 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  _bupc_call3 = polybench_alloc_data((unsigned long long) 1000ULL, (int) 8);
#line 133 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  _bupc__casttmp3 = _bupc_call3;
#line 133 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  _fict_ = _bupc__casttmp3;
#line 140 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  init_array(tmax, nx, ny, *(_IEEE64(**)[2600LL])(&ex), *(_IEEE64(**)[2600LL])(&ey), *(_IEEE64(**)[2600LL])(&hz), *(_IEEE64 **)(&_fict_));
#line 150 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  kernel_fdtd_2d(tmax, nx, ny, *(_IEEE64(**)[2600LL])(&ex), *(_IEEE64(**)[2600LL])(&ey), *(_IEEE64(**)[2600LL])(&hz), *(_IEEE64 **)(&_fict_));
#line 159 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  if(!(argc > 42))
    goto _2;
#line 159 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  _bupc_comma = strcmp((const char *) * argv, "");
#line 159 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  _bupc__spilleq4 = _bupc_comma;
#line 159 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  if(!(_bupc__spilleq4 == 0))
    goto _2;
#line 161 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  print_array(nx, ny, *(_IEEE64(**)[2600LL])(&ex), *(_IEEE64(**)[2600LL])(&ey), *(_IEEE64(**)[2600LL])(&hz));
#line 159 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  _2 :;
#line 164 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  free(ex);
#line 165 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  free(ey);
#line 166 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  free(hz);
#line 167 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  free(_fict_);
#line 169 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  UPCR_EXIT_FUNCTION();
#line 169 "polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c"
  return 0;
} /* user_main */

#line 1 "_SYSTEM"
/**************************************************************************/
/* upcc-generated strings for configuration consistency checks            */

GASNETT_IDENT(UPCRI_IdentString_fdtd_2d_o_1638813465_GASNetConfig_gen, 
 "$GASNetConfig: (/tmp/upcc--921905-1638813465/fdtd-2d.trans.c) RELEASE=2021.3.0,SPEC=0.13,CONDUIT=SMP(SMP-2.0/SMP-2.0),THREADMODEL=PAR,SEGMENT=FAST,PTR=64bit,CACHE_LINE_BYTES=64,noalign,pshm,nodebug,notrace,nostats,nodebugmalloc,nosrclines,timers_native,membars_native,atomics_native,atomic32_native,atomic64_native,notiopt $");
GASNETT_IDENT(UPCRI_IdentString_fdtd_2d_o_1638813465_UPCRConfig_gen,
 "$UPCRConfig: (/tmp/upcc--921905-1638813465/fdtd-2d.trans.c) VERSION=2021.4.0,PLATFORMENV=shared,SHMEM=pthreads/pshm,SHAREDPTRREP=packed/p20:t10:a34,TRANS=berkeleyupc,nodebug,nogasp,dynamicthreads $");
GASNETT_IDENT(UPCRI_IdentString_fdtd_2d_o_1638813465_translatetime, 
 "$UPCTranslateTime: (fdtd-2d.o) Mon Dec  6 09:57:45 2021 $");
GASNETT_IDENT(UPCRI_IdentString_fdtd_2d_o_1638813465_GASNetConfig_obj, 
 "$GASNetConfig: (fdtd-2d.o) " GASNET_CONFIG_STRING " $");
GASNETT_IDENT(UPCRI_IdentString_fdtd_2d_o_1638813465_UPCRConfig_obj,
 "$UPCRConfig: (fdtd-2d.o) " UPCR_CONFIG_STRING UPCRI_THREADCONFIG_STR " $");
GASNETT_IDENT(UPCRI_IdentString_fdtd_2d_o_1638813465_translator, 
 "$UPCTranslator: (fdtd-2d.o) /usr/local/upc/2020.12.0/translator/install/targ (aphid.lbl.gov) $");
GASNETT_IDENT(UPCRI_IdentString_fdtd_2d_o_1638813465_upcver, 
 "$UPCVersion: (fdtd-2d.o) 2020.12.0 $");
GASNETT_IDENT(UPCRI_IdentString_fdtd_2d_o_1638813465_compileline, 
 "$UPCCompileLine: (fdtd-2d.o) /usr/local/upc/2020.12.0/runtime/inst/bin/upcc.pl --at-remote-http -translator=/usr/local/upc/2020.12.0/translator/install/targ --arch-size=64 --network=smp --pthreads 8 --lines --trans --sizes-file=upcc-sizes fdtd-2d.i polybench.i $");
GASNETT_IDENT(UPCRI_IdentString_fdtd_2d_o_1638813465_compiletime, 
 "$UPCCompileTime: (fdtd-2d.o) " __DATE__ " " __TIME__ " $");
#ifndef UPCRI_CC /* ensure backward compatilibity for http netcompile */
#define UPCRI_CC <unknown>
#endif
GASNETT_IDENT(UPCRI_IdentString_fdtd_2d_o_1638813465_backendcompiler, 
 "$UPCRBackendCompiler: (fdtd-2d.o) " _STRINGIFY(UPCRI_CC) " $");

#ifdef GASNETT_CONFIGURE_MISMATCH
  GASNETT_IDENT(UPCRI_IdentString_fdtd_2d_o_1638813465_configuremismatch, 
   "$UPCRConfigureMismatch: (fdtd-2d.o) 1 $");
  GASNETT_IDENT(UPCRI_IdentString_fdtd_2d_o_1638813465_configuredcompiler, 
   "$UPCRConfigureCompiler: (fdtd-2d.o) " GASNETT_PLATFORM_COMPILER_IDSTR " $");
  GASNETT_IDENT(UPCRI_IdentString_fdtd_2d_o_1638813465_buildcompiler, 
   "$UPCRBuildCompiler: (fdtd-2d.o) " PLATFORM_COMPILER_IDSTR " $");
#endif

/**************************************************************************/
GASNETT_IDENT(UPCRI_IdentString_fdtd_2d_o_1638813465_transver_2,
 "$UPCTranslatorVersion: (fdtd-2d.o) 2.28.2, built on Dec 11 2020 at 14:19:36, host aphid.lbl.gov linux-x86_64/64, gcc v9.3.0 $");
GASNETT_IDENT(UPCRI_IdentString_INIT_fdtd_2d_249888066869364897,"$UPCRInitFn: (fdtd-2d.trans.c) UPCRI_INIT_fdtd_2d_249888066869364897 $");
GASNETT_IDENT(UPCRI_IdentString_ALLOC_fdtd_2d_249888066869364897,"$UPCRAllocFn: (fdtd-2d.trans.c) UPCRI_ALLOC_fdtd_2d_249888066869364897 $");
