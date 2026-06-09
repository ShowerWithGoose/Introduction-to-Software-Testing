#include<stdio.h>
#include<string.h>
int leftx[100],rightx[100],lefty[100],righty[100],a[400],x1,y1,x2,y2,qdx[100],qdy[100];
int main()
{
	int n,i,j,k,a1=0,a2=0,a3=0,a4=0,time[100],Time=0,mid,m;
	for(m=0;m<100;m++)
	{
		time[m]=1;
	}
	scanf("%d",&n);
	for(i=0;i<4*n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<4*n;i++)
	{
		if(i%4==0)
		{
			leftx[a1]=a[i];
			a1++;
		}
		else if(i%4==1)
		{
			lefty[a2]=a[i];
			a2++;
		}
		else if(i%4==2)
		{
			rightx[a3]=a[i];
			a3++;
		}
		else if(i%4==3)
		{
			righty[a4]=a[i];
			a4++;
		}	
	}
	
	while(Time<n)
	{
		x1=rightx[Time];
		y1=righty[Time];
		qdx[Time]=leftx[Time];
		qdy[Time]=lefty[Time];
		for(j=0;j<n;j++)
		{
			if(leftx[j]==x1&&lefty[j]==y1)
			{
				time[Time]++;
				x1=rightx[j];
				y1=righty[j];
				j=-1;
			}
		}
		Time++;
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(time[i]<time[j])
			{
				mid=time[j];
				time[j]=time[i];
				time[i]=mid;
				mid=qdx[j];
				qdx[j]=qdx[i];
				qdx[i]=mid;
				mid=qdy[j];
				qdy[j]=qdy[i];
				qdy[i]=mid;
			}
		}
	}
	printf("%d %d %d",time[0],qdx[0],qdy[0]);
}
