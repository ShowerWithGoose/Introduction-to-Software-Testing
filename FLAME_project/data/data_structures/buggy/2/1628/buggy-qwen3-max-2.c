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
        
        if(ca=='+')    sum+=num[i-1];
        
        else if(ca=='-')
        {
            sum+=num[i-1];
            num[i]==0-num[i]; // @@ [Using '==' instead of '=' for assignment; this does not negate num[i], leading to incorrect handling of subtraction]
        }
        
        else if(ca=='*') num[i]*=num[i-1];
        
        else if(ca=='/')//正常乘除 
        {
            num[i-1]/=num[i];
            num[i]=num[i-1]; // @@ [Incorrectly overwrites num[i] with result of division from previous operands, disrupting order of operations and operand values for subsequent calculations]
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