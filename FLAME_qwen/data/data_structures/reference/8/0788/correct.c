#include<stdio.h>
int map[200][200],a[200],i,n,m,x,y,z;
void DFS(int i);
void BFS(int n);
int main(){
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d %d",&x,&y);
		map[x][y]=1;
		map[y][x]=1;
	}
	scanf("%d",&z);
	DFS(0);
	printf("\n");
	for(i=0;i<200;i++)
	a[i]=0;
	BFS(n); 
	printf("\n");
	for(i=0;i<n;i++){
		map[z][i]=0;
		map[i][z]=0;
	}
	for(i=0;i<n;i++)
	a[i]=0;
	DFS(0);
	printf("\n");
	for(i=0;i<n;i++)
	a[i]=0;
	BFS(n-1);	
}
void DFS(int i){
	int j;
	a[i]=1;
	printf("%d ",i);
	for(j=0;j<n;j++)
	    if(map[i][j]==1&&a[j]==0)
		DFS(j);
}
void BFS(int k){
	int s[200]={0},j=0,t=0,f=0;
	s[t++]=0;
	a[0]=1;
	while(t!=k){
		for(j=0;j<n;j++){
			if(map[s[f]][j]&&!a[j]){
				a[j]=1;
			    s[t++]=j;
			}
		}
		f++;
	}
	for(j=0;j<k;j++)
	printf("%d ",s[j]);
}

