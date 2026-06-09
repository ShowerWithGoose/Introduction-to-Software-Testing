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
                printf("-%c", a); // @@ [When expansion condition fails, it should print '-' followed by the next character 'a', but this causes duplication of 'a' later because 'b=a' is executed after. Also, the loop condition in for-loop uses 'j < a' instead of 'j <= a', so it misses printing the last character of the range.]
            }
        }else{
                printf("%c", a);
        }
        b=a; // @@ [The variable 'b' is used before being initialized in the first iteration, leading to undefined behavior. Additionally, after handling a '-', the next character 'a' is assigned to 'b', but in the failure case, 'a' has already been printed as part of "printf(\"-%c\", a);", and will be printed again in the next iteration if it's not '-', causing duplication.]
    }
    return 0;
}