//이건 재대로 이해 못했다 ㅠㅠ
//컴파일이 재대로 동작하지 않는다.
// implicit declaration of function에러

#define MAX 256
#define TOSTR2(x) #x
#define TOSTR(x) TOSTR2(x)

int main(void)
{
    TOSTR(AAA);      //"AAA"
    TOSTR(MAX);      //"256"
    TOSTR(__LINE__); //"59"

#pragma message("We must fix it!")
    /*
    C표준은 아니나 gcc와 cl은 지원한다.
    ()괄호안에 내용을 컴파일창에 보여준다.
    컴파일시 상기시켜주기
    */
}

// 2-------------------------------------------------
/*
"We must fix it!"메세지가 뜨는 곳의 위치를 알려주어서
사용자에게 편의를 제공하겠다.
file이름과 line number과 desc출력하고 싶다.
*/
#define LOG(desc) \
    (__FILE__"("( __LINE__ ") : " desc)

int main(void)
{
#pragma message LOG("Place for modify")
}
//그런데 __LINE__에서 line number는 문자열이 아니다.

// 3-------------------------------------------------
//아래와 같이 써보겠다.
#define LOG(desc) \
    (__FILE__"("( #__LINE__ ") : " desc)

int main(void)
{
#pragma message LOG("Place for modify")
}
/*
컴파일 에러뜬다.

#은 매크로 인자만 쓸수 있다
#define LOG(desc) \
    (__FILE__"("( #desc ") : " desc)
즉 위와같이 #desc를 사용하면 가능하다
하지만 __FILE__ , __LINE__은 매크로 인자가 아니다.
*/

//#,##은 매크로 인자에만 사용할수 있다.

// 4-------------------------------------------------

#define TOSTR2(x) #x
#define TOSTR(x) TOSTR2(x)

#define LOG(desc) \
    (__FILE__"("( TOSTR(__LINE__) ") : " desc)

int main(void)
{
#pragma message LOG("Place for modify")
}

// 5-------------------------------------------------
//연습 문제
int main(void)
{
    // unique한 이름을 사용하는 변수를 선언하는 매크로
    // type와 line number를 받아서 unique한 변수를 만들어보자
    VAR(int, n); // int n6
    VAR(int, n); // int n7
    //위의 예제에서 6과 7은 line number
}

// 10-------------------------------------------------

#define VAR(TYPE, NAME) TYPE NAME##__LINE__
int main(void)
{
    VAR(int, n); // int n6
    VAR(int, n); // int n7
}

//위와 같이 ##__LINE__쓰면 에러뜬다.
