#include<stdio.h>
#include<stdlib.h>
int arr1[10000][2];
int arr2[10000][2];
int final[10000][2];
int cmp(const void*a,const void*b)
{
	return (int)(((int*)b)[1]-((int*)a)[1]);
}
int main()
{
	int len1=1,len2=0,i,j,len3=0,tmp;
	char ch='a';
	scanf("%d%d",&arr1[0][0],&arr1[0][1]);
	ch=getchar();
	while(ch!='\n')
	{
		scanf("%d%d",&arr1[len1][0],&arr1[len1][1]);
		len1++;
		ch=getchar();
	}
	ch=1;
		while(ch!=EOF)
	{
		scanf("%d%d",&arr2[len2][0],&arr2[len2][1]);
		len2++;
		ch=getchar();
	}
	for(i=0;i<len1;i++)
	{
		for(j=0;j<len2;j++)
		{
			final[len3][0]=arr1[i][0]*arr2[j][0];
			final[len3][1]=arr1[i][1]+arr2[j][1];
			len3++;
		}
	}
	qsort(final,len3,8,cmp);
	tmp=final[0][0];
     for(i=1;i<len3;i++)
     {
     	if(final[i][1]!=final[i-1][1])
     	{
     		if(tmp!=0)
     		printf("%d %d ",tmp,final[i-1][1]);
     		tmp=final[i][0];
		 }
		 else{
		 	tmp+=final[i][0];
		 }
	 }
	 if(tmp!=0)
	 printf("%d %d ",tmp,final[len3-1][1]);
return 0;
}

