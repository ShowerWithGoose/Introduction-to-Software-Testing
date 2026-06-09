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
            scanf("%c", &a); @@ // The variable 'b' is used uninitialized in the first iteration when '-' is encountered; also, after reading the character following '-', the condition checks use 'b' and 'a', but 'b' may not hold the correct preceding character due to overwriting 'a' before checking.
            if((b>='a'&&a<='z'&&(b<a))||(b>='A'&&a<='Z'&&(b<a))||(b>='0'&&a<='9'&&(b<a))){ @@ // The condition incorrectly checks only one side of the type range (e.g., b>='a' but a<='z'), which allows mixed-type cases like 'a'-'Z' to pass if ASCII values align; it should ensure both characters are of the same category.
                for(char j = b+1; j < a; j++){ @@ // The loop condition should be j <= a to include the ending character as per problem description (e.g., a-d should become abcd, but this outputs only b and c).
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