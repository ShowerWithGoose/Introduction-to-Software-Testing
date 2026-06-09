#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define ll long long
int n;
int ans[15];
int flag[15];
void dfs(int x){
    if(x==n){
        for(int i=0;i<n;i++){
            printf("%d",ans[i]); // @@ [Missing space after each number; output format requires space separation]
        }
        printf("\n");
        return;
    }
    for(int i=1;i<=n;i++){
        if(!flag[i]){
            ans[x]=i;
            flag[i]=1;
            dfs(x+1);
            flag[i]=0;
        }
    }
    return ;
}
int main(){
    scanf("%d",&n);
    dfs(0);
    return 0;
}