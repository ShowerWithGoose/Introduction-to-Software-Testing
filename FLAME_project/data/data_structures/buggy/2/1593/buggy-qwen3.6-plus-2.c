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
            op[k]=str[i]; // @@ The operator '=' is stored in the op array, but it should be ignored or handled as a terminator. The loop condition in main relies on 'k' which counts all operators including '=', leading to processing beyond valid numbers.
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
    for(int i = 0;i < k;i++) // @@ The loop runs up to k, which includes the index of the '=' operator. This causes out-of-bounds access or incorrect processing when i reaches the last operator which is '='.
    {
        if(Order(op[i])==1)
        {
            ans[m]=num[i];
            ope[m++]=op[i];
            ans[m]=num[i+1];
            for(i+=1;Order(op[i])==2;i++) // @@ The inner loop increments i, and the outer loop also increments i. This logic is flawed for handling precedence correctly and skipping processed tokens. It also risks accessing op[i] where i might be equal to k (the '=' operator), returning Order 0, stopping the loop, but then the outer loop continues incorrectly.
            {
                ans[m]=cal(ans[m],num[i+1],op[i]);
            }
            ope[m++]=op[i]; // @@ This stores the operator that broke the inner loop (likely low precedence or '='). If it was '=', this is invalid. Also, m is incremented, adding an extra operator/operand pair potentially misaligned with the final summation logic.
        }
        else if(Order(op[i])==2)
        {
            ans[m]=num[i];
            for(;Order(op[i])==2;i++)
            {
                ans[m]=cal(ans[m],num[i+1],op[i]);
            }
            ope[m++]=op[i]; // @@ Similar issue: stores the operator that terminated the sequence. If the sequence ends because of a lower precedence operator or '=', this logic fails to properly separate terms for the final addition/subtraction phase.
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