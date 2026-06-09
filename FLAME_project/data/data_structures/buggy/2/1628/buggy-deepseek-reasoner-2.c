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
        
        if(ca=='+')    sum+=num[i-1]; // @@ immediate addition without respecting operator precedence; should be deferred until after * and / are computed.
        
        else if(ca=='-')
        {
            sum+=num[i-1]; // @@ immediate addition of previous number; subtraction should not be performed here.
            num[i]==0-num[i]; // @@ comparison instead of assignment; also logic does not handle precedence.
        }
        
        else if(ca=='*') num[i]*=num[i-1]; // @@ immediate multiplication; should only be done after all * and / are processed in a separate pass.
        
        else if(ca=='/')//正常乘除 
        {
            num[i-1]/=num[i]; // @@ modifies num[i-1] in place, affecting later operations.
            num[i]=num[i-1]; // @@ sets num[i] to quotient, causing incorrect addition later.
        }    
        
        if(cal=='=') //如果出现等号 
        {
            sum+=num[i]; // @@ adds last number without considering its correct sign from preceding subtraction.
            break;
        }
        
        ca=cal;
        i++;
    }
    
    printf("%d",sum);
    
    return 0;
}