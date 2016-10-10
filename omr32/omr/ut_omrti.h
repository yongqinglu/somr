/*
 *  Do not edit this file 
 *  Generated by TraceGen
 */
#ifndef UTE_OMRTI_MODULE_HEADER
#define UTE_OMRTI_MODULE_HEADER
#include "ute_module.h"
#if !defined(UT_DIRECT_TRACE_REGISTRATION)
#include "jni.h"
#endif /* !defined(UT_DIRECT_TRACE_REGISTRATION) */
#ifndef UT_TRACE_OVERHEAD
#define UT_TRACE_OVERHEAD 1
#endif
#ifndef UT_THREAD
#define UT_THREAD(thr) (void *)thr
#endif /* UT_THREAD */
#ifndef UT_STR
#define UT_STR(arg) #arg
#endif
#ifdef __cplusplus
extern "C" {
#endif

#ifdef __clang__
#include <unistd.h>
#define Trace_Unreachable() _exit(-1)
#else
#define Trace_Unreachable()
#endif

#if defined(UT_DIRECT_TRACE_REGISTRATION)
int32_t registeromrtiWithTrace(UtInterface * utIntf, UtModuleInfo* containerName);
int32_t deregisteromrtiWithTrace(UtInterface * utIntf);
#define UT_MODULE_LOADED(utIntf) registeromrtiWithTrace((utIntf), NULL);
#define UT_MODULE_UNLOADED(utIntf) deregisteromrtiWithTrace((utIntf));
#define UT_OMRTI_MODULE_LOADED(utIntf) registeromrtiWithTrace((utIntf), NULL);
#define UT_OMRTI_MODULE_UNLOADED(utIntf) deregisteromrtiWithTrace((utIntf));
#else /* defined(UT_DIRECT_TRACE_REGISTRATION) */
int32_t registeromrtiWithTrace(JavaVM * vm, UtModuleInfo* containerName);
int32_t deregisteromrtiWithTrace(JavaVM * vm);
#define UT_MODULE_LOADED(vm) registeromrtiWithTrace((JavaVM *)(vm), NULL);
#define UT_MODULE_UNLOADED(vm) deregisteromrtiWithTrace((JavaVM *)(vm));
#define UT_OMRTI_MODULE_LOADED(vm) registeromrtiWithTrace((JavaVM *)(vm), NULL);
#define UT_OMRTI_MODULE_UNLOADED(vm) deregisteromrtiWithTrace((JavaVM *)(vm));
#endif /* defined(UT_DIRECT_TRACE_REGISTRATION) */

#if UT_TRACE_OVERHEAD >= 1
#define Trc_OMRTI_omrtiGetMemoryCategories_Entry(thr, P1, P2, P3, P4) do { /* tracepoint name: omrti.0 */ \
	if ((unsigned char) omrti_UtActive[0] != 0){ \
		omrti_UtModuleInfo.intf->Trace(UT_THREAD(thr), &omrti_UtModuleInfo, ((0u << 8) | omrti_UtActive[0]), "\4\6\6\6", P1, P2, P3, P4);} \
	} while(0)
#else
#define Trc_OMRTI_omrtiGetMemoryCategories_Entry(thr, P1, P2, P3, P4)   /* tracepoint name: omrti.0 */
#endif

#if UT_TRACE_OVERHEAD >= 1
#define Trc_OMRTI_omrtiGetMemoryCategories_WrongVersion_Exit(thr, P1) do { /* tracepoint name: omrti.1 */ \
	if ((unsigned char) omrti_UtActive[1] != 0){ \
		omrti_UtModuleInfo.intf->Trace(UT_THREAD(thr), &omrti_UtModuleInfo, ((1u << 8) | omrti_UtActive[1]), "\4", P1);} \
	} while(0)
#else
#define Trc_OMRTI_omrtiGetMemoryCategories_WrongVersion_Exit(thr, P1)   /* tracepoint name: omrti.1 */
#endif

#if UT_TRACE_OVERHEAD >= 1
#define Trc_OMRTI_omrtiGetMemoryCategories_AllOutputsNull_Exit(thr) do { /* tracepoint name: omrti.2 */ \
	if ((unsigned char) omrti_UtActive[2] != 0){ \
		omrti_UtModuleInfo.intf->Trace(UT_THREAD(thr), &omrti_UtModuleInfo, ((2u << 8) | omrti_UtActive[2]), NULL);} \
	} while(0)
#else
#define Trc_OMRTI_omrtiGetMemoryCategories_AllOutputsNull_Exit(thr)   /* tracepoint name: omrti.2 */
#endif

