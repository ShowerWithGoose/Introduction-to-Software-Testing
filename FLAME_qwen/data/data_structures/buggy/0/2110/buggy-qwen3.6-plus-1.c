#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <time.h>
#include <limits.h>
#include <float.h>
#include <errno.h>
#define N (int)1e6+1
int main(){
    char str[N];
    gets(str); // @@ gets is deprecated and removed in C11 standard, causing compilation errors; should use fgets or scanf.
    int len=strlen(str);
    for(int i=0;i<len;i++){ // @@ Missing boundary checks for i=0 and i=len-1, leading to out-of-bounds array access when evaluating str[i-1] and str[i+1].
        if(str[i]=='-'){
            if('0'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='9'){ // @@ Uses <= which allows equal characters, but problem requires strictly greater (<); also lacks boundary check.
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else if('a'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='z'){ // @@ Same as above, should use < for strict increase.
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else if('A'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='Z'){ // @@ Same as above, should use < for strict increase.
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else{
                printf("%c%c%c",str[i-1],str[i],str[i+1]); // @@ Incorrectly duplicates str[i-1] (already printed in previous iteration) and should only print str[i]; also risks out-of-bounds access.
            }
        }
        else{
            printf("%c",str[i]);
        }
    }
    return 0;
}