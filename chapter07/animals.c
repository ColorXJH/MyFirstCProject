//
// Created by ColorXJH on 2023-02-07.
// 使用switch语句
#include <stdio.h>
#include <ctype.h>
int main(void){
    char ch;
    printf("give me a letter of the alphabet, and i will give ");
    printf("an animal name \nbeginning with that letter.\n");
    printf("please type in a letter ;type # to end my act.\n");
    while((ch=getchar())!='#'){
        if('\n'==ch){//如果开始读取的是换行符，则继续
            continue;
        }
        if(islower(ch)){
            switch (ch) {
                case 'a':
                    printf("this is a\n");
                    break;
                case 'b':
                    printf("this is b\n");
                    break;
                case 'c':
                    printf("this is c\n");
                    break;
                default:
                    printf("this is other\n");
            }
        }else{
            printf("only accept lower letter or a # \n");

        }
        //跳过输入行的其他部分，读取并丢弃字符，最后丢弃的是换行符，所以下一个被读取的是下一行首字母，
        //外层循环读取首字母并赋值给ch
        while(getchar()!='\n'){
            continue;
        }
        printf("please enter a letter or a #.\n");

    }
    printf("bye!");
    return 0;
}

