#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
char a[1000],b[1000];
int c1[1000],c2[1000];
int ans[1000][2];

int cmp(const void *A,const void *B)
{
	int *a=(int *)A;
	int *b=(int *)B;
	if(a[1]<b[1])
		return 1;
	return -1;
}

int main()
{
	gets(a);
	gets(b);
	int i=0,j=0,tem=0,len1,len2;
	while(a[i]!='\0')
	{
		if(a[i]>='0'&&a[i]<='9')
			tem=tem*10+(a[i]-'0');
		else if(a[i]==' '&&a[i+1]!='\0')
		{
			c1[j++]=tem;
			tem=0;
		}
		i++;
	}
	c1[j]=tem;
	len1=j+1;
	i=0;j=0;tem=0;
	while(b[i]!='\0')
	{
		if(b[i]>='0'&&b[i]<='9')
			tem=tem*10+(b[i]-'0');
		else if(b[i]==' '&&b[i+1]!='\0')
		{
			c2[j++]=tem;
			tem=0;
		}
		i++;
	}
	c2[j]=tem;
	len2=j+1;
	
	int t=0;
	for(i=0;i<len1/2;i++)
		for(j=0;j<len2/2;j++)
		{
			ans[t][1]=c1[i*2+1]+c2[j*2+1];
			ans[t++][0]=c1[i*2]*c2[j*2];
			//printf("%d %d\n",ans[t-1][0],ans[t-1][1]);
		}
	qsort(ans,t,sizeof(ans[0]),cmp);
	tem=0;
	for(i=0;i<t;i++)
	{
		if(ans[i][1]==ans[i+1][1])
			tem+=ans[i][0];
		else
		{
			tem+=ans[i][0];
			printf("%d %d ",tem,ans[i][1]);
			tem=0;
		}
	}
	if(ans[t-1][1]==0)
		printf("%d %d",ans[t-1][0],ans[t-1][1]);

	return 0;
}


