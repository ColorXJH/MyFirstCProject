//
// Created by ColorXJH on 2023/1/16.
// 把秒数转换成分和秒
#include <stdio.h>
#define MIN_PER_SECOND 60
int main(void){
    int sec,min,left;
    printf("convert seconds to minutes and seconds!\n");
    printf("enter the number of seconds\n");
    scanf("%d",&sec);
    while (sec>0){
        min =sec/MIN_PER_SECOND;
        left=sec%MIN_PER_SECOND;
        printf("%d seconds is %d minutes and %d seconds.\n",sec,min,left);
        printf("enter the next value(<=0 to quit):\n");
        scanf("%d",&sec);
    }
    printf("done!\n");
    return 0;
}

