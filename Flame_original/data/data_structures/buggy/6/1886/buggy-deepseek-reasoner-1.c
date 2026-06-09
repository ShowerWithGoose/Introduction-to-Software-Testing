#include <stdio.h>

int main()
{
    int s[101];
    int n=-1,i=0;
    scanf("%d",&n);
    while(n!=-1){
        if(n == 1){
            
            scanf("%d",&s[i++]); // @@ Missing stack full check: should output "error " if i >= 100 before pushing
        }else if(n == 0){
            if(s[i] == '\0'){ // @@ Incorrect emptiness check: should check if i == 0 (stack empty), not compare with '\0' (which is 0) on an uninitialized slot
                printf("error ");
            }else{
                printf("%d ",&s[i--]); // @@ Wrong: prints address instead of value, and decrements after accessing wrong index; should be printf("%d ", s[--i]);
            }
        }
        scanf("%d",&n);
    }
    return 0;
 }