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
            if(len==100) continue; // @@ [Error: When the stack is full, the program should output "error " and continue, but here it just continues without printing "error ". According to the problem, if a push operation is attempted when the stack is full, output "error " followed by a space.]
            scanf("%d",&number[len++]);
        } else if(n==-1) {
            break;
        }
    }
    
    int i=0;
    for(i=0; i<len; i++) { // @@ [Error: After all operations, the program should not output the remaining elements in the stack. The problem only requires outputting the sequence of popped elements during operations, not the final stack contents. This extra loop causes the buggy output to include extra numbers like "2 5" at the end.]
        printf("%d ",number[i]);
    }
}