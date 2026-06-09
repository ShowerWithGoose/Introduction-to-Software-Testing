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
            if('0'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='9'){ // @@ The condition incorrectly uses str[i-1] <= str[i+1] instead of checking that str[i+1] > str[i-1] and that both are digits. Also, when i==0, str[i-1] accesses out-of-bounds memory.
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else if('a'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='z'){ // @@ Same issue: condition should check str[i+1] > str[i-1] and both are lowercase letters. Also, no bounds check for i==0 or i==len-1.
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else if('A'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='Z'){ // @@ Same issue: condition should check str[i+1] > str[i-1] and both are uppercase letters. Also, no bounds check for i==0 or i==len-1.
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else{
                printf("%c%c%c",str[i-1],str[i],str[i+1]); // @@ When no expansion is performed, this prints the three characters, but the loop will also print str[i-1] and str[i+1] again in subsequent iterations, causing duplication. Also, no bounds check for i==0 or i==len-1.
            }
        }
        else{
            printf("%c",str[i]);
        }
    }
    return 0;
}