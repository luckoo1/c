//지금부터 하는건 cl컴파일러는 오류가 나오니깐 참고하자

//1-------------------------------------------------
//FOREACH 매크로 만들어보자
//일단 FOREACH마 뭔지 알아보자.
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
    //함수들을 인자값의 수만큼 호출한다.
}
/*
FOREACH()는 첫번째 인자로 함수(show)를 받고
그 뒤로부터는 인자값(1,2,3..)들을 받는다.
*/

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
/*
FE_1()은 인자를 하나 줄거다 //show(1)
FE_2()은 인자를 두개 줄거다 //show(1),show(2)
....
이러한 의미로 만들어보겠다.
*/
// 3-------------------------------------------------

#include <stdio.h>
#define FE_1(FUNC, X) FUNC(X)
#define FE_2(FUNC, X, Y) \
    FUNC(X);             \
    FUNC(Y)
#define FE_3(FUNC, X, Y, Z) \
    FUNC(X);                \
    FUNC(Y);                \
    FUNC(Z)

/*
#define FE_1(FUNC, X) FUNC(X)
FUNC로 show를 받았고 X로 1을 받았다.
그래서 뒤에 "FUNC(X)"에서 "show(1)"이 된다.
#define FE_2(FUNC, X, Y) \
    FUNC(X);             \
    FUNC(Y)
FUNC로 show를 받았고 X로 1을 Y로 2를 받았다.
그래서 뒤에 "FUNC(X)"에서 "show(1)"로 한번 부르고
"show(2)"로 또 불렀다.
*/
//그런데, 위와 같이 적는건 비효율이다.

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
#define FE_2(FUNC, X, ...) FUNC(X); FE_1(FUNC, __VA_ARGS__)
#define FE_3(FUNC, X, ...) FUNC(X); FE_2(FUNC, __VA_ARGS__)
#define FE_4(FUNC, X, ...) FUNC(X); FE_3(FUNC, __VA_ARGS__)
#define FE_5(FUNC, X, ...) FUNC(X); FE_4(FUNC, __VA_ARGS__)

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

// 5-------------------------------------------------
//위의 코드 해석
#include <stdio.h>
#define FE_1(FUNC, X) FUNC(X);
#define FE_2(FUNC, X, ...) FUNC(X); FE_1(FUNC, __VA_ARGS__)
#define FE_3(FUNC, X, ...) FUNC(X); FE_2(FUNC, __VA_ARGS__)
#define FE_4(FUNC, X, ...) FUNC(X); FE_3(FUNC, __VA_ARGS__)
#define FE_5(FUNC, X, ...) FUNC(X); FE_4(FUNC, __VA_ARGS__)

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
FE_5호출하면
#define FE_5(FUNC, X, ...) FUNC(X); FE_4(FUNC, __VA_ARGS__)
가서 FUNC(1)호출하고
FE_4(FUNC,2,3,4,5)호출된다.

그럼
#define FE_4(FUNC, X, ...) FUNC(X); FE_3(FUNC, __VA_ARGS__)
가서 FUNC(2)호출하고
FE_2(FUNC,3,4,5)호출된다.
*/

// 6-------------------------------------------------
/*
cl컴파일러는 오류인 이유

FE_1(show, 1);      //OK
FE_2(show, 1, 2);   //OK
FE_3(show, 1, 2, 3);//NG

FE_3에서 에러가 발생한다.

#define FE_2(FUNC, X, ...) FUNC(X); FE_1(FUNC, __VA_ARGS__)

#define FE_3(FUNC, X, ...) FUNC(X); FE_2(FUNC, __VA_ARGS__)

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
#define FE_2(FUNC, X, ...) FUNC(X); FE_1(FUNC, __VA_ARGS__)
#define FE_3(FUNC, X, ...) FUNC(X); FE_2(FUNC, __VA_ARGS__)
#define FE_4(FUNC, X, ...) FUNC(X); FE_3(FUNC, __VA_ARGS__)
#define FE_5(FUNC, X, ...) FUNC(X); FE_4(FUNC, __VA_ARGS__)

#define FOREACH_N(N, FUNC, ...) FE_##N(FUNC, __VA_ARGS__)

void show(int a)
{
    printf("show : %d\n", a);
}

int main(void)
{
    FOREACH_N(5, show, 1, 2, 3, 4, 5); //수정
}
//문제없이 작동한다!

//5-------------------------------------------------
/*
하지만 또 문제가 발생할수 있다.
#define CNT 5
사용하는 경우다.
*/

#include <stdio.h>

#define FE_1(FUNC, X) FUNC(X);
#define FE_2(FUNC, X, ...) FUNC(X); FE_1(FUNC, __VA_ARGS__)
#define FE_3(FUNC, X, ...) FUNC(X); FE_2(FUNC, __VA_ARGS__)
#define FE_4(FUNC, X, ...) FUNC(X); FE_3(FUNC, __VA_ARGS__)
#define FE_5(FUNC, X, ...) FUNC(X); FE_4(FUNC, __VA_ARGS__)

