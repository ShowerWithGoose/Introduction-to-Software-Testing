#include<stdio.h>
#include<string.h>
int juzhen[200][200],visited[105]={0},s[200];
int n,m;
void DFS(int b){
	int i;
	printf("%d ",b);
	visited[b]=1;
	for(i=0;i<n;i++)
		if (juzhen[b][i] && !visited[i])
			DFS(i);
}
void BFS(int b){
	int i,head=0,tail=1,tmp;
	s[head]=b;
	while(head<=tail){
		tmp=s[head];
		head++;
		if(visited[tmp]!=0)
            continue;
		else{
			printf("%d ",tmp);
			visited[tmp]=1;
			for(i=0;i<n;i++)
				if(juzhen[tmp][i] && !visited[i])
					s[tail++]=i;
		}
	}
}
int main(){
	int a,b,i,d;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d %d",&a,&b); //Â¼Èë¾ØÕó
		juzhen[a][b]=1;
		juzhen[b][a]=1;
	}
	DFS(0);
	printf("\n");
	memset(visited,0,sizeof(visited));
	BFS(0);
	printf("\n");
	scanf("%d",&d);
	memset(visited,0,sizeof(visited));
	visited[d]=1;
	memset(s,0,sizeof(s));


	DFS(0);
    printf("\n");
	memset(visited,0,sizeof(visited));
	visited[d]=1;
	BFS(0);
	printf("\n");
	return 0;
}

