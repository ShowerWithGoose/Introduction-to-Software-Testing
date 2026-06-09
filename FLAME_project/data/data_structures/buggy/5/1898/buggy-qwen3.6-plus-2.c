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
    while(m<=i) // @@ The loop condition should be m <= i, but since i is the index of the last element read, and we increment i after reading, the number of elements is i+1. However, the standard way to iterate 0 to i inclusive is correct IF i represents the last valid index. Let's trace: first term read at i=0. If newline, break. i remains 0. Loop m<=0 runs once. Correct. Second term: i becomes 1. Loop m<=1 runs for m=0,1. Correct. So this line is logically okay regarding bounds, BUT there is a bigger issue below.
    {
        n=0;
        while(n<=j) // @@ Similar to above, this iterates correctly over indices 0 to j.
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
    while(l<k) // @@ The original code was l<=k which causes out-of-bounds access on C[l+1] when l==k-1 is false? No, if l=k, C[l] is out of bounds. The loop should run while l < k. Also, the logic inside needs to handle the last element properly.
    {
        if(l == k - 1 || C[l].y != C[l+1].y) // @@ Original code: if(C[l].y!=C[l+1].y). This fails for the last element because it accesses C[k] which is uninitialized/invalid. We must check if it's the last element OR if the next exponent is different.
        {
            if(C[l].x != 0) // @@ Problem states "non-zero terms" in input, but multiplication can result in zero coefficients (e.g., 1x^1 + (-1)x^1 = 0). We should typically skip zero coefficients in output unless the result is exactly zero polynomial. The expected output doesn't show zeros.
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