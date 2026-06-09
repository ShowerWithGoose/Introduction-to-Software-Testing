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
            num[i]==0-num[i]; // @@ [Error: This line uses '==' (comparison) instead of '=' (assignment). It should be num[i] = 0 - num[i]; to correctly negate the number for subtraction.]
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