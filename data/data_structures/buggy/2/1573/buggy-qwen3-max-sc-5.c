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
    gets(c); // @@ [Use of unsafe function 'gets' which is deprecated and may cause buffer overflow; also, some compilers (like newer GCC) remove 'gets' entirely, causing compilation error]
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
    for(int i=0;i<n;i++) // @@ [Loop condition uses 'n' (original string length) but iterates over 'ne', which may be shorter; should use strlen(ne) or proper bound]
    {
        if(isdigit(ne[i]))
        {
            a[x]=a[x]+ne[i]-'0';  // @@ [Logic error: digit accumulation is incorrect. Should multiply existing value by 10 before adding new digit, not after checking next char]
        }
        if(isdigit(ne[i+1])) // @@ [Accesses ne[i+1] without ensuring i+1 is within bounds; leads to undefined behavior]
        {
            a[x]*=10; // @@ [This multiplication happens after adding the digit, which reverses correct number building order]
        }
        else
        {
            x++;
            fu[xx]=ne[i+1]; // @@ [Accesses ne[i+1] which may be out-of-bounds; also stores operator incorrectly when current char is digit and next is non-digit]
            xx++;
        }
    }
    len=strlen(fu);
    for(int i=0;i<=strlen(fu);i++) // @@ [Loop goes to i <= strlen(fu), which accesses fu[strlen(fu)] == '\0', then later accesses fu[i-1] when i=0 → fu[-1] → undefined behavior]
    {
        if(fu[i]=='*'||fu[i]=='/')
        {
            if(fu[i-1]=='-') // @@ [When i=0, fu[i-1] is fu[-1], invalid memory access]
            {
                chengshu*=-1;
            }
            if((fu[i]=='*'||fu[i]=='/')&&(fu[i-1]=='+'||fu[i-1]=='-')) // @@ [Again, fu[i-1] when i=0 is invalid]
            {
            chengshu*=a[i];
            }
            if(fu[i]=='/')
            {
                chengshu/=a[i+1]; // @@ [May divide by zero; also logic assumes a[i+1] exists, but array bounds not checked]
            }
            else
            {
                chengshu*=a[i+1]; // @@ [Same issue: a[i+1] may be uninitialized or out of intended range]
            }
                
        }    
        if((fu[i-1]=='*'||fu[i-1]=='/')&&fu[i]!='*'&&fu[i]!='/') // @@ [fu[i-1] when i=0 is invalid access]
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
        for(int i=0;i<=len;i++) // @@ [Loop runs to i <= len, so accesses fu[len] which is '\0', and fu[i+1] → fu[len+1] → out of bounds]
        {
            if(fu[i]=='+'&&fu[i+1]!='*'&&fu[i+1]!='/') // @@ [fu[i+1] may be out of bounds; also logic doesn't handle operator precedence correctly after prior processing]
            {
                ans+=a[i+1];
            }
            if(fu[i]=='-'&fu[i+1]!='*'&&fu[i+1]!='/') // @@ [Typo: single '&' instead of '&&' → bitwise AND instead of logical AND]
            {
                ans-=a[i+1];
            }

        }
    }
    printf("%d",ans);
    return 0;
}