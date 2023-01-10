//
// Created by ColorXJH on 2023/1/10.
// 字符串格式
#include <stdio.h>
#define BLURB "Authentic imitation!"
int main(void){
    printf("[%2s]\n",BLURB);//[Authentic imitation!]
    printf("[%24s]\n",BLURB);//[    Authentic imitation!]
    //精度限制了打印字符的个数
    printf("[%24.5s]\n",BLURB);//[                   Authe]
    //左对齐
    printf("[%-24.5s]\n",BLURB);//[Authe                   ]
    return 0;
}

