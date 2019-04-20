/**
  ******************************************************************************
  * @file    static_linklist.c
  * @author  CGR
  * @version V1.0.0
  * @date    2018-9-24
  * @brief   静态链表
  ******************************************************************************
  * @attention 静态链表的实现结构
  *             数组的第一个元素存储的是备用链表的第一个结点的下标
  *             数组的最后一个元素存储的是第一个有数据元素的下标,最后一个元素的下标指向0
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "static_linklist.h"

/** @addtogroup DataStruct_Driver
  * @{
  */

/** @addtogroup static_linklist
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
  * @brief  静态链表的初始化
  * @param  space : 静态链表的头指针
  * @retval 返回初始化状态
  */ 
DataStruct_Status Static_Linklist_Init(STATIC_LINKLIST space)
{
    int i = 0;
    for(i=0; i<STATIC_LINKLIST_MAXSIZE; i++)
    {
        space[i].cur = i+1;
    }
    space[STATIC_LINKLIST_MAXSIZE-1].cur = 0;              /* 最后一个元素存储着第一个有数据的元素的下标，因为是空链表，所以为零 */
    return DS_OK;
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

int Static_Linklist_length(STATIC_LINKLIST L)
{
    len_t j = 0;

    len_t i = L[STATIC_LINKLIST_MAXSIZE-1].cur;

    while(i)
    {
        j++;
        i = L[i].cur;
    }
    return j;
}


/**
  * @brief  静态链表申请一个节点
  * @param  space : 静态链表的头指针
  * @retval 返回初始化状态
  */ 
len_t Static_Linklist_Malloc_SLL(STATIC_LINKLIST space)
{
    int i = space[0].cur;               //备用数据的第一个元素
    if(space[0].cur)                    //为什么要判断这个，是因为链表不为空的时候指向0？
        space[0].cur = space[i].cur;
    return i;
}

/**
  * @brief  插入一个新节点
  * @param  space : 静态链表的头指针
  * @retval 返回初始化状态
  */ 
DataStruct_Status Static_Linklist_Insert(STATIC_LINKLIST L, len_t i, ElemType e)
{
    len_t j,k,l;

    if(i<=0 || i>Static_Linklist_length(L)+1)
    {
        return DS_PARM_ERROR;
    }

    //1.申请一个空的节点,并填充数据
    j = Static_Linklist_Malloc_SLL(L);
    L[j].data = e;

    //2.查找第i个节点前面的一个节点的位置
    k = STATIC_LINKLIST_MAXSIZE-1;
    for(l=1; l<=i-1; l++)  
    {
        k = L[k].cur;
    }

    //3.把j的元素挂接上去
    L[j].cur = L[k].cur;
    L[k].cur = j;

    return DS_OK;
}

/**
  * @brief  释放一个节点
  * @param  space : 静态链表的头指针
  * @param  j : 要释放的节点
  * @retval 
  */ 
void Static_Linklist_Free_SLL(STATIC_LINKLIST L, len_t j)
{
    L[j].cur = L[0].cur;
    L[0].cur = j;
}

/**
  * @brief  删除一个新节点
  * @param  space : 静态链表的头指针
  * @param  i : 要删除的节点
  * @retval 返回初始化状态
  */ 
DataStruct_Status Static_Linklist_Delete(STATIC_LINKLIST L, len_t i)
{
    len_t j,k,l;

    if(i<=0 || i>Static_Linklist_length(L))
    {
        return DS_PARM_ERROR;
    }

    //1.查找要删除的节点的前一个节点
    k = STATIC_LINKLIST_MAXSIZE-1;
    for(l=1; l<=i-1; l++)  
    {
        k = L[k].cur;
    }

    //2.删除节点
    j = L[k].cur;
    L[k].cur = L[j].cur;

    //3.释放内存
    Static_Linklist_Free_SLL(L, j);

    return DS_OK;
}

/**
  * @brief  插入一个新节点
  * @param  space : 静态链表的头指针
  * @retval 返回初始化状态
  */ 
void Static_Linklist_bianli(STATIC_LINKLIST L)
{
    len_t i = L[STATIC_LINKLIST_MAXSIZE-1].cur;

    while(i)
    {
        printf("data = %d %d\n", L[i].data, i);
        i = L[i].cur;
    }
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
