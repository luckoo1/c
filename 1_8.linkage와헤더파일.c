#include "1_8.linkage.h"

int main(void)
{
    cnt = 10;
    goo();
}
//헤더파일에 함수구현을 넣어봤다.

//"1_8.linkage.c"에서도 #include "1_8.linkage.h"을 했다

/*
"1_8.linkage와 헤더파일.c"와 "1_8.linkage.c"를 동시에 컴파일 해보면
"1_8.linkage.h"안에 goo()가 
"1_8.linkage와 헤더파일.c"와 "1_8.linkage.c"에 동시에 놓이게 된다.
"1_8.linkage와 헤더파일.c"안에 goo()함수는 어디에 있는건지 알 수가 없다.
"1_8.linkage와 헤더파일.c"와 "1_8.linkage.c"를 동시에 컴파일하면 error
*/
