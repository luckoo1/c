#if 0
#include "1_7.goo.h"

int main(void)
{
    cnt = 10; //error cnt는 다른파일에 있다.
    goo();
}
#endif

#if 0
#include "1_7.goo.h"

//cnt는 다른파일에 있어서 링커가 찾아줄 것이라고 알려주는 것
extern int cnt;
int main(void)
{
    cnt = 10; //OK
    goo();
}
#endif

#if 0
#include "1_7.goo.h"

//goo.h에다가 extern int cnt;선언해줬다.
int main(void)
{
    cnt = 10; //OK
    goo();
}
/*
▣External linkage(외부연결)
임의의 심볼이 자신을 선언한 컴파일 단위(파일)을 벗어나서도 사용가능한 것
일반함수,전역변수
*/
#endif

#if 0
#include "1_7.goo.h"

int main(void)
{
    cnt = 10;
    goo();
    hoo(); //error
}

/*
"1_7.goo.c"에서 "static void hoo()"라고 사용했기 때문에
1_7.goo.c에서만 사용이 가능하다.
*/

/*
▣Internal linkage(내부연결)
임의의 심볼이 자신을 선언한 컴파일 단위(파일)에서만 사용가능한 것
static 함수/static 전역변수
*/
#endif

#if 0
#include "1_7.goo.h"

int main(void)
{
    cnt = 10;
    goo();
    //hoo(); //error
    int n = MAX; //error
}

/*
"1_7.goo.c"에서 MAX를 define해줬는데 여기서는 사용이 불가능하다.
"1_7.goo.h"에 define해주면 사용이 가능하긴한데 
그냥 "1_7.goo.h"에서 연결해서 사용하는거다.
*/

/*
▣Internal linkage(내부연결)
임의의 심볼이 자신을 선언한 컴파일 단위(파일)에서만 사용가능한 것
static 함수/static 전역변수
매크로 상수/매크로 함수
*/
#endif

#include "1_7.goo.h"

int main(void)
{
    cnt = 10;
    goo();
    //hoo(); //error
    //int n = MAX; //error
    int n = c;
}

//gcc는 컴파일되는데 g++은 컴파일이 되지 않는다

/*
결론
▣External linkage(외부연결)
임의의 심볼이 자신을 선언한 컴파일 단위(파일)을 벗어나서도 사용가능한 것
일반함수,전역변수
const변수(C언어)

▣Internal linkage(내부연결)
임의의 심볼이 자신을 선언한 컴파일 단위(파일)에서만 사용가능한 것
static 함수/static 전역변수
매크로 상수/매크로 함수
const변수(C++언어)
*/