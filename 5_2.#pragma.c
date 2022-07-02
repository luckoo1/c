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
/*
C:\Users\beobs\OneDrive\Desktop\Github\c>gcc 0.test.c
0.test.c: In function 'main':
0.test.c:11:9: note: #pragma message: We must fix it!
 #pragma message("We must fix it!")
         ^~~~~~~
*/

// 2-------------------------------------------------
/*
"We must fix it!"메세지가 뜨는 곳의 위치를 알려주어서
사용자에게 편의를 제공하겠다.
file이름과 line number과 description출력하고 싶다.
*/
#define LOG(desc) \
    (__FILE__"("( __LINE__ "): " desc)

int main(void)
{
#pragma message LOG("Place for modify")
}
//그런데 __LINE__에서 line number는 문자열이 아니다.

// 3-------------------------------------------------
//아래와 같이 써보겠다.
#define LOG(desc) \
    (__FILE__"("( #__LINE__ "): " desc)

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

/*
★★★
#,##은 매크로 인자에만 사용할수 있다.
*/
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

#define VAR(TYPE, NAME) TYPE NAME

int main(void)
{
    VAR(int, n) = 6; // int n
    printf("%d",n);

}
//6이 나오겠지
//----------------------------------------------------
#define VAR(TYPE, NAME) TYPE NAME

int main(void)
{
    VAR(int, n) = 6; // int n
    VAR(int, n) = 7; // int n
    printf("%d",n);

}
//같은 int n을 두번 선언하는 모양이되니깐 에러
//----------------------------------------------------
int main(void)
{
    // unique한 이름을 사용하는 변수를 선언하는 매크로
    VAR(int, n); // int n6
    VAR(int, n); // int n7
    //위의 예제에서 6과 7은 line number
    //line number적는 이유는 변수를 unique하게 만들려고
}
//----------------------------------------------------

int main(void)
{
    // unique한 이름을 사용하는 변수를 선언하는 매크로
    VAR(int, n) = 6; // int n6
    VAR(int, n) = 10; // int n7
    printf("%d",n6);
    printf("%d",n7);
}
/*
이런식으로 사용하고 싶은거다.
*/
// 10-------------------------------------------------

#define VAR(TYPE, NAME) TYPE NAME##__LINE__
int main(void)
{
    VAR(int, n); // int n6
    VAR(int, n); // int n7
}

//위와 같이 ##__LINE__쓰면 에러뜬다.
//----------------------------------------------------
/*
이렇게 사용하는 모양이 되므로..
*/
#define VAR(TYPE, NAME) TYPE NAME##__LINE__

int main(void)
{
    VAR(int, n) = 6; // int n
    printf("%d",n__LINE__);

}

