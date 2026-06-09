#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char num[1024]; 
char ans[1024];

int main()
{
    gets(num);
    int i;
    int ansCount=0;
    if(num[0]=='0'){//数字小于1 
        int count=1;
        int flag=0;
        for(i=2;i<strlen(num);i++){
            if(num[i]=='0'){
                count++; // @@ [This counts leading zeros after "0.", but 'count' should represent the exponent magnitude. For input "0.00000009...", there are 7 zeros before '9', so exponent should be -8, but this logic sets count=8 (starting from 1 and incrementing 7 times), leading to e-8 being printed as e-8? Wait: actually, count starts at 1 and increments for each '0', so for 7 zeros, count becomes 8, then prints e-8 — which matches expected exponent. However, the bug is elsewhere: the copying of digits into 'ans' stops at first non-zero but doesn't copy all remaining digits correctly due to uninitialized 'ans' and incorrect loop logic. Also, 'ans' may contain garbage beyond copied digits because it's not null-terminated, causing strlen(ans) to be unreliable.]
            }
            else{
                flag=1;
                ans[ansCount]=num[i];
                ansCount++;
            }
        }
        printf("%c",ans[0]);//第一位数字 
        if(ans[1]!=0){//一位数字没小数点  // @@ [This condition uses ans[1]!=0, but 'ans' is not null-terminated, so ans[1] could be garbage. This leads to incorrect decision on whether to print a decimal point. Also, even if only one digit exists, if more digits were intended, they might not be printed due to reliance on strlen(ans) later, which is undefined without null termination.]
            printf(".");
        }
        for(i=1;i<strlen(ans);i++){//小数点以后的数字  // @@ [strlen(ans) is undefined behavior because 'ans' is not null-terminated. This can cause reading beyond valid digits or stopping too early, leading to truncated output like missing '012' at the end.]
            printf("%c",ans[i]);
        }
        printf("e-%d",count);
    }
    else{//数字大于1 
    int eCount=0;
        for(i=0;i<strlen(num);i++){
            if(num[i]!='.'){
                ans[ansCount]=num[i];
                ansCount++;
                eCount++;
            }
            else{
                break;
            }
        }
        for(i=ansCount;i<=strlen(num);i++){ // @@ [This loop is logically flawed: it tries to copy digits after the decimal point but uses incorrect indexing. It assigns ans[i] = num[ansCount+1], which is always the same character (the one right after the last copied digit before the dot). Also, it runs up to strlen(num) inclusive, which may go out of bounds. Moreover, 'ans' is again not null-terminated, causing issues in later strlen(ans) calls.]
            ans[i]=num[ansCount+1];
            ansCount++;
        }
        printf("%c",ans[0]);
        if(ans[1]!='\0'){ // @@ [Again, 'ans' is not null-terminated, so ans[1] may contain garbage, leading to wrong decision about printing a decimal point.]
            printf(".");
        }
        for(i=1;i<strlen(ans);i++){ // @@ [strlen(ans) is undefined due to missing null terminator, possibly causing incorrect output length.]
            printf("%c",ans[i]);
        }
        printf("e%d",eCount-1);
    }
    return 0;
}