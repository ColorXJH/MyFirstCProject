//
// Created by ColorXJH on 2023-02-13.
// 以二进制清单打印整数
#include <stdio.h>
void to_binary(unsigned long n);
void to_binary2(unsigned long n);
int main(void){
    unsigned long number;
    printf("enter an integer(q to quit).\n");
    while(scanf("%lu",&number)==1){
        printf("binary is:");
        to_binary(number);
        printf("\n");
        printf("binary2 is:");
        to_binary2(number);
        printf("\n");
        printf("enter an integer(q to quit).\n");
    }
    printf("done!\n");
    return 0;
}
//递归函数(除2 求模 然后反向排序)：6==》 6%2=0   3%2=1  1%2=1  ==》110
void to_binary(unsigned long n){
    int r;
    r=n%2;
    if(n>=2){
        to_binary(n/2);
    }
    putchar(r==0?'0':'1');
    return;
}
//数组方式
void to_binary2(unsigned long n){
    //初始化字符数组
    char ch[32]="";
    int index;
    if(n>=2){
        for(index=0;n>=2;n=n/2){
            ch[index]=n%2==0?'0':'1';
            index++;
        }
        //上方index++ 副作用生效了
        ch[index]='1';
    }else{
        ch[0]='1';
    }
    for(;index>=0;index--){
        putchar(ch[index]);
    }
}