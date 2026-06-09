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
            if('0'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='9'){ // @@ The condition incorrectly checks str[i-1] <= str[i+1] but does not ensure both are digits; also it does not check that str[i-1] and str[i+1] are both digits before comparing. For input "B-e", str[i-1]='B' and str[i+1]='e', this condition may be entered incorrectly because 'B' <= 'e' is true, but they are not both digits.
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else if('a'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='z'){ // @@ The condition incorrectly checks str[i-1] <= str[i+1] but does not ensure both are lowercase letters; for "B-e", str[i-1]='B' is not lowercase, yet 'a' <= 'B' is false, so this branch is skipped, but the logic is flawed because it should first check that both characters are of the same type.
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else if('A'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='Z'){ // @@ The condition incorrectly checks str[i-1] <= str[i+1] but does not ensure both are uppercase letters; for "B-e", str[i-1]='B' is uppercase, but str[i+1]='e' is not uppercase, so 'A' <= 'B' is true but 'e' <= 'Z' is false, so this branch is skipped, but the logic is flawed.
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else{
                printf("%c%c%c",str[i-1],str[i],str[i+1]); // @@ This prints the three characters again, but the loop already printed str[i-1] and str[i+1] in the else branch of the outer loop, causing duplication. For "B-e", when i=1, str[i-1]='B' was already printed in the previous iteration, and str[i+1]='e' will be printed later, so this causes "BB-ee" output.
            }
        }
        else{
            printf("%c",str[i]);
        }
    }
    return 0;
}