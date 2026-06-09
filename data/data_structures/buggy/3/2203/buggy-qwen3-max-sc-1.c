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
            if(i==tt)printf("."); @@ [If there's only one non-zero digit after leading zeros, this prints a '.' after it, which violates the requirement that the base must have exactly one digit before the decimal and possibly digits after—but not trailing zeros. Also, if multiple non-zero digits exist, the '.' is printed in the wrong place (only when i == tt).]
        }
        printf("e-%d",tt-1); @@ ['tt' may be uninitialized if the input after "0." contains only zeros, which violates problem constraints but still risks undefined behavior.]
    } else {
        for(i=0; i<len; i++) {
            if(i==1)printf("."); @@ [This unconditionally prints a '.' after the first digit, even if the original number had more than one digit before the decimal point and the '.' hasn't been encountered yet. This corrupts the mantissa format.]
            if(a[i]=='.') {
                tt=i;
                continue;
            }
            printf("%c",a[i]);
        }
        printf("e%d",tt-1); @@ ['tt' may be uninitialized if the input has no decimal point (though problem states it does), but more critically, the logic for placing the decimal point in the output is flawed—it prints '.' at position 1 regardless of where the actual decimal was.]
    }
    return 0;
}