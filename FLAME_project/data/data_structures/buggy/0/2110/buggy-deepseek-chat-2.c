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
            if('0'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='9'){ // @@ The condition incorrectly checks str[i-1] <= str[i+1] but does not ensure both are digits; also it does not check that str[i-1] and str[i+1] are both digits, allowing mixed types like 'B' and 'e' to pass. Additionally, the condition should require str[i-1] < str[i+1] for expansion, but here it uses <= which would incorrectly expand when equal.
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else if('a'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='z'){ // @@ Same issue: the condition does not ensure both characters are lowercase letters; it allows mixed types like 'B' and 'e' to be treated as lowercase because 'B' (66) is between 'a' (97) and 'z' (122) in ASCII, but 'B' is uppercase. Also uses <= instead of <.
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else if('A'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='Z'){ // @@ Same issue: condition does not ensure both are uppercase; 'e' (101) is not between 'A' and 'Z', but the condition str[i-1] <= str[i+1] with 'B' <= 'e' is true, so this branch might be taken incorrectly. Also uses <= instead of <.
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else{
                printf("%c%c%c",str[i-1],str[i],str[i+1]); // @@ This prints the characters around the dash again, but the loop already printed str[i-1] in the previous iteration (since i-1 was printed as a non-dash character). This causes duplication of the character before the dash.
            }
        }
        else{
            printf("%c",str[i]);
        }
    }
    return 0;
}