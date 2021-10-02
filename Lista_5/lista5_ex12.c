/* Exercício 12:
No jogo Sudoku temos uma matriz 9 × 9 dividida em 9 quadrados de 3 × 3 preenchidos previamente com alguns números entre 1 e 9 (vejo o exemplo à esquerda abaixo). 
Uma solução para uma instância do jogo consiste no preenchimento de todas as posições vazias com números entre 1 e 9 respeitando-se as seguintes regras:

(a) Não pode haver números repetidos em um mesmo quadrado, ou seja, cada número entre 1 e 9 deve aparecer exatamente uma vez em cada quadrado.
(b) Não pode haver números repetidos em nenhuma linha da matriz.
(c) Não pode haver números repetidos em nenhuma coluna da matriz.

Escreva uma função que recebe uma matriz 9 × 9 por parâmetro que representa uma proposta de solução para um sudoku, 
e testa se a matriz é ou não uma solução para um sudoku, devolvendo 1 em caso verdadeiro e 0 caso contrário. 
O protótipo da função deve ser:
int solucao(int mat[9][9]);
Veja abaixo um exemplo (direita) de uma matriz solução para um sudoku.

(VEJA EXEMPLO NA LISTA)
*/
#include <stdio.h>
#include <stdlib.h>

int solucao(int mat[9][9]);

int main() {
int i, j, r, mat[9][9];

printf("Jogo Sudoku (matriz: 9x9).\n");
printf("Preencha todas as posicoes com valores de 1 a 9.\n");

for(i = 0; i < 9; i++) {
    for(j = 0; j < 9; j++) {
        printf("\nElemento na posicao (linha: %d, coluna: %d): ", i, j);
        scanf("%d", &mat[i][j]);
    }
}

printf("\nMatriz criada:\n");
for(i = 0; i < 9; i++) {
    printf("| ");
    for(j = 0; j < 9; j++) {
        printf("%d ", mat[i][j]);
    }
    printf("|\n");
}

r = solucao(mat);
if (r == 1) {
    printf("\nA matriz proposta representa uma solucao sudoku!\n");
} else {
    printf("\nA matriz proposta NAO representa uma solucao sudoku!\n");
}
return 0;
}

int solucao(int mat[9][9]) {
    int i, j, k, v, n, c=0, temp[9];

    ///Verifica a linha da matriz por numeros repetidos;
    for(i=0; i < 9; i++) {
        for(j=0; j < 9; j++) {
            for(k=j+1; k < 9; k++) {
                if(mat[i][j] == mat[i][k]) {
                    return 0;
                }
            }
        }
    }
    ///Verifica a coluna da matriz por numeros repetidos;
    for(i=0; i < 9; i++) {
        for(j=0; j < 9; j++) {
            for(k=j+1; k < 9; k++) {
                if(mat[j][i] == mat[k][i]) {
                    return 0;
                }
            }
        }
    }
    ///Verifica em cada quadrado da matriz por numeros repetidos;
    v=0;
    n=3;
    while(n < 10) {///Analisa os tres quadrados a esquerda;
        for(i=v; i < n; i++) {
            for(j=0; j < 3; j++) {
                temp[c] = mat[i][j];
                c++;
            }
        }
        c=0;
        for(i=0; i < 9; i++) {
            for(j=i+1; j < 9; j++) {
                if(temp[i] == temp[j]) {
                    return 0;
                }
            }
        }
        v=v+3;
        n=n+3;
    }

    v=0;
    n=3;
    while(n < 10) {///Analisa os tres quadrados do meio;
        for(i=v; i < n; i++) {
            for(j=3; j < 6; j++) {
                temp[c] = mat[i][j];
                c++;
            }
        }
        c=0;
        for(i=0; i < 9; i++) {
            for(j=i+1; j < 9; j++) {
                if(temp[i] == temp[j]) {
                    return 0;
                }
            }
        }
        v=v+3;
        n=n+3;
    }

    v=0;
    n=3;
    while(n < 10) {///Analisa os tres quadrados a direita;
        for(i=v; i < n; i++) {
            for(j=6; j < 9; j++) {
                temp[c] = mat[i][j];
                c++;
            }
        }
        c=0;
        for(i=0; i < 9; i++) {
            for(j=i+1; j < 9; j++) {
                if(temp[i] == temp[j]) {
                    return 0;
                }
            }
        }
        v=v+3;
        n=n+3;
    }
    return 1;
}
