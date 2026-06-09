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
        i++; // @@ [The increment of 'i' happens after checking for newline, so the last valid term is never stored in A[i] because loop breaks before increment. This causes the first polynomial to miss its last term.]
    }
    while(scanf("%d%d",&B[j].x,&B[j].y)==2)
    {    
        if(getchar()=='\n')
        {
            break;
        }
        j++; // @@ [Same issue as above: 'j' is incremented after the newline check, so the last term of the second polynomial is not properly indexed and may be skipped.]
    }
    int m=0,n=0,k=0;
    while(m<=i) // @@ [Loop condition should be 'm < i' because 'i' is the count of terms (0-based index up to i-1). Using '<=' accesses A[i], which is uninitialized or contains garbage.]
    {
        n=0;
        while(n<=j) // @@ [Same issue: should be 'n < j', not '<=j', to avoid accessing B[j] which is out of valid input range.]
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
    while(l<=k) // @@ [Loop condition should be 'l < k - 1' or similar; accessing C[l+1] when l == k leads to out-of-bounds read (C[k] is beyond valid indices 0..k-1).]
    {
        if(C[l].y!=C[l+1].y) // @@ [When l == k, C[l+1] is out of bounds. Also, this logic fails to handle the last term correctly even if bounds were fixed, because it only prints when exponents differ, but the last term has no next term to compare with.]
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