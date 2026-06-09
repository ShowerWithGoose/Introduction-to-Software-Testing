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
    gets(c); // @@ [Using `gets` is unsafe and deprecated; may cause compilation error with modern compilers that remove `gets` entirely.]
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
    for(int i=0;i<n;i++) // @@ [Loop condition uses `n` (original string length) but accesses `ne[i+1]`, which may go out of bounds since `ne` is shorter due to space/`=` removal.]
    {
        if(isdigit(ne[i]))
        {
            a[x]=a[x]+ne[i]-'0';  // @@ [Logic error: digit accumulation is incorrect. Should multiply existing value by 10 before adding new digit, not after checking next char.]
        }
        if(isdigit(ne[i+1])) // @@ [Accesses `ne[i+1]` without ensuring `i+1` is within bounds of `ne`; also logic flaw in number parsing.]
        {
            a[x]*=10;
        }
        else
        {
            x++;
            fu[xx]=ne[i+1]; // @@ [Accesses `ne[i+1]` which may be beyond the valid range of `ne`; also stores operator incorrectly when current token ends.]
            xx++;
        }
    }
    len=strlen(fu);
    for(int i=0;i<=strlen(fu);i++) // @@ [Loop runs to `strlen(fu)` inclusive, causing out-of-bounds access to `fu[i]` and `a[i+1]`.]
    {
        if(fu[i]=='*'||fu[i]=='/')
        {
            if(fu[i-1]=='-') // @@ [Accesses `fu[i-1]` when `i` could be 0, leading to out-of-bounds read (`fu[-1]`).]
            {
                chengshu*=-1;
            }
            if((fu[i]=='*'||fu[i]=='/')&&(fu[i-1]=='+'||fu[i-1]=='-')) // @@ [Again accesses `fu[i-1]` unsafely when `i == 0`.]
            {
            chengshu*=a[i];
            }
            if(fu[i]=='/')
            {
                chengshu/=a[i+1]; // @@ [May access `a[i+1]` beyond allocated or initialized range.]
            }
            else
            {
                chengshu*=a[i+1]; // @@ [Same issue: potential out-of-bounds access to `a[i+1]`.]
            }
                
        }    
        if((fu[i-1]=='*'||fu[i-1]=='/')&&fu[i]!='*'&&fu[i]!='/') // @@ [Accesses `fu[i-1]` when `i` could be 0 → undefined behavior.]
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
        for(int i=0;i<=len;i++) // @@ [Loop goes to `i <= len`, but `fu` has length `len`, so `fu[len]` is null terminator; accessing `fu[i+1]` at `i == len` is out-of-bounds.]
        {
            if(fu[i]=='+'&&fu[i+1]!='*'&&fu[i+1]!='/')
            {
                ans+=a[i+1]; // @@ [May access `a[i+1]` beyond valid indices.]
            }
            if(fu[i]=='-'&fu[i+1]!='*'&&fu[i+1]!='/') // @@ [Typo: used single `&` (bitwise AND) instead of `&&` (logical AND).]
            {
                ans-=a[i+1]; // @@ [Same potential out-of-bounds access.]
            }

        }
    }
    printf("%d",ans);
    return 0;
}