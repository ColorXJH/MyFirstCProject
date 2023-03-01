//
// Created by ColorXJH on 2023-03-01.
// 指针和字符串
#include <stdio.h>
int main(void){
    const char message2[]="dont be a fool!";
    char *message="dont be a fool!";
    const char *copy;
    const char *copy2;
    //指针的值都指向首字符的地址，让copy也指向message指向的字符串
    //注意：指针指向的字符字面量不能修改，数组指向的字符字面量可以修改
    copy=message;
    //指针的值指向message2的地址
    copy2=message2;
    printf("%s\n",copy);
    printf("%p\n","dont be a fool!");
    //message指向"dont be a fool!"首个字符的地址值
    printf("message=%s;&message=%p;value=%p\n",message,&message,message);
    printf("copy=%s;&copy=%p;value=%p\n",copy,&copy,copy+1);

    printf("-------------------\n");
    //
    printf("message2=%s;&message2=%p;value2=%p\n",message2,&message2,message2);

    printf("message2[1]=%p\n",&message2[1]);
    printf("copy2=%s;&copy2=%p;value2=%p\n",copy2,&copy2,copy2+1);
    return 0;
}

