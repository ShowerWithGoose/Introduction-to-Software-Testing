#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int number[1000];
int main() {
    int n,nums,len=0;
    
    while(1) {
        scanf("%d",&n);
        if(n==0) {
            if(len==0) {
                printf("error ");
                continue;
            } else {
                printf("%d ",number[len-1]);
                number[len-1]=0;
                len--;
            }
        } else if(n==1) {
            if(len==100) continue; // @@ [Error: When stack is full, should output "error " instead of silently ignoring the push operation.]
            scanf("%d",&number[len++]);
        } else if(n==-1) {
            break;
        }
    }
    
    int i=0; // @@ [Error: This variable is used only for the following loop which prints leftover stack contents; such output is not required by the problem specification.]
    for(i=0; i<len; i++) { // @@ [Error: This loop outputs elements still in the stack after operations end, which is not part of the required output (only popped elements should be printed).]
        printf("%d ",number[i]); // @@ [Error: Printing remaining elements is incorrect; the program should not output anything after the operation sequence ends.]
    }
}