//
// Created by ColorXJH on 2023-02-03.
// 统计字符数，单词数，行数
#include <stdio.h>
#include <ctype.h>//为isspace()函数提供原型
#include <stdbool.h>//为bool,true,false提供定义
#define STOP '|'
int main(void){
    char c,prev;//输入字符，前一个字符
    long n_chars=0L;//字符数
    int n_lines=0;//行数
    int n_words=0;//单词数
    int p_lines=0;//不完整的行数
    bool in_word=false;//如过c在单词中，该值为true
    printf("enter text to be analyzed (| to terminate):\n");
    prev='\n';//用于识别完整的行
    while((c=getchar())!=STOP){
        n_chars++;
        if(c=='\n'){
            n_lines++;
        }
        if(!isspace(c)&&!in_word){
            n_words++;
            in_word=true;
        }
        if(isspace(c)&&in_word){
            in_word=false;
        }
        prev=c;
    }
    if(prev!='\n'){
        p_lines=1;
    }
    printf("characters =%ld,words=%d,lines=%d,p_lines=%d \n",n_chars,n_words,n_lines,p_lines);
    return 0;
}


