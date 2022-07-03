//1-------------------------------------------------
#include <stdio.h>

#ifdef DEBUG
#define TRACE(msg) printf(msg)
#else
#define TRACE(msg)
#endif

/*
DEBUG가 정의되어 있지 않으면
TRACE() 사용해도 공백으로 치환되어서 아무일도 발생하지 않는다
*/

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
TRACE("디버그 메시지\n");는 잘 작동한다

TRACE("n1 = %d\n", n1);
TRACE("n1 = %d, n2 = %d\n", n1, n2);
이 코드들이 문제다
왜냐하면 위에 TRACE()안에는 인자가 2개다
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
//(...)여기에는 어떤인자가 몇개가 와도 상관없다.
//(...)에 오는 인자들이 (__VA_ARGS__)로 들어간다. 