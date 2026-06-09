#include <stdio.h>
int a[10000]={0},b[10000]={0},c[10000]={0},d[10000]={0};e[10000]={0},f[10000]={0};
int main()
{
	int i=0,j=0,m,n,k=0,temp,temp1,temp2,p;
	char ch;
	while(scanf("%d %d",&a[i],&b[i])!=EOF)
	{
		scanf("%c",&ch);
		i++;
		if(ch=='\n')
		break;
	}
	while(scanf("%d %d",&c[j],&d[j])!=EOF)
	{
		scanf("%c",&ch);
		j++;
		if(ch=='\n')
		break;
	}
	for(m=0;m<i;m++)
	{
		for(n=0;n<j;n++)
		{
			temp=0;
			for(p=0;p<k;p++)
			{
				if(b[m]+d[n]==f[p]){
				e[p]+=a[m]*c[n];
				temp=1;}
			}
			if(temp==0)
			{
				f[k]=b[m]+d[n];
				e[k]=a[m]*c[n];
				k++;
			}
		}
	}
	for(m=0;m<k;m++)
	{
		for(n=0;n<k-m-1;n++)
		{
			if(f[n]<f[n+1])
			{
				temp1=f[n];
				f[n]=f[n+1];
				f[n+1]=temp1;
				temp2=e[n];
				e[n]=e[n+1];
				e[n+1]=temp2;
			}
		}
	}
	for(m=0;m<k;m++)
		printf("%d %d ",e[m],f[m]);
	return 0;
}

