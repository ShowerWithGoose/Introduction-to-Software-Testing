#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct num{
    int x;
    int y;
}num; 
int cmp(const void *a, const void *b);
int main()
{
    struct num A[100];
    struct num B[100];
    struct num C[10000];
    int i=0,j=0;
    while(scanf("%d%d",&A[i].x,&A[i].y)==2)
    {
        if(getchar()=='\n')
        {
            break;
        }
        i++;
    }
    while(scanf("%d%d",&B[j].x,&B[j].y)==2)
    {    
        if(getchar()=='\n')
        {
            break;
        }
        j++;
    }
    int m=0,n=0,k=0;
    while(m<=i) // @@ Error: The loop condition should be m < i (not m <= i) because i is the index of the last element, not the count. This causes an extra iteration with uninitialized data.
    {
        n=0;
        while(n<=j) // @@ Error: The loop condition should be n < j (not n <= j) because j is the index of the last element, not the count. This causes an extra iteration with uninitialized data.
        {
            C[k].x=A[m].x*B[n].x;
            C[k].y=A[m].y+B[n].y;
            k++;
            n++;
        }
        m++;
    }
    qsort(C,k,sizeof(num),cmp);
    int l=0;
    while(l<=k) // @@ Error: The loop condition should be l < k (not l <= k) because k is the number of elements, and array indices go from 0 to k-1. This causes an out-of-bounds access when l equals k.
    {
        if(C[l].y!=C[l+1].y) // @@ Error: When l equals k-1, C[l+1] accesses C[k], which is out of bounds (since valid indices are 0 to k-1). This causes undefined behavior.
        {
            printf("%d %d ",C[l].x,C[l].y);
        }
        else 
        {
            C[l+1].x=C[l+1].x+C[l].x; // @@ Error: Same out-of-bounds issue as above when l equals k-1.
        }
        l++;
    }

    return 0;
}
int cmp(const void *a, const void *b)
{
    num *a1=(num *)a;
    num *b1=(num *)b;
    return(b1->y - a1->y);
}