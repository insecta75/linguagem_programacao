/* Exercício 4:
Escreva uma função que recebe um valor inteiro positivo n como parâmetro e devolve um valor inteiro b tal que b k = n para algum inteiro k, e b seja o menor possível. 
Por exemplo, se n = 27 então o valor devolvido deve ser 3, já se n = 12 então o valor devolvido deve ser 12. 
Não use funções de bibliotecas na sua solução. O protótipo da função deve ser:
int menor_base_log(int n);
*/
#include <stdio.h>

int menor_base_log(int n);

int main() {
int n;

printf("Digite o valor de n, da formula b^k = n: ");
scanf("%d", &n);

if(n < 1) {
    printf("\nO numero n deve ser inteiro e positivo!\n");
} else if(n == 1) {
    printf("\nO valor de b seria: 1\n");
} else {
    printf("\nO valor de b seria: %d\n", menor_base_log(n));
}

return 0;
}

int menor_base_log(int n) {
    int b=2, x=n;

    while(b <= x) {
        if(n%b == 0) {
            n = n/b;
            if(n == 1) {
                return b;///retorna o menor b;
            }
        } else {
            n = x;///n volta ao valor inicial;
            b++;///soma 1 ao b;
        }
    }
}