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
    Convert_Int(); @@ [The Convert_Int function does not reset num[k] to 0 before accumulating digits, causing incorrect number parsing when multiple numbers are present.]
    ans[0]=num[0]; @@ [This assumes at least one number exists, but more critically, the logic that follows does not correctly handle operator precedence and grouping of terms.]
    for(int i = 0;i < k;i++)
    {
        if(Order(op[i])==1)
        {
            ans[m]=num[i]; @@ [Incorrectly assigns num[i] instead of handling the current accumulated value or sign correctly.]
            ope[m++]=op[i];
            ans[m]=num[i+1]; @@ [Assumes next number is num[i+1], but fails to account for multi-operator sequences or correct term boundaries.]
            for(i+=1;Order(op[i])==2;i++)
            {
                ans[m]=cal(ans[m],num[i+1],op[i]); @@ [Accesses num[i+1] which may be out of sync with actual parsed numbers due to flawed indexing.]
            }
            ope[m++]=op[i]; @@ [May access op[i] beyond valid range after loop exit, especially near '='.]
        }
        else if(Order(op[i])==2)
        {
            ans[m]=num[i]; @@ [Same issue: uses num[i] as starting value, but should start from previous term or handle unary minus.]
            for(;Order(op[i])==2;i++)
            {
                ans[m]=cal(ans[m],num[i+1],op[i]); @@ [Again accesses num[i+1] incorrectly; indexing between ops and nums is mismatched.]
            }
            ope[m++]=op[i]; @@ [Potential out-of-bound access to op array.]
        }
    }
    result = ans[0];
    for(int i = 0;i < m-1;i++)
    {
        result = cal(result,ans[i+1],ope[i]); @@ [Final accumulation assumes all terms in ans[] are independent operands, but they were computed with inconsistent indexing and missing handling of leading signs or term separation.]
    }
    printf("%lld",result);
    return 0;
}