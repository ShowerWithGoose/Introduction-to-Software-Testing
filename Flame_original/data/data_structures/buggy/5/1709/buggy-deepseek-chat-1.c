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
    for(i=0;i<=lenx;i++) // @@ The loop condition should be i < lenx+1, but lenx is the index of the last term, so the number of terms is lenx+1. However, the input reading sets lenx = i after reading the newline, where i is the index of the last term. For example, if there are 3 terms, i becomes 2 after reading the third term, then the newline sets lenx=2. So the loop should run for i=0 to lenx inclusive, which is correct. But note that the arrays a1 and b1 are filled up to index lenx, so this is fine.
    {
        for(e=0;e<=leny;e++) // @@ Similar to above, loop runs from 0 to leny inclusive, which is correct.
        {
            for(u=0;u<=v;u++) // @@ The loop condition should be u < v, not u <= v, because v is the current count of terms in the result. When u == v, ind[u] is uninitialized, causing undefined behavior. This is a logical error.
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
    for(i=0;i<v;i++) // @@ The loop condition should be i < v-1 for bubble sort to avoid out-of-bounds access when e+1 equals v. Currently, when i = v-1, the inner loop runs e from 0 to v-(v-1)-1 = 0, which is fine, but when i = v-2, e goes up to 1, accessing ind[e+1] = ind[1] which is valid. However, the bubble sort logic is flawed because it does not properly sort all elements; it only does one pass. The correct bubble sort requires nested loops with i from 0 to v-1 and e from 0 to v-i-1. The current code has i from 0 to v-1 and e from 0 to v-i, which may cause out-of-bounds access when e+1 equals v. For example, when i=0, e goes up to v, accessing ind[v] which is out of bounds. This is a logical error.
    {
        for(e=0;e<v-i;e++) // @@ The condition should be e < v-i-1 to avoid accessing ind[e+1] when e = v-i-1. Currently, when e = v-i-1, e+1 = v-i, which may be out of bounds if v-i equals v (when i=0). This causes undefined behavior.
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
    for(i=0;i<=v;i++) // @@ The loop condition should be i < v, not i <= v, because v is the count of terms, and the valid indices are 0 to v-1. Accessing coe[v] and ind[v] is out of bounds and prints uninitialized values. This is a logical error.
    {
        printf("%d %d ",coe[i],ind[i]);
    }
    return 0;
}