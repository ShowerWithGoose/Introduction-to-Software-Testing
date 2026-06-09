#include <stdio.h> 
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
struct duoxiang{
	int xi;
	int zhi;
}a[10000],b[10000],c[10000],temp;
void paixu(int n,struct duoxiang c[10000],struct duoxiang temp) 
{
	int i,j,flag;
	for(i=0;i<n-1;i++)
	{
		flag=0;
		for(j=0;j<n-1-i;j++)
		{
			if(c[j].zhi<c[j+1].zhi)
			{
				temp=c[j];
				c[j]=c[j+1];
				c[j+1]=temp;
				flag=1;
			}
		}
		if(flag==0)
			{
				break;
			}
	}
}
int main()
{
	int m=0,n=0,k=0;
	char ch;
	do{
		scanf("%d%d%c",&a[m].xi,&a[m].zhi,&ch);
		m++;
	}while(ch!='\n');
	do{
		scanf("%d%d%c",&b[n].xi,&b[n].zhi,&ch);
		n++;
	}while(ch!='\n');
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			c[k].xi=a[i].xi*b[j].xi;
			c[k].zhi=a[i].zhi+b[j].zhi;
			k++;
		}
	}
	paixu(k,c,temp);
	for(i=0;i<k;i++)
	{
		if(c[i].zhi==c[i+1].zhi&&c[i].zhi!=0)
		{
			c[i+1].xi+=c[i].xi;
			c[i].xi=0;
		}
	}
	for(i=0;i<k;i++)
	{
		if(c[i].xi==0)
		{
			continue;
		}else{
			printf("%d %d ",c[i].xi,c[i].zhi);
		}
	}
	return 0;
}

