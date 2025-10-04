#ifndef RTW_HEADER_Car_Control_6_types_h_
#define RTW_HEADER_Car_Control_6_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_b3A3OrYrb6uy8T16ryln0F_
#define DEFINED_TYPEDEF_FOR_struct_b3A3OrYrb6uy8T16ryln0F_
typedef struct { uint8_T SimulinkDiagnostic ; uint8_T Model [ 43 ] ; uint8_T
Block [ 66 ] ; uint8_T OutOfRangeInputValue ; uint8_T NoRuleFired ; uint8_T
EmptyOutputFuzzySet ; uint8_T sl_padding0 [ 7 ] ; }
struct_b3A3OrYrb6uy8T16ryln0F ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_RCP1oovUDF2zF6C9vcJmtG_
#define DEFINED_TYPEDEF_FOR_struct_RCP1oovUDF2zF6C9vcJmtG_
typedef struct { uint8_T type [ 5 ] ; uint8_T sl_padding0 [ 3 ] ; int32_T
origTypeLength ; uint8_T sl_padding1 [ 4 ] ; real_T params [ 3 ] ; int32_T
origParamLength ; uint8_T sl_padding2 [ 4 ] ; } struct_RCP1oovUDF2zF6C9vcJmtG
;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_FOoMlVQ4d9OgoZkrIa8vkE_
#define DEFINED_TYPEDEF_FOR_struct_FOoMlVQ4d9OgoZkrIa8vkE_
typedef struct { struct_RCP1oovUDF2zF6C9vcJmtG mf [ 5 ] ; int32_T origNumMF ;
uint8_T sl_padding0 [ 4 ] ; } struct_FOoMlVQ4d9OgoZkrIa8vkE ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_scgDIFPaIpjnRc0Z0eJLIC_
#define DEFINED_TYPEDEF_FOR_struct_scgDIFPaIpjnRc0Z0eJLIC_
typedef struct { uint8_T type [ 7 ] ; uint8_T andMethod [ 3 ] ; uint8_T
orMethod [ 3 ] ; uint8_T defuzzMethod [ 8 ] ; uint8_T impMethod [ 3 ] ;
uint8_T aggMethod [ 3 ] ; uint8_T sl_padding0 [ 5 ] ; real_T inputRange [ 6 ]
; real_T outputRange [ 2 ] ; struct_FOoMlVQ4d9OgoZkrIa8vkE inputMF [ 3 ] ;
struct_FOoMlVQ4d9OgoZkrIa8vkE outputMF ; real_T antecedent [ 87 ] ; real_T
consequent [ 29 ] ; real_T connection [ 29 ] ; real_T weight [ 29 ] ; int32_T
numSamples ; int32_T numInputs ; int32_T numOutputs ; int32_T numRules ;
int32_T numInputMFs [ 3 ] ; int32_T numCumInputMFs [ 3 ] ; int32_T
numOutputMFs ; int32_T numCumOutputMFs ; real_T outputSamplePoints [ 101 ] ;
int32_T orrSize [ 2 ] ; int32_T aggSize [ 2 ] ; int32_T irrSize [ 2 ] ;
int32_T rfsSize [ 2 ] ; int32_T sumSize [ 2 ] ; int32_T inputFuzzySetType ;
uint8_T sl_padding1 [ 4 ] ; } struct_scgDIFPaIpjnRc0Z0eJLIC ;
#endif
#ifndef SS_UINT64
#define SS_UINT64 21
#endif
#ifndef SS_INT64
#define SS_INT64 22
#endif
typedef struct P_ P ;
#endif
