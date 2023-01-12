//
// Created by ColorXJH on 2023/1/12.
// 演示除法
#include <stdio.h>
int main(void){
    printf("integer division: 5/4 is %d\n",5/4);
    //-2.4 四舍五入为-3 趋零截断为-2,这里采用趋零截断
    printf("integer division: -12/5 is %d\n",-12/5);
    printf("integer division: 6/3 is %d\n",6/3);
    printf("integer division: 7/4 is %d\n",7/4);
    printf("floating division: 7./4. is %1.2f\n",7./4.);
    //编译器会把整数转换成浮点数，此时
    printf("mixed division: 7./4 is %1.2f\n",7./4);
    return 0;
}

