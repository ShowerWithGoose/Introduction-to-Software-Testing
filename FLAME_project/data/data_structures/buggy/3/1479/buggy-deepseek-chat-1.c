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
        if(ans[1]!=0){//一位数字没小数点 
            printf(".");
        }
        for(i=1;i<strlen(ans);i++){//小数点以后的数字 
            printf("%c",ans[i]);
        }
        printf("e-%d",count); // @@ [Error: The exponent calculation is incorrect. For input "0.00000009123456789012", count counts the zeros after the decimal point (7 zeros), but the exponent should be -8 because the first non-zero digit '9' is at position 8 after the decimal point. The exponent should be -(count+1) or the counting logic should start from the decimal point correctly.]
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
        for(i=ansCount;i<=strlen(num);i++){ // @@ [Error: This loop incorrectly copies characters. It uses ansCount as the index for num, but ansCount has been incremented to the number of digits before the decimal point. It should copy from the position after the decimal point in num, not from ansCount+1. Also, the loop condition i<=strlen(num) may cause out-of-bounds access.]
            ans[i]=num[ansCount+1]; // @@ [Error: This assignment uses a fixed index ansCount+1 for num, which does not correctly iterate through the digits after the decimal point. It should use a separate index for num.]
            ansCount++;
        }
        printf("%c",ans[0]);
        if(ans[1]!='\0'){
            printf(".");
        }
        for(i=1;i<strlen(ans);i++){
            printf("%c",ans[i]);
        }
        printf("e%d",eCount-1);
    }
    return 0;
}