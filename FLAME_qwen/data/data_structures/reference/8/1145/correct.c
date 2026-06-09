#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define M 100
int graph[M][M];
int arr[M]={0};
int brr[M]={0};
void DFS(int,int,int);
int ndian;
int nbian;
int x,y;
int m,n;
void chongzhi(){
    memset(arr,0x00,sizeof(int)*ndian);
    m=0;
    n=1;
    brr[0]=0;
 	arr[0]=1;
}
int main()
{
	scanf("%d%d", &ndian, &nbian);
	for (int i = 0; i < nbian; i++)
	{
		scanf("%d %d", &x, &y);
		graph[x][y]=1;
        graph[y][x] = 1;
	}
	DFS(0,0,ndian);
	printf("\n");
	chongzhi();
 	while (1)
	{
        if (m>=n)
        {
            break;
        }
  		int x=brr[m];
  		printf("%d ", x);
  		for (int i = 0; i < ndian; i++)
		{
   			if (graph[x][i]&&arr[i]==0)
			{
    			arr[i]=1;
    			brr[n]=i;
                n++;
   			}
  		}
        m++;
 	}
 	printf("\n");
    chongzhi();
    int p;
	scanf("%d", &p);
	DFS(0,p,ndian);
	printf("\n");
	chongzhi();
 	while (1)
	{
        if (m>=n)
        {
            break;
        }
  		int x = brr[m];
  		printf("%d ", x);
  		for (int i = 0; i < ndian; i++)
		{
   			if (graph[x][i]&&(arr[i]==0)&&(i!=p))
			{
    			arr[i]=1;
    			brr[n]=i;
                n++;
   			}
  		}
        m++;
 	}
 	printf("\n");
	return 0;
}


void DFS(int s,int t,int n){
	printf("%d ",s);
	arr[s]=1;
	for (int i = 0; i < n; i++)
	{
  		if (graph[s][i]&&(arr[i]==0)&&i!=t)
		{
   			DFS(i,t,n);
  		}
 	}
}
