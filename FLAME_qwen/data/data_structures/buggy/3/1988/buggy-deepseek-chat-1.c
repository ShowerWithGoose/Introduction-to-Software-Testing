#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
char str[10000];
int main() {
    scanf("%s", str);
    if(str[0] == '0'){
        int len = strlen(str), cnt1=0, cnt0=0;
        for(int i=2; i<len; i++){
            if(str[i]!='0'){
                cnt1++;
            }else{
                cnt0++;
            }
            if(cnt1 == 1){
                printf("%c", str[i]);
            }else if(cnt1 == 2){
                printf(".%c", str[i]);
            }else if(cnt1 > 1){
                printf("%c", str[i]);
            }
        }
        printf("e-%d", cnt0+1); // @@ [Error: The exponent calculation is incorrect. For numbers like 0.001, the exponent should be -3, but cnt0 counts zeros after the first non-zero digit, not the position of the first non-zero digit. Also, the loop logic for printing digits is flawed because it prints digits before determining the correct format.]
    }else if(str[1] == '.'){
        printf("%se0", str); // @@ [Error: This assumes the input has exactly one digit before the decimal point, but the problem allows numbers like "12.34" where str[1] is not '.'. Also, for numbers like "1.0" (though trailing zeros are not allowed per spec), this would incorrectly output "1.0e0" instead of "1e0".]
    }else{
        int i=0, len = strlen(str);
        while(str[i]!='.'){
            i++;
        }
        printf("%c.", str[0]);
        for(int j=1; j<len; j++){
            if(str[j]!='.'){
                printf("%c", str[j]);
            }
        }
        printf("e%d", i-1); // @@ [Error: The exponent calculation is wrong. For numbers like "123.45", i is the index of the decimal point (3), so i-1=2, but the correct exponent should be 2 (since 123.45 = 1.2345e2). However, for numbers like "1.23", i=1, i-1=0, which is correct. But the logic fails for numbers with multiple digits before the decimal point because it always uses str[0] as the first digit, which is correct, but the exponent should be the number of digits before the decimal point minus 1, which is i-1. Actually, this part is correct for the exponent, but the printing of digits after the decimal point includes all digits including trailing zeros, which violates the "no trailing zeros" rule. Also, it doesn't handle the case where the number is an integer (no decimal point) or where the result should be an integer (e.g., "100" should become "1e2", not "1.00e2").]
    }
    return 0;
}