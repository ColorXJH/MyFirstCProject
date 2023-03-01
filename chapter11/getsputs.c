//
// Created by ColorXJH on 2023-03-01.
// 使用gets(),puts()函数
#include <stdio.h>
#define STLEN 81
int main(void){
    char words[STLEN];//这里如果输入的字符过多会导致缓存溢出，多余的字符会尝试访问其他的内存地址，造成程序问题
    puts("enter a string ,please");
    gets(words);//典型用法
    printf("your string twice:\n");
    printf("%s\n",words);
    puts(words);
    puts("Done");
    return 0;
}