#if UT_TRACE_OVERHEAD >= 1
#define Trc_OMRTI_omrtiGetMemoryCategories_NullOutput_Exit(thr, P1) do { /* tracepoint name: omrti.3 */ \
	if ((unsigned char) omrti_UtActive[3] != 0){ \
		omrti_UtModuleInfo.intf->Trace(UT_THREAD(thr), &omrti_UtModuleInfo, ((3u << 8) | omrti_UtActive[3]), "\4", P1);} \
	} while(0)
#else
#define Trc_OMRTI_omrtiGetMemoryCategories_NullOutput_Exit(thr, P1)   /* tracepoint name: omrti.3 */
#endif

#if UT_TRACE_OVERHEAD >= 1
#define Trc_OMRTI_omrtiGetMemoryCategories_NullWrittenPtr_Exit(thr, P1, P2) do { /* tracepoint name: omrti.4 */ \
	if ((unsigned char) omrti_UtActive[4] != 0){ \
		omrti_UtModuleInfo.intf->Trace(UT_THREAD(thr), &omrti_UtModuleInfo, ((4u << 8) | omrti_UtActive[4]), "\4\6", P1, P2);} \
	} while(0)
#else
#define Trc_OMRTI_omrtiGetMemoryCategories_NullWrittenPtr_Exit(thr, P1, P2)   /* tracepoint name: omrti.4 */
#endif

#if UT_TRACE_OVERHEAD >= 1
#define Trc_OMRTI_omrtiGetMemoryCategories_J9MemAllocFail_Exit(thr, P1) do { /* tracepoint name: omrti.5 */ \
	if ((unsigned char) omrti_UtActive[5] != 0){ \
		omrti_UtModuleInfo.intf->Trace(UT_THREAD(thr), &omrti_UtModuleInfo, ((5u << 8) | omrti_UtActive[5]), "\4", P1);} \
	} while(0)
#else
#define Trc_OMRTI_omrtiGetMemoryCategories_J9MemAllocFail_Exit(thr, P1)   /* tracepoint name: omrti.5 */
#endif

#if UT_TRACE_OVERHEAD >= 1
#define Trc_OMRTI_omrtiGetMemoryCategories_BufferOverflow(thr) do { /* tracepoint name: omrti.6 */ \
	if ((unsigned char) omrti_UtActive[6] != 0){ \
		omrti_UtModuleInfo.intf->Trace(UT_THREAD(thr), &omrti_UtModuleInfo, ((6u << 8) | omrti_UtActive[6]), NULL);} \
	} while(0)
#else
#define Trc_OMRTI_omrtiGetMemoryCategories_BufferOverflow(thr)   /* tracepoint name: omrti.6 */
#endif

#if UT_TRACE_OVERHEAD >= 1
#define Trc_OMRTI_omrtiGetMemoryCategories_Exit(thr, P1) do { /* tracepoint name: omrti.7 */ \
	if ((unsigned char) omrti_UtActive[7] != 0){ \
		omrti_UtModuleInfo.intf->Trace(UT_THREAD(thr), &omrti_UtModuleInfo, ((7u << 8) | omrti_UtActive[7]), "\4", P1);} \
	} while(0)
#else
#define Trc_OMRTI_omrtiGetMemoryCategories_Exit(thr, P1)   /* tracepoint name: omrti.7 */
#endif

#if UT_TRACE_OVERHEAD >= 1
#define TrcEnabled_Trc_OMRPROF_MethodSampleStart  (omrti_UtActive[8] != 0)
#define Trc_OMRPROF_MethodSampleStart(thr, P1) do { /* tracepoint name: omrti.8 */ \
	if ((unsigned char) omrti_UtActive[8] != 0){ \
		omrti_UtModuleInfo.intf->Trace(UT_THREAD(thr), &omrti_UtModuleInfo, ((8u << 8) | omrti_UtActive[8]), "\6", P1);} \
	} while(0)
#else
#define TrcEnabled_Trc_OMRPROF_MethodSampleStart  (0)
#define Trc_OMRPROF_MethodSampleStart(thr, P1)   /* tracepoint name: omrti.8 */
#endif

#if UT_TRACE_OVERHEAD >= 1
#define TrcEnabled_Trc_OMRPROF_MethodSampleContinue  (omrti_UtActive[9] != 0)
#define Trc_OMRPROF_MethodSampleContinue(thr, P1) do { /* tracepoint name: omrti.9 */ \
	if ((unsigned char) omrti_UtActive[9] != 0){ \
		omrti_UtModuleInfo.intf->Trace(UT_THREAD(thr), &omrti_UtModuleInfo, ((9u << 8) | omrti_UtActive[9]), "\6", P1);} \
	} while(0)
