#include<stdio.h>
#include<string.h>
int main() {
    char a[200];
    scanf("%s",a);
    int len=strlen(a);
    int i,t=0,tt;
    if(a[1]=='.'&&a[0]!='0')
        printf("%se0",a);
    else if(a[1]=='.'&&a[0]=='0') { @@ [This condition assumes the input always has at least two characters and that the second character is '.', but if the input is just "0" or has no decimal point, this leads to undefined behavior. Also, 'tt' may be used uninitialized if no non-zero digit is found after the decimal point.]
        for(i=2; i<len; i++) {
            if(a[i]!='0') {
                if(t==0)tt=i; @@ ['tt' is only assigned inside this block; if all digits after '.' are zero (which shouldn't happen per problem statement, but code doesn't validate), 'tt' remains uninitialized, leading to undefined behavior when used later.]
                t=1;                
            }
            if(t==1)printf("%c",a[i]); @@ [This prints digits starting from the first non-zero, but also prints trailing zeros afterward, which violates the requirement of no trailing zeros. Additionally, the decimal point placement logic is flawed—it prints '.' right after the first non-zero digit, even if more digits follow, but it may print '.' multiple times if loop continues.]
            if(i==tt)printf("."); @@ [This prints '.' at position tt, but if tt was set to i in the same iteration, it prints '.' immediately after the first digit, which is correct for scientific notation, but the logic is entangled with printing digits in the same loop, causing potential misplacement or omission. Also, if t==0 (all zeros), this condition never triggers, but then 'tt' is uninitialized and later used in "e-%d".]
        }
        printf("e-%d",tt-1); @@ ['tt' may be uninitialized if the input after "0." contains no non-zero digits (e.g., "0.0"), which violates problem constraints but the program doesn't guard against it, leading to undefined behavior.]
    } else {
        for(i=0; i<len; i++) {
            if(i==1)printf("."); @@ [This unconditionally prints '.' at i==1, even if the original number had no decimal point or had more than one digit before the decimal. For example, input "123.45" would become "1.2345", but this prints '.' after first digit correctly; however, if input is "12345" (no decimal), this incorrectly inserts '.' after first digit without removing original digits properly. Also, if the number starts with multiple digits and includes a '.', this logic conflicts with the existing '.'.]
            if(a[i]=='.') {
                tt=i;
                continue;
            }
            printf("%c",a[i]);
        }
        printf("e%d",tt-1); @@ ['tt' is only set if a '.' is encountered in the input. If the input has no decimal point (e.g., "12345"), 'tt' remains uninitialized, leading to undefined behavior when printing the exponent.]
    }
    return 0;
}