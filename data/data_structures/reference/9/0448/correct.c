#include<stdio.h>
int main()
{
	int n,i,j,k,l,tmp,max;
	int qd[105][2],zd[105][2],count[105]={0};
	int maxx[105][2],maax;
	scanf("%d",&n);
	i=j=k=l=tmp=0;
	max=0;
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&qd[i][0],&qd[i][1],&zd[i][0],&zd[i][1]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			in:
			if(zd[i][0]==qd[j][0]&&zd[i][1]==qd[j][1])
			{
				i++;
				k++;
				maxx[k-1][0]=qd[i-1][0];
				maxx[k-1][1]=qd[i-1][1];
				goto out;
			}
		}	
	}
	if(i==n)
	{
		goto final;
	}
	out:
		l=j;
		count[k-1]++; 
		for(j=0;j<n;j++)
		{
			if(zd[l][0]==qd[j][0]&&zd[l][1]==qd[j][1]){
				goto out;
			}		
		}
	j=0;
	if(i<n)
	{
		goto in;
	}
	final:
		for(j=0;j<k;j++)
		{
			if(count[j]>max)
			{
				max=count[j];
				maax=j;
			}
		}
	printf("%d %d %d",max+1,maxx[maax][0],maxx[maax][1]);
	return 0;
}

