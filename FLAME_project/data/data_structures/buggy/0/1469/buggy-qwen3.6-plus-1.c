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
            if((b>='a'&&a<='z'&&(b<a))||(b>='A'&&a<='Z'&&(b<a))||(b>='0'&&a<='9'&&(b<a))){ // @@ The condition checks if 'a' is within a specific range (e.g., 'a'<='z') but fails to check if 'b' is in the same corresponding range (e.g., 'b'>='a'). For example, if b='u' and a='B', the condition `b>='a'` is true, but `a<='z'` is also true for 'B'? No, 'B' is not <= 'z' in ASCII? Wait, 'B' (66) is <= 'z' (122). So `b>='a'` (true) and `a<='z'` (true) and `b<a` (false). This part is okay. However, the logic for checking types is flawed. It should ensure both are lowercase, or both uppercase, or both digits. The current condition `(b>='a'&&a<='z'...)` mixes bounds. It should be `(b>='a' && b<='z' && a>='a' && a<='z')` etc. More critically, the loop below excludes the end character.
                for(char j = b+1; j < a; j++){ // @@ The loop condition `j < a` excludes the character `a` itself from the expansion. According to the problem description (expand a-d to abcd), the end character must be included. It should be `j <= a`.
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