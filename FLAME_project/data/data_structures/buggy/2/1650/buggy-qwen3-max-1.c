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
    gets(str);
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
    num=str[0]-'0'; // @@ [Assumes first character is always a digit; fails if expression starts with space (but spaces are removed), however more critically, it doesn't handle multi-digit numbers starting from index 0 correctly in the following loop logic]
    for(k=0,t=1;k<len;) // @@ [Loop logic for parsing numbers and operators is flawed: it uses k+1 to check next char, but when k is at last index, k+1 is out of bounds. Also, t starts at 1, so a[1] is first number, but a[0] is uninitialized and never used, causing misalignment]
    {
        if(str[k+1]>='0'&&str[k+1]<='9')
        {
            num=num*10+str[k+1]-'0';
            k++;
        }
        else
        {
            a[t]=num;
            b[t]=str[k+1]; // @@ [When str[k+1] is '=', this stores '=' in b[t], but when k+1 is beyond string end (e.g., at last char), this reads garbage. Also, after storing operator, t increments, but the next number isn't parsed correctly because num is reset too early]
            num=0;
            k++;
            t++;
        }
    }
    for(m=1,n=1;b[m]!='\0';) // @@ [b array may not be null-terminated properly; also, b was filled only up to t-1, but loop condition checks b[m]!='\0', which may run into uninitialized memory]
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
            ans=a[m]*a[m+1]; // @@ [ans is used without initialization in some paths; also, a[m+1] may be uninitialized if m+1 exceeds parsed numbers]
            else
            ans*=a[m+1]; // @@ [If previous operation wasn't '+' or '-', ans might contain garbage from previous iterations or uninitialized value]
            if(b[m+1]=='+'||b[m+1]=='-'||b[m+1]=='=')
            {
                a[m+1]=ans;
            }
            m++;
        }
        else if(b[m]=='/')
        {
            if(b[m-1]=='+'||b[m-1]=='-')
            ans=a[m]/a[m+1]; // @@ [Same issue: ans may be uninitialized or carry over incorrect value from prior unrelated operations]
            else
            ans/=a[m+1]; // @@ [Division uses previous ans which may be invalid; also integer division is correct per problem, but logic flow is broken]
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
    sum=c[1]; // @@ [c[1] may be uninitialized or incorrect because the earlier processing of multiplication/division doesn't reliably populate c[] for all terms; also, if first term is result of * or /, it may not be stored in c[] at all]
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