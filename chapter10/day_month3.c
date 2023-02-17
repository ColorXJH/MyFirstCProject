//
// Created by ColorXJH on 2023-02-17.
// 数组表示法--指针表示法
#include <stdio.h>
#define MONTHS 12
int main(void){
    int days[MONTHS]={31,28,31,30,31,30,31,31,30,31,30,31};
    int index;
    for(index=0;index<MONTHS;index++){
        //days是首个元素地址，days+index是days[index]的地址，而*（days+index）=>days[index]
        printf("Month %2d has %d days\n",index+1,*(days+index));
    }
    return 0;
}

