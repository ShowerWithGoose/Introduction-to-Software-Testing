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
            scanf("%d ",&c); @@
            if(i==-1){
                printf("error ");
            }
            else{
                printf("%d ",b[i]);
                i--;
            }
        }
        scanf("%d ",&c); @@
    }
    return 0;
}