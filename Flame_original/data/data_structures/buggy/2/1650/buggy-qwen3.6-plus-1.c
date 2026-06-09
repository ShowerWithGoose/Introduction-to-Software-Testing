#include <stdio.h>
#include <string.h>
char str[10000];
int a[10000];
char b[10000];
int c[100000];
char d[100000];
int main()
{
    int len,i,j,k,t,m,n,p,num=0,ans,sum=0; // @@ 'ans' is declared but not initialized, which leads to undefined behavior when used in multiplication/division accumulation.
    gets(str); // @@ 'gets' is deprecated and removed in C11 standard, which may cause compilation errors in modern environments; 'fgets' should be used instead.
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
    num=str[0]-'0';
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
            ans=a[m]*a[m+1]; // @@ 'ans' is not properly initialized for the start of a multiplication chain, and the logic fails to handle consecutive '*' correctly.
            else
            ans*=a[m+1]; // @@ 'ans' is uninitialized here, causing undefined behavior. It should be initialized to 'a[m]' before accumulating results.
            if(b[m+1]=='+'||b[m+1]=='-'||b[m+1]=='=')
            {
                a[m+1]=ans; // @@ This update only happens when the next operator is '+', '-', or '=', so consecutive '*' operations will not correctly propagate the result to 'a[m+1]'.
            }
            m++;
        }
        else if(b[m]=='/')
        {
            if(b[m-1]=='+'||b[m-1]=='-')
            ans=a[m]/a[m+1]; // @@ Same issue as above: 'ans' is not properly initialized, and consecutive '/' operations are not handled correctly.
            else
            ans/=a[m+1]; // @@ 'ans' is uninitialized, leading to undefined behavior.
            if(b[m+1]=='+'||b[m+1]=='-'||b[m+1]=='=')
            {
                a[m+1]=ans; // @@ Fails to update 'a[m+1]' for consecutive '/' operations, breaking the accumulation logic.
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