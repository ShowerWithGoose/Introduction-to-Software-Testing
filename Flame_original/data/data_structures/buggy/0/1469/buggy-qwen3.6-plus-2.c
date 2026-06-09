#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#define max(a, b) ( (a > b) ? (a) : (b) )
#define min(a, b) ( (a < b) ? (a) : (b) )
int main () {
    char a;
    char b; // @@ Variable 'b' is uninitialized, which may lead to undefined behavior if the input string starts with '-'.
    while(scanf("%c", &a)!=EOF){
        if(a=='-'){
            scanf("%c", &a);
            if((b>='a'&&a<='z'&&(b<a))||(b>='A'&&a<='Z'&&(b<a))||(b>='0'&&a<='9'&&(b<a))){ // @@ Missing upper bound checks for 'b' (e.g., b<='z', b<='Z', b<='9'), which can incorrectly trigger expansion for characters outside the valid ranges.
                for(char j = b+1; j < a; j++){ // @@ Loop condition 'j < a' excludes the end character; it should be 'j <= a' to correctly include the character after '-'.
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