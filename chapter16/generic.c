//
// Created by ColorXJH on 2023-04-03.
// 定义泛型宏
#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <math.h>
#define RAD_TO_DEG (180/(4*atan(1)))
//泛型平方根函数  SQRT()的定义也许更简洁。_Generic表达式的值就是函数名，如sinf ，函数的地址可以代替该函数名
//所以_Generic表达式的值是一个指向函数的指针,然而，紧随整个_Generic表达式之后的是(X)
//(参数)表示函数指针。因此，这是一个带指定的参数的函数指针。
#define SQRT(X) _Generic((X),\
long double: sqrtl, \
default: &sqrt, \
float: sqrtf)(X)
//泛型正弦函数，角度的单位为度  每一个标号的值是一个特定的函数调用 例如：sinl((X)/RAD_TO_DEG)
#define SIN(X) _Generic((X),\
long double: sinl((X)/RAD_TO_DEG),\
default:sin((X)/RAD_TO_DEG),\
float:sinf((X)/RAD_TO_DEG)\
)
//简而言之，对于SIN()，函数调用在泛型选择表达式内部；而对于SQRT(),先对泛型选择表达式求得一个指针，然后通过该指针调用它所指向的函数

int main(void){
    float x = 45.0f;
    double xx = 45.0;
    long double xxx = 45.0L;
    long double y = SQRT(x);
    long double yy = SQRT(xx);
    long double yyy = SQRT(xxx);
    //linux中使用%Lf Windows要加宏定义
    //在windows下想要输出， 可在编译选项中添加-D__USE_MINGW_ANSI_STDIO=1
    //或者在文件开头添加#define __USE_MINGW_ANSI_STDIO 1(必须位于#include之前) ，原因是 mingw的long double数据格式和msvcrt中的不兼容 。
    printf("%.17Lf\n", y);// 匹配 float
    printf("%.17Lf\n", yy);// 匹配 default
    printf("%.17Lf\n", yyy);// 匹配 long double
    int i = 45;
    yy = SQRT(i);// 匹配 default
    printf("%.17Lf\n", yy);
    yyy = SIN(xxx);// 匹配 long double
    printf("%.17Lf\n", yyy);
    return 0;
}