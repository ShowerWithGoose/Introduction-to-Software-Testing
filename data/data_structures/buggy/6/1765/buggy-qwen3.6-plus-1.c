#include<stdio.h>
int main(){
    int b[100];
    int c;
    int i=-1;
    scanf("%d ",&c); // @@ Trailing space in format string causes scanf to wait for non-whitespace input, potentially causing the program to hang or misread subsequent inputs.
    while(c!=-1){
        if(c==1){
        scanf("%d ",&c); // @@ Trailing space in format string causes scanf to wait for non-whitespace input.
        if(i==100){ // @@ Off-by-one error: array size is 100 (indices 0-99), so stack is full when i==99. Checking i==100 allows out-of-bounds access to b[100].
            printf("error ");
        }
        else{
            i++;
            b[i]=c;
        }
    }

        else{
            scanf("%d ",&c); // @@ Incorrectly reads the next operation code into c. Pop operation (0) does not take an argument, so this erroneously consumes the next input token and desynchronizes the loop.
            if(i==-1){
                printf("error ");
            }
            else{
                printf("%d ",b[i]);
                i--;
            }
        }
        scanf("%d ",&c); // @@ Trailing space in format string causes scanf to wait for non-whitespace input.
    }
    return 0;
}