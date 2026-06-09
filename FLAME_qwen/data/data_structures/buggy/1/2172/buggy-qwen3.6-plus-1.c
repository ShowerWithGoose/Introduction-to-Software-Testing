#include <stdio.h>
int n;
int x[20],y[20];
void qpl(int t){
    for(int i=1;i<=n;i++){ // @@ [C89/C90 standard does not allow variable declaration inside for-loop initialization, causing a compilation error in strict/older compilers]
        if(y[i]==0){
            x[t]=i;
            y[i]=1;
            qpl(t+1);
            y[i]=0;
        }
    }
     if(t==n+1){ // @@ [The recursion base case should be placed at the beginning of the function to properly terminate; also missing a 'return' statement after printing]
        for(int i=1;i<=n;i++){ // @@ [Same C89/C90 compilation issue as line 5 regarding loop variable declaration]
            printf("%d  ",x[i]); // @@ [Uses two spaces instead of one, violating the specified output format requirement]
        }
        printf("\n");
    }
}
int main(){
    scanf("%d",&n);
    qpl(1);
    return 0;
}