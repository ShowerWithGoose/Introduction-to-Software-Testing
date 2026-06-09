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
    for(int i=0;i<n;i++) // @@ [Loop condition uses `n` (original length including '=') but processes `ne`, which is shorter; should use `strlen(ne)` or loop until `ne[i] == '\0'`. Also, `ne` may not be null-terminated.]
    {
        if(isdigit(ne[i]))
        {
            a[x]=a[x]+ne[i]-'0';  // @@ [Digits are added before multiplying by 10, leading to incorrect number parsing (e.g., '12' becomes (0+1)*10 + (1+2) = 13 instead of 12). Should multiply first then add.]
        }
        if(isdigit(ne[i+1])) // @@ [Accesses `ne[i+1]` without ensuring `i+1` is within bounds; also logic flawed because it multiplies after adding current digit.]
        {
            a[x]*=10;
        }
        else
        {
            x++;
            fu[xx]=ne[i+1]; // @@ [When `ne[i]` is last digit, `ne[i+1]` may be out-of-bounds or garbage; also stores operator after number, but indexing misaligned.]
            xx++;
        }
    }
    len=strlen(fu);
    for(int i=0;i<=strlen(fu);i++) // @@ [Loop runs to `strlen(fu)` inclusive, causing out-of-bounds access to `fu[i]` and `a[i+1]`.]
    {
        if(fu[i]=='*'||fu[i]=='/')
        {
            if(fu[i-1]=='-') // @@ [Accesses `fu[i-1]` when `i=0`, leading to out-of-bounds read (undefined behavior).]
            {
                chengshu*=-1;
            }
            if((fu[i]=='*'||fu[i]=='/')&&(fu[i-1]=='+'||fu[i-1]=='-')) // @@ [Again accesses `fu[i-1]` at `i=0`; also logic doesn't correctly handle operator precedence or grouping.]
            {
            chengshu*=a[i];
            }
            if(fu[i]=='/')
            {
                chengshu/=a[i+1]; // @@ [May perform division by zero; also `a[i+1]` may be uninitialized or out-of-bounds.]
            }
            else
            {
                chengshu*=a[i+1]; // @@ [`a[i+1]` may be out-of-bounds; also this branch runs for non-'/' operators including invalid ones.]
            }
                
        }    
        if((fu[i-1]=='*'||fu[i-1]=='/')&&fu[i]!='*'&&fu[i]!='/') // @@ [Accesses `fu[i-1]` at `i=0`; undefined behavior.]
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
        for(int i=0;i<=len;i++) // @@ [Loop goes to `i <= len`, accessing `fu[len]` and `fu[len+1]` which are out-of-bounds (since `fu` has length `len`).]
        {
            if(fu[i]=='+'&&fu[i+1]!='*'&&fu[i+1]!='/')
            {
                ans+=a[i+1]; // @@ [`a[i+1]` may be out-of-bounds; also logic fails to account for multiplication/division already processed.]
            }
            if(fu[i]=='-'&fu[i+1]!='*'&&fu[i+1]!='/') // @@ [Uses bitwise AND `&` instead of logical AND `&&`; causes incorrect condition evaluation.]
            {
                ans-=a[i+1];
            }

        }
    }
    printf("%d",ans);
    return 0;
}