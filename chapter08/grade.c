//
// Created by ColorXJH on 2023-02-10.
// 处理换行符
#include <stdio.h>
int main(void){
    int score;
    char grade;
    printf("Enter the score.\n");
    while(scanf("%d",&score)==1){
        while(getchar()!='\n'){
            continue;
        }
        printf("Enter the letter grade.\n");
        grade = getchar();
        printf("%d--%c\n",score,grade);
        printf("Enter the score.\n");
    }
}

