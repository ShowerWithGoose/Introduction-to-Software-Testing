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
            if('0'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='9'){ // @@ [Condition does not ensure both characters are digits; also does not check str[i-1] is actually a digit. Should be (str[i-1]>='0' && str[i-1]<='9' && str[i+1]>='0' && str[i+1]<='9' && str[i-1]<str[i+1])]
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else if('a'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='z'){ // @@ [Condition does not ensure both characters are lowercase; should also check str[i-1]<='z' and str[i+1]>='a'.]
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else if('A'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='Z'){ // @@ [Condition does not ensure both characters are uppercase; should also check str[i-1]<='Z' and str[i+1]>='A'.]
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else{
                printf("%c%c%c",str[i-1],str[i],str[i+1]); // @@ [Prints surrounding characters again, causing duplicates. Should only print '-' character: printf("%c",str[i]);]
            }
        }
        else{
            printf("%c",str[i]);
        }
    }
    return 0;
}