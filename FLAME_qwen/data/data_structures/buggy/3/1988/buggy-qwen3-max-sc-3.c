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
        printf("e-%d", cnt0+1); @@ [The exponent calculation is incorrect. It assumes all leading zeros after "0." contribute to the exponent as cnt0+1, but it should be based on the position of the first non-zero digit, not total zero count. Also, if input is "0.0", this logic fails completely.]
    }else if(str[1] == '.'){
        printf("%se0", str); @@ [This outputs the original string with "e0", which violates the required scientific notation format. For example, "5.3" becomes "5.3e0", but correct output should be "5.3e0" only if allowed; however, per problem, if there's one digit before decimal and no trailing zeros, it's acceptable—but this branch doesn't handle cases like "12.3", which wouldn't enter this branch anyway. However, more critically, this branch assumes that any number starting with non-zero and having '.' at index 1 is already normalized, but it prints the whole string including digits after decimal without checking for trailing zeros (though problem says no trailing zeros). Still, the bigger issue is that this doesn't match the required base format when there are multiple digits before decimal—this branch only triggers when str[1]=='.', i.e., single digit before decimal, so it might seem okay, but the real bug is in the third branch.]
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
        printf("e%d", i-1); @@ [This incorrectly prints all digits except the decimal point after the first digit and a decimal point, which duplicates digits. For example, input "123.45" would print "1.2345e2", which is correct in value, but the loop prints from j=1 to end skipping '.', so it prints "2345", giving "1.2345e2"—which seems correct. However, the issue is that it always prints a decimal point even when unnecessary. According to the problem, if the base is an integer (i.e., only one significant digit), it should not have a decimal point. But here, it always prints "%c." — so even if the normalized form should be just "1e2" (if input were "100.0", but problem states no trailing zeros, so maybe not). However, given the problem says all digits are significant and no trailing zeros, then after normalization, if there's more than one significant digit, we need decimal. But the real error is that this branch assumes there are digits after the decimal, but also includes digits before the decimal beyond the first. However, the critical flaw is that it does not remove trailing zeros—but problem states input has no trailing zeros, so that’s okay. The actual logical error is in the first branch and possibly missing handling of edge cases like "0.1", which this code may mishandle due to incorrect exponent. Also, this branch doesn't consider if the number has no fractional part—but problem says input has digits before and after decimal point, so that's guaranteed. However, the main bugs are in the first branch's exponent logic and possibly the second branch's output format not aligning with specification when only one digit exists (should it print decimal or not?). But per problem: "If it’s a decimal, it must have one significant digit before and after..." — so if there's only one significant digit total (like "5"), but input always has digits before and after decimal, so minimal input is like "0.1" or "5.3". So for "5.3", second branch prints "5.3e0" which is correct. But for "12.3", third branch prints "1.23e1" — wait, no: i=2 (since "12." -> i=2 at '.'), so e1, and prints "1." then j=1: '2', j=2: skip '.', j=3: '3' → "1.23e1" which is correct. So third branch may be okay. The major error is in first branch: for "0.001", it sets cnt0=2, cnt1=1 at i=4 ('1'), prints '1', then e-3 (cnt0+1=3) → "1e-3" which is correct. But for "0.0102", it counts: i=2:'0'→cnt0=1; i=3:'1'→cnt1=1→print '1'; i=4:'0'→cnt0=2; i=5:'2'→cnt1=2→print '.2'; so output "1.2e-3" (cnt0+1=2+1=3). But correct exponent should be -2 (since 0.0102 = 1.02e-2). The exponent is wrong because cnt0 counts all zeros, not just leading ones before first non-zero. In "0.0102", leading zeros after decimal are only one (at i=2), so exponent should be -2, but cnt0 becomes 2 (because of the zero at i=4), so cnt0+1=3 → wrong exponent. Hence, first branch logic is fundamentally flawed.]
    }
    return 0;
}