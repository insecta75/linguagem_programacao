/* Exercício 8:
Escreva uma função que recebe como parâmetro duas matrizes quadradas de tamanho no máximo 30 × 30, 
onde a primeira matriz corresponde a uma matriz de entrada e a segunda corresponde a uma matriz resposta. 
A função deve calcular a transposta da matriz de entrada e guardar o resultado na matriz resposta. 
A função também recebe como parâmetro um inteiro n que indica as dimensões das matrizes. 
O protótipo da função deve ser:
void transposta(double mat1[30][30], double matRes[30][30], int n);
*/
#include <stdio.h>

void transposta(double mat1[30][30], double matRes[30][30], int n);

int main() {
double mat1[30][30], matRes[30][30];
int n, i, j;

printf("Qual o valor do n, para a dimensao n x n da matriz: ");
scanf("%d", &n);

for(i = 0; i < n; i++) {
    for(j = 0; j < n; j++) {
        printf("\nInsira elemnto na posicao (linha: %d, coluna: %d): ", i, j);
        scanf("%lf", &mat1[i][j]);
    }
}

transposta(mat1, matRes, n);

printf("\nMatriz normal:\n");
for(i = 0; i < n; i++) {
    printf("| ");
    for(j = 0; j < n; j++) {
        printf("%.1lf ", mat1[i][j]);
    }
    printf("|\n");
}

printf("\nMatriz transposta:\n");
for(i = 0; i < n; i++) {
    printf("| ");
    for(j = 0; j < n; j++) {
        printf("%.1lf ", matRes[i][j]);
    }
    printf("|\n");
}
return 0;
}

void transposta(double mat1[30][30], double matRes[30][30], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            matRes[j][i] = mat1[i][j];
        }
    }
}