#include <stdio.h>
#include <math.h>
#include <string.h>
int p[101][4],tmp[4];
int main()
{
	int n=0,x=0,y=0;
	int flag=0,num=0,hold=0;
	scanf("%d",&n);
	int i=0,j=0,k=0;
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&p[i][0],&p[i][1],&p[i][2],&p[i][3]);
	}
	for(i=0;i<n;i++)
	{
		for(j=1+i;j<n;j++)
		{
			if(p[i][0]>p[j][0])
			{
				tmp[0]=p[i][0];
				tmp[1]=p[i][1];
				tmp[2]=p[i][2];
				tmp[3]=p[i][3];
				p[i][0]=p[j][0];
				p[i][1]=p[j][1];
				p[i][2]=p[j][2];
				p[i][3]=p[j][3];
				p[j][0]=tmp[0];
				p[j][1]=tmp[1];
				p[j][2]=tmp[2];
				p[j][3]=tmp[3];
			}
		}
	}//≈≈–Ú
	for(i=0;i<n;i++)
	{
		hold=i;
		flag=0;
		for(j=i+1;j<n;j++)
		{
			if(p[hold][2]==p[j][0]&&p[hold][3]==p[j][1])
			{
				flag++;
				hold=j;
			}
		}
		if(flag>num)
		{
			num=flag;
			x=p[i][0];
			y=p[i][1];
		}
	}
	printf("%d %d %d",num+1,x,y);
	return 0;
}

