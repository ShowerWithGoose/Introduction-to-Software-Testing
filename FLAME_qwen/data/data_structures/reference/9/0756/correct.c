#include<stdio.h>
int main()
{
	int n,num[100]={0},k,m,p=1,q=0,s1=0,s2=0,max=0;
	int x[101][2]={0},y[101][2]={0},line[103][2]={0};
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<2;j++)
		{
			scanf("%d%d",&x[i][j],&y[i][j]);
		}
	}
	for(k=0;k<n;k++)
	{
		line[0][0]=x[k][0];
		line[0][1]=y[k][0];
		line[1][0]=x[k][1];
		line[1][1]=y[k][1];
		for(m=0;m<n;m++)
		{
			if(x[m][0]==line[p][0]&&y[m][0]==line[p][1])
			{
				p++;
				line[p][0]=x[m][1];
				line[p][1]=y[m][1];
				m=-1;
			}
		}
		num[q++]=p;
		p=1;
		if(max<num[q-1])
		{
			max=num[q-1];
			s1=line[0][0];
			s2=line[0][1];
		}
	}
	printf("%d %d %d",max,s1,s2);
	return 0;
}

