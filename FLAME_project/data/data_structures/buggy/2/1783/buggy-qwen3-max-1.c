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
    gets(s);
    int i=0,j=0,ans=0,sum,k=0,flag=0,num=0;
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]!=' ')
        {
            s[j++]=s[i];
        }

    }
    s[j]='\0';
    puts(s); // @@ [This outputs the processed expression to stdout, which is not required by the problem and causes extra output. The problem only requires the final result.]
    char op='+',c,opp;
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]=='=')
        {
            if(flag==1) sum=ope(sum,num,opp);
            else sum=num;
            printf("%d",ope(ans,sum,op)); // @@ [The function 'ope' is designed to apply an operator between 'ans' and 'sum', but here 'op' is the last top-level operator (e.g., '+' or '-'), and 'sum' already includes the result of multiplicative operations. However, the logic incorrectly applies 'op' again in a way that doesn't match standard operator precedence handling. Also, integer division truncation is correct, but the overall evaluation order is flawed.]
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