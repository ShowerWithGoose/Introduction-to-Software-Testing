#include<stdio.h>
int main()
{
    int a1[100]={},b1[100]={},a2[100]={},b2[100]={};
    int a,b,i=0,lenx,leny;
    char c;
    while(scanf("%d%d%c",&a,&b,&c)!=EOF)
    {
        a1[i]=a;
        b1[i]=b;
        if(c=='\n')
        {
            lenx=i;
            i=0;
            break;
        }
        i++;
    }
    while(scanf("%d%d%c",&a,&b,&c)!=EOF)
    {
        a2[i]=a;
        b2[i]=b;
        if(c=='\n')
        {
            leny=i;
            i=0;
            break;
        }
        i++;
    }
    int e,u,u0,tr=0,v=0;
    int coe[100]={},ind[100]={};
    for(i=0;i<=lenx;i++)
    {
        for(e=0;e<=leny;e++)
        {
            for(u=0;u<=v;u++) // @@ Loop condition should be u<v to avoid accessing uninitialized ind[v] (when v is the count of existing terms). This can cause incorrect matching or out-of-bounds access.
            {
                if((b1[i]+b2[e])==ind[u])
                {
                    tr=1;
                    u0=u;
                    break;
                }
            }
            if(tr==1)
            {
                coe[u0]+=(a1[i]*a2[e]);
                tr=0;
            }
            else
            {
                coe[v]=(a1[i]*a2[e]);
                ind[v]=(b1[i]+b2[e]);
                v++;
            }
        }
    }
    for(i=0;i<v;i++)
    {
        for(e=0;e<v-i;e++) // @@ When v-i is 1, e=0 accesses ind[e+1]=ind[1] which is out of bounds for the last element. This causes undefined behavior and introduces extra zero terms.
        {
            if(ind[e]<ind[e+1])
            {
                int tmp;
                tmp=ind[e];
                ind[e]=ind[e+1];
                ind[e+1]=tmp;
                tmp=coe[e];
                coe[e]=coe[e+1];
                coe[e+1]=tmp;
            }
        }
    }
    for(i=0;i<=v;i++) // @@ Loop should be i<v to avoid printing uninitialized coe[v] and ind[v]. This causes the extra "0 0" output.
    {
        printf("%d %d ",coe[i],ind[i]);
    }
    return 0;
}