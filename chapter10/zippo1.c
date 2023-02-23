//
// Created by ColorXJH on 2023-02-23.
// zippo的相关信息
#include <stdio.h>
int main(void){
    int zippo[4][2]={//地址
            {2,3},//00 04  zippo[0]     zippo[0][0]  zippo[0][1]
            {1,2},//08 0c  zippo[1]     zippo[1][0]  zippo[1][1]
            {3,8},//10 14  zippo[2]     zippo[2][0]  zippo[2][1]
            {7,9} //18 1c  zippo[3]     zippo[3][0]  zippo[3][1]
    };
    //引用的引用，指针的指针，zippo是zippo[0]的指针，zippo[0]是zippo[0][0]的指针
    //00 08
    printf("zippo=%p zippo+1=%p \n",zippo,zippo+1);
    //00 04
    printf("zippo[0]=%p zippo[0]+1=%p\n",zippo[0],zippo[0]+1);
    //00 04  *zippo指针指向第一个数组 *zippo+1指针指向第一个数组的第二个元素
    printf("*zippo=%p *zippo+1=%p\n",*zippo,*zippo+1);
    //解引用获取第一个元素的值
    printf("zippo[0][0]=%d\n",zippo[0][0]);
    //第一个数组的第一个元素
    printf("(*zippo)[0]=%d\n",(*zippo)[0]);
    //同上
    printf("*(zippo[0])=%d\n",*(zippo[0]));
    //同上，
    printf("**zippo=%d\n",**zippo);
    //第三个数组的第二个元素
    printf("zippo[2][1]=%d\n",zippo[2][1]);
    //zippo+2表示：zippo是数组的第一个子数组，+2表示第三个子数组，后面解引用表示第三个子数组的第一个元素，+1表示第二个元素指针
    printf("*(*(zippo+2)+1)=%d\n",*(*(zippo+2)+1));
    return 0;
}

