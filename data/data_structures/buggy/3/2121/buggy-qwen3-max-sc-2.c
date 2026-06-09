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
        printf("e-%d",cnt); @@ [The exponent should be cnt, but according to problem logic, when input is 0.00...d..., the exponent is -(number of leading zeros after decimal + 1). Here cnt starts at 1 and increments per zero, so it equals (number of leading zeros + 1), which is correct. However, if all digits after decimal are zero (which shouldn't happen per problem statement), this could access out-of-bound. But main issue is in next branch.]
        return 0;
    }
    if(strchr(num,'.')==NULL){
        int cnt=strlen(num)-1;
        printf("%c",num[0]);
        int cnt2; @@ [cnt2 is used uninitialized if all trailing digits are zero. The loop may never execute, leaving cnt2 with garbage value. Also, per problem, there are no trailing zeros, but code tries to handle them incorrectly by printing from index 2 onward, skipping num[1]. Should print digits from index 1 to cnt2, not starting at 2.]
        for(int i = strlen(num)-1;i>=1;i--)if(num[i]!='0')cnt2=i;
        for(int i=2;i<=cnt2;i++)printf("%c",num[i]); @@ [This skips num[1], which is a significant digit. Should start from i=1. Also, if cnt2 < 2, this loop does nothing or causes undefined behavior.]
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