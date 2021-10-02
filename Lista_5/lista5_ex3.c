/* Exercício 3:
Escreva uma função que calcule o máximo divisor comum de dois números m e n passados por parâmetro. 
Você deve utilizar a seguinte regra do cálculo do mdc onde m ≥ n
mdc(m, n) = m se n = 0
mdc(m, n) = mdc(n, m%n) se n > 0
O protótipo da função deve ser:
int mdc(int m, int n);
*/
#include <stdio.h>

int mdc(int m, int n);

int main() {
int m, n;

printf("Digite os numeros m e n: ");
scanf("%d %d", &m, &n);

if (m >= n) {
    printf("\nO valor do mdc entre %d e %d: %d\n", m, n, mdc(m, n));
} else {
    printf("\nO valor de m nao pode ser menor que n!\n");
}

return 0;
}

int mdc(int m, int n) {
    if(n == 0) {
        return m;
    } else {
        return mdc(n, m%n);
    }
}