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
            if(len==100) { // @@ The problem requires outputting "error " when pushing to a full stack, but this code just continues without printing anything.
                printf("error "); // @@ Added to fix the missing error output for stack overflow.
                continue;
            }
            scanf("%d",&number[len++]);
        } else if(n==-1) {
            break;
        }
    }
    
    int i=0;
    for(i=0; i<len; i++) { // @@ The problem states "After all operations have been performed, the stack may not be empty" and does NOT require printing the remaining elements. This loop incorrectly prints the remaining stack contents, causing extra output like "2 5" in the buggy output.
        printf("%d ",number[i]); // @@ This line should be removed or commented out as per problem description which only asks for popped elements sequence.
    }
}