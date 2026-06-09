#include <stdio.h>

int main()
{
    int s[101];
    int n=-1,i=0;
    scanf("%d",&n);
    while(n!=-1){
        if(n == 1){
            
            scanf("%d",&s[i++]); // @@ Error: The push operation does not check for stack overflow (i > 100). Also, the index i is incremented before storing, so the first element is stored at s[0] but the reference program uses 1-based indexing. The capacity check is missing.
        }else if(n == 0){
            if(s[i] == '\0'){ // @@ Error: This condition incorrectly checks if the current element is null character, but the stack stores integers, not strings. It should check if the stack is empty (i == 0). Also, the pop should decrement i before accessing the element, not after.
                printf("error ");
            }else{
                printf("%d ",&s[i--]); // @@ Error: Using &s[i--] prints the address of the element, not the value. Should be s[i--] (without &). Also, the pop should decrement i first, then access s[i], but here it accesses s[i] then decrements, which is incorrect for stack behavior.
            }
        }
        scanf("%d",&n);
    }
    return 0;
 }