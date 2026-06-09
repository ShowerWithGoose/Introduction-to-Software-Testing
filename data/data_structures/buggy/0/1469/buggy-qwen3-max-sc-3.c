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
            scanf("%c", &a); @@ [The variable 'b' is used uninitialized on the first occurrence of '-', leading to undefined behavior. Also, after reading the character following '-', the loop does not account for it in the next iteration properly.]
            if((b>='a'&&a<='z'&&(b<a))||(b>='A'&&a<='Z'&&(b<a))||(b>='0'&&a<='9'&&(b<a))){ @@ [The condition checks only one side of the type range (e.g., b is lowercase but a could be uppercase). It should ensure both characters are of the same category. Also, the condition structure allows mixed-type cases like b='a' and a='Z' to pass if b<a, which violates the requirement.]
                for(char j = b+1; j < a; j++){ @@ [The loop condition should be j <= a to include the ending character as per the problem's example (a-d becomes abcd).]
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