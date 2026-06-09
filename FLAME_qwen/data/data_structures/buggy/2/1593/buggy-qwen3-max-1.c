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
    gets(s); // @@ [Use of unsafe function 'gets' which is deprecated and removed in C11; causes compilation error with modern compilers]
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
            for(i+=1;Order(op[i])==2;i++) // @@ [Potential out-of-bounds access: when i reaches k-1, op[i] may be '\0' or undefined, and Order('\0') returns 0, but loop condition checks Order(op[i])==2 after incrementing i, which may exceed array bounds]
            {
                ans[m]=cal(ans[m],num[i+1],op[i]);
            }
            ope[m++]=op[i]; // @@ [After the inner for-loop, i may be >= k, so op[i] is out of valid range, leading to undefined behavior]
        }
        else if(Order(op[i])==2)
        {
            ans[m]=num[i];
            for(;Order(op[i])==2;i++) // @@ [Same issue: loop may increment i beyond k-1, causing access to op[k] or beyond, which is uninitialized or '\0']
            {
                ans[m]=cal(ans[m],num[i+1],op[i]);
            }
            ope[m++]=op[i]; // @@ [Again, op[i] may be out of bounds here]
        }
    }
    result = ans[0];
    for(int i = 0;i < m-1;i++) // @@ [If m is 0, this loop doesn't run, but if m>=1, ope has m elements? Logic mismatch: ope is filled with m++ after assignment, so ope indices go from 0 to m-1, but loop uses i < m-1, so last operator skipped? Also, ans has m+1 elements? Inconsistent indexing.]
    {
        result = cal(result,ans[i+1],ope[i]);
    }
    printf("%lld",result);
    return 0;
}