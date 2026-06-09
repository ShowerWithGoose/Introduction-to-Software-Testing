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
    printf("%s\n",c); // @@ Prints the input string, which is not part of required output, causing mismatch.
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
    for(int i=0;i<n;i++) // @@ Loop bound uses original length n, but ne array length is shorter; this accesses out-of-bounds when i >= number of filtered characters.
    {
        if(isdigit(ne[i]))
        {
            a[x]=a[x]+ne[i]-'0';  // @@ a[x] is not initialized; may contain garbage.
        }
        if(isdigit(ne[i+1])) // @@ Accesses ne[i+1] which may be beyond the valid range when i is the last valid index.
        {
            a[x]*=10;
        }
        else
        {
            x++;
            fu[xx]=ne[i+1]; // @@ When i is at the last character of ne, ne[i+1] is out-of-bounds (operator after last number does not exist).
            xx++;
        }
    }
    len=strlen(fu); // @@ fu array is not null-terminated; strlen behavior is undefined.
    for(int i=0;i<=strlen(fu);i++) // @@ Uses strlen in loop condition; also <= may cause iteration past end; fu not null-terminated.
    {
        if(fu[i]=='*'||fu[i]=='/')
        {
            if(fu[i-1]=='-') // @@ Out-of-bounds access when i==0.
            {
                chengshu*=-1;
            }
            if((fu[i]=='*'||fu[i]=='/')&&(fu[i-1]=='+'||fu[i-1]=='-')) // @@ Out-of-bounds access when i==0.
            {
            chengshu*=a[i]; // @@ Index i for a[] should refer to number index, not operator index; likely incorrect.
            }
            if(fu[i]=='/')
            {
                chengshu/=a[i+1]; // @@ Index i+1 for a[] is wrong; also may be out-of-bounds.
            }
            else
            {
                chengshu*=a[i+1]; // @@ Index i+1 for a[] is wrong; also may be out-of-bounds.
            }
                
        }    
        if((fu[i-1]=='*'||fu[i-1]=='/')&&fu[i]!='*'&&fu[i]!='/') // @@ Out-of-bounds access when i==0.
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
        for(int i=0;i<=len;i++) // @@ Loop bound uses len which is garbage from undefined strlen.
        {
            if(fu[i]=='+'&&fu[i+1]!='*'&&fu[i+1]!='/') // @@ fu[i+1] may be out-of-bounds.
            {
                ans+=a[i+1];
            }
            if(fu[i]=='-'&fu[i+1]!='*'&&fu[i+1]!='/') // @@ Bitwise & instead of logical &&; also fu[i+1] may be out-of-bounds.
            {
                ans-=a[i+1];
            }

        }
    }
    printf("%d",ans);
    return 0;
}