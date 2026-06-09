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
    gets(s); // @@ The use of gets is unsafe and deprecated; it may cause compilation error in modern compilers (e.g., with -Werror or C11/C17 standards).
    int i=0,j=0,ans=0,sum,k=0,flag=0,num=0;
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]!=' ')
        {
            s[j++]=s[i];
        }

    }
    s[j]='\0';
    puts(s); // @@ This line prints the stripped expression, which is not part of the required output. Only the integer result should be printed.
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