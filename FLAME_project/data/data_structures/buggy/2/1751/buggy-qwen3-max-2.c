#include<stdio.h>
#include<string.h>
int main()
{
    char a[1005],a1[1005],a2[1005];
    gets(a); // @@ [Using gets() is unsafe and may cause buffer overflow; more critically, it reads the whole line including '=', but later parsing assumes numbers and operators are separated correctly. However, the main logic errors are elsewhere.]
    int b1[1005]={0},b2[1005]={0};
    int i,j,sum;
    for(i=0,j=0;a[i]!='\0';i++)
    {
        if(a[i]!=' ')
        {
            a[j++]=a[i];
        }
    }
    a[j]='\0';
    for(i=0,j=0;a[i]!='\0';i++) // @@ [This loop incorrectly parses multi-digit numbers because it doesn't reset b1[j] when encountering an operator. It accumulates digits into b1[j] even across different numbers due to missing index increment at operator boundaries.]
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            b1[j]=10*b1[j]+(a[i]-'0');
        }
        else
        {
            j++;
        }
    }
    for(i=0,j=0;a[i]!='\0';i++)
    {
        if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')
        {
            a1[j++]=a[i];
        }
    }
    a1[j]='\0';
    for(i=0,j=0;a[i]!='\0';i++)
    {
        if(a[i]=='+'||a[i]=='-')
        {
            a2[j++]=a[i];
        }
    }
    a2[j]='\0';
    for(i=0;a1[i]!='\0';i++)
    {
        if(a1[i]=='*')
        {
            b1[i+1]=b1[i]*b1[i+1];
            b1[i]=-10001;
        }
        else if(a1[i]=='/')
        {
            b1[i+1]=b1[i]/b1[i+1];
            b1[i]=-10001;
        }
    }
    for(i=0,j=0;i<(int)strlen(b1);i++) // @@ [strlen(b1) is invalid because b1 is an integer array, not a null-terminated char array. This leads to undefined behavior and incorrect iteration count.]
    {
        if(b1[i]!=-10001)
        {
            b2[j++]=b1[i];
        }
    }
    sum=b2[0];
    for(i=0;a2[i]!='\0';i++)
    {
        if(a2[i]=='+')
        {
            sum+=b2[i+1];
        }
        else if(a2[i]=='-')
        {
            sum-=b2[i+1];
        }
    }
    printf("%d",sum);
    return 0;
}