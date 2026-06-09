#include<stdio.h>
using namespace std; // @@ [Error: 'using namespace std;' is not valid C syntax. This is a C++ feature. In C, you must use 'std::' prefix or avoid using namespace std entirely.]
int N;
int A[15],mk[15];
void dfs(int n){
    if(n==N+1){
        for(int i=1;i<n;i++)printf("%d ",A[i]); // @@ [Error: In C, variables cannot be declared inside the for loop initializer. Use 'int i;' before the loop and then 'for(i=1;...)' instead.]
        puts("");
    }
    for(int i=1;i<=N;i++){ // @@ [Error: Same issue as above; 'int i' declaration inside for loop is not allowed in C.]
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