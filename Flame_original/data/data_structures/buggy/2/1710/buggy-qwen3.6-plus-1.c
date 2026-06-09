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
    gets(s); // @@ gets is deprecated and removed in C11 standard, causing compilation error. Use fgets(s, sizeof(s), stdin); instead.
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
    num=s[0]-'0';
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
            if(b[m-1]=='+'||b[m-1]=='-'||b[m-1]=='~') // @@ Typo '~' should be '?' to match b[0], otherwise ans is incorrectly initialized for the first multiplication.
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
            if(b[m-1]=='+'||b[m-1]=='-'||b[m-1]=='~') // @@ Same typo as above, fails to correctly initialize ans for the first division.
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
            d[n]='='; // @@ Missing c[n]=a[m]; before this line, causing the last number in the expression to be lost.
            break;
        }
    }
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