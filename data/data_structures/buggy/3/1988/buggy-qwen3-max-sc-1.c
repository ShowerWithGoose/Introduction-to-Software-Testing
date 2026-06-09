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
        printf("e-%d", cnt0+1); @@ [The exponent calculation is incorrect. It counts leading zeros as cnt0 but doesn't account for the position correctly. Also, if all digits after decimal are zero (which shouldn't happen per problem statement), this logic fails. Moreover, it doesn't handle the case where only one non-zero digit exists after decimal point properly (should not print decimal point in that case).]
    }else if(str[1] == '.'){
        printf("%se0", str); @@ [This prints the original number with "e0", but per output format, if there's only one digit before decimal and it's non-zero, it should be printed without decimal point (e.g., "5e0", not "5.e0" or "5.0e0"). Also, trailing zeros after decimal should be removed, but this prints the whole input string.]
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
        printf("e%d", i-1); @@ [This always prints a decimal point even when there's only one significant digit (e.g., input "5.0" should output "5e0", not "5.e0"). Also, it doesn't remove trailing zeros after the decimal point, violating the requirement that there are no trailing zeros in the base part.]
    }
    return 0;
}