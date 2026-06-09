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
            if(num[i]=='0'){ @@ // Error: This condition does not distinguish leading zeros from zeros after the first non-zero digit. It should only count zeros before the first non-zero digit and copy zeros after that.
                count++; @@ // Error: count should only be incremented for leading zeros (flag==0). Incrementing it for zeros after the first non-zero digit corrupts the exponent.
            }
            else{
                flag=1;
                ans[ansCount]=num[i]; @@ // Error: This only copies non-zero digits. Zeros after the first non-zero digit are not written to ans, causing missing digits in the mantissa.
                ansCount++;
            }
        }
        printf("%c",ans[0]);//第一位数字 
        if(ans[1]!=0){ @@ // Error: Comparing char to integer 0 should be 'if(ans[1]!='\0')'. Although this may still work, the missing zero digits cause ans[1] to be the second non-zero digit, not the actual second digit.
            printf(".");
        }
        for(i=1;i<strlen(ans);i++){//小数点以后的数字 
            printf("%c",ans[i]); @@ // Error: Because ans does not contain the zero digits that were skipped, the printed mantissa is incomplete.
        }
        printf("e-%d",count); @@ // Error: count includes zeros after the first non-zero digit, so the exponent is one less than correct (should be -8, got -9 for the given test).
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
            ans[i]=num[ansCount+1];
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