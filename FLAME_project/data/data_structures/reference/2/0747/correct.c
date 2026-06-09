#include<stdio.h>
void qkg(char s[])
{
    long long i,j;
    for(i=j=0;s[i]!='\0';i++)
    {
        if(s[i]!=' ')
            s[j++]=s[i];
    }
    s[j]='\0';
}
int main()
{
    char s[1000000],f[100000];
    long long i,n=0,j=0,m=0;
    long long a[100000];
    gets(s);
    qkg(s);
    for(i=0;s[i]!='\0';i++)
    {
        while(s[i]<='9'&&s[i]>='0')
        {
            n=n*10+s[i]-'0';
            i++;
        }
        if(n!=0)
        {
            a[j]=n;
            n=0;
            j++;
        }
        if(s[i]!='=')
            f[j-1]=s[i];
    }
    for(i=0;i<j-1;i++)
    {
        if(f[i]=='*')
        {
            a[i]=a[i]*a[i+1];
            for(m=i+1;m<j-1;m++)
            {
                a[m]=a[m+1];
                f[m-1]=f[m];
            }
            j--;
            i--;
        }
        else if(f[i]=='/')
        {
            a[i]=a[i]/a[i+1];
            for(m=i+1;m<j-1;m++)
            {
                a[m]=a[m+1];
                f[m-1]=f[m];
            }
            j--;
            i--;
        }
    }
    while(j>1)
    {
        if(f[0]=='+')
            a[0]=a[0]+a[1];
        else if(f[0]=='-')
            a[0]=a[0]-a[1];
        for(i=1;i<j-1;i++)
        {
            a[i]=a[i+1];
            f[i-1]=f[i];
        }
        j--;
    }
    printf("%lld",a[0]%1000000000);
    return 0;
}



