#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "Car_Control_6_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 21
#endif
#ifndef SS_INT64
#define SS_INT64 22
#endif
#else
#include "builtin_typeid_types.h"
#include "Car_Control_6.h"
#include "Car_Control_6_capi.h"
#include "Car_Control_6_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 5 , TARGET_STRING (
"Car_Control_6/MATLAB Function" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0
} , { 1 , 5 , TARGET_STRING ( "Car_Control_6/MATLAB Function" ) ,
TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 2 , 5 , TARGET_STRING (
"Car_Control_6/MATLAB Function" ) , TARGET_STRING ( "" ) , 2 , 0 , 0 , 0 , 0
} , { 3 , 0 , TARGET_STRING (
"Car_Control_6/MATLAB Function/is_active_c2_Car_Control_6" ) , TARGET_STRING
( "is_active_c2_Car_Control_6" ) , 0 , 1 , 0 , 0 , 0 } , { 4 , 0 ,
TARGET_STRING ( "Car_Control_6/initial X" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 0 } , { 5 , 0 , TARGET_STRING ( "Car_Control_6/initial Y" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 6 , 0 , TARGET_STRING (
"Car_Control_6/initial theta" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 }
, { 7 , 1 , TARGET_STRING (
"Car_Control_6/Fuzzy Logic  Controller (FLC)/Fuzzy Logic Controller" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 8 , 0 , TARGET_STRING (
"Car_Control_6/Fuzzy Logic  Controller (FLC)/Zero-Order Hold" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 9 , 1 , TARGET_STRING (
 "Car_Control_6/Fuzzy Logic  Controller (FLC)/Fuzzy Logic Controller/Defuzzify Outputs"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 10 , 0 , TARGET_STRING (
 "Car_Control_6/Fuzzy Logic  Controller (FLC)/Fuzzy Logic Controller/Defuzzify Outputs/is_active_c14_fuzwiz"
) , TARGET_STRING ( "is_active_c14_fuzwiz" ) , 0 , 1 , 0 , 0 , 0 } , { 11 , 0
, TARGET_STRING (
 "Car_Control_6/Fuzzy Logic  Controller (FLC)/Fuzzy Logic Controller/Evaluate Rule Antecedents/is_active_c11_fuzwiz"
) , TARGET_STRING ( "is_active_c11_fuzwiz" ) , 0 , 1 , 0 , 0 , 0 } , { 12 , 3
, TARGET_STRING (
 "Car_Control_6/Fuzzy Logic  Controller (FLC)/Fuzzy Logic Controller/Evaluate Rule Consequents"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 13 , 0 , TARGET_STRING (
 "Car_Control_6/Fuzzy Logic  Controller (FLC)/Fuzzy Logic Controller/Evaluate Rule Consequents/is_active_c15_fuzwiz"
) , TARGET_STRING ( "is_active_c15_fuzwiz" ) , 0 , 1 , 0 , 0 , 0 } , { 0 , 0
, ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 14 , TARGET_STRING (
"Car_Control_6/Sat [0 1]" ) , TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } ,
{ 15 , TARGET_STRING ( "Car_Control_6/Sat [0 1]" ) , TARGET_STRING (
"LowerLimit" ) , 0 , 0 , 0 } , { 16 , TARGET_STRING (
"Car_Control_6/Sat[0 1]" ) , TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , {
17 , TARGET_STRING ( "Car_Control_6/Sat[0 1]" ) , TARGET_STRING (
"LowerLimit" ) , 0 , 0 , 0 } , { 18 , TARGET_STRING ( "Car_Control_6/Delay X"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 19 , TARGET_STRING
( "Car_Control_6/Delay Y" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 ,
0 } , { 20 , TARGET_STRING ( "Car_Control_6/Delay dtheta" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 21 , TARGET_STRING (
"Car_Control_6/Delay theta" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 0
, 0 } , { 22 , TARGET_STRING (
 "Car_Control_6/Fuzzy Logic  Controller (FLC)/Fuzzy Logic Controller/Output Sample Points"
) , TARGET_STRING ( "Value" ) , 0 , 3 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 ,
0 , 0 } } ; static int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static const
rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 , 0 , 0 } } ; static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0 , 0 ,
( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 23 , TARGET_STRING (
"theta1" ) , 0 , 0 , 0 } , { 24 , TARGET_STRING ( "xs" ) , 0 , 0 , 0 } , { 25
, TARGET_STRING ( "ys" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . nvmypogeka , & rtB . mc1jzs1oyx ,
& rtB . etsehycfqw , & rtDW . ipetmw5xox , & rtB . j12to3cpkc , & rtB .
howct3x34n , & rtB . pkyqj5ymbn , & rtB . jawqhxehe5 , & rtB . nuhns0povx [ 0
] , & rtB . jawqhxehe5 , & rtDW . n3regh311s , & rtDW . ikoa0bflnt , & rtB .
bjyfjp0f4o [ 0 ] , & rtDW . i0xmzrx5tb , & rtP . Sat01_UpperSat , & rtP .
Sat01_LowerSat , & rtP . Sat01_UpperSat_iihlhhdayd , & rtP .
Sat01_LowerSat_cylljsuqtn , & rtP . DelayX_InitialCondition , & rtP .
DelayY_InitialCondition , & rtP . Delaydtheta_InitialCondition , & rtP .
Delaytheta_InitialCondition , & rtP . OutputSamplePoints_Value [ 0 ] , & rtP
. theta1 , & rtP . xs , & rtP . ys , } ; static int32_T * rtVarDimsAddrMap [
] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } ,
{ "unsigned char" , "uint8_T" , 0 , 0 , sizeof ( uint8_T ) , ( uint8_T )
SS_UINT8 , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } } ;
static const uint_T rtDimensionArray [ ] = { 1 , 1 , 3 , 1 , 101 , 1 , 1 ,
101 } ; static const real_T rtcapiStoredFloats [ ] = { 0.1 , 0.0 } ; static
const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0 } , } ; static const
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , (
int8_T ) 1 , ( uint8_T ) 0 } } ; static rtwCAPI_ModelMappingStaticInfo
mmiStatic = { { rtBlockSignals , 14 , rtRootInputs , 0 , rtRootOutputs , 0 }
, { rtBlockParameters , 9 , rtModelParameters , 3 } , { ( NULL ) , 0 } , {
rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap
, rtDimensionArray } , "float" , { 4034232522U , 206379067U , 2960214353U ,
3051646076U } , ( NULL ) , 0 , ( boolean_T ) 0 , rt_LoggedStateIdxList } ;
const rtwCAPI_ModelMappingStaticInfo * Car_Control_6_GetCAPIStaticMap ( void
) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void Car_Control_6_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void Car_Control_6_host_InitializeDataMapInfo (
Car_Control_6_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetPath ( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap ->
mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
