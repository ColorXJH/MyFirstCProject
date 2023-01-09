//
// Created by ColorXJH on 2023/1/9.
//
#include <stdio.h>
#include <string.h>//提供strlen()函数原型
//如果编译器不识别%zd,尝试换成%u或者%lu
#define PRAISE "I AM YOUR FATHER"
int main(void){
    char name[40];
    printf("what's your name?");
    scanf("%s",name);
    printf("hello,%s,%s\n",name,PRAISE);
    //
    printf("your name of %zd letters occupies %zd memory cells.\n", strlen(name),sizeof name);
    printf("the phrase of praise has %zd letters", strlen(PRAISE));
    printf("and occupies %zd memory cells'\n",sizeof PRAISE);
    //6.28f 占用4个字节，6.28是double类型，占用8个字节（一般一个字符对应一个字节）
    printf("%zd",sizeof 6.28);
    return 0;
}
