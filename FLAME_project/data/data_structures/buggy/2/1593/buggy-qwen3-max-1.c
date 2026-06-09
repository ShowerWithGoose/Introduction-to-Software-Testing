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
    Convert_Int(); // @@ [The Convert_Int function does not reset num[k] to 0 before accumulating digits, so if multiple numbers are parsed, leftover values from previous iterations (or uninitialized values) may corrupt the current number. Also, it assumes that every non-digit is an operator and stores it immediately, but doesn't handle the final '=' correctly—it includes '=' as an operator in op[], which breaks logic later.]
    ans[0]=num[0]; // @@ [This assumes at least one number exists, but more critically, num[0] may be corrupted due to missing initialization in Convert_Int.]
    for(int i = 0;i < k;i++) // @@ [Loop condition uses k (number of operators including '='), but op[k-1] is '=', which has Order('=') = 0, causing unexpected behavior in the loop body.]
    {
        if(Order(op[i])==1)
        {
            ans[m]=num[i]; // @@ [Uses num[i], but num array indexing doesn't align with operator indexing—num has (k+1) numbers, but this accesses num[i] where i is operator index, leading to off-by-one errors.]
            ope[m++]=op[i];
            ans[m]=num[i+1];
            for(i+=1;Order(op[i])==2;i++) // @@ [This inner loop increments i, which affects the outer loop's i, potentially skipping operators or going out of bounds. Also, when op[i] is '=', Order returns 0, so loop exits, but then ope[m++]=op[i] stores '=' as an operator.]
            {
                ans[m]=cal(ans[m],num[i+1],op[i]);
            }
            ope[m++]=op[i]; // @@ [Stores '=' as an operator in ope[], which will later be used in final evaluation, causing undefined behavior in cal().]
        }
        else if(Order(op[i])==2)
        {
            ans[m]=num[i]; // @@ [Again, incorrect indexing: num[i] corresponds to the i-th number, but i is operator index; should be num[m] or similar.]
            for(;Order(op[i])==2;i++)
            {
                ans[m]=cal(ans[m],num[i+1],op[i]);
            }
            ope[m++]=op[i]; // @@ [Same issue: stores '=' as operator when loop exits on '='.]
        }
    }
    result = ans[0];
    for(int i = 0;i < m-1;i++) // @@ [If ope contains '=', then cal() will be called with op='=', which returns 0, corrupting the result. Also, m may be overcounted due to storing '='.]
    {
        result = cal(result,ans[i+1],ope[i]);
    }
    printf("%lld",result);
    return 0;
}