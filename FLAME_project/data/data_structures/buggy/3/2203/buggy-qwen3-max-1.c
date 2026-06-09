#include<stdio.h>
#include<string.h>
int main() {
    char a[200];
    scanf("%s",a);
    int len=strlen(a);
    int i,t=0,tt;
    if(a[1]=='.'&&a[0]!='0')
        printf("%se0",a); // @@ [When the input is like "5.3", this prints "5.3e0", but according to the problem, if there's only one digit before the decimal and it's non-zero, the output should be just that digit without a decimal point (e.g., "5e0"). However, this case isn't triggered by the failing test case "0.9".]
    else if(a[1]=='.'&&a[0]=='0') {
        for(i=2; i<len; i++) {
            if(a[i]!='0') {
                if(t==0)tt=i;
                t=1;                
            }
            if(t==1)printf("%c",a[i]); // @@ [This prints all digits from the first non-zero onward, including extra digits after the first two, which violates the requirement that the base must have only one digit before and one after the decimal point (or be a single digit integer). For "0.9", it prints "9." because when i==tt (i=2), it prints a '.' right after '9', resulting in "9." instead of "9".]
            if(i==tt)printf("."); // @@ [This unconditionally prints a decimal point after the first significant digit, even when there are no more digits to follow. For input "0.9", this leads to "9." instead of "9", which is incorrect per the expected output format requiring no decimal point for single-digit integer base.]
        }
        printf("e-%d",tt-1);
    } else {
        for(i=0; i<len; i++) {
            if(i==1)printf("."); // @@ [This inserts a decimal point at position 1 regardless of original structure, which may be correct for numbers with more than one digit before the decimal, but not relevant for the failing test case "0.9".]
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