#include<stdio.h>
int graph[105];
int relation[105][105];
int n;
void deep_search();
void deep(int);
void wide_search();
int main(){
	int num,point;
	scanf("%d%d",&n,&num);
	for(int i=0; i<num; i++){
		int point1,point2;
		scanf("%d%d",&point1,&point2);
		relation[point1][point2]=1;
		relation[point2][point1]=1;
	}scanf("%d",&point);
	//深度优先搜索 
	for(int i=0; i<n; i++) graph[i]=1;
	deep_search();
	//广度优先搜索 
	for(int i=0; i<n; i++) graph[i]=1;
	wide_search();	
	//删数之后的深度优先搜索 
	for(int i=0; i<n; i++) graph[i]=1;
	graph[point]=0;
	deep_search();
	//删数之后的广度优先搜索 
	for(int i=0; i<n; i++) graph[i]=1;
	graph[point]=0;	
	wide_search();
	return 0;
} 
//打印函数
void print(int k[],int n){
	printf("%d",k[0]);
	for(int i=1; i<=n; i++){
		printf(" %d",k[i]);
	}printf("\n");
} 
//深度优先搜索
int stack[105],top; 
void deep_search(){	
	top=-1;
	deep(0);
	print(stack,top);
}
void deep(int i){
	stack[++top]=i;
	graph[i]=0;
	for(int j=0; j<n; j++){
		if(graph[j]!=0&&relation[i][j]==1){
			deep(j);
		}
	}
}
//广度优先搜索
void wide_search(){
	int queue[105],front=0,rear=1,temp;
	queue[front]=0;
	graph[0]=0;
	while(front<rear){
		temp=queue[front++];
		for(int j=0; j<n; j++){
			if(graph[j]!=0&&relation[temp][j]==1){
				queue[rear++]=j;
				graph[j]=0;
			}
		}
	}
	print(queue,rear-1);
}

