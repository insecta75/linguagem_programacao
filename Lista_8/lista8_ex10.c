/* Exercício 10:
Escreva uma função recursiva para a busca sequencial em um vetor.
*/

///BUSCA SEQUENCIAL RECURSIVA;
#include <stdio.h>
#include <stdlib.h>

int buscaSequencial(int vet[], int tam, int chave);

int main () {
int pos, chave=45, tam=10, vet[] = {20, 5, 15, 24, 67, 45, 1, 76, -10, -1};

pos = buscaSequencial(vet, tam, chave);

    if(pos != -1) {
        printf("\nA posicao da chave %d no vetor é: %d\n", chave, pos);
    } else {
        printf("\nA chave %d não está no vetor! \n", chave);
    }

return 0;
}

int buscaSequencial(int vet[], int tam, int chave) {
    if(tam == 1) {
        if(vet[0] == chave) {
            return 0;
        } else {
            return -1;
        }
    } else {
        if(vet[tam-1] == chave) {
            return tam-1;
        }
        return buscaSequencial(vet, tam-1, chave);
    }
}
