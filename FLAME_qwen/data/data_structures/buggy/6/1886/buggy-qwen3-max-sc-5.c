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
            if(s[i] == '\0'){ // @@ [Incorrect way to check if stack is empty. The stack pointer i should be checked against 0, not the value at s[i]. Also, s[i] may contain any integer, not necessarily '\0'.]
                printf("error ");
            }else{
                printf("%d ",&s[i--]); // @@ [Printing address of s[i] instead of its value due to incorrect use of & operator. Should print s[i-1] before decrementing or adjust logic accordingly.]
            }
        }
        scanf("%d",&n);
    }
    return 0;
 }