#define FOREACH_N(N, FUNC, ...) FE_##N(FUNC, __VA_ARGS__)

#define CNT 5
void show(int a)
{
    printf("show : %d\n", a);
}

int main(void)
{
    FOREACH_N(CNT, show, 1, 2, 3, 4, 5); //수정
}

//위의 코드는 문제가 있다
/*
FE_CNT(show,1,2,3,4,5); 이런식으로 된다

FOREACH_N(CNT, show, 1, 2, 3, 4, 5);가 넘어가면

#define FOREACH_N(N, FUNC, ...) \
    FE_CNT(FUNC, __VA_ARGS__)
이런식으로 바뀐다
FOREACH_N()함수에서 N자리에 CNT로 왔기 때문이다.
*/

// 6-------------------------------------------------
#include <stdio.h>

#define FE_1(FUNC, X) FUNC(X);
#define FE_2(FUNC, X, ...) FUNC(X); FE_1(FUNC, __VA_ARGS__)
#define FE_3(FUNC, X, ...) FUNC(X); FE_2(FUNC, __VA_ARGS__)
#define FE_4(FUNC, X, ...) FUNC(X); FE_3(FUNC, __VA_ARGS__)
#define FE_5(FUNC, X, ...) FUNC(X); FE_4(FUNC, __VA_ARGS__)

//아래 두줄을 추가해야한다
#define CONCATENAT(arg1, arg2) CONCATENAT1(arg1, arg2) //인자로 받아서
#define CONCATENAT1(arg1, arg2) arg1##arg2  //여기서 합친다.

#define FOREACH_N(N, FUNC, ...) CONCATENAT(FE_, N)(FUNC, __VA_ARGS__)
    // FE_N(FUNC, __VA_ARGS__)와 같은 모양이 된다.

#define CNT 5
void show(int a)
{
    printf("show : %d\n", a);
}

int main(void)
{
    FOREACH_N(CNT, show, 1, 2, 3, 4, 5);
}

// 7-------------------------------------------------
//그림필기
/*매번 N을 보내줘야하는게 불편하다.
FOREACH(show,1,2,3,4,5);
이렇게만 보내도 인자의 수가 몇개인지 알수있게 하고싶다.
가변인자 매크로에 전달된 인자의 개수를 구하는 기술
*/

#include <stdio.h>

#define COUNT(...) COUNT_IMP(__VA_ARGS__, 5, 4, 3, 2, 1, 0)
#define COUNT_IMP(_1, _2, _3, _4, _5, N, ...) N
/*
int m = COUNT(1, 2, 3);호출하면

#define COUNT(...) COUNT_IMP(__VA_ARGS__, 5, 4, 3, 2, 1, 0)
__VA_ARGS__에 1,2,3이 온다

#define COUNT_IMP(_1, _2, _3, _4, _5, N, ...) N 이걸 살펴보면
COUNT_IMP의 숫자(_1, _2, _3, _4, _5, N, ...)들이 뭐랑 매핑되는지 보자

_VA_ARGS_가 1,2,3이니깐
COUNT_IMP함수에서
_1은 1과 매핑
_2은 2과 매핑
_3은 3과 매핑
_4는 5와 매핑
_5는 5와 매핑
N은 3과 매핑
COUNT_IMP은 N을 꺼내는 함수니깐 3이 나오는 거다.

이런형식으로 매핑되어서
N이 3이 된다.
*/

int main(void)
{
    int n = COUNT(1, 2, 3, 4, 5);
    printf("%d\n", n);//5
    int m = COUNT(1, 2, 3);
    printf("%d\n", m);//3
}

//8-------------------------------------------------
//결론
#include <stdio.h>

#define FE_1(FUNC, X) FUNC(X);
#define FE_2(FUNC, X, ...) FUNC(X); FE_1(FUNC, __VA_ARGS__)
#define FE_3(FUNC, X, ...) FUNC(X); FE_2(FUNC, __VA_ARGS__)
#define FE_4(FUNC, X, ...) FUNC(X); FE_3(FUNC, __VA_ARGS__)
#define FE_5(FUNC, X, ...) FUNC(X); FE_4(FUNC, __VA_ARGS__)


#define CONCATENAT(arg1, arg2) CONCATENAT1(arg1, arg2)
#define CONCATENAT1(arg1, arg2) arg1##arg2

#define CNT 5

#define FOREACH_N(N, FUNC, ...) CONCATENAT(FE_, N)(FUNC, __VA_ARGS__)

#define COUNT(...) COUNT_IMP(__VA_ARGS__, 5, 4, 3, 2, 1, 0)
#define COUNT_IMP(_1, _2, _3, _4, _5, N, ...) N

//이게 최종
#define FOREACH(FUNC, ...) FOREACH_N(COUNT(__VA_ARGS__), FUNC, __VA_ARGS__)

void show(int a)
{
    printf("show : %d\n", a);
}

int main(void)
{
    FOREACH(show, 1, 2, 3, 4, 5);
}