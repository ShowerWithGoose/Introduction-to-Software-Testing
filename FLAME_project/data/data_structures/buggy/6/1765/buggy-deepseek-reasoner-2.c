#include<stdio.h>
int main(){
    int b[100];
    int c;
    int i=-1;
    scanf("%d ",&c);
    while(c!=-1){
        if(c==1){
        scanf("%d ",&c);
        if(i==100){ // @@ condition should check if stack is full (i == 99), not i == 100; otherwise push when full causes out-of-bounds and no error is printed.
            printf("error ");
        }
        else{
            i++;
            b[i]=c;
        }
    }

        else{
            scanf("%d ",&c); // @@ this scanf is incorrect for a pop operation; it consumes the next integer from input (the next operation) instead of using the current c as the operation. This causes the program to skip pop operations and misread subsequent pushes.
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