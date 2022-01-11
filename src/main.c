#include <wheel_factorization.h>
#include <inttypes.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>



int main(int argc,const char** argv){
	factor_t fc[20];
	for (uint64_t i=1;i<1000;i++){
		uint64_t l=wheel_factorization(i,fc,20);
		printf("%"PRIu64": phi=%"PRIu64", ",i,euler_totient_function(i));
		for (uint32_t i=0;i<l;i++){
			if (fc[i].c>1){
				printf("%"PRIu64"^%"PRIu32,fc[i].n,fc[i].c);
			}
			else{
				printf("%"PRIu64,fc[i].n);
			}
			if (i<l-1){
				printf(" * ");
			}
			else{
				putchar('\n');
			}
		}
	}
	return 0;
}
