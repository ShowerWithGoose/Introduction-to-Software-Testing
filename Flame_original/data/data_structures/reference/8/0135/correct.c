#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int tab[105][105];
int list[105];
int queue[105];
int n,e,front,rear;                     //the number of points and sequence,the place of queue

//深度优先搜索并输出 
void DFS(int v){
	int w,i;
	printf("%d ",v);
	list[v] = 1;
	for(i=0;i<n&&(!tab[v][i]||list[i]);i++);
	while(i<n){
		w = i;
		DFS(w);
		for(;i<n&&(!tab[v][i]||list[i]);i++);
	}
}
 //广度优先搜索并输出 
void BFS(){
	int w=0;
	queue[rear++] = 0;
	list[0] = 1;
	list[w] = 1;
	while(front!=rear){
		printf("%d ",w);
		for(int i=0;i<n;i++){
			if(tab[w][i]&&!list[i]){
				queue[rear++] = i;
				list[i] = 1;
			} 
		}
		w = queue[++front];	
	}	
}

int main(){
	int x,y;                        
	int s;                          //the point to delete 
	scanf("%d %d",&n,&e);
	while(e--){
		scanf("%d %d",&x,&y);
		tab[x][y] = 1;
		tab[y][x] = 1;
	}
	scanf("%d",&s);
	DFS(0);
	memset(list,0,101);
	memset(queue,0,101);
	printf("\n");
	BFS();
	memset(list,0,101);
	memset(queue,0,101);
	printf("\n");
	for(int i=0;i<n;i++){
		tab[s][i] = 0;
		tab[i][s] = 0;
	}
	DFS(0);
	memset(list,0,101);
	memset(queue,0,101);
	printf("\n");
	BFS();
	memset(list,0,101);
	memset(queue,0,101);
	printf("\n");
	return 0;
} 

