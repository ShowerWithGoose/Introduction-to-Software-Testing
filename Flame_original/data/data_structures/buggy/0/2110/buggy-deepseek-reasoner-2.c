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
            if('0'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='9'){ // @@ [Missing boundary check for i==0 or i==len-1; condition should also verify both characters are digits and that left < right (not <=)]
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else if('a'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='z'){ // @@ [Same boundary and logic errors as above]
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else if('A'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='Z'){ // @@ [Same boundary and logic errors as above]
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else{
                printf("%c%c%c",str[i-1],str[i],str[i+1]); // @@ [Printing left and right characters again causes duplication; should only print the '-' character]
            }
        }
        else{
            printf("%c",str[i]);
        }
    }
    return 0;
}