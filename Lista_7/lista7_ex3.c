/* Exercício 3:
Suponha que criamos uma estrutura para armazenar dados de pessoas e uma outra estrutura para armazenar dados de várias pessoas como uma base de dados.
typedef struct Pessoa{
    int rg;
    int cpf;
    char nome[80];
}Pessoa;

typedef struct Base{
    int armazenado; //Deve sempre corresponder ao número de pessoas na base
    Pessoa pessoas[100];
}Base;

Crie funções para cada uma das operações abaixo:
• Cria base: esta função devolve uma Base onde o campo armazenado é inicializado com 0.
Base cria_base();

• Inclui Pessoa: esta função recebe como parâmetro um dado do tipo Pessoa e o inclui na base (também passada por parâmetro) caso já não exista na base uma pessoa com o mesmo RG. 
A função devolve 1 caso a inclusão tenha ocorrido, devolve 0 caso a Base esteja cheia e devolve -1 caso já exista uma pessoa com o RG informado.
int insere_base(Pessoa p, Base base);

• Exclui Pessoa: esta função recebe como parâmetro um dado do tipo int representando o RG de uma pessoa e o exclui da base caso esteja presente. 
A função devolve 1 caso a exclusão tenha ocorrido, e devolve 0 caso não exista uma pessoa com o RG informado.
int remove_base(int rg, Base base);
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoa{
    int rg;
    int cpf;
    char nome[80];
}Pessoa;

typedef struct Base{
    int armazenado; ///Deve sempre corresponder ao número de pessoas na base
    Pessoa pessoas[100];
}Base;

void cria_base(Base *base);///Modificado;
void mostra_base(Base *base);
void ordena_base(Base *base);
int busca_base(Base *base, int chave);
int insere_base(Pessoa p, Base *base);///Modificado;
int remove_base(int chave, Base *base);///Modificado;

int main () {
int chave, r;
char op, valor;
Pessoa p;
Base *base = malloc(sizeof(Base));

cria_base(base);

do {
    printf("\n#########################################\n");
    printf("########### Sistema de Cadastro ##########\n");
    printf("#########################################\n");
    printf("\nLista de Opcoes:\n");
    printf("a. Inserir Pessoa na Base\n");
    printf("b. Exibir a Base\n");
    printf("c. Buscar na Base\n");
    printf("d. Remover Pessoa da Base\n");
    printf("\nSelecione uma opcao: ");
    scanf(" %c", &valor);

    if(valor == 'a') {
        getchar();
        printf("Nome: ");
        fgets(p.nome, 80, stdin);
        p.nome[strlen(p.nome)-1] = '\0';
        printf("Digite o RG: ");
        scanf("%d", &p.rg);
        printf("Digite o CPF: ");
        scanf("%d", &p.cpf);

        r = insere_base(p, base);
        if(r == 0) {
            printf("\nErro: A base esta cheia!\n");
        } else if(r == -1) {
            printf("\nErro: Pessoa ja cadastrada na base!\n");
        } else {
            printf("\nPessoa foi cadastrada na base!\n");
        }
    } else if (valor == 'b') {
        printf("\n|----- Cadastrados na Base -----|\n");
        mostra_base(base);
    } else if (valor == 'c') {
        printf("\nInsira o RG para buscar Pessoa: ");
        scanf("%d", &chave);
        r = busca_base(base, chave);
        if(r == -1) {
            printf("\nPessoa inexistente na base!\n");
        } else {
            printf("\nPessoa encontrada na base!\n");
        }
    } else if (valor == 'd') {
        printf("\nInsira o RG para remover Pessoa: ");
        scanf("%d", &chave);
        r = remove_base(chave, base);
        if(r == 0) {
            printf("\nPessoa inexistente na base!\n");
        } else {
            printf("\nPessoa excluida na base!\n");
        }
    } else {
        printf("\nErro: Opcao inexistente!\n");
    }

printf("\nDeseja continuar no sistema (s/n): ");
scanf(" %c", &op);

///Limpadores de tela;
printf("\e[1;1H\e[2J");
system("cls");

} while(op == 's');

free(base);
return 0;
}

void cria_base(Base *base) {
    base->armazenado = 0;
}

void mostra_base(Base *base) {
    for(int i=0; i < base->armazenado; i++) {
        printf("\nPESSOA %d:", i+1);
        printf("\nNome: %s", base->pessoas[i].nome);
        printf("\nRG: %d", base->pessoas[i].rg);
        printf("\nCPF: %d\n", base->pessoas[i].cpf);
    }
}

void ordena_base(Base *base) {
    Pessoa temp[1];
    for(int i=0; i < base->armazenado; i++) {
        for(int j=i+1; j < base->armazenado; j++) {
            if(base->pessoas[i].rg > base->pessoas[j].rg) {
                temp[0] = base->pessoas[i];
                base->pessoas[i] = base->pessoas[j];
                base->pessoas[j] = temp[0];
            }
        }
    }
}

int busca_base(Base *base, int chave) {
    int ini=0, fim=base->armazenado-1, meio;

    ordena_base(base);

    while(ini <= fim) {
        meio = (ini+fim)/2;
        if(base->pessoas[meio].rg == chave) {
            return meio;
        } else if(base->pessoas[meio].rg > chave) {
            fim = meio-1;
        } else {
            ini = meio+1;
        }
    }
return -1;///Pessoa inexistente na Base;
}

int insere_base(Pessoa p, Base *base) {
    int r;
    r = busca_base(base, p.rg);

    if(base->armazenado == 100) {
        return 0;
    } else if(r == -1) {
        base->pessoas[base->armazenado] = p;
        base->armazenado++;
        return 1;
    } else {
        return -1;
    }
}

int remove_base(int chave, Base *base) {
    int r;
    r = busca_base(base, chave);

    if(r == -1) {
        return 0;
    } else {
        for(int i = r; i < base->armazenado-1; i++) {
            base->pessoas[i] = base->pessoas[i+1];
        }
        base->armazenado--;
        return 1;
    }
}