#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void DFS(int a[][100],int visited[],int v,int n){
	int w,k;
	printf("%d ",v);
	visited[v]=1;
	for(k=0;k<n;k++){
		if(a[v][k]==1){
			w=k;
			break;
		}
	}
	if(k==n){
		w=-1;
	}
	while(w!=-1){
		if(visited[w]==0){
			DFS(a,visited,w,n);
		}
		for(k=k+1;k<n;k++){
		  if(a[v][k]==1){
			w=k;
			break;
		  }
	    }
	    if(k==n){
		   w=-1;
	    }
	}
}
void BFS(int a[][100],int visited[],int v,int n,int dui[],int sign){
	int w,k;
	printf("%d ",v);
	visited[v]=1;
	dui[sign]=v;
	sign++;
	while(sign!=0){
		v=dui[0];
		for(k=0;dui[k+1]!=-1;k++){
			dui[k]=dui[k+1];
		}
		dui[k]=-1;
		sign=sign-1;
		for(k=0;k<n;k++){
		  if(a[v][k]==1){
			w=k;
			break;
		  }
	    }
	    if(k==n){
		  w=-1;
	    }
	    while(w!=-1){
	    	if(visited[w]==0){
	    		printf("%d ",w);
	    		dui[sign]=w;
	            sign++;
	            visited[w]=1;
			}
		    for(k=k+1;k<n;k++){
		      if(a[v][k]==1){
			    w=k;
			    break;
		      }
	        }
	        if(k==n){
		       w=-1;
	        }	
		}
	}
}

int main()
{
	int n,e,i,j,a[100][100],x,y,s;
	int visited[100]={0};
	int dui[100];
	for(i=0;i<100;i++){
		for(j=0;j<100;j++){
			a[i][j]=0;
		}
	}
	scanf("%d%d",&n,&e);
	for(i=0;i<e;i++){
		scanf("%d%d",&x,&y);
		a[x][y]=1;
		a[y][x]=1;
	}
	scanf("%d",&s);
	
	for(i=0;i<n;i++){
		visited[i]=0;
	}
	DFS(a,visited,0,n);
	printf("\n");
	for(i=0;i<n;i++){
		visited[i]=0;
	}
	for(i=0;i<n;i++){
		dui[i]=-1;
	}
	BFS(a,visited,0,n,dui,0);
	printf("\n");
	
	for(i=0;i<n;i++){
		a[s][i]=0;
		a[i][s]=0;
	}
	
	for(i=0;i<n;i++){
		visited[i]=0;
	}
	DFS(a,visited,0,n);
	printf("\n");
	for(i=0;i<n;i++){
		visited[i]=0;
	}
	for(i=0;i<n;i++){
		dui[i]=-1;
	}
	BFS(a,visited,0,n,dui,0);
	printf("\n");
	return 0;
} 

