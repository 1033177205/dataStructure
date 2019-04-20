/**
  ******************************************************************************
  * @file    Arithmetic.h
  * @author  chen
  * @version V1.0.0
  * @date    2018-10-27
  * @brief   四则运算表达式求值
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ARITHMETIC_H
#define __ARITHMETIC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "dataStruct_type.h"

/** @addtogroup DataStruct_Driver
  * @{
  */

/** @addtogroup Arithmetic
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup 
  * @{
  */ 



/**
  * @}
  */


/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/ 
/* Initialization and de-initialization functions *******************************/
/** @addtogroup Arithmetic_Exported_Functions
  * @{
  */

/** @addtogroup Arithmetic_Exported_Functions_Group1
  * @{
  */
int8_t Arithmetic_init(void);

/**
  * @}
  */

/* operation functions *******************************************************/
/** @addtogroup Arithmetic_Exported_Functions_Group2
  * @{
  */
len_t Arithmetic_InfixExpressionToPostfixExpression(const char *src, char *reault, len_t len);


/**
  * @}
  */

/**
  * @}
  */ 

/**
  * @}
  */

/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* __ARITHMETIC_H */

/******************* (C) HOME 2018 深圳龙华 *****END OF FILE****/

