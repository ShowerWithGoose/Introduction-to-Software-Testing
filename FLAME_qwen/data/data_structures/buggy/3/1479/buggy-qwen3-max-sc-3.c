#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char num[1024]; 
char ans[1024];

int main()
{
    gets(num); // @@ [Using `gets` is unsafe and deprecated; it was removed in C11 and causes compilation errors with modern compilers]
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
        for(i=ansCount;i<=strlen(num);i++){ // @@ [Loop condition `i<=strlen(num)` leads to out-of-bounds access; also logic for copying digits after '.' is flawed]
            ans[i]=num[ansCount+1]; // @@ [Incorrect indexing: `ansCount+1` is constant in loop, should use `i+1` or similar; also overwrites `ans` incorrectly]
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