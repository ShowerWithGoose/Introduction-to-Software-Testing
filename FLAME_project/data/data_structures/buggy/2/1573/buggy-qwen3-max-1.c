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
    printf("%s\n",c); // @@ [Unnecessary output that violates the problem's output format; should only output the final integer result]
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
    for(int i=0;i<n;i++) // @@ [Loop bound is incorrect: should iterate over `x` (length of `ne`) not original `n`; also logic for parsing numbers is flawed]
    {
        if(isdigit(ne[i]))
        {
            a[x]=a[x]+ne[i]-'0';  // @@ [Incorrect number parsing: accumulates digit without considering place value correctly]
        }
        if(isdigit(ne[i+1])) // @@ [Accesses ne[i+1] which may be out-of-bounds; also logic causes double multiplication by 10]
        {
            a[x]*=10;
        }
        else
        {
            x++;
            fu[xx]=ne[i+1]; // @@ [Accesses ne[i+1] which may be out-of-bounds when i is last valid index]
            xx++;
        }
    }
    len=strlen(fu);
    for(int i=0;i<=strlen(fu);i++) // @@ [Loop runs one past valid index of `fu`; also logic for handling operators and operands is fundamentally broken]
    {
        if(fu[i]=='*'||fu[i]=='/')
        {
            if(fu[i-1]=='-') // @@ [Accesses fu[i-1] when i could be 0, leading to undefined behavior]
            {
                chengshu*=-1;
            }
            if((fu[i]=='*'||fu[i]=='/')&&(fu[i-1]=='+'||fu[i-1]=='-')) // @@ [Same out-of-bounds risk; also misinterprets operator precedence context]
            {
            chengshu*=a[i];
            }
            if(fu[i]=='/')
            {
                chengshu/=a[i+1]; // @@ [Uses a[i+1] which may not correspond to correct operand due to earlier parsing errors]
            }
            else
            {
                chengshu*=a[i+1];
            }
                
        }    
        if((fu[i-1]=='*'||fu[i-1]=='/')&&fu[i]!='*'&&fu[i]!='/') // @@ [Again accesses fu[i-1] unsafely; logic does not correctly collapse multiplication/division subexpressions]
        {
            ans+=chengshu;
            chengshu=1;
        }
        
    }
    if(fu[0]!='*'&&fu[0]!='/')
    {
        ans+=a[0]; // @@ [Assumes a[0] is always part of addition, but doesn't account for initial negative or complex precedence]

    }
    {
        for(int i=0;i<=len;i++) // @@ [Loop bound again goes one past valid index]
        {
            if(fu[i]=='+'&&fu[i+1]!='*'&&fu[i+1]!='/') // @@ [Accesses fu[i+1] out-of-bounds; condition logic is invalid for precedence handling]
            {
                ans+=a[i+1];
            }
            if(fu[i]=='-'&fu[i+1]!='*'&&fu[i+1]!='/') // @@ [Uses single '&' instead of '&&'; also same out-of-bounds and logic flaws]
            {
                ans-=a[i+1];
            }

        }
    }
    printf("%d",ans);
    return 0;
}