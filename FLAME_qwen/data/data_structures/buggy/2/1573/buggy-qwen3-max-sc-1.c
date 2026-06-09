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
    for(int i=0;i<n;i++) // @@ [Loop condition uses `n` (original string length) but iterates over `ne`, which is shorter; should use `strlen(ne)` or track its actual length. Also, `ne[i+1]` may access out-of-bounds memory.]
    {
        if(isdigit(ne[i]))
        {
            a[x]=a[x]+ne[i]-'0';  // @@ [Digits are added before multiplying by 10, leading to incorrect number parsing (e.g., "12" becomes (0+1)*10 + (1+2) = 13 instead of 12). Should multiply first then add.]
        }
        if(isdigit(ne[i+1])) // @@ [Accesses `ne[i+1]` without ensuring `i+1` is within bounds; causes undefined behavior at last character.]
        {
            a[x]*=10;
        }
        else
        {
            x++;
            fu[xx]=ne[i+1]; // @@ [When `ne[i]` is the last digit, `ne[i+1]` is out of bounds; also, after skipping '=', this may read garbage or '\0' into operators.]
            xx++;
        }
    }
    len=strlen(fu);
    for(int i=0;i<=strlen(fu);i++) // @@ [Loop runs to `i <= strlen(fu)`, accessing `fu[strlen(fu)]` which is '\0', and then uses `fu[i-1]` when `i=0` → `fu[-1]` → undefined behavior.]
    {
        if(fu[i]=='*'||fu[i]=='/')
        {
            if(fu[i-1]=='-') // @@ [When i=0, `fu[i-1]` is `fu[-1]` → invalid memory access.]
            {
                chengshu*=-1;
            }
            if((fu[i]=='*'||fu[i]=='/')&&(fu[i-1]=='+'||fu[i-1]=='-')) // @@ [Again accesses `fu[i-1]` when i=0 → undefined behavior.]
            {
            chengshu*=a[i];
            }
            if(fu[i]=='/')
            {
                chengshu/=a[i+1]; // @@ [`a[i+1]` may be uninitialized or out of sync due to earlier parsing errors.]
            }
            else
            {
                chengshu*=a[i+1]; // @@ [Same issue: `a[i+1]` may not correspond to correct operand.]
            }
                
        }    
        if((fu[i-1]=='*'||fu[i-1]=='/')&&fu[i]!='*'&&fu[i]!='/') // @@ [When i=0, `fu[i-1]` is invalid. Also logic for grouping multiplication/division is flawed.]
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
        for(int i=0;i<=len;i++) // @@ [Loop goes to `i <= len`; `fu[len]` is '\0', and `fu[i+1]` becomes `fu[len+1]` → out of bounds.]
        {
            if(fu[i]=='+'&&fu[i+1]!='*'&&fu[i+1]!='/')
            {
                ans+=a[i+1];
            }
            if(fu[i]=='-'&fu[i+1]!='*'&&fu[i+1]!='/') // @@ [Uses single '&' (bitwise AND) instead of '&&' (logical AND), causing incorrect condition evaluation.]
            {
                ans-=a[i+1];
            }

        }
    }
    printf("%d",ans);
    return 0;
}