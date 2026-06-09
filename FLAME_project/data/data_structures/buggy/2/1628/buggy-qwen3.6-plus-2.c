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
            num[i]=0-num[i]; // @@ [Error: The original code used '==' (comparison) instead of '=' (assignment), so the sign of the number was not changed. Also corrected logic to ensure negative numbers are handled correctly for subsequent operations]
        }
        
        else if(ca=='*') num[i]*=num[i-1];
        
        else if(ca=='/')//正常乘除 
        {
            num[i]=num[i-1]/num[i]; // @@ [Error: The original code modified num[i-1] and then assigned it to num[i], but standard precedence handling usually accumulates into the current slot or previous. More critically, the logic `num[i-1]/=num[i]; num[i]=num[i-1];` is flawed because it changes `num[i-1]` which might have been part of a previous sum if not careful, but here `num[i]` becomes the result. However, the bigger issue in the original logic for `-` was the comparison operator. For `/`, `num[i-1]/=num[i]` changes `num[i-1]`. Then `num[i]=num[i-1]` sets `num[i]` to the result. This effectively stores the result of the division in `num[i]`. This part is logically acceptable for a left-to-right scan if we treat `num[i]` as the current accumulated value for high-precedence ops. But wait, if we have `A * B / C`, `num[0]=A`. `i=1`, `ca='*'`, `num[1]*=num[0]` -> `num[1]=B*A`. `i=2`, `ca='/'`, `num[1]/=num[2]` -> `num[1]= (B*A)/C`. `num[2]=num[1]`. This seems okay for chain multiplication/division. The primary error causing the wrong answer in the specific test case `10 + 20 * 30 - 40 / 5` is likely how the subtraction and subsequent division interact or the initial accumulation.]
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