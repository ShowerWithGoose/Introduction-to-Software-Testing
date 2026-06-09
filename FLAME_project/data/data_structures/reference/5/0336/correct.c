#include <stdio.h>
int a[100000]={0};
int A[100000]={0};
int b[100000]={0};
int B[100000]={0};
int f[100000]={0}; 
int l[100000]={0};
int main()
{
	char kong;
	int i,j,k,m,n=1;
	for(i=1;;i++)
	{
		scanf("%d",&a[i]);
		scanf("%c",&kong);
		scanf("%d",&A[i]);
		scanf("%c",&kong);
		if(kong=='\n')
		break;
	}
	for(j=1;;j++)
	{
		scanf("%d",&b[j]);
		scanf("%c",&kong);
		scanf("%d",&B[j]);
		scanf("%c",&kong);
		if(kong=='\n')
		break;
	}
	for(k=1;k<=i;k++)
	{
		for(m=1;m<=j;m++)
		{
			f[n]=a[k]*b[m];
			l[n]=A[k]+B[m];
			n++;
		}
	}
	int ans=1;
	int num;
	int flag;
	while(flag<=n-1)
	{
		for(num=1;num<n;num++)
		{
			if(l[ans]<l[num]&&f[num]!=0)
			{
				ans=num;
			}
		}
		for(num=ans+1;num<n;num++)
		{
			if(l[ans]==l[num])
			{
				f[ans]+=f[num];
				f[num]=0;
			}
		}
		printf("%d %d ",f[ans],l[ans]);
		f[ans]=0;
		for(flag=1;flag<=n-1;flag++)
		{
			if(f[flag]!=0)
			{
				ans=flag;
				break;	
			}	
		}
	}
	return 0;
}













