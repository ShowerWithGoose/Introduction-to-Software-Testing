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
    gets(str); // @@ [Using `gets` is unsafe and deprecated; may cause compilation error with modern compilers due to removal from standard library]
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
            k++; // @@ [This loop may go out of bounds if the number is at the end of the string and no operator follows]
            for(s=1;s<=k;s++)
            a[p]+=(ss[j-s]-'0')*pow(10,s-1); // @@ [Array `a` is not initialized to zero, leading to undefined behavior when using `+=`]
            p++;
            k=1;
            j--;
        }    
    }
    for(int sb=0;sb<strlen(fu);sb++) // @@ [Variable `sb` declared inside `for` loop may cause compilation error in C89 mode; also this loop does nothing]
    
        t=0,i=0,p=0,k=1; // @@ [This line is not inside any loop body due to missing braces above; logic error and possibly unintended scope]
    
    for(j=0;j<strlen(fu);j++)
    {
        if(fu[j]=='+'||fu[j]=='-')
        b[p++]=a[t++];
        else if(fu[j]=='*'||fu[j]=='/')
        {
        
        for(j=j+1;fu[j]!='+'&&fu[j]!='-'&&fu[j]!='=';j++)
        k++; // @@ [Loop may read beyond array bounds if expression ends without '+'/'-'/'=' after '*' or '/']
    
        ans=a[j-k]; // @@ [Index `j-k` may be negative or invalid due to incorrect tracking of operand positions]
        for(s=k;s>=1;s--)
        {
        if(fu[j-s]=='*')
        ans=ans*a[j-s+1]; // @@ [Index `j-s+1` may be out of bounds; also logic incorrectly uses `fu` array which stores operators, not operands]
        else
        ans=ans/a[j-s+1]; // @@ [Same indexing issue as above; division by zero possible if `a[...]` is zero]
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