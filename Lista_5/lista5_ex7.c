/* Exercício 7:
Escreva uma função que recebe um vetor de números reais e o seu tamanho por parâmetro e devolve o desvio padrão dos números do vetor usando a seguinte fórmula:

(VIDE FÓRMULA NA LISTA)

onde n é o número de elementos. O protótipo da função deve ser:
double desvioPadrao(double v[], int tam);
*/
#include <stdio.h>

double desvioPadrao(double v[], int tam);

int main() {
int tam, i;
double v[1000];

printf("Quantos numero tera o vetor: ");
scanf("%d", &tam);

for(i=0; i < tam; i++) {
    printf("\nDigite o numero %d: ", i+1);
    scanf("%lf", &v[i]);
}

printf("\nO desvio padrao e: %.1lf\n", desvioPadrao(v, tam));

return 0;
}

double desvioPadrao(double v[], int tam) {
    double sumq=0, sum=0;

    for(int i=0; i < tam; i++) {///Soma dos valores
        sum = sum + v[i];
    }
    for(int i=0; i < tam; i++) {///Soma dos valores ao quadrado
        sumq = sumq + (v[i]*v[i]);
    }

return (sumq-((sum*sum)/tam))/(tam-1);
}
