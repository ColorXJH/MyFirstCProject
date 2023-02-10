//
// Created by ColorXJH on 2023-02-10.
// 找出两个整数中较小的一个
#include <stdio.h>
int int_min(int,int);
int main(void){
    int a,b;
    printf("enter a pair of integer:\n");
    while(scanf("%d %d",&a,&b)==2){
        printf("the less integer of those is :%d\n",a,b, int_min(a,b));
        printf("enter a pair of integer(q to quit).\n");
    }
    printf("bye!");
    return 0;
}
int int_min(int a,int b){
    int min;
    if(a<b){
        return min=b;
    }else{
        return min=a;
    }
}