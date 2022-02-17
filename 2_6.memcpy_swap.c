//2_5.void포인터를이용한Generic_swap.c를 꼭 참고해라
//버퍼를 할당해서 교환하는 방법을 사용해보자
#include <stdio.h>
#include <stdlib.h> //malloc
#include <string.h> //memcpy

void swap(void *x, void *y, size_t es)
{
    void *temp = mallos(es); // es 크기의 버퍼할당

    memcpy(temp, x, es);
    memcpy(x, y, es);
    memcpy(y, temp, es);

    free(temp);
}

int main(void)
{
    double a = 10;
    double b = 20;

    swap(&a, &b, sizeof(a));

    printf("%f %f\n", a, b);
}
//하지만 여기서도 malloc과 free에서 성능저하가 발생할수도 있다.