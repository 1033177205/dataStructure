/**
  ******************************************************************************
  * @file    student.h
  * @author  CGR
  * @version V1.0.0
  * @date    2018-9-22
  * @brief   学生管理头文件
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STUDENT_H
#define __STUDENT_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/


/** @addtogroup DataStruct_Driver
  * @{
  */

/** @addtogroup listArray
  * @{
  */

/* Exported types ------------------------------------------------------------*/



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


/**
  * @}
  */

/* operation functions *******************************************************/
/** @addtogroup listArray_Exported_Functions_Group2
  * @{
  */
int student_add(char *name, int age);
int student_bianli(void);
int student_delete(char *name);
int student_replace(char *old_name, char *new_name, int new_age);


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

#endif /* __STUDENT_H */

/******************* (C) HOME 2018 深圳龙华 *****END OF FILE****/
