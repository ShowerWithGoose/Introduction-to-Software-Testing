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
        printf("e-%d",cnt); @@ [The exponent should be -(cnt), but cnt starts at 1 and counts zeros, so it should be e-(cnt) only if cnt counts leading zeros correctly. However, the real issue is that when all digits after decimal are zero (which shouldn't happen per problem statement), or when there's only one non-zero digit, the logic may break. But more critically, if the input is "0.0", this would access out-of-bound memory. However, per problem description, there are no trailing zeros and digits are significant, so "0.0" won't occur. The actual bug is in the exponent calculation: for "0.001", cnt becomes 3 (since i=2: '0'→cnt=2, i=3: '0'→cnt=3, i=4: '1' stops loop). Then it prints num[4] which is '1', and exponent e-3, but correct exponent is -3? Actually, 0.001 = 1e-3, so that seems right. Wait, but cnt starts at 1, then increments for each '0', so for "0.001", zeros at i=2 and i=3 → cnt becomes 3. Then 1+cnt = 4, which is correct. So exponent e-3 is correct. So maybe not here.]

        return 0;
    }
    if(strchr(num,'.')==NULL){
        int cnt=strlen(num)-1;
        printf("%c",num[0]);
        int cnt2; @@ [cnt2 is used uninitialized if all digits after the first are zero. But problem states all digits are significant and no trailing zeros, so the number won't have trailing zeros. However, if input is "5", then strlen=1, the loop for(i = strlen(num)-1;i>=1;i--) doesn't run (since i=0 >=1 false), so cnt2 remains uninitialized. Then the next loop for(int i=2;i<=cnt2;i++) uses uninitialized cnt2 → undefined behavior. This is a critical error. For integer input like "5", it should output "5e0", but instead it prints "5" then tries to print from i=2 to cnt2 (garbage), then "e0". So wrong output.]
        for(int i = strlen(num)-1;i>=1;i--)if(num[i]!='0')cnt2=i;
        for(int i=2;i<=cnt2;i++)printf("%c",num[i]); @@ [If input is single-digit integer like "5", this loop runs from i=2 to cnt2 (uninitialized), causing undefined behavior or printing garbage. Also, even for multi-digit like "123", it prints num[0]='1', then from i=2 to cnt2 (which is 2 for "123") → prints num[2]='3', skipping '2'. Should print digits from index 1 onward (excluding decimal), but here it skips index 1. So logic is wrong.]
        printf("e%d",cnt);
        return 0;
    }
    int cnt=strchr(num,'.')-num;
    cnt--;
    printf("%c.",num[0]);
    for(int i = 1;i < strlen(num);i++)if(num[i]!='.')printf("%c",num[i]); @@ [This prints all digits after the first, excluding the decimal point. But for input like "12.34", it prints "1." then "234", resulting in "1.234e1", which is correct. However, what if the integer part has more than one digit? The problem says: if more than one digit before decimal, first digit can't be zero. So "12.34" is valid. This seems okay. But wait, the problem requires that the base has only one significant digit before decimal. So "12.34" becomes "1.234e1" — correct. So this part may be okay.]
    printf("e%d",cnt);
    return 0;
}