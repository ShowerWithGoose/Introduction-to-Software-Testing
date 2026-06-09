#include <stdio.h>
#include <string.h>
struct formula
{
	int coe;
	int pow;
};
int compare(struct formula *x,struct formula *y)
{
	return y->pow-x->pow; 
}
int main()
{
	struct formula a[20],b[20],d[400],temp;
	int c,p;
	int i=0,j=0,k=0,l;
	for(i=0;i<400;i++)
	{
		d[i].pow=0;d[i].coe=0;
	}
	i=0;
	while(scanf("%d%d",&c,&p)!=EOF)
	{
		a[i].coe=c;
		a[i].pow=p;
		i++;	
		if(getchar()=='\n') 
			break;
	}int sum1=i;
	while(scanf("%d%d",&c,&p)!=EOF)
	{
		b[j].coe=c;
		b[j].pow=p;
		j++;
		if(getchar()=='\n') 
			break;	
	}int sum2=j;
	for(i=0;i<sum1;i++)
	{
		for(j=0;j<sum2;j++)
		{
		    temp.pow=a[i].pow+b[j].pow;
			temp.coe=a[i].coe*b[j].coe;
			for(l=0;l<k;l++)
			{
				if(temp.pow==d[l].pow)
				{
					break;
				}	
			}
			if(l==k)
			{
				d[k]=temp;k++;
			}
			else d[l].coe+=temp.coe;
		}
	}
	qsort(d,k,sizeof(struct formula),compare);
	for(i=0;i<k;i++)
	{
		printf("%d %d ",d[i].coe,d[i].pow);
	}
	return 0;
}
  


		
 
	
	
		


