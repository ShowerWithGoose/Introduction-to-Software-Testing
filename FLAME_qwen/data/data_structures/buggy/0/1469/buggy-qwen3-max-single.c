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
            scanf("%c", &a); @@ // The variable 'b' is used uninitialized in the first iteration when '-' is encountered; also, condition checks mix types incorrectly (e.g., b>='a' && a<='z' doesn't ensure both are same type)
            if((b>='a'&&a<='z'&&(b<a))||(b>='A'&&a<='Z'&&(b<a))||(b>='0'&&a<='9'&&(b<a))){ @@ // Logical error: conditions do not verify that both 'b' and 'a' belong to the same category (e.g., b could be lowercase and a uppercase but still pass part of the condition)
                for(char j = b+1; j < a; j++){ @@ // Loop should be j <= a to include the end character as per problem requirement (expand a-d to abcd, which includes 'd')
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