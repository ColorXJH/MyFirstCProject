//
// Created by ColorXJH on 2023-02-09.
// 猜谜，输入输出
#include <stdio.h>
int main(void){
    int guess=1;
    char ch;
    printf("pick an integer from 1-100,i will guess\n");
    printf("well .i guess is be %d ?\n",guess);
    //getchar()读取每个字符，包括空格、制表符和换行符；而 scanf()在读取数字时则会跳过空格、制表符和换行符。
    while((ch=getchar())!='y'){
        if(ch=='n'){
            printf("well .i guess is be %d ?\n",++guess);
        }else{
            printf("only accept y or n.\n");
        }
        while(getchar()!='\n')/* 跳过剩余的输入行 */
            continue;
    }
    printf("i know i could do it \n");
    return 0;
}


