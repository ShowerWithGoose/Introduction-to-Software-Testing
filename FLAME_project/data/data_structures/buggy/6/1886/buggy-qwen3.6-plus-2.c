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
            if(i == 0){ // @@ The condition `s[i] == '\0'` is incorrect for checking if the stack is empty. It should check the stack pointer `i`. Also, accessing `s[i]` when `i` points to the next free slot or uninitialized memory is undefined/incorrect logic for emptiness.
                printf("error ");
            }else{
                printf("%d ",s[--i]); // @@ The original code `&s[i--]` prints the address of the element and decrements `i` after use (post-decrement), which accesses the wrong index (one past the top) and passes a pointer instead of the value. It should be `s[--i]` to pre-decrement the index to the current top element and pass the value.
            }
        }
        scanf("%d",&n);
    }
    return 0;
 }