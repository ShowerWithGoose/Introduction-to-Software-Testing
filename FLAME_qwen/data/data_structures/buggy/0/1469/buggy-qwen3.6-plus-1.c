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
            if((b>='a'&&a<='z'&&(b<a))||(b>='A'&&a<='Z'&&(b<a))||(b>='0'&&a<='9'&&(b<a))){ // @@ Logical error: The condition fails to check the upper bound for `b` and the lower bound for `a` (e.g., missing `b<='z'` and `a>='a'`), allowing invalid characters to pass the type validation.
                for(char j = b+1; j < a; j++){ // @@ Compilation error: Declaring a variable (`char j`) inside the `for` loop initializer is not supported in C89/C90 standards, which will cause a compilation failure on strict compilers.
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