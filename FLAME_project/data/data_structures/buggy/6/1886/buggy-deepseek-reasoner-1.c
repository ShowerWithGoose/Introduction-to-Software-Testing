#include <stdio.h>

int main()
{
    int s[101];
    int n=-1,i=0;
    scanf("%d",&n);
    while(n!=-1){
        if(n == 1){
            
            scanf("%d",&s[i++]);
        }else if(n == 0){
            if(s[i] == '\0'){ // @@ [incorrect empty stack check: should check i == 0 instead of comparing to '\0']
                printf("error ");
            }else{
                printf("%d ",&s[i--]); // @@ [incorrect pop: should use s[--i] to print the popped value and correctly decrement the index]
            }
        }
        scanf("%d",&n);
    }
    return 0;
 }