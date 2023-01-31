//
// Created by ColorXJH on 2023-01-31.
// 浮点数比较
#include <stdio.h>
#include <math.h>
int main(void){
    const double ANSWER=3.14159;
    double response;
    printf("what is the value of PI?\n");
    scanf("%lf",&response);
    while (fabs(response-ANSWER)>0.001){
        printf(" try again!\n");
        scanf("%lf",&response);
    }
    printf("close enough!\n");
    return 0;
}

