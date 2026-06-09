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
    gets(str);
    int len=strlen(str);
    for(int i=0;i<len;i++){
        if(str[i]=='-'){
            if('0'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='9'){ // @@ [Condition incorrectly uses comparison as range, does not ensure both characters are digits; should be: '0'<=str[i-1] && str[i-1]<='9' && '0'<=str[i+1] && str[i+1]<='9' && str[i-1]<str[i+1]]
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else if('a'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='z'){ // @@ [Same error: condition does not properly check both characters are lowercase letters; should be: 'a'<=str[i-1] && str[i-1]<='z' && 'a'<=str[i+1] && str[i+1]<='z' && str[i-1]<str[i+1]]
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else if('A'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='Z'){ // @@ [Same error: condition does not properly check both characters are uppercase letters; should be: 'A'<=str[i-1] && str[i-1]<='Z' && 'A'<=str[i+1] && str[i+1]<='Z' && str[i-1]<str[i+1]]
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else{
                printf("%c%c%c",str[i-1],str[i],str[i+1]); // @@ [Error: prints surrounding characters again, causing duplication; should only print str[i] (the '-') because the other characters are already printed by the loop]
            }
        }
        else{
            printf("%c",str[i]);
        }
    }
    return 0;
}