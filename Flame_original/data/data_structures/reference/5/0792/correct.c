#include<stdio.h>
int a[100][2],b[100][2],c[100][2]={0};
int main()
{
	int i=1,n1=0,n2=0,n3=0,cnt,j,k;
	int hold1,hold2;
	char flag;
	for(i=1;flag!='\n';i++)
	{
		scanf("%d%d%c",&a[i][0],&a[i][1],&flag);
		n1++;
	}
	flag=1;
	for(i=1;flag!='\n';i++)
	{
		scanf("%d%d%c",&b[i][0],&b[i][1],&flag);
		n2++; 
	}
	for(i=1;i<=n1;i++)
	{
		for(j=1;j<=n2;j++)
		{
			cnt=a[i][1]+b[j][1];
			if(n3==0)
			{
				c[1][1]=cnt;
				c[1][0]=a[i][0]*b[j][0];
				n3++;
			}
			else
			{
				for(k=1;k<=n3;k++)
				{
					if(c[k][1]==cnt)
					{
						c[k][0]=c[k][0]+a[i][0]*b[j][0];
						break;
					}
				}
				if(k==n3+1)
				{
					c[k][1]=cnt;
					c[k][0]=c[k][0]+a[i][0]*b[j][0];
					n3++;
				}
			}
		}
	}
	for(i=1;i<=n3;i++)
	{
		for(j=1;j<=n3-i;j++)
		{
			if(c[j][1]<c[j+1][1])
			{
				hold1=c[j][0];
				hold2=c[j][1];
				c[j][0]=c[j+1][0];
				c[j][1]=c[j+1][1];
				c[j+1][0]=hold1;
				c[j+1][1]=hold2;
			}
		}
	}
	for(i=1;i<=n3;i++)
	{
		printf("%d %d ",c[i][0],c[i][1]);
	}
}

