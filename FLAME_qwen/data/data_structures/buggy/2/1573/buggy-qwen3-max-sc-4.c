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
    for(int i=0;i<n;i++) // @@ [Loop condition uses `n` (original string length) but iterates over `ne`, which is shorter; should use `strlen(ne)` or proper bound. Also, `ne[i+1]` may read out-of-bounds.]
    {
        if(isdigit(ne[i]))
        {
            a[x]=a[x]+ne[i]-'0';  // @@ [Logic error: digit accumulation is incorrect. Should first multiply by 10 then add new digit, not the other way around. Also `a[x]` is uninitialized.]
        }
        if(isdigit(ne[i+1])) // @@ [Accesses `ne[i+1]` beyond array bounds when `i == n-1`; undefined behavior.]
        {
            a[x]*=10; // @@ [This multiplication happens after adding digit, which reverses correct number-building order.]
        }
        else
        {
            x++;
            fu[xx]=ne[i+1]; // @@ [When `ne[i+1]` is '\0' or beyond, this writes garbage into `fu`. Also, operator placement logic is flawed.]
            xx++;
        }
    }
    len=strlen(fu);
    for(int i=0;i<=strlen(fu);i++) // @@ [Loop runs to `strlen(fu)` inclusive, causing out-of-bounds access to `fu[i]` and `a[i+1]`.]
    {
        if(fu[i]=='*'||fu[i]=='/')
        {
            if(fu[i-1]=='-') // @@ [When i=0, `fu[-1]` is accessed → undefined behavior.]
            {
                chengshu*=-1;
            }
            if((fu[i]=='*'||fu[i]=='/')&&(fu[i-1]=='+'||fu[i-1]=='-')) // @@ [Again accesses `fu[i-1]` when i=0 → undefined behavior.]
            {
            chengshu*=a[i]; // @@ [`a[i]` may not correspond to correct operand due to earlier parsing errors.]
            }
            if(fu[i]=='/')
            {
                chengshu/=a[i+1]; // @@ [May divide by zero; also `a[i+1]` may be uninitialized or wrong due to parsing bugs.]
            }
            else
            {
                chengshu*=a[i+1]; // @@ [Same issue: incorrect indexing and uninitialized values.]
            }
                
        }    
        if((fu[i-1]=='*'||fu[i-1]=='/')&&fu[i]!='*'&&fu[i]!='/') // @@ [Accesses `fu[i-1]` when i=0 → undefined behavior.]
        {
            ans+=chengshu;
            chengshu=1;
        }
        
    }
    if(fu[0]!='*'&&fu[0]!='/')
    {
        ans+=a[0]; // @@ [`a[0]` may be incorrect due to faulty number parsing earlier.]

    }
    {
        for(int i=0;i<=len;i++) // @@ [Loop goes to `len` inclusive, but `fu[len]` is out of bounds (valid indices: 0 to len-1).]
        {
            if(fu[i]=='+'&&fu[i+1]!='*'&&fu[i+1]!='/') // @@ [Accesses `fu[i+1]` beyond array bounds when i == len.]
            {
                ans+=a[i+1]; // @@ [Indexing into `a` likely mismatched due to earlier parsing errors.]
            }
            if(fu[i]=='-'&fu[i+1]!='*'&&fu[i+1]!='/') // @@ [Typo: used single '&' (bitwise AND) instead of '&&' (logical AND). This is a syntax/logic error.]
            {
                ans-=a[i+1]; // @@ [Same indexing issues.]
            }

        }
    }
    printf("%d",ans);
    return 0;
}