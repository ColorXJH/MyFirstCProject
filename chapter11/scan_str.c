//
// Created by ColorXJH on 2023-03-02.
// 使用scanf()函数
#include <stdio.h>
int main(void){
    char name1[11],name2[11];
    int count;
    printf("please enter 2 names.\n");
    //jackjonsss nuee
    //i read the 2 name are jackj and onsss.
    //说明截断时，name2从上一次截断的地方继续读取，知道换行符
    count= scanf("%5s %10s",name1,name2);
    printf("i read the %d name are %s and %s.\n",count,name1,name2);
    return 0;
}

