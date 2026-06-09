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
        printf("%c",num[1+cnt]);
        if(1+cnt<l-1)printf(".");
        for(int i=2+cnt;i<l;i++)printf("%c",num[i]);
        printf("e-%d",cnt); @@ [The exponent should be -(cnt), but the count starts at 1 and includes the first non-zero digit position incorrectly. For "0.001", cnt becomes 3, but exponent should be -3, yet logic counts zeros only and sets exponent to cnt which is number of leading zeros + 1, but here cnt starts at 1 and increments per zero, so for "0.001", cnt=3, which gives e-3 — actually correct. However, if input is "0.1", then cnt remains 1, and num[1+1]=num[2] which is '\0' → undefined behavior. So the real error is that when there are no leading zeros after "0.", like "0.1", the loop doesn't run, cnt=1, then accessing num[2] is out of bounds if string is "0.1" (length=3, indices 0,1,2; num[2]='1', so 1+cnt=2 → okay). But if input is "0.0", it's invalid per problem (no trailing zeros), so maybe not. However, more critically: in the case "0.10", which shouldn't occur per problem, but assuming valid input like "0.1", then 1+cnt = 2, which is valid. But what if input is "0."? Invalid per problem. So perhaps logic is okay. But wait: cnt starts at 1, and for each '0' from i=2 onward, cnt++. So for "0.001", i=2→'0'→cnt=2; i=3→'0'→cnt=3; i=4→'1'→stop. Then num[1+3]=num[4]='1' → correct. Exponent is -3 → correct. But for "0.1": loop doesn't run, cnt=1, num[2]='1', exponent -1 → correct. So this part may be okay. But the real bug is elsewhere.]

        return 0;
    }
    if(strchr(num,'.')==NULL){
        int cnt=strlen(num)-1;
        printf("%c",num[0]);
        int cnt2; @@ [cnt2 is used uninitialized if all digits after first are zero. But problem states all digits are significant and no trailing zeros, so last digit is non-zero. However, if input is "5", then strlen=1, loop from i=0 down to 1 doesn't run, cnt2 remains uninitialized, then for loop from i=2 to cnt2 (uninitialized) causes undefined behavior.]
        for(int i = strlen(num)-1;i>=1;i--)if(num[i]!='0')cnt2=i;
        for(int i=2;i<=cnt2;i++)printf("%c",num[i]); @@ [If input has only one digit (e.g., "5"), this loop runs from i=2 to cnt2 (uninitialized or <2), leading to incorrect output or crash. Also, even for multi-digit like "123", it prints from index 2 onward, skipping index 1. Should print from index 1 to end excluding decimal, but here it's integer so no decimal. But base should be single digit if integer? No: scientific notation base must have one significant digit before decimal. So "123" should become "1.23e2". But this code prints "1" then from index 2: "3", missing "2". So logic is wrong: it should print all digits after first, but this skips index 1.]
        printf("e%d",cnt);
        return 0;
    }
    int cnt=strchr(num,'.')-num;
    cnt--;
    printf("%c.",num[0]);
    for(int i = 1;i < strlen(num);i++)if(num[i]!='.')printf("%c",num[i]); @@ [This prints all non-decimal characters after first digit, which is correct for numbers like "123.45" → "1.2345e2". But what if input is "1.0"? Problem says no trailing zeros, so "1.0" won't appear. So this part may be okay. However, the earlier integer handling is broken.]
    printf("e%d",cnt);
    return 0;
}