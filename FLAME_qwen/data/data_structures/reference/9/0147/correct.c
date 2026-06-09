#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int site[150][4],count[100],flag[150];
int cmp(const void*a,const void*b){
	return *(int*)a-*(int*)b;
}
int search(int a[][4],int n,int x2,int y2)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		if(a[i][0]==x2&&a[i][1]==y2)
		return i;
	}
	return 0;
}
int main()
{
	int n,i,j,k=0,m,max=0,x2,y2;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<4;j++)
		scanf("%d",&site[i][j]);
	}
	qsort(site,n,sizeof(int)*4,cmp);
	for(i=0;i<n;i++)
	{
		for(m=0;flag[m]!=0;m++)
		{
			if(i==flag[m])
			{
				i++;
				continue;
			}
		}
		x2=site[i][2];
	    y2=site[i][3];
	    while(search(site,n,x2,y2))
		{
			flag[k]=search(site,n,x2,y2);
			count[i]++;
			x2=site[flag[k]][2];
		    y2=site[flag[k]][3];
		    k++;
		}
	}
	for(i=0;i<100;i++)
	{
		if(count[i]>max)
		{
			max=count[i];
			j=i;
		}
	}
	printf("%d %d %d",max+1,site[j][0],site[j][1]);
	return 0;
}

