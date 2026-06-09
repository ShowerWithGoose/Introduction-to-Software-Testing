#include <stdio.h>

int main()
{
    int s[101];
    int n=-1,i=0;
    scanf("%d",&n);
    while(n!=-1){
        if(n == 1){
            
            scanf("%d",&s[i++]); // @@ [Missing check for stack overflow (i >= 100). Also, i is incremented before checking capacity.]
        }else if(n == 0){
            if(s[i] == '\0'){ // @@ [Incorrect way to check if stack is empty. Should check index i == 0, not value at s[i]. Also, s[i] is uninitialized when i==0.]
                printf("error ");
            }else{
                printf("%d ",&s[i--]); // @@ [Printing address of s[i] instead of its value. Should be s[--i] or s[i-1] with proper decrement.]
            }
        }
        scanf("%d",&n);
    }
    return 0;
 }