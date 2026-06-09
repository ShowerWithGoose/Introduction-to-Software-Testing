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

    for(k=0;k<=i;k++) // @@ [Logic Error: The loop condition k<=i accesses Xiang[i], which is out of bounds or contains invalid data. The valid indices for the first polynomial are 0 to i-1. It should be k<i.]
    {
        for(l=0;l<=j;l++) // @@ [Logic Error: The loop condition l<=j accesses Shi[j], which is out of bounds or contains invalid data. The valid indices for the second polynomial are 0 to j-1. It should be l<j.]
        {
            De[m].xi=Xiang[k].xi*Shi[l].xi;
            De[m].zhi=Xiang[k].zhi+Shi[l].zhi;
            m++;
        }
    }
    for(n=0;n<=m;n++) // @@ [Logic Error: The loop condition n<=m accesses De[m], which is one past the last valid element (indices 0 to m-1). It should be n<m.]
    {
        for(o=n+1;o<=m;o++) // @@ [Logic Error: The loop condition o<=m accesses De[m], which is out of bounds. It should be o<m.]
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
    for(p=0;p<=m;p++) // @@ [Logic Error: The loop condition p<=m accesses De[m], which is out of bounds. It should be p<m.]
    {
        if(De[p].xi>0) // @@ [Logic Error: This condition skips terms with negative coefficients and zero coefficients. Zero coefficients should be skipped, but negative coefficients should be printed. It should be De[p].xi != 0.]
        {
            printf("%lld %d ",De[p].xi,De[p].zhi);
        }
    }
    return 0;
}