//1-------------------------------------------------
//type에 대한 별칭을 만드는 것
typedef int DWORD; //int 대신에 DWORD라 쓰겠다

int main(void)
{
    DWORD n = 0; //"int n = 0;"과 동일
}

//2-------------------------------------------------
//1.
int n;         //n은 변수
int *p;        //p는 포인터 변수
int x[3];      //x는 배열변수
void foo(int); //foo는 함수

//2.위에것을 그대로 복사해서 앞에 typedef를 붙였다

//변수자리에 있는 심볼을 변수가 아닌 type로 만들어 달라는 뜻이다.
typedef int n;
typedef int *p;
typedef int x[3];
typedef void foo(int);
/*typedef에 대한 의미
  ★변수자리에 있던 심볼이 변수가 아닌 타입이 된다.*/
 
//3.변수자리에 있는걸 타입으로 바꾸자
typedef int n;         //n은 타입
typedef int *p;        //p는 포인터 타입
typedef int x[3];      //x는 배열 타입
typedef void foo(int); //foo는 함수 타입

//4.
n a = 10;        //int a = 10;
x r = {1, 2, 3}; //int r[3] = {1,2,3}
foo goo;         //void goo(int); <- 즉 goo함수의 선언

typedef int DWORD;
typedef int AR[2];
typedef int AR2[2][3];

int main(void)
{
    AR x = {1, 2};                  //AR은 int[2]에 대한 type
    AR2 y = {{1, 2, 3}, {4, 5, 6}}; //AR2는 int [2][3]에 대한 type
}
/*
정리
변수 또는 함수 선언문 앞에 typedef를 붙이면 변수(함수)가 아닌 타입을 만들게 된다

-배열 타입의 typedef
typedef int AR1[2];
typedef int AR2[3][2];

AR1 x = {1,2};
AR2 y = {{1,2},{3,4},{5,6}}; 

-함수타입의 typedef
typedef int FUNC(int,int);
FUNC goo;
*/