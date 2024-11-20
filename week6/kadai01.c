#include <stdio.h>
#include <stdlib.h>

typedef struct monomial
{
    int c;
    int n;
} Monomial;

Monomial *construct_monomial(int c, int n)
{
    Monomial *m = (Monomial *)malloc(sizeof(Monomial));
    m->c = c;
    m->n = n;
    return m;
}
void diff_monomial(Monomial *m)
{
    m->c *= m->n;
    --m->n;
}
void print_monomial(Monomial *m)
{
    printf("%d*x^%d\n", m->c, m->n);
}
int main()
{
    Monomial *m1;
    m1 = construct_monomial(-4, 10);
    print_monomial(m1);
    diff_monomial(m1);
    print_monomial(m1);
    free(m1);
    return 0;
}