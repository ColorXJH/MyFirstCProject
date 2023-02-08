//
// Created by ColorXJH on 2023-02-08.
// 使用goto
#include <stdio.h>
int main(void){
    float numbers;
    printf("enter the number or q to quit:\n");
    while(scanf("%f",&numbers)==1){
        if(numbers==2)
            goto type2;
        printf("%f is good",numbers);
        printf("enter the number or q to quit\n");
    }
    printf("bye\n");
    type2:
    printf("this is number is 2 can print");
    return 0;
}

