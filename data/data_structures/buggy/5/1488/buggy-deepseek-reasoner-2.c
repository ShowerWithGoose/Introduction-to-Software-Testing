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
        scanf(" %lld %d",&Xiang[i].xi,&Xiang[i].zhi);  // @@ [Infinite loop: loop condition never breaks because detection logic is wrong; should detect newline instead.]
        i++;
        if(i>1&&Xiang[i-1].zhi>Xiang[i-2].zhi) // @@ [Incorrect condition for end of first polynomial; exponents are descending, so this condition is never true, causing infinite loop.]
        {
            Shi[j].xi=Xiang[--i].xi; // @@ [Incorrectly moves the last term from first polynomial to second polynomial; logic is flawed.]
            Shi[j++].zhi=Xiang[i].zhi; // @@ [Same as line above, moves term erroneously.]
            break;
        }
    }
    
    while(~scanf("%lld%d",&Shi[j].xi,&Shi[j].zhi)) // @@ [While loop condition expects EOF, but input ends with newline; may cause infinite waiting or incorrect reading. Should detect newline.]
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

    for(k=0;k<=i;k++) // @@ [Loop bound uses <= i, but i is the count, so index goes out of bounds. Should be < i.]
    {
        for(l=0;l<=j;l++) // @@ [Loop bound uses <= j, out of bounds. Should be < j.]
        {
            De[m].xi=Xiang[k].xi*Shi[l].xi;
            De[m].zhi=Xiang[k].zhi+Shi[l].zhi;
            m++;
        }
    }
    for(n=0;n<=m;n++) // @@ [Loop bound uses <= m, out of bounds. Should be < m.]
    {
        for(o=n+1;o<=m;o++) // @@ [Loop bound uses <= m, out of bounds. Should be < m.]
        {
            if(De[n].zhi==De[o].zhi)
            {
                De[n].xi=De[n].xi+De[o].xi;
                De[o].xi=0;
            }
            if(De[n].zhi<De[o].zhi)         
            {
                mid1=De[o].zhi;
                mid2=De[o].xi; // @@ [mid2 is int but stores long long xi, causing potential data loss. Should use long long.]
                De[o].zhi=De[n].zhi;
                De[o].xi=De[n].xi;
                De[n].zhi=mid1;
                De[n].xi=mid2;
            }
        }
    }
    for(p=0;p<=m;p++) // @@ [Loop bound uses <= m, out of bounds. Should be < m.]
    {
        if(De[p].xi>0)
        {
            printf("%lld %d ",De[p].xi,De[p].zhi);
        }
    }
    return 0;
}