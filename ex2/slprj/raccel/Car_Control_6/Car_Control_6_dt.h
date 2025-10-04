#include "ext_types.h"
static DataTypeInfo rtDataTypeInfoTable [ ] = { { "real_T" , 0 , 8 } , {
"real32_T" , 1 , 4 } , { "int8_T" , 2 , 1 } , { "uint8_T" , 3 , 1 } , {
"int16_T" , 4 , 2 } , { "uint16_T" , 5 , 2 } , { "int32_T" , 6 , 4 } , {
"uint32_T" , 7 , 4 } , { "boolean_T" , 8 , 1 } , { "fcn_call_T" , 9 , 0 } , {
"int_T" , 10 , 4 } , { "pointer_T" , 11 , 8 } , { "action_T" , 12 , 8 } , {
"timer_uint32_pair_T" , 13 , 8 } , { "physical_connection" , 14 , 8 } , {
"int64_T" , 15 , 8 } , { "uint64_T" , 16 , 8 } , {
"struct_b3A3OrYrb6uy8T16ryln0F" , 17 , 120 } , {
"struct_RCP1oovUDF2zF6C9vcJmtG" , 18 , 48 } , {
"struct_FOoMlVQ4d9OgoZkrIa8vkE" , 19 , 248 } , {
"struct_scgDIFPaIpjnRc0Z0eJLIC" , 20 , 3384 } , { "uint64_T" , 21 , 8 } , {
"int64_T" , 22 , 8 } , { "uint_T" , 23 , 32 } , { "char_T" , 24 , 8 } , {
"uchar_T" , 25 , 8 } , { "time_T" , 26 , 8 } } ; static uint_T
rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T ) , sizeof (
int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof ( uint16_T ) ,
sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T ) , sizeof (
fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T ) , sizeof ( action_T )
, 2 * sizeof ( uint32_T ) , sizeof ( int32_T ) , sizeof ( int64_T ) , sizeof
( uint64_T ) , sizeof ( struct_b3A3OrYrb6uy8T16ryln0F ) , sizeof (
struct_RCP1oovUDF2zF6C9vcJmtG ) , sizeof ( struct_FOoMlVQ4d9OgoZkrIa8vkE ) ,
sizeof ( struct_scgDIFPaIpjnRc0Z0eJLIC ) , sizeof ( uint64_T ) , sizeof (
int64_T ) , sizeof ( uint_T ) , sizeof ( char_T ) , sizeof ( uchar_T ) ,
sizeof ( time_T ) } ; static const char_T * rtDataTypeNames [ ] = { "real_T"
, "real32_T" , "int8_T" , "uint8_T" , "int16_T" , "uint16_T" , "int32_T" ,
"uint32_T" , "boolean_T" , "fcn_call_T" , "int_T" , "pointer_T" , "action_T"
, "timer_uint32_pair_T" , "physical_connection" , "int64_T" , "uint64_T" ,
"struct_b3A3OrYrb6uy8T16ryln0F" , "struct_RCP1oovUDF2zF6C9vcJmtG" ,
"struct_FOoMlVQ4d9OgoZkrIa8vkE" , "struct_scgDIFPaIpjnRc0Z0eJLIC" ,
"uint64_T" , "int64_T" , "uint_T" , "char_T" , "uchar_T" , "time_T" } ;
static DataTypeTransition rtBTransitions [ ] = { { ( char_T * ) ( & rtB .
j12to3cpkc ) , 0 , 0 , 111 } , { ( char_T * ) ( & rtDW . n02axnbajm ) , 0 , 0
, 4 } , { ( char_T * ) ( & rtDW . eqnnjqzwke . AQHandles ) , 11 , 0 , 2 } , {
( char_T * ) ( & rtDW . hubufiufje ) , 6 , 0 , 4 } , { ( char_T * ) ( & rtDW
. ipetmw5xox ) , 3 , 0 , 4 } , { ( char_T * ) ( & rtDW . py02jzg13v ) , 8 , 0
, 7 } } ; static DataTypeTransitionTable rtBTransTable = { 6U ,
rtBTransitions } ; static DataTypeTransition rtPTransitions [ ] = { { (
char_T * ) ( & rtP . theta1 ) , 0 , 0 , 112 } } ; static
DataTypeTransitionTable rtPTransTable = { 1U , rtPTransitions } ;
