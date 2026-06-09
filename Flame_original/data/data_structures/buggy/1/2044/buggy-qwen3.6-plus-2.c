#include<stdio.h>
using namespace std; // @@ This is C++ syntax and causes a compilation error when the code is compiled as C. It is unnecessary since the program only uses C standard I/O functions.
int N;
int A[15],mk[15];
void dfs(int n){
    if(n==N+1){
        for(int i=1;i<n;i++)printf("%d ",A[i]);
        puts("");
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