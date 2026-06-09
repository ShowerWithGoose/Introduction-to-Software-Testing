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
        printf("e-%d", cnt0+1); @@ [This logic incorrectly counts leading zeros and does not handle cases where all digits after decimal are zero; also fails to output anything if no non-zero digit is found (e.g., input "0.0")]
    }else if(str[1] == '.'){
        printf("%se0", str); @@ [This outputs the original string including the decimal point and trailing digits without removing unnecessary trailing zeros or adjusting format to have only one digit before decimal; e.g., "5.67e0" should be "5.67e0" but "5.e0" or "5.0e0" would be invalid per problem constraints]
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
        printf("e%d", i-1); @@ [This assumes there is always a decimal point in the input when str[0]!='0' and str[1]!='.', but if input has no decimal point (e.g., "123"), this loop runs indefinitely or accesses out-of-bound memory]
    }
    return 0;
}