//
// Created by ColorXJH on 2023/1/6.
// 打印类型大小
#include <stdio.h>
void test(void);
int main(void){
    //C99为类型大小提供%zd（即size_t）转换说明,不支持的可以使用%u %lu替代
    printf("type int has a size of %zd bytes\n", sizeof(int));
    printf("type char has a size of %zd bytes\n", sizeof(char));
    printf("type long has a size of %zd bytes\n", sizeof(long));
    printf("type float has a size of %zd bytes\n", sizeof(float));
    printf("type long long has a size of %zd bytes\n", sizeof(long long));
    printf("type double has a size of %zd bytes\n", sizeof(double));
    printf("type long double has a size of %zd bytes\n", sizeof(long double));
    //double类型初始化不同类型的变量
    int xb=12.99;
    float xc=3.1415621212;
    printf("%d\n",xb);//12 截断
    printf("%f\n",xc);//3.141562  保留6位精度
    test();
    return 0;
}

void test(void){
    int x;
    printf("please enter you number:\n");
    scanf("%d",&x);
    printf("your number convert character is %c",x);
}
