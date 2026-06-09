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
            if('0'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='9'){ // @@ The condition incorrectly checks str[i-1] <= str[i+1] but does not ensure both characters are digits; also it does not check that str[i-1] and str[i+1] are within the digit range properly. The logic should first verify both are digits and then compare, but the condition is flawed because it uses str[i-1] <= str[i+1] as part of the range check, which is not correct for validating digit type.
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else if('a'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='z'){ // @@ Similar issue: the condition does not properly ensure both characters are lowercase letters; it uses str[i-1] <= str[i+1] as a range check, which is incorrect. It should separately check that str[i-1] >= 'a' and str[i+1] <= 'z' and that str[i-1] < str[i+1].
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else if('A'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='Z'){ // @@ Same problem: the condition does not correctly validate both characters are uppercase letters; it incorrectly uses str[i-1] <= str[i+1] as part of the range check.
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else{
                printf("%c%c%c",str[i-1],str[i],str[i+1]); // @@ This prints the characters around the '-' even when they are not of the same type or when the left character is greater than or equal to the right, but it also prints the '-' itself. However, the main issue is that when the condition fails (e.g., 'B' and 'e' are different types), this else branch prints the three characters, but the loop also prints the characters before and after the '-' from the else branch of the outer if-else, leading to duplication. For input "B-e", it prints 'B' from the else branch of the outer loop, then when i points to '-', it enters this else and prints "B-e", then prints 'e' from the next iteration, resulting in "BB-ee".
            }
        }
        else{
            printf("%c",str[i]);
        }
    }
    return 0;
}