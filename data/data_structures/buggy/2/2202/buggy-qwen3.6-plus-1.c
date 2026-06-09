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
    gets(str); // @@ gets is removed in C11 standard and causes compilation errors in modern environments; use fgets instead.
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
            a[p]+=(ss[j-s]-'0')*pow(10,s-1); // @@ Array index j-s can be negative causing out-of-bounds access; logic for parsing multi-digit numbers is fundamentally flawed.
            p++;
            k=1;
            j--;
        }    
    }
    for(int sb=0;sb<strlen(fu);sb++) // @@ Missing braces for loop body, causing only the next line to execute repeatedly; likely a logical error.
    
        t=0,i=0,p=0,k=1;
    
    for(j=0;j<strlen(fu);j++)
    {
        if(fu[j]=='+'||fu[j]=='-')
        b[p++]=a[t++];
        else if(fu[j]=='*'||fu[j]=='/')
        {
        
        for(j=j+1;fu[j]!='+'&&fu[j]!='-'&&fu[j]!='=';j++)
        k++;
    
        ans=a[j-k]; // @@ Array index j-k can be negative, leading to out-of-bounds access; incorrect logic for retrieving the first operand in a chain.
        for(s=k;s>=1;s--)
        {
        if(fu[j-s]=='*')
        ans=ans*a[j-s+1]; // @@ Incorrect index calculation for operands, likely accessing wrong elements or out-of-bounds.
        else
        ans=ans/a[j-s+1]; // @@ Same indexing error as above for division.
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