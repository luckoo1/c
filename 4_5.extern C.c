// C와 C++을 모두 지원하는 라이브러리 만들기
// 1------------------------------------------------
"square.h"---------------------------------
int square(int a);
"square.c"---------------------------------
int square(int a)
{
    return a * a;
}
"main.c"---------------------------------
#include "square.h"

int main()
{
    square(3);
}
-----------------------------------------
// C언어로 컴파일하면 함수 이름에 변화는 없다.
//즉 위의 코드는 "main.c"에서 gcc로 컴파일하면 문제가 없다.

// 2-------------------------------------------------
"square.h"---------------------------------
int square(int a);
"square.c"---------------------------------
int square(int a)
{
    return a * a;
}
"main.cpp"---------------------------------
#include "square.h"

int main()
{
    square(3);
}
// 위의 코드는 "main.cpp"에서 g++로 컴파일하면 error발생
// C++언어로 컴파일하면 ?square@@YAHHZ 등 함수이름이 완전히 변경된다
// name mangling현상
// 함수 오버로딩이라는 문법을 지원하기 위해

// 3-------------------------------------------------
//C언어로 컴파일시
"square.h"---------------------------------
int square(int a);
"square.c"---------------------------------
int square(int a)
{
    return a * a;
}
/*
컴파일 된 후 함수이름
window : _square
linux : square
즉 "square.c"의 object 파일에 이렇게 들어있다.
*/
"main.c"---------------------------------
#include "square.h"

int main()
{
    square(3);
}
-----------------------------------------
/*
window라면 call _square
linux라면 call square
즉 "main.c"의 object 파일에 이렇게 들어있다.
*/

/*
즉 "square.c"의 object 파일에
window : _square
linux : square
이렇게 들어있으니깐

window라면 call _square
linux라면 call square
에서 call하는 것에 문제는 없다.
*/
// 4-------------------------------------------------
// C++언어로 호출 시
"square.h"---------------------------------
int square(int a);
"square.c"---------------------------------
int square(int a)
{
    return a * a;
/*
컴파일 된 후 함수이름
window : _square
linux : square
즉 "square.c"의 object 파일에 이렇게 들어있다.
*/
}
"main.cpp"---------------------------------
#include "square.h"

int main()
{
    square(3);
}

/*
call ?square@@YAHHZ
"main.cpp"의 object 파일에 이렇게 들어있다.

그런데
즉 "square.c"의 object 파일에
window : _square
linux : square
이렇게 들어있으니깐 불러올수가 없는거다.
*/

// 5-------------------------------------------------

//square.h와 square.c를 C++와 C에서 모두 사용하려면
"square.h"---------------------------------
extern "C" int square(int a); //extern "C" 를 붙임
"square.c"---------------------------------
int square(int a)
{
    return a * a;
}
"main.cpp"---------------------------------
#include "square.h"

int main()
{
    square(3);
}
/*
C++언어에서 C함수를 호출하려면
squere.h에 있는 함수 선언에 extern "C"를 붙여야 한다.
extern "C"를 보면 C함수임을 알 수 있는 것이다.

extern "C"를 적어줌으로서 C++컴파일러에 C함수임을 알려주는 것
그럼 "call ?square@@YAHZ"가 아니라 "call square"로 부른다
*/

// 6-------------------------------------------------
"square.h"---------------------------------
extern "C" int square(int a); //extern "C" 를 붙임
"square.c"---------------------------------
int square(int a)
{
    return a * a;
}
"main.cpp"---------------------------------
#include "square.h"

int main()
{
    square(3);
    /*
    여기서 square()함수를 호출할때
    C함수임을 알고
    "call ?square@@YAHZ"가 아니라
    "call square"라 부른다.
    */
}
// 7-------------------------------------------------

/*
그런데 내가 main.c를 사용한다면??
C언어는 extern "C"를 모른다
C언어로 컴파일하면
extern "C"를 모른다고 error발생한다.
*/

// 8-------------------------------------------------
//해결책
//square.h
//C++컴파일러에서만 extern "C"가 작동하게 했다.
#ifdef __cplusplus
    extern "C" {
#endif

int square(int a);

#ifdef __cplusplus
}
#endif

/*
C++ 컴파일러면 
extern "C"
{
    int square(int a);
}
이런모양이 된다.
*/