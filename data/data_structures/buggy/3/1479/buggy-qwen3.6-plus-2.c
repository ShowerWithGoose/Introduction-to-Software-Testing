#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char num[1024]; 
char ans[1024];

int main()
{
    gets(num); // @@ gets is deprecated and removed in C11, often causing compilation errors; use fgets or scanf instead
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
        if(ans[1]!=0){//一位数字没小数点  // @@ ans array is not null-terminated, checking ans[1]!=0 is unreliable; should check ansCount > 1
            printf(".");
        }
        for(i=1;i<strlen(ans);i++){//小数点以后的数字  // @@ strlen(ans) causes undefined behavior as ans lacks a null terminator; should iterate up to ansCount
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
        for(i=ansCount;i<=strlen(num);i++){ // @@ Loop logic is flawed for copying fractional part; condition and indexing are incorrect
            ans[i]=num[ansCount+1]; // @@ Incorrect indexing: uses dynamically changing ansCount to access num, copying wrong characters
            ansCount++; // @@ Modifying ansCount inside the loop corrupts the copy process and causes out-of-bounds access
        }
        printf("%c",ans[0]);
        if(ans[1]!='\0'){ // @@ ans is not null-terminated, making this check unreliable; should verify ansCount > 1
            printf(".");
        }
        for(i=1;i<strlen(ans);i++){ // @@ strlen(ans) is undefined behavior without null terminator; should use ansCount as limit
            printf("%c",ans[i]);
        }
        printf("e%d",eCount-1);
    }
    return 0;
}