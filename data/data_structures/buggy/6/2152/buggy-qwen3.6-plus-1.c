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
            if(len==100) continue; // @@ Fails to output "error " when the stack is full, and does not consume the integer to be pushed, causing subsequent inputs to be misread.
            scanf("%d",&number[len++]);
        } else if(n==-1) {
            break;
        }
    }
    
    int i=0;
    for(i=0; i<len; i++) { // @@ The problem only requires outputting the sequence of popped elements, not the remaining elements in the stack after all operations.
        printf("%d ",number[i]);
    }
}