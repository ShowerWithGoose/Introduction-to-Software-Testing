#include <stdio.h>

int main()
{
    int s[101];
    int n=-1,i=0;
    scanf("%d",&n);
    while(n!=-1){
        if(n == 1){
            
            scanf("%d",&s[i++]); // @@ Error: When n==1, the next integer is the value to push, but the code does not check if the stack is full (i==100). Pushing when full should output "error".
        }else if(n == 0){
            if(s[i] == '\0'){ // @@ Error: The condition s[i] == '\0' is incorrect for checking if the stack is empty. The stack is empty when i==0. Also, s[i] may not be '\0' even if the stack is empty, and '\0' could be a valid pushed value.
                printf("error ");
            }else{
                printf("%d ",&s[i--]); // @@ Error: Should print the value s[--i] (decrement first), not the address &s[i--]. Also, i-- decrements after the expression, so it accesses the wrong index.
            }
        }
        scanf("%d",&n);
    }
    return 0;
 }