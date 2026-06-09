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
                cnt0++; // @@ Incorrectly counts all zeros in the fractional part, including those after the first significant digit, leading to an incorrect exponent.
            }
            if(cnt1 == 1){
                printf("%c", str[i]);
            }else if(cnt1 == 2){
                printf(".%c", str[i]);
            }else if(cnt1 > 1){
                printf("%c", str[i]);
            }
        }
        printf("e-%d", cnt0+1); // @@ The exponent calculation relies on cnt0, which is flawed. It should only count leading zeros before the first non-zero digit.
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