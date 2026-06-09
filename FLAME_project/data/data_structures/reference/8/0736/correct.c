#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int read() {
    int s=0,k=1;char ch;
    while(!isdigit(ch=getchar())) if(ch=='-') k=-1;
    while(isdigit(ch)) {
        s=s*10+ch-'0';
        ch=getchar();
    }
    return s*k;
}

int lnk[109][109];
int n,m,del;
int vis[109];

int dfs(int x,int dl,int bs,int dpt,int lim) {
    if(vis[x]==lim) return 1;
    if(bs) {
        if(dpt==lim && vis[x]==0) {
            printf("%d ",x);
            vis[x]=lim;
            return 1;
        }
    }else {
        printf("%d ",x);
    }   
    vis[x] = lim;
    int ret=0;
    for(int i=0;i<n;i++) {
        if(lnk[x][i] && dl!=i && vis[i]!=lim) {
            ret+=dfs(i,dl,bs,dpt+1,lim);
        }
    }
    return ret;
}

int que[10086],fir=0,las=0;

int bfs(int dl) {
    memset(vis,0,sizeof(vis));
    // for(int i=1;i<=n;i++) {
    //     dfs(0, dl, 1, 1, i);
    // }
    // puts("");
    que[las++] = 0;
    vis[0]=1;
    while(fir<las) {
        int u=que[fir++];
        if(u==dl) continue;
        printf("%d ",u);
        for(int i=0;i<n;i++) {
            if(!vis[i] && lnk[i][u]) {
                que[las++]=i;
                vis[i]=1;
            }
        }
    }
    puts("");

}

int tdfs(int dl) {
    memset(vis,0,sizeof(vis));
    dfs(0, dl, 0, 1, 1);
    puts("");
} 

int main() {
    n=read();m=read();
    for(int i=1;i<=m;i++) {
        int u=read(),v=read();
        lnk[u][v]=lnk[v][u] = 1;
    }
    del=read();
    tdfs(-1);
    bfs(-1);
    tdfs(del);
    bfs(del);

    return 0;
}



