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
            num[i]==0-num[i]; // @@ 错误：此处应为赋值语句 `num[i] = 0 - num[i];` 而非比较运算符 `==`，导致无法正确将当前数字取反。
        }
        
        else if(ca=='*') num[i]*=num[i-1]; // @@ 错误：乘除运算未考虑优先级，直接修改 num[i] 会导致后续索引混乱，应使用临时变量累积乘除结果。
        
        else if(ca=='/')//正常乘除 
        {
            num[i-1]/=num[i];
            num[i]=num[i-1]; // @@ 错误：除法处理方式错误，应保持与乘法类似的累积机制，而非修改前一个元素并复制。
        }    
        
        if(cal=='=') //如果出现等号 
        {
            sum+=num[i]; // @@ 错误：此处累加的最后数字可能已被之前错误逻辑修改，且未正确处理所有运算符的优先级。
            break;
        }
        
        ca=cal;
        i++;
    }
    
    printf("%d",sum);
    
    return 0;
}