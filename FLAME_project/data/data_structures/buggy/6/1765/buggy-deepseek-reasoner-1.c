#include<stdio.h>
int main(){
    int b[100];
    int c;
    int i=-1;
    scanf("%d ",&c); // @@ Error: trailing space in scanf may cause reading issues; should be "%d" without space
    while(c!=-1){
        if(c==1){
        scanf("%d ",&c); // @@ Error: trailing space in scanf may cause reading issues; also this scanf overwrites the operation code with the value
        if(i==100){ // @@ Error: condition should be i==99 or i>=99 to detect full stack before pushing; i==100 will never be true
            printf("error ");
        }
        else{
            i++;
            b[i]=c;
        }
    }

        else{
            scanf("%d ",&c); // @@ Error: this scanf is in the pop/else block, but pop operation (0) has no following integer; this reads the next operation prematurely, causing the program to skip operations
            if(i==-1){
                printf("error ");
            }
            else{
                printf("%d ",b[i]);
                i--;
            }
        }
        scanf("%d ",&c); // @@ Error: trailing space in scanf may cause reading issues; should be "%d" without space
    }
    return 0;
}