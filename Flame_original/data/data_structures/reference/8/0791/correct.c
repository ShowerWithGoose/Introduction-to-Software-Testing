#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 32
struct node{
	int book[201];
	int cnt;
	int step[201];
}line[1000];
int np,nl,node1,node2,flag=0,cnt=1;
int link[200][200];
int d[300];
int book[201];
int ans[201];
void dfs(int now,int np0){
	int i;
	if(cnt==np0){
		flag=0;
		for(i=0;i<=np0-1;i++){
			printf("%d ",d[i]);
		}
		printf("\n");
	}
	else if(flag==1){
	  	return;
	}
	else{
		for(i=0;i<=np-1;i++){
			if(book[i]==0&&link[now][i]==1){
				book[i]=1;
				d[cnt]=i;
				cnt++;
				dfs(i,np0);
			}
		}
	}
}
int main()
{    int dele,i;
    scanf("%d %d",&np,&nl);
	   for(i=1;i<=nl;i++){
	   	scanf("%d %d",&node1,&node2);
	   	link[node1][node2]=link[node2][node1]=1;
	   }
	   scanf("%d",&dele);
	   book[0]=1;
	   dfs(0,np);
	   int head=0,tail=1;
	   for(i=0;i<=200;i++){
	   	book[i]=0;
	   }
	   book[0]=1;
	   ans[head]=0;
	   cnt=0;
	   while(cnt<np-1){
	   	for(i=0;i<=np-1;i++){
	   		if(book[i]==0&&link[ans[head]][i]==1){
	   			ans[tail]=i;
	   			book[i]=1;
	   			cnt++;
	   			tail++;
			   }
		   }
		   head++;
	   }
	   for(i=0;i<=np-1;i++){
	   	printf("%d ",ans[i]);
	   }
	   printf("\n");
	   for(i=0;i<=np-1;i++){
	   	link[dele][i]=link[i][dele]=0;
	   }
	   for(i=0;i<=200;i++){
	   	book[i]=0;
	   }
	   book[0]=1;
	   flag=0;
	   cnt=1;
	   dfs(0,np-1);
	   
	   head=0,tail=1;
	   for(i=0;i<=200;i++){
	   	book[i]=0;
	   }
	   book[0]=1;
	   ans[head]=0;
	   cnt=0;
	   while(cnt<np-2){
	   	for(i=0;i<=np-1;i++){
	   		if(book[i]==0&&link[ans[head]][i]==1){
	   			ans[tail]=i;
	   			book[i]=1;
	   			cnt++;
	   			tail++;
			   }
		   }
		   head++;
	   }
	   for(i=0;i<=np-2;i++){
	   	printf("%d ",ans[i]);
	   }
	return 0;
}



