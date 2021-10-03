/* Exercício 7:
Escreva uma função que recebe como parâmetro um vetor de inteiros, um inteiro n que indica o tamanho do vetor e dois ponteiros para inteiro f1 e f2. 
A função deve devolver no endereço apontado por f1 o elemento do vetor de menor frequência (que possui o menor número de ocorrências) e no endereço apontado por f2 o elemento do vetor de maior frequência.
O protótipo da função deve ser:
void frequencias(int v[], int n, int *f1, int *f2);
*/
#include <stdio.h>

void frequencias(int v[], int n, int *f1, int *f2);

int main() {
int n, i, v[100], f1, f2;

printf("Quantos numeros serao inseridos no vetor: ");
scanf("%d", &n);

for(i=0; i < n; i++) {
    printf("\nInsira o %d elemento: ", i+1);
    scanf("%d", &v[i]);
}

frequencias(v, n, &f1, &f2);

printf("\nf1: %d; f2: %d\n", f1, f2);

return 0;
}

void frequencias(int v[], int n, int *f1, int *f2) {
int i, j, c=0, cMe, cMa, nMe, nMa;

    for(i=0; i < n; i++) {
        for(j=0; j < n; j++) {
            if(v[i] == v[j]) {
                c++;///Contagem do elemento atual;
            }
        }
        if(i == 0) {///Primeiro elemento inserido como padrao (Maior e Menor);
            cMe = c;
            nMe = v[0];
            cMa = c;
            nMa = v[0];
        } else {///Verifica o Menor e Maior;
            if(c > cMa) {
                nMa = v[i];
                cMa = c;
            }
            if(c < cMe) {
                nMe = v[i];
                cMe = c;
            }
        }
        c=0;
    }
    *f1 = nMe;///Elemento com menor frequencia;
    *f2 = nMa;///Elemento com maior frequencia;
}
