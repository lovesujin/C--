/*
*******************************************************************
*
���� : ������� �ٽ� �ѹ� ���� ����...                            *
++PROGRAMER                                                       *
parkshim72@outlook.com                                            *
parkshim72@gmail.com                                              *
http://www.lovesujin.com                                          *
*
------------------------                                          *
SUPER USER : SHIM KYU SEON                                        *
------------------------                                          *
*
�����̸� : t06_ex03.cpp                                           *
*
*******************************************************************
*/
/*
*******************************************************************
*                                                                 *
*   �����̸� : t06_ex03.cpp                                       *
*   ������ : �ɱԼ�                                               *
*   ���α׷� ���� : internet ���� ���� C++                        *
*                                                                 *
*******************************************************************
*/

/*
// ����ȯ : �ڷ����� �ٸ� �ڷ������� �ٲٴ� �۾�
// int�� sum���� ����� �������� ����...

#include <stdio.h>

int main()
{
	int math = 90, korean = 95, english = 96;
	int sum = math + korean + english;
	double avg = sum / 3;

	printf("%f\n", avg); // 93.666667

	int a = 5 / 3;

}

// ���� / ���� = ����
// �Ǽ� / ���� = �Ǽ�
// �Ǽ� / �Ǽ� = �Ǽ�
*/

/*
//int�� double�� ������� �ϰ� sum�� ���� 93.666667�� ������ �ϴ� ���

#include <stdio.h>

int main()
{
	int math = 90, korean = 95, english = 96;
	double sum = math + korean + english;
	double avg = sum / 3;

	printf("%f\n", avg); // 93.666667

	int a = 5 / 3;

}

// ���� / ���� = ����
// �Ǽ� / ���� = �Ǽ�
// �Ǽ� / �Ǽ� = �Ǽ�
*/

// int�� ������ ���ΰ� double�� avg�� ��� (double)sum ���� �־��ִ� ����..
// double�� sum���̳�? , int�� sum���� (double)sum �� �ִ� ���....

#include <stdio.h>

int main()
{
	int math = 90, korean = 95, english = 96;
	int sum = math + korean + english;
	double avg = (double)sum / 3;

	printf("%f\n", avg); // 93.666667

	int a = 5 / 3;

}

// ���� / ���� = ����
// �Ǽ� / ���� = �Ǽ�
// �Ǽ� / �Ǽ� = �Ǽ�

// ���� + ���� = ����
// ���� + �Ǽ� = �Ǽ�
// �Ǽ� + �Ǽ� = �Ǽ�

