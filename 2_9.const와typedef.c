//1-------------------------------------------------
#include <stdio.h>

int main(void)
{
    int n1 = 10;
    int n2 = 10;

    const int *p1 = &n1; //p1을 따라가면 const
    int *const p2 = &n1; //p2가 const

    p1 = &n2; //OK
    *p1 = 20; //Error

    p2 = &n2; //Error
    *p2 = 20; //OK
}

//2-------------------------------------------------

typedef const int *PTY_TO_CONST;
typedef int *const Const_PTR;

#include <stdio.h>

int main(void)
{
    int n1 = 10;
    int n2 = 10;

    PTY_TO_CONST p1 = &n1; //p1을 따라가면 const
    Const_PTR p2 = &n1;    //p2가 const

    p1 = &n2; //OK
    *p1 = 20; //Error

    p2 = &n2; //Error
    *p2 = 20; //OK
}

//3-------------------------------------------------

typedef int *PINT;
typedef const PINT WHERE_CONST;

#include <stdio.h>

int main(void)
{
    int n1 = 10;
    int n2 = 10;

    WHERE_CONST p3 = &n1;

    p3 = &n2;
    *p3 = 20;
}
/*
WHERE_CONST가 cont int*의 뜻이 아니다
PINT가 const라는 뜻이다
즉 int*가 const라는 뜻이다.
WHERE_CONST p3 = &n1;는 p3이 const라는 뜻
*/

//4-------------------------------------------------

typedef int *PINT;
typedef PINT const WHERE_CONST;
//오해의 소지를 없앴다

#include <stdio.h>

int main(void)
{
    int n1 = 10;
    int n2 = 10;

    WHERE_CONST p3 = &n1;

    p3 = &n2;
    *p3 = 20;
}