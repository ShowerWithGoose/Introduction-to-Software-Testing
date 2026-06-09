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
    gets(c); // @@ [Use of unsafe function 'gets' which is deprecated and may cause buffer overflow; also, some compilers may not support it leading to compilation error]
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
    for(int i=0;i<n;i++) // @@ [Loop condition uses 'n' (length of original string with spaces and '=') but iterates over 'ne', which is shorter; should use strlen(ne) or proper bound]
    {
        if(isdigit(ne[i]))
        {
            a[x]=a[x]+ne[i]-'0';  // @@ [Logic error: digit accumulation is incorrect. Should first multiply existing value by 10 before adding new digit]
        }
        if(isdigit(ne[i+1])) // @@ [Accesses ne[i+1] without checking bounds; may read beyond array end when i = n-1]
        {
            a[x]*=10; // @@ [Incorrect placement: multiplying by 10 after adding digit leads to wrong number construction]
        }
        else
        {
            x++;
            fu[xx]=ne[i+1]; // @@ [Accesses ne[i+1] which may be out-of-bounds; also stores operator even when i+1 is beyond valid data]
            xx++;
        }
    }
    len=strlen(fu);
    for(int i=0;i<=strlen(fu);i++) // @@ [Loop runs to strlen(fu) inclusive, causing out-of-bounds access to fu[i]]
    {
        if(fu[i]=='*'||fu[i]=='/') // @@ [Accesses fu[i] when i == strlen(fu), which is '\0', leading to undefined behavior]
        {
            if(fu[i-1]=='-') // @@ [When i=0, accesses fu[-1], which is invalid memory]
            {
                chengshu*=-1;
            }
            if((fu[i]=='*'||fu[i]=='/')&&(fu[i-1]=='+'||fu[i-1]=='-')) // @@ [Again accesses fu[i-1] when i=0 → invalid]
            {
            chengshu*=a[i];
            }
            if(fu[i]=='/')
            {
                chengshu/=a[i+1]; // @@ [May divide by zero; also logic assumes a[i+1] exists, but array bounds not checked]
            }
            else
            {
                chengshu*=a[i+1]; // @@ [Same as above: potential out-of-bounds access to a[i+1]]
            }
                
        }    
        if((fu[i-1]=='*'||fu[i-1]=='/')&&fu[i]!='*'&&fu[i]!='/') // @@ [Accesses fu[i-1] when i=0 → invalid]
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
        for(int i=0;i<=len;i++) // @@ [Loop goes to i <= len, but fu has length 'len', so fu[len] is '\0'; accessing fu[i+1] at i=len causes out-of-bounds]
        {
            if(fu[i]=='+'&&fu[i+1]!='*'&&fu[i+1]!='/') // @@ [Accesses fu[i+1] beyond array bounds when i = len]
            {
                ans+=a[i+1]; // @@ [May access a[i+1] beyond allocated or initialized values]
            }
            if(fu[i]=='-'&fu[i+1]!='*'&&fu[i+1]!='/') // @@ [Typo: single '&' instead of '&&'; also same out-of-bounds issue as above]
            {
                ans-=a[i+1]; // @@ [Same out-of-bounds risk]
            }

        }
    }
    printf("%d",ans);
    return 0;
}