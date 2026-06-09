#include <stdio.h>

int main()
{
    int s[101];
    int n=-1,i=0;
    scanf("%d",&n);
    while(n!=-1){
        if(n == 1){
            
            scanf("%d",&s[i++]); // @@ [Pushes without checking stack full condition (max capacity 100). i can exceed 100 leading to buffer overflow.]
        }else if(n == 0){
            if(s[i] == '\0'){ // @@ [Incorrect way to check if stack is empty. Stack elements are integers, not strings; s[i] is uninitialized or invalid when i==0. Should check i <= 0 instead.]
                printf("error ");
            }else{
                printf("%d ",&s[i--]); // @@ [Printing address of s[i] instead of its value. Should be s[--i] or s[i-1] with proper index handling. Also, post-decrement logic is flawed.]
            }
        }
        scanf("%d",&n);
    }
    return 0;
 }