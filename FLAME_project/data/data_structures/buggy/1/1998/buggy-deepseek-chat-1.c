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
            printf("%d",ans[i]); // @@ Missing space between numbers; expected output has spaces (e.g., "1 2" not "12")
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