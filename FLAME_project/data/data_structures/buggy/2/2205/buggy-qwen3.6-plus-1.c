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
            result += flag * num1; // @@ The logic fails to handle operator precedence correctly. When encountering '+' or '-', it adds the current accumulated 'num1' to 'result'. However, if 'num1' was part of a pending multiplication or division chain that hasn't been fully resolved because the next operator is lower precedence, this is okay. But the main issue is how 'num1' is reset and how the final term is handled. Specifically, for input "10 + 20 * 30 - 40 / 5 =", when '-' is encountered, 'num1' holds 600 (20*30). It adds 600 to result. Then flag becomes -1. Then '40' is read. Then '/' is encountered, cnt=2. Then '5' is read. Loop ends or hits '='. The final 'result += num1' adds the last term. But wait, look at the trace.
            // Trace: 
            // i=0, reads 10. cnt=0 -> num1=10. s[2]='+'. Case '+': result += 1*10 => result=10. num1=0. flag=1.
            // i=3, reads 20. cnt=0 -> num1=20. s[5]='*'. Case '*': cnt=1.
            // i=6, reads 30. cnt=1 -> num1 *= 30 => num1=600. cnt=0. s[8]='-'. Case '-': result += 1*600 => result=610. num1=0. flag=-1.
            // i=9, reads 40. cnt=0 -> num1=40. s[11]='/'. Case '/': cnt=2.
            // i=12, reads 5. cnt=2 -> num1 /= 5 => num1=8. cnt=0. s[13]='='. Break.
            // After loop: result += num1 => result = 610 + 8 = 618.
            // Expected: 10 + 600 - 8 = 602.
            // The error is that `flag` is applied to `num1` only when adding to `result` inside the switch for '+' or '-'. 
            // In the step `result += flag * num1`, for the minus case, it adds `1 * 600` because flag was still 1 from the previous plus operation? No, flag is set to -1 AFTER adding.
            // Let's re-trace carefully.
            // Start: result=0, flag=1.
            // Read 10. num1=10. Hit '+'. result += 1*10 = 10. flag=1.
            // Read 20. num1=20. Hit '*'. cnt=1.
            // Read 30. num1=600. Hit '-'. result += 1*600 = 610. flag=-1.
            // Read 40. num1=40. Hit '/'. cnt=2.
            // Read 5. num1=8. Hit '='. Break.
            // End: result += num1. Here num1 is 8. But what sign should it have? It should be subtracted.
            // The code does `result += num1` which is `610 + 8 = 618`.
            // It should be `result += flag * num1` which would be `610 + (-1)*8 = 602`.
            // So the final addition outside the loop ignores the `flag`.
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
    result += num1; // @@ This line ignores the 'flag' variable. If the last operation was preceded by a minus sign (stored in flag), the last number 'num1' should be subtracted, not added. It should be 'result += flag * num1;'.
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