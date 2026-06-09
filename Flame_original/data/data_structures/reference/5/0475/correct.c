#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
struct multinomial
{
    int a;
    int n;
    struct multinomial *next;
    struct multinomial *front;
};
int read(struct multinomial *);
int main()
{
    struct multinomial *x, *y, *z, *xfirst, *yfirst, *zfirst, *p, *q;
    int i, j, k, nx = 0, ny = 0, nz = 0, flag, f;
    char m;
    p = (struct multinomial *)malloc(sizeof(struct multinomial)); //读取
    p->next = NULL;
    p->front = NULL;
    f = read(p);
    xfirst = x = p;
    nx++;
    /*p = (struct multinomial *)malloc(sizeof(struct multinomial));
    p->next = NULL;
    p->front = x;*/
    while (f != 1)
    {
        p = (struct multinomial *)malloc(sizeof(struct multinomial));
        p->next = NULL;
        p->front = x;
        f = read(p);
        x->next = p;
        x = p;
        nx++;
    }

    /*f = read(p);
    p->front = NULL;
    yfirst = y = p;
    ny++;*/
    p = (struct multinomial *)malloc(sizeof(struct multinomial));
    p->next = NULL;
    p->front = NULL;
    f = read(p);
    yfirst = y = p;
    ny++;
    while (f != 1)
    {
        p = (struct multinomial *)malloc(sizeof(struct multinomial));
        p->next = NULL;
        p->front = y;
        f = read(p);
        y->next = p;
        y = p;
        ny++;
    }
    //运算
    x = xfirst;
    y = yfirst;
    for (i = 0; i < nx; i++)
    {
        y = yfirst;
        for (j = 0; j < ny; j++)
        {
            flag = 0;
            z = zfirst;
            for (k = 0; k < nz; k++)
            {
                if (z->n == x->n + y->n)
                {
                    flag = 1;
                    break;
                }
                else if (z->n < x->n + y->n)
                {
                    flag = 2;
                    break;
                }
                if (k + 1 < nz)
                {
                    z = z->next;
                }
            }
            if (flag == 1)
            {
                z->a = z->a + x->a * y->a;
            }
            else
            {
                nz++;
                p = (struct multinomial *)malloc(sizeof(struct multinomial));
                p->a = x->a * y->a;
                p->n = x->n + y->n;
                // p->next = NULL;
                if (i == 0 && j == 0)
                {
                    p->next = NULL;
                    p->front = NULL;
                    zfirst = p;
                }
                else if (flag == 0)
                {
                    p->next = NULL;
                    p->front = z;
                    z->next = p;
                }
                else if (flag == 2)
                {
                    // p->next = z->next;
                    p->front = z->front;
                    z->front->next = p;
                    z->front = p;
                    p->next = z;
                }
            }
            y = y->next;
        }
        x = x->next;
    }
    z = zfirst;
    for (i = 0; i < nz; i++)
    {
        printf("%d %d ", z->a, z->n);
        z = z->next;
    }
    return 0;
}
int read(struct multinomial *p)
{
    char a1[30] = {'\0'}, n1[30] = {"\0"};
    char r;
    int i = 0;
    r = getchar();

    while (isdigit(r) != 0)
    {
        a1[i] = r;
        r = getchar();
        i++;
    }
    p->a = atoi(a1);
    i = 0;
    r = getchar();
    while (isdigit(r) != 0)
    {
        n1[i] = r;
        r = getchar();
        i++;
    }
    p->n = atoi(n1);
    if (r == '\n')
    {
        return 1;
    }
    return 0;
}
