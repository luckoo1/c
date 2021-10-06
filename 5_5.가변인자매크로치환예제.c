//1-------------------------------------------------
//cl컴파일러는 오류
//FOREACH 매크로 만들어보자

#include <stdio.h>

void show(int a)
{
    printf("show : %d\n", a);
}

int main(void)
{
    show(1);

    FOREACH(show, 1);             //show(1)
    FOREACH(show, 1, 2);          //show(1),show(2)
    FOREACH(show, 1, 2, 3, 4, 5); //show(1),show(2),show(3)....
}

//2-------------------------------------------------
void show(int a)
{
    printf("show : %d\n", a);
}

int main(void)
{
    FE_1(show, 1);
    FE_2(show, 1, 2);
    FE_3(show, 1, 2, 3);
    FE_4(show, 1, 2, 3, 4);
    FE_5(show, 1, 2, 3, 4, 5);
}

//3-------------------------------------------------
#include <stdio.h>
#define FE_1(FUNC, X) FUNC(x);
#define FE_2(FUNC, X, Y) \
    FUNC(X);             \
    FUNC(Y)
#define FE_3(FUNC, X, Y, Z) \
    FUNC(X);                \
    FUNC(Y);                \
    FUNC(Z)

//위와 같이 적는건 비효율이다.

void show(int a)
{
    printf("show : %d\n", a);
}

int main(void)
{
    FE_1(show, 1);
    FE_2(show, 1, 2);
    FE_3(show, 1, 2, 3);
    FE_4(show, 1, 2, 3, 4);
    FE_5(show, 1, 2, 3, 4, 5);
}

//4-------------------------------------------------
#include <stdio.h>
#define FE_1(FUNC, X) FUNC(X);

#define FE_2(FUNC, X, ...) \
    FUNC(X);               \
    FE_1(FUNC, __VA_ARGS__)

#define FE_3(FUNC, X, ...) \
    FUNC(X);               \
    FE_2(FUNC, __VA_ARGS__)

#define FE_4(FUNC, X, ...) \
    FUNC(X);               \
    FE_3(FUNC, __VA_ARGS__)

#define FE_5(FUNC, X, ...) \
    FUNC(X);               \
    FE_4(FUNC, __VA_ARGS__)

void show(int a)
{
    printf("show : %d\n", a);
}

int main(void)
{
    FE_1(show, 1);
    FE_2(show, 1, 2);
    FE_3(show, 1, 2, 3);
    FE_4(show, 1, 2, 3, 4);
    FE_5(show, 1, 2, 3, 4, 5);
}

/*
cl컴파일러는 오류인 이유
#define FE_2(FUNC, X, ...) \
    FUNC(X);               \
    FE_1(FUNC, __VA_ARGS__)

#define FE_3(FUNC, X, ...) \
    FUNC(X);               \
    FE_2(FUNC, __VA_ARGS__)

FE_3(show, 1, 2, 3);

위의 코드에서 
FE_3에서 ...에 2,3이 있다

그럼 FE_2(FUNC, X, ...)에서
X가 2가되고 3이 ...에 온다

그런데 cl은 2와 3이 X로 바로 같이간다

매크로 제거후 확인하면 된다.
*/

//4-------------------------------------------------
#include <stdio.h>

#define FE_1(FUNC, X) FUNC(X);

#define FE_2(FUNC, X, ...) \
    FUNC(X);               \
    FE_1(FUNC, __VA_ARGS__)

#define FE_3(FUNC, X, ...) \
    FUNC(X);               \
    FE_2(FUNC, __VA_ARGS__)

#define FE_4(FUNC, X, ...) \
    FUNC(X);               \
    FE_3(FUNC, __VA_ARGS__)

#define FE_5(FUNC, X, ...) \
    FUNC(X);               \
    FE_4(FUNC, __VA_ARGS__)

#define FOREACH_N(N, FUNC, ...) \
    FE_##N(FUNC, __VA_ARGS__)

void show(int a)
{
    printf("show : %d\n", a);
}

int main(void)
{
    FOREACH_N(5, show, 1, 2, 3, 4, 5);
}

//5-------------------------------------------------
#include <stdio.h>

#define FE_1(FUNC, X) FUNC(X);

#define FE_2(FUNC, X, ...) \
    FUNC(X);               \
    FE_1(FUNC, __VA_ARGS__)

