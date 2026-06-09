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
        printf("e-%d", cnt0+1); @@ [The exponent calculation is incorrect. It counts leading zeros as cnt0 but doesn't account for the position correctly. Also, if all digits after decimal are zero (which shouldn't happen per problem statement), this logic fails. Moreover, it doesn't handle the case where only one non-zero digit exists after zeros (should output just that digit without decimal point).]
    }else if(str[1] == '.'){
        printf("%se0", str); @@ [This outputs the original number with "e0", but per problem requirements, if there's only one digit before the decimal point and it's non-zero, it should be output as-is only if it's a single digit integer. However, numbers like "5.67" should become "5.67e0", which is correct, but numbers like "5." (if allowed) would be wrong. More critically, this branch assumes that any number starting with non-zero and having '.' at index 1 is already normalized, but the problem states that inputs have digits both before and after the decimal point, so "5." wouldn't appear. However, the bigger issue is that this doesn't remove trailing zeros after the decimal point, though the problem says there are none. Still, the main flaw is in other branches.]
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
        printf("e%d", i-1); @@ [This prints all digits except the decimal point after the first digit and a decimal point, which may include trailing zeros (though problem says there are none). However, the major error is that it always prints a decimal point even when the normalized form should be an integer (i.e., when there's only one significant digit total). For example, input "500.0" (but per problem, no trailing zeros, so maybe "500.1") — but according to problem, all digits are significant and there are digits after decimal, so maybe this is okay. However, the real issue is that if the number is like "123.45", it outputs "1.2345e2", which is correct. But the critical bug is in the first branch handling numbers starting with '0'. Also, this branch doesn't handle the case where after removing the decimal, there might be only one digit (should not print decimal point then). According to output format: if base is integer (only one significant digit), no decimal point. So if input is "5.0" (but problem says no trailing zeros, so maybe not), but if input is "7.8", it should be "7.8e0" — which this does. However, if input is "9" (but problem says has digits before and after decimal), so maybe not applicable. The main errors are in the first branch.]
    }
    return 0;
}