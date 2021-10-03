//1-------------------------------------------------
void f1(? n){}

int main(void)
{
    int n1 = 10;
    ? n2 = n1;

    f1(n1);

    int x1[3] = {1, 2, 3};
}

//2-------------------------------------------------
void f1(int n) {}

int main(void)
{
    int n1 = 10;
    int n2 = n1;

    f1(n1);

    int x1[3] = {1, 2, 3};
}

//대부분의 변수는 자신과 동일한 타입의 변수에 복사(초기화)할 수 있다.

//3-------------------------------------------------
void f1(int n) {}

int main(void)
{
    int n1 = 10;
    int n2 = n1;

    f1(n1);

    int x1[3] = {1, 2, 3};
    ? x2 = x1;
}

//4-------------------------------------------------
void f1(int n) {}
void f2(int a[3]) {} //2. error

int main(void)
{
    int n1 = 10;
    int n2 = n1;

    f1(n1);

    int x1[3] = {1, 2, 3};
    int x2[3] = x1;
    //1.이게 가능한가?
    //배열은 복사 될 수 없다.

    f2(x1);
}

//배열은 자신과 동일한 타입으로 복사 될 수 없다.

//5-------------------------------------------------
void f1(int n) {}
void f3(int (*a)[3])
{
    //a : 배열의 주소
    //*a : 배열
    *a[0]; //첫번째 요소
}
//2.배열을 가리키는 포인터로 받자
//포인터 변수인데 int3개짜리를 가리키는 거다

int main(void)
{
    int n1 = 10;
    int n2 = n1;

    f1(n1);

    int x1[3] = {1, 2, 3};

    f3(&x1);
    //1. 위와 같이 배열의 주소를 보내면
}

/*
배열의 이름이 아닌 배열의 주소로 전달하면
배열의 요소에 접근하기가 복잡해 진다.
*/

//6-------------------------------------------------

void f4(int *a)
{
    *a; //첫번째 요소
    //배열에서 포인터는 *대신에 []연산을 사용할수 있다.
    a[0]; //첫번째 요소를 가리켰다고 생각
    a[1]; //두번째 요소를 가리켰다고 생각
}

int main(void)
{
    int n1 = 10;
    int n2 = n1;

    f1(n1);

    int x1[3] = {1, 2, 3};

    f4(x1); //배열이름 전달
    //배열의 이름은 요소의 주소로 암시적 형변환 된다.
}
/*
배열주소가 아닌 이름을 전달하고 요소의 포인터로 받으면
기존 배열과 동일한 방식으로 요소에 접근할 수 있게 된다.
*/