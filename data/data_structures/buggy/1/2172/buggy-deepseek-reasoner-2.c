#include <stdio.h>
int n;
int x[20],y[20];
void qpl(int t){
    for(int i=1;i<=n;i++){ // @@ [Compilation error: variable declaration inside for loop is not allowed in C89; use separate declaration int i;]
        if(y[i]==0){
            x[t]=i;
            y[i]=1;
            qpl(t+1);
            y[i]=0;
        }
    }
     if(t==n+1){
        for(int i=1;i<=n;i++){ // @@ [Compilation error: variable declaration inside for loop is not allowed in C89; use separate declaration int i;]
            printf("%d  ",x[i]); // @@ [Output format error: uses two spaces between numbers, but should use a single space as per problem specification]
        }
        printf("\n");
    } 
} 
int main(){
    scanf("%d",&n);
    qpl(1);
    return 0;
}