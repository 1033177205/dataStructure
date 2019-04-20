/**
  ******************************************************************************
  * @file    kernel.h
  * @author  linux kernel
  * @version 
  * @date    
  * @brief   从Linux kernel中提取一部分需要用的代码
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */ 

 /* Define to prevent recursive inclusion -------------------------------------*/
#ifndef PERF_LINUX_KERNEL_H_
#define PERF_LINUX_KERNEL_H_

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

/**
 * container_of - cast a member of a structure out to the containing structure
 * @ptr:	the pointer to the member.
 * @type:	the type of the container struct this is embedded in.
 * @member:	the name of the member within the struct.
 *
 */
#define container_of(ptr, type, member) ({			\
	const typeof(((type *)0)->member) * __mptr = (ptr);	\
	(type *)((char *)__mptr - offsetof(type, member)); })





#endif /* PERF_LINUX_KERNEL_H_ */

/******************* (C) HOME 2018 深圳龙华 *****END OF FILE****/
