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
    gets(str); // @@ [gets() is unsafe and deprecated; may cause compilation error in strict C11; also no boundary check for hyphen at start/end]
    int len=strlen(str);
    for(int i=0;i<len;i++){
        if(str[i]=='-'){
            if('0'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='9'){ // @@ [Missing boundary check for i==0 or i==len-1; condition should ensure both sides are digits and first < second, but uses <= and does not properly restrict str[i-1] to digit range]
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else if('a'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='z'){ // @@ [Missing boundary check; condition should ensure both are lowercase and first < second; missing upper bound for str[i-1] and lower bound for str[i+1]; uses <= instead of <]
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else if('A'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='Z'){ // @@ [Missing boundary check; same issues as lowercase branch]
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else{
                printf("%c%c%c",str[i-1],str[i],str[i+1]); // @@ [Prints surrounding characters again, causing duplication; should only print hyphen; also lacks boundary check]
            }
        }
        else{
            printf("%c",str[i]);
        }
    }
    return 0;
}