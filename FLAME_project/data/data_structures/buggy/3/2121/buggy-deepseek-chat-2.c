#include<stdio.h>
#include<string.h>

int main(){
    char num[1100];
    scanf("%s",num);
    //先判断e后面是负数还是正数
    if(num[0]=='0'&&num[1]=='.'){//是小数
        int cnt=1; 
         int l=strlen(num);
         for(int i=2;i<l;i++){
             if(num[i]=='0')cnt++;
        }
        printf("%c",num[1+cnt]); // @@ Error: For input "0.00000009123456789012", cnt counts 7 zeros after the decimal point (positions 2-8 are zeros), so 1+cnt=8, but num[8] is '9', which is correct. However, the exponent should be cnt+1=8, not cnt=7, because the first non-zero digit is at position 8 (0-indexed from start), meaning the number is 9.123456789012e-8, but the code outputs e-7. The exponent calculation is off by one.
        if(1+cnt<l-1)printf(".");
        for(int i=2+cnt;i<l;i++)printf("%c",num[i]);
        printf("e-%d",cnt); // @@ Error: The exponent should be cnt+1, not cnt, because the decimal point is at position 1, and the first non-zero digit is at position 1+cnt+1 = cnt+2, so the exponent is -(cnt+1). For example, 0.0009 has cnt=3, but exponent should be -4.
        return 0;
    }
    if(strchr(num,'.')==NULL){
        int cnt=strlen(num)-1;
        printf("%c",num[0]);
        int cnt2;
        for(int i = strlen(num)-1;i>=1;i--)if(num[i]!='0')cnt2=i; // @@ Error: Variable cnt2 is uninitialized if all digits after the first are zero (e.g., "1000"), leading to undefined behavior. Also, the loop logic for removing trailing zeros is flawed; it should find the last non-zero digit.
        for(int i=2;i<=cnt2;i++)printf("%c",num[i]); // @@ Error: This loop may print incorrect digits if cnt2 is not properly set, and it skips the first digit after the decimal point (num[1]) incorrectly.
        printf("e%d",cnt);
        return 0;
    }
    int cnt=strchr(num,'.')-num;
    cnt--;
    printf("%c.",num[0]);
    for(int i = 1;i < strlen(num);i++)if(num[i]!='.')printf("%c",num[i]); // @@ Error: This prints all digits after the decimal point including trailing zeros, but the problem states no trailing zeros in input. However, for numbers like "123.456", it prints "1.23456e2" which is correct, but for numbers with leading zeros before decimal (e.g., "0.123"), this branch is not taken because of the first if. The main issue is that this branch does not handle the case where the first digit is zero (e.g., "0.123") correctly, but that's already handled above. The logic here is generally correct for numbers >=1.
    printf("e%d",cnt);
    return 0;
}