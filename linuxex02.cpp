#include <stdio.h>

int main () {
int i, sum=0;

for (i=0; i<20; ++i){
    sum=sum+i;
}
printf("1부터 19까지의 합 : %d", sum);

return 0;
}
