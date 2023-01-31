//
// Created by ColorXJH on 2023-01-31.
// 根据用户键入的整数求和
#include <stdio.h>
int main(void){
    long num;
    long sum=0L;
    int status;
    printf("please enter an integer to be summed\n");
    printf("q to quit\n");
    status= scanf("%ld",&num);//读取成功返回1，读取失败返回0，或者读取到吗、文件末尾EOF返回-1
    while (status==1){
        sum=sum+num;
        printf("please enter another integer(q to quit)\n");
        status= scanf("%ld",&num);
    }
    printf("those integer sum to %ld\n",sum);
    return 0;
}

