#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int a[100][2];
int res[10000][2];
int res1[10000][2];
int main()
{
	char c;
	int n=0,i=0,j=0;
	do{
		scanf("%d %d%c",&a[n][0],&a[n][1],&c);
		n++;
	}while(c!='\n');
	int cnt=0,cnt1=0;
	int x,y;
	do{
		scanf("%d %d%c",&x,&y,&c);
		for(i=0;i<n;i++)
		{
			res[cnt][0]=x*a[i][0];
			res[cnt][1]=y+a[i][1];
			cnt++;
		}
	}while(c!='\n');
	
	for(i=0;i<cnt;i++)
	{
		if(res[i][0]!=0)
		{
			for(j=i+1;j<cnt;j++)
			{
				if(res[i][1]==res[j][1]&&res[j][0]!=0)
				{
					res[i][0]+=res[j][0];
					res[j][0]=0;
					res[j][1]=0;
				}
			}
			res1[cnt1][0]=res[i][0];
			res1[cnt1][1]=res[i][1];
			cnt1++;
		}
	}
	int tmp;
	for(i=0;i<cnt1-1;i++)
	{
		for(j=0;j<cnt1-1-i;j++)
		{
			if(res1[j][1]<res1[j+1][1])
			{
				tmp=res1[j][0];
				res1[j][0]=res1[j+1][0];
				res1[j+1][0]=tmp;
				tmp=res1[j][1];
				res1[j][1]=res1[j+1][1];
				res1[j+1][1]=tmp;
			}
		}
	}
	
	for(i=0;i<cnt1;i++)
	{
		printf("%d %d ",res1[i][0],res1[i][1]);
	}
	return 0;
}



