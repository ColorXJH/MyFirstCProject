//
// Created by ColorXJH on 2023-03-03.
// strcpy的两个属性，1：返回char* 2：第一个参数不必指向数组的开始
#include <string.h>
#include <stdio.h>
#define WORDS "Beast"
#define SIZE 40
int main(void){
    const char * orig=WORDS;
    char copy[SIZE]="be the best that you can be";
    char *ps;
    puts(orig);
    puts(copy);
    //beast
    //be the best that you can be
    //be the beast
    //beast
    //拷贝把orig中的空字符‘\0’也拷贝到了copy中
    //从第七个地址开始向后拷贝，因为指针指向第七个地址，则返回后的ps从该位置开始打印（B）,答应道空字符出就结束打印，所以put(ps)==>Beast
    ps= strcpy(copy+7,orig);
    puts(copy);
    puts(ps);
    return 0;
}

