/* Exercício 4:
Suponha que criamos uma estrutura para armazenar dados de pessoas e um vetor para armazenar dados de várias pessoas:
typedef struct Pessoa{
    int rg;
    int cpf;
    char nome[80];
}Pessoa;

Pessoa cadastro[100];

Suponha que o vetor esteja ordenado em ordem crescente por valor de RG. 
Implemente uma função de busca por RG, que opera como a busca binária, e que caso exista uma pessoa no cadastro com o RG a ser buscado, 
devolve o índice deste no cadastro, e devolve -1 caso não exista uma pessoa com o RG a ser buscado.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoa{
    int rg;
    int cpf;
    char nome[80];
}Pessoa;

void armazenaDados(Pessoa cadastro[], int n);
void imprimirDados(Pessoa cadastro[], int n);
void ordenaRG(Pessoa cadastro[], int n);
int buscaBinaria(Pessoa cadastro[], int n, int chave);

int main () {
int n, res, chave;
Pessoa cadastro[100];

    printf("Numero de pessoas a serem cadastradas: ");
    scanf("%d", &n);

    armazenaDados(cadastro, n);

    printf("\nPESSOAS CADASTRADAS:\n");
    imprimirDados(cadastro, n);

    printf("\nDigite o numero de RG a ser buscado: ");
    scanf("%d", &chave);

    res = buscaBinaria(cadastro, n, chave);

    if(res == -1) {
        printf("\nRG nao foi encontrado!\n");
    } else {
        printf("\nRG foi encontrado!\n");
    }

    printf("\nPESSOAS CADASTRADAS:\n");
    imprimirDados(cadastro, n);

return 0;
}

void armazenaDados(Pessoa cadastro[], int n) {
    for(int i=0; i < n; i++) {
        printf("\nInsira %d pessoa:\n", i+1);
        getchar();
        printf("Nome: ");
        fgets(cadastro[i].nome, 80, stdin);
        cadastro[i].nome[strlen(cadastro[i].nome)-1] = '\0';
        printf("RG: ");
        scanf("%d", &cadastro[i].rg);
        printf("CPF: ");
        scanf("%d", &cadastro[i].cpf);
    }
}

void imprimirDados(Pessoa cadastro[], int n) {
    for(int i=0; i < n; i++) {
        printf("\nPESSOA %d:", i+1);
        printf("\nNome: %s", cadastro[i].nome);
        printf("\nRG: %d", cadastro[i].rg);
        printf("\nCPF: %d\n", cadastro[i].cpf);
    }
}

void ordenaRG(Pessoa cadastro[], int n) {
    Pessoa temp[1];
    for(int i=0; i < n; i++) {
        for(int j=i+1; j < n; j++) {
            if(cadastro[i].rg > cadastro[j].rg) {
                temp[0] = cadastro[i];
                cadastro[i] = cadastro[j];
                cadastro[j] = temp[0];
            }
        }
    }
}

int buscaBinaria(Pessoa cadastro[], int n, int chave) {
    int ini=0, fim=n-1, meio;

    ordenaRG(cadastro, n);

    while(ini <= fim) {
        meio = (ini+fim)/2;
        if(cadastro[meio].rg == chave) {
            return meio;
        } else if(cadastro[meio].rg > chave) {
            fim = meio-1;
        } else {
            ini = meio+1;
        }
    }
return -1;
}