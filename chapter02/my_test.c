//
// Created by ColorXJH on 2022/12/31.
//
#include <stdio.h>
//函数的声明
void writeMyNameAndAddress(void);
void changeAgeToDay(int year);
void jolly(void);
void deny(void);
int main(void){
    printf("Master XJH\n");
    printf("Master\nXJH\n");
    printf("Master");
    printf(" XJH\n");
    writeMyNameAndAddress();
    changeAgeToDay(28);
    for (int i = 0; i < 3; ++i) {
        jolly();
    }
    deny();

}

void writeMyNameAndAddress(void){
    printf("my name is colorXJH and my address is china AnHui\n");
}

void changeAgeToDay(int year){
    int day=365*year;
    printf("my age change day is %d\n",day);
}

void jolly(void){
    printf("for he is a jolly good fellow\n");
}

void deny(void){
    printf("which no body can deny\n");
}