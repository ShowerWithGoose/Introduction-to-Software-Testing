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
        printf("%c",num[1+cnt]); // @@ Error: This assumes the first non-zero digit is at index 1+cnt, but cnt counts all zeros including those after the first non-zero digit. For input "0.00000009123456789012", cnt becomes 8 (1 initial + 7 zeros), so 1+cnt=9, but num[9] is '1', not '9'. The correct first non-zero digit is at index 8 (num[8]='9'), so the exponent should be 8, not 9.
        if(1+cnt<l-1)printf(".");
        for(int i=2+cnt;i<l;i++)printf("%c",num[i]); // @@ Error: This skips the first non-zero digit and starts from the next digit. For the input, 2+cnt=10, so it prints from num[10]='2' onward, missing the '9' and '1'. The correct output should start with '9' and include all digits after it.
        printf("e-%d",cnt); // @@ Error: cnt is 8, but the correct exponent is 8 (since there are 8 zeros after the decimal point before the first non-zero digit). However, the base is wrong, so the overall output is incorrect.
        return 0;
    }
    if(strchr(num,'.')==NULL){
        int cnt=strlen(num)-1;
        printf("%c",num[0]);
        int cnt2;
        for(int i = strlen(num)-1;i>=1;i--)if(num[i]!='0')cnt2=i; // @@ Error: cnt2 is uninitialized if all digits after the first are zero (e.g., "1000"), but the problem states no trailing zeros, so this may not trigger. However, the logic is flawed: it finds the last non-zero digit but then uses it incorrectly.
        for(int i=2;i<=cnt2;i++)printf("%c",num[i]); // @@ Error: This prints from index 2 to cnt2, but for an integer like "123", cnt2 would be 2 (last non-zero digit at index 2), printing "3" only, missing "2". The correct output should be "1.23e2".
        printf("e%d",cnt);
        return 0;
    }
    int cnt=strchr(num,'.')-num;
    cnt--;
    printf("%c.",num[0]);
    for(int i = 1;i < strlen(num);i++)if(num[i]!='.')printf("%c",num[i]); // @@ Error: This prints all digits after the decimal point, including trailing zeros if any (though problem says no trailing zeros). For input like "123.456", it prints "1.23456e2", which is correct, but for "0.00123" it would not enter this branch because of the first if.
    printf("e%d",cnt);
    return 0;
}