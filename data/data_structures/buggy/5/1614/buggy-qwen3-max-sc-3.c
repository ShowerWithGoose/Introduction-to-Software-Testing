#include <stdio.h>
#include <stdlib.h>
typedef struct _term
{
    int a;
    int x;
}terms,*pterm;
terms term1[50];
terms term2[50];
terms term3[50]; // @@ [The array size 50 is too small to hold all possible products of two polynomials each with up to 50 terms; maximum possible terms after multiplication is 50*50=2500, leading to buffer overflow]
int cmp(const void* p1,const void*p2)
{
    int ans;
    pterm line1=(pterm)p1;
    pterm line2=(pterm)p2;
    ans=line1->x-line2->x;
    return ans; // @@ [The comparison function returns positive when line1->x > line2->x, which sorts in ascending order, but output requires descending order of exponents]
}
int main()
{
    int i=0,j=0;
    int a0,x0;
    int m,n;
    int h=0,k;
    int xsum,asum;
    scanf("%d%d",&a0,&x0);
    term1[i].a=a0;
    term1[i].x=x0;
    i++;
    scanf("%d%d",&a0,&x0); // @@ [This assumes at least two terms in the first polynomial; fails if first polynomial has only one term]
    while(x0<term1[i].x) // @@ [This loop condition assumes input is given in strictly descending order and breaks on non-descending input; however, problem does not guarantee input order, and this logic incorrectly handles end-of-line detection]
    {
        term1[i].a=a0;
        term1[i].x=x0;
        i++;
        scanf("%d%d",&a0,&x0);
    }
    n=i;
    term2[j].a=a0;
    term2[j].x=x0;
    j++;
    while(scanf("%d%d",&a0,&x0)!=EOF) // @@ [This reads until EOF, but problem states that each polynomial ends with a newline; mixing newline-terminated and EOF-terminated input causes incorrect parsing when second polynomial ends with newline (not EOF)]
    {
        term2[j].a=a0;
        term2[j].x=x0;
        j++;
    }
    m=j;
    for(j=0;j<m;j++)
    {
        for(i=0;i<n;i++)
        {
            asum=term2[j].a*term1[i].a;
            xsum=term2[j].x+term1[i].x;
            for(k=0;k<h;k++)
            {
                if(term3[k].x==xsum)
                {
                    term3[k].a=term3[k].a+asum;
                    break;
                }
            }
            if(k==h)
            {
                term3[h].x=xsum;
                term3[h].a=asum;
                h++;
            }

        }
    }
    qsort(term3,h,sizeof(term3[0]),cmp);
    for(k=h-1;k>=0;k--) // @@ [Because cmp sorts in ascending order, printing from h-1 to 0 gives descending exponents, which matches requirement; however, if cmp were fixed to sort descending, this loop would be wrong. But current cmp is wrong, so this partially compensates — yet overall logic is fragile and relies on incorrect assumptions]
    {
        printf("%d %d ",term3[k].a,term3[k].x);
    }
    return 0;
}