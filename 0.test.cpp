#include <stdio.h>

int main(void)
{
    int x[3] = {10, 20, 30};

    printf("%d\n", x[0]); //10
    printf("%d\n", x);    // 6422288
    //배열의 이름으로 출력하면 주소가 나옴
    int *p = x;
}