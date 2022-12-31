//
// Created by ColorXJH on 2022/12/31.
// 一个文件中包含两个函数
#include <stdio.h>
/*函数原型是一种声明形式，告知编译器正在使用某函数，因此也成为函数声明*/
void butler(void);/*ANSI/ISO C函数原型*/
int main(void){
    printf("i will summon the butler function.\n");
    butler();
    printf("yes, bring me some tea and writeable DVDS.\n");
    return 0;
}

/*函数定义开始*/
    void butler(void){
    printf("you rang,sir?\n");
}

