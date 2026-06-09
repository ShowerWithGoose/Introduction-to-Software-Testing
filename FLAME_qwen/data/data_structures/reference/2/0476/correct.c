#include<stdio.h>
#include<string.h>
int main()
{
    char s[85],c[85];
    gets(c);
    int i=0,j=0;
    while(i<strlen(c))
    {
        if(c[i]!=' ')
        {
            s[j]=c[i];
            j++;
        }
        i++;
    }
    s[j]='\0';
    int num;
    int a[85];
    char sign[85];
    i=0;
    int m=0;
    while(i<j)
    {
        num=0;
        while(s[i]>='0'&&s[i]<='9')
        {
            num=num*10+s[i]-'0';
            i++;
        }
        sign[m]=s[i];
        a[m]=num;
        m++;
        i++;
    }

    for(i=0; i<m; i++)
    {
        if(sign[i]=='/')
        {
            a[i+1]=a[i]/a[i+1];
            a[i]=0;
            if(i==0||sign[i-1]=='+')
                sign[i]='+';
            else if(sign[i-1]=='-')
                sign[i]='-';
        }
        else if(sign[i]=='*')
        {
            a[i+1]=a[i]*a[i+1];
            a[i]=0;
            if(i==0||sign[i-1]=='+')
                sign[i]='+';
            else if(sign[i-1]=='-')
                sign[i]='-';
        }
    }
    int sum=a[0];
    for(i=1; i<m; i++)
    {
        if(sign[i-1]=='-')
            sum-=a[i];
        else if(sign[i-1]=='+')
            sum+=a[i];
    }
    printf("%d\n",sum);

    return 0;
}

