#include<stdio.h>
int main(){
    int b[100];
    int c;
    int i=-1;
    scanf("%d ",&c); // @@ The format string "%d " expects a space after the integer, which may cause issues with input parsing. Use "%d" instead.
    while(c!=-1){
        if(c==1){
        scanf("%d ",&c); // @@ The format string "%d " expects a space after the integer, which may cause issues with input parsing. Use "%d" instead.
        if(i==100){
            printf("error ");
        }
        else{
            i++;
            b[i]=c;
        }
    }

        else{
            scanf("%d ",&c); // @@ The format string "%d " expects a space after the integer, which may cause issues with input parsing. Use "%d" instead.
            if(i==-1){
                printf("error ");
            }
            else{
                printf("%d ",b[i]);
                i--;
            }
        }
        scanf("%d ",&c); // @@ The format string "%d " expects a space after the integer, which may cause issues with input parsing. Use "%d" instead.
    }
    return 0;
}