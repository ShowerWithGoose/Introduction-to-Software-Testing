#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
	int a,b,m,n;	char c;
	int fs1[100]={0},fs2[100]={0};
	int sc1[100]={0},sc2[100]={0};
	for(m=0;scanf("%d %d",&a,&b)==2;m++)
	{
		
		fs1[m]=a; fs2[m]=b;
		if((c=getchar())=='\n')
			break;
	}
	m++;
	for(n=0;scanf("%d %d",&a,&b)==2;n++)
	{
		sc1[n]=a;sc2[n]=b;
		if((c=getchar())=='\n')
			break;
	}
	n++;
	int go1[m*n],go2[m*n];
	int sum=1;
	go1[0]=fs1[0]*sc1[0];
	go2[0]=fs2[0]+sc2[0];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		{
			if(i==0&&j==0)
				continue;
			int nub,exp;
			nub=fs1[i]*sc1[j];
			exp=fs2[i]+sc2[j];
			for(int cont=0;cont<sum;cont++)
			{
				if(exp==go2[cont])
				{
					go1[cont]+=nub;
					break;
				}
				else if(exp!=go2[cont]&&cont==sum-1)
				{
					go1[sum]=nub;
					go2[sum++]=exp;
					break;
				}
			}
		}
	for(int i=0;i<sum;i++)
	{			
		int max=go2[i];
		for(int j=i;j<sum;j++)
		{
			if(max<=go2[j])
			{
				int temp=go1[i];
				go2[i]=go2[j];
				go1[i]=go1[j];
				go2[j]=max;
				go1[j]=temp;
				max=go2[i];
			}
			if(max>=go2[j]&&j==sum-1)
				printf("%d %d ",go1[i],go2[i]);
		}
	}
		
	return 0;
}

