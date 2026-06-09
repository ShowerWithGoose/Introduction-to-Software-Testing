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
    printf("%s\n",c); // @@ [The program outputs the input string, which is not required and causes "Wrong Answer" due to extra output]
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
    for(int i=0;i<n;i++) // @@ [Loop condition uses original length 'n' instead of cleaned string length 'x', leading to out-of-bounds access or incorrect parsing]
    {
        if(isdigit(ne[i]))
        {
            a[x]=a[x]+ne[i]-'0';  
        }
        if(isdigit(ne[i+1])) // @@ [Accessing ne[i+1] without checking bounds, and logic for multi-digit numbers is flawed as it doesn't handle the accumulation correctly across loop iterations relative to index x]
        {
            a[x]*=10;
        }
        else
        {
            x++;
            fu[xx]=ne[i+1]; // @@ [Assigns operator to fu based on next character, but if i is at the last digit, ne[i+1] might be invalid or null. Also, fu array is not initialized, leading to garbage values.]
            xx++;
        }
    }
    len=strlen(fu); // @@ [strlen on uninitialized/partially initialized char array fu is unsafe and likely incorrect because fu is not null-terminated properly]
    for(int i=0;i<=strlen(fu);i++) // @@ [Again using strlen on improperly terminated string fu. Loop logic for evaluating precedence is fundamentally flawed and does not correctly handle standard arithmetic order of operations.]
    {
        if(fu[i]=='*'||fu[i]=='/')
        {
            if(fu[i-1]=='-') // @@ [Accessing fu[i-1] when i=0 causes out-of-bounds access]
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
        if((fu[i-1]=='*'||fu[i-1]=='/')&&fu[i]!='*'&&fu[i]!='/') // @@ [Accessing fu[i-1] when i=0 causes out-of-bounds access. Logic for accumulating results is incorrect.]
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
            if(fu[i]=='-'&fu[i+1]!='*'&&fu[i+1]!='/') // @@ [Uses bitwise AND '&' instead of logical AND '&&']
            {
                ans-=a[i+1];
            }

        }
    }
    printf("%d",ans);
    return 0;
}