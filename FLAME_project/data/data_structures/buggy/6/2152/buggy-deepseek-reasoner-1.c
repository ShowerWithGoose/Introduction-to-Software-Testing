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
            if(len==100) continue; // @@ Missing "error " output when stack is full
            scanf("%d",&number[len++]);
        } else if(n==-1) {
            break;
        }
    }
    
    int i=0;
    for(i=0; i<len; i++) { // @@ This loop incorrectly prints remaining stack contents; only popped elements and errors should be output
        printf("%d ",number[i]);
    }
}