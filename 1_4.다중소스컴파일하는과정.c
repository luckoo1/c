"foo.h"---------------------------------
void foo();
"foo.c"---------------------------------
void foo(int a){ 
    printf("foo : %d\n",a);
}
"main.c"---------------------------------
#include "foo.h"
int main(void)
{
    foo(10);
}

//gcc 다중소스를컴파일하는방법.c foo.c

/*
컴파일는 각각의 파일을 따로 컴파일하고 Linking할때 합친다.

"1_4.다중소스컴파일하는과정.c"
foo()를 찾지 못한다고 error뜬다.

foo()함수를 찾는것은 컴파일러의 역할이 아니다
실제 함수 호출부와 구현부를 연결하는 것은 컴파일러가 아닌 링커에 의해서 수행된다.
대부분의 컴파일러는 옵션을 지정하지 않은 경우 컴파일후 링킹과정을 자동으로 수행한다.
foo()함수를 찾으려고 시도하다가 못 찾아서 error가 발생하는 거다
*/

/*
첫번째 과정
링킹을 하지 않고 컴파일만 할거라는 옵션 "-c"추가했다.

"1_4.다중소스컴파일하는과정.c -c"
"다중소스를컴파일하는과정.o"라는 object파일이 출력된다.

"gcc foo.c -c"
"foo.o"라는 object파일이 출력된다.

"1_4.다중소스컴파일하는과정.o" object파일에는 main함수의 기계어코드는 있지만 foo()의 기계어 코드는 없다.
아직 foo()가 어디있는지 모른다.

두번째 과정
결합하기 위해서 링커를 돌린다.

"ld 1_4.다중소스컴파일하는과정.o foo.o"
위와같이 쓰면 옛날에는 돌아가서 "a.exe"파일을 만들었다

그런데 요즘은 ld대신에 gcc를 사용해도 한다.
gcc라는 명령어가 ld를 내부적으로 실행해서 결합까지 해준다.
"gcc 1_4.다중소스컴파일하는과정.o foo.o"
"a.exe"가 출력된다.
*/

/*
2개 파일을 동시에 빌드
"gcc 다중소스를컴파일하는과정.c foo.c"
"a.exe"가 출력된다.
*/
