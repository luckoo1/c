//1-------------------------------------------------
void f1(?)
{
}

void f2(?)
{
}

int main(void)
{
    int x1[3][2] = {0};
    int x2[3][2][2] = {0};

    f1(x1);
    f2(x2);
}

//2-------------------------------------------------
//아래같이 사용하면 컴파일 error
//배열은 자기와 똑같은 타입으로 복사할 수 없다
void f1(int a[3][2])
{
}

void f2(int a[3][2][2])
{
}

int main(void)
{
    int x1[3][2] = {0};
    int x2[3][2][2] = {0};

    f1(x1);
    f2(x2);
}

//3-------------------------------------------------
void f1(int (*a)[2])
{
    a[0][0];
    //a가 int 2개짜리 배열을 가리키는 포인터
    //배열에서 포인터는 *대신에 []연산을 사용할수 있다.
    //a[0] 적으면 배열을 가리키게 되어서 배열이 나오고
    //a[0][0]하면 위에서 나온 배열의 첫번째 요소
}

void f2(int (*a)[2][2])
{
    a[0][0][0] = 10;
}

int main(void)
{
    int x1[3][2] = {0};
    int x2[3][2][2] = {0};

    f1(x1); //2차배열이름 => 1차배열의 주소로 암시적 형변환
    //첫번째 요소가 1차배열이니깐
    f2(x2); //3차배열이름 => 2차배열의 주소로 암시적 형변환
}

/*
N차 배열을 함수인자로 전달하면
N-1차 배열을 가리키는 포인터로 받으면 된다
사용할때는 N차 배열처럼 사용하면 된다.

핵심 : 배열의 이름은 첫번째요소의 주소이다!
*/