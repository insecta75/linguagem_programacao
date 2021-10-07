/* Exercício 1:
Escreva um algoritmo iterativo em C para avaliar a ⇤ b usando a adição, onde a e b são inteiros não negativos.
*/
#include <stdio.h>
#include <stdlib.h>

int multInterativo(int a, int b);

int main () {
int a, b;

printf("Insira a e b (inteiros nao negativos) para a multiplicacao: ");
scanf("%d %d", &a, &b);

if(a < 0 || b < 0) {
    printf("\nO numero nao podem ser inteiros negativos!\n");
} else {
    printf("\nResultado da multiplicacao: %d\n", multInterativo(a, b));
}

return 0;
}

int multInterativo(int a, int b) {
    int s=0;
    for(int i=0; i < b; i++) {
        s = s + a;
    }
return s;
}