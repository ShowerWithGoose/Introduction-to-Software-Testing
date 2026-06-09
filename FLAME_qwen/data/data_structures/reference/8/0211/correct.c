#include<stdio.h>
#include <math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define uint unsigned int
#define uchar unsigned char

int a[110][110];
int vist[110];
int n;
int ans[110];
int l;

void DFSfind(int p){
	int j,flag=0;
	if(vist[p]){
		for(j=0;j<n;j++){
			if(a[p][j]==1&&vist[j]==0){
				DFSfind(j);
			}
		}
	}
	else{
		ans[l++]=p;
		vist[p]=1;
		for(j=0;j<n;j++){
			if(a[p][j]==1&&vist[j]==0){
				DFSfind(j);
				flag=1;
				break;
			}
		}
		if(flag)
		DFSfind(p);
	}
}

void DFS(){
	memset(vist,0,110*sizeof(int));
	memset(ans,0,110*sizeof(int));
	l=0;
	DFSfind(0);
}

void DBS(){
	int i,j,start,end,p;
	int b[110];
	memset(vist,0,110*sizeof(int));
	memset(ans,0,110*sizeof(int));
	p=0;	i=0;	start=end=-1;
	ans[i++]=p;
	vist[p]=1;
	for(j=0;j<n;j++){
		if(a[p][j]==1&&vist[j]==0){
			b[++end]=j;
		}
	}
	while(start<end){
		p=b[++start];
		if(vist[p]==0){
			ans[i++]=p;
			vist[p]=1;
			for(j=0;j<n;j++){
				if(a[p][j]==1&&vist[j]==0){
					b[++end]=j;
				}
			}	
		}	
	}
}

int main(){
	int i,m,key;
	int w1,w2;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&w1,&w2);
		a[w1][w2]=a[w2][w1]=1;
	}
	scanf("%d",&key);
	
	DFS();
	for(i=0;i<n-1;i++){
		printf("%d ",ans[i]); 
	}
	printf("%d\n",ans[i]);
	DBS();
	for(i=0;i<n-1;i++){
		printf("%d ",ans[i]); 
	}
	printf("%d\n",ans[i]);
	
	for(i=0;i<n;i++){
		a[key][i]=a[i][key]=0;
	}
	
	DFS();
	for(i=0;i<n-2;i++){
		printf("%d ",ans[i]); 
	}
	printf("%d\n",ans[i]);
	DBS();
	for(i=0;i<n-2;i++){
		printf("%d ",ans[i]); 
	}
	printf("%d\n",ans[i]);
	
	return 0;
}








