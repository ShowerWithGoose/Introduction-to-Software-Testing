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
        if(i>1&&Xiang[i-1].zhi>Xiang[i-2].zhi)
        {
            Shi[j].xi=Xiang[--i].xi;
            Shi[j++].zhi=Xiang[i].zhi;
            break;
        }
    }
    
    while(~scanf("%lld%d",&Shi[j].xi,&Shi[j].zhi))
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

    for(k=0;k<=i;k++) // @@ [Loop condition should be k < i, not k <= i; accessing Xiang[i] is out-of-bounds since valid indices are 0 to i-1]
    {
        for(l=0;l<=j;l++) // @@ [Loop condition should be l < j, not l <= j; accessing Shi[j] is out-of-bounds since valid indices are 0 to j-1]
        {
            De[m].xi=Xiang[k].xi*Shi[l].xi;
            De[m].zhi=Xiang[k].zhi+Shi[l].zhi;
            m++;
        }
    }
    for(n=0;n<=m;n++) // @@ [Loop condition should be n < m, not n <= m; De[m] is uninitialized and out-of-bounds]
    {
        for(o=n+1;o<=m;o++) // @@ [Loop condition should be o < m, not o <= m; same out-of-bounds issue]
        {
            if(De[n].zhi==De[o].zhi)
            {
                De[n].xi=De[n].xi+De[o].xi;
                De[o].xi=0;
            }
            if(De[n].zhi<De[o].zhi)         
            {
                mid1=De[o].zhi;
                mid2=De[o].xi;
                De[o].zhi=De[n].zhi;
                De[o].xi=De[n].xi;
                De[n].zhi=mid1;
                De[n].xi=mid2;
            }
        }
    }
    for(p=0;p<=m;p++) // @@ [Loop condition should be p < m, not p <= m; accesses uninitialized De[m]]
    {
        if(De[p].xi>0) // @@ [Should output terms with non-zero coefficients, not just positive ones; misses negative coefficients]
        {
            printf("%lld %d ",De[p].xi,De[p].zhi);
        }
    }
    return 0;
}