#include <stdio.h>

int main(void) {
    //macbook: option+command+l windows:ctrl+alt+l
    // \n 换行缩紧
    int dogs;
    printf("How many dogs do you have?\n");
    scanf("%d", &dogs);
    printf("So you have %d dog(s)!\n", dogs);
    return 0;
}
