//
// Created by ColorXJH on 2023-02-15.
// 打印每个月的天数,由编译器确定数组大小

#include <stdio.h>
int main(void){
    int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int index;
    //sizeof运算符给出它的运算对象的大小（以字节为单位），sizeof days[0]是数组中一个元素的大小，
    //整个数组对象大小与一个元素大小相除 求得数组中元素个数，这也是有弊端的，就是无法察觉初始化列表中的项数有误
    for(index=0;index<sizeof days/sizeof days[0];index++){
        printf("month %2d has %2d days\n",index+1,days[index]);
    }
    return 0;
}