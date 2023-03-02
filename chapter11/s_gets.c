//
// Created by ColorXJH on 2023-03-01.
// 自定义函数：读取整行输入并用空字符代替换行符，或者读取一部分输入，并丢弃其余部分
#include <stdio.h>
char *s_get(char *st,int n);
int main(void){
    char chs[5]="sxs";
    printf("%s\n",chs);
    printf("%s\n",chs[3]);
    printf("%c\n",chs[3]);
    char ch[5];
    char *ret=s_get(ch,4);
    puts(ret);
    return 0;
}

char *s_get(char *st,int n){
    char * ret_val;
    int i=0;
    ret_val= fgets(st,n,stdin);
    if(ret_val){//ret_val!=NULL
        while (st[i]!='\n'&& st[i]!='\0')
            i++;
        if(st[i]=='\n'){//换行使用空格代替
            st[i]='\0';
        }else{
            while (getchar()!='\n') //丢弃空字符和换行符之间的数据
                continue;
        }
    }
    return  ret_val;
}

//为什么要丢弃过长输入行中的余下字符。这是因为，输
//入行中多出来的字符会被留在缓冲区中，成为下一次读取语句的输入。例
//如，如果下一条读取语句要读取的是 double 类型的值，就可能导致程序崩
//溃。丢弃输入行余下的字符保证了读取语句与键盘输入同步