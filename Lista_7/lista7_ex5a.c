/* Exercício 5:
Refaça as funções de busca sequencial e busca binária vistas em aula assumindo que o vetor possui chaves que podem aparecer repetidas. 
Neste caso, você deve retornar em um outro vetor todas as posições onde a chave foi encontrada.
Protótipo da função: 
void busca(int vet[], int tam, int chave, int posicoes[], int *n)

• Você deve devolver em posicoes[] as posições de vet que possuem a chave, e devolver em *n o número de ocorrências da chave.
– OBS: Na chamada desta função, o vetor posições deve ter espaço suficiente (por exemplo, tam) para guardar todas as possíveis ocorrências da chave.
*/

///BUSCA SEQUENCIAL COM CHAVES REPETIDAS;
#include <stdio.h>
#include <stdlib.h>

void busca(int vet[], int tam, int chave, int posicoes[], int *n);

int main () {
int n, posicoes[10], vet[] = {20, 5, 15, 24, 67, 45, -1, 76, -1, -1};

    busca(vet, 10, -1, posicoes, &n);

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
    *n=0;
    for(int i=0; i<tam; i++) {
        if(vet[i] == chave) {
            posicoes[*n] = i;
            (*n)++;
        }
    }
}