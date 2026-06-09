#include <stdio.h>

int main()
{
    int s[101];
    int n=-1,i=0;
    scanf("%d",&n);
    while(n!=-1){
        if(n == 1){
            
            scanf("%d",&s[i++]); // @@ The push operation does not check if the stack is full (i == 100). According to the problem, if a push is attempted when the stack is full, "error" should be output.
        }else if(n == 0){
            if(s[i] == '\0'){ // @@ This condition incorrectly checks if the top element is '\0' to detect an empty stack. The stack should be considered empty when i == 0. Also, '\0' is a valid integer value (0), so this check is semantically wrong.
                printf("error ");
            }else{
                printf("%d ",&s[i--]); // @@ The format specifier should be "%d" with s[i--], not "&s[i--]". Using &s[i--] prints the address of the element, not its value.
            }
        }
        scanf("%d",&n);
    }
    return 0;
 }