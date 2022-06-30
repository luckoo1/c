// 3_1.배열을가리키는포인터.c 참고 
// 3_7.배열을가리키는포인터활용.c 참고

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    malloc(40); //40바이트 할당

    malloc(sizeof(char) * 40);
    malloc(sizeof(int) * 10);
    malloc(sizeof(double) * 5);
    malloc(sizeof(short) * 10);
    /*
    위에 type를 적어줬지만 의미없다
    malloc(sizeof(int) * 10);
    여기서 인자로 int정보가 넘어가는건 아니다

    즉 위에 4줄은 그냥 다 같은의미다
    그냥 40바이트 크기만 할당한다.
    */
}

/*
1.
malloc함수는 데이터 타입에 대한 정보를 전달받지 않는다
malloc함수는 인자로 메모리 크기만을 전달 받는다
malloc(sizeof(char) * 40);
40바이트 메모리 크기만 전달하지 int의 타입정보는 전달하지 않는다.

2.
malloc함수는 데이터타입에 대한 정보없이 주소만 return한다.
그러므로 malloc함수의 반환 타입은 void*이다(data type에 대한 정보가 없으니깐)
*/

//1-------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    void *p1 = malloc(40); //이런 형식으로 받는게 정확한 거다.
}

//2-------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /*
    malloc 함수가 할당한 메모리는 어떻게 사용할 것인가?
    malloc함수가 반환한 주소는 사용자가 원하는 타입으로 캐스팅해서 사용한다.
    */

    char *p2 = (char *)malloc(sizeof(char) * 40);
    /*
    나는 40바이트 할당했는데(malloc(sizeof(char) * 40))
    char변수처럼 쓸거야((char *)malloc(sizeof(char) * 40))

    내가 40바이트 할당했는데 char가 40개 있는거처럼 쓸거야

    (char *)malloc(sizeof(char) * 40);에서 (char *)빼도 되지만
    명시적으로 적어주는게 좋다고 계속 배워왔다.
    "char *p2 ="에서 char적는건 필수
    */

    int *p3 = (int *)malloc(sizeof(int) * 10);
    int *p4 = (int *)malloc(sizeof(double) * 5);
    /*
    위와같이 써도 무방하다(p4)
    40바이트 할당했는데 int 10개처럼 쓸거야라는 뜻이다.
    하지만 가독성이 떨어지게 된다.
    */
}

/*
malloc함수의 return 값은 주소값이다.
위의 예에서는 40바이트의 주소값이다.
반환한 주소는 타입의 정보없이 크기에 대한 정보만 있다.
명시적 캐스팅으로 할당해줘야한다.
*/

//3-------------------------------------------------
//뭐지??? 잘못된 강의내용인가??? 
//일단 나는 그대로 적음
//2차원 배열 할당
//"40바이트를 short의 2차원 배열 4 * 5"처럼 쓰고싶다.
//참고로 short의 크기는 2다.
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //40바이트를 short의 2차원 배열 4 by 5
    short(*p5)[5] = (short(*)[5])malloc(sizeof(short) * 10);

    /*
    위의 경우는 "malloc(sizeof(short) * 10)"로 40byte공간을 할당했는데,
    그걸 "short(*)[5]"로 캐스팅했다.(short의 2차원배열처럼 쓸거야)
    "short[5] 배열"을 가리키는 포인터
    */
}

/*
내생각은 20바이트 공간을 "malloc(sizeof(short) * 10)"로 할당했는데
(short(*)[5])로 캐스팅했다.
그래서 4*5배열이 되는것이라 생각
20바이트 공간을 5로 나누어서
4*5배열이 되었다고 생각했다.
*/