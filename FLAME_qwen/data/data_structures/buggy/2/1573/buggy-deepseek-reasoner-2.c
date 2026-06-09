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
    for(int i=0;i<n;i++) // @@ [Loop runs up to n but ne array has fewer characters, causing out-of-bounds access]
    {
        if(isdigit(ne[i]))
        {
            a[x]=a[x]+ne[i]-'0'; // @@ [a[x] uninitialized; should be set to 0 before adding]
        }
        if(isdigit(ne[i+1])) // @@ [ne[i+1] may be out of bounds; also logic flawed for parsing numbers]
        {
            a[x]*=10;
        }
        else
        {
            x++; // @@ [Incorrect increment; should only increment when operator found]
            fu[xx]=ne[i+1]; // @@ [ne[i+1] may be out of bounds or not an operator]
            xx++;
        }
    }
    len=strlen(fu);
    for(int i=0;i<=strlen(fu);i++) // @@ [Should be i < strlen(fu) to avoid accessing fu[strlen(fu)] which is '\0']
    {
        if(fu[i]=='*'||fu[i]=='/')
        {
            if(fu[i-1]=='-') // @@ [i=0 leads to out-of-bounds access fu[-1]]
            {
                chengshu*=-1;
            }
            if((fu[i]=='*'||fu[i]=='/')&&(fu[i-1]=='+'||fu[i-1]=='-')) // @@ [fu[i-1] out-of-bounds when i=0]
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
        if((fu[i-1]=='*'||fu[i-1]=='/')&&fu[i]!='*'&&fu[i]!='/') // @@ [fu[i-1] out-of-bounds when i=0]
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
        for(int i=0;i<=len;i++)
        {
            if(fu[i]=='+'&&fu[i+1]!='*'&&fu[i+1]!='/')
            {
                ans+=a[i+1];
            }
            if(fu[i]=='-'&fu[i+1]!='*'&&fu[i+1]!='/') // @@ [Bitwise & used instead of logical &&]
            {
                ans-=a[i+1];
            }

        }
    }
    printf("%d",ans);
    return 0;
}