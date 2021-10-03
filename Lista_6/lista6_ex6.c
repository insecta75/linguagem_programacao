/* Exercício 6:
Escreva uma função chamada media que recebe um vetor de double, um inteiro n que indica o tamanho do vetor, e um ponteiro para inteiro i. 
A função deve retornar a média dos n elementos no vetor e no endereço apontado por i deve retornar a posição do elemento que tem o valor mais próximo da média.
O protótipo da função deve ser:
double media(double vet[], int n, int *i);
*/
#include <stdio.h>

double media(double vet[], int n, int *i);

int main() {
int n, i;
double vet[100];

printf("Quantos numeros serao inseridos no vetor: ");
scanf("%d", &n);

printf("\nInsira os numeros em ordem crescente.\n");
for(int j=0; j < n; j++) {
    printf("\nInsira o %d elemento: ", j+1);
    scanf("%lf", &vet[j]);
}

printf("\nMedia: %.1lf", media(vet, n, &i));
printf("\nPosicao do valor mais proximo da media: %d\n", i);

return 0;
}

double media(double vet[], int n, int *i) {
double sum=0, mean, dmax, dmin;
int j, min, max;

    for(j=0; j < n; j++) {
        sum = sum + vet[j];
    }
    mean = sum/n;

    for(j=0; j < n; j++) {
        if(vet[j] > mean) {
            max = j;
            min = j-1;
            break;
        }
    }
    dmax = max - mean;
    dmin = mean - min;

    if(dmax > dmin) {
        *i = min;
    } else {
        *i = max;
    }
return mean;
}
