#ifdef _MSC_VER
#include <intrin.h>
#endif
#include <wheel_factorization.h>
#include <stdint.h>



#ifdef _MSC_VER
#pragma intrinsic(_BitScanForward64)
static __inline __forceinline unsigned int FIND_FIRST_SET_BIT(unsigned __int64 m){
	unsigned long o;
	_BitScanForward64(&o,m);
	return o;
}
#else
#define FIND_FIRST_SET_BIT(m) (__builtin_ffsll((m))-1)
#endif



#define WHEEL_STEP(x) \
	if (!(n%f)){ \
		c=0; \
		do{ \
			c++; \
			n/=f; \
		} while (!(n%f)); \
		(o+i)->n=f; \
		(o+i)->c=c; \
		i++; \
		if (i==ol){ \
			i--; \
		} \
	} \
	f+=x; \
	if (f*f>n){ \
		break; \
	}



#define WHEEL_STEP_EULER(x) \
	if (!(n%f)){ \
		do{ \
			n/=f; \
		} while (!(n%f)); \
		o-=o/f; \
	} \
	f+=x; \
	if (f*f>n){ \
		break; \
	}



uint32_t wheel_factorization(uint64_t n,factor_t* o,uint32_t ol){
	if (n<2){
		if (!ol){
			return 0;
		}
		o->n=1;
		o->c=1;
		return 1;
	}
	uint32_t i=0;
	uint32_t c=FIND_FIRST_SET_BIT(n);
	if (c){
		n>>=c;
		(o+i)->n=2;
		(o+i)->c=c;
		i++;
		if (i==ol){
			i--;
		}
	}
	if (!(n%3)){
		c=0;
		do{
			c++;
			n/=3;
		} while (!(n%3));
		(o+i)->n=3;
		(o+i)->c=c;
		i++;
		if (i==ol){
			i--;
		}
	}
	if (!(n%5)){
		c=0;
		do{
			c++;
			n/=5;
		} while (!(n%5));
		(o+i)->n=5;
		(o+i)->c=c;
		i++;
		if (i==ol){
			i--;
		}
	}
	uint64_t f=7;
	if (n>48){
		while (1){
			WHEEL_STEP(4);
			WHEEL_STEP(2);
			WHEEL_STEP(4);
			WHEEL_STEP(2);
			WHEEL_STEP(4);
			WHEEL_STEP(6);
			WHEEL_STEP(2);
			WHEEL_STEP(6);
		}
	}
	if (n!=1){
		(o+i)->n=n;
		(o+i)->c=1;
		i++;
		if (i==ol){
			i--;
		}
	}
	return i;
}



uint64_t euler_totient_function(uint64_t n){
	if (n<2){
		return 0;
	}
	uint64_t o=n;
	uint32_t c=FIND_FIRST_SET_BIT(n);
	if (c){
		n>>=c;
		o>>=1;
	}
	if (!(n%3)){
		do{
			n/=3;
		} while (!(n%3));
		o-=o/3;
	}
	if (!(n%5)){
		do{
			n/=5;
		} while (!(n%5));
		o-=o/5;
	}
	uint64_t f=7;
	if (n>48){
		while (1){
			WHEEL_STEP_EULER(4);
			WHEEL_STEP_EULER(2);
			WHEEL_STEP_EULER(4);
			WHEEL_STEP_EULER(2);
			WHEEL_STEP_EULER(4);
			WHEEL_STEP_EULER(6);
			WHEEL_STEP_EULER(2);
			WHEEL_STEP_EULER(6);
		}
	}
	if (n!=1){
		o-=o/n;
	}
	return o;
}
