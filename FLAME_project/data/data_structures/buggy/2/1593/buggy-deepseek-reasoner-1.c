#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


char s[5000],str[5000],op[5000],ope[5000];
int num[5000],ans[5000];
int k = 0,m = 0;

void Remove_Space()
{
    int j = 0;
    for(int i = 0;s[i]!='\0';i++)
    {
        if(s[i]!=' ')
        {
            str[j++]=s[i];
        }
    }
    str[j]='\0';
    return;
}

void Convert_Int()
{
    for(int i = 0;str[i]!='\0';i++)
    {
        if(isdigit(str[i]))
        {
            num[k]=num[k]*10+str[i]-'0';
        }
        else 
        {
            op[k]=str[i];
            k++;
        }
    }
    return;
}
int cal(int a,int b,char op)
{
    switch(op){
        case '+':
            return a+b;
            break;
        case '-':
            return a-b;
            break;
        case '*':
            return a*b;
            break;
        case '/':
            return a/b;
            break;    
    }
    return 0;
}
int Order(char op)
{
    if(op == '*'||op == '/')
    return 2;
    else if(op == '+'||op == '-')
    return 1;
    else
    return 0;
}
int main()
{
    long long result = 0;
    gets(s);
    Remove_Space();
    Convert_Int();
    ans[0]=num[0];
    for(int i = 0;i < k;i++)
    {
        if(Order(op[i])==1)
        {
            ans[m]=num[i]; // @@ Wrong: should use previous term result, not num[i]
            ope[m++]=op[i];
            ans[m]=num[i+1]; // @@ Wrong: right operand not computed from subsequent operations
            for(i+=1;Order(op[i])==2;i++) // @@ Wrong: i+=1 causes double increment; also inner loop may skip operators
            {
                ans[m]=cal(ans[m],num[i+1],op[i]); // @@ Wrong: indexing of num[i+1] may be incorrect due to previous i increments
            }
            ope[m++]=op[i];
        }
        else if(Order(op[i])==2)
        {
            ans[m]=num[i];
            for(;Order(op[i])==2;i++)
            {
                ans[m]=cal(ans[m],num[i+1],op[i]);
            }
            ope[m++]=op[i]; // @@ Wrong: this stores the operator that ends the chain, causing the operator to be processed as part of the previous term instead of starting a new term
        }
    }
    result = ans[0];
    for(int i = 0;i < m-1;i++)
    {
        result = cal(result,ans[i+1],ope[i]);
    }
    printf("%lld",result);
    return 0;
}