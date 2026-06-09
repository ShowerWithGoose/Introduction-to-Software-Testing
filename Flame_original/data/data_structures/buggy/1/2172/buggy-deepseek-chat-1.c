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
     if(t==n+1){ // @@ The base case check is placed after the recursive loop, causing it to never be reached because the loop will always execute first and recurse infinitely. It should be placed before the loop to properly terminate recursion.
        for(int i=1;i<=n;i++){
            printf("%d  ",x[i]); // @@ Two spaces after %d instead of one, causing output format mismatch with expected output (each integer should be separated by a single space).
        }
        printf("\n");
    } 
} 
int main(){
    scanf("%d",&n);
    qpl(1);
    return 0;
}