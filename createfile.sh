#!/bin/bash
# @file		createfile.bat
# @author	chenguanren
# @version	V1.2.0
# @date		2018-10-27
# @brief	自动生成一个Doxygen风格的.c和.
# @date		2019-03-22
# @brief    添加第三个参数，生产文件的目录
# @date		2019-04-13
# @brief    是否只创建头文件
###################################################

if [ '-h' = $1 ];then
    echo "使用说明"
    echo "<参数1>：文件名"
    echo "<参数2>：简要的注释"
    echo "[参数]：文件目录"
    echo "[参数]：只创建头文件"
    exit 0
fi

#判断参数
if [ $# -lt 3 ] || [ $# -gt 4 ];then
    echo "输入两个参数，第一个是文件名，第二个是文件的简要的注释 第三个是文件目录 第四个是否只创建头文件"
    exit 0
fi

if [ x"$3" != x"" ];then
    if [ x"$3" = x"Onlyhead" ];then
        cfile_creat=0
        echo "Only head file"
    elif [ ! -d $3 ];then
        mkdir -p $3
        cd $3
        echo `pwd`
    else
        cd $3
        echo `pwd`
    fi
fi

if [ x"$4" != x"" ] && [ x"$4" = x"Onlyhead" ];then
    cfile_creat=0
    echo "Only head file"
fi

cfile=0
#1.2 创建文件
if [ ! -e $1.c ] && [ "$cfile_creat" != "0" ];then
    touch $1.c
    cfile=1
fi

hfile=0
if [ ! -e $1.h ];then
    touch $1.h
    hfile=1
fi

#获取当前系统时间
ls_date=`date +%Y-%m-%d`
# echo $ls_date

name=`hostname`
# echo $name

UPPERCASE=$(echo $1 | tr '[a-z]' '[A-Z]') 
# echo $UPPERCASE
H=_H

#写c文件
if [ $cfile -eq 1 ];
then
echo "/**
    ******************************************************************************
    * @file    $1.c
    * @author  $name
    * @version V1.0.0
    * @date    $ls_date
    * @brief   $2
    ******************************************************************************
    * @attention
    *
    *
    ******************************************************************************
    */ 

/* Includes ------------------------------------------------------------------*/

/** @addtogroup DataStruct_Driver
    * @{
    */

/** @addtogroup $1
    * @{
    */

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/


/** @defgroup $1_Exported_Functions $1 Exported Functions
    * @{
    */

/** @defgroup $1_Exported_Functions_Group1 Initialization and deinitialization functions
    *  @brief    Initialization and Configuration functions
    *
@verbatim    
    ===============================================================================
                ##### Initialization and deinitialization functions #####
    ===============================================================================
    [..]
        This section provides functions allowing to initialize and de-initialize the $1
        to be ready for use.
 
@endverbatim
    * @{
    */ 

/**
    * @brief  初始化$1
    * @param  
    * @retval 
    */ 
    int8_t $1_init(void)
    {
        return 0;
    }

/**
    * @}
    */

/** @defgroup $1_Exported_Functions_Group2 operation functions 
    *  @brief   operation functions
    *
@verbatim   
    ===============================================================================
                        ##### operation functions #####
    ===============================================================================
    [..]
        This subsection provides a set of functions allowing to manage the $1.

@endverbatim
    * @{
    */

        /* 操作函数写在这里 */

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
" >> $1.c

echo "`date '+%Y-%m-%d %H:%M:%S'` create $1.c finish"
else 
    if [ "$cfile_creat" == "0" ];then
        echo "No need to create $1.c file"
    else
        echo "$1.c file existed"
    fi
fi

#写h文件
if [ $hfile -eq 1 ];
then
echo "/**
    ******************************************************************************
    * @file    $1.h
    * @author  $name
    * @version V1.0.0
    * @date    $ls_date
    * @brief   $2
    ******************************************************************************
    * @attention
    *
    *
    ******************************************************************************
    */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __$UPPERCASE$H
#define __$UPPERCASE$H

#ifdef __cplusplus
    extern \"C\" {
#endif

/* Includes ------------------------------------------------------------------*/


/** @addtogroup DataStruct_Driver
    * @{
    */

/** @addtogroup $1
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
/** @addtogroup $1_Exported_Functions
    * @{
    */

/** @addtogroup $1_Exported_Functions_Group1
    * @{
    */
    int8_t $1_init(void);

/**
    * @}
    */

/* operation functions *******************************************************/
/** @addtogroup $1_Exported_Functions_Group2
    * @{
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

/**
    * @}
    */


#ifdef __cplusplus
}
#endif

#endif /* __$UPPERCASE$H */

/******************* (C) HOME 2018 深圳龙华 *****END OF FILE****/
" >> $1.h

echo "`date '+%Y-%m-%d %H:%M:%S'` create $1.h finish"
else
echo "$1.h file existed"
fi
