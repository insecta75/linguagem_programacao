/* Exercício 2:
Suponha que criamos uma estrutura para armazenar Datas:
typedef struct Data{
    int dia;
    int mes;
    int ano;
}Data;
Implemente um algoritmo que receba um vetor de Datas como parâmetro e que retorne as datas em ordem cronológica. 
Protótipo da função é:
void ordena(struct Data vet[], int tam);
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Data {
    int dia;
    int mes;
    int ano;
}Data;

int inserir(struct Data vet[], int tam);
void ordena(struct Data vet[], int tam);

int main () {
int tam, r;
Data vet[1000];

    printf("Quantas datas serao inseridas: ");
    scanf("%d", &tam);

    r = inserir(vet, tam);

    if(r == 0) {
        printf("\nDatas inseridas:");
        print(vet, tam);

        ordena(vet, tam);

        printf("\nDatas ordenadas:");
        print(vet, tam);
    }
return 0;
}

int inserir(struct Data vet[], int tam) {
    for(int i=0; i < tam; i++) {
        printf("\nInsira a %d data nessa sequencia: dia mes ano ", i+1);
        scanf("%d %d %d", &vet[i].dia, &vet[i].mes, &vet[i].ano);
        if(vet[i].dia < 1 || vet[i].dia > 31) {
            printf("\nErro: Dia invalido!\n");
            return 1;
        }
        if(vet[i].mes < 1 || vet[i].mes > 12) {
            printf("\nErro: Mes invalido!\n");
            return 1;
        }
    }
return 0;
}

void print(struct Data vet[], int tam) {
    for(int i=0; i < tam; i++) {
        printf("\n%d / %d / %d", vet[i].dia, vet[i].mes, vet[i].ano);
    }
}

void ordena(struct Data vet[], int tam) {
    Data temp[1];

    for(int i=0; i < tam; i++) {
        for(int j=i+1; j < tam; j++) {
            if(vet[i].ano > vet[j].ano) {
                temp[0] = vet[i];
                vet[i] = vet[j];
                vet[j] = temp[0];
            } else if(vet[i].mes > vet[j].mes && vet[i].ano == vet[j].ano) {
                temp[0] = vet[i];
                vet[i] = vet[j];
                vet[j] = temp[0];
            } else if(vet[i].dia > vet[j].dia && vet[i].mes == vet[j].mes && vet[i].ano == vet[j].ano) {
                temp[0] = vet[i];
                vet[i] = vet[j];
                vet[j] = temp[0];
            } else {
                continue;
            }
        }
    }
}