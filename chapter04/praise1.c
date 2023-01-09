//
// Created by ColorXJH on 2023/1/9.
// 使用不同类型的字符串
#include <stdio.h>
#define PRAISE "i am your father"//编译器会在末尾加上空字符
int main(void){
    char name[40];
    printf("what's your name?");//color xjh 将只读取color
    //它在遇到第1个空白（空格、制表符或换行符）时就不再读取输入
    //%s的转换说明：scanf()只会读取字符串中的一个单词，而不是一整句
    scanf("%s",name);//在末尾会放置空字符
    printf("hello,%s,%s\n",name,PRAISE);
    return 0;
}

