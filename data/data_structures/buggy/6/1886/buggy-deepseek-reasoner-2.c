#include <stdio.h>

int main()
{
    int s[101];
    int n=-1,i=0;
    scanf("%d",&n);
    while(n!=-1){
        if(n == 1){
            
            scanf("%d",&s[i++]); // @@ [No overflow check: should verify if i < 100 before push, otherwise print "error". Also i may exceed array bounds.]
        }else if(n == 0){
            if(s[i] == '\0'){ // @@ [Incorrect empty check: s[i] is uninitialized. Should check if i == 0 to detect underflow.]
                printf("error ");
            }else{
                printf("%d ",&s[i--]); // @@ [Prints address of s[i], not value. Should print value and decrement correctly: e.g., printf("%d ", s[--i]);]
            }
        }
        scanf("%d",&n);
    }
    return 0;
 }