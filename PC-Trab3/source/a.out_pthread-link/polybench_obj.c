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
#include "upcr_geninclude/string.h"
#include "upcr_geninclude/stdlib.h"
#include</usr/include/unistd.h>
#include</usr/include/assert.h>
#include "upcr_geninclude/time.h"
#include</usr/include/x86_64-linux-gnu/sys/time.h>
#include</usr/include/x86_64-linux-gnu/sys/resource.h>
#include</usr/include/sched.h>
#include "upcr_geninclude/math.h"
#include</home/gth1ago/Documentos/UEM/4ano/prog_concorrente/PC_trab1/PC-Trab3/source/polybench-c-4.2.1-beta/utilities/polybench.h>
#line 1 "polybench.w2c.h"
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
struct polybench_data_ptrs {
  void ** user_view;
  void ** real_ptr;
  int nb_entries;
  int nb_avail_entries;
};
static _IEEE64 rtclock();

extern void polybench_flush_cache();

extern void polybench_prepare_instruments();

extern void polybench_timer_start();

extern void polybench_timer_stop();

extern void polybench_timer_print();

static void * xmalloc(unsigned long);

extern void polybench_free_data(void *);

extern void * polybench_alloc_data(unsigned long long, int);


double UPCR_TLD_DEFINE_TENTATIVE(polybench_t_start, 8, 8);
double UPCR_TLD_DEFINE_TENTATIVE(polybench_t_end, 8, 8);
unsigned long long UPCR_TLD_DEFINE_TENTATIVE(polybench_c_start, 8, 8);
unsigned long long UPCR_TLD_DEFINE_TENTATIVE(polybench_c_end, 8, 8);
int UPCR_TLD_DEFINE(polybench_papi_counters_threadid, 4, 4) = 0;
double UPCR_TLD_DEFINE(polybench_program_total_flops, 8, 8) = 0.0;
struct polybench_data_ptrs*  UPCR_TLD_DEFINE(_N22__polybench_alloc_table_N10_1484837057_, 8, 8) = 0;
unsigned long UPCR_TLD_DEFINE(_N32_polybench_inter_array_padding_sz_N10_2077961829_, 8, 8) = 0;
#define UPCR_SHARED_SIZE_ 8
#define UPCR_PSHARED_SIZE_ 8

void UPCRI_ALLOC_polybench_13889503819161544576(void) { 
UPCR_BEGIN_FUNCTION();

UPCR_SET_SRCPOS("_polybench_13889503819161544576_ALLOC",0);
}

void UPCRI_INIT_polybench_13889503819161544576(void) { 
UPCR_BEGIN_FUNCTION();
UPCR_SET_SRCPOS("_polybench_13889503819161544576_INIT",0);
}

#line 84 "polybench-c-4.2.1-beta/utilities/polybench.c"
static _IEEE64 rtclock()
#line 84 "polybench-c-4.2.1-beta/utilities/polybench.c"
{
#line 84 "polybench-c-4.2.1-beta/utilities/polybench.c"
  UPCR_BEGIN_FUNCTION();
  
#line 93 "polybench-c-4.2.1-beta/utilities/polybench.c"
  UPCR_EXIT_FUNCTION();
#line 93 "polybench-c-4.2.1-beta/utilities/polybench.c"
  return 0.0;
} /* rtclock */


