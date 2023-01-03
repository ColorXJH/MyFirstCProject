//
// Created by ColorXJH on 2023/1/3.
//
#include <stdio.h>
int main(void){
    float weight;//你的体重
    float value;//相等重量的白金价值
    printf("are you worth your weight in platinum?\n");
    printf("let's check it out\n");
    printf("please enter your weight in pounds:");
    scanf("%f",&weight);//获取用户的输入
    getchar();
    getchar();
    value=1700.0*weight*14.5833;
    printf("your weight in platinum is worth $%.2f.\n",value);
    printf("your are easy worth that!,if platinum price is drop\n");
    printf("eat more to maintain you value\n");
    return 0;

}
