//
// Created by ColorXJH on 2023-03-10.
// 多次掷色子模拟程序，与diceroll.c一起编译
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "diceroll.h"
#include "diceroll.c"//有原型有声明，也可以单独把头文件放过来
int main(void){
    int dice,roll;
    int sides,status;
    srand((unsigned int ) time(0));//设置随机种子，方便后面调用roll_n_dice==》rollem==》rand()函数师种子不随机
    //输入需要掷色子的面数
    printf("enter the number of sides per die,0 to stop.\n");
    while (scanf("%d",&sides)==1&&sides>0){
        //需要掷色子的次数
        printf("how many die?\n");
        if((status= scanf("%d",&dice))!=1){
            //处理输入错误或者END OF FILE
            if(status==EOF){
                break;//退出循环
            }else{
                //处理错误输入，如果不匹配则还是将数据放在缓冲区，下次读取还是从这里读，
                printf("you should enter an integer,lets begin again .\n");
                while (getchar()!='\n'){
                    continue;//处理缓冲区的数据，换行符之前的都过掉
                }
                printf("how many sides? enter 0 to stop.\n");
                continue;//进行循环的下一轮迭代
            }
        }
        roll= roll_n_dice(dice,sides);
        printf("you have rolled a %d using %d %d-sided dice.\n",roll,dice,sides);
        printf("how many sides? enter 0 to stop.\n");
    }
    printf("the rollem() function was called %d times.\n",roll_count);
    printf("GOOD　FORTUNE　TO　YOU!\n");
    return 0;
}

