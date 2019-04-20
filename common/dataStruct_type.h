/**
  ******************************************************************************
  * @file    dataStruct_type.h
  * @author  CGR
  * @version V1.0.0
  * @date    2018-9-1
  * @brief   数据结构自定义的类型
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DATASTRUCT_TYPE_H
#define __DATASTRUCT_TYPE_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stdlib.h"
#include <stdio.h>
#include <string.h>

/** @addtogroup DataStruct_Driver
  * @{
  */

/** @addtogroup type
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup 数据结构中的扩展类型
  * @{
  */ 

/** 
  * @brief 长度的扩展类型
  */ 
typedef int len_t;
typedef int ElemType; 
typedef unsigned char uint8_t;
typedef unsigned int uint32_t;
typedef unsigned long uint64_t;

/** 
  * @brief 函数状态返回标志
  */ 
typedef enum
{
    DS_OK = 0,
    DS_PARM_ERROR,          /* 参数错误 */
    DS_RAM_ERROR,           /* 内存错误 */
    DS_RAM_FULL,            /* 内存满了 */
    DS_RAM_EMPTY,           /* 空的 */
    DS_TRUE,
    DS_FALSE,
}DataStruct_Status;

/**
  * @}
  */


/* Exported constants --------------------------------------------------------*/


/* Exported macro ------------------------------------------------------------*/
#define     BUF_MAX_SIZE   1024

/* Exported functions --------------------------------------------------------*/ 


/**
  * @}
  */

/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* __DATASTRUCT_TYPE_H */

/******************* (C) HOME 2018 深圳龙华 *****END OF FILE****/