#line 113 "polybench-c-4.2.1-beta/utilities/polybench.c"
extern void polybench_flush_cache()
#line 113 "polybench-c-4.2.1-beta/utilities/polybench.c"
{
#line 113 "polybench-c-4.2.1-beta/utilities/polybench.c"
  UPCR_BEGIN_FUNCTION();
  int cs;
  _IEEE64 * flush;
  _IEEE64 * _bupc__casttmp0;
  _IEEE64 tmp;
  int i;
  void * _bupc_call0;
  
#line 114 "polybench-c-4.2.1-beta/utilities/polybench.c"
  cs = 4194560;
#line 115 "polybench-c-4.2.1-beta/utilities/polybench.c"
  _bupc_call0 = calloc((unsigned long)(_UINT64)(cs), (unsigned long) 8ULL);
#line 115 "polybench-c-4.2.1-beta/utilities/polybench.c"
  _bupc__casttmp0 = _bupc_call0;
#line 115 "polybench-c-4.2.1-beta/utilities/polybench.c"
  flush = _bupc__casttmp0;
#line 117 "polybench-c-4.2.1-beta/utilities/polybench.c"
  tmp = 0.0;
#line 121 "polybench-c-4.2.1-beta/utilities/polybench.c"
  i = 0;
#line 121 "polybench-c-4.2.1-beta/utilities/polybench.c"
  while(i < cs)
#line 121 "polybench-c-4.2.1-beta/utilities/polybench.c"
  {
#line 122 "polybench-c-4.2.1-beta/utilities/polybench.c"
    tmp = tmp + *(flush + i);
#line 122 "polybench-c-4.2.1-beta/utilities/polybench.c"
    _1 :;
#line 122 "polybench-c-4.2.1-beta/utilities/polybench.c"
    i = i + 1;
  }
#line 123 "polybench-c-4.2.1-beta/utilities/polybench.c"
  if(tmp <= 10.0)
#line 123 "polybench-c-4.2.1-beta/utilities/polybench.c"
  {
  }
  else
#line 123 "polybench-c-4.2.1-beta/utilities/polybench.c"
  {
#line 123 "polybench-c-4.2.1-beta/utilities/polybench.c"
    __assert_fail("tmp <= 10.0", "polybench-c-4.2.1-beta/utilities/polybench.c", (unsigned int) 123U, "polybench_flush_cache");
  }
#line 124 "polybench-c-4.2.1-beta/utilities/polybench.c"
  free(flush);
  UPCR_EXIT_FUNCTION();
  return;
} /* polybench_flush_cache */


#line 354 "polybench-c-4.2.1-beta/utilities/polybench.c"
extern void polybench_prepare_instruments()
#line 354 "polybench-c-4.2.1-beta/utilities/polybench.c"
{
#line 354 "polybench-c-4.2.1-beta/utilities/polybench.c"
  UPCR_BEGIN_FUNCTION();
  
#line 356 "polybench-c-4.2.1-beta/utilities/polybench.c"
  polybench_flush_cache();
  UPCR_EXIT_FUNCTION();
  return;
} /* polybench_prepare_instruments */


#line 365 "polybench-c-4.2.1-beta/utilities/polybench.c"
extern void polybench_timer_start()
#line 365 "polybench-c-4.2.1-beta/utilities/polybench.c"
{
#line 365 "polybench-c-4.2.1-beta/utilities/polybench.c"
  UPCR_BEGIN_FUNCTION();
  register _IEEE64 _bupc_comma;
  
#line 366 "polybench-c-4.2.1-beta/utilities/polybench.c"
  polybench_prepare_instruments();
#line 368 "polybench-c-4.2.1-beta/utilities/polybench.c"
  _bupc_comma = rtclock();
#line 368 "polybench-c-4.2.1-beta/utilities/polybench.c"
  (*((_IEEE64 *) UPCR_TLD_ADDR( polybench_t_start ))) = _bupc_comma;
  UPCR_EXIT_FUNCTION();
  return;
} /* polybench_timer_start */


#line 376 "polybench-c-4.2.1-beta/utilities/polybench.c"
extern void polybench_timer_stop()
#line 376 "polybench-c-4.2.1-beta/utilities/polybench.c"
{
#line 376 "polybench-c-4.2.1-beta/utilities/polybench.c"
  UPCR_BEGIN_FUNCTION();
  register _IEEE64 _bupc_comma;
  
#line 378 "polybench-c-4.2.1-beta/utilities/polybench.c"
  _bupc_comma = rtclock();
#line 378 "polybench-c-4.2.1-beta/utilities/polybench.c"
  (*((_IEEE64 *) UPCR_TLD_ADDR( polybench_t_end ))) = _bupc_comma;
  UPCR_EXIT_FUNCTION();
  return;
} /* polybench_timer_stop */


#line 389 "polybench-c-4.2.1-beta/utilities/polybench.c"
extern void polybench_timer_print()
#line 389 "polybench-c-4.2.1-beta/utilities/polybench.c"
{
#line 389 "polybench-c-4.2.1-beta/utilities/polybench.c"
  UPCR_BEGIN_FUNCTION();
  
#line 402 "polybench-c-4.2.1-beta/utilities/polybench.c"
  printf("%0.6f\n", (*((_IEEE64 *) UPCR_TLD_ADDR( polybench_t_end ))) - (*((_IEEE64 *) UPCR_TLD_ADDR( polybench_t_start ))));
  UPCR_EXIT_FUNCTION();
  return;
} /* polybench_timer_print */


