#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h> 
#include<assert.h>

int side[105][105];
int flag[4][105][105],f[4][105];

void dfs();

int main(){
	int n,m,dlt,i,j,k,s1,s2,tmp[105]={0},top=1,save[105]={0},num;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&s1,&s2);
		side[s1][s2]=side[s2][s1]=1;
	}
	scanf("%d",&dlt);
	dfs(0,n,0);
	printf("\n0");
	f[1][0]=i=1;
	while(1){
		top=0;
		for(j=0;j<i;j++){
			num=save[j];
			for(k=0;k<n;k++){
				if(side[num][k]==1&&flag[1][num][k]==0&&f[1][k]==0){
					flag[1][num][k]=flag[1][k][num]=f[1][k]=1;
					printf(" %d",k);
					tmp[top++]=k;
				}
			}
		}
		if(top==0) break;
		else
			for(i=0;i<top;i++)
				save[i]=tmp[i];
	}
	printf("\n");
	for(i=0;i<n;i++){
		side[i][dlt]=side[dlt][i]=0;
	}
	dfs(0,n,2);
	printf("\n0");
	f[3][0]=i=1;
	save[0]=0;
	while(1){
		top=0;
		for(j=0;j<i;j++){
			num=save[j];
			for(k=0;k<n;k++){
				if(side[num][k]==1&&flag[3][num][k]==0&&f[3][k]==0){
					flag[3][num][k]=flag[3][k][num]=f[3][k]=1;
					printf(" %d",k);
					tmp[top++]=k;
				}
			}
		}
		if(top==0) break;
		else
			for(i=0;i<top;i++)
				save[i]=tmp[i];
	}
	printf("\n");
	return 0;
}


void dfs(int num,int n,int mark){
	int i;
	printf("%d",num);
	f[mark][num]=1;
	for(i=0;i<n;i++){
		if(side[num][i]==1&&flag[mark][num][i]==0&&f[mark][i]==0){
			flag[mark][num][i]=flag[mark][i][num]=f[mark][i]=1;
			printf(" ");
			dfs(i,n,mark);
		}
	}
}

