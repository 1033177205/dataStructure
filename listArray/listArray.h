/**
  ******************************************************************************
  * @file    listArray.h
  * @author  CGR
  * @version V1.0.0
  * @date    2018-9-1
  * @brief   数组实现的线性表的头文件
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LISTARRAY_H
#define __LISTARRAY_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "dataStruct_type.h"

/** @addtogroup DataStruct_Driver
  * @{
  */

/** @addtogroup listArray
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup 数组实现的线性表中的扩展类型
  * @{
  */ 

/** 
  * @brief 线性表中的数据类型
  */ 
typedef struct
{
    len_t length;                               /* 数据长度 */
    len_t Item;                                 /* 多少个包 */
    len_t Size;                                 /* 一个包的大小 */
    uint8_t data[];                             /* 数组的地址 */
}SqList, *pSqList;

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
pSqList ListArray_InitList(len_t Item, len_t Size);

/**
  * @}
  */

/* operation functions *******************************************************/
/** @addtogroup listArray_Exported_Functions_Group2
  * @{
  */
DataStruct_Status ListArray_ListEmpty(pSqList L);
DataStruct_Status ListArray_ClearList(pSqList L);
DataStruct_Status ListArray_GetElem(pSqList L, len_t i, uint8_t *buf, len_t size);
len_t ListArray_LocateElem(pSqList L, const uint8_t *buf, len_t size);
DataStruct_Status ListArray_ListInsert(pSqList L, len_t i, const uint8_t *buf, len_t size);
DataStruct_Status ListArray_ListDelete(pSqList L, len_t i);
len_t ListArray_ListLength(pSqList L);

DataStruct_Status ListArray_ListAdd(pSqList L, const uint8_t *buf, len_t size);
DataStruct_Status ListArray_ListPrint(pSqList L);

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

#endif /* __LISTARRAY_H */

/******************* (C) HOME 2018 深圳龙华 *****END OF FILE****/
