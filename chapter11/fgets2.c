//
// Created by ColorXJH on 2023-03-01.
// 使用fgets()和fputs()
#include <stdio.h>
#define STLEN 10
int main(void){
    char words[STLEN];
    puts("enter string (empty line to quit:example \"enter\")");
    //当读到文件末尾则只想空指针NULL 也就是我们的数字0，现在假设读到空行（\n）也结束
    //fgets读取换行符，这会导致或者程序看上去就算输入超过了10也没有问题，123456789wwww999依然会在一行打出，坏处是你可能并不想把换行符存储在字符串中
    while (fgets(words,STLEN,stdin)!=NULL&&words[0]!='\n'){
        fputs(words,stdout);
    }
    puts("Done.");
    return 0;
}

