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
        for(i=ansCount;i<=strlen(num);i++){
            ans[i]=num[ansCount+1]; // @@ [Error: This loop incorrectly copies characters from num to ans. It uses ansCount+1 as the source index, which is wrong because ansCount has already been incremented past the decimal point. This results in missing digits and incorrect output. For input "0.00000009123456789012", the loop fails to copy all digits after the decimal point, leading to a truncated mantissa and wrong exponent.]
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