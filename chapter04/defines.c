//
// Created by ColorXJH on 2023/1/9.
// 使用limit.h和float头文件中定义的明示常量
#include <stdio.h>
#include <limits.h>//整形限制
#include <float.h>//浮点型限制
int main(void){
    printf("some number limits for this system:\n");
    printf("biggest int:%d\n",INT_MAX);
    printf("smallest long long:%lld\n",LLONG_MIN);
    printf("one byte =%d bits on this system.\n",CHAR_BIT);
    printf("largest double:%e\n",DBL_MAX);
    //保留全部精度的float类型最小正数
    printf("smallest normal float:%e\n",FLT_MIN);
    //float类型的最少有效数字位数（10进制）
    printf("float precision=%d digits\n",FLT_DIG);
    //1.00与比1.00大的最小float类型之间的差值
    printf("float epsilon= %e\n",FLT_EPSILON);
    return 0;
}

