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
                printf("%c", str[i]); // @@ Logic error: prints only the first non-zero digit, but fails to include zeros that appear after it before the second non-zero digit.
            }else if(cnt1 == 2){
                printf(".%c", str[i]); // @@ Logic error: places decimal point before the second non-zero digit instead of after the first digit.
            }else if(cnt1 > 1){
                printf("%c", str[i]); // @@ Logic error: prints digits without a decimal point, but the base should have a decimal point after the first digit.
            }
        }
        printf("e-%d", cnt0+1); // @@ Logic error: exponent counts all zeros after decimal, including those after the first non-zero digit; should be based on the index of the first non-zero digit.
    }else if(str[1] == '.'){
        printf("%se0", str);
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
        printf("e%d", i-1);
    }
    return 0;
}