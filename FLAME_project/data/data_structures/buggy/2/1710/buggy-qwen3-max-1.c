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
    b[0]='?'; // @@ [b[0] is set to '?' but never used correctly; this leads to incorrect operator tracking]
    for(i=0,j=0;i<len;)
    {
        if(s[i]!=' ')
        s[j++]=s[i++];    
        else
        i++;    
    }
    s[j]='\0';
    len=strlen(s);
    num=s[0]-'0'; // @@ [assumes first character is a digit, but doesn't handle multi-digit numbers starting at index 0 properly in the loop below]
    for(k=0,t=1;k<len;) // @@ [loop logic for parsing numbers and operators is flawed: it uses k+1 without ensuring k+1 < len, and misaligns tokens]
    {
        if(s[k+1]>='0'&&s[k+1]<='9')
        {
            num=num*10+s[k+1]-'0';
            k++;
        }
        else
        {
            a[t]=num;
            b[t]=s[k+1]; // @@ [s[k+1] may be '=' or beyond string end; also, b[t] stores operator after number, but indexing is off]
            num=0;
            k++;
            t++;
        }
    }
    for(m=1,n=1;b[m]!='\0';) // @@ [b array was not null-terminated properly, leading to undefined behavior in loop condition]
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
            if(b[m-1]=='+'||b[m-1]=='-'||b[m-1]=='~') // @@ [b[m-1] accesses uninitialized or invalid memory (e.g., b[0]='?', and '~' is not a real operator)]
            ans=a[m]*a[m+1];
            else
            ans*=a[m+1];
            if(b[m+1]=='+'||b[m+1]=='-'||b[m+1]=='=') // @@ [b[m+1] may be out of bounds; also, assignment a[m+1]=ans doesn't propagate correctly through chain of * and /]
            {
                a[m+1]=ans;
            }
            m++;
        }
        else if(b[m]=='/')
        {
            if(b[m-1]=='+'||b[m-1]=='-'||b[m-1]=='~') // @@ [same issue: '~' is not a valid sentinel; logic for detecting start of multiplicative term is broken]
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
    }
    res=c[1]; // @@ [c[1] may not be initialized if first token wasn't handled as additive; entire separation of multiplicative and additive phases is flawed]
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