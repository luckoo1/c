//1-------------------------------------------------
#include <stdio.h>

void foo(int a);

int main(void)
{
    //1.
    int n = 0;
    int x[3] = {1, 2, 3};

    printf("%p\n", &n); //n의 주소
    printf("%d\n", n);  //n의 값

    printf("%p\n", &x); //배열의 주소
    printf("%p\n", x);  //첫번째의 요소의 주소로 암시적 형변환
                        //첫번째 요소의 주소
    
    /*
    //2
    -함수도 메모리(코드 메모리)에 기계어 코드가 놓여있다.
    주소연산자(&)를 통해서 함수의 주소도 구할 수 있다.
    */

    printf("%p\n", &foo); //함수의 주소
    printf("%d\n", foo);  //함수의 주소
                          //함수의 이름은 함수의 주소로 암시적 형변환

    /*
    -함수의 이름은 함수의 주소로 암시적 형 변환 된다.
    C++의 멤버함수는 반드시 주소연산자(&)를 사용해야 한다
    */

    //3
    foo(10);
    //주소를 담는 포인터변수를 만들어 보자

    int *p1 = &n;           //변수의 주소의 Type
    int(*p2)[3] = &x;       //배열의 주소의 Type
    void (*p3)(int) = &foo; //함수의 주소의 Type

    /*
    void foo(int a); 그대로 적은다음에
    이름만 지우면 void (int);
    이름 적을 자리에 포인터 변수이름을 적자
    void *p3(int) = &foo
    */

    /*
    void *p3(int) = &foo;
    이경우에 우선순위가 ()가 높다
    void *p3(int)
    반환값이 "void*"인 함수로 해석한다.
    */

    /*
    우선순위를 높이기 위해서
    void (*p3)(int) 사용했다.
    (*p3)는 포인터 변수인데 
    인자가 int이고 반환값이 void인 함수가 있다는걸 나타낸다.
    */

    /*
    ▣함수를 가리키는 포인터
    함수의 선언과 동일한 선언문을 만들고
    변수이름 앞에 *를 붙인다.
    우선 순위 문제로 ()를 표기해야 한다.
    */

    void (*p3)(int) = foo; //& 생략가능(함수의 이름은 함수의 주소로 암시적 형변환)
}
void foo(int a)
{
    printf("foo: %d\n", a);
}

/*
▣정리
-함수도 메모리(코드 메모리)에 기계어 코드가 놓여있다.
주소연산자(&)를 통해서 함수의 주소도 구할 수 있다.

-함수의 이름은 함수의 주소로 암시적 형 변환 된다.
C++의 멤버함수는 반드시 주소연산자(&)를 사용해야 한다

-함수를 가리키는 포인터
함수의 선언과 동일한 선언문을 만들고
변수이름 앞에 *를 붙인다.
우선 순위 문제로 ()를 표기해야 한다.
*/

//2-------------------------------------------------
#include <stdio.h>

int Add(int a, int b)
{
    return a + b;
}

//ADD는 코드메모리에 기계어 코드로 있다
//0x4000이라는 주소로 있다
//그림필기 참조
int main(void)
{
    Add(1, 2); //함수호출

    int (*f)(int, int) = &Add;
    //&Add는 0x4000번지를 뜻한다

    /*
    함수호출하기
    f  : 함수를 가리키는 포인터
    *f : 함수
    */

    (*f)(1, 2); //Add(1,2)와 동일

    *f(1,2);//error
    /*
    "*f(1,2);"적으면 안된다
    이유 : 연산자 우선순위상 ()가 빠르다
    "f(1,2)"를 먼저 호출하고 그 결과값에 *붙이는 격
    */

    f(1, 2); //Add(1,2)와 동일
             //C언어에서는 이걸 허용한다
             //이 모양을 다시 생각하면 함수의 주소(f)에 (1,2)를 붙인거다

    (&Add)(1, 2); //Add(1,2)와 동일
                  //이것도 허용된다.
}

/*
정리
함수를 가리키는 포인터로 함수를 호출하려면
(*f)(1,2) 또는 f(1,2)를 사용한다.
*/