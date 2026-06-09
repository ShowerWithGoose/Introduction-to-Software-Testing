#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#define max(a, b) ( (a > b) ? (a) : (b) )
#define min(a, b) ( (a < b) ? (a) : (b) )
int main () {
    char a;
    char b;
    while(scanf("%c", &a)!=EOF){
        if(a=='-'){
            scanf("%c", &a); // @@ [The condition checks use 'a' and 'b', but after reading the next character into 'a', the original left character is in 'b'. However, the type compatibility check is missing: it doesn't ensure both characters are of the same category (e.g., both lowercase, both digits, etc.). For example, 'a' could be a digit and 'b' a letter, and the condition might still pass if ASCII values satisfy b < a. Also, the loop prints from b+1 to a-1, but should include 'a' as per problem (e.g., a-d => abcd).]
            if((b>='a'&&a<='z'&&(b<a))||(b>='A'&&a<='Z'&&(b<a))||(b>='0'&&a<='9'&&(b<a))){ // @@ [Incorrect range checks: e.g., b>='a' && a<='z' does not guarantee both are lowercase. Should check b>='a' && b<='z' && a>='a' && a<='z'. Same issue for uppercase and digits. This allows mixed-type cases like b='a' (lowercase) and a='Z' (uppercase) to incorrectly pass if b<a in ASCII.]
                for(char j = b+1; j < a; j++){ // @@ [Loop condition should be j <= a to include the ending character as per problem requirement (e.g., a-d expands to abcd, which includes 'd'). Current code stops at a-1, so outputs abc for a-d.]
                    printf("%c", j);
                }
            }else{
                printf("-%c", a);
            }
        }else{
                printf("%c", a);
        }
        b=a;
    }
    return 0;
}