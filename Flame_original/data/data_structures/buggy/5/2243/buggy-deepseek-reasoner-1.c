#include<stdio.h>
#include<stdlib.h>
struct xiang{
    int a;
    int n;
};
typedef struct xiang item;
item items1[1000],items2[1000],items3[1000];    
int cmp(const void *p1,const void *p2)
{    struct xiang *a=(struct xiang *)p1;
    struct xiang *b=(struct xiang *)p2;
    if(a->n<b->n) // @@ [Comparison function does not return 0 for equal exponents, violating strict weak ordering and causing undefined behavior in qsort.]
    return 1;
    else
    return -1; // @@ [Should return 0 when exponents are equal to maintain a valid comparator.]
}
int main()
{    int i=0,j=0,l1,l2,count=0;
    scanf("%d %d",&items1[i].a ,&items1[i].n);
    while(getchar()!='\n')
    {i++;
    scanf("%d %d",&items1[i].a ,&items1[i].n);
    }
    l1=i;
    i=0;
    scanf("%d %d",&items2[i].a ,&items2[i].n);
    while(getchar()!='\n')
    {i++;
    scanf("%d %d",&items2[i].a ,&items2[i].n);
    }
    l2=i;
    for(i=0;i<=l1;i++)
    {for(j=0;j<=l2;j++)
    {
    items3[i*(l2+1)+j].a=(items1[i].a)*(items2[j].a); // @@ [No combination of like terms; separate entries for same exponent will cause incorrect output.]
    items3[i*(l2+1)+j].n=(items1[i].n)+(items2[j].n); // @@ [Missing logic to add coefficients when exponents match; should traverse and combine.]
    count++;
    }
    }
    qsort(items3,count,sizeof(struct xiang),cmp);
    for(i=0;i<count;i++)
    printf("%d %d ",items3[i].a,items3[i].n);
    
    

return 0;
}