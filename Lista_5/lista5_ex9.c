/* Exercício 9:
Uma matriz quadrada de inteiros é um quadrado mágico se a soma dos elementos de cada linha,
a soma dos elementos de cada coluna, a soma dos elementos da diagonal principal e da diagonal secundária são todos iguais. 
A matriz abaixo é um exemplo de quadrado mágico:

3  4 8
10 5 0
2  6 7

Escreva uma função que recebe como parâmetro uma matriz quadrada de tamanho no máximo 30 × 30, 
e suas dimensões n, e determina se ela é um quadrado mágico devolvendo 1 caso seja e 0 caso contrário. 
O protótipo da função deve ser:
int magico(int mat[30][30], int n);
*/
#include <stdio.h>

int magico(int mat[30][30], int n);

int main() {
int mat[30][30], n, i, j, r;

printf("Qual o valor do n, para a dimensao n x n da matriz: ");
scanf("%d", &n);

for(i = 0; i < n; i++) {
    for(j = 0; j < n; j++) {
        printf("\nInsira elemento na posicao (linha: %d, coluna: %d): ", i, j);
        scanf("%d", &mat[i][j]);
    }
}

printf("\nMatriz criada:\n");
for(i = 0; i < n; i++) {
    printf("| ");
    for(j = 0; j < n; j++) {
        printf("%d ", mat[i][j]);
    }
    printf("|\n");
}

r = magico(mat, n);

if(r == 1) {
    printf("\nA matriz e um quadrado magico!\n");
} else {
    printf("\nA matriz nao e um quadrado magico!\n");
}

return 0;
}

int magico(int mat[30][30], int n) {
    int temp[62], i, j, sum=0, c=0;
    ///Soma linhas;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            sum = sum + mat[i][j];
        }
        temp[c] = sum;
        c++;
        sum=0;
    }
    ///Soma colunas;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            sum = sum + mat[j][i];
        }
        temp[c] = sum;
        c++;
        sum=0;
    }
    ///Soma diagonal principal;
    for(i = 0; i < n; i++) {
        sum = sum + mat[i][i];
    }
    temp[c] = sum;
    c++;
    sum=0;
    ///Soma diagonal secundaria;
    for(i = 0, j = n-1; i < n, j >= 0; i++, j--) {
        sum = sum + mat[i][i];
    }
    temp[c] = sum;
    ///Comparacao final
    for(i = 1; i < c; i++) {
        if(temp[0] != temp[i]) {
            return 0;
        }
    }
    return 1;
}