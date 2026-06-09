#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int a1[1000][3];
int a2[1000][3];
int a[100000][3];
int ans[100000][3];
int cmp(const void*pa,const void*pb);	
int main()
{
	int i,j,k,flag=0,t;
	int num1,num2;
	i=0;
	char c; 
	while(scanf("%d%d",&a1[i][0],&a1[i][1])!=EOF)
	{
		scanf("%c",&c);
		if(c=='\n')
		break;
		else
		i++;
	}
	num1=i+1;
		i=0;
	while(scanf("%d%d",&a2[i][0],&a2[i][1])!=EOF)
	{
		i++;
	}
	num2=i;
	k=0;
	for(i=0;i<num1;i++)
	{
		for(j=0;j<num2;j++)
		{
			a[k][0]=a1[i][0]*a2[j][0];
			a[k][1]=a1[i][1]+a2[j][1];
			k++;
		}
	}
	a[k][1]=-1;
	int num3=k;

	qsort(a,k,sizeof(a[0]),cmp);
	
	j=0;
	for(i=0;i<k;i++)
	{
		int l=i;
		t=a[l][0];
		while(a[l][1]==a[l+1][1])
		{
			flag=1;
			t+=a[l+1][0];
			ans[j][1]=a[l][1];	
			l++;i++;
		}
		if(flag==1)
		{
			ans[j][0]=t;
			j++;
		}
		
		else if(flag==0)
		{
			ans[j][0]=a[i][0];
			ans[j][1]=a[i][1];
			j++;
		}
		flag=0;
	}
	
	qsort(ans,j,sizeof(ans[0]),cmp);
	for(i=0;i<j;i++)
	{
		if(ans[i][0]!=0)
		{
			printf("%d %d ",ans[i][0],ans[i][1]);
		}
	}
	
	
	
	return 0;
 } 
 int cmp(const void*pa,const void*pb) {

		if(((int *)pa)[1]> ((int *)pb)[1])
			return -1;
		else if(((int *)pa)[1]<((int *)pb)[1])
			return 1;

}

