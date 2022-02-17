//1-------------------------------------------------
#include <stdio.h>

int main(void)
{
    int n1 = 0x11223344;
    int n2 = 0x44;
}

/*
메모리에 데이터가 저장되는 방식

▣빅 엔디언(Big-endia)
 11 22 33 44

모토롤라 프로세서
사람이 읽는 방식과 동일하기 때문에 디버깅시에 메모리의 값을 읽기가 편리

▣리틀 엔디언(Little-endian)
44 33 22 11
인텔 계열 CPU
바이트 단위로 거꾸로 보관
메모리 값을 읽기가 불편하다
메모리에 저장된 값의 하위 바이트만 사용할 때는 별도의 계산이 필요없는 장점

ex) int n2 = 0x44; 에서 
    빅 엔디언이었다면 "00 00 00 44"가 되고
    리들 엔티언에서는 "44 00 00 00"이 된다

▣바이 엔디언(Bi-endian)
 SW또는 HW적으로 빅엔디언/리틀엔티언 방식을 선택할 수 있다
ARM,PowerPC,DEC알파,MIPS,PA-RISC,IA-64

 ▣미들 엔디언(Middle-endian)
 34 12 78 56
 45 78 12 32

 PDP-11
 */

//2-------------------------------------------------
//엔디언 방식을 조사하는 방법

#include <stdio.h>

int main(void)
{
    int n1 = 0x11223344;
    char *p = (char *)&n1; //강제로 char포인터로 캐스팅

    if (*p == 0x11)
    {
        printf("Big endian\n");
    }
    else if (*p == 0x44)
    {
        printf("Little endian\n");
    }
    else 
    {
        printf("Unknown endian\n");
    }
}

/*
그림필기 넣자
p가 가리키는 곳이 
11이면 빅엔디안
44면 리틀엔디안
*/
//3-------------------------------------------------
//Byte order와 네트워크 프로그래밍
#include <stdio.h>
#include <winsock2.h> //for window
//#include <arpa/inet.h> //for linux

int main(void)
{
    int n1 = 0x11223344;

    int n2 = htonl(n1);

    printf("%x\n", n1);
    printf("%x\n", n2);
}
/*
Little endian방식 PC와
Big endian방식 PC가 통신을 한다면..?
0x11223344전송하면 거꾸로 해석이 된다

다른환경의 네트워크 통신에서 중요하다
 
전송할 데이터를 Network표준방식(Big Endian)으로 변경해서 전송해야한다.
*/

/*
▣엔디언방식 바꾸는 명령어
Host방식 -> Big Endian으로 변경
htonl : host to network long(4바이트를 바꿀때)
htons : host to network short(2바이트를 바꿀때)

Host방식이 기존에 Big Endian이었으면 바뀌지 않고 유지
Host방식이 기존에 Little Endian이었으면 Big Endian로 변경

Big Endian -> Host방식으로 변경
htonl : network to host long
htons : network to host short
여기서 말하는 Host방식은 Little일수도있고 Big일수도 있다.
*/

int main(void)
{
    int n1 = 0x11223344;
    // intel CPU니깐 0x44332211로 저장된다.
    int n2 = htonl(n1);
    // Big endian방식으로 전송하기 위해서 거꾸로 n2에 저장한다.

    printf("%x\n", n1); // 0x11223344
    printf("%x\n", n2); // 0x44332211
}