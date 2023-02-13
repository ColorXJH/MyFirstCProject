//
// Created by ColorXJH on 2023-02-13.
// 房间费率程序
#include <stdio.h>
//#include "hotel.h" //定义符号常量，声明函数 //行2
#include "hotel.c" //引用其他源文件(使用其中的函数) //行1
//(在clion中使用这个就可以编译，在windows命令行中，去掉行1，打开行2，运行 gcc usehotel.c hotel.c 会生成新的exe文件，运行该可执行文件也可以)
int main(void){
    int nights;
    double hotel_rate;
    int code;
    while((code=menu())!=QUIT){
        switch (code) {
            case 1:
                hotel_rate=HOTEL1;
                break;
            case 2:
                hotel_rate=HOTEL2;
                break;
            case 3:
                hotel_rate=HOTEL3;
                break;
            case 4:
                hotel_rate=HOTEL4;
                break;
            default:
                hotel_rate=0.0;
                printf("Oops!\n");
                break;
        }
        nights=getNights();
        showPrice(hotel_rate,nights);
    }
    printf("thanks for your visit ,goodbye!\n");
    return 0;
}


