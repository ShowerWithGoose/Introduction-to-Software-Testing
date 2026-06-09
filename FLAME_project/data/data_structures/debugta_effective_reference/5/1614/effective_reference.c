#include <stdio.h>
typedef struct
{
    int coef;
    int expn;
} poly;
void read_in(poly term[], int *h)
{
    while (1)
    {
        scanf("%d%d", &term[*h].coef, &term[*h].expn);
        (*h)++;
        if (getchar() == '\n')
            break;
    }
}
void sort(poly a[], int n)
{
    poly temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j].expn > a[j + 1].expn)
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
void multiple(poly term1[], poly term2[], int n1, int n2, poly term[])
{
    int h = 0;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            term[h].coef = term1[i].coef * term2[j].coef;
            term[h].expn = term1[i].expn + term2[j].expn;
            h++;
        }
    }
    for (int i = 0; i <= h; i++)
    {
        for (int j = i + 1; j <= h; j++)
        {
            if (term[i].expn == term[j].expn)
            {
                term[i].coef = term[i].coef + term[j].coef;
                term[j].coef = 0;
            }
        }
    }
}
void put_out(int n, poly term[])
{
    for (int i = n; i >= 0; i--)
    {
        if (term[i].coef != 0)
            printf("%d %d ", term[i].coef, term[i].expn);
    }
}
int main()
{
    poly term1[2000], term2[2000], term3[2000];
    int n = 0, m = 0;
    for (int i = 0; i < 2000; i++)
    {
        term1[i].coef = 0;
        term2[i].coef = 0;
        term1[i].expn = 0;
        term2[i].expn = 0;
        term3[i].coef = 0;
        term3[i].expn = 0;
    }
    read_in(term1, &n);
    read_in(term2, &m);
    sort(term1, n);
    sort(term2, m);
    multiple(term1, term2, n, m, term3);
    sort(term3, n * m);
    put_out(m * n, term3);
}


