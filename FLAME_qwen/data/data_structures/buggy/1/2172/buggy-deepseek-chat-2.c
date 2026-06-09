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
     if(t==n+1){ // @@ The condition check is placed after the loop, causing the base case to be executed after all recursive calls return, but the loop will also run when t==n+1, leading to incorrect behavior because the loop accesses x[t] and y[i] with t out of valid range (t=n+1, but x and y are indexed from 1 to n). The base case should be checked before the loop to properly terminate recursion.
        for(int i=1;i<=n;i++){
            printf("%d  ",x[i]); // @@ Extra space after %d causes output format mismatch (two spaces instead of one between numbers).
        }
        printf("\n");
    } 
} 
int main(){
    scanf("%d",&n);
    qpl(1);
    return 0;
}