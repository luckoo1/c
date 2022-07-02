#define VAR(TYPE, NAME) TYPE NAME

int main(void)
{
    VAR(int, n) = 6; // int n
    printf("%d",n);

}
//6이 나오겠지
//----------------------------------------------------
#define VAR(TYPE, NAME) TYPE NAME

int main(void)
{
    VAR(int, n) = 6; // int n
    VAR(int, n) = 7; // int n
    printf("%d",n);

}
//같은 int n을 두번 선언하는 모양이되니깐 에러
//----------------------------------------------------
int main(void)
{
    // unique한 이름을 사용하는 변수를 선언하는 매크로
    VAR(int, n); // int n6
    VAR(int, n); // int n7
    //위의 예제에서 6과 7은 line number
    //line number적는 이유는 변수를 unique하게 만들려고
}
//----------------------------------------------------

int main(void)
{
    // unique한 이름을 사용하는 변수를 선언하는 매크로
    VAR(int, n) = 6; // int n6
    VAR(int, n) = 10; // int n7
    printf("%d",n6);
    printf("%d",n7);
}
/*
이런식으로 사용하고 싶은거다.
*/
//----------------------------------------------------

#define VAR(TYPE, NAME) TYPE NAME##__LINE__
int main(void)
{
    VAR(int, n); // int n6
    VAR(int, n); // int n7
}

//위와 같이 ##__LINE__쓰면 에러뜬다.
//----------------------------------------------------
/*
이렇게 사용하는 모양이 되므로..
*/
#define VAR(TYPE, NAME) TYPE NAME##__LINE__

int main(void)
{
    VAR(int, n) = 6; // int n
    printf("%d",n__LINE__);

}