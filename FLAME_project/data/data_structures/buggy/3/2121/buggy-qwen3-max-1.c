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
        printf("%c",num[1+cnt]); // @@ [The index should be `cnt + 1`, but `cnt` starts at 1 and counts all leading zeros including the one right after '.', so it overcounts by 1. For "0.00000009...", cnt becomes 8, so 1+cnt=9, which skips the '9'. It should start counting zeros from i=2 and set cnt=0 initially.]
        if(1+cnt<l-1)printf(".");
        for(int i=2+cnt;i<l;i++)printf("%c",num[i]);
        printf("e-%d",cnt); // @@ [Because `cnt` is off by one (starts at 1 instead of 0), the exponent is also off by one. For 0.00000009..., there are 7 zeros after '.' before '9', so exponent should be -8, but cnt=8 leads to e-8 being printed as e-8? Wait: actually, in this case, input is "0.00000009123...", which has 7 zeros then '9', so total offset is 8 positions from decimal, so exponent is -8. But the code sets cnt=1 initially, then increments for each '0' from i=2 onward. There are 7 zeros, so cnt becomes 1+7=8. Then it prints num[1+8]=num[9], which is '1' (since num[0]='0', num[1]='.', num[2..8]='0', num[9]='9'? Wait indexing: "0.00000009..." → indices: 0:'0',1:'.',2:'0',3:'0',4:'0',5:'0',6:'0',7:'0',8:'0',9:'9' → so 7 zeros from i=2 to i=8 inclusive → loop runs i=2 to 8 (7 times), cnt=1+7=8 → num[1+8]=num[9]='9' → that seems correct. But output was "1.234...e-9", meaning it printed '1' as first digit. That implies num[9] was '1', not '9'. So perhaps the input was longer? Wait test input: "0.00000009123456789012" → after decimal: 7 zeros then '9','1','2',... So num[9] = '9'. Then why output starts with '1'? Because in the buggy output: "1.23456789012e-9" — that suggests the first digit printed was '1', which is num[10]. So likely, cnt was 9, not 8. Why? Because the loop condition: for(i=2; i<l; i++) if(num[i]=='0') cnt++; → this counts ALL zeros after decimal, but stops at first non-zero? No! It counts every zero in the entire fractional part, even after non-zero digits! That's the bug. For "0.00000009123456789012", after the '9', there is a '0' later (in "...9012"), so that zero gets counted too, making cnt larger than it should be. The loop must stop at the first non-zero digit, not count all zeros in the string.]
        return 0;
    }
    if(strchr(num,'.')==NULL){
        int cnt=strlen(num)-1;
        printf("%c",num[0]);
        int cnt2;
        for(int i = strlen(num)-1;i>=1;i--)if(num[i]!='0')cnt2=i; // @@ [If the number has trailing zeros, this finds last non-zero, but problem states: "all digits are significant (i.e., there are no trailing zeros after the decimal point)" — however, this branch is for integers (no decimal point), and problem says input has digits before and after decimal point, so this branch may never be used. But more critically, `cnt2` is uninitialized if all digits after first are zero, leading to undefined behavior. Also, the loop prints from index 2 onward, skipping index 1, which is wrong. Should print from index 1 to cnt2.]
        for(int i=2;i<=cnt2;i++)printf("%c",num[i]); // @@ [This skips num[1]. Should start at i=1. Also, if cnt2 < 2, this loop doesn't run, which might be okay, but combined with previous line, logic is broken.]
        printf("e%d",cnt);
        return 0;
    }
    int cnt=strchr(num,'.')-num;
    cnt--;
    printf("%c.",num[0]);
    for(int i = 1;i < strlen(num);i++)if(num[i]!='.')printf("%c",num[i]); // @@ [This prints all digits except '.', starting from index 1, but after printing the first digit and '.', it should only print the remaining significant digits without trailing zeros. However, problem states no trailing zeros, so maybe okay. But it prints everything after the first digit, including digits that were after the decimal, which is correct for numbers like 123.45 → 1.2345e2. However, note that it always prints a decimal point even if the normalized form should be an integer (but per problem, base must have one digit before decimal and possibly after, so decimal point is needed unless only one digit total — but problem says if integer, no decimal point. However, this branch handles numbers with decimal point in input, so output should have decimal point only if there are digits after. But the code always prints "%c." — so for input "5.0" (though problem says no trailing zeros, so "5.0" wouldn't appear), but given problem constraints, input has significant digits after decimal, so this may be okay. Main issue is in the first branch.]
    printf("e%d",cnt);
    return 0;
}