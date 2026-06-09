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
            if(s[i] == '\0'){ // @@ [Incorrectly checks for empty stack by comparing with '\0'; should check index i <= 0 instead]
                printf("error ");
            }else{
                printf("%d ",&s[i--]); // @@ [Prints address of s[i--] instead of the value; should be s[--i] or s[i-1] before decrementing]
            }
        }
        scanf("%d",&n);
    }
    return 0;
 }