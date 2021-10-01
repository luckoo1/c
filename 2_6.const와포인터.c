//1-------------------------------------------------
#include <stdio.h>

int main(void)
{
    int n = 10;

    const int *p3 = &n;
    n = 30;   //ok
    *p3 = 30; //error
    //읽기만 가능하다
}

//2-------------------------------------------------
#include <stdio.h>

int main(void)
{
    int n1 = 10; //read와 write가능

    const int c1 = 10; //write가능

    const int c2 = 10;
    int const c3 = 10; //이렇게도 가능
    //Data type의 앞 또는 뒤쪽에 표기할 수 있다.

    const int c4;
    printf("%d\n", c4);
    /*
    초기화되지 않은 const상수
    C에서는 경고(Warning)
    C++에서는 컴파일에러(Error)

    초기화 되지 않은 const상수는 절대 사용하지마라
    */
}

//3-------------------------------------------------
#include <stdio.h>

int main(void)
{
    int n = 10;

    int *p1 = &n;

    //char *p2 = &n; //C에서는 경고 C++에서는 에러
    char *p2 = (char *)&n; //명시적으로 적어줌

    const int *p3 = &n;
}

/*
1.
포인터 변수를 해석하는 방법
포인터 변수가 가진 주소를 따라가면 
"*연산자 앞에 있는 타입의 데이터"가 있다.

2.
예제)그림필기참조
int *p1 = &n;
*p1이 가진 1000번지를 따라가면 *앞에 있는 int type의 데이터가 있을거다

3.
char *p2 = &n;
*p2이 가진 1000번지를 따라가면 *앞에 있는 char type의 데이터가 있을거다
그런데 int가 있네....?
기존에 배웠듯이 이렇게 하는건 메모리 바라보는 관점을 바꾸겠다는 거다
원래는 int지만 앞으로 char처럼 생각할게!
C에서는 경고 C++에서는 에러

4.
const int *p3 = &n;에서
*p3이 가진 1000번지를 따라가면 *앞에 있는 const int type의 데이터가 있을거다
int가 있기는 한데 const int는 아니잖아
n은 read와 write를 다 할 수 있잖아
*p3를 통해서 1000번지 접근하면 읽기만 하게 할거야!
메모리에 제약을 주는거다
const int *p3 = &n;은 그냥 돌아간다.
*/

//4-------------------------------------------------
#include <stdio.h>

int main(void)
{
    int n = 10;

    const int *p3 = &n;
    n = 30;   //ok
    *p3 = 30; //error
    //읽기만 가능하다
}

/*
일반 변수와 상수를 가리키는 포인터
상수가 아닌 일반 변수의 주소를 "상수를 가리키는 포인터"에 담을 수 있다.

원본은 Read와 write 모두 가능하지만 포인터 변수를 통해서는 읽기만 하겠다는 의도
*/

//5-------------------------------------------------

#include <stdio.h>

int main(void)
{
    int n = 10;

    int *p1 = &n;       //OK
    const int *p2 = &n; //OK

    const int c = 10;

    int *p3 = &c;       //이게 문제네?
    const int *p4 = &c; //OK
}
/*
그림필기
int *p3 = &c; 
*p3이 가진 1000번지를 따라가면 *앞에 있는 int type의 데이터가 있을거다

이렇게 되면 원본은 read만 가능한데 read와 write를 가능하게 만들어 버린다
원본이 가진 특수함을 제약하는게 아니라 더 많은일을 하게 하려한다
C에서는 경고,C++에서는 error
*/

#include <stdio.h>

int main(void)
{
    const int c = 10;

    int *p3 = (int *)&c; //명시적으로 캐스팅하면 문제없긴하다
    const int *p4 = &c;

    *p3 = 20; //OK
    /*
    값을 못바꾸는 변수 C를 만들어놓고 값을 바꿔버리네...
    컴파일러에 따라 값이 바뀔수도 있고 안바뀔수도 있다
    결론은 이런 코드를 사용하면 안된다!!
    잠깐 주소를 보관하는 용도정도만 사용해라
    */
}

/*
const상스의 주소를 "비상수를 카리키는 포인터"로 명시적 캐스팅 할수는 있지만
포인터를 사용해서 상수값을 변경하는 코드를 사용하는 것은 좋지 않다
*/