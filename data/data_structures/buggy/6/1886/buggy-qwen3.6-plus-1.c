#include <stdio.h>

int main()
{
    int s[101];
    int n=-1,i=0;
    scanf("%d",&n);
    while(n!=-1){
        if(n == 1){
            
            scanf("%d",&s[i++]); // @@ Missing check for stack full condition (i >= 100), which should output "error " and prevent pushing.
        }else if(n == 0){
            if(s[i] == '\0'){ // @@ Incorrect condition for checking empty stack; array s is uninitialized so s[i] contains garbage, should check if i == 0.
                printf("error ");
            }else{
                printf("%d ",&s[i--]); // @@ Incorrectly passes the address of the element to printf instead of its value, and accesses the wrong index (should be s[--i]).
            }
        }
        scanf("%d",&n);
    }
    return 0;
 }