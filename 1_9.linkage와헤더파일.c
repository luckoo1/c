//static을 추가했다.
#include "1_9.linkage.h"

int main(void)
{
    cnt = 10;
    goo();
}
//정상적으로 동작한다

/*
결론
External linkage을 가지는 심볼은 헤더파일에 넣으면 안된다
Internal linkage를 가지는 심볼은 헤더에 넣을 수 있다.
*/