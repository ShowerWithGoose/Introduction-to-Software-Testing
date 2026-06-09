#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define MAX 1024
int a[1024][1024]={0};
int visd1[1024]={0};
int visd2[1024]={0};
int que[1024],rear,count,front,flag;
int v_num,e_num;
int isempty(){
	return count==0;
}
void enter(int que[],int v){
	rear=rear+1;
	que[rear]=v;
    count++;
}
int run(int que[]){
	if(isempty())
    printf("error:empty\n");
    else
	{
    	count--;
    	printf("%d ",que[front]);
    	que[front]=0;
    	front=front+1;
	}
	return que[front];
}
void dfs(int a[][1024],int v)
{
	if(!visd1[v])
	{
		if(v==0)
		printf("%d",v);
		else
		printf(" %d",v);
	}
	visd1[v]=1;
	for(int i=0;i<v_num;i++)
	{
		if(a[v][i]&&(!visd1[i]))
		dfs(a,i);
	}
	return;
}
void bfs(int a[][1024],int v)
{
    int t;
    que[1] = v;
    for(int j=1,r=1;j<= r;)
    {
        t=que[j++];
        if(visd2[t]==1)
        continue;
        if (flag==0)
        {
            printf("%d",t);
            flag=1;
        }
        else
        printf(" %d",t);
        visd2[t]=1;
        for(int i=1;i<=v_num;i++)
        {
            if(a[t][i]==1&&visd2[i]==0)
            que[++r]=i;
        }
    }
}
int main()
{
	int m,n,rub;
	scanf("%d%d",&v_num,&e_num);
	for(int i=0;i<e_num;i++)
	{
		scanf("%d%d",&m,&n);
		
		a[m][n]=1;
		a[n][m]=1;
	}
	scanf("%d",&rub);
	dfs(a,0),printf("\n");
	bfs(a,0),printf("\n");
	for(int i=0;i<v_num;i++)
	a[rub][i]=a[i][rub]=0;
	memset(visd1,0,1024);
	memset(visd2,0,1024);
	memset(que,0,1024);
	flag=0;
	dfs(a,0),printf("\n");
	bfs(a,0),printf("\n");
	return 0;
}
//9 10
//0 1
//0 2
//1 4
//1 3
//1 8
//8 6
//3 6
//7 2
//7 5
//5 2
//3

