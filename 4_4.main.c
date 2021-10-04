#include "4_4.square.h"

int main()
{
    square(3);
    /*
    3.
    main.cpp가 컴파일 된 후 object파일에
    square(3);는
    "call ?square@@YAHZ"로 바뀐다

    그런데
    "square.c"에서 object파일은
    window라면 call _square
    linux라면 call square
    로 바뀌어 있어서 호출을 못하는 거다.
    */
}

/*
1.
C와 C++을 모두 지원하는 라이브러리 만들기

위의 코드는 "main.c"에서 gcc로 컴파일하면 문제가 없는데
"main.cpp"에서 g++로 컴파일하면 문제가 있다
*/

//정리 ##########################################################

/*
square.h와 square.c를 C++와 C에서 모두 사용하려면

C++언어에서 C함수를 호출하려면
squere.h에 있는 함수 선언에 extern "C"를 붙여야 한다.
즉 아래와 같이 사용해야 한다

4_4.square.h
##################################
extern "C"
int square(int a);
##################################

extern "C"를 적어줌으로서 C++컴파일러에 C함수임을 알려주는 것
그럼 "call ?square@@YAHZ"가 아니라 "call square"로 부른다
*/

/*
그런데 내가 main.c를 사용한다면??
C는 extern "C"를 모른다
extern "C"를 모른다고 error발생한다.
*/

/*
해결책

4_4.square.h
##################################
#ifdef __cplusplus
extern "C"
{
#endif

int square(int a);

#ifdef __cplusplus
}
#endif
##################################
*/