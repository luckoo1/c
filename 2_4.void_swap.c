//1-------------------------------------------------
#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(void)
{
    int a = 10;
    int b = 20;

    swap(&a, &b);

    printf("%d %d\n", a, b);
}

//2-------------------------------------------------
#include <stdio.h>
//2. 이 함수가 다양한 Data Type에서 동작하게 만들고 싶다
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(void)
{
    //1.double로 바꾸었다.
    double a = 10;
    double b = 20;

    swap(&a, &b);

    printf("%d %d\n", a, b);
}

//3-------------------------------------------------
#include <stdio.h>

/*
1. 
int뿐만 아니라 다른 타입도 인자로 보낼 수 있어야 한다.
함수의 인자를 void*로 만든다.
모든 type를 받을 수 있다.
*/
void swap(void *x, void *y)
{
    /*
    2. 
    메모리의 내용을 접근할 수 있어야 한다.
    void*를 다른 타입(char*)로 캐스팅 한 후에 사용한다.
    */
    char *pc1 = (char *)x;
    char *pc2 = (char *)y;
    /*
    3.
    char *pc1 = (char *)x;
    char *pc2 = (char *)y;
    명시적 캐스팅해도 C에서는 문제가 없으니
    C++에서는 error이고 의도를 명확하게 해주기 위해서 사용했다.
    */

    char temp = *pc1;
    *pc1 = *pc2;
    *pc2 = temp;
}

int main(void)
{
    double a = 10;
    double b = 20;

    swap(&a, &b);

    printf("%f %f\n", a, b);
    /*
    4.
    그대로나온다(그림필기 참조)
    double은 8바이트인데 char는 1바이트다
    pc1과 pc2는 한바이트만 가리키니깐 한 바이트면 교환된다.
    */
}

//4-------------------------------------------------
#include <stdio.h>

/*
1.
요소의 주소뿐만 아니라 요소의 크기도 같이 전달한다
요소의 크기만큼 반복해서 교환한다
*/
void swap(void *x, void *y, size_t es)
{

    char *pc1 = (char *)x;
    char *pc2 = (char *)y;

    for (int i = 0; i < es; i++)
    {
        char temp = pc1[i];
        pc1[i] = pc2[i];
        pc2[i] = temp;
    }
    //루프를 돌면서 다 바꾼다
}

int main(void)
{
    double a = 10;
    double b = 20;

    swap(&a, &b, sizeof(a));

    printf("%f %f\n", a, b);
}

//void포인터로 받는다는 건 주소만 받지, 크기에 대한 정보가 없다는 거다.

//이 방법은 size_t es의 크기가 커지면 오래걸릴수도 있다.

//5-------------------------------------------------
//버퍼를 할당해서 교환하는 방법을 사용해보자
#include <stdio.h>
#include <stdlib.h> //malloc
#include <string.h> //memcpy

void swap(void *x, void *y, size_t es)
{
    //es 크기의 버퍼
    void *temp = mallos(es);

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