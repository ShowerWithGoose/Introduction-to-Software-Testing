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
    int i=0,j=0,k,l,m=0,n,o,p,mid1=0,mid2=0,r,s; // @@ mid2 should be long long to prevent data truncation when storing coefficient values
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

    for(k=0;k<=i;k++) // @@ Off-by-one error: loop condition should be k<i to avoid accessing uninitialized Xiang[i]
    {
        for(l=0;l<=j;l++) // @@ Off-by-one error: loop condition should be l<j to avoid accessing uninitialized Shi[j]
        {
            De[m].xi=Xiang[k].xi*Shi[l].xi;
            De[m].zhi=Xiang[k].zhi+Shi[l].zhi;
            m++;
        }
    }
    for(n=0;n<=m;n++) // @@ Off-by-one error: loop condition should be n<m to avoid accessing uninitialized De[m]
    {
        for(o=n+1;o<=m;o++) // @@ Off-by-one error: loop condition should be o<m to avoid out-of-bounds array access
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
    for(p=0;p<=m;p++) // @@ Off-by-one error: loop condition should be p<m to avoid out-of-bounds array access
    {
        if(De[p].xi>0) // @@ Condition should be !=0 to correctly output terms with negative coefficients
        {
            printf("%lld %d ",De[p].xi,De[p].zhi);
        }
    }
    return 0;
}