/* Exercício 4:
Escreva uma função que recebe um valor inteiro positivo n como parâmetro e dois ponteiros para inteiros b e k. 
A função deve encontrar um valor inteiro b tal que b^k = n para algum inteiro k , e b seja o menor possível. 
A função deve retornar no endereço apontado por b (respectivamente k) o valor de b (respectivamente k) encontrado. 
O protótipo da função deve ser:
void menor_base_log(int n, int *b, int *k);
*/
#include <stdio.h>

void menor_base_log(int n, int *b, int *k);

int main() {
int n, b, k;

printf("Digite o valor de n, da formula b^k = n: ");
scanf("%d", &n);

if(n < 1) {
    printf("\nO numero n deve ser inteiro e positivo!\n");
} else if(n == 1) {
    printf("\nO valor de b seria: 1\n");
} else {
    menor_base_log(n, &b, &k);
    printf("\nOs valores seriam. b: %d, k: %d\n", b, k);
}

return 0;
}

void menor_base_log(int n, int *b, int *k) {
    int x=n, B=2;
    *k=0;

    while(B <= x) {
        if(n%B == 0) {
            n = n/B;
            (*k)++;///retorna k;
            if(n == 1) {
                *b = B;///retorna o menor b;
                break;
            }
        } else {
            n = x;///n volta ao valor inicial;
            *k=0;///k volta ao valor inicial;
            B++;///soma 1 ao b;
        }
    }
}