#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

int a[110][110]={0};
int v[110]={0};
int v_num,e_num;
int b[110],front=0,rear=1;
void DFS(int ver){
	printf("%d ",ver);
	v[ver]=1;
	int i;
	for(i=0;i<110;i++){
		if(a[ver][i]==1&&v[i]==0){
			DFS(i);
		}
	}
}
void BFS(int ver){
	v[ver]=1;
	int i;
	for(i=0;i<110;i++){
		if(a[ver][i]==1&&v[i]==0){
			b[rear]=i; rear++;
			v[i]=1;
		}
	}
	if(front!=rear-1){
		front++;
	    BFS(b[front]);
	}
}
int main(){
	scanf("%d%d",&v_num,&e_num);
	int i,j,k,del;
	for(i=0;i<e_num;i++){
		scanf("%d %d",&j,&k);
		a[j][k]=1; a[k][j]=1; 
	}
	scanf("%d",&del);
	int ver=0;
	
	DFS(ver); printf("\n");
	for(i=0;i<110;i++) 
	    v[i]=0;
	    
	b[0]=0;
	BFS(ver); 
	for(i=0;i<rear;i++){
		printf("%d ",b[i]);
	}printf("\n");
	for(i=0;i<110;i++) 
	    v[i]=0;
	    
	for(i=0;i<110;i++){
		a[del][i]=a[i][del]=0;
	}
	
	ver=0;
	DFS(ver); printf("\n");
	for(i=0;i<110;i++) 
	    v[i]=0; 
	    
	b[0]=0;
	for(i=0;i<110;i++)
	    b[i]=0;
	front=0; rear=1;
	BFS(ver); 
	for(i=0;i<rear;i++){
		printf("%d ",b[i]);
	}printf("\n");
	return 0;
}

