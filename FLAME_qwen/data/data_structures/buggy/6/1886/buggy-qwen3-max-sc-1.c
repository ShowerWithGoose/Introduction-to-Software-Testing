#include <stdio.h>

int main()
{
    int s[101];
    int n=-1,i=0;
    scanf("%d",&n);
    while(n!=-1){
        if(n == 1){
            
            scanf("%d",&s[i++]); // @@ [Pushing without checking stack overflow (max capacity is 100, but i can exceed 100)]
        }else if(n == 0){
            if(s[i] == '\0'){ // @@ [Incorrect way to check if stack is empty; should check index i <= 0 instead of comparing value to '\0']
                printf("error ");
            }else{
                printf("%d ",&s[i--]); // @@ [Printing address of array element instead of the value; should be s[--i] or s[i-1] with proper index handling]
            }
        }
        scanf("%d",&n);
    }
    return 0;
 }