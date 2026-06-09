#include<stdio.h>
#include<string.h>

int main(){
    char num[1100];
    scanf("%s",num);
    //先判断e后面是负数还是正数
    if(num[0]=='0'&&num[1]=='.'){//是小数
        int cnt=1; // @@ Incorrect initialization; should be 0 and count only leading zeros.
        int l=strlen(num);
        for(int i=2;i<l;i++){ // @@ Loop should break upon encountering first non-zero digit; it incorrectly counts all zeros in the fractional part.
            if(num[i]=='0')cnt++; // @@ Incrementing for all zeros, not just leading zeros, leading to wrong index and exponent.
        }
        printf("%c",num[1+cnt]); // @@ Uses incorrect index due to wrong cnt; should print the first non-zero digit.
        if(1+cnt<l-1)printf("."); // @@ Condition based on wrong cnt, may incorrectly decide to print a decimal point.
        for(int i=2+cnt;i<l;i++)printf("%c",num[i]); // @@ Starting index based on wrong cnt, omits digits between the first non-zero and later zeros.
        printf("e-%d",cnt); // @@ Exponent uses cnt which counts all zeros after decimal, not just leading zeros; exponent is incorrect.
        return 0;
    }
    if(strchr(num,'.')==NULL){
        int cnt=strlen(num)-1;
        printf("%c",num[0]);
        int cnt2; // @@ Uninitialized variable; used later without definite assignment.
        for(int i = strlen(num)-1;i>=1;i--)if(num[i]!='0')cnt2=i; // @@ Logic flawed: only stores last non-zero index, skips digits in between. Also uses uninitialized cnt2 in the next loop.
        for(int i=2;i<=cnt2;i++)printf("%c",num[i]); // @@ Missing decimal point, starts from index 2 (skipping digit at index 1), and may access uninitialized cnt2.
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