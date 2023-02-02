//
// Created by ColorXJH on 2023-02-02.
// 找出0度以下的天数占总数的百分比
#include <stdio.h>
int main(void){
    const int FREEZING=0;
    float temperature;
    int code_days=0;
    int all_days=0;
    printf("enter the temperature this day,use q to quit:\n");
    while (scanf("%f",&temperature)==1){
        all_days++;
        if(temperature<FREEZING){
            code_days++;
        }
    }
    if(all_days!=0){
        printf("%d days total,has %.1f%% were below freezing\n",all_days,100.0*(float )code_days/all_days);
    }
    if(all_days==0){
        printf("no data enter\n");
    }
    return 0;
}

