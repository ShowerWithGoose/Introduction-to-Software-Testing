#include<stdio.h>
#include<string.h>
int main() {
    char a[200];
    scanf("%s",a);
    int len=strlen(a);
    int i,t=0,tt;
    if(a[1]=='.'&&a[0]!='0')
        printf("%se0",a); @@ [This prints the original string including the decimal point (e.g., "9.e0" for "9."), but according to the problem, if there's only one non-zero digit before the decimal and no fractional part needed, it should be printed as an integer without a decimal point. However, this case doesn't apply to the failing test case "0.9".]
    else if(a[1]=='.'&&a[0]=='0') {
        for(i=2; i<len; i++) {
            if(a[i]!='0') {
                if(t==0)tt=i;
                t=1;                
            }
            if(t==1)printf("%c",a[i]); @@ [This prints every non-zero digit starting from the first non-zero, but also prints extra digits after the first one without controlling the format to have only one digit before the decimal and optionally one after. For "0.9", it prints "9." because when i==tt (i=2), it prints a '.' right after '9', resulting in "9." instead of just "9".]
            if(i==tt)printf("."); @@ [This unconditionally prints a decimal point after the first significant digit, even when there are no more digits to follow. For input "0.9", this leads to output "9." instead of "9", violating the requirement that if the base is an integer (only one significant digit), it should not have a decimal point.]
        }
        printf("e-%d",tt-1);
    } else {
        for(i=0; i<len; i++) {
            if(i==1)printf("."); @@ [This always prints a decimal point at position 1, which may be incorrect if the original number had more than one digit before the decimal and the conversion logic doesn't properly shift digits. However, this branch isn't taken for the test case "0.9".]
            if(a[i]=='.') {
                tt=i;
                continue;
            }
            printf("%c",a[i]);
        }
        printf("e%d",tt-1);
    }
    return 0;
}