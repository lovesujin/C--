/* �ڵ��� ���� ��� ���α׷�*/

#include <stdio.h>
int voice_charge(int a);
int text_charge(int a);
int result(int a, int b, int c,int d);

int main() {

	int voice, text;
	//int result_voice =0, result_text = 0

	printf("======================\n");
	printf("���� ��ȭ �ð���(��)? : ");
	scanf("%d", &voice);
	printf("�������� �Ǽ���? : ");
	scanf("%d", &text);

	printf("\n ���� ��ȭ �ð� : %d�� \n", voice);
	printf("���� ���� �Ǽ� : %d�� \n", text);

	if (text <= 20)
		text = 0;
	else
		text = text - 20;
	text_charge(text);
	result(voice, text, voice_charge(voice), text_charge(text));

     }

int voice_charge(int a){
	int sum_voice = 0;
	int temp = 0;
	if (a <= 100)
		sum_voice = a * 100;
	if (a > 100);
	temp = a - 100;
	sum_voice = 10000 + (temp * 80);

	return sum_voice;
     }

int result(int a, int b, int c, int d) {
	int initial = 10000;
	int subtotal = initial + c + d;
	int vat = subtotal * 0.1;
	int total = subtotal + vat;

	printf("\n �⺻��� %d��\n", initial);
	printf("������ȭ�� %d��  %d��\n", a, c);
	printf("���� ���۷� �ʰ� %d��(20�� ����) %d��\n", b, d);
	printf("\n �հ� %d��\n", subtotal);
	printf("�ΰ���(10%%) %d��\n", vat);
	printf("\n�̹� �� ��� %d��\n", total);

}


