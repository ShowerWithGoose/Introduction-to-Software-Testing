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
            hold = num[i+1]; // @@ [When encountering '+' or '-', the current 'hold' (which is the accumulated value for the current term) is stored in 'result', but the next term should start with num[i+1]. However, if the expression ends with '=', num[i+1] may be uninitialized or zero, and more critically, after storing 'hold', we must reset 'hold' to the next number. But this line is missing in the original code, causing incorrect accumulation. However, even with this fix, the loop logic is flawed because it doesn't properly handle the last number after the final operator. But the immediate error causing wrong answer is that after pushing 'hold' to result, 'hold' is not reset to the next number, so subsequent operations use stale 'hold'. Yet looking at the test case: 10 + 20 * 30 - 40 / 5 =, the real issue is that the algorithm processes operators left-to-right without respecting that multiplication/division should bind tighter. The current approach tries to do one-pass but fails because when it sees '+', it pushes current 'hold' (10) to result, then sets hold to next num (20). Then when it sees '*', it does hold=20*30=600. Then sees '-', pushes 600 to result, sets hold to 40. Then sees '/', does 40/5=8, then loop ends. But the '=' is not processed as an operator, so the final 'hold'=8 is never pushed to result. Thus result = [10, 600], and sign_simple = ['+', '-'], then it computes: hold = result[0]=10; i=0: '+' -> hold += result[0] => 10+10=20; i=1: '-' -> hold -= result[1] => 20-600=-580. But expected is 10 + (20*30) - (40/5) = 10+600-8=602. So two bugs: (1) the final term (8) is never added to result; (2) in the addition/subtraction loop, it uses result[i] instead of result[i+1]. Specifically, after splitting into terms, result should have 3 elements: [10, 600, 8], and sign_simple should have 2 signs: ['+', '-']. Then computation should be: result[0] + result[1] - result[2]. But the current addition loop does: hold = result[0]; then for i=0: if sign_simple[0]=='+', hold += result[0] (should be result[1]); for i=1: hold -= result[1] (should be result[2]). So the indexing in the final addition loop is off by one.]
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
        hold += result[i]; // @@ [This should be result[i+1] because result[0] is already used as the initial value. For example, with terms [a, b, c] and signs ['+', '-'], the calculation should be a + b - c. Here, hold starts as a, then for first sign '+', it should add b (result[1]), but it adds result[0] again. Similarly, for the next sign, it subtracts result[1] instead of result[2]. This off-by-one error causes incorrect results.]
        else if(sign_simple[i] == '-')
        hold -= result[i]; // @@ [Same as above: should be result[i+1]]
     } 
     printf("%lld", hold);
    return 0;
}