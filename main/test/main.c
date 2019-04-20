/**
  ******************************************************************************
  * @file    main.c
  * @author  CGR
  * @version V1.0.0
  * @date    2018-9-1
  * @brief   主函数
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "listArray.h"
#include "student.h"
#include "static_linklist.h"
#include "listArray_stack.h"
#include "people.h"
#include "sstudent.h"
#include "Arithmetic.h"

char buff[40];
len_t len;
int reault;

/**
  * @brief  main函数
  * @param  None
  * @retval None
  */
int main(int argc, char **argv)
{
    printf("argv1 %s %d\r\n", argv[1], strlen(argv[1]));

    // len = Arithmetic_InfixExpressionToPostfixExpression(argv[1], buff, strlen(argv[1]));

    

    return 0;
}


