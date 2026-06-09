#include<stdio.h>
#include<string.h>
int a[110][110]={0};
int vertex[200]={0};
int sdbl(int i,int max,int shanchu){
	printf("%d ",i);
	vertex[i]=1;
	for(int j=0;j<=max;j++){
		if(a[i][j]!=0&&vertex[j]==0&&j!=shanchu){
			sdbl(j,max,shanchu);
		}
	}
}
int dl[1000],rear=-1,front=0;
int gdbl(int i,int max,int shanchu){
	rear=-1;
	front=0;
	memset(vertex,0,sizeof(vertex));//
	memset(dl,0,sizeof(dl));
	dl[++rear]=0;
	vertex[0]=1;
	while(rear>=front){
		i=dl[front++];
		printf("%d ",i);
		for(int j=0;j<=max;j++){
			if(a[i][j]!=0&&vertex[j]==0&&j!=shanchu){
				vertex[j]=1;
				dl[++rear]=j;
			}
		}
	}
	printf("\n");
}
int main(){
	int nvertex,nedge,temint1,temint2,shanchu;
	scanf("%d%d",&nvertex,&nedge);
	for(int i=0;i<nedge;i++){
		scanf("%d%d",&temint1,&temint2);
		a[temint1][temint2]=1;
		a[temint2][temint1]=1;
	}
	scanf("%d",&shanchu);
	sdbl(0,nvertex-1,-1);
	printf("\n");
	gdbl(0,nvertex-1,-1);
	memset(vertex,0,sizeof(vertex));
	sdbl(0,nvertex-1,shanchu);
	printf("\n");
	gdbl(0,nvertex-1,shanchu);
}