#line 518 "polybench-c-4.2.1-beta/utilities/polybench.c"
static void * xmalloc(
  unsigned long alloc_sz)
#line 518 "polybench-c-4.2.1-beta/utilities/polybench.c"
{
#line 518 "polybench-c-4.2.1-beta/utilities/polybench.c"
  UPCR_BEGIN_FUNCTION();
  register _INT32 _bupc_comma;
  void * ret;
  unsigned long padded_sz;
  int err;
  
#line 519 "polybench-c-4.2.1-beta/utilities/polybench.c"
  ret = (void *)(0ULL);
#line 521 "polybench-c-4.2.1-beta/utilities/polybench.c"
  (*((unsigned long *) UPCR_TLD_ADDR( _N32_polybench_inter_array_padding_sz_N10_2077961829_ ))) = (*((unsigned long *) UPCR_TLD_ADDR( _N32_polybench_inter_array_padding_sz_N10_2077961829_ )));
#line 522 "polybench-c-4.2.1-beta/utilities/polybench.c"
  padded_sz = alloc_sz + (*((unsigned long *) UPCR_TLD_ADDR( _N32_polybench_inter_array_padding_sz_N10_2077961829_ )));
#line 523 "polybench-c-4.2.1-beta/utilities/polybench.c"
  _bupc_comma = posix_memalign(&ret, (unsigned long) 4096ULL, padded_sz);
#line 523 "polybench-c-4.2.1-beta/utilities/polybench.c"
  err = _bupc_comma;
#line 524 "polybench-c-4.2.1-beta/utilities/polybench.c"
  if((_INT32)(((_UINT64)(ret) == 0ULL)) || (_INT32)((err != 0)))
#line 524 "polybench-c-4.2.1-beta/utilities/polybench.c"
  {
#line 526 "polybench-c-4.2.1-beta/utilities/polybench.c"
    fprintf(stderr, "[PolyBench] posix_memalign: cannot allocate memory");
#line 527 "polybench-c-4.2.1-beta/utilities/polybench.c"
    exit((int) 1);
  }
#line 543 "polybench-c-4.2.1-beta/utilities/polybench.c"
  UPCR_EXIT_FUNCTION();
#line 543 "polybench-c-4.2.1-beta/utilities/polybench.c"
  return ret;
} /* xmalloc */


#line 548 "polybench-c-4.2.1-beta/utilities/polybench.c"
extern void polybench_free_data(
  void * ptr)
#line 548 "polybench-c-4.2.1-beta/utilities/polybench.c"
{
#line 548 "polybench-c-4.2.1-beta/utilities/polybench.c"
  UPCR_BEGIN_FUNCTION();
  
#line 552 "polybench-c-4.2.1-beta/utilities/polybench.c"
  free(ptr);
  UPCR_EXIT_FUNCTION();
  return;
} /* polybench_free_data */


#line 558 "polybench-c-4.2.1-beta/utilities/polybench.c"
extern void * polybench_alloc_data(
  unsigned long long n,
  int elt_size)
#line 558 "polybench-c-4.2.1-beta/utilities/polybench.c"
{
#line 558 "polybench-c-4.2.1-beta/utilities/polybench.c"
  UPCR_BEGIN_FUNCTION();
  unsigned long val;
  void * ret;
  void * _bupc_call1;
  
#line 564 "polybench-c-4.2.1-beta/utilities/polybench.c"
  val = n;
#line 565 "polybench-c-4.2.1-beta/utilities/polybench.c"
  val = val * (_UINT64)(elt_size);
#line 566 "polybench-c-4.2.1-beta/utilities/polybench.c"
  _bupc_call1 = xmalloc(val);
#line 566 "polybench-c-4.2.1-beta/utilities/polybench.c"
  ret = _bupc_call1;
#line 568 "polybench-c-4.2.1-beta/utilities/polybench.c"
  UPCR_EXIT_FUNCTION();
#line 568 "polybench-c-4.2.1-beta/utilities/polybench.c"
  return ret;
} /* polybench_alloc_data */

#line 1 "_SYSTEM"
/**************************************************************************/
/* upcc-generated strings for configuration consistency checks            */

