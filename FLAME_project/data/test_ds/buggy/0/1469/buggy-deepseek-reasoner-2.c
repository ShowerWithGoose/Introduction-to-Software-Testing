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
            if((b>='a'&&a<='z'&&(b<a))||(b>='A'&&a<='z'&&(b<a))||(b>='0'&&a<='9'&&(b<a))){ // @@ The condition for uppercase should check a<='Z' instead of a<='z', but this error does not affect the current test case because uppercase letters are still <= 'z'.
                for(char j = b+1; j < a; j++){
                    printf("%c", j);
                } // @@ After expanding the range, the code does not print the ending character 'a' (the second endpoint). This causes the loss of the ending character in the output, as seen with missing 'u' from first expansion and missing 'F' from second expansion.
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