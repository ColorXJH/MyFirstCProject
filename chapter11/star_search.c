//
// Created by ColorXJH on 2023-03-03.
// 使用strncmp()函数比较字符串
#include <stdio.h>
#include <string.h>
#define LISTSIZE 6
int main(void){
    const char* list[LISTSIZE]={
            "astronomy","astounding",
            "astrophysics","ostracize",
            "asterism","astrophobia"
    };
    int count=0;
    int i;
    for (int i = 0; i < LISTSIZE; ++i) {
        if(strncmp(list[i],"astro",5)==0){
            printf("found :%s \n",list[i]);
            count++;
        }
    }
    printf("The　list　contained　%d　words　beginning"
           "　with　astro.\n",count);
    return 0;
}

