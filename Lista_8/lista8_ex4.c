/* Exercício 4:
Faça uma função recursiva em C que calcula o elemento mínimo em um vetor.
*/
#include <stdio.h>
#include <stdlib.h>

int minRecursivo(int vet[], int n);

int main () {
int n=5, vet[] = {2, 3, 1, 5, 4};

printf("Elemento minimo: %d\n", minRecursivo(vet, n));

return 0;
}

int minRecursivo(int vet[], int n) {
    int aux;
    if(n == 1) {
        return vet[0];
    } else {
        aux = minRecursivo(vet, n-1);
        if(aux < vet[n-1]) {
            return aux;
        }
        return vet[n-1];
    }
}