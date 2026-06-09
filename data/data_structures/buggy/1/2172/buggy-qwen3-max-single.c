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
            printf("%d  ",x[i]); // @@ [The output uses two spaces between numbers, but the problem requires single space separation. Also, this print block is placed after the loop, so it never executes when t == n+1 because the function returns from recursion before reaching this point. The base case check should come before the loop.]
        }
        printf("\n");
    } 
} 
int main(){
    scanf("%d",&n);
    qpl(1);
    return 0;
}