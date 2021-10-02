/* Exercício 6:
Escreva uma função que recebe um vetor de números reais e o seu tamanho por parâmetro e devolve a média aritmética dos números do vetor. 
O protótipo da função deve ser:
double media(double v[], int tam);
*/
#include <stdio.h>

double media(double v[], int tam);

int main() {
int tam, i;
double v[1000];

printf("Quantos numero tera o vetor: ");
scanf("%d", &tam);

for(i=0; i < tam; i++) {
    printf("\nDigite o numero %d: ", i+1);
    scanf("%lf", &v[i]);
}

printf("\nA media aritmetica e: %.1lf\n", media(v, tam));

return 0;
}

double media(double v[], int tam) {
    double sum=0;

    for(int i=0; i < tam; i++) {
        sum = sum + v[i];
    }
return sum/tam;
}