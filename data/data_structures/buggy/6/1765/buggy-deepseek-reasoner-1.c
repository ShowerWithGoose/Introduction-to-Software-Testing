#include<stdio.h>
int main(){
    int b[100];
    int c;
    int i=-1;
    scanf("%d ",&c); @@ // trailing space in scanf causes input reading issues
    while(c!=-1){
        if(c==1){
        scanf("%d ",&c); @@ // reads push value but overwrites operation code; also trailing space
        if(i==100){ @@ // condition should be i>=99 for full stack (array size 100)
            printf("error ");
        }
        else{
            i++;
            b[i]=c;
        }
    }

        else{ @@ // this block executes for both pop (0) and end (-1) operations, but also contains an extra scanf
            scanf("%d ",&c); @@ // pop operation does not have an integer argument; this reads the next operation incorrectly
            if(i==-1){
                printf("error ");
            }
            else{
                printf("%d ",b[i]);
                i--;
            }
        }
        scanf("%d ",&c); @@ // extra read at loop end, combined with earlier reads misaligns input parsing
    }
    return 0;
}