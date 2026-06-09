#include<stdio.h>
#include<string.h>
char s[1000];
char a[1000];
int b[1000];
int main()
{
    gets(s);
    printf("%s\n",s);
    int i,j=1,k=0;
    int sum=0;
    int len=strlen(s);
    a[0]='+';
    for(i=0;i<=len-1;i++)
    {
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='=')
        {
            b[k]=sum;
            sum=0;
            k++;
            if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
            {
                a[j]=s[i];
                j++;
            }
        }
        if(s[i]>=48&&s[i]<=57)
        {
            sum=10*sum+(s[i]-'0');
        }
    }
    int len1=strlen(a); // @@ a is not null-terminated; strlen may read garbage, causing undefined behavior
    for(i=0;i<=len1-1;i++) // @@ loop bound based on incorrect len1; may access out-of-bounds
    {
        if(a[i]=='*')
        {
            a[i]=a[i-1];
            b[i]=b[i]*b[i-1];
            b[i-1]=0;
        }
        if(a[i]=='/')
        {
            a[i]=a[i-1];
            b[i]=b[i-1]/b[i];
            b[i-1]=0;
        }
    }
    for(i=0;i<=len1-1;i++) // @@ loop bound based on incorrect len1; may access uninitialized a or b
    {
        if(a[i]=='+')
        {
            sum+=b[i];
        }
        if(a[i]=='-')
        {
            sum-=b[i];
        }
    }
    printf("%d",sum);
    
    return 0;
}