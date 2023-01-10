//
// Created by ColorXJH on 2023/1/10.
// 一些浮点型修饰符的组合
#include <stdio.h>
int main(void){
    const double RENT=3852.99;
    printf("%f\n",RENT);
    printf("%e\n",RENT);
    printf("%4.2f\n",RENT);
    printf("%3.1f\n",RENT);
    printf("*%10.3f\n",RENT);//*  3852.990
    printf("%10.3E\n",RENT);
    printf("%+4.2f\n",RENT);
    //转换说明：%m.nf m指定字段宽度,n指定小数点精度
    printf("*%010.2f\n",RENT);//*0003852.99   %m.nf
    return 0;
}

