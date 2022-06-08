// 1-------------------------------------------------

"linkage.h"----------------------------------
//보통 헤더파일에는 선언부만 넣어야하는데
//아래와 같이 헤더파일에 함수구현을 넣어봤다.
void goo(){};
int cnt = 0;
"linkage.c"---------------------------------
#include "linkage.h"

void foo()
{
    goo();
    cnt = 20;
}
"main.c"--------------------------------
#include "linkage.h"
int main(void)
{
    cnt = 10;
    goo();
}
-----------------------------------------
// 2-------------------------------------------------
/*
헤더파일에 함수구현을 넣어봤다.
"main.c"에서도 #include "linkage.h"을 했다
gcc main.c linkage.c하면
아래의 모양처럼 코드가 되는 격이다.
*/

"linkage.h"----------------------------------
void goo(){};
int cnt = 0;
"linkage.c"---------------------------------
#include "linkage.h"
void goo(){};//여기에 놓이게 된다.
int cnt = 0;//여기에 놓이게 된다
void foo()
{
    goo();
    cnt = 20;
}
"main.c"--------------------------------
#include "linkage.h"
void goo(){};//여기에 놓이게 된다
int cnt = 0;//여기에 놓이게 된다
void foo()
{
    goo();
    cnt = 20;
}
-----------------------------------------
/*
위와같이 4군데에 놓이게 되는데
goo가 main에도 있고 "linkage.h"에도 있게되어 어디있는건지
알 수 없게 된다.
goo함수가 2개 있다는 에러가 발생
*/

// 3-------------------------------------------------
"linkage.h"----------------------------------
static void goo(){};//static을 추가
static int cnt = 0; // static을 추가
"linkage.c"---------------------------------
#include "linkage.h"
void foo()
{
    goo();
    cnt = 20;
}
"main.c"--------------------------------
#include "linkage.h"

void foo()
{
    goo();
    cnt = 20;
}
-----------------------------------------


// 4-------------------------------------------------
//3번의 코드는 아래처럼 된다
"linkage.h"----------------------------------
static void goo(){};
static int cnt = 0;
"linkage.c"---------------------------------
#include "linkage.h"
static void goo(){}; //이렇게 된다.
static int cnt = 0;  //이렇게 된다.
void foo()
{
    goo();
    cnt = 20;
}
"main.c"--------------------------------
#include "linkage.h"
static void goo(){};//이렇게 된다.
static int cnt = 0; //이렇게 된다.
void foo()
{
    goo();
    cnt = 20;
}
-----------------------------------------
/*
static자가 붙어있으면 자기 파일에서만 쓸 수 있게 된다.
gcc main.c linkage.c
문제없이 빌드된다.
*/

/*
3번과 4번의 결론
External linkage을 가지는 심볼은 헤더파일에 넣으면 안된다
Internal linkage를 가지는 심볼은 헤더에 넣을 수 있다.
*/

// 5-------------------------------------------------
"linkage.h"----------------------------------
#define MAX 100 //이걸 추가했다.
static void goo(){};
static int cnt = 0;
"linkage.c"---------------------------------
#include "linkage.h"
void foo()
{
    int n = MAX; //이걸 추가했다.
    goo();
    cnt = 20;
}
"main.c"--------------------------------
#include "linkage.h"
void foo()
{
    int n = MAX; //이걸 추가했다.
    goo();
    cnt = 20;
}
-----------------------------------------
/*
매크로는 Internal linkage니깐 아무 문제없이 컴파일 된다.
각자의 영역에서 쓰이는거지!
*/

// 6-------------------------------------------------
"linkage.h"----------------------------------
const int MAX = 100; //이걸 추가했다.
static void goo(){};
static int cnt = 0;
"linkage.c"---------------------------------
#include "linkage.h"
void foo()
{
    int n = MAX; 
    goo();
    cnt = 20;
}
"main.c"--------------------------------
#include "linkage.h"
void foo()
{
    int n = MAX;
    goo();
    cnt = 20;
}
-----------------------------------------
/*
C++에서 const만들어냈고 C가 그걸 받아들였다.
매크로는 전처리가 처리하는거니깐 매크로쓰지말고 const쓰자는 주장이 나왔다.
컴파일러가 취급하는거니깐 훨씬 좋다고 생각했다.
C언어에서 const는 external linkage니깐 컴파일이 안된다.
MAX가 양쪽에 있다고 뜬다.
C++에서는 const는 internal linkage니깐 컴파일이 된다.
*/


//C언어
"linkage.h"----------------------------------
const int MAX = 100; //이걸 추가하면
static void goo(){};
static int cnt = 0;
"linkage.c"---------------------------------
#include "linkage.h"
const int MAX = 100; //이렇게 추가됨(external이니깐)
void foo()
{
    int n = MAX; 
    goo();
    cnt = 20;
}
"main.c"--------------------------------
#include "linkage.h"
const int MAX = 100; //이렇게 추가됨(external이니깐)
void foo()
{
    int n = MAX;
    goo();
    cnt = 20;
}
-----------------------------------------
/*
결론
C언어에서는 const상수를 소스파일에 놓아야한다.
C++에서는 const상수를 헤더파일에 놓을 수 있다.
*/