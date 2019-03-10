/* 핸드폰 사용료 계산 프로그램*/

#include <stdio.h>
int voice_charge(int a);
int text_charge(int a);
int result(int a, int b, int c,int d);

int main() {

	int voice, text;
	//int result_voice =0, result_text = 0

	printf("======================\n");
	printf("음성 통화 시간은(분)? : ");
	scanf("%d", &voice);
	printf("문자전송 건수는? : ");
	scanf("%d", &text);

	printf("\n 음성 통화 시간 : %d분 \n", voice);
	printf("문자 전송 건수 : %d건 \n", text);

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

	printf("\n 기본요금 %d원\n", initial);
	printf("음성통화료 %d분  %d원\n", a, c);
	printf("문자 전송료 초과 %d건(20건 무료) %d원\n", b, d);
	printf("\n 합계 %d원\n", subtotal);
	printf("부가세(10%%) %d원\n", vat);
	printf("\n이번 달 요금 %d원\n", total);

}


