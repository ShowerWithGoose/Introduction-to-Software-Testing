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
            scanf("%c", &a); @@ // The variable 'b' is used uninitialized in the first iteration when '-' is encountered; also, after reading the character following '-', the type compatibility check is incorrect (e.g., checks b>='a' && a<='z', which mixes types)
            if((b>='a'&&a<='z'&&(b<a))||(b>='A'&&a<='Z'&&(b<a))||(b>='0'&&a<='9'&&(b<a))){ @@ // Logical condition is flawed: it doesn't ensure both characters are of the same category (e.g., b could be lowercase and a uppercase but still pass part of the condition); also, uses unverified 'b' which may be uninitialized
                for(char j = b+1; j < a; j++){ @@ // Should be j <= a to include the end character as per problem requirement (expand a-d to abcd, inclusive)
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