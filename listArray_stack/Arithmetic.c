/**
  ******************************************************************************
  * @file    Arithmetic.c
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

/* Includes ------------------------------------------------------------------*/
#include "listArray_stack.h"
#include "Arithmetic.h"

/** @addtogroup DataStruct_Driver
  * @{
  */

/** @addtogroup Arithmetic
  * @{
  */

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
static SqStack *arithmetic;

/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/


/** @defgroup Arithmetic_Exported_Functions Arithmetic Exported Functions
  * @{
  */

/** @defgroup Arithmetic_Exported_Functions_Group1 Initialization and deinitialization functions
 *  @brief    Initialization and Configuration functions
 *
@verbatim    
 ===============================================================================
              ##### Initialization and deinitialization functions #####
 ===============================================================================
  [..]
    This section provides functions allowing to initialize and de-initialize the Arithmetic
    to be ready for use.
 
@endverbatim
  * @{
  */ 

/**
  * @brief  初始化Arithmetic
  * @param  
  * @retval 
  */ 
int8_t Arithmetic_init(void)
{
    arithmetic = listArray_stack_alloc(50, sizeof(char));        /* 申请50个 */
    return 0;
}

/**
  * @}
  */

/** @defgroup Arithmetic_Exported_Functions_Group2 operation functions 
 *  @brief   operation functions
 *
@verbatim   
 ===============================================================================
                       ##### operation functions #####
 ===============================================================================
  [..]
    This subsection provides a set of functions allowing to manage the Arithmetic.

@endverbatim
  * @{
  */

/**
  * @brief  中缀表达式转后缀表达式
  * @param  
  * @retval 
  */ 
len_t Arithmetic_InfixExpressionToPostfixExpression(const char *src, char *reault, len_t len)
{
    // printf("aize %s %d\r\n", src, len);
    /* 判断参数是否正确 */
    if(src == NULL || reault == NULL || len <= 0)
    {
        return DS_PARM_ERROR;
    }

    while(*src)
    {
        printf("%c ",*src);

        if(*src >=0 && *src <=9)
        {
            *reault = *src;
        }
        else if(*src >=40 && *src <=47)
        {
            if(listArray_stack_is_empty(arithmetic) == 1)
            {
                listArray_stack_Push(arithmetic, src, sizeof(char));
            }
            else
            {
                
            }
        }

        src++;
    }


    return 0;
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

