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
    for(int i=0;i<n;i++) // @@ Error: Should iterate over ne array, not c array. Also logic for extracting numbers and operators is flawed.
    {
        if(isdigit(ne[i]))
        {
            a[x]=a[x]+ne[i]-'0';  
        }
        if(isdigit(ne[i+1]))
        {
            a[x]*=10;
        }
        else
        {
            x++;
            fu[xx]=ne[i+1];
            xx++;
        }
    }
    len=strlen(fu);
    for(int i=0;i<=strlen(fu);i++) // @@ Error: Loop condition should be i < strlen(fu), not i <= strlen(fu). Also array index out of bounds when accessing fu[i-1] for i=0.
    {
        if(fu[i]=='*'||fu[i]=='/')
        {
            if(fu[i-1]=='-') // @@ Error: Accessing fu[-1] when i=0, causing undefined behavior.
            {
                chengshu*=-1;
            }
            if((fu[i]=='*'||fu[i]=='/')&&(fu[i-1]=='+'||fu[i-1]=='-')) // @@ Error: Same issue with fu[i-1] when i=0.
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
        if((fu[i-1]=='*'||fu[i-1]=='/')&&fu[i]!='*'&&fu[i]!='/') // @@ Error: Accessing fu[-1] when i=0.
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
        for(int i=0;i<=len;i++) // @@ Error: Loop condition should be i < len, not i <= len. Also logic for handling + and - is incomplete and incorrect.
        {
            if(fu[i]=='+'&&fu[i+1]!='*'&&fu[i+1]!='/')
            {
                ans+=a[i+1];
            }
            if(fu[i]=='-'&fu[i+1]!='*'&&fu[i+1]!='/') // @@ Error: Should use && instead of & for logical AND.
            {
                ans-=a[i+1];
            }

        }
    }
    printf("%d",ans);
    return 0;
}