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
        i++; // @@ [The increment happens after checking for newline, so the last valid term is never counted. Should increment before or handle loop differently.]
    }
    while(scanf("%d%d",&B[j].x,&B[j].y)==2)
    {    
        if(getchar()=='\n')
        {
            break;
        }
        j++; // @@ [Same issue as above: last term not counted due to increment after break condition.]
    }
    int m=0,n=0,k=0;
    while(m<=i) // @@ [Loop condition should be m < i, not m <= i, because i points to the next unused index (off-by-one error).]
    {
        n=0;
        while(n<=j) // @@ [Same off-by-one error: should be n < j.]
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
    while(l<=k) // @@ [Loop condition should be l < k to avoid reading C[k], which is out of bounds (C has indices 0 to k-1).]
    {
        if(C[l].y!=C[l+1].y) // @@ [Accesses C[l+1] when l == k, which is out of bounds. Also fails to combine more than two terms with same exponent.]
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