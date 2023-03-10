//
// Created by ColorXJH on 2023-03-10.
// 使用外部变量
#include <stdio.h>
int units=4;//外部变量
void critic(void);
int main(void){
    //可选的重复声明
    extern int units;
    printf("how many pounds to a firkin of butter?\n");
    scanf("%d",&units);
    while (units!=56){
        critic();
    }
    printf("you are luckily--%d\n",units);
    return 0;
}


void critic(void){
    //删除了可选的重复声明
    printf("no luck,my friend, try again.\n");
    scanf("%d",&units);
}

