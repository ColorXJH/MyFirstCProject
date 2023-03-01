//
// Created by ColorXJH on 2023-03-01.
// 指针数组，字符串数组
#include <stdio.h>
#define SLEN 40
#define LIM 5
int main(void){
    //mytalents是一个内含5个指针的数组【】优先级比*高，先于【】结合表示一个数组是5个char类型元素，再与*结合表示这5个元素都是指针类型
    //每个指针分别是char类型的指针，正好指向子数组的首元素地址，其中指针再系统中占用8个字节，所以指针mytalents=5*8=40个字节
    const char *mytalents[LIM] = {
            "Adding　numbers　swiftly",
            "Multiplying　accurately",
            "Stashing　data",
            "Following　instructions　to　the　letter",
            "Understanding　the　C　language"
    };
    //yourtalents是一个二维数组，一个维度是5，另一个维度是40，表示一共包含5*40个char类型字符，一个char占用一个字节，则共占用5*40=200个字节
    char yourtalents[LIM][SLEN]={
            "Walking　in　a　straight　line",
            "Sleeping",
            "Watching　television",
            "Mailing　letters",
            "Reading　email"
    };
    int i;
    puts("let's compare talents.");
    printf("%-36s  %-25s\n","My talents","Your talents");
    for (int i = 0; i < LIM; ++i) {
        printf("%-36s  %-25s\n",mytalents[i],yourtalents[i]);
    }
    printf("sizeof mytalents:%d,sizeof yourtalents:%d\n", sizeof(mytalents),sizeof(yourtalents) );
    return 0;
}

