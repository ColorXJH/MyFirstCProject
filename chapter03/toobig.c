//
// Created by ColorXJH on 2023/1/4.
// 整数溢出
#include <stdio.h>
void test(void);
int main(void){
    int i=2147483647;
    unsigned  int j=4294967295;
    printf("%d %d %d\n",i,i+1,i+2);//有符号整数在达到最大值时会从另一端（最小值）开始计数
    //printf("%u",x)显示 unsigned int类型的值
    printf("%u %u %u\n",j,j+1,j+2);//无符号整数在达到最大值时会从另一端（0）开始计数
    //整数溢出都体现了周而复始的思想，只不过他们的边界不同，0~+x  -y~+y
    test();
    int x='ABCD';
    char ch='ABCD';
    char beep=7;
    printf("beep is %hd\n",beep);
    printf("x is %d\n",x);
    printf("ch is %hd\n",ch);//D
    return 0;
}
void test(void){
    //int
    printf("%d\n",10);
    printf("%D\n",10);
    //unsigned int
    printf("%u\n",20);
    //long
    printf("%ld\n",100000);
    printf("%#dl\n",100000);//100000l
    //long 16进制
    printf("%lx\n",1616);//650
    printf("%#x\n",1616);//0x650
    printf("%#xl\n",1616);//0x650l
    printf("%#XL\n",1616);//0X650L
    //long 8进制
    printf("%lo\n",8888);//21270
    printf("%#ol\n",8888);//021270l
    printf("%#o\n",8888);//021270
    printf("%#oL\n",8888);//021270L

    //short
    printf("%hd\n",'A');
    //short 8进制
    printf("%ho\n",'a');
    //short 16进制
    printf("%hx\n",'F');
    //unsigned long
    printf("%lu\n",10000);
    //unsigned  long long
    printf("%llu\n",100000);
    //long long
    printf("%lld\n",1000000);
}

