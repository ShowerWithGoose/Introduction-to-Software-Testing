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
        printf("%c",num[1+cnt]); // @@ [The index should be `cnt + 1`, but `cnt` already includes the first non-zero digit's offset incorrectly. The loop counts all leading zeros after '0.', so the first significant digit is at index `cnt + 1`, but `cnt` starts at 1, so it actually skips one extra digit. For input "0.00000009123...", cnt becomes 8 (7 zeros + initial 1), so 1+cnt=9, which points to '1' instead of '9'.]
        if(1+cnt<l-1)printf(".");
        for(int i=2+cnt;i<l;i++)printf("%c",num[i]); // @@ [Same indexing error: starts printing from `2 + cnt`, which skips the correct first significant digit and includes wrong subsequent digits. Should start from `cnt + 2` only if `cnt` correctly counted leading zeros. But since `cnt` is off by one, this prints from the wrong position.]
        printf("e-%d",cnt); // @@ [Exponent should be equal to the number of leading zeros after the decimal point plus one. In "0.00000009...", there are 7 zeros before '9', so exponent is -8. But `cnt` starts at 1 and increments for each zero, ending at 8, which gives e-8 — this part is actually correct. However, because the mantissa is wrong due to indexing, the overall result is wrong. The real issue is in mantissa extraction, not exponent calculation.]
        return 0;
    }
    if(strchr(num,'.')==NULL){
        int cnt=strlen(num)-1;
        printf("%c",num[0]);
        int cnt2;
        for(int i = strlen(num)-1;i>=1;i--)if(num[i]!='0')cnt2=i; // @@ [Variable `cnt2` may be used uninitialized if all digits after the first are zero (though problem states no trailing zeros, so maybe safe). But more critically, the loop prints from index 2 onward (`for(int i=2;...)` below), skipping `num[1]`. This causes loss of the second digit.]
        for(int i=2;i<=cnt2;i++)printf("%c",num[i]); // @@ [Should start from `i = 1`, not `i = 2`, because after printing `num[0]`, the next significant digit is at index 1. Starting at 2 skips the second digit entirely.]
        printf("e%d",cnt);
        return 0;
    }
    int cnt=strchr(num,'.')-num;
    cnt--;
    printf("%c.",num[0]);
    for(int i = 1;i < strlen(num);i++)if(num[i]!='.')printf("%c",num[i]); // @@ [This prints all digits after the decimal point, including trailing digits, but also includes digits that may have been after the decimal. However, the bigger issue is that it doesn't stop at significant digits — but per problem, all digits are significant. However, it prints the entire fractional part without removing anything, which is okay. BUT: it prints starting from index 1, which includes the part before the decimal (already printed `num[0]`), so when `i=1`, if original was "123.45", then `num[1]` is '2', which is correct. So this part might be okay. However, combined with previous logic, the real bug is in the first branch.]
    printf("e%d",cnt);
    return 0;
}