#include <stdio.h>
#include <stdlib.h>

typedef struct poly
{
    int x, z;
    struct poly *prev, *next;
} poly;

void poly_print(poly *a)
{
    while (a != NULL)
    {
        printf("+%dx^%d ", a->x, a->z);
        // printf(" %X\n", a);
        a = a->next;
    }
}

poly *poly_srch(poly *a, int z)
{
    poly *t = a;
    while (t != NULL)
    {
        a = t;
        if (t->z == z)
        {
            return a;
        }
        t = a->next;
    }
    a->next = (poly *)malloc(sizeof(poly));
    a->next->prev = a;
    a = a->next;
    a->next = NULL;
    a->z = z;
    a->x = 0;
    return a;
}

void poly_mul(poly *ans, poly *a, poly b)
{
    while (a != NULL)
    {
        (poly_srch(ans, (a->z + b.z))->x) += (a->x) * (b.x);
        a = a->next;
    }
}

int hhcmp(const void *a,const void *b){
    const int aa=*((const int*)a+1);
    const int bb=*((const int*)b+1);
    return bb-aa;
}

int main()
{
    poly *ha = NULL, *ta, b = {0, 0, NULL, NULL}, *ans, *tl;
    ans = (poly *)malloc(sizeof(poly));
    ans->next = ans->prev = NULL;
    ans->x = ans->z = 0;
    int x, z=1;
    char kongge;
    do
    {
        scanf("%d%d", &x, &z);
        kongge=getchar();
        if (ha == NULL)
        {
            ha = (poly *)malloc(sizeof(poly));
            ha->next = ha->prev = NULL;
            ha->x = x;
            ha->z = z;
            ta = ha;
        }
        else
        {
            ta->next = (poly *)malloc(sizeof(poly));
            ta->next->prev = ta;
            ta = ta->next;
            ta->next = NULL;
            ta->x = x;
            ta->z = z;
        }
    } while (kongge!=10);
    do
    {
        scanf("%d%d", &x, &z);
        kongge=getchar();
        b.x = x;
        b.z = z;
        poly_mul(ans, ha, b);
    } while (kongge!=10);
    //链表排序老出bug，开始偷鸡
    int (*ssort)[2],k;tl=ans;
    for (k = 0; tl!=NULL; k++)
    {
        tl=tl->next;
    }
    ssort=(int (*)[2])malloc(k*sizeof(*ssort));
    tl=ans;
    for (int i = 0; i < k; i++)
    {
        *(*(ssort+i))=tl->x;
        *(*(ssort+i)+1)=tl->z;
        tl=tl->next;
    }
    
    qsort(*(ssort),k,sizeof(*ssort),hhcmp);
    for (int i = 0; i < k; i++)
    {
        if(*(*(ssort+i))==0){
            continue;
        }
        printf("%d %d ",*(*(ssort+i)),*(*(ssort+i)+1));
    }
    //poly_print(ans);
}

