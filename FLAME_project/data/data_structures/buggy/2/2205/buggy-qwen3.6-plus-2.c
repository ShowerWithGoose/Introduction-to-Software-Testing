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
            num1 *= temp;
            cnt = 0;
            break;
        case 2:
            num1 /= temp;
            cnt = 0;
            break;        
        }
        temp = 0;
        switch (s[i]){
        case '+':
            result += flag * num1; // @@ The logic fails to handle operator precedence correctly. When encountering '+' or '-', it adds the current accumulated 'num1' to 'result'. However, if 'num1' was part of a pending multiplication or division chain that hasn't been fully resolved relative to previous additions, or if the logic for deferring addition/subtraction is flawed, the result will be wrong. Specifically, this approach tries to handle * and / immediately via 'cnt', but it applies them to 'num1' which accumulates. The critical error is that when we hit '+' or '-', we add 'flag * num1' to result. But 'num1' might have been modified by a previous '*' or '/'. The real issue is simpler: the variable 'flag' is applied to 'num1' only when adding to result. If we have 10 + 20 * 30, 'num1' becomes 10. Then '+', result += 1*10 (result=10), num1=0, flag=1. Then '20', num1=20. Then '*', cnt=1. Then '30', num1 *= 30 -> num1=600, cnt=0. Then '-', result += 1*600 (result=610), num1=0, flag=-1. Then '40', num1=40. Then '/', cnt=2. Then '5', num1 /= 5 -> num1=8, cnt=0. End of loop. result += num1 -> 610 + 8 = 618. The expected is 10 + 600 - 8 = 602. The error is that the sign 'flag' for the term '40/5' was set to -1, but in the final step 'result += num1', the flag is not applied.
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
    result += num1; // @@ The final term 'num1' is added without applying the current 'flag'. In the example 10 + 20 * 30 - 40 / 5, the last term is 40/5=8. The flag was set to -1 by the '-' operator. So it should be result += (-1) * 8. Here it adds 8 directly, leading to 618 instead of 602.
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