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
        i++; // @@ [The increment of 'i' happens after checking for newline, so the last valid term is never stored in A[i]; this causes the first polynomial to miss its last term.]
    }
    while(scanf("%d%d",&B[j].x,&B[j].y)==2)
    {    
        if(getchar()=='\n')
        {
            break;
        }
        j++; // @@ [Same issue as above: 'j' is incremented after breaking, so the last term of the second polynomial is not stored.]
    }
    int m=0,n=0,k=0;
    while(m<=i) // @@ [Loop condition should be 'm < i' because 'i' is one past the last valid index due to the earlier off-by-one error; using '<=' accesses uninitialized memory.]
    {
        n=0;
        while(n<=j) // @@ [Same issue: should be 'n < j'; accessing B[j] reads uninitialized data.]
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
    while(l<=k) // @@ [Loop condition should be 'l < k - 1' or similar; accessing C[l+1] when l == k leads to out-of-bounds read. Also, this merging logic fails to combine more than two terms with same exponent.]
    {
        if(C[l].y!=C[l+1].y)
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