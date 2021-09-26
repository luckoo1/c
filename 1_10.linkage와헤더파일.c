#include "1_10.linkage.h"

int main(void)
{
    cnt = 10;
    goo();

    int n = MAX1; //잘 작동한다
    int n = MAX;  //error뜬다. MAX가 양쪽에 있다고 한다.
    //g++은 그런데... 작동한다.
}

/*
const상수와 헤더파일
C언어 : const상수는 소스파일에 놓아야 한다.
C++언어 : const상수를 헤더파일에 놓을 수 있다.
*/