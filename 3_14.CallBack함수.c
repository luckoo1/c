//1-------------------------------------------------
#include <stdio.h>

void foo(void)
{
    printf("Time\n");
}

int main(void)
{
    printf("Hello\n");
    printf("World\n");

    //프로그램이 종료되기 전에 foo함수를 반드시 호출하고 싶다
    foo();
}

//2-------------------------------------------------
#include <stdio.h>

void foo(void)
{
    printf("Time\n");
}

int main(void)
{
    printf("Hello\n");
    //나중에 내가 수정을 하다가 
    //아래의 코드처럼 어떤 조건이 만족되면서 foo()함수가 호출되지 않는다.
    if (1)
    {
        return;
    }
    printf("World\n");
    //프로그램이 종료되기 전에 foo함수를 반드시 호출하고 싶다
    foo();
}

//3-------------------------------------------------
#include <stdio.h>
#include <stdlib.h> //atexit()

void foo(void)
{
    printf("Time\n");
}

int main(void)
{
    printf("Hello\n");
    //나중에 내가 수정을 하다가 
    //아래의 코드처럼 어떤 조건이 만족되면서 foo()함수가 호출되지 않는다.
    if (1)
    {
        return;
    }
    atexit(&foo);
    /*
    C언어 표준에 atexit함수가 있다
    atexit(foo);이렇게 사용해도 된다.
    프로그램이 종료되기 이전에 "foo함수"를 호출한다.
    */
    printf("World\n");
}

/*
1.
atexit()표준함수
인자로 함수(주소)를 받아서 프로그램이 종료되기 전에 함수를 호출해준다.

2.
callback함수
함수의 호출시점에 프로그래머가 아닌 시스템에서 결정하는 함수
foo함수는 만들기는 사용자가 만들지만 호출은 시스템이 결정
사용자가 만든함수(함수 주소)를 시스템에 등록하면 시스템은 주어진 조건을 만족할때 해당함수를 호출한다.

3.
void atexit(void (*f)(void)) //반환값이 void, 인자도 void
{
}
atexit()표준함수는 위와 같은 모양으로 생겼다.

Callback함수로 등록하기 위한 함수는 함수 시그니쳐(반환값,인자,함수 호출규약)가 미리 약속되어 있다
atexit에 전달하기 위한 인자함수는 "void (void)"모양으로 만들어야 한다.
*/
