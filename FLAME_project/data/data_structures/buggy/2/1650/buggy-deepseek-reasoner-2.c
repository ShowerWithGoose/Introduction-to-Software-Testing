#include <stdio.h>
#include <string.h>
char str[10000];
int a[10000];
char b[10000];
int c[100000];
char d[100000];
int main()
{
    int len,i,j,k,t,m,n,p,num=0,ans,sum=0; // @@ [ans is uninitialized, leads to undefined behavior in later calculations]
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
    num=str[0]-'0';
    for(k=0,t=1;k<len;) // @@ [Loop condition allows k to reach len-1, then accesses str[k+1] out of bounds; also fails to process the last character '=']
    {
        if(str[k+1]>='0'&&str[k+1]<='9')
        {
            num=num*10+str[k+1]-'0';
            k++;
        }
        else
        {
            a[t]=num;
            b[t]=str[k+1]; // @@ [When k is len-1, str[k+1] is beyond the string, causing undefined behavior]
            num=0;
            k++;
            t++;
        }
    }
    for(m=1,n=1;b[m]!='\0';) // @@ [Due to parsing error, b never contains '=', so the loop may terminate early or incorrectly]
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
            if(b[m-1]=='+'||b[m-1]=='-') // @@ [b[m-1] may be uninitialized for m=1, and the logic for precedence is incorrect]
            ans=a[m]*a[m+1];
            else
            ans*=a[m+1]; // @@ [ans is uninitialized here, causing undefined behavior]
            if(b[m+1]=='+'||b[m+1]=='-'||b[m+1]=='=')
            {
                a[m+1]=ans;
            }
            m++;
        }
        else if(b[m]=='/')
        {
            if(b[m-1]=='+'||b[m-1]=='-') // @@ [Same issue as above]
            ans=a[m]/a[m+1];
            else
            ans/=a[m+1]; // @@ [ans uninitialized]
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
    for(p=1;d[p]!='=';p++) // @@ [d[1] is '\0' (global), so this loop runs indefinitely, leading to undefined behavior]
    {
        if(d[p]=='+')
        sum+=c[p+1];
        else if(d[p]=='-')
        sum-=c[p+1];    
    }
    printf("%d",sum);    
    return 0;
}