GASNETT_IDENT(UPCRI_IdentString_polybench_o_1638813465_GASNetConfig_gen, 
 "$GASNetConfig: (/tmp/upcc--921905-1638813465/polybench.trans.c) RELEASE=2021.3.0,SPEC=0.13,CONDUIT=SMP(SMP-2.0/SMP-2.0),THREADMODEL=PAR,SEGMENT=FAST,PTR=64bit,CACHE_LINE_BYTES=64,noalign,pshm,nodebug,notrace,nostats,nodebugmalloc,nosrclines,timers_native,membars_native,atomics_native,atomic32_native,atomic64_native,notiopt $");
GASNETT_IDENT(UPCRI_IdentString_polybench_o_1638813465_UPCRConfig_gen,
 "$UPCRConfig: (/tmp/upcc--921905-1638813465/polybench.trans.c) VERSION=2021.4.0,PLATFORMENV=shared,SHMEM=pthreads/pshm,SHAREDPTRREP=packed/p20:t10:a34,TRANS=berkeleyupc,nodebug,nogasp,dynamicthreads $");
GASNETT_IDENT(UPCRI_IdentString_polybench_o_1638813465_translatetime, 
 "$UPCTranslateTime: (polybench.o) Mon Dec  6 09:57:45 2021 $");
GASNETT_IDENT(UPCRI_IdentString_polybench_o_1638813465_GASNetConfig_obj, 
 "$GASNetConfig: (polybench.o) " GASNET_CONFIG_STRING " $");
GASNETT_IDENT(UPCRI_IdentString_polybench_o_1638813465_UPCRConfig_obj,
 "$UPCRConfig: (polybench.o) " UPCR_CONFIG_STRING UPCRI_THREADCONFIG_STR " $");
GASNETT_IDENT(UPCRI_IdentString_polybench_o_1638813465_translator, 
 "$UPCTranslator: (polybench.o) /usr/local/upc/2020.12.0/translator/install/targ (aphid.lbl.gov) $");
GASNETT_IDENT(UPCRI_IdentString_polybench_o_1638813465_upcver, 
 "$UPCVersion: (polybench.o) 2020.12.0 $");
GASNETT_IDENT(UPCRI_IdentString_polybench_o_1638813465_compileline, 
 "$UPCCompileLine: (polybench.o) /usr/local/upc/2020.12.0/runtime/inst/bin/upcc.pl --at-remote-http -translator=/usr/local/upc/2020.12.0/translator/install/targ --arch-size=64 --network=smp --pthreads 8 --lines --trans --sizes-file=upcc-sizes fdtd-2d.i polybench.i $");
GASNETT_IDENT(UPCRI_IdentString_polybench_o_1638813465_compiletime, 
 "$UPCCompileTime: (polybench.o) " __DATE__ " " __TIME__ " $");
#ifndef UPCRI_CC /* ensure backward compatilibity for http netcompile */
#define UPCRI_CC <unknown>
#endif
GASNETT_IDENT(UPCRI_IdentString_polybench_o_1638813465_backendcompiler, 
 "$UPCRBackendCompiler: (polybench.o) " _STRINGIFY(UPCRI_CC) " $");

#ifdef GASNETT_CONFIGURE_MISMATCH
  GASNETT_IDENT(UPCRI_IdentString_polybench_o_1638813465_configuremismatch, 
   "$UPCRConfigureMismatch: (polybench.o) 1 $");
  GASNETT_IDENT(UPCRI_IdentString_polybench_o_1638813465_configuredcompiler, 
   "$UPCRConfigureCompiler: (polybench.o) " GASNETT_PLATFORM_COMPILER_IDSTR " $");
  GASNETT_IDENT(UPCRI_IdentString_polybench_o_1638813465_buildcompiler, 
   "$UPCRBuildCompiler: (polybench.o) " PLATFORM_COMPILER_IDSTR " $");
#endif

/**************************************************************************/
GASNETT_IDENT(UPCRI_IdentString_polybench_o_1638813465_transver_2,
 "$UPCTranslatorVersion: (polybench.o) 2.28.2, built on Dec 11 2020 at 14:19:36, host aphid.lbl.gov linux-x86_64/64, gcc v9.3.0 $");
GASNETT_IDENT(UPCRI_IdentString_ALLOC_polybench_13889503819161544576,"$UPCRAllocFn: (polybench.trans.c) UPCRI_ALLOC_polybench_13889503819161544576 $");
GASNETT_IDENT(UPCRI_IdentString_INIT_polybench_13889503819161544576,"$UPCRInitFn: (polybench.trans.c) UPCRI_INIT_polybench_13889503819161544576 $");
