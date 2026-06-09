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
            a[p]+=(ss[j-s]-'0')*pow(10,s-1); // @@ [Error: pow(10, s-1) returns a double, and the multiplication with int may cause precision loss; also, the loop logic for extracting multi-digit numbers is flawed because j is incremented inside the inner loop, causing incorrect indexing and potential out-of-bounds access]
            p++;
            k=1;
            j--;
        }    
    }
    for(int sb=0;sb<strlen(fu);sb++) // @@ [Error: This for loop has an empty body (no braces), so it only executes the next statement (t=0,i=0,p=0,k=1;) repeatedly, which is likely unintended and causes incorrect resetting of variables]
    
        t=0,i=0,p=0,k=1;
    
    for(j=0;j<strlen(fu);j++)
    {
        if(fu[j]=='+'||fu[j]=='-')
        b[p++]=a[t++];
        else if(fu[j]=='*'||fu[j]=='/')
        {
        
        for(j=j+1;fu[j]!='+'&&fu[j]!='-'&&fu[j]!='=';j++) // @@ [Error: Modifying loop variable j inside the inner loop causes incorrect iteration and potential out-of-bounds access]
        k++;
    
        ans=a[j-k]; // @@ [Error: j-k may be negative or out of bounds due to the flawed loop logic above]
        for(s=k;s>=1;s--)
        {
        if(fu[j-s]=='*')
        ans=ans*a[j-s+1]; // @@ [Error: a[j-s+1] may be out of bounds or incorrectly indexed]
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