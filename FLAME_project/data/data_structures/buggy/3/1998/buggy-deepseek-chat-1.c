#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define ll long long
char s[200];
int dot=0,flag=0,wa=0,sum=1;
int main(){
    gets(s);
    int len=strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]=='.')dot=i;
        if(dot>0){
            if(s[i]!='0')flag=1;
            if(!flag&&s[i]=='0')sum++; // @@ Error: sum counts leading zeros after decimal point, but the logic is flawed. For input "0.00000009123456789012", sum becomes 8 (including the '9'? Actually it counts zeros until a non-zero, but sum starts at 1 and increments for each zero, so sum=8 for the 7 zeros after decimal before '9', but the exponent should be -8, not -7. Also, the condition `if(dot>0)` is always true after dot is set, but the loop continues, causing sum to count incorrectly when there are zeros before the decimal point.
        }
    }
    if(dot==1&&s[0]!='0'){ // @@ Error: This condition incorrectly handles cases where the number has one digit before decimal and is non-zero, but it outputs the whole string with "e0", which is wrong for numbers like "1.23" (should be "1.23e0" but the format requires one digit before decimal, which is correct, but the output format may be wrong if there are trailing zeros? Actually the problem says no trailing zeros, so this might be okay, but the logic is incomplete for other cases.
        printf("%se0",s);
    }
    else{
        if(s[0]=='0'){
            for(int i=dot+sum;i<len;i++){ // @@ Error: dot+sum is used as the starting index, but sum is miscalculated. For "0.00000009123456789012", dot=1, sum=8, so dot+sum=9, which points to '9', but the loop prints from '9' onwards, missing the leading '9'? Actually it prints '9' first, then '.' after, but the output should be "9.123456789012e-8". The exponent sum is 8, but should be 8? Wait, the number of leading zeros after decimal is 7, so exponent should be -8 (since 0.000000091... = 9.1...e-8). sum=8 gives e-8, which is correct, but the loop prints from index 9, which is '9', then prints '.' after it, then continues printing '1','2',... but the output in the buggy output shows "0.0000009123456789012e-1", which is completely different. The buggy output from the first program is shown, not this one. This program's logic is also flawed.
                if(s[i]!='.')
                printf("%c",s[i]);
                if(i==dot+sum&&i!=len-1)printf("."); // @@ Error: This prints a decimal point after the first digit, but the condition `i==dot+sum` is true only for the first iteration, so it prints '.' after the first digit, which is correct for scientific notation base, but the exponent calculation is wrong.
            }
            printf("e-%d",sum); // @@ Error: sum is used as exponent, but for input "0.00000009123456789012", sum=8, so exponent is -8, which is correct, but the output from this program would be "9.123456789012e-8" if the loop worked correctly. However, the buggy output shown is from the first program, not this one. This program has its own errors.
        }
        else{
            for(int i=0;i<len;i++){
                if(s[i]!='.'){
                    printf("%c",s[i]); 
                }
                if(i==0)printf("."); // @@ Error: This prints a decimal point after the first digit, but for numbers like "123.45", it would print "1.2345e2", which is correct, but the exponent calculation `dot-1` is wrong if there are leading zeros? Actually for "123.45", dot=3, so exponent is 2, correct. But the loop prints all digits including the decimal point? It skips the original decimal point, so it prints "12345" with a '.' after the first digit, giving "1.2345", then "e2". That seems correct for that case. However, the logic fails for numbers like "0.001" because it goes to the else branch? No, s[0]=='0' so it goes to the first branch.
            }
            printf("e%d",dot-1);
        }
    }
    return 0;
}