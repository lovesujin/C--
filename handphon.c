/* 핸드폰 가격 계산 프로그램 */

#include <stdio.h>

int main() {

    double chul; //출고가

    printf("핸드폰 가격을 계산해주는 프로그램입니다. \n");
    printf("핸드폰 가격을 입력해주세요:");

    scanf("%lf", &chul); //출고가를 입력 받는다
    
    printf("핸드폰 가격은 %d 입니다, 구입 가격은 %d 입니다. \n", chul, 998500 - chul);

    return 0;


    /*
    int a,b,c,d,e,f,g; // a:출고가, b:공시지원금, c:선택약정,d:온가족,

    a = 500000;
    b = 200000;
    c = 100000;
    d = 500000;
    e = 700000;
    f = 600000;
    g = 500000;

    

    printf("출고가-공시지원= %d \n", a - b );

    return 0;
    */
}

