//
// Created by ColorXJH on 2023-04-04.
// atexit()示例
#include <stdio.h>
#include <stdlib.h>
void sign_off(void);
void too_bad(void);
int main(void){
    int n;
    atexit(sign_off);//注册sign_off函数
    puts("enter an integer:");
    if(scanf("%d",&n)!=1){
        puts("that not integer!");
        atexit(too_bad);//注册too_bad函数
        exit(EXIT_FAILURE);
    }
    printf("%d is %s.\n",n,(n%2==0)?"even":"odd");
    return 0;
}
void sign_off(void){
    puts("thus terminates another magnificent program from");
    puts("see saw software!");

}
void too_bad(void){
    puts("see saw software extends its heartfelt condolences");
    puts("to you upon the failure of your program.");

}
