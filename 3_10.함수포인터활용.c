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
/*
함수포인터를 인자로 가지는 함수
*/

//3-------------------------------------------------
//함수 포인터를 반환하는 함수
#include <stdio.h>

int Add(int a, int b)
{
    printf("Add : %d %d\n", a, b);
    return a + b;
}

? goo()
{
    return &Add; //퀴즈
}

int main(void)
{
    //goo함수를 어떻게 불러야 할까
}

//4-------------------------------------------------

#include <stdio.h>

int Add(int a, int b)
{
    printf("Add : %d %d\n", a, b);
    return a + b;
}
/*
1.함수 포인터 타입을 만들자
int(*f)(int,int); //&Add의 주소를 담을 수 있는 함수 포인터

2.변수자리에 "함수이름()"를 넣자
int(*f)(int,int); => int(*goo())(int,int);
*/
int (*goo())(int, int)
{
    return &Add;
    //3."return Add;"라고 적어도 무방하다
}

int main(void)
{
    goo()(1, 2); //4.이런 모양으로 불러야한다.
                 //Add(1,2)와 동일한 모양
                 //goo()는 &Add를 반환하니깐 뒤에(1,2)를 붙여준거다
}