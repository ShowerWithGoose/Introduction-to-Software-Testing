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
            if(i==tt)printf("."); @@ [This prints '.' immediately after the first non-zero digit, but it may print multiple times if loop continues and i equals tt again (though unlikely), and more critically, if no non-zero digit exists (e.g., input "0.0"), 'tt' remains uninitialized, causing undefined behavior.]
        }
        printf("e-%d",tt-1); @@ ['tt' may be uninitialized if the input after "0." contains only zeros (e.g., "0.000"), leading to undefined behavior when used here.]
    } else {
        for(i=0; i<len; i++) {
            if(i==1)printf("."); @@ [This unconditionally prints a '.' after the first character, even if the original number had more than one digit before the decimal point, which corrupts the mantissa format. For example, input "123.45" becomes "1.2345", but this code prints "1." then "2", "3", etc., resulting in "1.2345" — however, it also prints '.' even if there was no decimal point in input (e.g., integer input like "123"), which violates problem assumptions but still breaks logic. More critically, it prints '.' at position 1 regardless of where the actual decimal point is.]
            if(a[i]=='.') {
                tt=i;
                continue;
            }
            printf("%c",a[i]);
        }
        printf("e%d",tt-1); @@ ['tt' may be uninitialized if the input has no decimal point (e.g., "123"), leading to undefined behavior. The problem states input has digits before and after the decimal point, but the code doesn't validate this, so missing '.' leaves 'tt' uninitialized.]
    }
    return 0;
}