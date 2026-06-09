#include<stdio.h>
#include<string.h>
int main() {
    char a[200];
    scanf("%s",a);
    int len=strlen(a);
    int i,t=0,tt;
    if(a[1]=='.'&&a[0]!='0')
        printf("%se0",a);
    else if(a[1]=='.'&&a[0]=='0') { @@ [This condition assumes the input always has at least two characters and that the second character is '.', but if the input is just "0" or has no decimal point, this leads to undefined behavior. Also, tt may be used uninitialized if no non-zero digit is found after the decimal point.]
        for(i=2; i<len; i++) {
            if(a[i]!='0') {
                if(t==0)tt=i; @@ [tt is only initialized when a non-zero digit is found; if all digits after '.' are zero (which shouldn't happen per problem statement, but code doesn't validate), tt remains uninitialized.]
                t=1;                
            }
            if(t==1)printf("%c",a[i]);
            if(i==tt)printf("."); @@ [This prints '.' after the first non-zero digit, but it may print '.' even if there's only one significant digit, violating the requirement that trailing zeros are not present. Also, if tt was never set (no non-zero found), this causes undefined behavior.]
        }
        printf("e-%d",tt-1); @@ [tt may be uninitialized if the loop never finds a non-zero digit, leading to undefined behavior.]
    } else {
        for(i=0; i<len; i++) {
            if(i==1)printf("."); @@ [This unconditionally prints '.' at position 1, even if the original number had more than one digit before the decimal point, which incorrectly modifies the significant digits. For example, input "123.45" becomes "1.2345", but this code would output "1.23.45".]
            if(a[i]=='.') {
                tt=i;
                continue;
            }
            printf("%c",a[i]);
        }
        printf("e%d",tt-1); @@ [tt is only set if a '.' is encountered in the input. If the input has no decimal point (e.g., "123"), tt remains uninitialized, causing undefined behavior.]
    }
    return 0;
}