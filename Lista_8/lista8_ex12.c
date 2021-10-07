/* Exercício 12:
Escreva uma função recursiva para o cálculo do máximo divisor comum de dois números inteiros não negativos. 
Lembre-se que:
• mdc(x,y) = x se y é zero,
• mdc(x,y) = mdc(y,x%y) caso contrário.
*/
#include <stdio.h>
#include <locale.h>

int mdcInt(int x, int y);
int mdcRec(int x, int y);

int main() {
int x, y;

printf("\nInsira os numeros inteiros e positivos x e y, onde x maior ou igual a y: ");
scanf("%d %d", &x, &y);
    if (x <= 0 || y < 0) {
        printf("\nErro: Os números não podem ser negativos ou x não pode ser nulo!\n");
    } else if (x < y) {
        printf("\nErro: O número y não pode ser o maior!\n");
    } else if(y == 0) {
        printf("\nO M.D.C dos dois número é: %d", x);
    } else {
        printf("\nO M.D.C Interativo dos números %d e %d é: %d\n", x, y, mdcInt(x, y));
    }

    if (x < 0 || y < 0) {
        printf("\nErro: Os números não podem ser negativos ou m não pode ser nulo!\n");
    } else {
        printf("\nO M.D.C Recursivo dos números %d e %d é: %d\n", x, y, mdcRec(x, y));
    }

return 0;
}

int mdcInt(int x, int y) {///Interativo (Alg e Log de Progr, Lista 2, ex6);
    for (int i=y; y >= 1; i--) {
        if (x%i == 0 && y%i == 0) {
             return i;
        }
    }
}

int mdcRec(int x, int y) {///Recursivo;
    if(x%y == 0) {
        return y;
    }
return mdcRec(y, x%y);
}