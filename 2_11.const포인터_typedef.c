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

typedef const int *PTY_TO_CONST; //따라가면 const니깐
typedef int *const Const_PTR;    //상수 포인터니깐

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
typedef const int* WHERE_CONST;로생각해서
따라가면 const int라고 생각할수 있다.
하지만 이건
typedef const PINT WHERE_CONST;
PINT자체가 const란 말이다.

p3 = &n2;//error
*p3 = 20;//OK

p3가 const다.
WHERE_CONST가 cont int*의 뜻이 아니다
PINT가 const라는 뜻이다
즉 int*가 const라는 뜻이다.
WHERE_CONST p3 = &n1;는 p3이 const라는 뜻
*/

// 4-------------------------------------------------
//오해의 소지를 없애자.
typedef int *PINT;
typedef PINT const WHERE_CONST;


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
typedef PINT const WHERE_CONST;
typedef int* const WHERE_CONST;가 되니깐
*/

/*
typedef PINT const WHERE_CONST;
typedef const PINT WHERE_CONST;
data type과 const의 순서는 바꿀수 있으니깐 위에 두개는 같다.

"const int"보다 "int const"를 선호하는 사람이 이 이유때문에 그런거다.
*/