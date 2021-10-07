/* Exercício 2:
Escreva uma definição recursiva para o cálculo de a ⇤ b e em seguida escreva um algoritmo recursivo para o calculo de a ⇤ b, 
onde a e b são inteiros não-negativos.
*/
#include <stdio.h>
#include <stdlib.h>

int multRecursivo(int a, int b);

int main () {
int a, b;

printf("Insira a e b (inteiros nao negativos) para a multiplicacao: ");
scanf("%d %d", &a, &b);

if(a < 0 || b < 0) {
    printf("\nO numero nao podem ser inteiros negativos!\n");
} else {
    printf("\nResultado da multiplicacao: %d\n", multRecursivo(a, b));
}

return 0;
}

int multRecursivo(int a, int b) {
    if(b == 0) {
        return 0;
    } else if (b == 1) {
        return a;
    } else {
        return a + multRecursivo(a, b-1);
    }
}