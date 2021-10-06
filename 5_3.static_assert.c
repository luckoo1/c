//1-------------------------------------------------
#include <stdio.h>
#include <assert.h>

static_assert(sizeof(int *) == 8);
//컴파일 시간에 인자의 유효성을 확인한다
/*
"sizeof(int *) == 8"을 컴파일시간에 조사해서
실패하면 컴파일을 멈춰라
즉 컴파일시간에 64bit가 아니면 멈추라는 말이다.
*/

void foo(int age)
{
    //실행시간에 인자의 유효성을 확인한다.
    assert(age > 0);
}
int main(void)
{
    foo(-10);
}

//2-------------------------------------------------
#include <stdio.h>
#include <assert.h>

#define static_assert(expr) \
    char __static_assert_failed[(expr) ? 1 : -1];

//char형식의 배열  __static_assert_failed[]만들었는데
//expr이 참이면 1 거짓이면 -1이다.

static_assert(sizeof(int *) == 8);

void foo(int age)
{
    assert(age > 0);
}
int main(void)
{
    foo(-10);
}

/*
컴파일 시간에 값의 유효성을 확인하기 위해 사용
배열의 크기는 음수가 될 수 없다는 특징을 활용해서 만드는 경우가 많다.

C11부터는 C표준에서 _Static_assert라는 이름을 제공
_Static_assert(expr,"message");
*/

//3-------------------------------------------------
#include <stdio.h>
#include <assert.h>

_Static_assert(sizeof(int *) == 8, "not 64bit");

void foo(int age)
{
    assert(age > 0);
}
int main(void)
{
    foo(-10);
}