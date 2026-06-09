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
                printf("%c", str[i]); // @@ Prints only the first non-zero digit; misses the decimal point that should follow immediately, and ignores subsequent zeros.
            }else if(cnt1 == 2){
                printf(".%c", str[i]); // @@ Inserts dot before the second non-zero instead of after the first; also ignores zeros between non-zero digits.
            }else if(cnt1 > 1){
                printf("%c", str[i]); // @@ Prints only non-zero digits, skipping zeros that are significant between non-zero digits.
            }
        }
        printf("e-%d", cnt0+1); // @@ Exponent calculation uses total zeros (cnt0) instead of leading zeros only, producing wrong exponent.
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