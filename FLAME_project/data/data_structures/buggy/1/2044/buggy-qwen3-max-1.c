#include<stdio.h>
using namespace std; @@ [This line causes a compilation error because 'using namespace std;' is C++ syntax and not valid in C. The program is compiled as C code (evident from #include<stdio.h> and lack of C++ headers), so this line must be removed.]
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