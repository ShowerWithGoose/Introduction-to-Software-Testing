#include<stdio.h>
struct Duo {
    long long xi;
    int zhi;
};
int main()
{
    struct Duo Xiang[10086];
    struct Duo Shi[10086];
    struct Duo De[10086];
    char c[10086];
    int i=0,j=0,k,l,m=0,n,o,p,mid1=0,mid2=0,r,s;
    while(1)
    {
        scanf(" %lld %d",&Xiang[i].xi,&Xiang[i].zhi);  
        i++;
        if(i>1&&Xiang[i-1].zhi>Xiang[i-2].zhi) @@ The condition incorrectly assumes an increase in exponents marks the start of the second polynomial, but input exponents are strictly descending, making this boundary detection unreliable.
        {
            Shi[j].xi=Xiang[--i].xi;
            Shi[j++].zhi=Xiang[i].zhi;
            break;
        }
    }
    
    while(~scanf("%lld%d",&Shi[j].xi,&Shi[j].zhi)) @@ The `~scanf` construct is non-standard and may cause compilation errors or warnings in strict environments; additionally, it reads until EOF rather than stopping at the newline as specified by the input format.
    {
        
        j++;
    }
/*       for(k=0;k<i;k++)
    {
        printf("%lld %d\n",Xiang[k].xi,Xiang[k].zhi);
    }
    printf("\n");
    for(k=0;k<j;k++)
    {
        printf("%lld %d\n",Shi[k].xi,Shi[k].zhi);
    }*/

    for(k=0;k<=i;k++) @@ Off-by-one error causing array index out of bounds; `i` represents the number of terms, so the loop should run while `k < i`.
    {
        for(l=0;l<=j;l++) @@ Off-by-one error causing array index out of bounds; `j` represents the number of terms, so the loop should run while `l < j`.
        {
            De[m].xi=Xiang[k].xi*Shi[l].xi;
            De[m].zhi=Xiang[k].zhi+Shi[l].zhi;
            m++;
        }
    }
    for(n=0;n<=m;n++) @@ Off-by-one error causing array index out of bounds; `m` represents the number of product terms, so the loop should run while `n < m`.
    {
        for(o=n+1;o<=m;o++) @@ Off-by-one error causing array index out of bounds; `m` represents the number of product terms, so the loop should run while `o < m`.
        {
            if(De[n].zhi==De[o].zhi)
            {
                De[n].xi=De[n].xi+De[o].xi;
                De[o].xi=0;
            }
            if(De[n].zhi<De[o].zhi)         
            {
                mid1=De[o].zhi;
                mid2=De[o].xi; @@ `mid2` is declared as `int`, but `De[o].xi` is `long long`, which may cause data truncation and compilation warnings/errors in strict modes.
                De[o].zhi=De[n].zhi;
                De[o].xi=De[n].xi;
                De[n].zhi=mid1;
                De[n].xi=mid2;
            }
        }
    }
    for(p=0;p<=m;p++) @@ Off-by-one error causing array index out of bounds; `m` represents the number of product terms, so the loop should run while `p < m`.
    {
        if(De[p].xi>0) @@ Incorrect condition for filtering terms; should be `!= 0` to properly handle polynomials with negative coefficients.
        {
            printf("%lld %d ",De[p].xi,De[p].zhi);
        }
    }
    return 0;
}