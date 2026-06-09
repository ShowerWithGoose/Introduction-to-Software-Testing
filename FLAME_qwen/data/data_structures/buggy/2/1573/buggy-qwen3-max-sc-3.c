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
    gets(c); // @@ [Use of unsafe function 'gets' which is deprecated and may cause buffer overflow; also, some compilers reject it entirely leading to compilation error]
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
    for(int i=0;i<n;i++) // @@ [Loop condition uses 'n' (length of original input including '=') but processes 'ne' which is shorter; should use strlen(ne) or proper bound]
    {
        if(isdigit(ne[i]))
        {
            a[x]=a[x]+ne[i]-'0';  // @@ [Logic error: digit accumulation is incorrect. Should multiply existing value by 10 before adding new digit, not after checking next char]
        }
        if(isdigit(ne[i+1])) // @@ [Accesses ne[i+1] without ensuring i+1 is within bounds; leads to undefined behavior or reading garbage]
        {
            a[x]*=10;
        }
        else
        {
            x++;
            fu[xx]=ne[i+1]; // @@ [When ne[i] is last digit, ne[i+1] may be out-of-bound or invalid (e.g., '\0'), causing fu to store garbage]
            xx++;
        }
    }
    len=strlen(fu);
    for(int i=0;i<=strlen(fu);i++) // @@ [Loop runs to i <= strlen(fu), which accesses fu[strlen(fu)] == '\0', then checks fu[i-1] when i=0 → fu[-1] → undefined behavior]
    {
        if(fu[i]=='*'||fu[i]=='/')
        {
            if(fu[i-1]=='-') // @@ [When i=0, fu[i-1] is fu[-1], which is invalid memory access]
            {
                chengshu*=-1;
            }
            if((fu[i]=='*'||fu[i]=='/')&&(fu[i-1]=='+'||fu[i-1]=='-')) // @@ [Again, fu[i-1] when i=0 is invalid]
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
        for(int i=0;i<=len;i++) // @@ [Loop goes to i <= len, but fu[len] is '\0'; also, accesses fu[i+1] → out-of-bound when i = len]
        {
            if(fu[i]=='+'&&fu[i+1]!='*'&&fu[i+1]!='/') // @@ [fu[i+1] may be out-of-bound when i = len]
            {
                ans+=a[i+1];
            }
            if(fu[i]=='-'&fu[i+1]!='*'&&fu[i+1]!='/') // @@ [Typo: single '&' instead of '&&'; also, fu[i+1] may be out-of-bound]
            {
                ans-=a[i+1];
            }

        }
    }
    printf("%d",ans);
    return 0;
}