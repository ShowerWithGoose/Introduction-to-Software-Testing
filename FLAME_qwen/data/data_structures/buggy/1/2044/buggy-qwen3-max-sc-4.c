#include<stdio.h>
using namespace std; // @@ [The program uses C++ syntax 'using namespace std;' but includes only C standard header <stdio.h>. This causes a compilation error in C. The reference program is written in C, so this line should be removed.]
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