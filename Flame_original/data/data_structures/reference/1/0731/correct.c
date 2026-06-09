#include<stdio.h>
int n;
int ans[10];
int bool[10];
void Ans(){
    for(int i=0;i<n;i++){
        printf("%d ",ans[i]);
    }
    puts("");
}
void dfs(int m){
    if(m==n+1){
        Ans();
        return;
    }
    for(int i=0;i<n;i++){
        if(!bool[i]){
            ans[m-1]=i+1;
            bool[i]=1;
            dfs(m+1);
            bool[i]=0;
        }
    }
}
int main(){
    scanf("%d",&n);
    dfs(1);
    return 0;
}


