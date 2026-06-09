#include <stdio.h>

int main()
{
    int s[101];
    int n=-1,i=0;
    scanf("%d",&n);
    while(n!=-1){
        if(n == 1){
            
            scanf("%d",&s[i++]); // @@ [Pushing without checking if stack is full (i >= 101)]
        }else if(n == 0){
            if(s[i] == '\0'){ // @@ [Incorrect way to check if stack is empty; 'i' points to next empty slot, and stack elements are integers, not strings]
                printf("error ");
            }else{
                printf("%d ",&s[i--]); // @@ [Printing address of element (&s[i--]) instead of the value (s[--i])]
            }
        }
        scanf("%d",&n);
    }
    return 0;
 }