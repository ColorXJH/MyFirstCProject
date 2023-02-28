//
// Created by ColorXJH on 2023-02-28.
// 表示字符串的几种方式
#include <stdio.h>
#define MSG "I am a symbolic String constant."//字符串常量
#define MAXLENGTH 81
int main(void){
    char words[MAXLENGTH]="I am a string in an array.";//char类型数组
    const char *pt1="Something is pointing at me.";//指向char的指针
    puts("here are somethings:");
    puts(MSG);
    puts(words);
    puts(pt1);
    words[8]='p';
    puts(words);
    return 0;
    //和printf函数一样，puts函数也属于stdio.h系列的输入输出函数，但是puts只用于显示字符串，而且自动在末尾加上换行符
}

