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
        i++; // @@ [The increment happens after checking for newline, so the last valid term is not counted because loop breaks before incrementing i. This causes m<=i to access one extra uninitialized element.]
    }
    while(scanf("%d%d",&B[j].x,&B[j].y)==2)
    {    
        if(getchar()=='\n')
        {
            break;
        }
        j++; // @@ [Same issue as above: j is not incremented for the last term, leading to off-by-one error in multiplication loop.]
    }
    int m=0,n=0,k=0;
    while(m<=i) // @@ [Should be m < i, because i points to the next unused index, not the last valid index. Using <= accesses A[i], which is uninitialized.]
    {
        n=0;
        while(n<=j) // @@ [Same issue: should be n < j, not <= j.]
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
    while(l<=k) // @@ [Loop condition should be l < k, not <= k. Accessing C[l+1] when l == k leads to out-of-bounds read.]
    {
        if(C[l].y!=C[l+1].y) // @@ [When l == k-1, C[l+1] is out of bounds. Also, this logic fails to combine more than two terms with same exponent.]
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