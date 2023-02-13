//
// Created by ColorXJH on 2023-02-13.
// 酒店管理函数
#include <stdio.h>
#include "hotel.h"
int menu(void){
    int code,status;
    printf("\n%s%s\n",STARS,STARS);
    printf("enter the number of the desired hotel:\n");
    printf("1) HOTEL1               2) HOTEL2\n");
    printf("3) HOTEL3               4) HOTEL4\n");
    printf("5) QUIT\n");
    printf("\n%s%s\n",STARS,STARS);
    //短路求值
    while((status= scanf("%d",&code))!=1||(code<1||code>5)){
        if(status!=1){
            //这是我们需要将输入的错误信息读取掉 否则scanf函数会把错误信息保留 影响下次的读入
            scanf("%*s");//处理非整数输入,调用scanf("%*s")跳至下一个空白字符
        }
        printf("enter an integer from 1 to 5,pleas.\n");
    }
    return  code;
}

int getNights(void){
    int nights;
    printf("how many nights are you need?\n");
    while(scanf("%d",&nights)!=1){
        scanf("%*s");//处理非整数输入
        printf("please enter an integer,such as 2.\n");
    }
    return nights;
}

void showPrice(double rate,int nights){
    int n;
    double total=0.0;
    double factor=1.0;
    for(n=1;n<nights;n++,factor*=DISCOUNT){
        total+=rate*factor;
    }
    printf("the total cost will be $%0.2f.\n",total);
}
