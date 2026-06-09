#include<stdio.h>
int num[500005];

int main() 
{
    int sum=0;
    
    char cal,ca='=';//运算符号 
    
    int i=0;//记录第几个数字 
    
    while(scanf("%d %c",&num[i],&cal)!=EOF)
    {
        if(cal!='='&&i==0) 
        {
            ca=cal;
            i++;
            continue;
        }
        
        if(ca=='+')    sum+=num[i-1]; // @@ Premature addition: '+' operators are applied immediately without waiting for higher-precision '*' and '/' operators, causing incorrect order of operations.
        
        else if(ca=='-')
        {
            sum+=num[i-1]; // @@ Premature addition: the subtraction operator adds the previous number to sum before handling subsequent '*' and '/' operators, leading to wrong result.
            num[i]==0-num[i]; // @@ Syntax error: uses '==' (comparison) instead of '=' (assignment). Even if corrected, the logic of negating the current number is not sufficient to handle precedence correctly.
        }
        
        else if(ca=='*') num[i]*=num[i-1];
        
        else if(ca=='/')//正常乘除 
        {
            num[i-1]/=num[i];
            num[i]=num[i-1];
        }    
        
        if(cal=='=') //如果出现等号 
        {
            sum+=num[i];
            break;
        }
        
        ca=cal;
        i++;
    }
    
    printf("%d",sum);
    
    return 0;
}