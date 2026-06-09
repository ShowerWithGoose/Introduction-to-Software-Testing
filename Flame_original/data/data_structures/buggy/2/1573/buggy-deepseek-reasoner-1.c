#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main(int argc, char** argv)
{
    char c[5000];
    char ne[5000];
    char fu[5000];
    int a[5000];
    char m;
    int len,n,x,xx,wei,ans=0,chengshu=1;
    x=0;
    xx=0;
    gets(c);
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
    for(int i=0;i<n;i++)  // @@ Loop should iterate over ne length, not n. Also parsing logic incorrect.
    {
        if(isdigit(ne[i]))
        {
            a[x]=a[x]+ne[i]-'0';  // @@ a[x] not initialized, leads to garbage.
        }
        if(isdigit(ne[i+1]))  // @@ Potential out-of-bounds access when i+1 >= strlen(ne). Also wrong logic for number parsing.
        {
            a[x]*=10;
        }
        else
        {
            x++;  // @@ x incremented for every non‑digit, including within a multi‑digit number.
            fu[xx]=ne[i+1];  // @@ Assigns operator based on next character, but index may be out of bounds and logic is flawed.
            xx++;
        }
    }
    len=strlen(fu);  // @@ fu is not null‑terminated, strlen may read garbage.
    for(int i=0;i<=strlen(fu);i++)  // @@ Loop includes i = strlen(fu), leading to use of fu[strlen(fu)] which is '\0', not a problem but condition i<=len is unconventional.
    {
        if(fu[i]=='*'||fu[i]=='/')
        {
            if(fu[i-1]=='-')  // @@ i=0 leads to out‑of‑bounds access fu[-1].
            {
                chengshu*=-1;
            }
            if((fu[i]=='*'||fu[i]=='/')&&(fu[i-1]=='+'||fu[i-1]=='-'))  // @@ Again out‑of‑bounds when i=0.
            {
            chengshu*=a[i];  // @@ a[i] may not correspond to the correct operand.
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
        if((fu[i-1]=='*'||fu[i-1]=='/')&&fu[i]!='*'&&fu[i]!='/')  // @@ i=0 leads to out‑of‑bounds.
        {
            ans+=chengshu;
            chengshu=1;
        }
        
    }
    if(fu[0]!='*'&&fu[0]!='/')  // @@ fu[0] may be uninitialized or incorrect.
    {
        ans+=a[0];  // @@ a[0] may be uninitialized or incorrect.

    }
    {
        for(int i=0;i<=len;i++)
        {
            if(fu[i]=='+'&&fu[i+1]!='*'&&fu[i+1]!='/')
            {
                ans+=a[i+1];
            }
            if(fu[i]=='-'&fu[i+1]!='*'&&fu[i+1]!='/')  // @@ Single '&' should be '&&'; also logic incomplete.
            {
                ans-=a[i+1];
            }

        }
    }
    printf("%d",ans);
    return 0;
}