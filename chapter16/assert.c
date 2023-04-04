//
// Created by ColorXJH on 2023-04-04.
// 使用断言 assert()
#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <assert.h>
//_Static_assert(CHAR_BIT==16,"16-BIT char falsely assumed");
_Static_assert(CHAR_BIT==8,"16-BIT char falsely assumed");
int main(void){
    double x,y,z;
    puts("enter a pair of numbers(0 0 to quit):");
    while (scanf("%lf %lf",&x,&y)==2&&(x!=0||y!=0)){
        z=x*x-y*y;
        assert(z>=0);
        printf("answer is %f\n", sqrt(z));
        puts("next pair of numbers:");
    }
    puts("done!");
    return 0;
}

