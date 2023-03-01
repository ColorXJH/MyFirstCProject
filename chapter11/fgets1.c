//
// Created by ColorXJH on 2023-03-01.
// 使用fgets和fputs
#include <stdio.h>
#define STLEN 8
int main(void){
    char words[STLEN];
    puts("enter a string please");
    //如果不溢出则会讲换行符也存入，例如 enter\n\0,如果溢出了则enterxxx\0
    //比如输入123456789 按下回车会显示：1234567 剩下的89作为下一次输入=》89\n\0,
    //第一次puts会添加换行符=》89\n\0\n(这里中间对多余空一行).第二此不添加换行符=》89\n\0
    fgets(words,STLEN,stdin);
    printf("your string twice (puts(),then fputs()):\n");
    puts(words);
    //不会再字符串末尾添加换行符
    fputs(words,stdout);
    puts("enter another string please.");
    fgets(words,STLEN,stdin);
    printf("your string twice (puts(),then fputs()):\n");
    puts(words);
    fputs(words,stdout);
    puts("DOne");
    return 0;
}

