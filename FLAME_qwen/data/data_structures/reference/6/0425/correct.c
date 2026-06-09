#include <stdio.h>
int a[101];
int main(){
    int n=0,t;
    while(scanf("%d",&t)&&t!=-1){
        if(t==1){
            if(n<100){
                scanf("%d",&a[n]);
                n++;
            }
            else{
                printf("error ");
            }
        }
        else {
            if(n>0){
                n--;
                printf("%d ",a[n]);
            }
            else{
                printf("error ");
            }
        }
    }
    return 0;
}

