//1-------------------------------------------------
#include <stdio.h>

#define print_value1(x) printf("%s = %d\n", #x, x);
#define print_value2(x) printf("%d, %d\n", x##1, x##2);

int main(void)
{
    int value1 = 10;
    int value2 = 20;

    print_value1(value1 / 2);
    //printf("%s = %d\n","value1 / 2", value1 / 2);
    print_value2(value);
    //printf("%d, %d\n", value1, value2);
}

/*
#을 사용한 매크로 치환 => 매크로 인자를 문자열로 치환

##을 사용한 매크로 치환 => 2개의 토큰(Token)을 붙여서 치환
2개의 문자열을 붙임

gcc 파일이름 -E
하면 매크로 제거된거 볼수 있다.
*/

//2-------------------------------------------------
#define MAX 256
#define TOSTR(x) #x //인자로 전달받은것을 문자열로 치환

int main(void)
{
    TOSTR(AAA);      //"AAA"
    TOSTR(MAX);      //"MAX"로 나올까 "256"으로 나올까?
    TOSTR(__LINE__); //"__LINE__"으로 나올까 "진짜 라인넘버"로 나올까?
}

//3-------------------------------------------------
#define MAX 256
#define TOSTR(x) #x

int main(void)
{
    TOSTR(AAA);      //"AAA"
    TOSTR(MAX);      //"MAX"
    TOSTR(__LINE__); //"__LINE__"
}

//4-------------------------------------------------
#define MAX 256
#define TOSTR2(x) #x
#define TOSTR(x) TOSTR2(x)

int main(void)
{
    TOSTR(AAA);      //"AAA"
    TOSTR(MAX);      //"256"
    TOSTR(__LINE__); //"59"
}

/*
#define TOSTR(x) TOSTR2(x)
TOSTR(__LINE__)으로 들어와서 TOSTR2로 넘아갈때
TOSTR2(59)로 바뀐다

매크로 심볼의 값을 문자열로 치환하려면 2번의 매크로 치환을 해야한다.
*/

//5-------------------------------------------------
#define MAX 256
#define TOSTR2(x) #x
#define TOSTR(x) TOSTR2(x)

int main(void)
{
    TOSTR(AAA);      //"AAA"
    TOSTR(MAX);      //"256"
    TOSTR(__LINE__); //"59"

#pragma message("ABCDEFGHIJK")
    /*
C표준은 아니나 gcc와 cl은 지원한다.
()괄호안에 내용을 컴파일창에 보여준다.
*/
}

//6-------------------------------------------------
#define LOG(desc) \
    (__FILE__"("( __LINE__ ") : " desc)

//file이름과 line number과 desc출력하고 싶다.
//그런데 __LINE__은 문자열이 아니다.
int main(void)
{
#pragma message LOG("Place for modify")
}

//7-------------------------------------------------
//아래와 같이 써보겠다.
#define LOG(desc) \
    (__FILE__"("( #__LINE__ ") : " desc)
/*
컴파일 에러뜬다.
#은 매크로 인자만 쓸수 있다
즉 #desc는 가능하다
*/

int main(void)
{
#pragma message LOG("Place for modify")
}

//8-------------------------------------------------

#define TOSTR2(x) #x
#define TOSTR(x) TOSTR2(x)

#define LOG(desc) \
    (__FILE__"("( TOSTR(__LINE__) ") : " desc)

int main(void)
{
#pragma message LOG("Place for modify")
}

//9-------------------------------------------------
//연습 문제
int main(void)
{
    //unique한 이름을 사용하는 변수를 선언하는 매크로
    //type와 line number를 받아서 unique한 변수를 만들어보자
    VAR(int, n); //int n6
    VAR(int, n); //int n7
    //위의 예제에서 6과 7은 line number
}

//10-------------------------------------------------

#define VAR(TYPE, NAME) TYPE NAME##__LINE__
int main(void)
{
    VAR(int, n); //int n6
    VAR(int, n); //int n7
}

//위와 같이 ##__LINE__쓰면 에러뜬다.
