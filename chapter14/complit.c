//
// Created by ColorXJH on 2023-03-20.
// 复合字面量
#include <stdio.h>
#define MAX_TITLE 41
#define MAX_AUTH 31
struct book{
    char title[MAX_TITLE];
    char author[MAX_AUTH];
    float value
};
int main(void){
    struct book read_list;
    int score;
    printf("enter the test score:\n");
    scanf("%d",&score);
    if(score>84){
        read_list=(struct book){"color","xjh",99.99};
    }else{
        read_list=(struct book){"kcy","niuniu",666};
    }
    printf("your read_list is %s by %s and price is %.2f:\n",read_list.title,read_list.author,read_list.value);

    return 0;
}

