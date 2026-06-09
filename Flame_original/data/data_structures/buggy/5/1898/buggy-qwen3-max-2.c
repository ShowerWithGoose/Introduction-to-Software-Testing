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
        i++; @@ [The increment of 'i' happens after checking for newline, so the last valid term is not counted. This causes the loop to miss processing the final term because 'i' is not incremented when breaking on '\n'.]
    }
    while(scanf("%d%d",&B[j].x,&B[j].y)==2)
    {    
        if(getchar()=='\n')
        {
            break;
        }
        j++; @@ [Same issue as above: 'j' is not incremented for the last term before breaking, leading to undercounting the number of terms in polynomial B.]
    }
    int m=0,n=0,k=0;
    while(m<=i) @@ [Loop condition should be 'm < i' (not '<=') because 'i' is the count of terms, and indices go from 0 to i-1. Using '<=' accesses A[i], which is uninitialized or invalid.]
    {
        n=0;
        while(n<=j) @@ [Same error: should be 'n < j', not '<=j', to avoid accessing B[j] which is out of bounds.]
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
    while(l<=k) @@ [Loop condition should be 'l < k - 1' or similar; using '<=k' leads to accessing C[k] and C[k+1], which are out of bounds (valid indices are 0 to k-1).]
    {
        if(C[l].y!=C[l+1].y) @@ [Accesses C[l+1] when l == k, which is beyond the array boundary (C has size 10000 but only k elements are valid, indexed 0 to k-1).]
        {
            printf("%d %d ",C[l].x,C[l].y);
        }
        else 
        {
            C[l+1].x=C[l+1].x+C[l].x;
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