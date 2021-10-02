/* Exercício 1:
Considere o código em C abaixo (assuma que no lugar de D seja usado o último dígito de seu RA):

(a) Determine quais são as variáveis locais e globais deste programa. Para cada variável local identifique a que função esta pertence.
(b) (1.5 pontos) Mostre o que será impresso na tela do computador quando for executado este programa (lembre-se de usar o último dígito de seu RA no lugar de D).
*/
#include <stdio.h>

int fun1(int a, int b);
int j = 1;///Variável Global;

int main() {
int i, j;///Variáveis Locais de main();
///a = D (no exemplo foi colocado como 1)
int a = 1;///Variável Local de main();

    if(a % 2 == 0) {
        a = 2;
    } else {
        a = 3;
    }
    ///a = 3;
    printf("%d\n", fun1(2,4));///fun1 = 17;

    for(i = 1; i < 3; i++){
        for(j= 1; j < 3; j++){
            printf("%d\n", fun1(a, i+j));///fun1 = 10, 28, 28, 82;
        }
    }
}

int fun1(int a, int b) {///a=2, b=4; a=3, b=2; a=3, b=3; a=3, b=3; a=3, b=4;
int i, p = 1;///Variáveis Locais de fun1();

    for(i = 1; i <= b; i++) {
        p = p * a;
    }
    ///p = 16, 9, 27, 27, 81;
    return p + j;///j=1
}