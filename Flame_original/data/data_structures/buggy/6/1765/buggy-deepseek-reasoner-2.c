#include<stdio.h>
int main(){
    int b[100];
    int c;
    int i=-1;
    scanf("%d ",&c);
    while(c!=-1){
        if(c==1){
        scanf("%d ",&c);
        if(i==100){ // @@ Error: Condition should check if stack is full, i.e., i>=99. i==100 will never be true because i is index (max 99) when full. This results in stack overflow without proper error detection.
            printf("error ");
        }
        else{
            i++;
            b[i]=c;
        }
    }

        else{
            scanf("%d ",&c); // @@ Error: This extra read consumes the next token, but pop operation (0) has no following value. This causes misalignment of input parsing.
            if(i==-1){
                printf("error ");
            }
            else{
                printf("%d ",b[i]);
                i--;
            }
        }
        scanf("%d ",&c);
    }
    return 0;
}