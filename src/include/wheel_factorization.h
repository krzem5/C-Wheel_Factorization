#ifndef __WHEEL_FACTORIZATION_H__
#define __WHEEL_FACTORIZATION_H__ 1
#include <stdint.h>



typedef struct __FACTOR{
	uint64_t n;
	uint32_t c;
} factor_t;



uint32_t wheel_factorization(uint64_t n,factor_t* o,uint32_t ol);



uint64_t euler_totient_function(uint64_t n);



#endif
