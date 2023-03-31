//
// Created by ColorXJH on 2023-03-31.
// 使用names结构
#include "my_names.c"
int main(void){
    names  candidate;
    get_names(&candidate);
    printf("let's welcome ");
    show_names(&candidate);
    printf(" to this program!");
    return 0;
}

