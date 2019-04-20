/**
  ******************************************************************************
  * @file    listArray.c
  * @author  CGR
  * @version V1.0.0
  * @date    2018-9-1
  * @brief   用数组实现的线性表
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "listArray.h"

/** @addtogroup DataStruct_Driver
  * @{
  */

/** @addtogroup listArray
  * @{
  */

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/


/** @defgroup listArray_Exported_Functions listArray Exported Functions
  * @{
  */

/** @defgroup listArray_Exported_Functions_Group1 Initialization and deinitialization functions
 *  @brief    Initialization and Configuration functions
 *
@verbatim    
 ===============================================================================
              ##### Initialization and deinitialization functions #####
 ===============================================================================
  [..]
    This section provides functions allowing to initialize and de-initialize the listArray
    to be ready for use.
 
@endverbatim
  * @{
  */

/**
  * @brief  初始化线性表
  * @param  Item : 多少个数据
  * @param  Size : 每个数据的大小
  * @retval 线性表的指针
  */ 
pSqList ListArray_InitList(len_t Item, len_t Size)
{
    pSqList L = NULL;
    /* 1.判断输入参数 */
    if(Item * Size > BUF_MAX_SIZE)
    {
        printf("ListArray_InitList buf error\n");
        return NULL;
    }

    /* 2.申请内存 */
    L = (SqList*)malloc(sizeof(SqList) + Item*Size);
    if(L == NULL)
    {
        printf("ListArray_InitList malloc error\n");
        return NULL;
    }

    /* 3.填充数据 */
    L->Item = Item;
    L->Size = Size;
    L->length = 0;

    return L;
}

/**
  * @}
  */

/** @defgroup listArray_Exported_Functions_Group2 operation functions 
 *  @brief   operation functions
 *
@verbatim   
 ===============================================================================
                       ##### operation functions #####
 ===============================================================================
  [..]
    This subsection provides a set of functions allowing to manage the listArray.

@endverbatim
  * @{
  */

/**
  * @brief  判断线性表是否为空
  * @param  L : 线性表的指针
  * @retval 若线性表为空，返回true，否则返回false
  */ 
DataStruct_Status ListArray_ListEmpty(pSqList L)
{
     /* 1.判断输入参数 */
    if(L == NULL)
    {
        return DS_PARM_ERROR;
    }

    /* 2.返回结果 */
    return (L->length ? DS_TRUE : DS_FALSE);
}

/**
  * @brief  将线性表清空
  * @param  L : 线性表的指针
  * @retval 
  */ 
DataStruct_Status ListArray_ClearList(pSqList L)
{
     /* 1.判断输入参数 */
    if(L == NULL)
    {
        return DS_PARM_ERROR;
    }

    /* 2.线性表清空 */
    L->length = 0;

    return DS_OK;
}

/**
  * @brief  将线性表L中的第i个位置元素值返回出去
  * @param  L     : 线性表的指针
  * @param  i     : 获取值的位置
  * @param  buf   : 获取值的指针
  * @param  size  : 获取值的大小
  * @retval 
  */ 
DataStruct_Status ListArray_GetElem(pSqList L, len_t i, uint8_t *buf, len_t size)
{
    uint8_t *item = NULL;
    /* 1.判断输入参数 */
    if(L == NULL || i < 1 || i > L->length)    /* 判断插入位置是否合理，i的判断要注意 */
    {
        return DS_PARM_ERROR;
    }

    if(L->length == 0)                         /* 线性表是否空 */
    {
        return DS_RAM_EMPTY;
    }

    item = L->data+((i-1) * L->Size);                           /* 做好偏移量 */
    memcpy(buf, item, L->Size);

    return DS_OK;
}

/**
  * @brief  在线性表L中查找与给定值e相等的元素，如果查找成功，返回该元素在表中序号表示成功；否则，返回0表示失败。
  * @param  L     : 线性表的指针
  * @param  buf   : 获取值的指针
  * @param  size  : 获取值的大小
  * @retval 
  * @attention  这个实用性不强，换了就用不了了
  */ 
len_t ListArray_LocateElem(pSqList L, const uint8_t *buf, len_t size)
{
    len_t k = 0;
    uint8_t *item = NULL;
    /* 1.判断输入参数 */
    if(L == NULL || buf == NULL)                               /* 判断插入位置是否合理，i的判断要注意 */
    {
        return DS_PARM_ERROR;
    }

    if(L->length == 0)                         /* 线性表是否空 */
    {
        return DS_RAM_EMPTY;
    }

    for(k=0; k<L->length; k++)
    {
        item = L->data+(k * L->Size);
        if(memcmp(item, buf, size) == 0)
            return k+1;
    }

    return 0;
}

