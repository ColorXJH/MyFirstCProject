//
// Created by ColorXJH on 2023-03-20.
// 嵌套结构案例
#include <stdio.h>
#define LEN 20
const char *msgs[5]={
        "hello",
        "nice to meet you",
        "i am fine,thank you",
        "what is your name",
        "see you"
};
struct  names{//结构
    char first[LEN];
    char last[LEN];
};
struct guy{//嵌套结构
    struct names handle;
    char food[LEN];
    char job[LEN];
    float inCome;
};
int main(void){
    struct guy fellow={//初始化一个结构变量
            {"color","xjh"},
            "watermelon",
            "computer",
            23.44
    };
    printf("dear %s,\n\n",fellow.handle.first);
    printf("%s %s.\n",msgs[0],fellow.handle.first);
    return 0;
}

