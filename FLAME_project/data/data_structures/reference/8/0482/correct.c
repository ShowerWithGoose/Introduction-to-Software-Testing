#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int hia[105][105] = {0};
int flag[105] = {0};
int temp[105] = {0};
int ver,edg;
int ber = 0;

void Dfs(int n)
{
	int k;
	if(ber == 0){
		ber = 1;
		printf("%d",n);
	}
	else
		printf(" %d",n);
	temp[n] = 1;
	for(k=0;k<ver;k++){
		if(hia[n][k]==1 && temp[k]==0)
			Dfs(k);
	}
}

void Bfs(int n)
{
    int t,j,r,k;
    flag[1] = n;
    for(j=1,r=1;j<=r;)
    {
        t = flag[j++];
        if(temp[t] == 1)
            continue;
        if(ber == 0){
            printf("%d",t);
            ber = 1;
        }
        else
            printf(" %d",t);
        temp[t] = 1;
        for(k=1;k<ver;k++)
        {
            if(hia[t][k] == 1 && temp[k] == 0)
                flag[++r] = k;
        }
    }
}

int main()
{
	scanf("%d%d",&ver,&edg);
	int i,x,y,del;
	for(i=0;i<edg;i++){
		scanf("%d %d",&x,&y);
		hia[x][y] = 1;
		hia[y][x] = 1;
	}
	scanf("%d",&del);
	Dfs(0);
	printf("\n");
	memset(temp,0,sizeof(temp));
	//memset(flag,0,sizeof(flag));
	ber = 0;
	Bfs(0);
	printf("\n");
	memset(temp,0,sizeof(temp));
	memset(flag,0,sizeof(flag));
	ber = 0;
	temp[del] = 1;
	Dfs(0);
	printf("\n");
	memset(temp,0,sizeof(temp));
	//memset(flag,0,sizeof(flag));
	ber = 0;
	temp[del] = 1;
	Bfs(0);
	printf("\n");
	return 0;
}

