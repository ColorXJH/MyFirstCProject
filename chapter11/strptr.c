//
// Created by ColorXJH on 2023-02-28.
// 把字符串看作指针
#include <stdio.h>
int main(void){
    //*"spring" 表示该字符串所指向地址上存储的值，即字符串的首字符s
    printf("%s,%p,%c\n","we","are",*"spring");
    return 0;
}

