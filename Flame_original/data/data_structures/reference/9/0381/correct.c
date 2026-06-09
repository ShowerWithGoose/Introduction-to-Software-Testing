#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int a[105][4],yin[4];
void replace(int a[105][4],int yin[4],int n)
{
	int i,j,k;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(a[i][0]>a[j][0])
			{
				for(k=0;k<4;k++)
					yin[k]=a[i][k];
				for(k=0;k<4;k++)
					a[i][k]=a[j][k];
				for(k=0;k<4;k++)
					a[j][k]=yin[k];
			}
}
int main()
{
	int i,j,n,k,max=0,line,x,y;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf(" %d %d %d %d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
	replace(a,yin,n);
	/*for(i=0;i<n;i++)
		printf(" %d %d %d %d\n",a[i][0],a[i][1],a[i][2],a[i][3]);*/
	for(i=0;i<n;i++)
	{
		k=i,line=0;
		for(j=i+1;j<n;j++)
			if(a[k][2]==a[j][0]&&a[k][3]==a[j][1])
				k=j,line++;
		if(line>max)
		{
			max=line;
			x=a[i][0];
			y=a[i][1];
		}
	}
	printf("%d %d %d",max+1,x,y);
	return 0;
}

