//
// Created by ColorXJH on 2023/1/9.
// 使用转换说明
#include <stdio.h>
#define PI 3.1415926
int main(void){
    int number=7;
    float pies=12.75;
    int cost=7800;
    //%f默认6位精度  %m.nf  m表示小数点前位宽度，n表示精度
    printf("the %d contestants ate %f berry pies.\n",number,pies);
    printf("the value of pi is %f.\n",PI);
    printf("farewell,----------.\n");
    printf("%c%d\n",'$',2*cost);
    printf("this is %d%%\n",10);
    return 0;
}

