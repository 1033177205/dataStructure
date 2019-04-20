/**
  ******************************************************************************
  * @file    static_linklist.h
  * @author  CGR
  * @version V1.0.0
  * @date    2018-9-24
  * @brief   静态链表的头文件
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STATIC_LINKLIST_H
#define __STATIC_LINKLIST_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "dataStruct_type.h"

/** @addtogroup DataStruct_Driver
  * @{
  */

/** @addtogroup static_linklist
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup 静态链表中的的扩展类型
  * @{
  */ 

/** 
  * @brief 静态链表中的数据类型
  */ 
#define STATIC_LINKLIST_MAXSIZE     1000
typedef  struct
{
    ElemType data;
    len_t cur;              /* 游标 */
}STATIC_LINKLIST[STATIC_LINKLIST_MAXSIZE];

/**
  * @}
  */


/* Exported constants --------------------------------------------------------*/


/* Exported macro ------------------------------------------------------------*/


/* Exported functions --------------------------------------------------------*/ 
/* Initialization and de-initialization functions *******************************/
/** @addtogroup listArray_Exported_Functions
  * @{
  */

/** @addtogroup listArray_Exported_Functions_Group1
  * @{
  */
DataStruct_Status Static_Linklist_Init(STATIC_LINKLIST space);

/**
  * @}
  */

/* operation functions *******************************************************/
/** @addtogroup listArray_Exported_Functions_Group2
  * @{
  */
int Static_Linklist_length(STATIC_LINKLIST L);
DataStruct_Status Static_Linklist_Insert(STATIC_LINKLIST L, len_t i, ElemType e);
DataStruct_Status Static_Linklist_Delete(STATIC_LINKLIST L, len_t i);
void Static_Linklist_bianli(STATIC_LINKLIST L);

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

#endif /* __STATIC_LINKLIST_H */

/******************* (C) HOME 2018 深圳龙华 *****END OF FILE****/
