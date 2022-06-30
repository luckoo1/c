//2_5.void포인터를이용한Generic_swap.c를 꼭 참고해라
//2_5에서는 요소의 크기만큼 반복해서 교환하는 방법을 사용했다.
//버퍼를 할당해서 교환하는 방법을 사용해보자
#include <stdio.h>
#include <stdlib.h> //malloc
#include <string.h> //memcpy

void swap(void *x, void *y, size_t es)
{
    //es 크기의 버퍼를 만들었다.
    void *temp = mallos(es);
    //타입정보 필요없이 주소만 교환했다.

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
//아주 큰 크기의 데이터라면 malloc이 나을수 있다.