//
// Created by ColorXJH on 2023-02-15.
// 打印每个月的天数
#include <stdio.h>
#define MONTHS 12
int main(void){
    int days[MONTHS]={31,28,31,30,31,30,31,31,30,31,30,31};
    int index;
    for(index=0;index<MONTHS;index++){
        printf("month %2d has %2d days\n",index+1,days[index]);
    }
    return 0;
}

