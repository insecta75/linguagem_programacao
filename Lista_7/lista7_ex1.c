/* Exercício 1:
Suponha que criamos uma estrutura para armazenar produtos de um supermercado:
typedef struct Produto{
    char nome[80];
    double preco;
    int quantidade;
}Produto;
Implemente duas funções, uma que devolve o vetor ordenado por preços e outra que devolve o vetor ordenado pela quantidade de itens no estoque. 
Os protótipos são:
void ordenaPreco(Produto vet[], int n);
void ordenaQuant(Produto vet[], int n);
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Produto{
    char nome[80];
    double preco;
    int quantidade;
}Produto;

void insereProd(Produto vet[], int n);
void imprimirProd(Produto vet[], int n);
void ordenaPreco(Produto vet[], int n);
void ordenaQuant(Produto vet[], int n);

int main () {
int n;
Produto vet[1000];

    printf("\nNumero de produtos a serem inseridos: ");
    scanf("%d", &n);

    insereProd(vet, n);

    printf("\n########## Lista de Produtos ##########\n");
    imprimirProd(vet, n);

    ordenaPreco(vet, n);

    printf("\n########## Lista Ordenada por Preco ##########\n");
    imprimirProd(vet, n);

    ordenaQuant(vet, n);

    printf("\n########## Lista Ordenada por Quantidade ##########\n");
    imprimirProd(vet, n);

return 0;
}

void insereProd(Produto vet[], int n) {
    for(int i=0; i < n; i++) {
        printf("\nInsira %d produto:\n", i+1);
        printf("Nome: ");
        scanf("%s", vet[i].nome);
        printf("Preco: ");
        scanf("%lf", &vet[i].preco);
        printf("Quantidade: ");
        scanf("%d", &vet[i].quantidade);
    }
}

void imprimirProd(Produto vet[], int n) {
    for(int i=0; i < n; i++) {
        printf("\nPRODUTO %d:", i+1);
        printf("\nNome: %s", vet[i].nome);
        printf("\nPreco: %.1lf", vet[i].preco);
        printf("\nQuantidade: %d\n", vet[i].quantidade);
    }
}

void ordenaPreco(Produto vet[], int n) {    
    Produto temp[1];

    for(int i=0; i < n; i++) {
        for(int j=i+1; j < n; j++) {
            if(vet[i].preco > vet[j].preco) {
                temp[0] = vet[i];
                vet[i] = vet[j];
                vet[j] = temp[0];
            }
        }
    }
}

void ordenaQuant(Produto vet[], int n) {    
    Produto temp[1];

    for(int i=0; i < n; i++) {
        for(int j=i+1; j < n; j++) {
            if(vet[i].quantidade > vet[j].quantidade) {
                temp[0] = vet[i];
                vet[i] = vet[j];
                vet[j] = temp[0];
            }
        }
    }
}