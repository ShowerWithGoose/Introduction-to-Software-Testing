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
    while(m<=i)
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
    while(l<=k) // @@ loop condition l <= k leads to out-of-bounds access; valid indices are 0..k-1
    {
        if(C[l].y!=C[l+1].y) // @@ accessing C[l+1] when l can be k-1 or k causes out-of-bounds; also logic fails for three or more equal exponents
        {
            printf("%d %d ",C[l].x,C[l].y); // @@ prints terms with zero coefficient; should check if coefficient != 0
        }
        else 
        {
            C[l+1].x=C[l+1].x+C[l].x; // @@ out-of-bounds access when l = k-1; also does not zero out C[l], leading to duplicate output
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