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
                printf("-%c", a); // @@ The else branch prints the hyphen and the character after it, but when the expansion condition fails, the original hyphen and the character after it should be output unchanged. However, the character before the hyphen (stored in b) has already been printed in the previous iteration (when a was not '-'), so this is correct. The bug is that when the expansion condition succeeds, the character 'a' (the end character) is not printed after the loop. The loop prints from b+1 to a-1, but 'a' itself is missing. The expected output includes the end character.
            }
        }else{
                printf("%c", a);
        }
        b=a;
    }
    return 0;
}