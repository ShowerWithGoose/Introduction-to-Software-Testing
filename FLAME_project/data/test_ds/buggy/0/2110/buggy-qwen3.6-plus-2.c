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
            if('0'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='9'){ // @@ The comparison should be strictly less than ('<') instead of less than or equal ('<=') because the problem requires the character after '-' to be strictly greater than the one before it.
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else if('a'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='z'){ // @@ The comparison should be strictly less than ('<') instead of less than or equal ('<=') because the problem requires the character after '-' to be strictly greater than the one before it.
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else if('A'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='Z'){ // @@ The comparison should be strictly less than ('<') instead of less than or equal ('<=') because the problem requires the character after '-' to be strictly greater than the one before it.
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else{
                printf("%c%c%c",str[i-1],str[i],str[i+1]); // @@ This prints the surrounding characters which are already printed (or will be printed) by the loop's other iterations, causing duplication. It should only print str[i] (the '-' itself).
            }
        }
        else{
            printf("%c",str[i]);
        }
    }
    return 0;
}