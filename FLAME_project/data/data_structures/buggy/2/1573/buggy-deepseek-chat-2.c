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
    printf("%s\n",c); // @@ This line prints the input expression, which is not required by the problem and may cause output mismatch.
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
    for(int i=0;i<n;i++) // @@ The loop uses n (length of original input) but should use x (length of ne) to iterate over ne array correctly.
    {
        if(isdigit(ne[i]))
        {
            a[x]=a[x]+ne[i]-'0';  
        }
        if(isdigit(ne[i+1])) // @@ This logic for building multi-digit numbers is flawed; it multiplies by 10 even when the next character is not a digit, and does not handle consecutive digits properly.
        {
            a[x]*=10;
        }
        else
        {
            x++;
            fu[xx]=ne[i+1]; // @@ This assigns the operator from the next character, but i+1 may be out of bounds or incorrect when i is the last digit.
            xx++;
        }
    }
    len=strlen(fu); // @@ fu is not null-terminated properly, so strlen may give incorrect length.
    for(int i=0;i<=strlen(fu);i++) // @@ Loop condition uses <= strlen(fu) which may cause out-of-bounds access; also uses strlen in loop condition causing repeated calculation.
    {
        if(fu[i]=='*'||fu[i]=='/')
        {
            if(fu[i-1]=='-') // @@ When i=0, fu[i-1] accesses out-of-bounds memory.
            {
                chengshu*=-1;
            }
            if((fu[i]=='*'||fu[i]=='/')&&(fu[i-1]=='+'||fu[i-1]=='-')) // @@ Same out-of-bounds issue when i=0.
            {
            chengshu*=a[i];
            }
            if(fu[i]=='/')
            {
                chengshu/=a[i+1]; // @@ a[i+1] may be uninitialized or out-of-bounds.
            }
            else
            {
                chengshu*=a[i+1]; // @@ a[i+1] may be uninitialized or out-of-bounds.
            }
                
        }    
        if((fu[i-1]=='*'||fu[i-1]=='/')&&fu[i]!='*'&&fu[i]!='/') // @@ Out-of-bounds access when i=0.
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
        for(int i=0;i<=len;i++) // @@ Loop condition uses <= len, causing out-of-bounds access when i equals len.
        {
            if(fu[i]=='+'&&fu[i+1]!='*'&&fu[i+1]!='/') // @@ fu[i+1] may be out-of-bounds when i is len-1.
            {
                ans+=a[i+1];
            }
            if(fu[i]=='-'&fu[i+1]!='*'&&fu[i+1]!='/') // @@ Uses bitwise & instead of logical &&; also fu[i+1] may be out-of-bounds.
            {
                ans-=a[i+1];
            }

        }
    }
    printf("%d",ans);
    return 0;
}