//
// Created by ColorXJH on 2023-03-20.
// 使用指向结构的指针
#include <stdio.h>
#define LEN 20
struct names{//占用40字节
    char first[LEN];
    char last[LEN];
};
struct guy{//占用84字节
    struct names handle;
    char food[LEN];
    char job[LEN];
    float inCome;
};

int main(void){
    struct guy fellow[2]={
            {{"color","xjh"},
             "food1",
             "job1",
             24.44
                },
            {
                    {"color2","xjh2"},
                    "food2",
                    "job2",
                    25.66
            }

    };
    struct guy *him;//指向结构的指针
    printf("address #1: %p #2: %p\n", &fellow[0], &fellow[1]);
    /* 告诉编译器该指针指向何处 */
    him = &fellow[0];
    printf("point#1:%p,point#2:%p\n",him,him+1);
    printf("him->income is $%.2f,(*him).income is $%.2f\n",him->inCome,(*him).inCome);
    him++;//指针指向下一个结构
    printf("him->food is %s,him->handle.last is %s\n",him->food,him->handle.last);
    return 0;
}

//在有些系统中，一个结构的大小可能大于它各成员大小之和。这
//是因为系统对数据进行校准的过程中产生了一些“缝隙”。例如，有些系统必
//须把每个成员都放在偶数地址上，或4的倍数的地址上。在这种系统中，结
//构的内部就存在未使用的“缝隙”
