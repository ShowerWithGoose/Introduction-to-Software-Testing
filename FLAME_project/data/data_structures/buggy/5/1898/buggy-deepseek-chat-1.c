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
    while(m<=i) // @@ Error: The loop condition should be m < i (or m <= i-1) because i is the index of the last element, not the count. This causes an extra iteration with uninitialized data.
    {
        n=0;
        while(n<=j) // @@ Error: Same issue as above; should be n < j (or n <= j-1) to avoid accessing uninitialized B[j].
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
    while(l<=k) // @@ Error: The loop condition should be l < k (or l <= k-1) because k is the count of elements, and C[k] is out of bounds.
    {
        if(C[l].y!=C[l+1].y) // @@ Error: When l = k-1, C[l+1] accesses C[k], which is out of bounds and may cause undefined behavior.
        {
            printf("%d %d ",C[l].x,C[l].y);
        }
        else 
        {
            C[l+1].x=C[l+1].x+C[l].x; // @@ Error: This modifies the next element but does not print the current one; also, when l = k-1, C[l+1] is out of bounds.
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