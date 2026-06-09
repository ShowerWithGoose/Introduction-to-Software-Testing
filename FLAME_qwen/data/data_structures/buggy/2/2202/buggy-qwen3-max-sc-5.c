#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
char str[10000];
char ss[10000];
char fu[10000];
char jia[10000];
int a[10000];
int b[10000];
int main()
{
    gets(str); // @@ [Using `gets` is unsafe and deprecated; may cause buffer overflow. However, the immediate error is likely due to uninitialized array `a` leading to undefined behavior during number parsing.]
    int t=0,i=strlen(str),j,k=1,p,s,ans=0,anss=0;
    for(j=0;j<i;j++)
    {
    
    if(str[j]!=32)
    ss[t++]=str[j];
}

    t=0,i=0,p=0;
    for(j=0;j<strlen(ss);j++)
    {
        if(ss[j]=='*'||ss[j]=='/'||ss[j]=='=')
        fu[t++]=ss[j];
        else if(ss[j]=='+'||ss[j]=='-')
        fu[t++]=ss[j],jia[i++]=ss[j];
        else if(ss[j]!='=')
        {
            for(j=j+1;ss[j]!='*'&&ss[j]!='/'&&ss[j]!='+'&&ss[j]!='-'&&ss[j]!='=';j++)
            k++;
            for(s=1;s<=k;s++)
            a[p]+=(ss[j-s]-'0')*pow(10,s-1); // @@ [Array `a` is not initialized to zero, so `a[p]` contains garbage values before addition. This leads to incorrect number parsing.]
            p++;
            k=1;
            j--;
        }    
    }
    for(int sb=0;sb<strlen(fu);sb++) // @@ [This loop does nothing useful and is followed by reinitialization of variables, indicating flawed logic structure. Also, variable-length loop with unused variable `sb` suggests confusion in control flow.]
    
        t=0,i=0,p=0,k=1;
    
    for(j=0;j<strlen(fu);j++)
    {
        if(fu[j]=='+'||fu[j]=='-')
        b[p++]=a[t++];
        else if(fu[j]=='*'||fu[j]=='/')
        {
        
        for(j=j+1;fu[j]!='+'&&fu[j]!='-'&&fu[j]!='=';j++)
        k++;
    
        ans=a[j-k]; // @@ [Index `j-k` may be out of bounds or refer to uninitialized/incorrectly parsed values due to earlier errors in number extraction. Also, logic assumes contiguous operands but parsing was flawed.]
        for(s=k;s>=1;s--)
        {
        if(fu[j-s]=='*')
        ans=ans*a[j-s+1];
        else
        ans=ans/a[j-s+1]; // @@ [Division uses floating-point `pow` earlier but expects integer division; however, more critically, indices like `j-s+1` are likely invalid because `a` indexing doesn't align with operator positions in `fu`.]
        }
        b[p++]=ans;
        t=j+1;
        k=1;
    
        }
    }

    
    anss=b[0];
    i=1;
    for(j=0;j<strlen(jia);j++)
    {
        if(jia[j]=='+')
        anss+=b[i++];
        else
        anss-=b[i++];
    }
    printf("%d",anss);

return 0;
}