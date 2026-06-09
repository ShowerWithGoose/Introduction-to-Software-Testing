#include <stdio.h>

int main()
{
    int s[101];
    int n=-1,i=0;
    scanf("%d",&n);
    while(n!=-1){
        if(n == 1){
            
            scanf("%d",&s[i++]); // @@ [This line incorrectly assumes that after reading '1', the next integer is always available and valid to push. However, it does not check for stack overflow (i >= 100). Also, the increment happens before checking capacity.]
        }else if(n == 0){
            if(s[i] == '\0'){ // @@ [This condition is incorrect: it checks if the value at s[i] is '\0' (which is 0), but i points to the next empty slot, so s[i] is uninitialized or garbage. The correct check for an empty stack is if i == 0.]
                printf("error ");
            }else{
                printf("%d ",&s[i--]); // @@ [This prints the address of s[i--] instead of the value. It should be s[--i] to first decrement i then access the top element. Also, i-- decrements after use, which would access an invalid index.]
            }
        }
        scanf("%d",&n);
    }
    return 0;
 }