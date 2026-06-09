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
    num=str[0]-'0'; // @@ [This assumes the first character is always a digit, but after removing spaces, the expression might start with a negative number or other edge cases. However, more critically, this initialization is wrong because it only takes the first digit and ignores multi-digit numbers starting at index 0. For example, "24..." becomes num=2 instead of 24.]
    for(k=0,t=1;k<len;) // @@ [Loop starts at k=0, but the logic inside uses str[k+1], which skips the first character when building numbers. Combined with the above line, this causes incorrect parsing of the first number.]
    {
        if(str[k+1]>='0'&&str[k+1]<='9')
        {
            num=num*10+str[k+1]-'0';
            k++;
        }
        else
        {
            a[t]=num;
            b[t]=str[k+1];
            num=0;
            k++;
            t++;
        }
    }
    for(m=1,n=1;b[m]!='\0';) // @@ [The array b is not null-terminated properly. The loop that fills b stops when k reaches len, and b[t] is assigned str[k+1] which may be beyond the string (e.g., when k = len-1, str[k+1] is '\0', so b[t] = '\0'. But then b[m] in this loop may access uninitialized values if t is not correctly managed. Also, the logic for handling operators and operands is flawed.]
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
            ans=a[m]*a[m+1];
            else
            ans*=a[m+1]; // @@ [Variable 'ans' is used without being initialized in all paths. If the first operator is '*', and b[m-1] is not '+' or '-', then 'ans' is uninitialized, leading to undefined behavior. In the test case, this likely causes garbage values like 32760.]
            if(b[m+1]=='+'||b[m+1]=='-'||b[m+1]=='=')
            {
                a[m+1]=ans;
            }
            m++;
        }
        else if(b[m]=='/')
        {
            if(b[m-1]=='+'||b[m-1]=='-')
            ans=a[m]/a[m+1];
            else
            ans/=a[m+1]; // @@ [Same issue: 'ans' may be uninitialized if this is the first operation and previous operator wasn't '+' or '-'.]
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
    sum=c[1];
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