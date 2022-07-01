//함수 포인터를 반환하는 함수
#include <stdio.h>

int Add(int a, int b)
{
    printf("Add : %d %d\n", a, b);
    return a + b;
}

? goo() //반환값이 함수의 주소
{
    return &Add; //퀴즈
    //반환값이 함수의 주소
}

int main(void)
{
}

//-------------------------------------------------
#include <stdio.h>

int Add(int a, int b)
{
    printf("Add : %d %d\n", a, b);
    return a + b;
}
/*
반환값적는 방법을 알아보자
1.함수 포인터 타입을 만들자
int(*f)(int,int); //&Add의 주소를 담을 수 있는 함수 포인터

2.변수자리에 "함수이름()"를 넣자
int(   *f     )(int,int);
int(  *goo()  )(int,int);
f 자리에 goo()넣은 격이다.(int(*f)(int,int); => int(*goo())(int,int);)

goo()라는 함수가 반환값이 int(*)(int,int) type다라는 뜻이다.
*/
int (*goo())(int, int)
{
    return &Add;
    // 4."return Add;"라고 적어도 무방하다
}

int main(void)
{
    /*
    3.
    goo();
    이렇게 적으면 반환하는건 함수포인터
    뒤에 인자를 적어줘야한다.
    goo()(1,2);
    */
    goo()(1, 2); //이런 모양으로 불러야한다.
                 // Add(1,2)와 동일한 모양
}