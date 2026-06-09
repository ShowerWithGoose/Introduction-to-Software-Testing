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
    gets(c); // @@ [Using `gets` is unsafe and deprecated; may cause compilation error with modern compilers that remove it entirely.]
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
    for(int i=0;i<n;i++) // @@ [Loop condition uses `n` (original string length) but accesses `ne[i+1]`, which may be out of bounds since `ne` is shorter due to space/`=` removal.]
    {
        if(isdigit(ne[i]))
        {
            a[x]=a[x]+ne[i]-'0';  // @@ [Digits are added before multiplying by 10, leading to incorrect number parsing (e.g., "12" becomes (0+1)*10 + (1+2) = 13). Should multiply first then add.]
        }
        if(isdigit(ne[i+1])) // @@ [Accesses `ne[i+1]` without ensuring `i+1` is within bounds of `ne`; also logic flaw: multiplication by 10 should happen when current digit is part of multi-digit number, not based on next char being digit in this way.]
        {
            a[x]*=10;
        }
        else
        {
            x++;
            fu[xx]=ne[i+1]; // @@ [When `ne[i]` is last character, `ne[i+1]` is undefined; also, after skipping spaces and '=', `ne` doesn't end with '=', so `ne[i+1]` may read garbage.]
            xx++;
        }
    }
    len=strlen(fu);
    for(int i=0;i<=strlen(fu);i++) // @@ [Loop goes to `i <= strlen(fu)`, accessing `fu[strlen(fu)]` which is null terminator, then uses `fu[i-1]` when i=0 → `fu[-1]` (undefined behavior).]
    {
        if(fu[i]=='*'||fu[i]=='/')
        {
            if(fu[i-1]=='-') // @@ [When i=0, `fu[-1]` is accessed → undefined behavior.]
            {
                chengshu*=-1;
            }
            if((fu[i]=='*'||fu[i]=='/')&&(fu[i-1]=='+'||fu[i-1]=='-')) // @@ [Again, `fu[i-1]` when i=0 is invalid. Also, logic doesn't correctly handle operator precedence or grouping.]
            {
            chengshu*=a[i];
            }
            if(fu[i]=='/')
            {
                chengshu/=a[i+1]; // @@ [`a[i+1]` may be uninitialized or wrong index; overall algorithm for handling * and / is flawed.]
            }
            else
            {
                chengshu*=a[i+1];
            }
                
        }    
        if((fu[i-1]=='*'||fu[i-1]=='/')&&fu[i]!='*'&&fu[i]!='/') // @@ [`fu[i-1]` when i=0 is invalid; also, this condition tries to finalize multiplication/division chain but indexing is inconsistent.]
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
        for(int i=0;i<=len;i++) // @@ [Loop goes to `i <= len`, but `fu[len]` is null; then accesses `fu[i+1]` → out of bounds.]
        {
            if(fu[i]=='+'&&fu[i+1]!='*'&&fu[i+1]!='/')
            {
                ans+=a[i+1];
            }
            if(fu[i]=='-'&fu[i+1]!='*'&&fu[i+1]!='/') // @@ [Typo: single `&` instead of `&&` → bitwise AND instead of logical AND, causing incorrect condition evaluation.]
            {
                ans-=a[i+1];
            }

        }
    }
    printf("%d",ans);
    return 0;
}