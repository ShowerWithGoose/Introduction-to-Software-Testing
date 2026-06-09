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
                num1=num1+(a[j]-'0')*pow(10,i-j-1); // @@ undefined reference to `pow' because math library not linked
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
            for(j=s;result!=0;j--)
            {
                a[j]=result%10+'0';
                result/=10;
            }
            for(;e<=j;j--)
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