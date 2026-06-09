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
            if(len==100) continue; @@ [When the stack is full (len == 100), the program should output "error " for a push attempt, but instead it silently skips the operation.]
            scanf("%d",&number[len++]);
        } else if(n==-1) {
            break;
        }
    }
    
    int i=0;
    for(i=0; i<len; i++) { @@ [The problem requires only the popped elements to be printed during pop operations. This extra loop prints remaining stack elements at the end, which is not part of the expected output.]
        printf("%d ",number[i]);
    }
}