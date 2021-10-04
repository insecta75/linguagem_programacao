/* Exercício 5:
Refaça as funções de busca sequencial e busca binária vistas em aula assumindo que o vetor possui chaves que podem aparecer repetidas. 
Neste caso, você deve retornar em um outro vetor todas as posições onde a chave foi encontrada.
Protótipo da função: 
void busca(int vet[], int tam, int chave, int posicoes[], int *n)

• Você deve devolver em posicoes[] as posições de vet que possuem a chave, e devolver em *n o número de ocorrências da chave.
– OBS: Na chamada desta função, o vetor posições deve ter espaço suficiente (por exemplo, tam) para guardar todas as possíveis ocorrências da chave.
*/

///BUSCA BINARIA COM CHAVES REPETIDAS;
#include <stdio.h>
#include <stdlib.h>

void busca(int vet[], int tam, int chave, int posicoes[], int *n);
void troca(int *a, int *b);
void insertionSort(int vet[], int tam);

int main () {
int n, posicoes[10], vet[] = {20, 5, 1, 1, 5, 1, 1, 76, 78, 100};

    insertionSort(vet, 10);

    printf("Vetor Ordenado: ");
    for(int i=0; i<10; i++) {
        printf("%d , ", vet[i]);
    }
    printf("\n");

    busca(vet, 10, 5, posicoes, &n);

        if(n != 0) {
            printf("No vetor a chave aparece %d vez(es). As posicoes seriam:\n", n);
            for(int i=0; i < n; i++) {
                printf("%d ", posicoes[i]);
            }
            printf("\n");
        } else {
            printf("A chave não está no vetor! \n");
        }
return 0;
}

void busca(int vet[], int tam, int chave, int posicoes[], int *n) {
    int ini=0, fim=tam-1, meio;
    *n=0;

    while(ini<=fim) {
        meio = (ini+fim)/2;

        if(vet[meio] == chave) {
            posicoes[*n] = meio;
            (*n)++;
            for(int k=meio-1; k >= ini ; k--) {///Verifica valores inferiores ao meio;
                if(vet[k] == chave) {
                    posicoes[*n] = k;
                    (*n)++;
                } else {
                    break;
                }
            }
            for(int k=meio+1; k <= fim; k++) {///Verifica valores superiores ao meio;
                if(vet[k] == chave) {
                    posicoes[*n] = k;
                    (*n)++;
                } else {
                    break;
                }
            }
            break;
        } else if(vet[meio] > chave) {
            fim = meio - 1;
        } else {
            ini = meio+1;
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
