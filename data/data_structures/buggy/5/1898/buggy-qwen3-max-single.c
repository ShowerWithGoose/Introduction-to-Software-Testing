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
        i++; // @@ [i is incremented after checking for newline, so the last valid term is not stored at index i but at i-1; this causes the loop to miss storing the last input term correctly]
    }
    while(scanf("%d%d",&B[j].x,&B[j].y)==2)
    {    
        if(getchar()=='\n')
        {
            break;
        }
        j++; // @@ [same issue as above: j is incremented after break, so last term is not properly indexed]
    }
    int m=0,n=0,k=0;
    while(m<=i) // @@ [m should go from 0 to i-1, not i; because i points to one past the last valid index due to post-increment after break]
    {
        n=0;
        while(n<=j) // @@ [same issue: n should go up to j-1, not j]
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
    while(l<=k) // @@ [l goes up to k, but valid indices are 0 to k-1; accessing C[l+1] when l == k leads to out-of-bounds read]
    {
        if(C[l].y!=C[l+1].y) // @@ [when l == k-1, C[l+1] is out of bounds; also, this logic fails to combine more than two terms with same exponent]
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