//
// Created by ColorXJH on 2023-03-06.
// 修改字符串
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LIM 81
void ToUpper(char * str);
int PunctCount(const char* str);
int main(void){
    char line[LIM];
    char *find;
    puts("please enter a line;");
    //读取指定数字并加上换行符
    fgets(line,LIM,stdin);
    find= strchr(line,'\n');
    if(find){
        *find='\0';
    }
    ToUpper(line);
    puts(line);
    printf("the line has %d punctuation characters\n", PunctCount(line));
    return 0;
}
//直至遇到空字符。
//此时*str的值为0（空字符的编码值为0），即循环条件为假，循环结束
void ToUpper(char * str){
    while (*str){
        *str= toupper(*str);
        str++;
    }
}
//直至遇到空字符。
//此时*str的值为0（空字符的编码值为0），即循环条件为假，循环结束
int PunctCount(const char* str){
    int ct=0;
    while (*str){
        if(ispunct(*str)){
            ct++;
        }
        str++;
    }
    return ct;
}

