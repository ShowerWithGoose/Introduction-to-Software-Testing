#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char s[1000005];
int ope(int ans,int sum,char op)
{
    if(op=='+') return ans+sum;
    else if(op=='-') return ans-sum;
    else if(op=='*') return ans*sum;
    else return ans/sum;
}
int main()
{
    gets(s); // @@ [The function `gets` is unsafe and has been removed from the C standard library since C11. Compilers often disable it by default, leading to a compilation error. Use `fgets` instead.]
    int i=0,j=0,ans=0,sum,k=0,flag=0,num=0;
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]!=' ')
        {
            s[j++]=s[i];
        }

    }
    s[j]='\0';
    puts(s);
    char op='+',c,opp;
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]=='=')
        {
            if(flag==1) sum=ope(sum,num,opp);
            else sum=num;
            printf("%d",ope(ans,sum,op));
            return 0;
        }
        else if(s[i]=='+')
        {
            if(flag==1) sum=ope(sum,num,opp);
            else sum=num;
            ans=ope(ans,sum,op);
            op='+';
            flag=0;
            num=0;
        }
        else if(s[i]=='-')
        {
            if(flag==1) sum=ope(sum,num,opp);
            else sum=num;
            ans=ope(ans,sum,op);
            op='-';
            flag=0;
            num=0;
        }
        else if(s[i]=='*')
        {
            if(flag==1) sum=ope(sum,num,opp);
            else sum=num;
            opp='*';
            flag=1;
            num=0;
        }
        else if(s[i]=='/')
        {
            if(flag==1) sum=ope(sum,num,opp);
            else sum=num;
            opp='/';
            flag=1;
            num=0;
        }
        else
        {
            num=10*num+s[i]-'0';
        }
    }
}