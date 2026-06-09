#include <stdio.h>
#include <string.h>
#include <ctype.h>

int res = 0;

int bo(int a, char b, int c)
{
    if(b == '+')
    {
        return (a + c);
    }
    else if(b == '-')
    {
        return(a - c);
    }
    else if(b == '*')
    {
        return(a * c);
    }
    else
    {
        if(c != 0)
        {
            return(a/c);
        }    
    }
    
    return 0;
}

int main()
{
    //输入 
    char s[5000];
    int j = 0, i = 0;
    
    fgets(s,sizeof(s),stdin);
    
    //puts(s);
    
    //处理数字 

    int num1 = 0,res = 0;
    char op = '+';
    
    while(s[j] != '=')
    {        
        if((s[j] <='9') && (s[j] >= '0'))
        {
            num1 = num1 * 10 + (s[j] - '0');
            //while((s[j] <='9') && (s[j] >= '0'))
        }
        else if((s[j] == '*') || (s[j] == '/'))
        {
            op = s[j];
            int num2 = 0;
            
            for(i = j;i < strlen(s); i ++)
            {
                if((s[i] <='9') && (s[i] >= '0'))
                {
                    num2 = num2 * 10 + (s[i] - '0');
                }
                
                if((isdigit(s[i+1])) == 0) // @@ The loop termination condition is incorrect. It breaks when the next character is not a digit, but it should continue scanning until the end of the current number token. More importantly, this inner loop logic is flawed because it doesn't correctly skip spaces or handle the boundary of the number properly in the context of the outer loop's index `j`. The primary issue is that after calculating `num2`, `j` is set to `i`. If `i` stops at a non-digit (like space or operator), the outer loop increments `j`, potentially skipping the operator or misaligning. However, the critical logical error causing the wrong answer is that `num1` is updated with `*` or `/` immediately, but the accumulation of `res` for `+` and `-` happens only when `+` or `-` is encountered. The variable `op` stores the *previous* additive operator. When we encounter `*` or `/`, we update `num1` (the current term). But `op` is overwritten with `*` or `/` here: `op = s[j];`. This `op` is then used in `bo(num1, op, num2)`. This part is actually okay for the immediate calculation. The real bug is in how `j` is updated and how the next iteration proceeds. Let's look closer. If input is `10 + 20 * 30`, when `j` is at `*`, `num1` is 20. `num2` becomes 30. `num1` becomes 600. `j` becomes index of `0` in 30? No, `i` goes past 30. If `s[i+1]` is space, `isdigit` is 0, break. `i` is at last digit of 30. `j=i`. Then `j++` makes `j` point to space. Next iter: space is ignored? No, there is no `continue` for space. It falls through. `s[j]` is space. Not digit, not `* /`, not `+ -`. So nothing happens. `j++`. Eventually hits `=`. Then `res = bo(res, op, num1)`. What is `op`? It was set to `*` inside the block. But `res` was 10 (from `10 + ...`? No. Initially `res=0, op='+', num1=0`. `j=0` '1': num1=1. `j=1` '0': num1=10. `j=2` ' ': nothing. `j=3` '+': `res = bo(0, '+', 10)` -> 10. `num1=0`. `op='+'`. Wait, `op` becomes `+`. `j=4` ' ': nothing. `j=5` '2': num1=2. `j=6` '0': num1=20. `j=7` ' ': nothing. `j=8` '*': enters `*` block. `op='*'`. `num2` scans 30. `num1 = bo(20, '*', 30)` -> 600. `j` set to index of '0' in 30 (say idx 9). `j++` -> 10 (space). `j=10` ' ': nothing. `j=11` '-': enters `-` block. `res = bo(10, '*', 600)`? NO. `op` is currently `*` because it was updated in the `*` block. So `res = bo(10, '*', 600)` -> 6000. This is wrong. `op` should represent the pending additive operator. When we process `*` or `/`, we are modifying the current term `num1`. We should NOT update `op` to `*` or `/` because `op` is used to combine the previous `res` with the current `num1` when a new `+` or `-` is found. The variable `op` should only be updated when `+` or `-` is encountered.
            {
                break;
            }
            j = i;    
                
            num1 = bo(num1,op,num2); // @@ Logic Error: 'op' was incorrectly updated to '*' or '/' above. It should retain the previous additive operator ('+' or '-'). The multiplication/division should apply to 'num1' directly, not using 'op' which is meant for additive accumulation. Also, 'op' should not be changed here.
            
        }
        else if((s[j] == '+') || (s[j] == '-'))
        {
            res = bo(res,op,num1);
            num1 = 0;
            op = s[j];
        }
        j ++;
    }
    
    res = bo(res,op,num1);
    
    printf("%d",res);

    return 0;
}