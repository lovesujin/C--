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
파일이름 : t06_ex03.cpp                                           *
*
*******************************************************************
*/
/*
*******************************************************************
*                                                                 *
*   파일이름 : t06_ex03.cpp                                       *
*   만든이 : 심규선                                               *
*   프로그램 목적 : internet 강의 예제 C++                        *
*                                                                 *
*******************************************************************
*/

/*
// 형변환 : 자료형을 다른 자료형으로 바꾸는 작업
// int를 sum으로 계산을 했을때의 계산법...

#include <stdio.h>

int main()
{
	int math = 90, korean = 95, english = 96;
	int sum = math + korean + english;
	double avg = sum / 3;

	printf("%f\n", avg); // 93.666667

	int a = 5 / 3;

}

// 정수 / 정수 = 정수
// 실수 / 정수 = 실수
// 실수 / 실수 = 실수
*/

/*
//int를 double로 계산으로 하고 sum의 값을 93.666667로 나오게 하는 방법

#include <stdio.h>

int main()
{
	int math = 90, korean = 95, english = 96;
	double sum = math + korean + english;
	double avg = sum / 3;

	printf("%f\n", avg); // 93.666667

	int a = 5 / 3;

}

// 정수 / 정수 = 정수
// 실수 / 정수 = 실수
// 실수 / 실수 = 실수
*/

// int는 가만이 나두고 double의 avg에 잠시 (double)sum 값을 넣어주는 계산식..
// double에 sum값이냐? , int에 sum값을 (double)sum 에 넣는 방식....

#include <stdio.h>

int main()
{
	int math = 90, korean = 95, english = 96;
	int sum = math + korean + english;
	double avg = (double)sum / 3;

	printf("%f\n", avg); // 93.666667

	int a = 5 / 3;

}

// 정수 / 정수 = 정수
// 실수 / 정수 = 실수
// 실수 / 실수 = 실수

// 정수 + 정수 = 정수
// 정수 + 실수 = 실수
// 실수 + 실수 = 실수

