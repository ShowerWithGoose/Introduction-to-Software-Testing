#include<stdio.h>
#include<string.h>
int main() {
    char a[200];
    scanf("%s",a);
    int len=strlen(a);
    int i,t=0,tt;
    if(a[1]=='.'&&a[0]!='0')
        printf("%se0",a);
    else if(a[1]=='.'&&a[0]=='0') {
        for(i=2; i<len; i++) {
            if(a[i]!='0') {
                if(t==0)tt=i;
                t=1;                
            }
            if(t==1)printf("%c",a[i]);
            if(i==tt)printf("."); // @@ This prints a decimal point unconditionally after the first non-zero digit, even when there are no more digits, resulting in an extra decimal point for numbers like 0.9. Should only print decimal point if there are additional digits after the first non-zero digit.
        }
        printf("e-%d",tt-1);
    } else {
        for(i=0; i<len; i++) {
            if(i==1)printf(".");
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