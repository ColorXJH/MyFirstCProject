//
// Created by ColorXJH on 2023-03-10.
//
#include <stdio.h>
int static_store;
int main(void){
    int n=2;
    if(n++>1||n--<1){
        printf("%d\n",n);
    }
    printf("-----%d\n",static_store);
    return 0;
}

