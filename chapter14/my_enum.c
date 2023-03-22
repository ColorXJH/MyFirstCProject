//
// Created by ColorXJH on 2023-03-21.
// 使用枚举类型的值
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
char *s_gets(char *st,int n);
enum spectrum{red,orange,yellow,green,blue,violet};
//这里的6可写可不写，不写则编译器自动根据初始化项数计算分配内存，这是一个数组指针，每项是一个char *,指向一个字符串
const char *colors[6]={
        "red","orange","yellow","green","blue","violet"
};
#define LEN 30
int main(void){
    char choice[LEN];
    enum spectrum color;
    bool color_is_found=false;
    puts("enter a color (empty line to quit):");
    while (s_gets(choice,LEN)!=NULL&&choice[0]!='\0'){
        for (color=red;color <=violet ;color ++) {
            if(strcmp(choice,colors[color])==0){
                color_is_found=true;
                break;
            }
        }
        if(color_is_found){
            switch (color) {
                case red:
                    puts("rose is red");
                    break;
                case orange:
                    puts("rose is orange");
                    break;
                case yellow:
                    puts("rose is yellow");
                    break;
                case green:
                    puts("rose is green");
                    break;
                case blue:
                    puts("rose is blue");
                    break;
                case violet:
                    puts("rose is violet");
                    break;
            }
        }else{
            printf("i dont know about the color %s.\n",choice);
            color_is_found=false;
            puts("next color,please (empty line to quit):");
        }
    }
    puts("Goodbye!");
    return 0;
}


//获取输入，处理换行符等问题
char *s_gets(char *st,int n){
    char *ret_val;
    int i=0;
    ret_val= fgets(st,n,stdin);
    if(ret_val){
        while (st[i]!='\n'&&st[i]!='\0'){
            i++;
        }
        if(st[i]=='\n'){
            st[i]='\0';//查找换行符并替换为空字符
        }else{
            while(getchar()!='\n'){
                continue;//清理输入行
            }
        }
    }
    return ret_val;
}

