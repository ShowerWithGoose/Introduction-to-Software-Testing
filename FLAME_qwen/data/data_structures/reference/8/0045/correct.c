#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int tu[200][200],tap,num,i,x,y,no,fl[4][200],gd[4][200];

void sdbl(int i,int d){
	int j;
	fl[d][0]=1;
	for(j=0;j<tap;j++){
		if(d==1&&j==no) continue;
		if(tu[i][j]==1&&fl[d][j]==0)
		{
			fl[d][j]=1;
			printf(" %d",j);
			sdbl(j,d);
		}
	}
	return;
}

void gdbl(int i,int d,int s,int u){
	int j;
	fl[d][0]=1;
	for(j=0;j<tap;j++){
		if(d==3&&j==no) continue;
		if(tu[i][j]==1&&fl[d][j]==0)
		{
			fl[d][j]=1;
			gd[d][s]=j;
			s++;
		}
	}
	if(gd[d][u]!=0){
		printf(" %d",gd[d][u]);
		gdbl(gd[d][u],d,s,u+1);
	}
	return;
}

int main()
{
	scanf("%d%d",&tap,&num);
	for(i=0;i<num;i++)
	{
		scanf("%d%d",&x,&y);
		tu[x][y]++;
		tu[y][x]++;
	}
	scanf("%d",&no);
	printf("0");
	sdbl(0,0);
	printf("\n");
	printf("0");
	gdbl(0,2,0,0);
	printf("\n");
	printf("0");
	sdbl(0,1);
	printf("\n");
	printf("0");
	gdbl(0,3,0,0);
}

