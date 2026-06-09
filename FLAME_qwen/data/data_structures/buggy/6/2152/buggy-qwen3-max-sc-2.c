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
            if(len==100) continue; // @@ [When the stack is full (len == 100), the program silently skips the push operation instead of printing "error ". According to the problem, attempting to push when the stack is full should output "error ".]
            scanf("%d",&number[len++]);
        } else if(n==-1) {
            break;
        }
    }
    
    int i=0;
    for(i=0; i<len; i++) { // @@ [After processing all operations, the program incorrectly prints the remaining elements in the stack. The problem only requires outputting popped elements (or "error") during pop operations, not the final stack contents.]
        printf("%d ",number[i]);
    }
}