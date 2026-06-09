#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char num[1024]; 
char ans[1024];

int main()
{
    gets(num); // @@ gets is removed in C11 standard, causing compilation error; use fgets instead.
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
        if(ans[1]!=0){//一位数字没小数点  // @@ ans is not null-terminated, accessing ans[1] may cause undefined behavior; should check ansCount > 1.
            printf(".");
        }
        for(i=1;i<strlen(ans);i++){//小数点以后的数字  // @@ strlen(ans) causes undefined behavior because ans lacks a null terminator.
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
        for(i=ansCount;i<=strlen(num);i++){ // @@ Loop condition and logic for copying fractional part are incorrect; may cause out-of-bounds access.
            ans[i]=num[ansCount+1]; // @@ Incorrect indexing for copying characters; should use ans[ansCount] = num[i+1];
            ansCount++;
        }
        printf("%c",ans[0]);
        if(ans[1]!='\0'){ // @@ ans is not null-terminated, checking ans[1] is unreliable.
            printf(".");
        }
        for(i=1;i<strlen(ans);i++){ // @@ strlen(ans) causes undefined behavior due to missing null terminator.
            printf("%c",ans[i]);
        }
        printf("e%d",eCount-1);
    }
    return 0;
}