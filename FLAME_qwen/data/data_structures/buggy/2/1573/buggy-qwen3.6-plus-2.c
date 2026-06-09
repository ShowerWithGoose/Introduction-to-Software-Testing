#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main(int argc, char** argv)
{
    char c[5000];
    char ne[5000];
    char fu[5000];
    int a[5000]; // @@ Array 'a' is not initialized, leading to undefined behavior when accumulating digits. Should be initialized to 0.
    char m;
    int len,n,x,xx,wei,ans=0,chengshu=1;
    x=0;
    xx=0;
    gets(c); // @@ 'gets' is removed in the C11 standard and causes a compilation error in modern environments. Use 'fgets' instead.
    n=strlen(c);
    printf("%s\n",c);
    for(int i=0;i<n;i++)
    {
        if(c[i]==' '||c[i]=='=')
        {
            continue;
        }
        else
        {
            ne[x++]=c[i];
        }
    }
    x=0;
    for(int i=0;i<n;i++) // @@ Loop bound 'n' uses the length of the original string, but 'ne' only contains 'x' valid characters and lacks a null terminator, causing out-of-bounds access.
    {
        if(isdigit(ne[i]))
        {
            a[x]=a[x]+ne[i]-'0';  // @@ Uses uninitialized value of 'a[x]'. Should properly accumulate digits with initialization.
        }
        if(isdigit(ne[i+1])) // @@ Accesses 'ne[i+1]' which is out of bounds when 'i' reaches the last valid character.
        {
            a[x]*=10;
        }
        else
        {
            x++;
            fu[xx]=ne[i+1]; // @@ Out-of-bounds access to 'ne' and incorrect logic for parsing operators.
            xx++;
        }
    }
    len=strlen(fu); // @@ 'fu' is not null-terminated, so 'strlen' will read past valid memory, causing undefined behavior.
    for(int i=0;i<=strlen(fu);i++) // @@ Loop condition uses 'strlen' on a non-null-terminated array and 'i<=' causes out-of-bounds access.
    {
        if(fu[i]=='*'||fu[i]=='/')
        {
            if(fu[i-1]=='-') // @@ When i=0, accesses 'fu[-1]', causing out-of-bounds memory access.
            {
                chengshu*=-1;
            }
            if((fu[i]=='*'||fu[i]=='/')&&(fu[i-1]=='+'||fu[i-1]=='-'))
            {
            chengshu*=a[i];
            }
            if(fu[i]=='/')
            {
                chengshu/=a[i+1];
            }
            else
            {
                chengshu*=a[i+1];
            }
                
        }    
        if((fu[i-1]=='*'||fu[i-1]=='/')&&fu[i]!='*'&&fu[i]!='/') // @@ When i=0, accesses 'fu[-1]', causing out-of-bounds memory access.
        {
            ans+=chengshu;
            chengshu=1;
        }
        
    }
    if(fu[0]!='*'&&fu[0]!='/')
    {
        ans+=a[0];

    }
    {
        for(int i=0;i<=len;i++)
        {
            if(fu[i]=='+'&&fu[i+1]!='*'&&fu[i+1]!='/')
            {
                ans+=a[i+1];
            }
            if(fu[i]=='-'&fu[i+1]!='*'&&fu[i+1]!='/') // @@ Uses bitwise '&' instead of logical '&&', resulting in incorrect condition evaluation.
            {
                ans-=a[i+1];
            }

        }
    }
    printf("%d",ans);
    return 0;
}