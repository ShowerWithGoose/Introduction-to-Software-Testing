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
        i++; @@ // The increment of i happens after checking for newline, so the last term is not counted properly. i should be incremented before the check or handled differently.
    }
    while(scanf("%d%d",&B[j].x,&B[j].y)==2)
    {    
        if(getchar()=='\n')
        {
            break;
        }
        j++; @@ // Same issue as above: j is not incremented for the last term before breaking, leading to missing the last term of the second polynomial.
    }
    int m=0,n=0,k=0;
    while(m<=i) @@ // Loop condition should be m < i (or m <= i only if i was correctly set to the last valid index). Because of earlier bug, i is one less than actual count, but even then, using <= includes an uninitialized element.
    {
        n=0;
        while(n<=j) @@ // Same issue: n <= j accesses B[j] which may be uninitialized due to input reading bug.
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
    while(l<=k) @@ // Loop goes up to l == k, but C[k] is out of bounds (valid indices are 0 to k-1). Also, C[l+1] when l == k causes out-of-bounds access.
    {
        if(C[l].y!=C[l+1].y) @@ // Accesses C[l+1] when l == k, which is beyond the array (undefined behavior). Also fails to handle the last term correctly if it's unique.
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