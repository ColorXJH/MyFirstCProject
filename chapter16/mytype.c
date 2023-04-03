//
// Created by ColorXJH on 2023-04-03.
// 使用泛型选择
#include <stdio.h>
#define MYTYPE(X) _Generic((X), \
int:"int",                      \
float:"float",                  \
double:"double",                \
default:"other"                 \
)
int main(void){
    int d=5;
    printf("%s\n", MYTYPE(d));//int
    printf("%s\n", MYTYPE(2.0*d));//double
    printf("%s\n", MYTYPE(3L)); //long
    printf("%s\n", MYTYPE(&d));//int *
    return 0;
}

















