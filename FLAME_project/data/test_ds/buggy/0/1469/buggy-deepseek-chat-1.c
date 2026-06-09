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
                printf("-%c", a); // @@ [Error: When expansion is not performed, the program prints '-' and the character after it, but it fails to print the character before the dash (b) that was already read. In the reference program, the character before the dash is printed in the main loop before processing the dash, so here the output is missing that character, leading to incorrect output like "BCDE" instead of "uBCDEF".]
            }
        }else{
                printf("%c", a);
        }
        b=a;
    }
    return 0;
}