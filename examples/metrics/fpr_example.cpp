#include "fpr.h"

#include "stdlib.h"
#include "stdio.h"

int main()
{

    int ref[10][10]=	{{0,0,0,1,1,1,0,0,0,1},
    		     	 {1,0,0,1,0,1,0,1,0,1},
    			 {1,1,1,1,1,1,1,1,1,1},
    			 {1,1,1,1,1,1,1,0,0,0},
    			 {1,1,1,1,1,1,1,0,0,0},
    			 {1,1,1,1,1,1,0,0,0,0},
    			 {1,1,1,1,1,0,0,0,0,0},
    			 {1,1,1,1,0,0,0,0,0,0},
    			 {1,1,1,1,0,0,0,0,0,0},
    			 {1,1,1,0,0,0,0,0,0,0}};
    int det[10][10]=	{{0,0,0,1,1,1,0,0,0,1},
    		     	 {1,0,0,1,0,1,0,1,0,1},
    			 {1,1,1,1,1,1,1,1,1,1},
    			 {1,1,1,1,1,1,1,1,0,0},
    			 {1,1,1,1,1,1,1,1,0,0},
    			 {1,1,1,1,1,1,1,0,0,0},
    			 {1,1,1,1,1,1,0,0,0,0},
    			 {1,1,1,1,1,0,0,1,0,0},
    			 {1,1,1,1,1,0,0,0,0,0},
    			 {1,1,1,0,0,0,1,1,0,0}};
 
    printf("FPR: %f\n", fpr(10, 10, (int *)ref, (int *)det));

    return 0;
}
