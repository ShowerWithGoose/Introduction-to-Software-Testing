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

    for(k=0;k<=i;k++) // @@ The loop condition k<=i causes an out-of-bounds access. It should be k<i because i is the count of elements in Xiang (indices 0 to i-1). Accessing Xiang[i] reads uninitialized memory.
    {
        for(l=0;l<=j;l++) // @@ The loop condition l<=j causes an out-of-bounds access. It should be l<j because j is the count of elements in Shi (indices 0 to j-1). Accessing Shi[j] reads uninitialized memory.
        {
            De[m].xi=Xiang[k].xi*Shi[l].xi;
            De[m].zhi=Xiang[k].zhi+Shi[l].zhi;
            m++;
        }
    }
    for(n=0;n<=m;n++) // @@ The loop condition n<=m is incorrect. m is the number of elements in De (indices 0 to m-1). Accessing De[m] is out of bounds. It should be n<m.
    {
        for(o=n+1;o<=m;o++) // @@ The loop condition o<=m is incorrect. It should be o<m to stay within bounds of the De array.
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
    for(p=0;p<=m;p++) // @@ The loop condition p<=m is incorrect. It should be p<m to avoid accessing De[m] which is out of bounds.
    {
        if(De[p].xi>0) // @@ This condition fails to print terms with negative coefficients or zero coefficients (if required by problem, though usually non-zero terms are printed). More critically, if the result coefficient is negative, it won't be printed. The problem says "non-zero terms" in input, but output should likely include negative coefficients if they result from multiplication. However, the primary issue here combined with the previous loop errors is accessing invalid memory. Also, if De[p].xi is 0, it shouldn't be printed, but if it's negative, it should. The condition `>0` is logically wrong for general polynomial output unless specified otherwise. Given the expected output `120 ...`, positive is fine here, but generally `!= 0` is safer. But the crash is due to bounds.
        {
            printf("%lld %d ",De[p].xi,De[p].zhi);
        }
    }
    return 0;
}