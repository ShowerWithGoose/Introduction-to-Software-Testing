#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
void sort(int point[101][4],int n,int tmp[4]);
int point[101][4],tmp[4],temp,num,ans,x,y;
int n,i,j,k;

int main()
{
	scanf("%d",&n);
	for(i = 0 ; i < n ; i ++)
	{
		scanf("%d %d %d %d",&point[i][0],&point[i][1],&point[i][2],&point[i][3]);
	}
	sort(point,n,tmp);

	for(i = 0; i < n; i ++)
	{
		temp = i;
		num = 0;
		for(j = i + 1; j < n; j ++)
		{
			if((point[temp][2] == point[j][0]) && (point[temp][3] == point[j][1]))
			{
				num ++;
				temp = j;	
			}
		}
		if(num > ans)
		{
			ans = num;
			x = point[i][0];
			y = point[i][1];
		}
	}
	printf("%d %d %d",ans + 1,x,y);
	return 0;
}
void sort(int point[101][4],int n,int tmp[4])//按x1的大小排序 
{
	for(i = 0 ; i < n ; i ++)
	{
		for(j = i + 1 ; j < n ; j ++)
		{
			if(point[i][0]>point[j][0])
			{
				for(k = 0 ; k < 4 ; k ++)
				{
					tmp[k] = point[i][k];
					point[i][k] = point[j][k];
					point[j][k] = tmp[k];
				}
									
			}
		}
	}
}

