//
// Created by ColorXJH on 2023-03-22.
// 使用typedef
#include <stdio.h>
typedef struct {double x;double y;} rect;
int main(void){
    rect r1={3.0,6.0};
    rect r2;
    r2=r1;
    printf("now r2 value is %.2f and %.2f",r2.x,r2.y);
    return 0;
};

