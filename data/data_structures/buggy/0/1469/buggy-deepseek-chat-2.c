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
                for(char j = b+1; j < a; j++){ // @@ The loop condition should be j <= a to include the last character, and the initial value should be b+1, but the expansion should start from the character after b and include a. However, the problem requires expanding a-d to abcd, meaning the output should include b, c, d. The loop should print from b+1 to a inclusive. Also, the character after '-' is read into a, overwriting the original a, which is correct for the expansion logic, but the condition check uses the new a (the character after '-') and b (the character before '-'). The logic is correct except the loop should be j <= a.
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