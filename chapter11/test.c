//
// Created by ColorXJH on 2023-03-07.
//
#include <stdio.h>
char *pr(char *str);
int main(void){
    char *x = pr("Ho Ho Ho!");
    return 0;
}


char *pr(char *str)
{
    char *pc;
    pc=str;
    while (*pc)
        putchar(*pc++);
    do{
        putchar(*--pc);
    }while(pc-str);
    return(pc);
}