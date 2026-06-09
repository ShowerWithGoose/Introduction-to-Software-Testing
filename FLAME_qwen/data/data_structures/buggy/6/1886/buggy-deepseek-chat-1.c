#include <stdio.h>

int main()
{
    int s[101];
    int n=-1,i=0;
    scanf("%d",&n);
    while(n!=-1){
        if(n == 1){
            
            scanf("%d",&s[i++]); // @@ Error: The push operation does not check if the stack is full (maximum capacity 100). Also, the index i is incremented before storing, so the first element is stored at s[0] but the reference program uses 1-based indexing. Additionally, there is no check for stack overflow.
        }else if(n == 0){
            if(s[i] == '\0'){ // @@ Error: This condition incorrectly checks if the current top element is '\0' (null character) to detect an empty stack. The stack elements are integers, not characters, and uninitialized elements may not be '\0'. The correct check should be if i == 0 (stack empty). Also, the pop operation should decrement i before accessing the element, not after.
                printf("error ");
            }else{
                printf("%d ",&s[i--]); // @@ Error: This prints the address of s[i] (&s[i--]) instead of the value s[i]. It should be printf("%d ", s[i--]) to print the popped value. Additionally, the decrement should happen after accessing the current top element, but since i points to the next empty slot, it should be i-- first, then print s[i].
            }
        }
        scanf("%d",&n);
    }
    return 0;
 }