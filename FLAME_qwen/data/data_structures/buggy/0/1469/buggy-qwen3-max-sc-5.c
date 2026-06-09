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
            scanf("%c", &a); @@ [The condition checks `b` and `a` but does not verify that both characters belong to the same category (e.g., both lowercase, both uppercase, or both digits). Also, the condition uses `a<='z'` etc. without checking the type of `b`, leading to incorrect expansions like 'a-R'. Additionally, the loop prints from `b+1` to `a-1`, missing the final character `a`.]
            if((b>='a'&&a<='z'&&(b<a))||(b>='A'&&a<='Z'&&(b<a))||(b>='0'&&a<='9'&&(b<a))){
                for(char j = b+1; j < a; j++){ @@ [Loop condition should be `j <= a` to include the end character in expansion. Current code omits the last character.]
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