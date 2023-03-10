//
// Created by ColorXJH on 2023-03-10.
// 生成随机数，使用ansi c 可移植算法
#include <stdio.h>
static unsigned long int next=1;//种子
unsigned int rand0(void);
/*int main(void){
    for (int i = 0; i < 3; ++i) {
        printf("this random value is %d\n",rand0());
    }
    return 0;
}*/
//该函数是用于返回一个0～32767之间的值
unsigned int rand0(void){
    //生成伪随机数的公式
    next=next*1103515245+12345;
    return (unsigned int)(next/65536)%32768;
}

void srand(unsigned int seed){
    next=seed;
}


