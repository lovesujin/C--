/*
*******************************************************************
*
목적 : 연습삼아 다시 한번 시작 하자...                            *
++PROGRAMER                                                       *
parkshim72@outlook.com                                            *
parkshim72@gmail.com                                              *
http://www.lovesujin.com                                          *
*
------------------------                                          *
SUPER USER : SHIM KYU SEON                                        *
------------------------                                          *
*
파일이름 : t07_ex01.cpp                                           *
*
*******************************************************************
*/
/*
*******************************************************************
* 2017년 2월 12일 일요일 11시58분                                 *
*   파일이름 : t07_ex01.cpp                                       *
*   만든이 : 심규선                                               *
*   프로그램 목적 : internet 강의 예제 C++                        *
*                                                                 *
*******************************************************************
*/
/*

// 출력하는 프로그램이 기본동작, 여기에 입력을 하게 하는 프로그램 만드는 프로그램..
// 밑에 프로그램은 기본임....

#include <stdio.h>

int main()
{
	int a = 5;
	int b = 3;

	int hap = a + b;
	int cha = a - b;
	int gop = a * b;
	int mok = a / b;

	printf("%d + %d = %d\n", a, b, hap);
	printf("%d - %d = %d\n", a, b, cha);
	printf("%d * %d = %d\n", a, b, gop);
	printf("%d / %d = %d\n", a, b, mok);

}

*/
/*
#include <stdio.h>

int main()
{
	int a, b;

	//입력을 받는 함수는 scanf() 임...
	//출력하는 함수는 prinft() 임...
	// & (엔퍼센드) = 포인터 ..

	scanf("%d%d", &a, &b); // &:포인터




	int hap = a + b;
	int cha = a - b;
	int gop = a * b;
	int mok = a / b;

	printf("%d + %d = %d\n", a, b, hap);
	printf("%d - %d = %d\n", a, b, cha);
	printf("%d * %d = %d\n", a, b, gop);
	printf("%d / %d = %d\n", a, b, mok);

}
*/

/*
#include <stdio.h>

int main()
{
	float a, b;

	//입력을 받는 함수는 scanf()임....
	//출력을 하는 함수는 printf()임....
	//& (엔퍼센드) = 포인터 ..

	scanf("%f %f", &a, &b); // & : 포인터 를 명칭한다..


	float hap = a + b;
	float cha = a - b;
	float gop = a*b;
	float mok = a / b;

	printf("%f + %f = %f\n", a, b, hap);
	printf("%f - %f = %f\n", a, b, cha);
	printf("%f * %f = %f\n", a, b, gop);
	printf("%f / %f = %f\n", a, b, mok);

}

*/

#include <stdio.h>

int main()

{

	float a, b;

	//입력을 받는 함수는 scanf()임....
	//출력을 하는 함수는 printf()임...
	//& (엔퍼센트) = 포인터..

	scanf("%f %f", &a, &b); // & : 포인터를 명친한다...

	float hap = a + b;
	float cha = a - b;
	float gop = a*b;
	float mok = a / b;

	printf("%f + %f = %f\n", a, b, hap);
	printf("%f + %f = %f\n", a, b, cha);
	printf("%f + %f = %f\n", a, b, gop);
	printf("%f + %f = %f\n", a, b, mok);

}

