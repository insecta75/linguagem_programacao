/* Exercício 9:
Escreva uma função recursiva que calcule [lg n], ou seja, o piso do logaritmo de n na base 2.
*/
#include <stdio.h>

int recLog2n(int n);

int main() {
int n;

printf("Digite o valor de n, para obter x, de 2^x = n: ");
scanf("%d", &n);

if(n < 1) {
    printf("\nErro: Valores devem ser inteiros positivos!\n");
} else {
    printf("\nResultado: %d\n", recLog2n(n));
}
return 0;
}

int recLog2n(int n) {
    if(n == 1) {
        return 0;
    }
    return 1 + recLog2n(n/2);
}