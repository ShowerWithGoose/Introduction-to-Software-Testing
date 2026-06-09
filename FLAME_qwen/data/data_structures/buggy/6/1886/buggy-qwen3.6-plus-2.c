#include <stdio.h>

int main()
{
    int s[101];
    int n=-1,i=0;
    scanf("%d",&n);
    while(n!=-1){
        if(n == 1){
            
            scanf("%d",&s[i++]); // @@ Missing check for stack full condition (overflow)
        }else if(n == 0){
            if(s[i] == '\0'){ // @@ Incorrect condition to check if stack is empty; should check if i == 0
                printf("error ");
            }else{
                printf("%d ",&s[i--]); // @@ Prints memory address instead of value due to '&', and incorrect pop logic; should be s[--i]
            }
        }
        scanf("%d",&n);
    }
    return 0;
 }