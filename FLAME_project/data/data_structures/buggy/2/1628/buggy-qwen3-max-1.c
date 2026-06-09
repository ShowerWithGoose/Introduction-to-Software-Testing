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
            num[i]==0-num[i]; // @@ [Using '==' instead of '=' for assignment; should be num[i] = -num[i]; also logic for handling subtraction is flawed]
        }
        
        else if(ca=='*') num[i]*=num[i-1]; // @@ [Incorrectly modifying current number with previous; should compute multiplication result and store appropriately without affecting future operations]
        
        else if(ca=='/')//正常乘除 
        {
            num[i-1]/=num[i]; // @@ [Incorrect order of operands: should be num[i-1] = num[i-1] / num[i], but then assigning result back to num[i] breaks sequence]
            num[i]=num[i-1]; // @@ [This overwrites current number with result of division, disrupting correct operator precedence and chaining]
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