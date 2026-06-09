#include<stdio.h>
char f[100][100];
int v[100]={0};
int u[100];
int a=0,z=0;
int p;
void DFS(int v[ ],int q){
	int i;
	v[q]=1;
	printf("%d ",q);
	for(i=0;i<p;i++){
		if((!v[i])&&(f[q][i]==1)){
			DFS(v,i);
		}
	}
	}
void tDFS(int v[ ]){
	int i;
	for(i=0;i<p;i++){
		v[i]=0;
	}
	DFS(v,0);
}
void BFS(int v[ ],int q){
	int i;
	printf("%d ",q);
	v[q]=1;
	u[z++]=q;
	while(a!=z){
		q=u[a++];
		for(i=0;i<p;i++){
			if(f[q][i]==1&&(!v[i])){
				printf("%d ",i);
				v[i]=1;
				u[z++]=i;
			}
		}
	}
}
void tBFS(int v[ ]){
	int i;
	for(i=0;i<p;i++){
		v[i]=0;
	}
	BFS(v,0);
}
int main(){
	int l,i,j,x,y,dl;
	scanf("%d %d",&p,&l);
	for(i=0;i<p;i++)
		for(j=0;j<p;j++){
			f[i][j]=0;
		}
	for(i=0;i<l;i++){
		scanf("%d %d",&x,&y);
		f[x][y]=1;
		f[y][x]=1;
	}
	tDFS(v);
	printf("\n");
	tBFS(v);
	printf("\n");
	scanf("%d",&dl);
	for(i=0;i<p;i++){
		f[dl][i]=0;
		f[i][dl]=0;
	}
	tDFS(v);
	printf("\n");
	tBFS(v);
	printf("\n");
	return 0;
}

