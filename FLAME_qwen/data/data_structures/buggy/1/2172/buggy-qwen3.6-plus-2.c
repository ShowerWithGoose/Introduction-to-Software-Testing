#include <stdio.h>
int n;
int x[20],y[20];
void qpl(int t){
    for(int i=1;i<=n;i++){ // @@ The base case condition should be checked before this loop to prevent infinite recursion.
        if(y[i]==0){
            x[t]=i;
            y[i]=1;
            qpl(t+1);
            y[i]=0;
        }
    }
     if(t==n+1){ // @@ This check is placed after the loop, causing infinite recursion as the function never returns when t == n+1.
        for(int i=1;i<=n;i++){
            printf("%d  ",x[i]); // @@ Uses two spaces instead of one, which does not match the required output format.
        }
        printf("\n");
    }  // @@ Missing 'return;' statement after printing, which is necessary to stop the recursion and backtrack correctly.
} 
int main(){
    scanf("%d",&n);
    qpl(1);
    return 0;
}