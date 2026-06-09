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
            if('0'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='9'){ @@ // The condition 'str[i-1] <= str[i+1]' is checked before verifying that both characters are digits, which may lead to incorrect expansion when one is not a digit. Also, boundary checks for i-1 and i+1 being valid indices are missing.
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else if('a'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='z'){ @@ // Same issue: the range check assumes both ends are lowercase letters without first confirming they are, and lacks bounds safety for i-1 and i+1.
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else if('A'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='Z'){ @@ // Same issue: no validation that both characters are uppercase letters before comparing, and no array bounds checking.
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else{
                printf("%c%c%c",str[i-1],str[i],str[i+1]); @@ // This prints three characters at once, but in the loop, each character is normally printed individually. This causes duplication: e.g., for "B-e", when i=1 ('-'), it prints "B-e", but then when i=0 and i=2 are processed separately, 'B' and 'e' get printed again, leading to "BB-ee".
            }
        }
        else{
            printf("%c",str[i]);
        }
    }
    return 0;
}