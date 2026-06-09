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
    while(m<=i) // @@ The loop condition should be m <= i, but since i was not incremented after the last valid read, it points to the last valid index. However, the initialization of i and j starts at 0 and increments only if not breaking. If the input has one term, i remains 0. The loop runs for m=0. This part is actually logically okay for 0-indexed arrays IF i and j represent the last valid index. Let's trace: Input "20 500000 10 0". First read A[0]. getchar is space. i becomes 1. Second read A[1]. getchar is newline. Break. So i=1. Terms are A[0] and A[1]. Loop m<=i means m=0,1. Correct.
    {
        n=0;
        while(n<=j)
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
    while(l<k) // @@ The original code had l<=k which causes out-of-bounds access on C[l+1] when l==k-1 or l==k. It should iterate through all k elements. Also, the logic inside needs to handle the last element correctly.
    {
        if(l == k - 1 || C[l].y != C[l+1].y) // @@ Original code didn't check bounds for C[l+1] and didn't print the last accumulated term correctly if it wasn't followed by a different exponent. We need to print if it's the last element OR the next exponent is different.
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