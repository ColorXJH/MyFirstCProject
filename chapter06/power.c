//
// Created by ColorXJH on 2023-02-01.
// 计算数的整数次幂
#include <stdio.h>
double power(double n,int p);
int main(void ){
    double x,xpow;
    int exp;
    printf("enter a number and a positive integer\n");
    printf("to which the number will be raised,enter q to quit\n");
    while (scanf("%lf%d",&x,&exp)==2){
        xpow= power(x,exp);
        printf("%.3g to the power %d is %.5g\n",x,exp,xpow);
        printf("enter another pair of number or q to quit.\n");
    }
    printf("hope you enjoyed this game--bye!\n");
    return 0;
}
double power(double n,int p){
    double power=1;
    int i;
    for(i=1;i<=p;i++){
        power*=n;
    }
    return power;
}
