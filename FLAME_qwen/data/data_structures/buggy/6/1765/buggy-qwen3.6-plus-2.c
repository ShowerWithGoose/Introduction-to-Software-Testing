#include<stdio.h>
int main(){
    int b[100];
    int c;
    int i=-1;
    scanf("%d ",&c); // @@ Trailing space in format string causes scanf to skip whitespace and wait for non-whitespace input, potentially hanging the program.
    while(c!=-1){
        if(c==1){
        scanf("%d ",&c); // @@ Trailing space in format string causes input buffering issues.
        if(i==100){ // @@ Off-by-one error: array b has size 100 (indices 0-99). Stack is full when i==99, so condition should be i==99.
            printf("error ");
        }
        else{
            i++;
            b[i]=c;
        }
    }

        else{
            scanf("%d ",&c); // @@ Pop operation does not have a following value; this scanf incorrectly consumes the next operation code from input.
            if(i==-1){
                printf("error ");
            }
            else{
                printf("%d ",b[i]);
                i--;
            }
        }
        scanf("%d ",&c); // @@ Trailing space in format string causes input buffering issues.
    }
    return 0;
}