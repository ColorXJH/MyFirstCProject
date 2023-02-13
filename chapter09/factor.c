//
// Created by ColorXJH on 2023-02-13.
// 尾递归等价于循环
#include <stdio.h>
long fact(int n);
long rfact(int n);
int main(void){
    printf("enter number 0-12 \n");
    int num;
    long sum1,sum2;
    while(scanf("%d",&num)==1){
        if(num>=0 && num<=12){
            sum1=fact(num);
            sum2= rfact(num);
            printf("sum1 is %ld and sum2 is %ld\n",sum1,sum2);
        }else{
            printf("error data \n");
        }
    }
    printf("bye! \n");
    return 0;
}
//循环阶乘
long fact(int n){
    long ans;
    for(ans=1;n>0;n--){
        ans*=n;
    }
    return ans;
}
//尾递归
long rfact(int n){
    long ans;
    if(n>0){
        ans=n*rfact(n-1);
    }else{
        ans=1;
    }
    return ans;
}

