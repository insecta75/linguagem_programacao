/* Exercício 2:
O que será impresso pelo programa abaixo? 
Considere que a seja inicializada com a soma dos 3 primeiros dígitos do seu RA e b seja inicializada com a soma dos demais dígitos. 
Por exemplo, se RA=123456 então a recebe inicialmente 6 enquanto que b recebe inicialmente 15.
*/
#include <stdio.h>

int main() {
int a=6, b=15, *c, *d;

c = &a;
printf("c: %d", *c);/// 6
d = c;
printf("\nd: %d", *d);/// 6
c = &b;
printf("\nc: %d", *c);/// 15
printf("\nd: %d", *d);/// 6

if(*d % 2 == 0) {/// 6%2
    *d = *d - 10;/// -4
} else {
    *c = 2 * (*c);
}

printf("\na = %d, b = %d\n", a, b);///a=-4; b=15

return 0;
}
