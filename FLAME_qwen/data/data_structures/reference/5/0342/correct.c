/*
 * @Author:
 * @Date: 2022-03-24 19:41:20
 * @LastEditors:
 * @LastEditTime: 2022-03-24 20:03:14
 * @FilePath: multi.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXN 100010

typedef struct Node
{
    int p,a;
    struct Node *next;
}Node;

Node *A,*B,*pa,*pb;
int tot=0;

Node C[MAXN];

int cmp(const void *x, const void *y)
{
    Node *X = (Node *)x;
    Node *Y = (Node *)y;
    if(X->p < Y->p) return 1;
    if(X->p > Y->p) return -1;
    return 0;
}

int main()
{
    A = (Node *)malloc(sizeof(Node));
    B = (Node *)malloc(sizeof(Node));
    int pi,ai;
    pa = A, pb = B;
    do
    {
        scanf("%d%d",&ai,&pi);
        pa->a = ai; pa->p = pi;
        if(getchar() == '\n') break;
        pa->next = (Node *)malloc(sizeof(Node));
        pa = pa->next;
    } while (pi);
    pa->next = NULL;
    do
    {
        scanf("%d%d",&ai,&pi);
        pb->a = ai; pb->p = pi;
        if(getchar() == '\n') break;
        pb->next = (Node *)malloc(sizeof(Node));
        pb = pb->next;
    } while (pi);
    pb->next = NULL;
    for(pa=A;pa != NULL;pa = pa->next)
        for(pb=B;pb != NULL;pb = pb->next)
        {
            Node ret;
            ret.a = pa->a * pb->a;
            ret.p = pa->p + pb->p;
            C[++tot] = ret;
        }
    qsort(C+1,tot,sizeof(C[0]),cmp);
    pi = -1;
    for(int i=1;i<=tot;++i)
    {
        if(C[i].p != pi)
        {
            if(pi >= 0)
                printf("%d %d ",ai,pi);
            ai = C[i].a;
            pi = C[i].p;
        }
        else
            ai += C[i].a;
    }
    printf("%d %d",ai,pi);
    return 0;
}
