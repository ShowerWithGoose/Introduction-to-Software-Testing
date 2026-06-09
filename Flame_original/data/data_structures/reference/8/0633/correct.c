/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
int m,n,line[102][102],Visited[102],flag=0,a,b,c;
int queue[102];
int front=0,rear=101,count=0;
void DFS(int v);
void in(int temp);
void BFS(int v);
int out();

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		line[a][b]=1;
        line[b][a]=1;
	}
	scanf("%d",&c);
	for(int i=0;i<n;i++)
		Visited[i]=0;
	DFS(0);//删除前深度 
	printf("\n");
	for(int i=0;i<n;i++)
		Visited[i]=0;
	BFS(0);//删除前广度 
	for(int i=0;i<102;i++)
        queue[i]=-1;
    printf("\n");
    for(int i=0;i<n;i++)
		Visited[i]=0;
    Visited[c]=1;
    DFS(0);
    printf("\n");
    for(int i=0;i<n;i++)
		Visited[i]=0;
	Visited[c]=1;
	for(int i=0;i<102;i++)
        queue[i]=-1;
    BFS(0);
    printf("\n");
    return 0; 
}
void DFS(int v){
    printf("%d ",v);
    Visited[v]=1;//标记已经访问过
    for(int i=0;i<n;i++){
        if(line[v][i]&&!Visited[i]){//如果有边且没有访问过
            DFS(i);
        }
    }
}
void in(int temp){
	count++;
    Visited[temp]=1;
    rear=(rear+1)%102;
    queue[rear]=temp;
}
void BFS(int v){
    in(v);
    while(count!=0){//只要队列不空
        int temp=out();//出队
        printf("%d ",temp);
        for(int i=0;i<n;i++){//将与此结点相连且未访问的结点加入队列
            if(!Visited[i]&&line[i][temp]){
                in(i);
            }
        }
    }
}
int out(){
    count--;
    int temp;
    temp=queue[front];
    front=(front+1)%102;
    return temp;
}


