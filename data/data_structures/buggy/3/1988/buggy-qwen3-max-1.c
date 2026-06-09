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
        printf("e-%d", cnt0+1); @@ [This logic incorrectly counts leading zeros as cnt0 and uses it for exponent; also fails when input is "0.0" or has no non-zero digits after decimal]
    }else if(str[1] == '.'){
        printf("%se0", str); @@ [This prints the entire original string including the decimal point and all digits, violating scientific notation format which requires only one digit before decimal and possibly one after]
    }else{
        int i=0, len = strlen(str);
        while(str[i]!='.'){ @@ [If input has no decimal point (though problem states it does), this loop may run out of bounds; but more critically, the logic assumes there is always a decimal point]
            i++;
        }
        printf("%c.", str[0]);
        for(int j=1; j<len; j++){
            if(str[j]!='.'){
                printf("%c", str[j]);
            }
        }
        printf("e%d", i-1); @@ [Exponent calculation is incorrect: for "123.45", i=3, so exponent=2 which is correct, but the mantissa printed is "1.2345" which is wrong—it should be "1.2345" only if we remove the decimal properly, but the code includes all digits including those before original decimal beyond first]
    }
    return 0;
}