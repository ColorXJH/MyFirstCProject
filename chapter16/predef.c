//
// Created by ColorXJH on 2023-04-03.
// 预定义宏和预定义标识符
#include <stdio.h>
void why_me();
int main(void){
    printf("the file is %s.\n",__FILE__);
    printf("the date is %s.\n",__DATE__);
    printf("the time is %s.\n",__TIME__);
    printf("the version is %ld.\n",__STDC_VERSION__);
    printf("the line is %d.\n",__LINE__);
    printf("the function is %s.\n",__func__ );
    why_me();
    return 0;
}
void why_me(){
    printf("this function is %s.\n",__func__ );
    printf("this line is %d line.\n",__LINE__);
}

