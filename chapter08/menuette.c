//
// Created by ColorXJH on 2023-02-10.
// 菜单程序
#include <stdio.h>
char get_choice(void);
void count(void);
char get_first(void);
int get_int(void);
//入口程序
int main(void){
    //debug时不输出问题，或者在scanf()和printf()函数之间调用刷新函数fflush(stdout)
    //setbuf(stdout, 0);
    int choice;
    //void count(void);
    while ((choice=get_choice())!='q'){
        switch (choice) {
            case 'a':
                printf("buy low,sell high.\n");
                break;
            case 'b':
                putchar('\a');
                break;
            case 'c':
                count();
                break;
            default:
                printf("program error!\n");
                break;
        }
    }
    printf("bye.\n");
    return 0;
}
//
void count(void){
   int n,i;
    printf("count how far? enter an integer:\n");
    n=get_int();
    for(i=1;i<=n;i++){
        printf("%d\n",i);
    }
    //清理数字后面的字母以及换行符，放置下次调用出问题（清理本行除数字外的其他所有字符）
    //防止下次get_choice=》get_first产生字符为'\n'导致不明行为
    while (getchar()!='\n')
        continue;
}

char get_choice(void){
    int ch;
    printf("enter the letter of your choice:\n");
    printf("a. advice         b. bell\n");
    printf("c. count          d. quit\n");
    //解决debug不输出问题
    fflush(stdout);

    ch=get_first();
    while ((ch<'a'||ch>'c')&&ch!='q'){
        printf("please response with a,b,c,or q.\n");
        ch=get_first();
    }
    return ch;
}

char get_first(void){
    int ch;
    ch=getchar();
    while (getchar()!='\n')
        continue;
    return ch;
}

//获取输入的整数
int get_int(void){
    int input;
    char ch;
    //scanf 忽略空白和换行
    while (scanf("%d",&input)!=1){
        while ((ch=getchar())!='\n')
            putchar(ch);
        printf(" is not an integer.\nplease enter an integer value such as 21,-123:");
    }
    return input;
}
