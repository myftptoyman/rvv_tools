#include <stdio.h>
#include <stdlib.h>


void main(void)
{
	int i= 100;	
	int var1 = 12;
        int var2 = 10;

	printf("hello\n");  

//	for(int j=0; j<100; j++) {
		asm("vsetvli %[VL], %[AVL], e32 \n \
		     vmv.s.x v0, %[my_var1] \n \
                     vadd.vv v0, v0, v0 \n"    : 
                                               :
                     [my_var1]  "r"  (var1), [VL] "r" (128), [AVL] "r" (128) :);

	printf("pre %d\n", var1);
		asm("vext.x.v %[my_var2], v0, zero" :
                     [my_var2] "=r" (var1)          :
                                                    :);
	printf("post %d\n", var1);
//	 }
        
}
