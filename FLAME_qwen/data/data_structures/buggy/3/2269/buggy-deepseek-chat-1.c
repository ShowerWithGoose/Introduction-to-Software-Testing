#include<stdio.h>
#include<string.h>
char s[101];
int main(){
    int j=0;
    char t;
    gets(s); // @@ gets() is unsafe and may cause buffer overflow; also not standard in modern C, but the main issue is that the problem expects scanf, and gets() reads until newline which may include trailing spaces or cause issues with input format
    if(s[0]!='0'){

    for(int i=0;i<strlen(s);i++){
        
        if(s[i]=='.')
        {
        j=i;break;}
        
    }
        for(int i=0;i<j;i++)
    {
        if(i==1) // @@ This condition incorrectly adds a decimal point after the second digit, but the base should have only one digit before the decimal point; for numbers like "12.34", this would output "1.2.34" instead of "1.234"
        printf(".");
        printf("%c",s[i]);
    }
    
        if(j==1) // @@ This adds an extra decimal point when there is exactly one digit before the decimal point (e.g., "1.23" becomes "1..23"), which is incorrect
        printf(".");
        for(int i=j+1;i<strlen(s);i++)
    {
        printf("%c",s[i]);
    }
        printf("e%d",j-1);
    
}
    else
    {
        for(int i=0;i<strlen(s);i++){
        
        if(s[i]!='0'&&s[i]!='.')
        {
        j=i;break;}
        
    }
    
    for(int i=j;i<strlen(s);i++)
    {
        printf("%c",s[i]);
        if(i==j+1) // @@ This incorrectly adds a decimal point after the second digit of the significant part, but the base should have only one digit before the decimal point; for "0.00123", this would output "1.23" instead of "1.23" (correct here) but for "0.0123" it would output "1.23" instead of "1.23" (actually correct), but the logic is flawed because it always adds a dot after the second character, which may not be correct for numbers like "0.1" (outputs "1." instead of "1")
        printf(".");
        
    }
    printf("e-%d",j-1); // @@ The exponent calculation is incorrect; for "0.00123", j=3 (index of '1'), so j-1=2, but the exponent should be -3 (since 0.00123 = 1.23e-3)
    }
    return 0;}