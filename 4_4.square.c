//함수 구현
int square(int a)
{
    return a * a;
}

/*
2.
square.c가 컴파일 된 후 
object파일에서 함수 이름이

window라면 _square
linux라면 square

즉
window라면 call _square
linux라면 call square
로 바뀐다.
*/