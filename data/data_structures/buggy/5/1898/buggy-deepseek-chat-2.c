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
    while(m<=i) // @@ Error: Loop condition should be m < i (not <=) because i is the index of the last element, and the loop should iterate over all elements from 0 to i-1. Using <= causes out-of-bounds access when m equals i.
    {
        n=0;
        while(n<=j) // @@ Error: Same issue as above; should be n < j to avoid accessing B[j] which is uninitialized or out of bounds.
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
    while(l<=k) // @@ Error: Loop condition should be l < k (not <=) because k is the count of elements, and valid indices are 0 to k-1. Using <= causes out-of-bounds access when l equals k.
    {
        if(C[l].y!=C[l+1].y) // @@ Error: When l equals k-1, C[l+1] accesses C[k] which is out of bounds. Also, the logic for combining like terms is incorrect; it should combine all consecutive terms with the same exponent, not just pairs.
        {
            printf("%d %d ",C[l].x,C[l].y);
        }
        else 
        {
            C[l+1].x=C[l+1].x+C[l].x; // @@ Error: This overwrites the next term's coefficient without outputting the current term, and does not handle cases where more than two terms have the same exponent.
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