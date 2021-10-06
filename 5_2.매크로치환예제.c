//1-------------------------------------------------
#include <stdio.h>
#include <assert.h>

void foo(int age)
{
    /*
    "함수인자인 age는 나이이므로 0보다 클것이다"
    라고 가정하고 코드작성
    그런데 사용자가 음수를 보내서 문제가 발생할 수 있다.
    인자의 유효성을 확인하자
    */
}

int main(void)
{
    foo(-10);
}

//2-------------------------------------------------
#include <stdio.h>
#include <assert.h>

void foo(int age)
{
    assert(age > 0);
}

int main(void)
{
    foo(-10);
}

/*
<assert.h>
실행시간에 값의 유효성을 확인할 수 있다.
*/

//3-------------------------------------------------
//직접만들어 보자
#include <stdio.h>

#define assert(expr)                                                                   \
    if (!(expr))                                                                       \
    {                                                                                  \
        printf("Assertion Failed: %s, file %s, line %d\n", #expr, __FILE__, __LINE__); \
        abort();                                                                       \
    }

void foo(int age)
{
    assert(age > 0);
}

int main(void)
{
    foo(-10);
}

/*
<assert.h>
실행시간에 값의 유효성을 확인할 수 있다.
*/