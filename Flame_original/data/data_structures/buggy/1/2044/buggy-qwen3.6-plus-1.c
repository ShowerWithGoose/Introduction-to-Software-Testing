#include<stdio.h>
using namespace std;
int N;
int A[15],mk[15];
void dfs(int n){
    if(n==N+1){
        for(int i=1;i<n;i++)printf("%d ",A[i]);
        puts(""); // @@ Missing return statement after printing the permutation. Without it, the function continues to execute the loop below, leading to incorrect output or stack overflow.
    }
    for(int i=1;i<=N;i++){
        if(mk[i])continue;
        mk[i]=1;A[n]=i;
        dfs(n+1);
        mk[i]=0;
    }
}
int main(){
    scanf("%d",&N);
    dfs(1);
    return 0; 
}