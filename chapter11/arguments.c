//
// Created by ColorXJH on 2023-03-06.
// 带参数的main
#include <stdio.h>
int main(int argc,char* argv[]){
    int count;
    char * point;
    printf("the command line has %d arguments\n",argc-1);
    for (count = 1;count  <argc ; count++) {
        point=argv[count];
        //字符串打印的其实时一个指针地址，指向字符变量的值，然后遇到'\0'就停下来不打印了
        printf("%c--%c---%s--%p--%d\n",*point,*argv[count],argv[count],argv[count],*argv[count]);
        argv[count][1]='\0';//如此操作就会让每个变量的第二个字符变为空字符'\n',打印的就是只有一个首字符
        printf("%d---%s\n",count,argv[count]);
    }
    return 0;
}

