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
            lenx=i; // @@ [lenx should be i+1 because the current term (at index i) is valid and included; the loop breaks after reading the last term, so total terms = i+1]
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
            leny=i; // @@ [same issue: leny should be i+1 to include the last term read before '\n']
            i=0;
            break;
        }
        i++;
    }
    int e,u,u0,tr=0,v=0;
    int coe[100]={},ind[100]={};
    for(i=0;i<=lenx;i++) // @@ [loop runs from 0 to lenx inclusive, but if lenx was set to i (instead of i+1), this misses the last term; however, even if lenx were correct, the loop condition should be i < lenx_actual, not <=]
    {
        for(e=0;e<=leny;e++) // @@ [same issue: should be e < actual number of terms in second polynomial]
        {
            for(u=0;u<=v;u++) // @@ [u <= v accesses ind[v], which is uninitialized (since valid indices are 0 to v-1); should be u < v]
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
        for(e=0;e<v-i;e++) // @@ [e goes up to v-i-1, but accesses e+1, so when e = v-i-1, e+1 = v-i which may be out of bounds if i=0 → e+1 = v, but valid indices are 0 to v-1]
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
    for(i=0;i<=v;i++) // @@ [prints v+1 terms (0 to v inclusive), but only v terms were stored (indices 0 to v-1); this prints an extra uninitialized term (coe[v], ind[v]) which is zero-initialized, causing "0 0" in output]
    {
        printf("%d %d ",coe[i],ind[i]);
    }
    return 0;
}