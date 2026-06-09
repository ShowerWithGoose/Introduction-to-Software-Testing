#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int calculate(char s[]){
    int result = 0, cnt = 0, temp = 0, num1 = 0, flag = 1;
    for(int i = 0;s[i] != '\0'; i++){        
        while(s[i] >= '0'&& s[i] <= '9'){
            temp = 10*temp + s[i] - '0';
            i++;
        }
        switch (cnt)
        {
        case 0:
            num1 = temp;
            
            break;
        case 1:
            num1 *= temp; // @@ Error: This performs multiplication immediately when encountering '*' or '/', but does not handle operator precedence correctly when multiple '*' or '/' appear consecutively. For example, in "20 * 30", it works, but in "40 / 5", it also works, but the issue is that the logic does not accumulate results properly when there are multiple '*' or '/' in sequence without resetting num1 correctly for the next operation.
            cnt = 0;
            break;
        case 2:
            num1 /= temp; // @@ Error: Same issue as above; integer division is performed immediately, but the logic fails to handle cases where multiplication and division are mixed with addition/subtraction in a single pass without proper precedence handling.
            cnt = 0;
            break;        
        }
        temp = 0;
        switch (s[i]){
        case '+':
            result += flag * num1;
            num1 = 0;
            flag = 1;
            break;
        case '-':
            result += flag * num1;
            num1 = 0;           
            flag = -1;
            break;
        case '*':
            cnt = 1;
            break;
        case '/':
            cnt = 2;
            break;    
        }
    if(s[i] == '=')
        break;    
    }
    result += num1; // @@ Error: This adds the last num1 to result, but due to incorrect handling of consecutive '*' and '/' operations, num1 may not hold the correct value. For example, in "10 + 20 * 30 - 40 / 5", after processing "20 * 30", num1 becomes 600, then when encountering '-', result gets 10 + 600 = 610, but then num1 is reset to 0, and flag becomes -1. Then "40 / 5" sets num1 to 8, and at the end result += num1 gives 610 + 8 = 618, which is wrong because the subtraction should be 610 - 8 = 602. The error is that the subtraction is not applied correctly because the logic treats '-' as a sign for the next number rather than accumulating the result with the correct sign.
    return result;
}
int main()
{
    char str1[1000];
    int len = 0;
    fgets(str1, 900, stdin);
    for(int i = 0; str1[i] != '\0'; i++){
        if(str1[i] != ' '){
            str1[len++] = str1[i];
        }
    }
    str1[len] = '\0';
    printf("%d\n", calculate(str1));
    //puts(str1);

    system("pause");
    return 0;
}