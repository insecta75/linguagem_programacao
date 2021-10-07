/* Exercício 13:
Suponha que uma matriz binária quadrada M represente a ligação entre um conjunto de n cidades. 
Desta forma M [i,j] = 1 indica que existe uma estrada da cidade i para a cidade j, e M [i,j] = 0 caso contrário. 
Por exemplo, na matriz abaixo temos que a cidade 0 possui estradas para 1 e 2, já a cidade 1 possui estrada apenas para 2. 
Note que existe estrada de 0 para 1, mas não de 1 para 0, pois só há estradas de 2 e 3 para 0.

0 1 1 0
0 0 1 0
1 1 0 1
1 0 1 0

Escreva uma função recursiva que dada uma matriz M e uma cidade i determina todas as cidades que podem ser alcançadas a partir de i.
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 900

typedef struct {
    int cidOri;
    int cidDes;
}DADO;

typedef struct {
    DADO dados[MAX];
    int num;
}LISTA;

int verificaRec(int mat[30][30], int i, int j, int n, LISTA *resp);

int main() {
int mat[30][30], n, i, j;
LISTA *resp = malloc(sizeof(LISTA));

    printf("Digite o valor de n (numero de cidades) para a matriz n x n (de 2 a 30): ");
    scanf("%d", &n);

    if(n < 2) {
        printf("\nErro: Deve haver no minimo duas cidades!\n");
    } else {
        printf("\nDigite se ha estradas indo para a cidade (0 ausente, 1 existente).\n");
        ///Na estrada, (i) representa cidade origem (j) cidade destino;
        for (i=0; i < n; i++) {
            for (j=0; j < n; j++) {
                if (i == j) {
                    mat[i][j] = 0;
                } else {
                    printf("\nCidade de Origem %d para Cidade de Destino %d: ", i, j);
                    scanf("%d", &mat[i][j]);
                }
            }
        }
        resp->num = 0;

        verificaRec(mat, 0, 0, n, resp);

        printf("\nResposta:\n");
        for (i=0; i < resp->num; i++) {
            printf("\nCidade de Origem %d para Cidade de Destino %d\n", resp->dados[i].cidOri, resp->dados[i].cidDes);
        }
    }
    free(resp);
return 0;
}

int verificaRec(int mat[30][30], int i, int j, int n, LISTA *resp) {
    if(i == j) {
        return verificaRec(mat, i, j+1, n, resp);
    } else if(j == n) {
        return verificaRec(mat, i+1, 0, n, resp);
    } else if(i < n) {
        if (mat[i][j] == 1) {
            resp->dados[resp->num].cidOri = i;
            resp->dados[resp->num].cidDes = j;
            resp->num++;
        }
        return verificaRec(mat, i, j+1, n, resp);
    } else {
        return 0;
    }
}