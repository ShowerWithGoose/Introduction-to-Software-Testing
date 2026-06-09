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
                count++;
            }
            else{
                flag=1;
                ans[ansCount]=num[i];
                ansCount++;
            }
        }
        printf("%c",ans[0]);//第一位数字 
        if(ans[1]!=0){//一位数字没小数点  @@ The condition `ans[1]!=0` checks if the character value is non-zero (which is true for any digit '0'-'9'). It should check if `ans[1]` exists (i.e., `ansCount > 1`) or if `ans[1] != '\0'`. Using `!=0` treats the character '0' (ASCII 48) as true, so it always prints a decimal point even if there's only one significant digit collected, or fails to handle the buffer correctly. More critically, `ans` is not null-terminated, so `strlen(ans)` later is undefined behavior.
        printf(".");
        }
        for(i=1;i<strlen(ans);i++){//小数点以后的数字  @@ `ans` is not null-terminated, so `strlen(ans)` will read beyond the intended data, causing incorrect output length or garbage characters. The loop should run up to `ansCount`.
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
        for(i=ansCount;i<=strlen(num);i++){  @@ The loop condition `i<=strlen(num)` and the source index `num[ansCount+1]` are incorrect. It should copy the remaining digits after the decimal point. The logic here is flawed: it copies from `num[ansCount+1]` which is not necessarily the character after the decimal point, and it overwrites `ans` incorrectly. Also, `ans` is still not null-terminated.
            ans[i]=num[ansCount+1];
            ansCount++;
        }
        printf("%c",ans[0]);
        if(ans[1]!='\0'){
            printf(".");
        }
        for(i=1;i<strlen(ans);i++){  @@ Again, `strlen(ans)` is unsafe because `ans` is not null-terminated.
            printf("%c",ans[i]);
        }
        printf("e%d",eCount-1);
    }
    return 0;
}