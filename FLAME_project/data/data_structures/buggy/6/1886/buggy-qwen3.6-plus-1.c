#include <stdio.h>

int main()
{
    int s[101];
    int n=-1,i=0; // @@ [Variable i is initialized to 0, but it is used as the index of the next available slot. However, the logic for checking empty/full and accessing elements is flawed compared to the reference.]
    scanf("%d",&n);
    while(n!=-1){
        if(n == 1){
            
            scanf("%d",&s[i++]); // @@ [This pushes the element correctly if we assume i points to the next free slot, but there is no check for stack overflow (capacity 100).]
        }else if(n == 0){
            if(s[i] == '\0'){ // @@ [Error 1: Checking s[i] for null character is incorrect. The stack status should be tracked by the index i (i==0 means empty). Error 2: s[i] contains uninitialized garbage or the next free slot, not the top element.]
                printf("error ");
            }else{
                printf("%d ",&s[i--]); // @@ [Error 1: &s[i--] prints the memory address of the element, not the value. It should be s[--i]. Error 2: The order of decrement matters. If i points to the next free slot, the top element is at i-1. So we should decrement i first then access s[i], or access s[i-1] then decrement. The reference uses pre-decrement on a count variable. Here, if i is the count/next-index, we need s[--i].]
            }
        }
        scanf("%d",&n);
    }
    return 0;
 }