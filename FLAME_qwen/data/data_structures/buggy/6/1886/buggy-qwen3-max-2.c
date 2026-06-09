#include <stdio.h>

int main()
{
    int s[101];
    int n=-1,i=0;
    scanf("%d",&n);
    while(n!=-1){
        if(n == 1){
            
            scanf("%d",&s[i++]); // @@ [Pushes value into stack but does not check for stack overflow (i >= 101)]
        }else if(n == 0){
            if(s[i] == '\0'){ // @@ [Incorrect way to check if stack is empty; 'i' points to next empty slot, and stack elements are integers, not strings]
                printf("error ");
            }else{
                printf("%d ",&s[i--]); // @@ [Printing address of s[i] instead of the value; should be s[--i] or s[i-1] with proper index handling]
            }
        }
        scanf("%d",&n);
    }
    return 0;
 }