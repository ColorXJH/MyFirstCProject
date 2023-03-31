//
// Created by ColorXJH on 2023-03-27.
// c预处理器和c库-在字符串中替换
#include <stdio.h>
#include <math.h>
#define PSQR(x) printf("the square of "#x" is %d.\n",((x)*(x)));
#define XNAME(n) x##n
#define PRINT_XN(n) printf("x"#n"=%d.\n",x##n);
#define PR(X,...) printf("message "#X ":" __VA_ARGS__)

int main(void){
    int y=5;
    PSQR(y);
    PSQR(2+4);
    int XNAME(1)=14;//int x1=14
    PRINT_XN(1);//printf("x1=%d",x1);
    int x=5;
    PR(1,"x=%g\n",x);
    return 0;
}

