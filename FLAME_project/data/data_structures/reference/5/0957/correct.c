#include <stdio.h>
typedef struct
{
    int coef;
    int expn;
} poly;
void read_in(poly term[], int *count)
{
    while (1)
    {
        scanf("%d%d", &term[*count].coef, &term[*count].expn);
        (*count)++;
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
    int count = 0;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            term[count].coef = term1[i].coef * term2[j].coef;
            term[count].expn = term1[i].expn + term2[j].expn;
            count++;
        }
    }
    for (int i = 0; i <= count; i++)
    {
        for (int j = i + 1; j <= count; j++)
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
    poly term1[2000], term2[2000], term_res[2000];
    int count1 = 0, count2 = 0;
    for (int i = 0; i < 2000; i++)
    {
        term1[i].coef = 0;
        term2[i].coef = 0;
        term1[i].expn = 0;
        term2[i].expn = 0;
        term_res[i].coef = 0;
        term_res[i].expn = 0;
    }
    read_in(term1, &count1);
    read_in(term2, &count2);
    sort(term1, count1);
    sort(term2, count2);
    multiple(term1, term2, count1, count2, term_res);
    sort(term_res, count1 * count2);
    put_out(count2 * count1, term_res);
}


