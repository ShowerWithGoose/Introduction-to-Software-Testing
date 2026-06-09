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
    gets(str); // @@ [Using `gets` is unsafe and deprecated; may cause compilation error with modern compilers that remove `gets` entirely.]
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
    num=str[0]-'0'; // @@ [Assumes first character is a digit; fails if expression starts with space or negative number (though problem says valid expression without parentheses, but doesn't guarantee no leading space after cleaning). However, more critically, if the first number has more than one digit, this initialization is correct only if followed by proper parsing—but logic below may mishandle single-digit vs multi-digit.]
    for(k=0,t=1;k<len;) // @@ [Loop condition and indexing are error-prone: accesses `str[k+1]` which may go out of bounds when `k == len-1`. Also, `t` starts at 1, so `a[1]` is first number, but `a[0]` is unused—may lead to off-by-one errors later.]
    {
        if(str[k+1]>='0'&&str[k+1]<='9') // @@ [When k = len-1, str[k+1] is '\0' or beyond, causing undefined behavior. This leads to potential buffer overread.]
        {
            num=num*10+str[k+1]-'0';
            k++;
        }
        else
        {
            a[t]=num;
            b[t]=str[k+1]; // @@ [Same issue: when k = len-1, str[k+1] is out of bounds. Also, when str[k+1] is '=', b[t] stores '=', but loop continues incorrectly.]
            num=0;
            k++;
            t++;
        }
    }
    for(m=1,n=1;b[m]!='\0';) // @@ [`b` array was filled up to index t-1, but not necessarily null-terminated. So `b[m]!='\0'` may never be true, causing infinite loop or reading garbage.]
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
            ans=a[m]*a[m+1]; // @@ [`a[m+1]` may be uninitialized or out of valid range. Also, `ans` is used uninitialized in `else` branch (`ans*=a[m+1]`) if previous operations didn't set it.]
            else
            ans*=a[m+1]; // @@ [Uninitialized use of `ans` if this is the first operation and previous condition wasn't met.]
            if(b[m+1]=='+'||b[m+1]=='-'||b[m+1]=='=')
            {
                a[m+1]=ans;
            }
            m++;
        }
        else if(b[m]=='/')
        {
            if(b[m-1]=='+'||b[m-1]=='-')
            ans=a[m]/a[m+1]; // @@ [Same issues: `a[m+1]` may be invalid, and `ans` may be uninitialized in `else` branch.]
            else
            ans/=a[m+1]; // @@ [Uninitialized `ans` usage.]
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
    sum=c[1]; // @@ [If there's only one number in the expression, `c[1]` may be uninitialized because the loop that fills `c` may not have run (e.g., expression "5=").]
    for(p=1;d[p]!='=';p++) // @@ [`d` array may not be properly null-terminated or may not contain '=' at expected position, leading to infinite loop or accessing uninitialized memory. Also, if expression ends without storing '=' in `d`, loop condition fails.]
    {
        if(d[p]=='+')
        sum+=c[p+1];
        else if(d[p]=='-')
        sum-=c[p+1];    
    }
    printf("%d",sum);    
    return 0;
}