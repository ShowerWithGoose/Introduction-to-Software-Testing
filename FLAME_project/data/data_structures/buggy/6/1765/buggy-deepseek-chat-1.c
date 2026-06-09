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

        else{
            scanf("%d ",&c); // @@ This line incorrectly reads the next operation when c is 0 (pop), but the input format has the operation code followed by the value only for push (1). For pop (0), there is no following integer, so this extra read consumes the next operation code, causing the program to skip operations.
            if(i==-1){
                printf("error ");
            }
            else{
                printf("%d ",b[i]);
                i--;
            }
        }
        scanf("%d ",&c); // @@ This line reads the next operation code, but due to the extra read in the else branch, it reads the value after a push instead of the next operation, causing the program to misinterpret the input sequence.
    }
    return 0;
}