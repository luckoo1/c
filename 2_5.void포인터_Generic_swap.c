/*
이 함수가 다양한 Data Type에서 동작하게 만들고 싶다
Generic(일반화)프로그래밍이란?
하나의 함수(알고리즘)이 특정한 타입에만 동작하지 않고 다양한 타입에 동작할 수 있게 만드는 프로그래밍 기술
*/
#include <stdio.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(void)
{
    double a = 10; // double을 쓰든 int를 쓰든 되게 하고 싶다.
    double b = 20;

    swap(&a, &b);

    printf("%d %d\n", a, b);
}

//2-------------------------------------------------
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
    가장작은 type인 "char*"를 사용했다.
    */
    char *pc1 = (char *)x;
    char *pc2 = (char *)y;
    /*
    3.
    char *pc1 = (char *)x;
    char *pc2 = (char *)y;
    명시적 캐스팅해도 C에서는 문제가 없으나
    C++에서는 error니깐 의도를 명확하게 해주기 위해서 사용했다.
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
    10.000000, 20.000000가 나온다.
    결국 안바뀌고 그대로나온다(그림필기 참조)
    double은 8바이트인데 char는 1바이트다
    pc1과 pc2는 한바이트만 가리키니깐 한 바이트면 교환된다.
    */
}

//3-------------------------------------------------
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
    //루프를 돌면서 다 바꾼다
    for (int i = 0; i < es; i++)
    {
        char temp = pc1[i];
        pc1[i] = pc2[i];
        pc2[i] = temp;
    }
}

int main(void)
{
    double a = 10;
    double b = 20;

    swap(&a, &b, sizeof(a));

    printf("%f %f\n", a, b);
}

/*
void포인터로 받는다는 건 주소만 받지, 크기에 대한 정보가 없다는 거다.
이 방법은 size_t es의 크기가 커지면 오래걸릴수도 있다.
*/