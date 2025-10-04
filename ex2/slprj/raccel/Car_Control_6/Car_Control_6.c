#include "Car_Control_6.h"
#include "rtwtypes.h"
#include "mwmathutil.h"
#include "Car_Control_6_private.h"
#include "rt_logging_mmi.h"
#include "Car_Control_6_capi.h"
#include "Car_Control_6_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , & stopRequested ) ; }
rtExtModeShutdown ( 2 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 3 ; const char_T
* gbl_raccel_Version = "10.7 (R2023a) 19-Nov-2022" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 0 ; const int_T
gblNumModelInputs = 0 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ - 1 } ; const int_T gblInportDims [ ] = { - 1 } ; const int_T
gblInportComplex [ ] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1
} ; const int_T gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [
] = { 1 , 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes (
SimStruct * S , const char * inportFileName , int * matFileFormat ) { return
rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
#define hppzdqbr3t (-1)
B rtB ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS = &
model_S ; static real_T cxthrgce23 ( real_T x , const real_T params [ 3 ] ) ;
static void brnn32k1sf ( const real_T x [ 101 ] , const real_T params [ 3 ] ,
real_T y [ 101 ] ) ; static real_T cxthrgce23 ( real_T x , const real_T
params [ 3 ] ) { real_T y ; y = 0.0 ; if ( ( params [ 0 ] != params [ 1 ] )
&& ( params [ 0 ] < x ) && ( x < params [ 1 ] ) ) { y = 1.0 / ( params [ 1 ]
- params [ 0 ] ) * ( x - params [ 0 ] ) ; } if ( ( params [ 1 ] != params [ 2
] ) && ( params [ 1 ] < x ) && ( x < params [ 2 ] ) ) { y = 1.0 / ( params [
2 ] - params [ 1 ] ) * ( params [ 2 ] - x ) ; } if ( x == params [ 1 ] ) { y
= 1.0 ; } return y ; } static void brnn32k1sf ( const real_T x [ 101 ] ,
const real_T params [ 3 ] , real_T y [ 101 ] ) { real_T a ; real_T b ; real_T
c ; real_T x_p ; int32_T i ; a = params [ 0 ] ; b = params [ 1 ] ; c = params
[ 2 ] ; for ( i = 0 ; i < 101 ; i ++ ) { y [ i ] = 0.0 ; if ( a != b ) { x_p
= x [ i ] ; if ( ( a < x_p ) && ( x_p < b ) ) { y [ i ] = 1.0 / ( b - a ) * (
x_p - a ) ; } } if ( b != c ) { x_p = x [ i ] ; if ( ( b < x_p ) && ( x_p < c
) ) { y [ i ] = 1.0 / ( c - b ) * ( c - x_p ) ; } } if ( x [ i ] == b ) { y [
i ] = 1.0 ; } } } void MdlInitialize ( void ) { rtDW . n02axnbajm = rtP .
DelayX_InitialCondition ; rtDW . eyefb11fhu = rtP . DelayY_InitialCondition ;
rtDW . alw3bg4oqi = rtP . Delaytheta_InitialCondition ; rtDW . cetghxnadh =
rtP . Delaydtheta_InitialCondition ; rtDW . hubufiufje = hppzdqbr3t ; rtDW .
ipetmw5xox = 0U ; rtDW . ngupsge0y1 = hppzdqbr3t ; rtDW . ikoa0bflnt = 0U ;
rtDW . ki33ahdvnp = hppzdqbr3t ; rtDW . i0xmzrx5tb = 0U ; rtDW . aewedtmiuy =
hppzdqbr3t ; rtDW . n3regh311s = 0U ; } void MdlStart ( void ) { { bool
externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} { { { bool isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU
srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars ( "MATLAB Function:1" )
; sdiLabelU origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "MATLAB Function:1" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "Car_Control_6/To Workspace" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars (
"MATLAB Function:1" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont = SAMPLE_TIME_DISCRETE
; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims .
dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ; srcInfo .
fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. eqnnjqzwke . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"d483e202-07b0-4714-b135-999ee413ffd8" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . eqnnjqzwke . AQHandles , hDT , & srcInfo ) ; if ( rtDW . eqnnjqzwke .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . eqnnjqzwke . AQHandles ,
"0.1" , 0.1 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . eqnnjqzwke
. AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . eqnnjqzwke . AQHandles ,
ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
eqnnjqzwke . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
eqnnjqzwke . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . eqnnjqzwke . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"X" ) ; sdiRegisterWksVariable ( rtDW . eqnnjqzwke . AQHandles , varName ,
"timeseries" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "MATLAB Function:2" ) ;
sdiLabelU origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "MATLAB Function:2" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "Car_Control_6/To Workspace1" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars (
"MATLAB Function:2" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont = SAMPLE_TIME_DISCRETE
; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims .
dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ; srcInfo .
fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. cxutsucrtu . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"2143173b-d4ad-47e0-a216-705bb4d348d6" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . cxutsucrtu . AQHandles , hDT , & srcInfo ) ; if ( rtDW . cxutsucrtu .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . cxutsucrtu . AQHandles ,
"0.1" , 0.1 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . cxutsucrtu
. AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . cxutsucrtu . AQHandles ,
ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
cxutsucrtu . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
cxutsucrtu . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . cxutsucrtu . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"Y" ) ; sdiRegisterWksVariable ( rtDW . cxutsucrtu . AQHandles , varName ,
"timeseries" ) ; sdiFreeLabel ( varName ) ; } } } } } rtB . j12to3cpkc = rtP
. xs ; rtDW . py02jzg13v = true ; rtB . howct3x34n = rtP . ys ; rtDW .
ljhulhsbnj = true ; rtB . pkyqj5ymbn = rtP . theta1 ; rtDW . ihslb1hbsu =
true ; MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) { real_T
outputMFCache [ 505 ] ; real_T tmp_e [ 101 ] ; real_T tmp_g [ 101 ] ; real_T
tmp_i [ 101 ] ; real_T tmp_m [ 101 ] ; real_T tmp_p [ 101 ] ; real_T
hszrlf2uxv [ 29 ] ; real_T inputMFCache [ 15 ] ; real_T tmp [ 3 ] ; real_T
absx ; real_T b_absx ; real_T kied35bz3q ; real_T u ; real_T varargin_1_data
; int32_T i ; int32_T trueCount ; int8_T n ; boolean_T tmp_data ; static
const int8_T f [ 29 ] = { 5 , 5 , 5 , 4 , 2 , 5 , 5 , 5 , 3 , 2 , 5 , 5 , 3 ,
2 , 2 , 5 , 5 , 3 , 2 , 1 , 5 , 4 , 3 , 2 , 1 , 4 , 3 , 3 , 2 } ; static
const real_T e [ 3 ] = { 75.8333333333333 , 130.0 , 184.166666666667 } ;
static const real_T d [ 3 ] = { 10.8333333333333 , 65.0 , 119.166666666667 }
; static const int8_T d_p [ 87 ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 1 , 2 , 2 , 1
, 1 , 1 , 1 , 1 , 2 , 2 , 2 , 2 , 2 , 3 , 3 , 3 , 3 , 3 , 4 , 4 , 4 , 4 , 4 ,
5 , 5 , 5 , 5 , 5 , 5 , 5 , 5 , 5 , 1 , 2 , 3 , 4 , 5 , 1 , 2 , 3 , 4 , 5 , 1
, 2 , 3 , 4 , 5 , 1 , 2 , 3 , 4 , 5 , 1 , 2 , 3 , 4 , 5 , 3 , 4 , 3 , 4 } ;
static const real_T c [ 3 ] = { - 119.166666666667 , - 65.0 , -
10.8333333333333 } ; static const real_T b [ 3 ] = { - 184.166666666667 , -
130.0 , - 75.8333333333333 } ; static const real_T c_p [ 3 ] = {
0.791666666666667 , 1.0 , 1.20833333333333 } ; static const real_T b_p [ 3 ]
= { 0.0416666666666667 , 0.25 , 0.458333333333333 } ; real_T c_idx_0 ;
boolean_T guard1 = false ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( rtDW .
py02jzg13v ) { rtDW . py02jzg13v = false ; rtB . j12to3cpkc = rtP . xs ; }
else { rtB . j12to3cpkc = rtDW . n02axnbajm ; } if ( rtDW . ljhulhsbnj ) {
rtDW . ljhulhsbnj = false ; rtB . howct3x34n = rtP . ys ; } else { rtB .
howct3x34n = rtDW . eyefb11fhu ; } if ( rtDW . ihslb1hbsu ) { rtDW .
ihslb1hbsu = false ; rtB . pkyqj5ymbn = rtP . theta1 ; } else { rtB .
pkyqj5ymbn = rtDW . alw3bg4oqi ; } rtDW . hubufiufje = hppzdqbr3t ; if ( rtB
. j12to3cpkc >= 10.0 ) { u = 0.0 ; } else { u = 0.05 ; } kied35bz3q = rtB .
pkyqj5ymbn + rtDW . cetghxnadh ; trueCount = 0 ; if ( ( kied35bz3q < - 180.0
) || ( kied35bz3q > 180.0 ) ) { for ( i = 0 ; i < 1 ; i ++ ) { trueCount ++ ;
} } if ( trueCount - 1 >= 0 ) { if ( muDoubleScalarIsNaN ( kied35bz3q + 180.0
) || muDoubleScalarIsInf ( kied35bz3q + 180.0 ) ) { absx = ( rtNaN ) ; } else
if ( kied35bz3q + 180.0 == 0.0 ) { absx = 0.0 ; } else { absx =
muDoubleScalarRem ( kied35bz3q + 180.0 , 360.0 ) ; if ( absx == 0.0 ) { absx
= 0.0 ; } else if ( kied35bz3q + 180.0 < 0.0 ) { absx += 360.0 ; } }
varargin_1_data = absx ; } if ( trueCount - 1 >= 0 ) { tmp_data = ( (
varargin_1_data == 0.0 ) && ( kied35bz3q + 180.0 > 0.0 ) ) ; } if ( tmp_data
&& ( trueCount - 1 >= 0 ) ) { varargin_1_data = 360.0 ; } c_idx_0 =
kied35bz3q ; trueCount = 0 ; if ( ( kied35bz3q < - 180.0 ) || ( kied35bz3q >
180.0 ) ) { for ( i = 0 ; i < 1 ; i ++ ) { c_idx_0 = varargin_1_data - 180.0
; trueCount ++ ; } } if ( muDoubleScalarIsInf ( c_idx_0 ) ||
muDoubleScalarIsNaN ( c_idx_0 ) ) { kied35bz3q = ( rtNaN ) ; absx = ( rtNaN )
; } else { kied35bz3q = muDoubleScalarRem ( c_idx_0 , 360.0 ) ; absx =
muDoubleScalarAbs ( kied35bz3q ) ; if ( absx > 180.0 ) { if ( kied35bz3q >
0.0 ) { kied35bz3q -= 360.0 ; } else { kied35bz3q += 360.0 ; } absx =
muDoubleScalarAbs ( kied35bz3q ) ; } if ( absx <= 45.0 ) { kied35bz3q *=
0.017453292519943295 ; kied35bz3q = muDoubleScalarCos ( kied35bz3q ) ; } else
{ guard1 = false ; if ( absx <= 135.0 ) { if ( kied35bz3q > 0.0 ) {
kied35bz3q = ( kied35bz3q - 90.0 ) * 0.017453292519943295 ; kied35bz3q = -
muDoubleScalarSin ( kied35bz3q ) ; } else { kied35bz3q = ( kied35bz3q + 90.0
) * 0.017453292519943295 ; n = - 1 ; guard1 = true ; } } else { if (
kied35bz3q > 0.0 ) { kied35bz3q = ( kied35bz3q - 180.0 ) *
0.017453292519943295 ; n = 2 ; } else { kied35bz3q = ( kied35bz3q + 180.0 ) *
0.017453292519943295 ; n = - 2 ; } guard1 = true ; } if ( guard1 ) { if ( n
== - 1 ) { kied35bz3q = muDoubleScalarSin ( kied35bz3q ) ; } else {
kied35bz3q = - muDoubleScalarCos ( kied35bz3q ) ; } } } absx =
muDoubleScalarRem ( c_idx_0 , 360.0 ) ; b_absx = muDoubleScalarAbs ( absx ) ;
if ( b_absx > 180.0 ) { if ( absx > 0.0 ) { absx -= 360.0 ; } else { absx +=
360.0 ; } b_absx = muDoubleScalarAbs ( absx ) ; } if ( b_absx <= 45.0 ) {
absx *= 0.017453292519943295 ; absx = muDoubleScalarSin ( absx ) ; } else {
guard1 = false ; if ( b_absx <= 135.0 ) { if ( absx > 0.0 ) { absx = ( absx -
90.0 ) * 0.017453292519943295 ; absx = muDoubleScalarCos ( absx ) ; } else {
absx = ( absx + 90.0 ) * 0.017453292519943295 ; n = - 1 ; guard1 = true ; } }
else { if ( absx > 0.0 ) { absx = ( absx - 180.0 ) * 0.017453292519943295 ; n
= 2 ; } else { absx = ( absx + 180.0 ) * 0.017453292519943295 ; n = - 2 ; }
guard1 = true ; } if ( guard1 ) { if ( n == - 1 ) { absx = -
muDoubleScalarCos ( absx ) ; } else { absx = - muDoubleScalarSin ( absx ) ; }
} } } kied35bz3q = u * kied35bz3q * 0.1 + rtB . j12to3cpkc ; absx = u * absx
* 0.1 + rtB . howct3x34n ; rtB . nvmypogeka = kied35bz3q ; rtB . mc1jzs1oyx =
absx ; rtB . etsehycfqw = c_idx_0 ; { if ( rtDW . eqnnjqzwke . AQHandles &&
ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . eqnnjqzwke . AQHandles ,
ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB . nvmypogeka + 0 ) ; } } { if (
rtDW . cxutsucrtu . AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal (
rtDW . cxutsucrtu . AQHandles , ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB
. mc1jzs1oyx + 0 ) ; } } if ( kied35bz3q <= 5.0 ) { i = 0 ; } else if (
kied35bz3q <= 6.0 ) { i = 1 ; } else if ( kied35bz3q <= 7.0 ) { i = 2 ; }
else { i = 3 ; } u = muDoubleScalarMax ( 0.0 , absx - ( real_T ) i ) ; if ( u
> rtP . Sat01_UpperSat ) { u = rtP . Sat01_UpperSat ; } else if ( u < rtP .
Sat01_LowerSat ) { u = rtP . Sat01_LowerSat ; } if ( absx <= 1.0 ) { i = 5 ;
} else if ( absx <= 2.0 ) { i = 6 ; } else if ( absx <= 3.0 ) { i = 7 ; }
else { i = 20 ; } kied35bz3q = muDoubleScalarMax ( 0.0 , ( real_T ) i -
kied35bz3q ) ; if ( kied35bz3q > rtP . Sat01_UpperSat_iihlhhdayd ) {
kied35bz3q = rtP . Sat01_UpperSat_iihlhhdayd ; } else if ( kied35bz3q < rtP .
Sat01_LowerSat_cylljsuqtn ) { kied35bz3q = rtP . Sat01_LowerSat_cylljsuqtn ;
} rtB . nuhns0povx [ 0 ] = u ; rtB . nuhns0povx [ 1 ] = kied35bz3q ; rtB .
nuhns0povx [ 2 ] = rtB . etsehycfqw ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
absx = u ; rtDW . ngupsge0y1 = hppzdqbr3t ; u = 0.0 ; tmp [ 0 ] = -
0.208333333333333 ; tmp [ 1 ] = 0.0 ; tmp [ 2 ] = 0.208333333333333 ;
inputMFCache [ 0 ] = cxthrgce23 ( absx , tmp ) ; inputMFCache [ 1 ] =
cxthrgce23 ( absx , b_p ) ; tmp [ 0 ] = 0.291666666666667 ; tmp [ 1 ] = 0.5 ;
tmp [ 2 ] = 0.708333333333333 ; inputMFCache [ 2 ] = cxthrgce23 ( absx , tmp
) ; tmp [ 0 ] = 0.541666666666667 ; tmp [ 1 ] = 0.75 ; tmp [ 2 ] =
0.958333333333333 ; inputMFCache [ 3 ] = cxthrgce23 ( absx , tmp ) ;
inputMFCache [ 4 ] = cxthrgce23 ( absx , c_p ) ; tmp [ 0 ] = -
0.208333333333333 ; tmp [ 1 ] = 0.0 ; tmp [ 2 ] = 0.208333333333333 ;
inputMFCache [ 5 ] = cxthrgce23 ( kied35bz3q , tmp ) ; inputMFCache [ 6 ] =
cxthrgce23 ( kied35bz3q , b_p ) ; tmp [ 0 ] = 0.291666666666667 ; tmp [ 1 ] =
0.5 ; tmp [ 2 ] = 0.708333333333333 ; inputMFCache [ 7 ] = cxthrgce23 (
kied35bz3q , tmp ) ; tmp [ 0 ] = 0.541666666666667 ; tmp [ 1 ] = 0.75 ; tmp [
2 ] = 0.958333333333333 ; inputMFCache [ 8 ] = cxthrgce23 ( kied35bz3q , tmp
) ; inputMFCache [ 9 ] = cxthrgce23 ( kied35bz3q , c_p ) ; tmp [ 0 ] = -
255.0 ; tmp [ 1 ] = - 180.0 ; tmp [ 2 ] = - 105.0 ; inputMFCache [ 10 ] =
cxthrgce23 ( rtB . etsehycfqw , tmp ) ; tmp [ 0 ] = - 165.0 ; tmp [ 1 ] = -
90.0 ; tmp [ 2 ] = - 15.0 ; inputMFCache [ 11 ] = cxthrgce23 ( rtB .
etsehycfqw , tmp ) ; tmp [ 0 ] = - 75.0 ; tmp [ 1 ] = 0.0 ; tmp [ 2 ] = 75.0
; inputMFCache [ 12 ] = cxthrgce23 ( rtB . etsehycfqw , tmp ) ; tmp [ 0 ] =
15.0 ; tmp [ 1 ] = 90.0 ; tmp [ 2 ] = 165.0 ; inputMFCache [ 13 ] =
cxthrgce23 ( rtB . etsehycfqw , tmp ) ; tmp [ 0 ] = 105.0 ; tmp [ 1 ] = 180.0
; tmp [ 2 ] = 255.0 ; inputMFCache [ 14 ] = cxthrgce23 ( rtB . etsehycfqw ,
tmp ) ; for ( i = 0 ; i < 29 ; i ++ ) { kied35bz3q = 1.0 ; hszrlf2uxv [ i ] =
1.0 ; n = d_p [ i ] ; if ( n != 0 ) { absx = inputMFCache [ n - 1 ] ; if (
absx < 1.0 ) { kied35bz3q = absx ; hszrlf2uxv [ i ] = absx ; } else {
kied35bz3q = 1.0 ; hszrlf2uxv [ i ] = 1.0 ; } } n = d_p [ i + 29 ] ; if ( n
!= 0 ) { absx = inputMFCache [ n + 4 ] ; if ( ( kied35bz3q > absx ) || (
muDoubleScalarIsNaN ( kied35bz3q ) && ( ! muDoubleScalarIsNaN ( absx ) ) ) )
{ kied35bz3q = absx ; hszrlf2uxv [ i ] = absx ; } else { hszrlf2uxv [ i ] =
kied35bz3q ; } } n = d_p [ i + 58 ] ; if ( n != 0 ) { absx = inputMFCache [ n
+ 9 ] ; if ( ( kied35bz3q > absx ) || ( muDoubleScalarIsNaN ( kied35bz3q ) &&
( ! muDoubleScalarIsNaN ( absx ) ) ) ) { kied35bz3q = absx ; hszrlf2uxv [ i ]
= absx ; } else { hszrlf2uxv [ i ] = kied35bz3q ; } } u += kied35bz3q ; }
rtDW . ki33ahdvnp = hppzdqbr3t ; brnn32k1sf ( rtP . OutputSamplePoints_Value
, b , tmp_p ) ; brnn32k1sf ( rtP . OutputSamplePoints_Value , c , tmp_e ) ;
tmp [ 0 ] = - 54.1666666666667 ; tmp [ 1 ] = 0.0 ; tmp [ 2 ] =
54.1666666666667 ; brnn32k1sf ( rtP . OutputSamplePoints_Value , tmp , tmp_i
) ; brnn32k1sf ( rtP . OutputSamplePoints_Value , d , tmp_m ) ; brnn32k1sf (
rtP . OutputSamplePoints_Value , e , tmp_g ) ; for ( i = 0 ; i < 101 ; i ++ )
{ rtB . bjyfjp0f4o [ i ] = 0.0 ; outputMFCache [ 5 * i ] = tmp_p [ i ] ;
outputMFCache [ 5 * i + 1 ] = tmp_e [ i ] ; outputMFCache [ 5 * i + 2 ] =
tmp_i [ i ] ; outputMFCache [ 5 * i + 3 ] = tmp_m [ i ] ; outputMFCache [ 5 *
i + 4 ] = tmp_g [ i ] ; } for ( i = 0 ; i < 29 ; i ++ ) { absx = hszrlf2uxv [
i ] ; for ( trueCount = 0 ; trueCount < 101 ; trueCount ++ ) { b_absx =
outputMFCache [ ( 5 * trueCount + f [ i ] ) - 1 ] ; if ( ( b_absx > absx ) ||
( muDoubleScalarIsNaN ( b_absx ) && ( ! muDoubleScalarIsNaN ( absx ) ) ) ) {
kied35bz3q = absx ; } else { kied35bz3q = b_absx ; } b_absx = rtB .
bjyfjp0f4o [ trueCount ] ; if ( ( b_absx < kied35bz3q ) || (
muDoubleScalarIsNaN ( b_absx ) && ( ! muDoubleScalarIsNaN ( kied35bz3q ) ) )
) { rtB . bjyfjp0f4o [ trueCount ] = kied35bz3q ; } else { rtB . bjyfjp0f4o [
trueCount ] = b_absx ; } } } rtDW . aewedtmiuy = hppzdqbr3t ; if ( u == 0.0 )
{ rtB . jawqhxehe5 = 0.0 ; } else { u = 0.0 ; kied35bz3q = 0.0 ; for ( i = 0
; i < 101 ; i ++ ) { kied35bz3q += rtB . bjyfjp0f4o [ i ] ; } if ( kied35bz3q
== 0.0 ) { rtB . jawqhxehe5 = ( rtP . OutputSamplePoints_Value [ 0 ] + rtP .
OutputSamplePoints_Value [ 100 ] ) / 2.0 ; } else { for ( i = 0 ; i < 101 ; i
++ ) { u += rtP . OutputSamplePoints_Value [ i ] * rtB . bjyfjp0f4o [ i ] ; }
rtB . jawqhxehe5 = 1.0 / kied35bz3q * u ; } } } } UNUSED_PARAMETER ( tid ) ;
} void MdlOutputsTID2 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void
MdlUpdate ( int_T tid ) { if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtDW .
n02axnbajm = rtB . nvmypogeka ; rtDW . eyefb11fhu = rtB . mc1jzs1oyx ; rtDW .
alw3bg4oqi = rtB . etsehycfqw ; rtDW . cetghxnadh = rtB . jawqhxehe5 ; }
UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID2 ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlTerminate ( void ) { { if ( rtDW .
eqnnjqzwke . AQHandles ) { sdiTerminateStreaming ( & rtDW . eqnnjqzwke .
AQHandles ) ; } } { if ( rtDW . cxutsucrtu . AQHandles ) {
sdiTerminateStreaming ( & rtDW . cxutsucrtu . AQHandles ) ; } } } static void
mr_Car_Control_6_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j
, const void * srcData , size_t numBytes ) ; static void
mr_Car_Control_6_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j
, const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_Car_Control_6_restoreDataFromMxArray ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static
void mr_Car_Control_6_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( (
uint8_T * ) destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber (
srcArray , i , j ) ) , numBytes ) ; } static void
mr_Car_Control_6_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i ,
int j , uint_T bitVal ) ; static void mr_Car_Control_6_cacheBitFieldToMxArray
( mxArray * destArray , mwIndex i , int j , uint_T bitVal ) {
mxSetFieldByNumber ( destArray , i , j , mxCreateDoubleScalar ( ( real_T )
bitVal ) ) ; } static uint_T mr_Car_Control_6_extractBitFieldFromMxArray (
const mxArray * srcArray , mwIndex i , int j , uint_T numBits ) ; static
uint_T mr_Car_Control_6_extractBitFieldFromMxArray ( const mxArray * srcArray
, mwIndex i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T )
mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( (
1u << numBits ) - 1u ) ; } static void
mr_Car_Control_6_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex
i , int j , mwIndex offset , const void * srcData , size_t numBytes ) ;
static void mr_Car_Control_6_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_Car_Control_6_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) ; static void mr_Car_Control_6_restoreDataFromMxArrayWithOffset (
void * destData , const mxArray * srcArray , mwIndex i , int j , mwIndex
offset , size_t numBytes ) { const uint8_T * varData = ( const uint8_T * )
mxGetData ( mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T *
) destData , ( const uint8_T * ) & varData [ offset * numBytes ] , numBytes )
; } static void mr_Car_Control_6_cacheBitFieldToCellArrayWithOffset ( mxArray
* destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static
void mr_Car_Control_6_cacheBitFieldToCellArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) {
mxSetCell ( mxGetFieldByNumber ( destArray , i , j ) , offset ,
mxCreateDoubleScalar ( ( real_T ) fieldVal ) ) ; } static uint_T
mr_Car_Control_6_extractBitFieldFromCellArrayWithOffset ( const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static
uint_T mr_Car_Control_6_extractBitFieldFromCellArrayWithOffset ( const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) {
const uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell (
mxGetFieldByNumber ( srcArray , i , j ) , offset ) ) ; return fieldVal & ( (
1u << numBits ) - 1u ) ; } mxArray * mr_Car_Control_6_GetDWork ( ) { static
const char_T * ssDWFieldNames [ 3 ] = { "rtB" , "rtDW" , "NULL_PrevZCX" , } ;
mxArray * ssDW = mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_Car_Control_6_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) & ( rtB
) , sizeof ( rtB ) ) ; { static const char_T * rtdwDataFieldNames [ 19 ] = {
"rtDW.n02axnbajm" , "rtDW.eyefb11fhu" , "rtDW.alw3bg4oqi" , "rtDW.cetghxnadh"
, "rtDW.hubufiufje" , "rtDW.ki33ahdvnp" , "rtDW.ngupsge0y1" ,
"rtDW.aewedtmiuy" , "rtDW.ipetmw5xox" , "rtDW.i0xmzrx5tb" , "rtDW.ikoa0bflnt"
, "rtDW.n3regh311s" , "rtDW.py02jzg13v" , "rtDW.ljhulhsbnj" ,
"rtDW.ihslb1hbsu" , "rtDW.oue4u1fsup" , "rtDW.amqcyfju03" , "rtDW.jb0y2agf4z"
, "rtDW.llkgqs04uq" , } ; mxArray * rtdwData = mxCreateStructMatrix ( 1 , 1 ,
19 , rtdwDataFieldNames ) ; mr_Car_Control_6_cacheDataAsMxArray ( rtdwData ,
0 , 0 , ( const void * ) & ( rtDW . n02axnbajm ) , sizeof ( rtDW . n02axnbajm
) ) ; mr_Car_Control_6_cacheDataAsMxArray ( rtdwData , 0 , 1 , ( const void *
) & ( rtDW . eyefb11fhu ) , sizeof ( rtDW . eyefb11fhu ) ) ;
mr_Car_Control_6_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void * ) & (
rtDW . alw3bg4oqi ) , sizeof ( rtDW . alw3bg4oqi ) ) ;
mr_Car_Control_6_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const void * ) & (
rtDW . cetghxnadh ) , sizeof ( rtDW . cetghxnadh ) ) ;
mr_Car_Control_6_cacheDataAsMxArray ( rtdwData , 0 , 4 , ( const void * ) & (
rtDW . hubufiufje ) , sizeof ( rtDW . hubufiufje ) ) ;
mr_Car_Control_6_cacheDataAsMxArray ( rtdwData , 0 , 5 , ( const void * ) & (
rtDW . ki33ahdvnp ) , sizeof ( rtDW . ki33ahdvnp ) ) ;
mr_Car_Control_6_cacheDataAsMxArray ( rtdwData , 0 , 6 , ( const void * ) & (
rtDW . ngupsge0y1 ) , sizeof ( rtDW . ngupsge0y1 ) ) ;
mr_Car_Control_6_cacheDataAsMxArray ( rtdwData , 0 , 7 , ( const void * ) & (
rtDW . aewedtmiuy ) , sizeof ( rtDW . aewedtmiuy ) ) ;
mr_Car_Control_6_cacheDataAsMxArray ( rtdwData , 0 , 8 , ( const void * ) & (
rtDW . ipetmw5xox ) , sizeof ( rtDW . ipetmw5xox ) ) ;
mr_Car_Control_6_cacheDataAsMxArray ( rtdwData , 0 , 9 , ( const void * ) & (
rtDW . i0xmzrx5tb ) , sizeof ( rtDW . i0xmzrx5tb ) ) ;
mr_Car_Control_6_cacheDataAsMxArray ( rtdwData , 0 , 10 , ( const void * ) &
( rtDW . ikoa0bflnt ) , sizeof ( rtDW . ikoa0bflnt ) ) ;
mr_Car_Control_6_cacheDataAsMxArray ( rtdwData , 0 , 11 , ( const void * ) &
( rtDW . n3regh311s ) , sizeof ( rtDW . n3regh311s ) ) ;
mr_Car_Control_6_cacheDataAsMxArray ( rtdwData , 0 , 12 , ( const void * ) &
( rtDW . py02jzg13v ) , sizeof ( rtDW . py02jzg13v ) ) ;
mr_Car_Control_6_cacheDataAsMxArray ( rtdwData , 0 , 13 , ( const void * ) &
( rtDW . ljhulhsbnj ) , sizeof ( rtDW . ljhulhsbnj ) ) ;
mr_Car_Control_6_cacheDataAsMxArray ( rtdwData , 0 , 14 , ( const void * ) &
( rtDW . ihslb1hbsu ) , sizeof ( rtDW . ihslb1hbsu ) ) ;
mr_Car_Control_6_cacheDataAsMxArray ( rtdwData , 0 , 15 , ( const void * ) &
( rtDW . oue4u1fsup ) , sizeof ( rtDW . oue4u1fsup ) ) ;
mr_Car_Control_6_cacheDataAsMxArray ( rtdwData , 0 , 16 , ( const void * ) &
( rtDW . amqcyfju03 ) , sizeof ( rtDW . amqcyfju03 ) ) ;
mr_Car_Control_6_cacheDataAsMxArray ( rtdwData , 0 , 17 , ( const void * ) &
( rtDW . jb0y2agf4z ) , sizeof ( rtDW . jb0y2agf4z ) ) ;
mr_Car_Control_6_cacheDataAsMxArray ( rtdwData , 0 , 18 , ( const void * ) &
( rtDW . llkgqs04uq ) , sizeof ( rtDW . llkgqs04uq ) ) ; mxSetFieldByNumber (
ssDW , 0 , 1 , rtdwData ) ; } return ssDW ; } void mr_Car_Control_6_SetDWork
( const mxArray * ssDW ) { ( void ) ssDW ;
mr_Car_Control_6_restoreDataFromMxArray ( ( void * ) & ( rtB ) , ssDW , 0 , 0
, sizeof ( rtB ) ) ; { const mxArray * rtdwData = mxGetFieldByNumber ( ssDW ,
0 , 1 ) ; mr_Car_Control_6_restoreDataFromMxArray ( ( void * ) & ( rtDW .
n02axnbajm ) , rtdwData , 0 , 0 , sizeof ( rtDW . n02axnbajm ) ) ;
mr_Car_Control_6_restoreDataFromMxArray ( ( void * ) & ( rtDW . eyefb11fhu )
, rtdwData , 0 , 1 , sizeof ( rtDW . eyefb11fhu ) ) ;
mr_Car_Control_6_restoreDataFromMxArray ( ( void * ) & ( rtDW . alw3bg4oqi )
, rtdwData , 0 , 2 , sizeof ( rtDW . alw3bg4oqi ) ) ;
mr_Car_Control_6_restoreDataFromMxArray ( ( void * ) & ( rtDW . cetghxnadh )
, rtdwData , 0 , 3 , sizeof ( rtDW . cetghxnadh ) ) ;
mr_Car_Control_6_restoreDataFromMxArray ( ( void * ) & ( rtDW . hubufiufje )
, rtdwData , 0 , 4 , sizeof ( rtDW . hubufiufje ) ) ;
mr_Car_Control_6_restoreDataFromMxArray ( ( void * ) & ( rtDW . ki33ahdvnp )
, rtdwData , 0 , 5 , sizeof ( rtDW . ki33ahdvnp ) ) ;
mr_Car_Control_6_restoreDataFromMxArray ( ( void * ) & ( rtDW . ngupsge0y1 )
, rtdwData , 0 , 6 , sizeof ( rtDW . ngupsge0y1 ) ) ;
mr_Car_Control_6_restoreDataFromMxArray ( ( void * ) & ( rtDW . aewedtmiuy )
, rtdwData , 0 , 7 , sizeof ( rtDW . aewedtmiuy ) ) ;
mr_Car_Control_6_restoreDataFromMxArray ( ( void * ) & ( rtDW . ipetmw5xox )
, rtdwData , 0 , 8 , sizeof ( rtDW . ipetmw5xox ) ) ;
mr_Car_Control_6_restoreDataFromMxArray ( ( void * ) & ( rtDW . i0xmzrx5tb )
, rtdwData , 0 , 9 , sizeof ( rtDW . i0xmzrx5tb ) ) ;
mr_Car_Control_6_restoreDataFromMxArray ( ( void * ) & ( rtDW . ikoa0bflnt )
, rtdwData , 0 , 10 , sizeof ( rtDW . ikoa0bflnt ) ) ;
mr_Car_Control_6_restoreDataFromMxArray ( ( void * ) & ( rtDW . n3regh311s )
, rtdwData , 0 , 11 , sizeof ( rtDW . n3regh311s ) ) ;
mr_Car_Control_6_restoreDataFromMxArray ( ( void * ) & ( rtDW . py02jzg13v )
, rtdwData , 0 , 12 , sizeof ( rtDW . py02jzg13v ) ) ;
mr_Car_Control_6_restoreDataFromMxArray ( ( void * ) & ( rtDW . ljhulhsbnj )
, rtdwData , 0 , 13 , sizeof ( rtDW . ljhulhsbnj ) ) ;
mr_Car_Control_6_restoreDataFromMxArray ( ( void * ) & ( rtDW . ihslb1hbsu )
, rtdwData , 0 , 14 , sizeof ( rtDW . ihslb1hbsu ) ) ;
mr_Car_Control_6_restoreDataFromMxArray ( ( void * ) & ( rtDW . oue4u1fsup )
, rtdwData , 0 , 15 , sizeof ( rtDW . oue4u1fsup ) ) ;
mr_Car_Control_6_restoreDataFromMxArray ( ( void * ) & ( rtDW . amqcyfju03 )
, rtdwData , 0 , 16 , sizeof ( rtDW . amqcyfju03 ) ) ;
mr_Car_Control_6_restoreDataFromMxArray ( ( void * ) & ( rtDW . jb0y2agf4z )
, rtdwData , 0 , 17 , sizeof ( rtDW . jb0y2agf4z ) ) ;
mr_Car_Control_6_restoreDataFromMxArray ( ( void * ) & ( rtDW . llkgqs04uq )
, rtdwData , 0 , 18 , sizeof ( rtDW . llkgqs04uq ) ) ; } } mxArray *
mr_Car_Control_6_GetSimStateDisallowedBlocks ( ) { return ( NULL ) ; } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 0 ) ; ssSetNumY (
rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ;
ssSetNumSampleTimes ( rtS , 2 ) ; ssSetNumBlocks ( rtS , 25 ) ;
ssSetNumBlockIO ( rtS , 13 ) ; ssSetNumBlockParams ( rtS , 112 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 0.1 ) ; ssSetOffsetTime ( rtS , 0 , 1.0 ) ;
ssSetOffsetTime ( rtS , 1 , 0.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 4034232522U ) ; ssSetChecksumVal ( rtS , 1 ,
206379067U ) ; ssSetChecksumVal ( rtS , 2 , 2960214353U ) ; ssSetChecksumVal
( rtS , 3 , 3051646076U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; static struct _ssBlkInfo2 blkInfo2 ;
static struct _ssBlkInfoSLSize blkInfoSLSize ; ( void ) memset ( ( char_T * )
rtS , 0 , sizeof ( SimStruct ) ) ; ( void ) memset ( ( char_T * ) & mdlInfo ,
0 , sizeof ( struct _ssMdlInfo ) ) ; ( void ) memset ( ( char_T * ) &
blkInfo2 , 0 , sizeof ( struct _ssBlkInfo2 ) ) ; ( void ) memset ( ( char_T *
) & blkInfoSLSize , 0 , sizeof ( struct _ssBlkInfoSLSize ) ) ;
ssSetBlkInfo2Ptr ( rtS , & blkInfo2 ) ; ssSetBlkInfoSLSizePtr ( rtS , &
blkInfoSLSize ) ; ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; ssSetExecutionInfo (
rtS , executionInfo ) ; slsaAllocOPModelData ( rtS ) ; { static time_T
mdlPeriod [ NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ;
static time_T mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [
NSAMPLE_TIMES ] ; static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static
boolean_T mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T
mdlPerTaskSampleHits [ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T
mdlTimeOfNextSampleHit [ NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i <
NSAMPLE_TIMES ; i ++ ) { mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ;
mdlTaskTimes [ i ] = 0.0 ; mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } }
ssSetSampleTimePtr ( rtS , & mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , &
mdlOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ;
ssSetTPtr ( rtS , & mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , &
mdlSampleHits [ 0 ] ) ; ssSetTNextWasAdjustedPtr ( rtS , &
mdlTNextWasAdjustedPtr [ 0 ] ) ; ssSetPerTaskSampleHitsPtr ( rtS , &
mdlPerTaskSampleHits [ 0 ] ) ; ssSetTimeOfNextSampleHitPtr ( rtS , &
mdlTimeOfNextSampleHit [ 0 ] ) ; } ssSetSolverMode ( rtS ,
SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS , ( ( void * ) & rtB ) ) ;
( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof ( B ) ) ; } { void *
dwork = ( void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset
( dwork , 0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void
) memset ( ( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ;
ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo . numDataTypes = 27 ;
dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = &
rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = & rtBTransTable ; dtInfo .
PTransTable = & rtPTransTable ; dtInfo . dataTypeInfoTable =
rtDataTypeInfoTable ; } Car_Control_6_InitializeDataMapInfo ( ) ;
ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"Car_Control_6" ) ; ssSetPath ( rtS , "Car_Control_6" ) ; ssSetTStart ( rtS ,
0.0 ) ; ssSetTFinal ( rtS , 120.0 ) ; { static RTWLogInfo rt_DataLoggingInfo
; rt_DataLoggingInfo . loggingInterval = ( NULL ) ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 1 , 1
, 1 , 1 } ; static int_T rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 , 1 }
; static int_T rt_LoggedStateDimensions [ ] = { 1 , 1 , 1 , 1 } ; static
boolean_T rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 } ; static
BuiltInDTypeId rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE } ; static int_T rt_LoggedStateComplexSignals [ ] = { 0
, 0 , 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) } ; static const char_T * rt_LoggedStateLabels [ ] = { "DSTATE" ,
"DSTATE" , "DSTATE" , "DSTATE" } ; static const char_T *
rt_LoggedStateBlockNames [ ] = { "Car_Control_6/Delay X" ,
"Car_Control_6/Delay Y" , "Car_Control_6/Delay theta" ,
"Car_Control_6/Delay dtheta" } ; static const char_T * rt_LoggedStateNames [
] = { "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" } ; static boolean_T
rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 } ; static
RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static
int_T rt_LoggedStateIdxList [ ] = { 0 , 1 , 2 , 3 } ; static RTWLogSignalInfo
rt_LoggedStateSignalInfo = { 4 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 4 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtDW . n02axnbajm ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtDW . eyefb11fhu ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtDW . alw3bg4oqi ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtDW . cetghxnadh ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"xFinal" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
ssSolverInfo slvrInfo ; ssSetStepSize ( rtS , 0.1 ) ; ssSetMinStepSize ( rtS
, 0.0 ) ; ssSetMaxNumMinSteps ( rtS , - 1 ) ; ssSetMinStepViolatedError ( rtS
, 0 ) ; ssSetMaxStepSize ( rtS , 0.1 ) ; ssSetSolverMaxOrder ( rtS , - 1 ) ;
ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , ( NULL ) ) ;
ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 ) ;
ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 0 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
0 ) ; ssSetNonContDerivSigInfos ( rtS , ( NULL ) ) ; ssSetSolverInfo ( rtS ,
& slvrInfo ) ; ssSetSolverName ( rtS , "VariableStepDiscrete" ) ;
ssSetVariableStepSolver ( rtS , 1 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetSolverStateProjection ( rtS ,
0 ) ; ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetTNextTid ( rtS , INT_MIN ) ;
ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; } ssSetChecksumVal ( rtS , 0 ,
4034232522U ) ; ssSetChecksumVal ( rtS , 1 , 206379067U ) ; ssSetChecksumVal
( rtS , 2 , 2960214353U ) ; ssSetChecksumVal ( rtS , 3 , 3051646076U ) ; {
static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static
RTWExtModeInfo rt_ExtModeInfo ; static const sysRanDType * systemRan [ 6 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = &
rtAlwaysEnabled ; systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = &
rtAlwaysEnabled ; systemRan [ 4 ] = & rtAlwaysEnabled ; systemRan [ 5 ] = &
rtAlwaysEnabled ; rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) ,
& ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo
( rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS
) , ssGetTPtr ( rtS ) ) ; } slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_Car_Control_6_GetSimStateDisallowedBlocks ) ; slsaGetWorkFcnForSimTargetOP
( rtS , mr_Car_Control_6_GetDWork ) ; slsaSetWorkFcnForSimTargetOP ( rtS ,
mr_Car_Control_6_SetDWork ) ; rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if
( ssGetErrorStatus ( rtS ) ) { return rtS ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 2 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID2 ( tid ) ; }
