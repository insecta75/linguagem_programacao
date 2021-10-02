/* Exercício 5:
Um inteiro positivo n é pitagórico se existem inteiros positivos a e b tais que a^2 + b^2 = n.
Por exemplo, 13 é pitagórico pois 2^2 + 3^2 = 13.

(a) Escreva uma função que recebe como parâmetro três inteiros a, b e n, e que devolve 1 caso a^2 + b^2 = n e devolve 0 caso contrário. 
O protótipo da função deve ser:
int teste(int a, int b, int n);

(b) Utilize a função do item anterior e escreva uma outra função que recebe como parâmetro um inteiro positivo n e verifica se n é pitagórico, 
devolvendo 1 caso n seja pitagórico e 0 caso contrário. O protótipo da função deve ser:
int pitagorico(int n);
*/
#include <stdio.h>

int teste(int a, int b, int n);

int main() {
int a, b, n, r;

printf("Digite tres numeros inteiros a, b, n: ");
scanf("%d %d %d", &a, &b, &n);

if(a < 1 || b < 1 || n < 1) {
    printf("\nErro: Todos os numeros devem ser inteiros e positivos!\n");
} else {
    r = teste(a, b, n);
    if(r == 1) {
        printf("\nO numero %d e pitagoricos!\n", n);
    } else {
        printf("\nO numero %d nao e pitagoricos!\n", n);
    }
}
return 0;
}

int teste(int a, int b, int n) {
    int x = (a*a)+(b*b);

    if(n == x) {
        return 1;
    } else {
        return 0;
    }
}
