/* 내가 짜보는 C++ linux 이기때문에 compile 하기 쉽게 c로 만든다 */

#include <stdio.h>

int main(){

    double cell; //화씨 게산

    printf("섭씨 온도를 화씨 온도로 바꿔주는 프로그램 입니다. \n");
    printf("섭씨 온도를 입력해 주세요 : \n");
    scanf("%lf", &cell); //섭씨 온도를 입력 해라..

    printf("섭씨 %f 도느 화씨로 %f 도 입니다. \n" cell, 9*cell/5+32);

    return 0;

}

