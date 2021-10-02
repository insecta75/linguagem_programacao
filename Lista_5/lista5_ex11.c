/* Exercício 11:
Suponha que uma matriz binária represente ligações entre cidades, e que, se uma posição (i,j) possui o valor 1, 
então há uma estrada da cidade i para a cidade j. Seja o seguinte exemplo de matriz:

0 1 1
0 0 0
1 0 0

Neste caso, há caminhos disponíveis da cidade 0 para a 1 e 2, e da 2 para 0.
Para cada item abaixo escreva uma função que recebe como parâmetro uma matriz quadrada indicando as estradas entre as cidades, 
um inteiro n correspondendo as dimensões da matriz e um vetor resposta (que terá tamanho n). 
O protótipo da função deve ser:
void verifica(int mat[30][30], int n, int resposta[]);
• A função deve determinar as cidades com entrada e sem saída, indicando isto no vetor resposta, 
tal que resposta[i] recebe 1 caso a cidade i satisfaça esta propriedade e 0 caso contrário.
• A função deve determinar as cidades com saída mas sem entrada, indicando isto no vetor resposta, 
tal que resposta[i] recebe 1 caso a cidade i satisfaça esta propriedade e 0 caso contrário.
• A função deve determinar as cidades isoladas, indicando isto no vetor resposta, 
tal que resposta[i] recebe 1 caso a cidade i satisfaça esta propriedade e 0 caso contrário.
*/
#include <stdio.h>
#include <stdlib.h>

void verifica(int mat[30][30], int n, int resposta[30]);

int main() {
int mat[30][30], n, resposta[30];

printf("Digite o valor de n (numero de cidades) para a matriz n x n (de 0 a 30): ");
scanf("%d", &n);

printf("\nDigite se ha estradas indo para a cidade (0 ausente, 1 existente).\n");
///Na estrada, (e) representa entrada e (s) saida de cada cidade;
for (int s=0; s < n; s++) {
    for (int e=0; e < n; e++) {
    	if (s == e) {
    		mat[s][e] = 0;
    	} else {
	    	printf("\nSaida da cidade %d indo para Entrada da cidade %d: ", s, e);
            scanf("%d", &mat[s][e]);
    	}
    }
}

verifica(mat, n, resposta);
return 0;
}


void verifica(int mat[30][30], int n, int resposta[30]) {
    int vet_e[30], vet_s[30];

    for (int i=0; i < 30; i++) {
        vet_e[i] = 0;
        vet_s[i] = 0;
        resposta[i] = 0;
    }
    ///Cidades com entrada;
    for (int c=0; c < n; c++) {
        for (int s=0; s < n; s++) {
            for (int e=0; e < n; e++) {
                if (c == e && mat[s][e] == 1) {
                    vet_e[c] = 1;
                }
            }
        }
    }
    ///Cidades com saida;
    for (int c=0; c < n; c++) {
        for (int s=0; s < n; s++) {
            for (int e=0; e < n; e++) {
                if (c == s && mat[s][e] == 1) {
                    vet_s[c] = 1;
                }
            }
        }
    }
    ///Verifica quais cidades tem entrada e saida;
    for (int i=0; i < n; i++) {
        if (vet_e[i] == 1 && vet_s[i] == 1) {
            resposta[i] = 1;
        }
    }
    printf("\nCidades com entrada e saida: ");
    for (int i=0; i < n; i++) {
        if (resposta[i] == 1) {
            printf("%d ", i);
        }
    }
    for (int i=0; i < 30; i++) {///Zera vetor resposta;
        resposta[i] = 0;
    }
    ///Verifica quais cidades tem entrada, mas nao tem saida;
    for (int i=0; i < n; i++) {
        if (vet_e[i] == 1 && vet_s[i] == 0) {
            resposta[i] = 1;
        }
    }
    printf("\nCidades com entrada, mas sem saida: ");
    for (int i=0; i < n; i++) {
        if (resposta[i] == 1) {
            printf("%d ", i);
        }
    }
    for (int i=0; i < 30; i++) {///Zera vetor resposta;
        resposta[i] = 0;
    }
    ///Verifica quais cidades nao tem entrada, mas tem saida;
    for (int i=0; i < n; i++) {
        if (vet_e[i] == 0 && vet_s[i] == 1) {
            resposta[i] = 1;
        }
    }
    printf("\nCidades com saida, mas sem entrada: ");
    for (int i=0; i < n; i++) {
        if (resposta[i] == 1) {
            printf("%d ", i);
        }
    }
    for (int i=0; i < 30; i++) {///Zera vetor resposta;
        resposta[i] = 0;
    }
    ///Verifica quais cidades estao isoladas;
    for (int i=0; i < n; i++) {
        if (vet_e[i] == 0 && vet_s[i] == 0) {
            resposta[i] = 1;
        }
    }
    printf("\nCidades que estao isoladas: ");
    for (int i=0; i < n; i++) {
        if (resposta[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
}
/**No exemplo:
Entrada: j, Saida: i
Cidades: 0, 1, 2
Cidades com apenas entrada: 1
Cidades com apenas saida: nulo
Cidades com entrada e saida: 0 e 2
Cidades sem entrada e sem saida: nulo
valor 1 para ok e valor 0 para nulo
**/