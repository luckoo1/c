//1-------------------------------------------------
#include <stdio.h>

int Add(int a, int b)
{
    return a + b;
}

int main(void)
{
    int x[3] = {1, 2, 3};

    ? p1 = &x;
    ? p2 = &Add;
}

//2-------------------------------------------------

#include <stdio.h>

int Add(int a, int b) //int(int,int) : 함수 타입
{
    return a + b;
}

int main(void)
{
    int x[3] = {1, 2, 3};
    //int[3] : 배열 타입

    int(*p1)[3] = &x;
    //int (*)[3] : 배열을 가리키는 포인터 타입

    int (*p2)(int, int) = &Add;
    //int(*)(int,int) : 함수를 가리키는 포인터 타입
}

/*
int[3] : 배열 타입
int (*)[3] : 배열을 가리키는 포인터 타입
int(int,int) : 함수 타입
int(*)(int,int) : 함수를 가리키는 포인터 타입
*/

//3-------------------------------------------------
#include <stdio.h>

int Add(int a, int b); //함수 선언
int (*f)(int, int);    //함수포인터변수 선언

typedef int FUNC(int, int);     //FUNC : 함수 타입
typedef int (*PFUNC)(int, int); //PFUNC : 함수포인터 타입

int Add(int a, int b)
{
    printf("Add : %d %d\n", a, b);
    return a + b;
}

//예제 1,2로 이걸 표현
void foo(int (*f)(int, int))
{
    f(1, 2);
}

//예제 1
void foo(FUNC *f) //함수의 포인터 타입을 인자로 받는다.
{
    f(1, 2);
}
//예제 2
void foo(PFUNC f) //함수의 포인터 타입을 인자로 받는다.
{
    f(1, 2);
}

//예제 3,4로 이걸 표현
int (*goo())(int, int)
{
    return Add;
}

//예제3
FUNC *goo() //반환값이 함수포인터
{
    return Add;
}

//예제4
PFUNC goo() //반환값이 함수포인터
{
    return Add;
}

/*
정리

배열타입과 배열을 가리키는 포인터 타입
int[3] : 배열 타입
int (*)[3] : 배열을 가리키는 포인터 타입

함수타입과 함수를 가리키는 포인터 타입
int(int,int) : 함수 타입
int(*)(int,int) : 함수를 가리키는 포인터 타입

함수타입과 typedef
typedef int FUNC(int, int); : FUNC : 함수 타입
typedef int (*PFUNC)(int, int); : PFUNC : 함수포인터 타입
*/
