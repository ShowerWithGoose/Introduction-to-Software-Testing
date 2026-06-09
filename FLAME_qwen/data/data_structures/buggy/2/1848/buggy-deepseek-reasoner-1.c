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
            num[k] = num[k] * 10 + aft[i] - '0'; // @@ The index k is not incremented when digits are read; it should correspond to the current number index, but here k is only updated on operators, causing misalignment between num and sign arrays.
        }//读取数值 
        else
        {
            sign[k] = aft[i]; // @@ This stores the '=' terminator as an operator, which is invalid. Also, the '=' should be recognized as end of input, not processed as an operator.
            k++;
        }//读取符号 
    }
    l = 0;
    long long len_num = k; // @@ len_num is set to the number of operators, but the number of numbers should be one more than the number of operators (excluding the '='). This causes incorrect iteration bounds later.
    k = 0;
    hold = num[0] ; // @@ If the expression starts with a sign (e.g., "-5"), num[0] is not the first number; it may be zero or uninitialized. Also, for expressions starting with a digit, this is okay, but the logic is fragile.
    long long len_sign = strlen(sign);
    //先计算乘除，并将各部分结果存入result 
    for(i = 0; i < len_num; i++) // @@ Loop condition uses len_num (operator count) but accesses num[i+1] which may be out of bounds when i becomes len_num-1 because num arrays has len_num+1 entries due to misalignment. Also, the loop does not correctly handle precedence across multiplicative ops separated by additive ops.
    {
        /*
        if(i = 0 && (sign[i] == '*' || sign[i] == '/'))
        hold = num[i];
        else if((sign[i-1] == '+' || sign[i-1] == '-') && (sign[i] == '*' || sign[i] == '/'))
        hold = num[i];
        先作废*/
        
        if(sign[i] == '*')
        {
            hold *= num[i+1]; // @@ hold accumulates sequentially, but for expressions like "2*3*4" it might compute 2*3=6, then 6*4=24, which is correct, but if additive ops intervene, the logic fails because hold is carried over incorrectly. Also, num[i+1] may be out of bounds.
        }
        else if(sign[i] == '/')
        {
            hold /= num[i+1]; // @@ Same issue as above.
        }
        else
        {
            result[k] = hold; // @@ hold is stored but after processing only consecutive * and /, but it doesn't reset hold properly for a new additive segment. Also, k is not reset, so result indices may be overwritten.
            k++;
        }
    
    }
    //计算加减
    char sign_simple[500] = {0};
    for (i = 0; i < len_sign; i++) // @@ len_sign includes the '=' character, which is not a valid operator. This loop should only process '+' and '-', but it iterates over all characters in sign, including '=' (which does nothing because it's not added to sign_simple, but the loop still runs over it).
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
        hold += result[i]; // @@ The result array indexing may be off because result was populated based on incorrect loop logic.
        else if(sign_simple[i] == '-')
        hold -= result[i];
     } 
     printf("%lld", hold);
    return 0;
}