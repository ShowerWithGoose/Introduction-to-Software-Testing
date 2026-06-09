#include<stdio.h>
#include<string.h>
char s[101];
int main(){
    int j=0;
    char t;
    gets(s);
    if(s[0]!='0'){

    for(int i=0;i<strlen(s);i++){
        
        if(s[i]=='.')
        {
        j=i;break;}
        
    }
        for(int i=0;i<j;i++)
    {
        if(i==1)
        printf("."); // @@ [This prints a decimal point after the second digit, but scientific notation requires only one non-zero digit before the decimal point. It should print '.' only when i == 0 to format as d.d...]
        printf("%c",s[i]);
    }
    
        if(j==1)
        printf("."); // @@ [This condition is redundant and incorrectly adds a '.' when there's only one digit before the decimal in the original number, but the loop above already handles digits before '.', leading to potential double '.' or misformatting]
        for(int i=j+1;i<strlen(s);i++)
    {
        printf("%c",s[i]);
    }
        printf("e%d",j-1); // @@ [The exponent calculation is correct for numbers >= 1, but the base formatting is wrong due to earlier errors]
    
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
        if(i==j+1)
        printf("."); // @@ [This inserts the decimal point after the second significant digit, but scientific notation requires it after the first significant digit. Should be if(i == j) { printf("%c.", s[i]); } or similar logic to place '.' after first digit]
        
    }
    printf("e-%d",j-1); // @@ [The exponent is computed as -(j-1), but for input "0.000...d...", the exponent should be -(number of leading zeros after decimal + 1). Here, j is the index of first non-zero digit; for "0.00000009...", j=8 (0-indexed), so exponent should be -8, but j-1 = 7, so it prints e-7 instead of e-8]
    }
    return 0;}