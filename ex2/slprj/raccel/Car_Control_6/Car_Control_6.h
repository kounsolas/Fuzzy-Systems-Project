#ifndef RTW_HEADER_Car_Control_6_h_
#define RTW_HEADER_Car_Control_6_h_
#ifndef Car_Control_6_COMMON_INCLUDES_
#define Car_Control_6_COMMON_INCLUDES_
#include <stdlib.h>
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "Car_Control_6_types.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include <stddef.h>
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#include <string.h>
#define MODEL_NAME Car_Control_6
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (13) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (0)   
#elif NCSTATES != 0
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T j12to3cpkc ; real_T howct3x34n ; real_T pkyqj5ymbn ;
real_T nuhns0povx [ 3 ] ; real_T nvmypogeka ; real_T mc1jzs1oyx ; real_T
etsehycfqw ; real_T bjyfjp0f4o [ 101 ] ; real_T jawqhxehe5 ; } B ; typedef
struct { real_T n02axnbajm ; real_T eyefb11fhu ; real_T alw3bg4oqi ; real_T
cetghxnadh ; struct { void * AQHandles ; } eqnnjqzwke ; struct { void *
AQHandles ; } cxutsucrtu ; int32_T hubufiufje ; int32_T ki33ahdvnp ; int32_T
ngupsge0y1 ; int32_T aewedtmiuy ; uint8_T ipetmw5xox ; uint8_T i0xmzrx5tb ;
uint8_T ikoa0bflnt ; uint8_T n3regh311s ; boolean_T py02jzg13v ; boolean_T
ljhulhsbnj ; boolean_T ihslb1hbsu ; boolean_T oue4u1fsup ; boolean_T
amqcyfju03 ; boolean_T jb0y2agf4z ; boolean_T llkgqs04uq ; } DW ; typedef
struct { rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T
theta1 ; real_T xs ; real_T ys ; real_T OutputSamplePoints_Value [ 101 ] ;
real_T DelayX_InitialCondition ; real_T DelayY_InitialCondition ; real_T
Delaytheta_InitialCondition ; real_T Delaydtheta_InitialCondition ; real_T
Sat01_UpperSat ; real_T Sat01_LowerSat ; real_T Sat01_UpperSat_iihlhhdayd ;
real_T Sat01_LowerSat_cylljsuqtn ; } ; extern const char_T *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern DW rtDW ; extern P rtP ;
extern mxArray * mr_Car_Control_6_GetDWork ( ) ; extern void
mr_Car_Control_6_SetDWork ( const mxArray * ssDW ) ; extern mxArray *
mr_Car_Control_6_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * Car_Control_6_GetCAPIStaticMap ( void ) ;
extern SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern
const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern const int_T gblNumRootInportBlks ; extern const int_T
gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ; extern
const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [ ] ;
extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model (
ssExecutionInfo * executionInfo ) ;
#endif
