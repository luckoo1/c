//1-------------------------------------------------
#include <stdio.h>

#ifdef DEBUG
#define TRACE(msg) printf(msg)
#else
#define TRACE(msg)
#endif

int main(void)
{
    int n1 = 10;
    int n2 = 20;

    TRACE("디버그 메시지\n");
    TRACE("n1 = %d\n", n1);
    TRACE("n1 = %d, n2 = %d\n", n1, n2);
}

/*
DEBUG를 정의하면 TRACE가 작동하게 만들고 싶다.
TRACE("디버그 메시지\n");는 잘 작동하는데
TRACE("n1 = %d\n", n1);
TRACE("n1 = %d, n2 = %d\n", n1, n2);
이 코드들이 문제다
*/

//2-------------------------------------------------
#include <stdio.h>

#ifdef DEBUG
#define TRACE(msg) printf(msg)
#define TRACE1(msg, a) printf(msg, a)
#define TRACE2(msg, a, b) printf(msg, a, b)
#else
#define TRACE(msg)
#define TRACE1(msg, a)
#define TRACE2(msg, a, b)
#endif

int main(void)
{
    int n1 = 10;
    int n2 = 20;

    TRACE("디버그 메시지\n");
    TRACE1("n1 = %d\n", n1);
    TRACE2("n1 = %d, n2 = %d\n", n1, n2);
}
//옛날에는 위와 같은 방법을 사용했다.

//3-------------------------------------------------
//가변인자 매크로

#include <stdio.h>

#ifdef DEBUG
#define TRACE(...) printf(__VA_ARGS__)
#else
#define TRACE(...)
#endif

int main(void)
{
    int n1 = 10;
    int n2 = 20;

    TRACE("디버그 메시지\n");
    TRACE("n1 = %d\n", n1);
    TRACE("n1 = %d, n2 = %d\n", n1, n2);
}