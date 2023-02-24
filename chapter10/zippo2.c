//
// Created by ColorXJH on 2023-02-24.
// 通过指针获取zippo信息
#include <stdio.h>
int main(void){
    int zippo[4][2]={//地址
            {2,3},//F0 F4  zippo[0]     zippo[0][0]  zippo[0][1]
            {1,2},//F8 Fc  zippo[1]     zippo[1][0]  zippo[1][1]
            {3,8},//00 04  zippo[2]     zippo[2][0]  zippo[2][1]
            {7,9} //08 0c  zippo[3]     zippo[3][0]  zippo[3][1]
    };
    int (*ps)[2];
    ps=zippo;
    //F0  F8
    printf("ps=%p  ps+1=%p\n",ps,ps+1);
    //F0  F4
    printf("ps[0]=%p ps[0]+1=%p\n",ps[0],ps[0]+1);
    //F0  F4
    printf("*ps=%p  *ps+1=%p\n",*ps,*ps+1);
    //2
    printf("ps[0][0]=%d\n",ps[0][0]);
    //2
    printf("*ps[0]=%d\n",*ps[0]);
    //2
    printf("**ps=%d\n",**ps);
    //8
    printf("ps[2][1]=%d\n",ps[2][1]);
    //8
    printf("*(*(ps+2)+1)=%d\n",*(*(ps+2)+1));
    return 0;
}

//虽然ps是一个指针不是数组名，也可以使用ps[2][1]这样的写法，可以使用数组表示法或指针表示法来表示一个数组元素，既可以使用数组名也可以使用指针名
//zippo[m][n]==*(*(zippo+m)+n)
//ps[m][n]==*(*(ps+m)+n)