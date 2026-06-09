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
        printf("e-%d",cnt); @@ [The exponent should be -(cnt), but the count starts at 1 and includes the first non-zero digit position incorrectly. Also, if all digits after decimal are zero (which shouldn't happen per problem statement), this would access out-of-bound memory. However, the main logical error is that 'cnt' counts leading zeros plus one, so exponent should be -(cnt) but actually needs to be -(number of leading zeros + 1). The current 'cnt' initialization to 1 causes off-by-one error in exponent.]
        return 0;
    }
    if(strchr(num,'.')==NULL){
        int cnt=strlen(num)-1;
        printf("%c",num[0]);
        int cnt2; @@ [Variable 'cnt2' is used uninitialized if all trailing digits are zero, which violates problem constraints but still leads to undefined behavior. However, per problem description there are no trailing zeros, but code doesn't handle case where only one digit exists (e.g., "5"). In that case, loop doesn't run and cnt2 is uninitialized.]
        for(int i = strlen(num)-1;i>=1;i--)if(num[i]!='0')cnt2=i;
        for(int i=2;i<=cnt2;i++)printf("%c",num[i]); @@ [This loop starts at i=2, but should start at i=1 to include the second digit. For input "123", it skips '2' and prints from '3', causing wrong mantissa.]
        printf("e%d",cnt);
        return 0;
    }
    int cnt=strchr(num,'.')-num;
    cnt--;
    printf("%c.",num[0]);
    for(int i = 1;i < strlen(num);i++)if(num[i]!='.')printf("%c",num[i]);
    printf("e%d",cnt);
    return 0;
}