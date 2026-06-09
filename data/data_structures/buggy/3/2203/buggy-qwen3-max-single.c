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
                if(t==0)tt=i;
                t=1;                
            }
            if(t==1)printf("%c",a[i]);
            if(i==tt)printf("."); @@ [This prints '.' at position tt during the loop, which may print the dot in the wrong place if multiple non-zero digits exist; also, if t remains 0 (all zeros after decimal), tt is uninitialized and this causes undefined behavior.]
        }
        printf("e-%d",tt-1); @@ ['tt' may be uninitialized if the fractional part contains only zeros, leading to undefined behavior. The problem states there are no trailing zeros, but it doesn't guarantee at least one non-zero digit after decimal when starting with "0."; however, per problem description, all digits are significant, so input like "0.0" shouldn't occur. Still, logic fails if input is "0." with nothing after.]
    } else {
        for(i=0; i<len; i++) {
            if(i==1)printf("."); @@ [This unconditionally prints a '.' after the first digit, even if the original number had more than one digit before the decimal point and the '.' hasn't been encountered yet. This corrupts the mantissa format.]
            if(a[i]=='.') {
                tt=i;
                continue;
            }
            printf("%c",a[i]);
        }
        printf("e%d",tt-1); @@ ['tt' may be uninitialized if the input has no decimal point (though problem says it does), but more critically, the mantissa printing logic is flawed: it prints a '.' after the first character regardless of where the actual decimal point was, and then skips printing the actual '.' character, leading to incorrect base representation.]
    }
    return 0;
}