#include <stdio.h>
#include <ctype.h>  //字符类型判断
#include <string.h> //字符串处理
#include <stdlib.h> //qsort,rand,bsearch
int main()
{
    struct multi
    {
        int a;
        int x;
        struct multi *next;
    };
    struct multi *firstq = NULL, *tailq, *q, *firstp = NULL, *tailp, *p, *firstw = NULL, *tailw, *w, *ff, *f, k = {0, 0, NULL};
    char ch = ' ';
    int i, j;
    for (i = 0; ch != '\n'; i++) //链表1
    {
        q = (struct multi *)malloc(sizeof(struct multi));
        scanf("%d%d%c", &q->a, &q->x, &ch);
        q->next = NULL;
        if (firstq == NULL)
        {
            firstq = tailq = q;
        }
        else
        {
            tailq->next = q;
            tailq = q;
        }
    }
    ch = ' ';
    for (j = 0; ch != '\n'; j++) //链表2
    {
        p = (struct multi *)malloc(sizeof(struct multi));
        scanf("%d%d%c", &p->a, &p->x, &ch);
        p->next = NULL;
        if (firstp == NULL)
        {
            firstp = tailp = p;
        }
        else
        {
            tailp->next = p;
            tailp = p;
        }
    }
    q = firstq;
    for (int k = 0; k < i; k++)
    {
        p = firstp;
        for (int l = 0; l < j; l++)
        {
            w = (struct multi *)malloc(sizeof(struct multi));
            w->a = q->a * p->a;
            w->x = q->x + p->x;
            w->next = NULL;
            if (firstw == NULL)
            {
                firstw = tailw = w;
            }
            else
            {
                tailw->next = w;
                tailw = w;
            }
            p = p->next;
        }
        q = q->next;
    }
    w = firstw;
    int n = i * j;
    for (int z = 0; w->next != NULL; z++)
    {
        f = w;
        ff = f->next;
        if (ff->next == NULL)
        {
            break;
        }
        for (int m = 0; ff != NULL; m++)
        {
            if (w->x == ff->x)
            {
                w->a += ff->a;
                f->next = ff->next;
                free(ff);
                n--;
                ff = f->next;
            }
            else
            {
                ff = ff->next;
                f = f->next;
            }
        }
        w = w->next;
    }
    ff = firstw;
    // do
    // {
    //     if (ff->x == w->x)
    //     {
    //         ff->a += w->a;
    //         f->next = NULL;
    //         free(w);
    //         n--;
    //         break;
    //     }
    //     else
    //     {
    //         ff = ff->next;
    //     }

    // } while (ff->next != w);
    for (int l = 0; l < n - 1; l++)
    {
        w = firstw;
        f = w->next;
        for (int m = 0; m < n - 1 - l; m++)
        {
            if (w->x < f->x)
            {
                k.a = w->a;
                w->a = f->a;
                f->a = k.a;
                k.x = w->x;
                w->x = f->x;
                f->x = k.x;
            }
            w = w->next;
            f = f->next;
        }
    }
    w = firstw;
    while (w->next != NULL)
    {
        printf("%d %d ", w->a, w->x);
        w = w->next;
    }
    printf("%d %d ", w->a, w->x);
    return 0;
}


