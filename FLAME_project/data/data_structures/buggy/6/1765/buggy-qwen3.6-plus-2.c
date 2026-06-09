#include<stdio.h>
int main(){
    int b[100];
    int c;
    int i=-1;
    scanf("%d ",&c);
    while(c!=-1){
        if(c==1){
        scanf("%d ",&c);
        if(i==100){
            printf("error ");
        }
        else{
            i++;
            b[i]=c;
        }
    }

        else{ // @@ The logic for handling '0' (pop) and other numbers is incorrect. The problem states '0' is pop, but this branch handles anything that isn't '1'. Also, it consumes an extra integer via scanf which is wrong for a pop operation.
            scanf("%d ",&c); // @@ This scanf incorrectly consumes the next token from input. For a '0' operation (pop), there is no following integer to consume. This causes the program to skip operations or misinterpret data.
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