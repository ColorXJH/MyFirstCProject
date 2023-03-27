//
// Created by ColorXJH on 2023-03-27.
// 使用_Alignof和_Alignas
#include <stdio.h>
int main(void){
    double dx;
    char ca;
    char cx;
    double dz;
    char cb;
    _Alignas(double) char cz;
    //在我们的系统中，double的对齐值是8，这意味着地址的类型对齐可以
    //被8整除。以0或8结尾的十六进制地址可被8整除。这就是地址常用两个
    //double类型的变量和char类型的变量cz（该变量是double对齐值）。因为char
    //的对齐值是1，对于普通的char类型变量，编译器可以使用任何地址。
    printf("char alignment :%zd\n", _Alignof(char));
    printf("double alignment :%zd\n", _Alignof(double ));
    printf("&dx:%p\n",&dx);
    printf("&ca:%p\n",&ca);
    printf("&cx:%p\n",&cx);
    printf("&dz:%p\n",&dz);
    printf("&cb:%p\n",&cb);
    printf("&cz:%p\n",&cz);
    return 0;
    //在程序中包含 stdalign.h 头文件后，就可以把 alignas 和 alignof 分别作为
    //_Alignas 和_Alignof的别名。这样做可以与C++关键字匹配
}

