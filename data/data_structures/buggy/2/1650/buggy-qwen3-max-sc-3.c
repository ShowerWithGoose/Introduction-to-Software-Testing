#include <stdio.h>
#include <string.h>
char str[10000];
int a[10000];
char b[10000];
int c[100000];
char d[100000];
int main()
{
    int len,i,j,k,t,m,n,p,num=0,ans,sum=0;
    gets(str); // @@ [Using `gets` is unsafe and deprecated; however, the actual compilation error is likely due to missing include for `gets` or compiler settings. But more critically, the logic below has multiple flaws leading to incorrect parsing and evaluation.]
    len=strlen(str);
    for(i=0,j=0;i<len;)
    {
        if(str[i]!=' ')
        str[j++]=str[i++];    
        else
        i++;    
    }
    str[j]='\0';
    len=strlen(str);
    num=str[0]-'0'; // @@ [Assumes first character is a digit; fails if expression starts with negative number (though problem says valid expression without parentheses, but doesn't guarantee positive start). However, main issue is in parsing logic.]
    for(k=0,t=1;k<len;) // @@ [Loop condition and indexing are flawed: accesses str[k+1] without ensuring k+1 < len, leading to out-of-bounds access when k == len-1.]
    {
        if(str[k+1]>='0'&&str[k+1]<='9')
        {
            num=num*10+str[k+1]-'0';
            k++;
        }
        else
        {
            a[t]=num;
            b[t]=str[k+1]; // @@ [When k+1 == len (i.e., at '='), this reads beyond the string or assigns '=' correctly, but later logic mishandles termination. Also, t starts at 1, so a[0] is uninitialized.]
            num=0;
            k++;
            t++;
        }
    }
    for(m=1,n=1;b[m]!='\0';) // @@ [b array may not be null-terminated properly; also, logic for handling operators is incorrect—doesn't account for operator precedence correctly in all cases and uses uninitialized `ans`.]
    {
        if(b[m]=='+'||b[m]=='-'||b[m]=='=')
        {
            c[n]=a[m];
            d[n]=b[m];
            n++;
            m++;
        }
        else if(b[m]=='*')
        {
            if(b[m-1]=='+'||b[m-1]=='-')
            ans=a[m]*a[m+1]; // @@ [`ans` is used uninitialized if previous condition wasn't met; also, a[m+1] may be out of bounds.]
            else
            ans*=a[m+1]; // @@ [Relies on previous value of `ans`, which may be garbage.]
            if(b[m+1]=='+'||b[m+1]=='-'||b[m+1]=='=')
            {
                a[m+1]=ans;
            }
            m++;
        }
        else if(b[m]=='/')
        {
            if(b[m-1]=='+'||b[m-1]=='-')
            ans=a[m]/a[m+1]; // @@ [Same issues as multiplication: uninitialized `ans` and potential out-of-bounds access.]
            else
            ans/=a[m+1]; // @@ [Uses uninitialized or stale `ans`.]
            if(b[m+1]=='+'||b[m+1]=='-'||b[m+1]=='=')
            {
                a[m+1]=ans;
            }
            m++;
        }
        else if(b[m]=='=')
        {
            d[n]='=';
            break;
        }
    }
    sum=c[1]; // @@ [c[1] may be uninitialized if no '+'/'-'/'=' was processed; also, indexing starts at 1 inconsistently.]
    for(p=1;d[p]!='=';p++)
    {
        if(d[p]=='+')
        sum+=c[p+1];
        else if(d[p]=='-')
        sum-=c[p+1];    
    }
    printf("%d",sum);    
    return 0;
}