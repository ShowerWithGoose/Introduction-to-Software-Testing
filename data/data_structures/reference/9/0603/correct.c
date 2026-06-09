#include<stdio.h>
int main()
{
	int a[100000][5]={0},n,k=0,flag;
	scanf("%d",&n);
	scanf("%d%d%d%d",&a[k][1],&a[k][2],&a[k][3],&a[k][4]);
	a[k][0]++;k++;
	for(int i=0;i<n-1;i++)
	{
		flag=0;
		scanf("%d%d%d%d",&a[k][1],&a[k][2],&a[k][3],&a[k][4]);
		for(int j=0;j<k;j++)
		{
			if(a[k][1]==a[j][3]&&a[k][2]==a[j][4])
			{
				flag=1;
				a[j][0]++;
				a[j][3]=a[k][3];
				a[j][4]=a[k][4];
				break;
			}
		}
		if(flag==0){a[k][0]++;k++;}
	}k--;
	do{flag=0;
	for(int i=0;i<=k;i++)
	{
		for(int j=i+1;j<=k;j++)
		{
            if(a[i][1]==a[j][3]&&a[i][2]==a[j][4])
			{
				flag=1;
				a[j][0]+=a[i][0];
				a[j][3]=a[i][3];
				a[j][4]=a[i][4];
				break;
			}	
		}
		if(flag==1)
		{
		for(int j=i+1;j<=k;j++)
		{
			a[i][0]=a[j][0];
			a[i][1]=a[j][1];
			a[i][2]=a[j][2];
			a[i][3]=a[j][3];
			a[i][4]=a[j][4];
		}
		k--;
		break;
		}
	}
	}while(flag);flag=0;
	do{flag=0;
	for(int i=k;i>=0;i--)
	{
		for(int j=i-1;j>=0;j--)
		{
            if(a[i][1]==a[j][3]&&a[i][2]==a[j][4])
			{
				flag=1;
				a[j][0]+=a[i][0];
				a[j][3]=a[i][3];
				a[j][4]=a[i][4];
				break;
			}	
		}
		if(flag==1)
		{
		for(int j=i+1;j<=k;j++)
		{
			a[i][0]=a[j][0];
			a[i][1]=a[j][1];
			a[i][2]=a[j][2];
			a[i][3]=a[j][3];
			a[i][4]=a[j][4];
		}
		k--;
		break;
		}
	}
	}while(flag);
	flag=0;n=0;
	for(int i=0;i<=k;i++)
	{
		n=(flag>a[i][0])?n:i;
		flag=(flag>a[i][0])?flag:a[i][0];
	}
	printf("%d %d %d\n",flag,a[n][1],a[n][2]);
	return 0;
}



