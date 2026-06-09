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
            lenx=i; // @@ [lenx should be i+1 because the current term (at index i) is valid and needs to be included; breaking here excludes the last term from count]
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
            leny=i; // @@ [same issue: leny should be i+1 to include the last term]
            i=0;
            break;
        }
        i++;
    }
    int e,u,u0,tr=0,v=0;
    int coe[100]={},ind[100]={};
    for(i=0;i<=lenx;i++) // @@ [loop condition should be i < lenx if lenx was correctly set, but since lenx = i (not i+1), this loop runs one extra time leading to out-of-bound or zero terms]
    {
        for(e=0;e<=leny;e++) // @@ [same issue: e <= leny causes access beyond valid data]
        {
            for(u=0;u<=v;u++) // @@ [u <= v accesses uninitialized element coe[v], ind[v]; should be u < v]
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
        for(e=0;e<v-i;e++) // @@ [e < v - i - 1 is correct for bubble sort; e < v - i causes access to ind[e+1] when e = v - i - 1, which is out of bounds when i=0 → e goes up to v-1, then e+1 = v → invalid]
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
    for(i=0;i<=v;i++) // @@ [should be i < v; i <= v prints an extra uninitialized term (index v), which explains the "0 0" in output]
    {
        printf("%d %d ",coe[i],ind[i]);
    }
    return 0;
}