#define FE_3(FUNC, X, ...) \
    FUNC(X);               \
    FE_2(FUNC, __VA_ARGS__)

#define FE_4(FUNC, X, ...) \
    FUNC(X);               \
    FE_3(FUNC, __VA_ARGS__)

#define FE_5(FUNC, X, ...) \
    FUNC(X);               \
    FE_4(FUNC, __VA_ARGS__)

#define FOREACH_N(N, FUNC, ...) \
    FE_##N(FUNC, __VA_ARGS__)

#define CNT 5
void show(int a)
{
    printf("show : %d\n", a);
}

int main(void)
{
    FOREACH_N(CNT, show, 1, 2, 3, 4, 5);
}

//위의 코드는 문제가 있다
//FE_CNT(show,1,2,3,4,5); 이런식으로 된다

//6-------------------------------------------------
#include <stdio.h>

#define FE_1(FUNC, X) FUNC(X);

#define FE_2(FUNC, X, ...) \
    FUNC(X);               \
    FE_1(FUNC, __VA_ARGS__)

#define FE_3(FUNC, X, ...) \
    FUNC(X);               \
    FE_2(FUNC, __VA_ARGS__)

#define FE_4(FUNC, X, ...) \
    FUNC(X);               \
    FE_3(FUNC, __VA_ARGS__)

#define FE_5(FUNC, X, ...) \
    FUNC(X);               \
    FE_4(FUNC, __VA_ARGS__)

//이걸 추가해야한다
#define CONCATENAT(arg1, arg2) CONCATENAT1(arg1, arg2)
#define CONCATENAT1(arg1, arg2) arg1##arg2

#define CNT 5

#define FOREACH_N(N, FUNC, ...) \
    CONCATENAT(FE_, N)          \
    (FUNC, __VA_ARGS__)

void show(int a)
{
    printf("show : %d\n", a);
}

int main(void)
{
    FOREACH_N(CNT, show, 1, 2, 3, 4, 5);
}

//위의 코드는 문제가 있다
//FE_CNT(show,1,2,3,4,5); 이런식으로 된다

//7-------------------------------------------------
//가변인자 매크로에 전달된 인자의 개수를 구하는 기술

#include <stdio.h>

#define COUNT(...) COUNT_IMP(__VA_ARGS__, 5, 4, 3, 2, 1, 0)
#define COUNT_IMP(_1, _2, _3, _4, _5, N, ...) N
/*
int m = COUNT(1, 2, 3);에서

__VA_ARGS__에 1,2,3이 오니깐
COUNT_IMP에서
_1 : 1
_2 : 2
_3 : 3
_4 : 5
_5 : 4
N : 3
이런형식으로 매핑되어서
N이 3이 된다.
*/

int main(void)
{
    int n = COUNT(1, 2, 3, 4, 5);
    printf("%d\n", n);
    int m = COUNT(1, 2, 3);
    printf("%d\n", m);
}

//8-------------------------------------------------
#include <stdio.h>

#define FE_1(FUNC, X) FUNC(X);

#define FE_2(FUNC, X, ...) \
    FUNC(X);               \
    FE_1(FUNC, __VA_ARGS__)

#define FE_3(FUNC, X, ...) \
    FUNC(X);               \
    FE_2(FUNC, __VA_ARGS__)

#define FE_4(FUNC, X, ...) \
    FUNC(X);               \
    FE_3(FUNC, __VA_ARGS__)

#define FE_5(FUNC, X, ...) \
    FUNC(X);               \
    FE_4(FUNC, __VA_ARGS__)

#define CONCATENAT(arg1, arg2) CONCATENAT1(arg1, arg2)
#define CONCATENAT1(arg1, arg2) arg1##arg2

#define CNT 5

#define FOREACH_N(N, FUNC, ...) \
    CONCATENAT(FE_, N)          \
    (FUNC, __VA_ARGS__)

#define COUNT(...) COUNT_IMP(__VA_ARGS__, 5, 4, 3, 2, 1, 0)
#define COUNT_IMP(_1, _2, _3, _4, _5, N, ...) N

#define FOREACH(FUNC, ...) \
    FOREACH_N(COUNT(__VA_ARGS__), FUNC, __VA_ARGS__)

void show(int a)
{
    printf("show : %d\n", a);
}

int main(void)
{
    FOREACH(show, 1, 2, 3, 4, 5);
}