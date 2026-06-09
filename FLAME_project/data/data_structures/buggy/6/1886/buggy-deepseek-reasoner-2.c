#include <stdio.h>

int main()
{
    int s[101];
    int n=-1,i=0;
    scanf("%d",&n);
    while(n!=-1){
        if(n == 1){
            
            scanf("%d",&s[i++]); // @@ error: missing check for stack full (i should be < 100)
        }else if(n == 0){
            if(s[i] == '\0'){ // @@ error: condition should check i==0 for empty stack
                printf("error ");
            }else{
                printf("%d ",&s[i--]); // @@ error: should print value s[--i] with correct decrement order
            }
        }
        scanf("%d",&n);
    }
    return 0;
 }