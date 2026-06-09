#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 

int main(){
    int num = 0, num1, num2;
    char flag1 = '+', flag2;

    scanf("%d", &num1);//œ»∏≥÷µnum1
    while(1){
        scanf(" %c", &flag2); // @@ [Missing space before %c causes reading of leftover whitespace/newline instead of the next operator]
        if(flag2 == '='){
            if(flag1 == '+'){
                num += num1;
            }
            else{
                num -= num1;
            }
            break;
        }
        scanf("%d", &num2);
        if(flag2 == '+' || flag2 =='-'){
            if(flag1 == '+'){
                num += num1;
            }
            else{
                num -= num1;
            }
            num1 = num2;
            flag1 = flag2;
        }
        else{
            if(flag2 == '*'){
                num1 *= num2;
            }
            else{
                if(num2 != 0)
                    num1 /= num2;
                // @@ [Division by zero is checked, but problem states expression is always valid, so this check is unnecessary; however, more critically, when flag2 is '/', and num2 is negative, integer division in C truncates toward zero, which matches requirement. But the real issue is that the logic fails to handle sequences like "5 - 1 * 2" correctly because it doesn't account for operator precedence across multiple terms properly in all cases. However, the primary bug causing incorrect output is the missing space in scanf for char input.]
            }
        }
    } 
    printf("%d\n", num);
    return 0;
}