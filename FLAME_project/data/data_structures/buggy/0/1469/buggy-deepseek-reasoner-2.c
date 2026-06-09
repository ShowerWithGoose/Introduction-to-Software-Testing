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
            }else{ // @@ After the expansion loop, the end character 'a' (the right bound) should be printed. Without it, the character following '-' is lost. In this test case, 'u' and 'F' are not output.
                printf("-%c", a);
            }
        }else{
                printf("%c", a);
        }
        b=a;
    }
    return 0; // @@ The last character stored in 'b' is not printed. After the loop, a printf("%c", b) is needed to output the final character. Here 'u' and 'F' are lost.
}