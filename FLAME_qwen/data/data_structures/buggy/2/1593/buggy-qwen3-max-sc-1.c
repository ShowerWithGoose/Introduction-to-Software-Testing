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
    gets(s); // @@ [Using `gets` is unsafe and deprecated; it was removed in C11 and causes compilation errors with modern compilers. Use `fgets` instead.]
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
            for(i+=1;Order(op[i])==2;i++) // @@ [This loop may access `op[i]` beyond valid bounds when `i` reaches `k-1` and then increments, leading to undefined behavior or incorrect parsing.]
            {
                ans[m]=cal(ans[m],num[i+1],op[i]);
            }
            ope[m++]=op[i]; // @@ [After the inner loop, `i` may be equal to `k`, so `op[i]` is out of bounds (since `op` has `k` elements indexed 0 to k-1).]
        }
        else if(Order(op[i])==2)
        {
            ans[m]=num[i];
            for(;Order(op[i])==2;i++) // @@ [Same issue: loop condition checks `Order(op[i])` after `i` might have reached `k`, causing out-of-bounds access.]
            {
                ans[m]=cal(ans[m],num[i+1],op[i]);
            }
            ope[m++]=op[i]; // @@ [Again, `i` may be `k` here, so `op[i]` is invalid.]
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