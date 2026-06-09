#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#define max(a, b) ( (a > b) ? (a) : (b) )
#define min(a, b) ( (a < b) ? (a) : (b) )
int main () {
    char a;
    char b; @@ // @@ Uninitialized variable b leads to undefined behavior when used in the condition below.
    while(scanf("%c", &a)!=EOF){
        if(a=='-'){
            scanf("%c", &a);
            if((b>='a'&&a<='z'&&(b<a))||(b>='A'&&a<='Z'&&(b<a))||(b>='0'&&a<='9'&&(b<a))){ @@ // @@ Condition does not check that both b and a are within the same character range; it only checks one boundary of each. For example, b='a' and a='9' would incorrectly pass the lowercase check because a<='z' is true. It should require both characters to be in the same range (e.g., b>='a' && b<='z' && a>='a' && a<='z').
                for(char j = b+1; j < a; j++){ @@ // @@ Loop uses strict less than, so it prints from b+1 to a-1, omitting the last character a. Should be j <= a to include the character after the hyphen.
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