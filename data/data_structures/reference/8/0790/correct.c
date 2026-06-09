#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void dfs(int a);
void bfs(int a);
int n,m,ch[101][101],p[101],q[101],flag;
int main()
{
	int i,j,a,b;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		ch[a][b]=1;ch[b][a]=1;
	}
	scanf("%d", &i);
	dfs(0);printf("\n");
	memset(p,0,sizeof(p));
    flag=0;
	bfs(0);printf("\n");
    p[i]=1;
	flag=0;
    dfs(0);printf("\n");
    memset(p,0,sizeof(p));
    flag=0;p[i]=1;
    bfs(0);printf("\n");
	return 0;
}
void dfs(int a)
{
	int i;
    if(flag!=0)
        printf(" %d",a);
    else{
    	printf("%d",a);
        flag=1;
    }
    p[a]=1;
    for (i=1;i<=n;i++){
        if(ch[a][i]==1 && p[i]==0)
            dfs(i);
    }
}
void bfs(int a)
{
    int t,i=1,s=1,j;
    q[1]=a;
    while(i<=s){
        t=q[i];i++;
        if(p[t]==1)
            continue;
        if(flag==0){
            printf("%d",t);
            flag=1;
        }
        else
            printf(" %d",t);
        p[t]=1;
        for(j=1;j<=n;j++){
            if(ch[t][j]==1 && p[j]==0){
            	s++;
                q[s]=j;
            }
        }
    }
    memset(p,0,sizeof(p));
}





