/* Exercício 7:
Determine o que a seguinte definição recursiva para uma função f calcula. 
A definição da função f é dada abaixo:
• Se n == 0 retorne 0.
• Se n > 0 retorne n + f (n - 1).
*/
#include <stdio.h>
#include <stdlib.h>

int f(int n);

int main () {
int n=5;

printf("Resultado: %d\n", f(n));

return 0;
}

int f(int n) {///Soma os valores (ex: 0+1+2+3+4+5=15);
    if(n == 0) {
        return 0;
    } else {
        return n + f(n-1);
    }
}