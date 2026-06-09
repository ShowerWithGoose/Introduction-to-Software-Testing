#include<stdio.h>
int main(){
    int b[100];
    int c;
    int i=-1;
    scanf("%d ",&c); // @@ The format string "%d " expects a space after the integer, which may cause issues with input parsing. Use "%d" instead.
    while(c!=-1){
        if(c==1){
        scanf("%d ",&c); // @@ This reads the next integer into c, overwriting the operation code. The push value should be stored separately, not in c. Also, the format string "%d " has the same issue.
        if(i==100){
            printf("error ");
        }
        else{
            i++;
            b[i]=c;
        }
    }

        else{
            scanf("%d ",&c); // @@ For pop (0) or end (-1), this reads the next integer, which is incorrect. The next input should be the next operation, not read here. Also, the format string "%d " has the same issue.
            if(i==-1){
                printf("error ");
            }
            else{
                printf("%d ",b[i]);
                i--;
            }
        }
        scanf("%d ",&c); // @@ This reads the next operation, but due to the previous scanf calls, the input stream may be misaligned. Also, the format string "%d " has the same issue.
    }
    return 0;
}