#include <stdio.h>
#include <string.h>
char s[10005];
int a[10000];
char b[10000];
int c[20000];
char d[20000];
int main()
{
    int len,i,j,k,t,m,n,p,num=0,ans=1,res=0;
    gets(s);
    len=strlen(s);
    b[0]='?';
    for(i=0,j=0;i<len;)
    {
        if(s[i]!=' ')
        s[j++]=s[i++];    
        else
        i++;    
    }
    s[j]='\0';
    len=strlen(s);
    num=s[0]-'0'; @@ // Error: assumes first character is a digit, but expression may start with negative number (though not in given test case). However, more critically, this initialization fails when the first token has more than one digit because it only takes the first digit.
    for(k=0,t=1;k<len;)
    {
        if(s[k+1]>='0'&&s[k+1]<='9')
        {
            num=num*10+s[k+1]-'0';
            k++;
        }
        else
        {
            a[t]=num;
            b[t]=s[k+1];
            num=0;
            k++;
            t++;
        }
    } @@ // Error: parsing logic is flawed. It uses s[k+1] without ensuring k+1 < len, leading to out-of-bound access. Also, it doesn't correctly parse multi-digit numbers that appear after operators because `num` is reset too early and indexing is off.
    for(m=1,n=1;b[m]!='\0';)
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
            if(b[m-1]=='+'||b[m-1]=='-'||b[m-1]=='~')
            ans=a[m]*a[m+1];
            else
            ans*=a[m+1];
            if(b[m+1]=='+'||b[m+1]=='-'||b[m+1]=='=')
            {
                a[m+1]=ans;
            }
            m++;
        }
        else if(b[m]=='/')
        {
            if(b[m-1]=='+'||b[m-1]=='-'||b[m-1]=='~')
            ans=a[m]/a[m+1];
            else
            ans/=a[m+1];
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
    } @@ // Error: The logic for handling multiplication and division is incorrect. It uses a global `ans` variable that retains state across operations, which causes incorrect accumulation. Also, it modifies `a[m+1]` but doesn't propagate this back correctly for chained operations like `/ / *`. Additionally, `b[m-1]` may be uninitialized or invalid (e.g., when m=1, b[0]='?' which is not '+', '-', or '~', so it goes to `else` and uses stale `ans`).
    res=c[1];
    for(p=1;d[p]!='=';p++)
    {
        if(d[p]=='+')
        res+=c[p+1];
        else if(d[p]=='-')
        res-=c[p+1];    
    }
    printf("%d",res);    
    return 0;
}