//
// Created by ColorXJH on 2023-03-02.
// 字符串相关函数
#include <stdio.h>
#include <string.h>
void fit(char *string,unsigned int size);
int main(void){
    char mesg []="Things　should　be　as　simple　as　possible,"
                   "　but　not　simpler.";
    puts(mesg);
    fit(mesg,26);
    puts(mesg);
    puts("Let's　look　at　some　more　of　the　string.");
    puts(mesg+27);
    return 0;
}

void fit(char *string,unsigned int size){
    if(strlen(string)>size){
        string[size]='\0';
    }
}



