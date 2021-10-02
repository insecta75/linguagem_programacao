/* Exercício 2:
Escreva uma função que recebe dois números inteiros positivos a e b por parâmetro e determina se eles são amigos ou não, 
devolvendo 1 caso sejam amigos, e 0 caso contrário.
Dois números são amigos se cada número é igual à soma dos divisores próprios do outro (os divisores próprios de um número m são os divisores estritamente menores que m). 
Por exemplo, os divisores próprios de 220 são 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 e 110, cuja soma é 284; 
e os divisores próprios de 284 são 1, 2, 4, 71 e 142, cuja soma é 220. 
Logo, 220 e 284 são números amigos. 
O protótipo da função deve ser:
int amigos(int a, int b);
*/
#include <stdio.h>

int amigos(int a, int b);

int main() {
int a, b, r;

printf("Digite os valores de a e b: ");
scanf("%d %d", &a, &b);

r = amigos(a, b);

if(r == 1) {
    printf("\nOs numeros %d e %d sao amigos!\n", a, b);
} else {
    printf("\nEsse numeros nao sao amigos!\n");
}

return 0;
}

int amigos(int a, int b) {
    int sa=0, sb=0, i;

    for(i=1; i < a; i++) {
        if(a%i == 0) {
            sa = sa + i;
        }
    }
    for(i=1; i < b; i++) {
        if(b%i == 0) {
            sb = sb + i;
        }
    }
    if(sa == b && sb == a) {
        return 1;
    } else {
        return 0;
    }
}