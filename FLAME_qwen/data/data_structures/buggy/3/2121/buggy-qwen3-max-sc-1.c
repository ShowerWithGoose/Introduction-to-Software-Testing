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
        printf("e-%d",cnt); @@ [The exponent should be -(cnt), but the count starts at 1 and includes the first non-zero digit position incorrectly. For "0.001", cnt becomes 3, but exponent should be -3, yet logic counts zeros plus initial 1, leading to off-by-one error. Also, if all digits after decimal are zero (though problem says no trailing zeros), this may access out-of-bound.]
        return 0;
    }
    if(strchr(num,'.')==NULL){
        int cnt=strlen(num)-1;
        printf("%c",num[0]);
        int cnt2; @@ [cnt2 is used uninitialized if all digits from index 1 onward are '0'. Since problem states all digits are significant and no trailing zeros, but if input is like "500" (which shouldn't happen per problem), this leads to undefined behavior. However, per problem constraints, integer inputs won't have trailing zeros, but still, if strlen(num)==1, loop doesn't run and cnt2 remains uninitialized.]
        for(int i = strlen(num)-1;i>=1;i--)if(num[i]!='0')cnt2=i;
        for(int i=2;i<=cnt2;i++)printf("%c",num[i]); @@ [This loop starts at i=2, skipping num[1]. Should start at i=1. Also, if cnt2 < 2, this loop may not run or cause issues. For input "123", it prints from index 2 onward ("3"), missing "2".]
        printf("e%d",cnt);
        return 0;
    }
    int cnt=strchr(num,'.')-num;
    cnt--;
    printf("%c.",num[0]);
    for(int i = 1;i < strlen(num);i++)if(num[i]!='.')printf("%c",num[i]); @@ [This prints all digits except '.', but includes digits before '.' beyond the first one. For "123.45", it prints "1.2345", which is correct, but note: the loop starts at i=1, so it prints "2","3","4","5" — that's correct. However, the issue is in the previous branch, not here. But wait: in this branch, the number has a decimal point and more than one digit before it (since first branch handles "0.x", and this is else). So "12.34" becomes "1.234e1" — correct. So this line may be okay. However, the real error is in the integer case above.]
    printf("e%d",cnt);
    return 0;
}