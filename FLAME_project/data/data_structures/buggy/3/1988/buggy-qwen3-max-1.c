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
        printf("e-%d", cnt0+1); @@ // The exponent calculation is incorrect. For input "0.00000009123456789012", the first non-zero digit '9' is at position 8 after the decimal (i=8 in 0-indexed string starting from index 2), so there are 7 leading zeros. The correct exponent should be -8, but this code prints -(7+1) = -8 only if cnt0 counts all zeros before the first non-zero. However, cnt0 is incremented for every zero including those after non-zero digits because the loop doesn't break after finding the first non-zero. But more critically, cnt0 counts ALL zeros from index 2 onward until the end, not just leading zeros. This leads to wrong exponent when trailing digits exist. Actually, the real issue is that cnt0 counts zeros even after non-zero digits start appearing, which is wrong. The exponent should be -(position of first non-zero digit after decimal). In "0.00000009...", the '9' is the 8th digit after decimal, so exponent is -8. The current logic uses cnt0+1 where cnt0 is total zeros from index 2 onward, which is incorrect.
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