#else
#define TrcEnabled_Trc_OMRPROF_MethodSampleContinue  (0)
#define Trc_OMRPROF_MethodSampleContinue(thr, P1)   /* tracepoint name: omrti.9 */
#endif

#if UT_TRACE_OVERHEAD >= 1
#define TrcEnabled_Trc_OMRPROF_insertMethodDictionary_success  (omrti_UtActive[10] != 0)
#define Trc_OMRPROF_insertMethodDictionary_success(P1, P2) do { /* tracepoint name: omrti.10 */ \
	if ((unsigned char) omrti_UtActive[10] != 0){ \
		omrti_UtModuleInfo.intf->Trace((void *)NULL, &omrti_UtModuleInfo, ((10u << 8) | omrti_UtActive[10]), "\6\377", P1, P2);} \
	} while(0)
#else
#define TrcEnabled_Trc_OMRPROF_insertMethodDictionary_success  (0)
#define Trc_OMRPROF_insertMethodDictionary_success(P1, P2)   /* tracepoint name: omrti.10 */
#endif

#if UT_TRACE_OVERHEAD >= 1
#define TrcEnabled_Trc_OMRPROF_insertMethodDictionary_replaceExistingEntry  (omrti_UtActive[11] != 0)
#define Trc_OMRPROF_insertMethodDictionary_replaceExistingEntry(P1, P2) do { /* tracepoint name: omrti.11 */ \
	if ((unsigned char) omrti_UtActive[11] != 0){ \
		omrti_UtModuleInfo.intf->Trace((void *)NULL, &omrti_UtModuleInfo, ((11u << 8) | omrti_UtActive[11]), "\6\377", P1, P2);} \
	} while(0)
#else
#define TrcEnabled_Trc_OMRPROF_insertMethodDictionary_replaceExistingEntry  (0)
#define Trc_OMRPROF_insertMethodDictionary_replaceExistingEntry(P1, P2)   /* tracepoint name: omrti.11 */
#endif

#if UT_TRACE_OVERHEAD >= 1
#define TrcEnabled_Trc_OMRPROF_insertMethodDictionary_failed  (omrti_UtActive[12] != 0)
#define Trc_OMRPROF_insertMethodDictionary_failed(P1, P2, P3) do { /* tracepoint name: omrti.12 */ \
	if ((unsigned char) omrti_UtActive[12] != 0){ \
		omrti_UtModuleInfo.intf->Trace((void *)NULL, &omrti_UtModuleInfo, ((12u << 8) | omrti_UtActive[12]), "\4\6\377", P1, P2, P3);} \
	} while(0)
#else
#define TrcEnabled_Trc_OMRPROF_insertMethodDictionary_failed  (0)
#define Trc_OMRPROF_insertMethodDictionary_failed(P1, P2, P3)   /* tracepoint name: omrti.12 */
#endif

#if UT_TRACE_OVERHEAD >= 1
#define TrcEnabled_Trc_OMRPROF_methodDictionaryHighWaterMark  (omrti_UtActive[13] != 0)
#define Trc_OMRPROF_methodDictionaryHighWaterMark(P1, P2, P3, P4) do { /* tracepoint name: omrti.13 */ \
	if ((unsigned char) omrti_UtActive[13] != 0){ \
		omrti_UtModuleInfo.intf->Trace((void *)NULL, &omrti_UtModuleInfo, ((13u << 8) | omrti_UtActive[13]), "\4\4\4\4", P1, P2, P3, P4);} \
	} while(0)
#else
#define TrcEnabled_Trc_OMRPROF_methodDictionaryHighWaterMark  (0)
#define Trc_OMRPROF_methodDictionaryHighWaterMark(P1, P2, P3, P4)   /* tracepoint name: omrti.13 */
#endif

extern UtModuleInfo omrti_UtModuleInfo;
extern unsigned char omrti_UtActive[];

#ifndef UT_MODULE_INFO
#define UT_MODULE_INFO omrti_UtModuleInfo
#endif /* UT_MODULE_INFO */

#ifndef UT_ACTIVE
#define UT_ACTIVE omrti_UtActive
#endif /* UT_ACTIVE */

#ifdef __cplusplus
} /* extern "C" */
#endif
#endif /* UTE_OMRTI_MODULE_HEADER */
/*
 * End of file
 */
