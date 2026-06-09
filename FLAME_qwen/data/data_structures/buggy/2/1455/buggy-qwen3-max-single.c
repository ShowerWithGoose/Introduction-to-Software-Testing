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
    gets(a); // @@ [Using `gets` is unsafe and deprecated; more critically, in many modern environments (like those with strict compilation flags or without legacy support), `gets` may not be available, leading to a compilation error. The reference program also uses `gets`, but the actual issue here might be environment-related. However, the real compilation error indicated ("gcc: not found") suggests a build environment problem, but since we're to find code errors causing logical/runtime issues under normal compilation, the use of `gets` is a critical flaw that can cause compilation failure in standards-compliant compilers (e.g., C11+ where `gets` is removed).]
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
                num1=num1+(a[j]-'0')*pow(10,i-j-1); // @@ [Using `pow` from math.h for integer powers introduces floating-point inaccuracies. For example, pow(10,2) might yield 99.999... which becomes 99 when cast to int, causing incorrect digit reconstruction. This leads to wrong operand extraction.]
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
            for(j=s;result!=0;j--) // @@ [If `result` is 0 (e.g., 0*5), this loop never runs, leaving old digits in place. Also, writing digits backwards without clearing extra positions causes malformed expressions. Additionally, if `result` has fewer digits than the original `num2`, leftover digits remain, corrupting parsing.]
            {
                a[j]=result%10+'0';
                result/=10;
            }
            for(;e<=j;j--) // @@ [After the previous loop, `j` may be less than `e`, making this loop condition (`e <= j`) false immediately, so spaces aren't inserted to overwrite the first operand. Also, modifying `j` in the loop condition while using it as index is error-prone and likely leaves parts of the original numbers unerased, causing parsing errors later.]
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
                sum=temp;
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