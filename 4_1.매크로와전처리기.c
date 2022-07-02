//1-------------------------------------------------
/*
C/C++소스에서 "#으로 시작"하는 문장
#include <stdio.h>
#define MAX 256
#define SQUARE(n) n *n
컴파일러가 소스를 컴파일 하기전에 "전처리기"에 의해서 처리(치환)된다
*/

//2-------------------------------------------------
/*
매크로(함수)의 장점

1.속도가 빠르다 - 실제 호출이 아닌 문자 치환방식이므로

2.모든 타입에 동작하는 함수를 만들수 있다 - Generic프로그래밍(C++함수템플릿)

#define SQUARE(n) n *n
n자리에 int든 double이든 아무거나 들어가도 된다.

int n1 = square(3.3); //여기서는 data손실이 발생
3.3은 int니깐

doulbe n2 = SQUARE(3.3); //여기서는 "3.3*3.3"으로 진행됨
받는건 물론 double로 받아야한다.
*/

#include <stdio.h>

#define MAX 256        //매크로 상수
#define SQUARE(n) n *n //매크로 함수

int square(int n) { return n * n; }

int main(void)
{
    char name[MAX];

    int a = 3;
    int n1 = square(a);
    int n2 = SQUARE(a); //미리 만들어놔서 속도가 빠르다
    //속도가 빠르다 - 실제 호출이 아닌 문자 치환방식이므로
    printf("%d %d\n", n1, n2);
}

// 3-------------------------------------------------
//매크로(함수)의 단점(1~3)

#include <stdio.h>

#define MAX 256        //매크로 상수
#define SQUARE(n) ((n) * (n)) //3. 이게 안전한 코드

int square(int n) { return n * n; }

int main(void)
{
    char name[MAX];

    int a = 3;
    int n1 = square(a + 1); // 1.OK
    int n2 = SQUARE(a + 1); // 2. a+1*a+1되면 사칙연산 우선순위따른다.
                            //    엉뚱한 값이 나온다.
    printf("%d %d\n", n1, n2);
}
// 4-------------------------------------------------
//매크로(함수)의 단점

#include <stdio.h>

#define MAX 256 
#define SQUARE(n) ((n) * (n))

int square(int n)
{
    return n * n;
}

int main(void)
{
    char name[MAX];

    int a = 3;
    int n1 = square(++a); // OK
    int n2 = SQUARE(++a);
    printf("%d %d\n", n1, n2);
}
/*
((++a)*(++a))를 살펴보자
"++a"하면 4로 변경되고
"++a"하면 5로 변경되므로
25가 나온다
즉! ++이 두번되는거다

#define SQUARE(n) (n) * (n) <= 100프로 안전한 코드가 아니다
매크로 함수의 인자로 ++같은건 사용하지 않는 것이 좋다.
*/