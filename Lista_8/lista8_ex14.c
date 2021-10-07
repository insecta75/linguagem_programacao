/* Exercício 14:
VIDE LISTA 8 PELO ENUNCIADO.
*/

//RECURSAO: TRIANGULO DE PASCAL;
#include <stdio.h>
#include <stdlib.h>

int fatr(int n);
int triangPascal(int n, int k);

int main () {
int n, k;

printf("Digite o valor de n e k: ");
scanf("%d %d", &n, &k);

if(n >= 0 && k >= 0) {
    if(n >= k) {
        printf("\nResultado: %d\n", triangPascal(n, k));
    } else {
        printf("\nErro: O valor de n deve ser maior ou igual ao k!\n");
    }
} else {
    printf("\nErro: Os valores nao podem ser inteiro negativo!\n");
}
return 0;
}

int triangPascal(int n, int k) {
    return fatr(n) / (fatr(k) * fatr(n-k));
}

int fatr(int n) {
    int x, r;
    if(n <= 1) {///Passo Básico;
        return 1;
    } else {
        x = n-1;
        r = fatr(x);///Sabendo o fatorial de (n−1);
        return (n*r);///Calculamos o fatorial de n;
    }
}
