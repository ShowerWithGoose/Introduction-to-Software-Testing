#include <stdio.h>

int main()
{
    int s[101];
    int n=-1,i=0;
    scanf("%d",&n);
    while(n!=-1){
        if(n == 1){
            
            scanf("%d",&s[i++]); // @@ [Pushes without checking stack overflow; stack capacity is 100 but index i can go beyond 100]
        }else if(n == 0){
            if(s[i] == '\0'){ // @@ [Incorrect way to check if stack is empty; 'i' points to next available slot, and stack elements are not null-terminated]
                printf("error ");
            }else{
                printf("%d ",&s[i--]); // @@ [Printing address of s[i] instead of value; should be s[i-1] or adjust index before printing]
            }
        }
        scanf("%d",&n);
    }
    return 0;
 }