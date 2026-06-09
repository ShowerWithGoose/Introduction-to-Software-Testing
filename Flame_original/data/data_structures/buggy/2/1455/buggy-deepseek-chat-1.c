#include<stdio.h>
#include<math.h>
#include<string.h>
char *p(char f[])
{
    int i,j;
    j=0;
    for(i=0;;i++)
    {
        if(f[i]!=' ')
        {
            f[j]=f[i];
            j++;
        }
        if(f[i]=='=')
        {
            break;
        }
    }
    return f;
}
int main()
{
    char a[10000];
    gets(a);
    strcpy(a,p(a));
    int i,j;
    int num=0;
    for(i=0;a[i]!='=';i++)
    {
        if(a[i]=='*'||a[i]=='/')
        {
            int s,e;
            int num1=0;
            int result=0;
            for(j=i-1;a[j]>='0'&&a[j]<='9'&&j>=0;j--)
            {
                num1=num1+(a[j]-'0')*pow(10,i-j-1); // @@ [Error: pow returns double, and using it for integer digit extraction is unreliable due to floating-point precision issues; also the logic for extracting the left operand is flawed because it assumes single-digit numbers and doesn't correctly handle multi-digit numbers]
                e=j;
            }
            int num2=0;
            for(j=i+1;a[j]>='0'&&a[j]<='9'&&a[j]!='=';j++)
            {
                num2=num2*10+(a[j]-'0');
                s=j;
            }
            if(a[i]=='*')
            {
                result=num1*num2;
            }
            if(a[i]=='/')
            {
                result=num1/num2;
            }
            for(j=s;result!=0;j--) // @@ [Error: This loop incorrectly overwrites the array starting from position s, but the logic for placing digits is wrong; it does not correctly replace the expression with the result, and the loop condition and decrement are flawed]
            {
                a[j]=result%10+'0';
                result/=10;
            }
            for(;e<=j;j--) // @@ [Error: This loop is intended to clear spaces but uses incorrect bounds and logic; it may overwrite other parts of the array incorrectly]
            {
                a[j]=' ';
            }
        }
    }
    puts(a);
        int temp=0;
        int sum=0;
        int op=0;
    for(i=0;;i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            temp=temp*10+(a[i]-'0');
            if(op==0)
            {
                sum=temp; // @@ [Error: This sets sum to temp on the first digit, but if the first number is multi-digit, it will be overwritten incorrectly; also op==0 should indicate no operator yet, but the logic is flawed for handling the first number]
            }
        }
        else
        {
            if(op==1)
            {
                sum+=temp;
            }
            else if(op==2)
            {
                sum-=temp;
            }
            if(a[i]=='+')
            {
                op=1;
                temp=0;
            }
            else if(a[i]=='-')
            {
                op=2;
                temp=0;
            }        
        }
        if(a[i]=='=')
        {
            break;
        }
    }
    printf("%d",sum);
    return 0;
}