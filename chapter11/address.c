//
// Created by ColorXJH on 2023-02-28.
// 字符串的地址，数组和指针
#define MSG "I'm special"
#include <stdio.h>
int main(void){
    char ch[]=MSG;
    const char *pt=MSG;
    printf("address of \"i'm special\": %p\n","I'm special");
    printf("address ch: %p\n",ch);
    printf("address pt: %p\n",pt);
    printf("address of MSG: %p\n",MSG);
    printf("address of \"i'm special\": %p\n","I'm special");
    return 0;
}

