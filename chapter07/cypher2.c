//
// Created by ColorXJH on 2023-02-02.
// 替换输入的字母，非字母字符保持不变
#include <stdio.h>
#include <ctype.h>//包含很多字符映射函数
int main(void){
    char ch;
    while((ch=getchar())!='\n'){
        if(isalpha(ch)){
            putchar(ch+1);
        }else{
            putchar(ch);
        }
    }
    putchar(ch);
    return 0;
}

