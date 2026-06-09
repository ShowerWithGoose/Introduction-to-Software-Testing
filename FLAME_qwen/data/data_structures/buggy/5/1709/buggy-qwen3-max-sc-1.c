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
            lenx=i; // @@ [lenx should be i+1 because the current term (at index i) is valid and should be included; the loop breaks after storing the term that ends with '\n', so total terms = i+1]
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
            leny=i; // @@ [same issue as above: leny should be i+1 to include the last term]
            i=0;
            break;
        }
        i++;
    }
    int e,u,u0,tr=0,v=0;
    int coe[100]={},ind[100]={};
    for(i=0;i<=lenx;i++) // @@ [loop condition should be i < lenx (or i <= lenx if lenx was correctly set to count), but since lenx is off-by-one, this causes out-of-bound access or missing terms]
    {
        for(e=0;e<=leny;e++) // @@ [same issue: should be e < leny or fix leny first]
        {
            for(u=0;u<=v;u++) // @@ [u <= v accesses ind[v] which is uninitialized (valid indices are 0 to v-1); should be u < v]
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
        for(e=0;e<v-i;e++) // @@ [e < v - i - 1 is correct for bubble sort; current condition e < v - i leads to accessing ind[e+1] out of bounds when e = v - i - 1]
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
    for(i=0;i<=v;i++) // @@ [should be i < v; i <= v prints an extra uninitialized element at index v]
    {
        printf("%d %d ",coe[i],ind[i]);
    }
    return 0;
}