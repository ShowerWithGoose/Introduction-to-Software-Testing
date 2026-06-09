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
        i++; // @@ [The increment happens after checking for newline, so the last term read before '\n' is not counted in i. This causes the first polynomial to miss its last term in multiplication.]
    }
    while(scanf("%d%d",&B[j].x,&B[j].y)==2)
    {    
        if(getchar()=='\n')
        {
            break;
        }
        j++; // @@ [Same issue as above: the last term of the second polynomial is not included because j is incremented only when the next character is not '\n'.]
    }
    int m=0,n=0,k=0;
    while(m<=i) // @@ [Loop condition should be m < i (or m <= i-1), because i points to the last valid index + 1 due to premature break logic. As written, it accesses A[i] which was never properly filled.]
    {
        n=0;
        while(n<=j) // @@ [Same issue: should be n < j or n <= j-1 for the same reason.]
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
    while(l<=k) // @@ [Loop goes up to l == k, but C[k] is out of bounds since valid indices are 0 to k-1. Also, C[l+1] when l == k-1 accesses C[k], which is uninitialized.]
    {
        if(C[l].y!=C[l+1].y) // @@ [Accesses C[l+1] without ensuring l+1 < k, leading to undefined behavior and missing the last term if it doesn't combine with a next term.]
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