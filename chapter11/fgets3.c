//
// Created by ColorXJH on 2023-03-01.
// 读取输入行，删除存储在字符串中的换行符，如果没有换行符，丢弃数组装不下的字符
#include <stdio.h>
#define STLEN 10
int main(void){
    char words[STLEN];
    char word[STLEN];
    word[0]='\0';//空字符
    word[1]='a';
    printf("%c-%c\n",word[0],word[1]);// -a
    int i;
    puts("enter string (empty line to quit):");
    //保证读取的加上构造的小于等于10个字符
    while (fgets(words,STLEN,stdin)!=NULL && words[0]!='\n'){//文件末尾。或者换行（enter）  结束循环
        i=0;
        while(words[i]!='\n'&& words[i]!='\0'){
            i++;
        }
        if(words[i]=='\n'){//如果输入包含换行符(\n)，则删除换行符
            words[i]='\0';
        }
        else{//如果超出大小，则过掉这些字符，知道最末尾的换行符（enter）
            while(getchar()!='\n'){
                continue;
            }
        }
        puts(words);
    }
    puts("Done");
    return 0;
}

