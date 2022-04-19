/* Exercício 5:
Escreva uma função chamada primo que recebe como parâmetro um inteiro n e dois outros ponteiros para inteiros p1 e p2. 
A função deve retornar no endereço apontado por p1 o maior número primo que é menor do que n e deve retornar no endereço apontado por p2 o menor número primo que é maior do que m. 
O protótipo da função deve ser:
int primo(int n, int *p1, int *p2);
*/
#include <stdio.h>

int primo(int n, int *p1, int *p2);

int main() {
int n, p1, p2;

printf("Insira um valor inteiro n: ");
scanf("%d", &n);

primo(n, &p1, &p2);

printf("\nO maior número primo que é menor do que %d: %d\n", n, p1);
printf("\nO menor número primo que é maior do que %d: %d\n", n, p2);

return 0;
}

int primo(int n, int *p1, int *p2) {
    int i=n-1, j, c=0;

    while(i>1) {///Retorna o maior numero primo que e menor do que n;
        for(j=2; j < i; j++) {
            if(i%j == 1) {
                c++;
                if(c == i-2) {
                    *p1 = i;
                    i=0;
                    break;
                }
            }
            if(i%j == 0) {
                i--;
                c=0;
                break;
            }
        }
    }
    i=n+1;
    while(i>n) {///Retorna o menor numero primo que e maior do que n;
        for(j=2; j < i; j++) {
            if(i%j == 1) {
                c++;
                if(c == i-2) {
                    *p2 = i;
                    i=0;
                    break;
                }
            }
            if(i%j == 0) {
                i++;
                c=0;
                break;
            }
        }
    }
return 0;
}
