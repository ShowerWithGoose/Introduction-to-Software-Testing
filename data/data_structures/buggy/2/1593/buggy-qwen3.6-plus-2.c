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
    gets(s); // @@ [gets is deprecated and removed in C11, causing compilation errors in modern compilers; use fgets instead]
    Remove_Space();
    Convert_Int();
    ans[0]=num[0];
    for(int i = 0;i < k;i++) // @@ [The evaluation loop logic is fundamentally flawed; it incorrectly manages indices i and m, causing numbers after * or / chains to be skipped]
    {
        if(Order(op[i])==1)
        {
            ans[m]=num[i]; // @@ [Incorrectly maps num indices to ans indices without accounting for consumed high-precedence operations, leading to misaligned data]
            ope[m++]=op[i];
            ans[m]=num[i+1];
            for(i+=1;Order(op[i])==2;i++) // @@ [Modifying the outer loop variable i inside the inner loop header causes index misalignment and skips subsequent operators/numbers]
            {
                ans[m]=cal(ans[m],num[i+1],op[i]);
            }
            ope[m++]=op[i];
        }
        else if(Order(op[i])==2) // @@ [Fails to store the subsequent number for low-precedence operations after processing a * or / chain, resulting in data loss]
        {
            ans[m]=num[i];
            for(;Order(op[i])==2;i++) // @@ [Similar index misalignment issue; the loop consumes operators but does not properly queue the next operand for final evaluation]
            {
                ans[m]=cal(ans[m],num[i+1],op[i]);
            }
            ope[m++]=op[i];
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