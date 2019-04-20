/**
  ******************************************************************************
  * @file    log2.h
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
 #ifndef LOG2_H_
 #define LOG2_H_

#include "stdbool.h"
#include "dataStruct_type.h"

/*
 * deal with unrepresentable constant logarithms
 */
extern int ____ilog2_NaN(void);

static inline int constant_fls(int x)
{
	int r = 32;

	if (!x)
		return 0;
	if (!(x & 0xffff0000u)) {
		x <<= 16;
		r -= 16;
	}
	if (!(x & 0xff000000u)) {
		x <<= 8;
		r -= 8;
	}
	if (!(x & 0xf0000000u)) {
		x <<= 4;
		r -= 4;
	}
	if (!(x & 0xc0000000u)) {
		x <<= 2;
		r -= 2;
	}
	if (!(x & 0x80000000u)) {
		x <<= 1;
		r -= 1;
	}
	return r;
}

static inline int fls(int x)
{
	int ret;

	if (__builtin_constant_p(x))
	       return constant_fls(x);

	//asm("clz\t%0, %1" : "=r" (ret) : "r" (x) : "cc");
       	ret = 32 - ret;
	return ret;
}

static inline __attribute__((const))
int __ilog2_u32(uint32_t n)
{
	return fls(n) - 1;
}

static __always_inline int fls64(uint64_t x)
{
	uint32_t h = (uint32_t)(x >> 32);
	if (h)
		return fls(h) + 32;
	return fls(x);
}

static inline __attribute__((const))
int __ilog2_u64(uint64_t n)
{
	return fls64(n) - 1;
}


static inline unsigned fls_long(unsigned long l)
{
	if (sizeof(l) == 4)
		return fls(l);
	return fls64(l);
}

unsigned long __roundup_pow_of_two(unsigned long n)
{
	return 1UL << fls_long(n - 1);
}

/**
  * @brief  2的几次幂
  * @param  n   : 
  * @retval 线性表的指针
  * @note 我也不知道为什么这样
  */ 
bool is_power_of_2(unsigned long n)
{
	return (n != 0 && ((n & (n - 1)) == 0));
}

/**
 * ilog2 - log of base 2 of 32-bit or a 64-bit unsigned value
 * @n - parameter
 *
 * constant-capable log of base 2 calculation
 * - this can be used to initialise global variables from constant data, hence
 *   the massive ternary operator construction
 *
 * selects the appropriately-sized optimised version depending on sizeof(n)
 */
#define ilog2(n)				\
(						\
	__builtin_constant_p(n) ? (		\
		(n) < 1 ? ____ilog2_NaN() :	\
		(n) & (1ULL << 63) ? 63 :	\
		(n) & (1ULL << 62) ? 62 :	\
		(n) & (1ULL << 61) ? 61 :	\
		(n) & (1ULL << 60) ? 60 :	\
		(n) & (1ULL << 59) ? 59 :	\
		(n) & (1ULL << 58) ? 58 :	\
		(n) & (1ULL << 57) ? 57 :	\
		(n) & (1ULL << 56) ? 56 :	\
		(n) & (1ULL << 55) ? 55 :	\
		(n) & (1ULL << 54) ? 54 :	\
		(n) & (1ULL << 53) ? 53 :	\
		(n) & (1ULL << 52) ? 52 :	\
		(n) & (1ULL << 51) ? 51 :	\
		(n) & (1ULL << 50) ? 50 :	\
		(n) & (1ULL << 49) ? 49 :	\
		(n) & (1ULL << 48) ? 48 :	\
		(n) & (1ULL << 47) ? 47 :	\
		(n) & (1ULL << 46) ? 46 :	\
		(n) & (1ULL << 45) ? 45 :	\
		(n) & (1ULL << 44) ? 44 :	\
		(n) & (1ULL << 43) ? 43 :	\
		(n) & (1ULL << 42) ? 42 :	\
		(n) & (1ULL << 41) ? 41 :	\
		(n) & (1ULL << 40) ? 40 :	\
		(n) & (1ULL << 39) ? 39 :	\
		(n) & (1ULL << 38) ? 38 :	\
		(n) & (1ULL << 37) ? 37 :	\
		(n) & (1ULL << 36) ? 36 :	\
		(n) & (1ULL << 35) ? 35 :	\
		(n) & (1ULL << 34) ? 34 :	\
		(n) & (1ULL << 33) ? 33 :	\
		(n) & (1ULL << 32) ? 32 :	\
		(n) & (1ULL << 31) ? 31 :	\
		(n) & (1ULL << 30) ? 30 :	\
		(n) & (1ULL << 29) ? 29 :	\
		(n) & (1ULL << 28) ? 28 :	\
		(n) & (1ULL << 27) ? 27 :	\
		(n) & (1ULL << 26) ? 26 :	\
		(n) & (1ULL << 25) ? 25 :	\
		(n) & (1ULL << 24) ? 24 :	\
		(n) & (1ULL << 23) ? 23 :	\
		(n) & (1ULL << 22) ? 22 :	\
		(n) & (1ULL << 21) ? 21 :	\
		(n) & (1ULL << 20) ? 20 :	\
		(n) & (1ULL << 19) ? 19 :	\
		(n) & (1ULL << 18) ? 18 :	\
		(n) & (1ULL << 17) ? 17 :	\
		(n) & (1ULL << 16) ? 16 :	\
		(n) & (1ULL << 15) ? 15 :	\
		(n) & (1ULL << 14) ? 14 :	\
		(n) & (1ULL << 13) ? 13 :	\
		(n) & (1ULL << 12) ? 12 :	\
		(n) & (1ULL << 11) ? 11 :	\
		(n) & (1ULL << 10) ? 10 :	\
		(n) & (1ULL <<  9) ?  9 :	\
		(n) & (1ULL <<  8) ?  8 :	\
		(n) & (1ULL <<  7) ?  7 :	\
		(n) & (1ULL <<  6) ?  6 :	\
		(n) & (1ULL <<  5) ?  5 :	\
		(n) & (1ULL <<  4) ?  4 :	\
		(n) & (1ULL <<  3) ?  3 :	\
		(n) & (1ULL <<  2) ?  2 :	\
		(n) & (1ULL <<  1) ?  1 :	\
		(n) & (1ULL <<  0) ?  0 :	\
		____ilog2_NaN()			\
				   ) :		\
	(sizeof(n) <= 4) ?			\
	__ilog2_u32(n) :			\
	__ilog2_u64(n)				\
 )

/**
  * @brief  将给定值四舍五入到最接近的2的幂
  * @param  n   : 
  * @note   
  */
#define roundup_pow_of_two(n)			\
(						                \
	__builtin_constant_p(n) ? (		    \
		(n == 1) ? 1 :			        \
		(1UL << (ilog2((n) - 1) + 1))	\
				   ) :		            \
	__roundup_pow_of_two(n)			    \
 )









 #endif /* LOG2_H_ */

 /******************* (C) HOME 2018 深圳龙华 *****END OF FILE****/
