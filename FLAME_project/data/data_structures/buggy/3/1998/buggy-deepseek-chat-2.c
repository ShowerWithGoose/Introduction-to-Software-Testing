#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define ll long long
char s[200];
int dot=0,flag=0,wa=0,sum=1;
int main(){
    gets(s);
    int len=strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]=='.')dot=i;
        if(dot>0){
            if(s[i]!='0')flag=1;
            if(!flag&&s[i]=='0')sum++; // @@ Error: sum is incremented for every zero after the decimal point, but it should only count leading zeros before the first non-zero digit. The logic incorrectly counts zeros even after flag becomes 1, because the condition `!flag` is checked but flag is set to 1 when a non-zero is found, so this part is actually correct. However, the main issue is that sum starts at 1, which adds an extra count, and the loop condition `dot>0` is always true after the first dot, causing sum to be incremented for zeros after the decimal point even when there are non-zero digits later, but the flag check prevents that. The real error is that sum is initialized to 1, which incorrectly adds 1 to the count of leading zeros.
        }
    }
    if(dot==1&&s[0]!='0'){
        printf("%se0",s);
    }
    else{
        if(s[0]=='0'){
            for(int i=dot+sum;i<len;i++){
                if(s[i]!='.')
                printf("%c",s[i]);
                if(i==dot+sum&&i!=len-1)printf("."); // @@ Error: This prints a decimal point after the first digit, but the logic for placing the decimal point is flawed. For input "0.00000009123456789012", dot=1, sum becomes 8 (due to starting at 1 and counting 7 zeros), so dot+sum=9, which skips the leading zeros and prints "9123456789012" with a decimal point after the first digit, giving "9.123456789012", but the exponent is printed as e-8, which is wrong because the expected exponent is e-8, but the output shows e-1 in the buggy output, indicating sum is miscalculated. The actual bug is that sum starts at 1, so for 7 leading zeros, sum becomes 8, leading to exponent -8, but the output shows e-1, meaning sum is 2, so the loop logic is also wrong.
            }
            printf("e-%d",sum); // @@ Error: The exponent should be the number of leading zeros plus one (for the digit before the decimal point), but sum is miscalculated due to starting at 1 and the loop logic. For the test case, sum should be 8 (7 zeros + 1 for the digit), but the buggy output shows e-1, indicating sum is 2, which means the loop incorrectly counts only 1 zero.
        }
        else{
            for(int i=0;i<len;i++){
                if(s[i]!='.'){
                    printf("%c",s[i]); 
                }
                if(i==0)printf("."); // @@ Error: This adds a decimal point after the first digit for numbers with more than one digit before the decimal point, but it does not handle the case where the number has only one digit before the decimal point (e.g., "1.23" should output "1.23e0", but this code would output "1.23.e0" incorrectly).
            }
            printf("e%d",dot-1);
        }
    }
    return 0;
}