//
// Created by ColorXJH on 2023/1/4.
//
#include <stdio.h>
int main(void){
    int ten=10;
    int two=2;
    printf("doing it right: ");
    printf("%d minus %d is %d\n",ten,2,ten-two);
    printf("doing it wrong: ");
    printf("%d minus %d is %d\n",ten);//遗漏两个参数
    printf("%d - %o - %x\n",10,010,0x10);//10 - 10 - 10
    printf("%d - %#o - %#x -%#X\n",10,10,10,10);//10 - 012 - 0xa -0XA(十六进制0-9 ABCDEF（abcdef）标识10-15)
    //0x,0X并没有什么不同，只是大小写得问题
    return 0;
}

void test(void){
    long int es;
    long john;
    short int errs;
    short ribs;
    unsigned int c_counts;
    unsigned players;
    unsigned long hearCount;
    unsigned short years;
    long long ages;
    long long int asg;
}