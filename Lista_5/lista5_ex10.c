/* Exercício 10:
Escreva uma função que recebe como parâmetro três matrizes quadradas de tamanho no máximo 30 × 30, 
onde a primeira e a segunda matriz correspondem a entrada e a terceira corresponde a uma matriz resposta. 
A função deve calcular a multiplicação da primeira pela segunda matriz e guardar o resultado na matriz resposta. 
A função também recebe como parâmetro um inteiro n que indica as dimensões das matrizes. 
O protótipo da função deve ser:
void multiplica(double mat1[30][30], double mat2[30][30], double matRes[30][30], int n);
*/
#include <stdio.h>

void multiplica(double mat1[30][30], double mat2[30][30], double matRes[30][30], int n);

int main() {
int n, n1, n2, i, j;
double mat1[30][30], mat2[30][30], matRes[30][30];

printf("Qual o valor do n, para a dimensao n x n da matriz 1: ");
scanf("%d", &n1);

printf("\nQual o valor do n, para a dimensao n x n da matriz 2: ");
scanf("%d", &n2);

if (n1 == n2) {
    for(i = 0; i < n1; i++) {
        for(j = 0; j < n1; j++) {
            printf("\nMatriz 1: linha: %d, coluna: %d: ", i, j);
            scanf("%lf", &mat1[i][j]);
        }
    }
    for(i = 0; i < n2; i++) {
        for(j = 0; j < n2; j++) {
            printf("\nMatriz 2: linha: %d, coluna: %d: ", i, j);
            scanf("%lf", &mat2[i][j]);
        }
    }
    n = n1;
    multiplica(mat1, mat2, matRes, n);

    printf("\nMatriz Resultante:\n");
    for(i = 0; i < n; i++) {
        printf("| ");
        for(j = 0; j < n; j++) {
            printf("%.1lf ", matRes[i][j]);
        }
        printf("|\n");
    }
} else {
    printf("\nAs matrizes 1 e 2 devem ter a mesma dimensao!\n");
}
return 0;
}

void multiplica(double mat1[30][30], double mat2[30][30], double matRes[30][30], int n) {
    int i, j, k;
    double sum=0;

    for(i=0; i < n; i++) {
        for(j=0; j < n; j++) {
            for(k=0; k < n; k++) {
                sum = sum + (mat1[i][k] * mat2[k][j]);
            }
            matRes[i][j] = sum;
            sum=0;
        }
    }
}