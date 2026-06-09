#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a,b,flag,temp1[200],temp2[200],key[200][200];
void dfs(int p){
	int i;
	if(flag==0){
		printf("%d",p);
		flag=1;
	}
	else printf(" %d",p);
	temp1[p]=1;
	for(i=1;i<=a;i++){
		if(key[p][i]==1&&temp1[i]==0){
			dfs(i);
		}
	}
}
void bfs(int p){
	int i,j,k,t;
	temp2[1]=p;
	for(i=1,j=1;i<=j;){
		t=temp2[i++];
		if(temp1[t]==1) continue;
		if(flag==0){
			printf("%d",t);
			flag=1;
		}
		else printf(" %d",t);
		temp1[t]=1;
	    for(k=1;k<=a;k++){
		    if(key[t][k]==1&&temp1[k]==0) temp2[++j]=k;
	    }
	}

}
int main(){
    int i,x,y;
	scanf("%d%d",&a,&b);
	for(i=1;i<=b;i++){
		scanf("%d%d",&x,&y);
		key[x][y]=1;
		key[y][x]=1;
	}
	dfs(0);
	printf("\n");
	flag=0;
	for(i=0;i<102;i++){
		temp1[i]=0;
	}
	bfs(0);
	printf("\n");
    flag=0;
	for(i=0;i<102;i++){
		temp1[i]=0;
	}
	scanf("%d",&x);
	temp1[x]=1;
	dfs(0);
	printf("\n");
	flag=0;
	for(i=0;i<102;i++){
		temp1[i]=0;
	}
	temp1[x]=1;
	bfs(0);
	printf("\n");
	flag=0;
	for(i=0;i<102;i++){
		temp1[i]=0;
	}
	return 0;
}

