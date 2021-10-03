/* Exercício 1:
Considere que tenha sido executado as seguintes instruções (assuma que o endereço de x é 1000 e de y é 1004):
(VIDE CÓDIGO ABAIXO)
Determine o valor especificado em cada item abaixo:
(VIDE CÓDIGO ABAIXO)
*/
#include <stdio.h>

int main() {
int x=10, y=20;
int *p1;
int *p2;
p1 = &x;
p2 = &y;

(*p1)++;

printf("%d", x);/// 11
printf("\n%d", y);/// 20
printf("\n%d", &x);/// 1000
printf("\n%d", &y);/// 1004
printf("\n%d", p1);/// 1000
printf("\n%d", p2);/// 1004
printf("\n%d", (*p1)+(*p2));/// 31
printf("\n%d", *(&x));/// 11
printf("\n%d", &(*p2));/// 1004

return 0;
}
