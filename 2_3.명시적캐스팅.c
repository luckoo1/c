#include <stdio.h>

int main(void)
{
    int n = 0x11223344;
    int *p1 = &n;
    char *p2 = &n;
    short *p3 = &n;
    float *p4 = &n;

    printf("%p : %x\n", p1, *p1);
    printf("%p : %x\n", p2, *p2);
    printf("%p : %x\n", p3, *p3);
    printf("%p : %x\n", p4, *p4);

}
/*
변수의 주소를 다른 타입의 포인터 변수에 저장하는 것은?
메모리에 있는 "데이터를 해석하는 방식을 변경"하겠다는 의도
위험하므로 되도록 사용하지 않은 것이 좋다.
*/

//----------------------------------------------------

//꼭 필요하다면 명시적 캐스팅을 사용하는 것이 좋다
#include <stdio.h>

int main(void)
{
    int n = 0x11223344;
    int *p1 = &n;
    char *p2 = &n;
    short *p3 = &n;
    float *p4 = &n;

    //명시적 캐스팅
    int *p1 = &n;
    char *p2 = (char *)&n;
    short *p3 = (short *)&n;
    float *p4 = (float *)&n;
}

/*
char *p2 = (char*)&n;
short *p3 = (short*)&n;
float *p4 = (float*)&n;
이걸 보면 '아! 이사람은 실수가 아닌 의도구나!' 파악이 가능
C++은 명시적캐스팅 안하면 error가 뜬다
C언어는 경고다
*/