/**
  * @brief  在线性表L中的第i个位置插入新元素e
  * @param  L     : 线性表的指针
  * @param  i     : 插入的位置
  * @param  buf   : 插入值的指针
  * @param  size  : 插入值的大小
  * @retval 
  */ 
DataStruct_Status ListArray_ListInsert(pSqList L, len_t i, const uint8_t *buf, len_t size)
{
    len_t k = 0;
    uint8_t *item = NULL;
    /* 1.判断输入参数 */
    if(L == NULL || i < 1 || i > L->length+1 || size > L->Size)     /* 判断插入位置是否合理，i的判断要注意 */
    {
        return DS_PARM_ERROR;
    }
    
    if(L->length == L->Item)                                        /* 线性表已经满了 */
    {
        return DS_RAM_FULL;
    }

    /* 2.插入操作 */
    if(i <= L->length)                                              /* 若插入的位置不在表尾 */
    {
        for(k=L->length-1; k>=i-1; k--)                             /* 从最后一位开始移动位置，时间算法复杂度为O[n] */
        {
            item = L->data+(k * L->Size);                           /* 做好偏移量 */
            memcpy(item+L->Size, item, L->Size);    
        }  
    }
    memcpy(&L->data[(i-1)*L->Size], buf, size);                     /* 新元素插入 */                     
    L->length++;
    
    return DS_OK;
}

/**
  * @brief  删除线性表L中第i个位置元素，并用e返回其值
  * @param  L : 线性表的指针
  * @param  i : 删除的位置
  * @retval 
  */ 
DataStruct_Status ListArray_ListDelete(pSqList L, len_t i)
{
    len_t k = 0;
    uint8_t *item = NULL;
    /* 1.判断输入参数 */
    if(L == NULL || i < 1 || i > L->length)    /* 判断插入位置是否合理，i的判断要注意 */
    {
        return DS_PARM_ERROR;
    }

    if(L->length == 0)                          /* 线性表是否空 */
    {
        return DS_RAM_EMPTY;
    }

    /* 2.删除操作 */  
    for(k=i; k<L->length; k++)            /* 从删除那位开始移动，直到最后一位，时间算法复杂度为O[n] */
    {
        item = L->data+(k * L->Size);                           /* 做好偏移量 */
        memcpy(item-L->Size, item, L->Size);   
    }  
    L->length--;
    
    return DS_OK;
}

/**
  * @brief  返回线性表L的元素个数
  * @param  L : 线性表的指针
  * @retval 
  */ 
len_t ListArray_ListLength(pSqList L)
{
    if(L == NULL)
    {
        return DS_PARM_ERROR;
    }

    return L->length;
}   

/**
  * @brief  在线性表L中添加新元素e，在表尾添加
  * @param  L     : 线性表的指针
  * @param  buf   : 插入值的指针
  * @param  size  : 插入值的大小
  * @retval 
  */ 
DataStruct_Status ListArray_ListAdd(pSqList L, const uint8_t *buf, len_t size)
{
    uint8_t *item = NULL;
    /* 1.判断输入参数 */
    if(L == NULL || size > L->Size)             /* 一次只能添加一包数据 */
    {
        return DS_PARM_ERROR;
    }

    if(L->length == L->Item)                    /* 线性表已经满了 */
    {
        return DS_RAM_FULL;
    }

    /* 2.插入操作 */
    item = L->data+(L->length * L->Size);        /* 做好偏移量 */       
    memcpy(item, buf, size);                     /* 新元素插入 */
               
    L->length++;
    
    return DS_OK;
}

/**
  * @brief  遍历线性表中的元素
  * @param  L : 线性表的指针
  * @retval 
  */ 
DataStruct_Status ListArray_ListPrint(pSqList L)
{
    int i = 0;
    /* 1.判断输入参数 */
    if(L == NULL)
    {
        printf("dd ");
        return DS_PARM_ERROR;
    }

    /* 2.遍历 */
    for(i=0; i<L->length; i++)
    {
        printf("data = %d i = %d\n", L->data[i*L->Size], i);
    }

    if(L->length == 0)
    {
        printf("Empty table\n");
    }

    return DS_OK;
}

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

/************************ (C) HOME 2018 深圳龙华 *****END OF FILE****/
