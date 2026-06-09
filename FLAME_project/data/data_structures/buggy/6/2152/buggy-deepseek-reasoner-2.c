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
            if(len==100) continue; // @@ [When stack is full, should print "error " and then read the value to consume input. Currently it just continues, causing misalignment.]
            scanf("%d",&number[len++]);
        } else if(n==-1) {
            break;
        }
    }
    
    int i=0;
    for(i=0; i<len; i++) { // @@ [This loop prints the remaining elements in the stack, which is not required. Only popped elements should be output.]
        printf("%d ",number[i]); // @@ [This line prints remaining elements, causing extra output.]
    }
}