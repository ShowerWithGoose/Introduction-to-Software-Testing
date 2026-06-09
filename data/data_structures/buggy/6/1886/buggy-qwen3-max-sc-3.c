#include <stdio.h>

int main()
{
    int s[101];
    int n=-1,i=0;
    scanf("%d",&n);
    while(n!=-1){
        if(n == 1){
            
            scanf("%d",&s[i++]); // @@ [Pushes value into stack but does not check for stack overflow (max capacity is 100). If i reaches 101, it writes beyond array bounds.]
        }else if(n == 0){
            if(s[i] == '\0'){ // @@ [Incorrect way to check if stack is empty. The stack uses integer values; uninitialized or popped elements are not guaranteed to be '\0'. Should check index i <= 0 instead.]
                printf("error ");
            }else{
                printf("%d ",&s[i--]); // @@ [Printing address of s[i] using & instead of the value. Should print s[i-1] before decrementing, or adjust logic to access correct top element. Also, i-- after accessing wrong index.]
            }
        }
        scanf("%d",&n);
    }
    return 0;
 }