# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>

# define ll long long
int vcnt,ecnt,map[110][110],x,y,vis[110],queue[110],cnt;
void dfs(int t){
    if(vis[t])return;
    vis[t]++;
    printf("%d ",t);
    for(int i=1;i<vcnt;i++){
        if(map[t][i])dfs(i);
    }
};
int main() {
    scanf("%d%d",&vcnt,&ecnt);
    for(int i=0;i<ecnt;i++){
        scanf("%d%d",&x,&y);
        map[x][y]++;
        map[y][x]++;
    }
    dfs(0);
    puts("");
    for(int i=0;i<vcnt;i++)vis[i]=0;
    queue[0]=0;
    int l=0,r=0;
    while(l<=r){
        while(vis[queue[l]])l++;
        if(l>r)break;
        vis[queue[l]]++;
        printf("%d ",queue[l]);
        for(int i=1;i<vcnt;i++){
            if(map[queue[l]][i])queue[++r]=i;
        }
    }
    for(int i=0;i<vcnt;i++)vis[i]=0;
    scanf("%d",&x);
    vis[x]=1;
    puts("");
    dfs(0);
    puts("");
    for(int i=0;i<vcnt;i++)vis[i]=0;
    vis[x]=1;
    l=0,r=0;
    while(l<=r){
        while(vis[queue[l]])l++;
        if(l>r)break;
        vis[queue[l]]++;
        printf("%d ",queue[l]);
        for(int i=1;i<vcnt;i++){
            if(map[queue[l]][i])queue[++r]=i;
        }
    }
}
