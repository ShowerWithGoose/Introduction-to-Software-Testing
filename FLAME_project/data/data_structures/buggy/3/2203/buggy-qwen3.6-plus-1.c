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
            if(i==tt)printf("."); // @@ [The logic prints a decimal point if the significant digit is not the last character. For input "0.9", tt=2 and len=3. The loop runs for i=2. It prints '9'. Since i (2) != tt (2) is false? Wait. i==tt is true. So it prints ".". Then loop ends. Output "9.". Expected "9". The condition should check if there are more digits after the significant one to decide whether to print the decimal point, or handle the single-digit case specifically.]
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