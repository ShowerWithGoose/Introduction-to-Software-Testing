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
            b[t]=str[k+1]; // @@ The operator is stored at index t, but the loop increments t immediately after. This means b[1] holds the first operator. However, the logic for handling * and / relies on a[m] and a[m+1]. If b[1] is '*', it accesses a[1] and a[2]. This part seems to align indices such that a[t] is the number BEFORE operator b[t].
            num=0;
            k++;
            t++;
        }
    }
    // The parsing loop has a flaw: it doesn't store the last number if the expression ends with '=', because it expects an operator after every number to trigger the storage. 
    // For "24/4/3/2*2*3*4=", when k points to '4', str[k+1] is '='. It goes to else. a[t]=4, b[t]='='. Then k++, t++. Loop ends.
    // So a[1]=24, b[1]='/', a[2]=4, b[2]='/', a[3]=3, b[3]='/', a[4]=2, b[4]='*', a[5]=2, b[5]='*', a[6]=3, b[6]='*', a[7]=4, b[7]='='.
    
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
            ans=a[m]*a[m+1]; // @@ 'ans' is used uninitialized if this is the first operation or if previous ops were not * or /. It should initialize ans based on context. More critically, if b[m-1] is '*' or '/', it uses 'ans' which might be garbage or from a previous disjoint chain.
            else
            ans*=a[m+1]; // @@ If b[m-1] was '*' or '/', we continue the chain. But 'ans' needs to be initialized correctly at the start of a chain.
            if(b[m+1]=='+'||b[m+1]=='-'||b[m+1]=='=')
            {
                a[m+1]=ans;
            }
            m++;
        }
        else if(b[m]=='/')
        {
            if(b[m-1]=='+'||b[m-1]=='-')
            ans=a[m]/a[m+1]; // @@ Same issue as above: 'ans' usage is flawed for chaining multiplicative operations correctly across the whole expression without proper state management.
            else
            ans/=a[m+1]; // @@ Same issue.
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

int pre(char c)
{
    if(c=='*'||c=='/') return 1;
    else if(c=='-'||c=='+') return 0;
}

int func(char c,int i,int j)
{
    if(c=='*') return (i*j);
    else if(c=='/') return(i/j);
    else if(c=='+') return(i+j);
    else if(c=='-') return(i-j);
}