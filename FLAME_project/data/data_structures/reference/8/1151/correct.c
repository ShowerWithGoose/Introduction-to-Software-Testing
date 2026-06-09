#include<stdio.h>
#include<string.h>
#define cin(k) scanf("%d",&k)
int a[105][105];
int n,m,del,l=1,r;
int v[105],s[105];
void bfs()
{
    s[++r]=0;
    v[0]=1;
    while(l<=r)
    {
        int k=s[l++];
        printf("%d ",k);
        for(int q=1;q<=n;q++)
            if(a[k][q]&&!v[q])
                s[++r]=q,v[q]=1;
    }
}
void dfs(int k)
{
    printf("%d ",k);
    for(int q=1;q<=n;q++)
        if(a[k][q]&&!v[q])
            v[q]=1,dfs(q);
}
signed main()
{
    cin(n),cin(m);
    for(int q=1;q<=m;q++)
    {
        int s,t;
        cin(s),cin(t);
        a[s][t]=a[t][s]=1;
    }
    cin(del);
    dfs(0);
    memset(v,0,sizeof(v));
    printf("\n");
    v[0]=1;
    bfs();
    memset(v,0,sizeof(v));
    printf("\n");
    for(int q=0;q<=n;q++)
        a[del][q]=a[q][del]=0;
    l=1,r=0;
    dfs(0);
    memset(v,0,sizeof(v));
    printf("\n");
    v[0]=1;
    bfs();
    printf("\n");
}
