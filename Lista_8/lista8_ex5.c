/* Exercício 5:
Faça uma função recursiva em C que calcula a média dos elementos de um vetor.
*/
#include <stdio.h>
#include <stdlib.h>

double medRecursivo(double vet[], int n, int tam);

int main () {
int tam=5;
double vet[] = {2, 3.5, 10, 5.2, 4.7};

printf("Elemento media: %.2lf\n", medRecursivo(vet, tam, tam));

return 0;
}

double medRecursivo(double vet[], int n, int tam) {
    double aux;
    if(n == 1) {
        return vet[0];
    } else {
        aux = medRecursivo(vet, n-1, tam);///Variavel somadora;
        if(n == tam) {
            return (vet[n-1] + aux)/tam;
        } else {
            return vet[n-1] + aux;
        }
    }
}