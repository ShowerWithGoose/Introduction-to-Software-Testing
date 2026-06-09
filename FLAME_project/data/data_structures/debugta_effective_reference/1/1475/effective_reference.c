
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int vis[15];
int ans[15];
int n;
int cnt=0;
int f(int x){
    int ans=1;
    for(int i=1;i<=x;i++){
        ans*=i;
    }
    return ans;
}
void dfs(int x){
    int i;
    if(x==n+1){
        for(i=1;i<=n;i++){
            printf("%d",ans[i]);
            if(i!=n)printf(" ");
            else if(cnt!=f(n)-1)printf("\n"); 
        }

        cnt++;
        return ;
    }
    for(i=1;i<=n;i++){
        if(vis[i]==0){
            ans[x]=i;
            vis[i]=1;
            dfs(x+1);
            vis[i]=0;
        }
    }
    return;
}
int main()
{
    scanf("%d",&n);
    dfs(1);
    return 0;
}


