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
            scanf("%c", &a); // @@ [The condition checks use 'a' and 'b', but after reading the next character into 'a', the original left character is in 'b'. However, the type compatibility check is missing: it doesn't ensure both characters are of the same category (e.g., both lowercase, both digits, etc.). Also, the loop prints from b+1 to a-1, but should include 'a' as per problem (e.g., a-d → abcd).]
            if((b>='a'&&a<='z'&&(b<a))||(b>='A'&&a<='Z'&&(b<a))||(b>='0'&&a<='9'&&(b<a))){ // @@ [Incorrect range checks: e.g., b>='a' && a<='z' does not guarantee both are lowercase. Should check both b and a are in same range. Also, expansion should include the end character 'a', but loop condition is j < a, so it stops before 'a'.]
                for(char j = b+1; j < a; j++){ // @@ [Loop condition should be j <= a to include the end character as per example a-d → abcd.]
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