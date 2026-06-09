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
    gets(s); // @@ [Using `gets` is unsafe and deprecated; it may cause buffer overflow. More critically, in many modern environments (like the test environment), `gets` is not available, leading to a compilation error because it was removed from the C standard library in C11.]
    Remove_Space();
    Convert_Int();
    ans[0]=num[0];
    for(int i = 0;i < k;i++)
    {
        if(Order(op[i])==1)
        {
            ans[m]=num[i];
            ope[m++]=op[i];
            ans[m]=num[i+1];
            for(i+=1;Order(op[i])==2;i++) // @@ [This loop condition accesses `op[i]` when `i` may be equal to `k`, which is out of bounds since `op` has valid indices from 0 to k-1. This leads to undefined behavior and potential runtime errors, but more importantly, combined with logic flaws, it causes incorrect parsing. However, the primary compilation issue is `gets`.]
            {
                ans[m]=cal(ans[m],num[i+1],op[i]);
            }
            ope[m++]=op[i]; // @@ [Here, `op[i]` is accessed after the inner loop exits, which likely occurs when `Order(op[i]) != 2`, but if the loop exited due to `i >= k`, then `op[i]` is out of bounds. Also, this line may store an invalid operator (like '=') into `ope`, causing further issues.]
        }
        else if(Order(op[i])==2)
        {
            ans[m]=num[i];
            for(;Order(op[i])==2;i++) // @@ [Same out-of-bounds access risk: when `i` reaches `k`, `op[i]` is invalid. The loop doesn't check `i < k` before accessing `op[i]`.]
            {
                ans[m]=cal(ans[m],num[i+1],op[i]);
            }
            ope[m++]=op[i]; // @@ [Again, `op[i]` may be out of bounds here. Additionally, the final character in the expression is '=', which is stored in `op` during `Convert_Int()`, so `Order('=')` returns 0, but this code still tries to process it as an operator.]
        }
    }
    result = ans[0];
    for(int i = 0;i < m-1;i++) // @@ [If `m` is 0, this loop doesn't run, but more critically, the logic for building `ans` and `ope` is flawed due to incorrect handling of the '=' terminator and operator precedence grouping, leading to wrong results. However, the immediate cause of compilation failure is `gets`.]
    {
        result = cal(result,ans[i+1],ope[i]);
    }
    printf("%lld",result);
    return 0;
}