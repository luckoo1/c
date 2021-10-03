//핵심 : 배열에서 포인터는 *대신에 []연산을 사용할수 있다.(내생각)
//핵심 : 배열의 이름은 첫번째요소의 주소이다!(이건 이론)
//3장을 시작할건데 이거 기억잘해두자 그래야 헷갈리지 않는다.

//1-------------------------------------------------
#include <stdio.h>

int main(void)
{
    int x[3] = {10, 20, 30};

    printf("%d\n", x[0]); //10
    printf("%d\n", x);    //주소

    int *p = x;
}

/*
배열의 이름이 가지는 의미
배열의 이름은 배열의 주소(X)
배열의 이름은 배열의 첫번째 요소의 주소(O)
*/

//2-------------------------------------------------
//문제 : 변수 n,d,x의 주소를 담는 포인터 변수 p1,p2,p3을 만드세요
#include <stdio.h>

int main(void)
{
    int n = 10;
    double d = 3.4;
    int x[3] = {1, 2, 3};
}

//3-------------------------------------------------

#include <stdio.h>
/*
규칙
변수의 주소를 구하려면 변수 이름 앞에 "주소연산자(&)"를 붙인다
포인터 변수를 만들려면 변수 이름 앞에 "포인터 연산자(*)"를 붙인다
*/
int main(void)
{
    int n = 10;
    double d = 3.4;
    int x[3] = {1, 2, 3};

    int *p1 = &n;
    double *p2 = &d;

    //배열을 가리키는 포인터는 이렇게 쓸까???
    int *p3[3] = &x;
    /*
    위와같이 연산자가 여러개 있으면 연산자 우선순위를 따른다
    포인터연산자(*)보다는 배열연산자([])가 우선순위가 높다
    포인터 변수로 보는것이 아니라 우선순위 관계로 배열로 처리한다
    즉 아래처럼 주소를 담는 배열이 되는거다
    */
}

//4-------------------------------------------------
#include <stdio.h>

int main(void)
{
    int n1 = 10;
    int n2 = 20;
    int n3 = 30;

    //주소를 담는 배열

    int *p[3] = {&n1, &n2, &n3};

    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", *(p[i]));
    }
}

//4-------------------------------------------------
#include <stdio.h>

int main(void)
{
    int n = 10;
    double d = 3.4;
    int x[3] = {1, 2, 3};

    int *p1 = &n;
    double *p2 = &d;

    int(*p3)[3] = &x;
    //포인터연산을 먼저 적용할 수 있게 괄호를 사용했다
    //"너는 포인터변수구나 그런데 int를 3개짜리 가리키는구나" 판단한다
}

/*
정리
그림필기
포인터 배열vs배열을 가리키는 포인터

int *p3[3] = &x;
[]연산자를 먼저 해석한다
p3는 크기가 3인 배열, 각요소는 int*
32비트 환경에서 sizeof(p3)=>12

int(*p3)[3] = &x;
*연산자를 먼저 해석한다
p3는 포인터 변수, 배열(int[3])을 가리킨다
32비트 환경에서 sizeof(p3)=>4
*/