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
            if(num[i]=='0'){ // @@ [Should only count leading zeros before first non-zero digit; missing check for flag (if(!flag && ...))]
                count++; // @@ [Incorrectly counts zeros after first non-zero digit, altering exponent]
            }
            else{
                flag=1; // @@ [Should be inside a condition that only sets flag when first non-zero encountered, and after that, all digits (including zeros) must be added to ans]
                ans[ansCount]=num[i];
                ansCount++;
            }
        }
        printf("%c",ans[0]);//第一位数字 
        if(ans[1]!=0){//一位数字没小数点  // @@ [Relies on zero-initialization; better to use ansCount to check if mantissa has more than one digit]
            printf(".");
        }
        for(i=1;i<strlen(ans);i++){//小数点以后的数字  // @@ [Uses strlen(ans) which depends on null terminator; ans is not explicitly null-terminated, though global zero-initialization may make it work; better to use ansCount]
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
        for(i=ansCount;i<=strlen(num);i++){ // @@ [Loop condition includes null terminator; incorrect index range]
            ans[i]=num[ansCount+1]; // @@ [Wrong assignment: repeatedly assigns the same character; should copy remaining digits correctly]
            ansCount++; // @@ [Incorrectly increments ansCount inside loop, affecting both index and assignment]
        }
        printf("%c",ans[0]);
        if(ans[1]!='\0'){ // @@ [Same issue as line 28; relies on null terminator]
            printf(".");
        }
        for(i=1;i<strlen(ans);i++){ // @@ [Same issue as line 31; uses strlen without null termination]
            printf("%c",ans[i]);
        }
        printf("e%d",eCount-1);
    }
    return 0;
}