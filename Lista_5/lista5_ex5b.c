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

int pitagorico(int n);

int main() {
int n, r;

printf("Digite o numero inteiro n: ");
scanf("%d", &n);

if(n < 1) {
    printf("\nErro: n deve ser inteiro e positivo!\n");
} else {
    r = pitagorico(n);
    if(r == 1) {
        printf("\nO numero %d e pitagoricos!\n", n);
    } else {
        printf("\nO numero %d nao e pitagoricos!\n", n);
    }
}
return 0;
}

int pitagorico(int n) {
    int a, b, x;

    for(a=1; a < n; a++) {
        for(b=1; b < n; b++) {
            x = (a*a)+(b*b);
            if(n == x) {
                return 1;
            }
        }
    }
return 0;
}
