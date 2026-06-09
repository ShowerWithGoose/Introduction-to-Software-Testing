
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int vis[15];
int num[15];
int N;
int cnt=0;
int f(int x){
    int ans=1;
    for(int i=1;i<=x;i++){
        ans*=i;
    }
    return ans;
}
void dfs(int step){
    int i;
    if(step==N+1){
        for(i=1;i<=N;i++){
            printf("%d",num[i]);
            if(i!=N)printf(" ");
            else if(cnt!=f(N)-1)printf("\n"); 
        }

        cnt++;
        return ;
    }
    for(i=1;i<=N;i++){
        if(vis[i]==0){
            num[step]=i;
            vis[i]=1;
            dfs(step+1);
            vis[i]=0;
        }
    }
    return;
}
int main()
{
    scanf("%d",&N);
    dfs(1);
    return 0;
}


