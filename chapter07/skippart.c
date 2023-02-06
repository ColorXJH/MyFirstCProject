//
// Created by ColorXJH on 2023-02-06.
// 使用continue跳过部分循环
#include <stdio.h>
int main(void){
    const float MIN=0.0f;
    const float MAX=100.0f;
    float score;
    float total=0.0f;
    int n=0;
    float min=MAX;
    float max=MIN;
    printf("enter the first score (q to quit):\n");
    while(scanf("%f",&score)==1){
        if(score<MIN||score>MAX){
            printf("%0.1f is an invalid value,try again:\n",score);
            continue;
        }
        printf("accepting %0.1f:\n",score);
        min=(score<min)?score:min;
        max=(score>max)?score:max;
        total+=score;
        n++;
        printf("enter next score (q to quit):\n");
    }
    if(n>0){
        printf("average of %d scores is %0.1f.\n",n,total/n);
        printf("low =%0.1f, high=%0.1f\n",min,max);
    }else{
        printf("no valid scores were entered.\n");
    }
    return 0;
}

