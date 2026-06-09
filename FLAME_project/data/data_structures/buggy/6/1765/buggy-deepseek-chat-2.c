#include<stdio.h>
int main(){
    int b[100];
    int c;
    int i=-1;
    scanf("%d ",&c); // @@ The format string "%d " with a trailing space will cause scanf to consume whitespace after the number, potentially skipping the next input or causing issues with reading the sequence correctly. Use "%d" instead.
    while(c!=-1){
        if(c==1){
        scanf("%d ",&c); // @@ Same issue: trailing space in format string. Also, this reads the value to push into c, but then the next scanf at the end of the loop will read the next operation, potentially skipping or misreading input. The logic for reading input is flawed.
        if(i==100){
            printf("error ");
        }
        else{
            i++;
            b[i]=c;
        }
    }

        else{
            scanf("%d ",&c); // @@ Same trailing space issue. For a pop operation (c==0), this reads the next integer, which should be the next operation, not a value. This incorrectly consumes the next operation.
            if(i==-1){
                printf("error ");
            }
            else{
                printf("%d ",b[i]);
                i--;
            }
        }
        scanf("%d ",&c); // @@ This extra scanf at the end of the loop causes the program to read an additional integer each iteration, skipping operations and leading to incorrect behavior. The input reading logic should be restructured.
    }
    return 0;
}