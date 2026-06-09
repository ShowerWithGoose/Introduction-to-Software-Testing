#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
bool weight[105][105],visit[105];
int que[200];
int poi,s;
void ins_B(){
	memset(visit,0,sizeof(visit));
}
void ins_D(){
	memset(visit,0,sizeof(visit));
	memset(que,0,sizeof(que));
}
void delect(int p){
	visit[p]=1;
}
void travel_BFS(int p){
    int head=0,tail=1,temp,i;
	que[head]=p;
	while(head<=tail){
		temp=que[head];
		head++;
		if(visit[temp])continue;
		else{
			printf("%d ",temp);
			visit[temp]=1;
			for(i=0;i<poi;i++)
			if(weight[temp][i]&&visit[i]==0)
			que[tail++]=i;
		}
	}	
}
void travel_DFS(int p){
	int i;
	printf("%d ",p);
	visit[p]=1;
	for(i=0;i<poi;i++)
	if(weight[p][i]&&visit[i]==0)
	travel_DFS(i);
}

int main(){
	int i;
	scanf("%d %d",&poi,&s);
	int p1,p2,point;
	for(i=1;i<=s;i++){
		scanf("%d %d",&p1,&p2);
		weight[p1][p2]=1;
		weight[p2][p1]=1;
	}
	travel_DFS(0);printf("\n");
	ins_B();
	travel_BFS(0);printf("\n");
	
	scanf("%d",&point);
	
	ins_D();delect(point);
	
	travel_DFS(0);printf("\n");
	
	ins_B();delect(point);
	
	travel_BFS(0);printf("\n");
	
	return 0;
}



