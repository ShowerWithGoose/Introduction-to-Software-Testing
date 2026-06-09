#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
int a[500],b[500];
int aa[500]={0},bb[500]={0};
int hold[500][500]={0};
int m,n,p;
void dfs(int v){
	int i;
	if(v==0){
		printf("%d",v);
	}
	else{
		printf(" %d",v);
	}
	aa[v]=1;
	for(i=1;i<=m;i++){
		if(hold[v][i]==1&&aa[i]==0){
		    dfs(i);
		}
	}
}

void bfs(int v){//aa：走过的点；bb：输出的点 
	int i,j,k,l;
	bb[1]=v;
	for(j=1,k=1;j<=k;){
		i=bb[j++];
		if(aa[i]==1){
			continue;//跳出当前循环，进入下一次循环 
		}
		printf("%d ",i); 
	    aa[i]=1;
	    for(l=1;l<m;l++){
	    	if(hold[i][l]==1&&aa[l]==0){
	    		bb[++k]=l;
			}
		}
	}
}

int main(){
	int i,j;
	scanf("%d%d",&m,&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&a[i],&b[i]);
		hold[a[i]][b[i]]=1;
		hold[b[i]][a[i]]=1;
	}
	scanf("%d",&p);
	dfs(0);
	printf("\n");
	
	for(i=0;i<n;i++){
		aa[i]=0;
	}
	bfs(0);
	printf("\n");
	
	for(i=0;i<n;i++){
		aa[i]=0;
	}
	aa[p]=1;
	dfs(0);
	printf("\n");
	
	for(i=0;i<n;i++){
		aa[i]=0;
	}
	aa[p]=1;
	bfs(0);
	printf("\n");
	
	return 0;
}



