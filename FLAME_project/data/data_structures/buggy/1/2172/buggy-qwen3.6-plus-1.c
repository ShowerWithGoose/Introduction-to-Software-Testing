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
            printf("%d  ",x[i]); // @@ The format string "%d  " prints two spaces after each number, but the expected output requires single space separation (e.g., "1 2" instead of "1  2  "). It should be "%d " or handled to avoid trailing spaces.
        }
        printf("\n");
    } 
} 
int main(){
    scanf("%d",&n);
    qpl(1);
    return 0;
}