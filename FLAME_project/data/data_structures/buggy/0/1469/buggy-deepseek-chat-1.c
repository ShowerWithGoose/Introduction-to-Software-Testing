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
            scanf("%c", &a);
            if((b>='a'&&a<='z'&&(b<a))||(b>='A'&&a<='Z'&&(b<a))||(b>='0'&&a<='9'&&(b<a))){
                for(char j = b+1; j < a; j++){
                    printf("%c", j);
                }
            }else{
                printf("-%c", a); // @@ [Error: When expansion is not performed, the program prints '-' and the character after it, but it fails to print the character before the '-'. For example, in input "a-uB-F", when processing "B-F", b='B', a='F', the condition fails because 'B' and 'F' are both uppercase but the program incorrectly checks b<a (which is true) but the type check is missing; however, the main issue is that when the else branch executes, it prints "-F" but does not print the 'B' that was read before the '-', causing the output to miss 'B'. The correct behavior should print the character before '-' (i.e., 'B') and then '-' and the character after, or handle the logic differently to ensure all characters are output.]
            }
        }else{
                printf("%c", a);
        }
        b=a;
    }
    return 0;
}