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
        printf("e-%d", cnt0+1); // @@ The exponent calculation is incorrect. For numbers like 0.001, the exponent should be -3, but cnt0 counts zeros after the first non-zero digit, leading to wrong exponent. Also, the loop logic for printing digits is flawed; it does not handle cases where there are no non-zero digits after the decimal point (e.g., 0.0) or when the number is exactly 0.
    }else if(str[1] == '.'){
        printf("%se0", str); // @@ This incorrectly handles numbers like 1.0 or 1.00, which should be output as 1e0 (integer base) or 1.0e0 (decimal base) according to the problem. The problem requires no trailing zeros, so 1.0 should become 1e0, not 1.0e0. Also, for numbers like 12.34, this branch is not taken, but the else branch below handles it.
    }else{
        int i=0, len = strlen(str);
        while(str[i]!='.'){
            i++;
        }
        printf("%c.", str[0]); // @@ This always prints a decimal point after the first digit, even if the number is an integer (e.g., 123 should become 1.23e2, but 100 should become 1e2, not 1.00e2). The problem requires that if the base is an integer (only one significant digit), no decimal point should be printed.
        for(int j=1; j<len; j++){
            if(str[j]!='.'){
                printf("%c", str[j]);
            }
        }
        printf("e%d", i-1); // @@ The exponent calculation is incorrect for numbers like 12.34 (should be 1.234e1, but i-1 gives 1, which is correct), but for numbers like 100 (input as 100.), the while loop will not find a '.' and will go out of bounds. Also, trailing zeros are not removed; e.g., 100 should output 1e2, not 1.00e2.
    }
    return 0;
}