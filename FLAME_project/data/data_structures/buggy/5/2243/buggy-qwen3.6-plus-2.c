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
    if(a->n<b->n)
    return 1;
    else
    return -1;
}
int main()
{    int i=0,j=0,l1,l2,count=0;
    scanf("%d %d",&items1[i].a ,&items1[i].n);
    while(getchar()!='\n')
    {i++;
    scanf("%d %d",&items1[i].a ,&items1[i].n);
    }
    l1=i; // @@ The variable l1 stores the index of the last element, but the loop condition below uses <= l1, which implies l1 should be the count. Since arrays are 0-indexed, if i is the last index, the count is i+1. Using l1=i here leads to off-by-one errors in loop bounds.
    i=0;
    scanf("%d %d",&items2[i].a ,&items2[i].n);
    while(getchar()!='\n')
    {i++;
    scanf("%d %d",&items2[i].a ,&items2[i].n);
    }
    l2=i; // @@ Same error as above. l2 stores the last index, not the count.
    for(i=0;i<=l1;i++) // @@ Because l1 is the last index (not count), this loop runs from 0 to last_index inclusive, which is correct for iterating elements IF l1 was correctly identified as last index. However, combined with the previous logic, if input has 1 term, i=0, loop runs once. If input has 2 terms, i becomes 1, l1=1, loop runs for i=0,1. This part actually iterates correctly over the stored items based on the previous parsing logic.
    {for(j=0;j<=l2;j++) // @@ Similar to above, iterates correctly over items2 based on the parsing logic.
    {
    items3[i*(l2+1)+j].a=(items1[i].a)*(items2[j].a);
    items3[i*(l2+1)+j].n=(items1[i].n)+(items2[j].n);
    count++;
    }
    }
    qsort(items3,count,sizeof(struct xiang),cmp);
    for(i=0;i<count;i++) // @@ The code simply prints all multiplied terms without merging terms with the same exponent. Polynomial multiplication requires combining like terms (summing coefficients of terms with the same exponent). This is the primary reason for the Wrong Answer.
    printf("%d %d ",items3[i].a,items3[i].n);
    
    

return 0;
}