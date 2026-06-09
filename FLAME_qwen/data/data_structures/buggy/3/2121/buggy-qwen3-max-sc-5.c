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
        printf("e-%d",cnt); @@ [The exponent should be cnt, but according to problem logic, it should be cnt (number of leading zeros after decimal) + 1. For example, 0.001 becomes 1e-3, not 1e-2. So this line has a logical error in exponent calculation.]
        return 0;
    }
    if(strchr(num,'.')==NULL){
        int cnt=strlen(num)-1;
        printf("%c",num[0]);
        int cnt2; @@ [Variable cnt2 is used uninitialized if all digits after the first are zero. This leads to undefined behavior. Also, the loop condition may never execute, leaving cnt2 uninitialized.]
        for(int i = strlen(num)-1;i>=1;i--)if(num[i]!='0')cnt2=i;
        for(int i=2;i<=cnt2;i++)printf("%c",num[i]); @@ [This loop starts at i=2, but should start at i=1 to include the second digit. Also, if cnt2 < 2, this loop may not behave correctly or print extra digits. Additionally, the base format requires only one digit before decimal unless it's an integer with one digit — but here multiple digits may be printed without a decimal point, violating output format.]
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