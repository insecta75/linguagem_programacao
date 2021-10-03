/* Exercício 3:
O que será impresso pelo programa abaixo?
*/
#include <stdio.h>

void f1(int v[], int n, int *a) {
    int i;
    *a = v[0];///a=14

    for(i=1; i < n; i++) {///n=7
        if(v[i]%2==0 && (*a) < v[i]) {
            *a = v[i];///a=20
        }
    }
}

int main() {
    int v[] ={14, 7, 8, 51, 13, 20, 2};
    int h = 15;

    f1(v, 7, &h);

    printf("h = %d\n", h);///h=20
}
