// 3_9.함수포인터_기초.c 참조
//1-------------------------------------------------
//함수 포인터를 인자로 가지는 함수
#include <stdio.h>

int Add(int a, int b)
{
    printf("Add : %d %d\n", a, b);
    return a + b;
}

void foo(? f) //퀴즈
{
    f(1, 2);
}

int main(void)
{
    foo(&Add);
}

//2-------------------------------------------------

#include <stdio.h>

int Add(int a, int b)
{
    printf("Add : %d %d\n", a, b);
    return a + b;
}

void foo(int (*f)(int, int))
{
    f(1, 2);
}

int main(void)
{
    foo(&Add); //주소연산자(&)를 적어줘도 되고
    foo(Add);  //함수의 이름만 적어줘도 된다
               //함수의 이름은 함수의 주소로 명시적 형변환되니깐
}