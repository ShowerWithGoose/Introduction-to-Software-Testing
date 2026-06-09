#include <stdio.h>
#include <stdlib.h>
typedef struct _term
{
    int a;
    int x;
}terms,*pterm;
terms term1[50];
terms term2[50];
terms term3[50]; // @@ [The array size 50 is too small to hold all possible products of two polynomials each with up to 50 terms; maximum number of product terms can be up to 2500, leading to buffer overflow.]
int cmp(const void* p1,const void*p2)
{
    int ans;
    pterm line1=(pterm)p1;
    pterm line2=(pterm)p2;
    ans=line1->x-line2->x;
    return ans; // @@ [The comparison function returns ascending order by exponent, but the output requires descending order. Also, returning difference may cause integer overflow.]
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
    scanf("%d%d",&a0,&x0); // @@ [This reads the second term unconditionally, which fails if the first polynomial has only one term.]
    while(x0<term1[i].x) // @@ [This loop assumes input terms are given in strictly descending order and that there are at least two terms; it will not handle single-term polynomials or malformed input correctly.]
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
    while(scanf("%d%d",&a0,&x0)!=EOF) // @@ [This loop does not check for newline termination as per problem specification; it relies on EOF which may not occur when input ends with newline, causing infinite loop or incorrect parsing.]
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
    for(k=h-1;k>=0;k--) // @@ [Loop prints in reverse to get descending order, but since cmp sorts in ascending order, this works only if no duplicate exponents remain after combining; however, due to earlier logic errors in input parsing, the result may be incomplete or incorrect.]
    {
        printf("%d %d ",term3[k].a,term3[k].x);
    }
    return 0;
}