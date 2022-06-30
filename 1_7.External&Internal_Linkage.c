//1-------------------------------------------------
"goo.h"---------------------------------
void goo();
"goo.c"---------------------------------
int cnt = 0;
void goo(){ }
"main.c"---------------------------------
#include "goo.h"

int main(void)
{
    cnt = 10; //error cnt는 다른파일에 있다.
    goo();
}
-----------------------------------------
// gcc main.c goo.c하면 error발생

// 2-------------------------------------------------

"goo.h"---------------------------------
void goo();
"goo.c"---------------------------------
int cnt = 0;
void goo(){ }
"main.c"---------------------------------
#include "goo.h"

//cnt는 다른파일에 있어서 링커가 찾아줄 것이라고 알려주는 것
extern int cnt;
int main(void)
{
    cnt = 10; //OK
    goo();
}
// gcc main.c goo.c하면 OK
-----------------------------------------

// 3-------------------------------------------------

"goo.h"---------------------------------
void goo();
extern int cnt;
"goo.c"---------------------------------
int cnt = 0;
void goo(){ }
"main.c"---------------------------------
#include "goo.h"

/*매번 main쪽에서 extern선언하기가 귀찮았다
  goo.h에다가 extern int cnt;선언해줬다.*/
int main(void)
{
    cnt = 10; //OK
    goo();
}
-----------------------------------------
/*
위와같이 헤더파일에 extern작성하면
goo.c에 있는 전역변수를 main에서 쉽게 사용가능해진다.
*/

/*
▣External linkage(외부연결)
임의의 심볼(함수이름이나 변수이름)이 자신을 선언한 컴파일 단위(파일)을 벗어나서도 사용가능한 것을
"External linkage"를 갖는다고 이야기한다.
외부연결성이 있다고 이야기한다.
일반함수,전역변수
즉 main함수에서 끌어서 쓸수 있는거라 생각하자
1_8 1~2번 함수 확인해보자
*/

//4-------------------------------------------------

"goo.h"---------------------------------
void goo();
extern int cnt;

static void hoo();
"goo.c"---------------------------------
int cnt = 0;
void goo(){ }

static void hoo(){}
static int cnt = 0;

"main.c"---------------------------------
#include "goo.h"

int main(void)
{
    cnt = 10;
    goo();
    hoo(); //error
}
-----------------------------------------
/*
"goo.c"에서 "static void hoo()"라고 사용했기 때문에
goo.c에서만 사용이 가능하다.
*/

/*
▣Internal linkage(내부연결)
임의의 심볼(함수이름이나 변수이름)이 자신을 선언한 컴파일 단위(파일)에서만 사용가능한 것
외부연결성이 있다고 이야기한다.
static 함수/static 전역변수
*/

//5-------------------------------------------------

"goo.h"---------------------------------
void goo();
extern int cnt;

static void hoo();
"goo.c"---------------------------------
#define MAX 100
int cnt = 0;
void goo(){ }

static void hoo(){}
static int cnt = 0;
"main.c"---------------------------------
#include "goo.h"

int main(void)
{
    cnt = 10;
    goo();
    //hoo(); //error
    int n = MAX; //error
}
-----------------------------------------
/*
"goo.c"에서 MAX를 define해줬는데 여기서는 사용이 불가능하다.
"goo.h"에 define해주면 사용이 가능하긴한데 
그냥 "goo.h"에서 연결해서 사용하는거다.
*/

/*
▣Internal linkage(내부연결)
임의의 심볼이 자신을 선언한 컴파일 단위(파일)에서만 사용가능한 것
static 함수/static 전역변수
매크로 상수/매크로 함수
*/

// 6-------------------------------------------------

"goo.h"---------------------------------
void goo();
extern int cnt;

static void hoo();
extern const int c;
"goo.c"---------------------------------
#define MAX 100

const int c = 10;
int cnt = 0;
void goo(){ }

static void hoo(){}
static int cnt = 0;
"main.c"---------------------------------
#include "goo.h"

int main(void)
{
    cnt = 10;
    goo();
    //hoo(); //error
    //int n = MAX; //error
    int n = c;
}
-----------------------------------------
//gcc(c언어)는 컴파일되는데 g++(C++)은 컴파일이 되지 않는다

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