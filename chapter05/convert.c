//
// Created by ColorXJH on 2023/1/17.
// 自动类型转换
#include <stdio.h>
int main(void){
    char ch;
    int i;
    float fl;
    //升级
    fl=i=ch='C';
    printf("ch=%c,i=%d,fl=%2.2f\n",ch,i,fl);
    ch=ch+1;
    i=fl+2*ch;
    fl=2.0*ch+i;
    printf("ch=%c,i=%d,fl=%2.2f\n",ch,i,fl);
    //降级
    ch=1107;
    //求模256
    printf("now ch=%c\n",ch);
    ch=88.99;
    //截断
    printf("now ch=%c\n",ch);
    return 0;
}
