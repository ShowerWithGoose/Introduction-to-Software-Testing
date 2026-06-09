#include<stdio.h>
#include<string.h>
char s[1000];
char a[1000];
int b[1000];
int main()
{
    gets(s); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; many compilers no longer support it, leading to compilation errors. Use 'fgets' instead.]
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
    int len1=strlen(a);
    for(i=0;i<=len1-1;i++)
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
            b[i]=b[i-1]/b[i]; // @@ [Division by zero may occur if b[i] is 0, but more critically, the logic for handling operator precedence and operand association is flawed due to overwriting operators and operands in place without proper order of operations handling. However, the immediate cause of compilation error is the use of 'gets'.]
            b[i-1]=0;
        }
    }
    for(i=0;i<=len1-1;i++)
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