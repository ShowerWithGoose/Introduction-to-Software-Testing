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
            if('0'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='9'){ // @@ The condition incorrectly checks str[i-1] <= str[i+1] as part of the range check, but it should first verify both characters are digits, then separately check str[i-1] < str[i+1]. This logic also fails to ensure both characters are digits before comparing them.
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else if('a'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='z'){ // @@ Same issue as above: the condition mixes range and ordering checks incorrectly. It should first check both are lowercase letters, then separately check str[i-1] < str[i+1].
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else if('A'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='Z'){ // @@ Same issue as above: the condition mixes range and ordering checks incorrectly. It should first check both are uppercase letters, then separately check str[i-1] < str[i+1].
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else{
                printf("%c%c%c",str[i-1],str[i],str[i+1]); // @@ This prints the characters around '-' even when they are not of the same type or the order is wrong, but it also prints them when the '-' is at the beginning or end of the string, causing out-of-bounds access. Additionally, for cases like "B-e", it prints "B-e" correctly, but the buggy output shows "BB-ee" because the previous conditions incorrectly matched and printed extra characters.
            }
        }
        else{
            printf("%c",str[i]);
        }
    }
    return 0;
}