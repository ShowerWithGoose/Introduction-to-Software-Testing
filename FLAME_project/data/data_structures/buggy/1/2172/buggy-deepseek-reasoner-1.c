#include <stdio.h>
int n;
int x[20],y[20];
void qpl(int t){
    for(int i=1;i<=n;i++){
        if(y[i]==0){
            x[t]=i;
            y[i]=1;
            qpl(t+1);
            y[i]=0;
        }
    }
     if(t==n+1){
        for(int i=1;i<=n;i++){
            printf("%d  ",x[i]); // @@ The format "%d  " prints two spaces after each number, should be "%d " (single space) to match expected output.
        }
        printf("\n");
    } 
} 
int main(){
    scanf("%d",&n);
    qpl(1);
    return 0;
}