#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char num[1024]; 
char ans[1024];

int main()
{
    gets(num); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings depending on compiler settings. It should be replaced with 'fgets'.]
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
        for(i=ansCount;i<=strlen(num);i++){ // @@ [This loop writes beyond the bounds of 'num' because 'ansCount+1' may exceed the length of 'num', and the loop condition uses '<=' which can lead to reading past the null terminator. Also, this logic incorrectly copies characters after the decimal point.]
            ans[i]=num[ansCount+1]; // @@ [This line always reads from the same position 'ansCount+1' instead of incrementing the source index, leading to incorrect copying of digits after the decimal point.]
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