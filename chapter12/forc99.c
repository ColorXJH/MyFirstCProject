//
// Created by ColorXJH on 2023-03-09.
// 新的c99块规则
#include <stdio.h>
int main(void){
    int n=8;
    printf("initially,n=%d at %p\n",n,&n);
    for (int n = 1; n < 3; ++n)
        printf("loop1:n=%d at %p\n",n,&n);
    printf("after loop1,n=%d at %p\n",n,&n);
    for (int n = 1; n < 3; ++n) {
        printf("loop2 index n=%d at %p\n",n,&n);
        int n=6;
        printf("loop2: n=%d at %p\n",n,&n);
        n++;
    }
    printf("after loop2,n=%d at%p\n",n,&n);
    return 0;
}
//8 oc

//1 ox
//2 ox

//8 oc

//1 od
//6 op
//2 od
//6 op

//8 oc