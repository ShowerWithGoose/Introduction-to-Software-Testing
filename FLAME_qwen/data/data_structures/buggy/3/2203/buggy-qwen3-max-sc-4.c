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
                if(t==0)tt=i;
                t=1;                
            }
            if(t==1)printf("%c",a[i]);
            if(i==tt)printf("."); @@ [tt may be uninitialized if all digits after '.' are zero, leading to undefined behavior. Also, printing '.' inside the loop at position tt causes incorrect formatting (e.g., multiple dots or dot in wrong place).]
        }
        printf("e-%d",tt-1); @@ [tt may be uninitialized if the fractional part is all zeros, causing undefined behavior.]
    } else {
        for(i=0; i<len; i++) {
            if(i==1)printf("."); @@ [This prints a '.' after the first digit unconditionally, even if the original number had more than one digit before the decimal point, which breaks the scientific notation format. Also, it prints '.' even when the number has no decimal point originally.]
            if(a[i]=='.') {
                tt=i;
                continue;
            }
            printf("%c",a[i]);
        }
        printf("e%d",tt-1); @@ [tt may be uninitialized if the input has no decimal point (e.g., an integer like "123"), leading to undefined behavior.]
    }
    return 0;
}