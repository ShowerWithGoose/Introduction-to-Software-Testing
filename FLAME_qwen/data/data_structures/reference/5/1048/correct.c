#include<stdio.h>
#include<string.h>
int main()
{
	char ch;
	int temp,i,j,k,len1,len2;
	int a1[100001],n1[100001],a2[100001],n2[100001];
	memset(a1,0,sizeof(a1));
	memset(n1,0,sizeof(n1));
	memset(a2,0,sizeof(a2));
	memset(n2,0,sizeof(n2));
	i=1;
	do
	{
		scanf("%d",&temp);
		if(i%2==1) a1[(i+1)/2]=temp;
		else n1[(i+1)/2]=temp; 
		i=i+1;
	}while((ch=getchar())!='\n');
	//printf("%d %d %d %d",a1[1],n1[1],a1[2],n1[2]);
	len1=i-1;
	//printf("%d",len1); 
	i=1;
	do
	{
		scanf("%d",&temp);
		if(i%2==1) a2[(i+1)/2]=temp;
		else n2[(i+1)/2]=temp; 
		i=i+1;
	}while((ch=getchar())!='\n');
	//printf("%d %d %d %d",a2[1],n2[1],a2[2],n2[2]);
	len2=i-1;
	//printf("%d",len2); 
	int ans[len1*len2+1][3];
	memset(ans,0,sizeof(ans)); 
	k=1;
	for(i=1;i<=len1;i=i+1)
	{
		for(j=1;j<=len2;j=j+1)
		{
			ans[k][1]=a1[i]*a2[j];
			ans[k][2]=n1[i]+n2[j];
			k=k+1; 
		}
	}
	for(i=2;i<=k-1;i=i+1)
	{
		for(j=k-1;j>=i;j=j-1)
		{
			if(ans[j][2]>ans[j-1][2])
			{
				temp=ans[j][2];
				ans[j][2]=ans[j-1][2];
				ans[j-1][2]=temp;
				temp=ans[j][1];
				ans[j][1]=ans[j-1][1];
				ans[j-1][1]=temp;
			}
			else if(ans[j][2]==ans[j-1][2])
			{
				ans[j-1][1]=ans[j-1][1]+ans[j][1];
				ans[j][1]=0;
				ans[j][2]=0;
			}
		}
	}
	for(i=1;i<=k;i=i+1)
	{
		if(ans[i][1]!=0) printf("%d %d ",ans[i][1],ans[i][2]); 
	}
	return 0;
}

