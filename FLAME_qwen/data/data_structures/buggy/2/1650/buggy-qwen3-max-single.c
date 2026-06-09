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
    num=str[0]-'0'; // @@ [Assumes first character is a digit; fails if expression starts with space or sign (though problem says valid expression, but still risky). However, main issue is uninitialized `ans` used later.]
    for(k=0,t=1;k<len;)
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
            if(b[m-1]=='+'||b[m-1]=='-')
            ans=a[m]*a[m+1]; // @@ [`ans` is used without being initialized in all paths; if this branch isn't taken first, `ans` has garbage value.]
            else
            ans*=a[m+1]; // @@ [If previous `ans` was not set (e.g., first operator is *), this uses uninitialized `ans`.]
            if(b[m+1]=='+'||b[m+1]=='-'||b[m+1]=='=')
            {
                a[m+1]=ans;
            }
            m++;
        }
        else if(b[m]=='/')
        {
            if(b[m-1]=='+'||b[m-1]=='-')
            ans=a[m]/a[m+1]; // @@ [Same issue: `ans` may be uninitialized if this is the first operation and no prior assignment.]
            else
            ans/=a[m+1]; // @@ [Uses uninitialized `ans` if no prior assignment.]
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
    sum=c[1]; // @@ [If there's only one number in the expression (e.g., "5 ="), `c[1]` may be uninitialized because the loop that fills `c` starts at `m=1` and may not run.]
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