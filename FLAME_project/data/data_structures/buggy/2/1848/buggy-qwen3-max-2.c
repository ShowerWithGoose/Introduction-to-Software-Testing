#include <stdio.h>
#include <string.h>


int main(){
    char s[500] = {0}, aft[500] = {0}, sign[500] = {0};
    long long num[500] = {0}, result[500] = {0};
    long long i = 0, k = 0, l = 0, len1 = 0, len = 0, hold = 0;
    gets(s);
    len1 = strlen(s);
    //先去掉空格
    for (i = 0; i < len1; i++)
    {
        if(s[i] != ' ')
        {
            aft[k] = s[i];
            k++;
        }
    }
    len = strlen(aft);
    k = 0;
    //将符号和数字分开 
    for(i = 0; i < len; i++)
    {
        if(aft[i] <= '9' && aft[i] >= '0')
        {
            num[k] = num[k] * 10 + aft[i] - '0';
        }//读取数值 
        else
        {
            sign[k] = aft[i];
            k++;
        }//读取符号 
    }
    l = 0;
    long long len_num = k;
    k = 0;
    hold = num[0] ;
    long long len_sign = strlen(sign);
    //先计算乘除，并将各部分结果存入result 
    for(i = 0; i < len_num; i++)
    {
        /*
        if(i = 0 && (sign[i] == '*' || sign[i] == '/'))
        hold = num[i];
        else if((sign[i-1] == '+' || sign[i-1] == '-') && (sign[i] == '*' || sign[i] == '/'))
        hold = num[i];
        先作废*/
        
        if(sign[i] == '*')
        {
            hold *= num[i+1];
        }
        else if(sign[i] == '/')
        {
            hold /= num[i+1];
        }
        else
        {
            result[k] = hold;
            k++;
            hold = num[i+1]; // @@ [When encountering '+' or '-', the current 'hold' is stored in result, but the next number (num[i+1]) must be assigned to 'hold' for the next segment. Without this, subsequent operations use stale or zero values.]
        }
    
    }
    //计算加减
    char sign_simple[500] = {0};
    for (i = 0; i < len_sign; i++)
    {
        if(sign[i] == '+' || sign[i] == '-')
        {
            sign_simple[l] = sign[i];
            l++;
        }
    }
    
    hold = result[0];
    for(i =0; sign_simple[i] != '\0'; i++)
    {
        if(sign_simple[i] == '+')
        hold += result[i+1]; // @@ [The loop uses result[i] instead of result[i+1]. Since result[0] is already used as initial 'hold', the first addition/subtraction should involve result[1], not result[0] again. This causes incorrect accumulation.]
        else if(sign_simple[i] == '-')
        hold -= result[i+1]; // @@ [Same as above: should use result[i+1] to align with the correct operand after the operator.]
     } 
     printf("%lld", hold);
    return 0;
}