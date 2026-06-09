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
    gets(str);
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
            a[p]+=(ss[j-s]-'0')*pow(10,s-1); // @@ [Error: pow returns double, causing potential precision loss and incorrect integer conversion; also a[p] is not initialized to 0 before accumulation]
            p++;
            k=1;
            j--;
        }    
    }
    for(int sb=0;sb<strlen(fu);sb++) // @@ [Error: This loop has an empty body, but the following lines are not part of it due to missing braces, causing unintended execution]
    
        t=0,i=0,p=0,k=1; // @@ [Error: These assignments are executed only once (for sb=0) due to missing braces, resetting variables incorrectly]
    
    for(j=0;j<strlen(fu);j++)
    {
        if(fu[j]=='+'||fu[j]=='-')
        b[p++]=a[t++];
        else if(fu[j]=='*'||fu[j]=='/')
        {
        
        for(j=j+1;fu[j]!='+'&&fu[j]!='-'&&fu[j]!='=';j++) // @@ [Error: This loop modifies j, causing the outer loop to skip indices and potentially go out of bounds]
        k++;
    
        ans=a[j-k]; // @@ [Error: j has been incremented past the operator, so j-k may be out of bounds or incorrect]
        for(s=k;s>=1;s--)
        {
        if(fu[j-s]=='*')
        ans=ans*a[j-s+1]; // @@ [Error: a[j-s+1] may be uninitialized or out of bounds due to incorrect indexing]
        else
        ans=ans/a[j-s+1]; // @@ [Error: Same indexing issue as above]
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