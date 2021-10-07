/* Exercício 11:
Escreva uma função recursiva para a busca binária em um vetor.
*/

///BUSCA BINARIA RECURSIVA;
#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int vet[], int ini, int fim, int chave);
void troca(int *a, int *b);
void insertionSort(int vet[], int tam);

int main () {
int pos, chave=15, tam=10, ini=0, fim=tam-1, vet[] = {20, 5, 15, 24, 67, 45, 1, 76, 78, 100};

    insertionSort(vet, tam);

    printf("Vetor Ordenado: ");
    for(int i=0; i<10; i++) {
        printf("%d , ", vet[i]);
    }
    printf("\n");

    pos = buscaBinaria(vet, ini, fim, chave);

    if(pos != -1) {
        printf("\nA posicao da chave %d no vetor é: %d\n", chave, pos);
    } else {
        printf("\nA chave %d não está no vetor! \n", chave);
    }
return 0;
}

int buscaBinaria(int vet[], int ini, int fim, int chave) {
    int meio = (ini+fim)/2;

    if(fim < 0 || ini > fim) {
        return -1;
    } else {
        if(vet[meio] == chave) {
            return meio;
        } else if(vet[meio] > chave) {
            fim = meio - 1;
            buscaBinaria(vet, ini, fim, chave);
        } else {
            ini = meio + 1;
            buscaBinaria(vet, ini, fim, chave);
        }
    }
}

void troca(int *a, int *b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void insertionSort(int vet[], int tam) {
    int i, j;
    for(i=1; i<tam; i++) {
        j=i; /// Colocar elemento v[i] na pos correta;
        while(j>0) { /// trocar v[i] com elementos anteriores;
            /// até achar sua posicao correta;
            if(vet[j-1] > vet[j]) {
                troca(&vet[j-1], &vet [j]);
                j--;
            } else {
                break;
            }
        }
    }
}