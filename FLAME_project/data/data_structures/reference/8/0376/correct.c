#include <stdio.h>
#include <string.h>
int myGraph[110][110];
int isVisit[110];
int team[110];
int front,rear,numD,numB;

void rNode(int i)
{
	int k;
	for(k=0;k<=numD;k++){
		if(myGraph[i][k]==1&&isVisit[k]==0){
			front ++; 
			team[front] = k;
			isVisit[k]=1;
			rNode(k);
		}
	}
	return;
}
int main(void)
{
	int i,a,b,k;
	scanf("%d%d",&numD,&numB);
	for(i=1;i<=numB;i++){
		scanf("%d%d",&a,&b);
		myGraph[a][b] = myGraph[b][a] = 1;
	}
	//深度
	memset(isVisit,0,sizeof(isVisit));
	memset(team,-1,sizeof(team));
	front = -1;team[++front]=0;isVisit[0]=1;
	rNode(0);
	for(i=1;i<numD;i++) 
		if(isVisit[i]==0) {
			rNode(i);
		}
	for(i=0;i<numD;i++) printf("%d ",team[i]);printf("\n");
	//广度 
	front=0,rear=-1; 
	memset(isVisit,0,sizeof(isVisit));
	memset(team,-1,sizeof(team));
	team[++rear]=0;
	while(front<numD){
		i = team[front];front++;isVisit[i]=1;
		for(k=0;k<=numD;k++)
			if(myGraph[i][k]==1&&isVisit[k]==0)
			{
				team[++rear] = k;
				isVisit[k]=1;
			}
	}
	for(i=0;i<numD;i++) printf("%d ",team[i]);printf("\n");
	//删除 
	scanf("%d",&a);
	for(i=0;i<numD;i++) myGraph[a][i]=myGraph[i][a]=0;
	//深度 
	memset(isVisit,0,sizeof(isVisit));
	memset(team,-1,sizeof(team));
	if(a==0)  team[0]=1;
	else team[0]=0;
	front=0;isVisit[team[0]]=1;isVisit[team[0]]=1;
	rNode(team[0]);
	for(i=1;i<numD;i++)
		if(isVisit[i]==0) 
			rNode(i);
	for(i=0;i<numD-1;i++) printf("%d ",team[i]);printf("\n");
	//广度 
	memset(isVisit,0,sizeof(isVisit));
	memset(team,-1,sizeof(team));
	if(a==0)  team[0]=1;
	else team[0]=0;
	front=0;rear=0;
	while(front<numD){
		i = team[front];front++;isVisit[i]=1;
		for(k=0;k<=numD;k++)
			if(myGraph[i][k]==1&&isVisit[k]==0)
			{
				team[++rear] = k;
				isVisit[k] = 1;
			}
	}
	for(i=0;i<numD-1;i++) printf("%d ",team[i]);printf("\n");
	return 0;
}



