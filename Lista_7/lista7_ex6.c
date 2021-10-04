/* Exercício 6:
O que será impresso pelo programa abaixo?
*/
#include <stdio.h>

struct T{
    int x;
    int y;
};

typedef struct T T;

void f1(T *a);
void f2(int *b);

int main() {
T a, b, *c, *d;
c = &a;

    a.x = 2;///c.x=2
    a.y = 4;///c.y=4
    b.x = 2;
    b.y = 2;
    d = c;///d.x=2, d.y=4

    f1(d);///d.x=4, d.y=8

    b = *d;///b.x=4, b.y=8

    printf("x: %d --- y: %d\n",b.x,b.y);
}

void f1(T *a){
    f2(&(a->x));
    f2(&(a->y));
}

void f2(int *b){
    *b = 2*(*b);
}
