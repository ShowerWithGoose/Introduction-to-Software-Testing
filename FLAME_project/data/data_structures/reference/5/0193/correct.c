#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct math{
    int di;
    int mi;
}M;

void paixu(M in[],int num);
void delet(M in[],int num);
void shanchu(M in[],int begin,int final);

int main()
{
	M a[1000],b[1000],result[100000];
	char c;
	int i=0,j=0,k=0;
	int m,n;
	do{
		scanf("%d%d%c",&a[i].di,&a[i].mi,&c);
		i++;
	}while(c!='\n');
	do{
		scanf("%d%d%c",&b[j].di,&b[j].mi,&c);
		j++;
	}while(c!='\n');
	for(m=0;m<i;m++)
	{
		for(n=0;n<j;n++)
		{
			result[k].di=a[m].di*b[n].di;
			result[k].mi=a[m].mi+b[n].mi;
			k++;
		}
	}
	delet(result,k-1);
	paixu(result,k);
	for(i=0;i<k;i++)
	{
		if(result[i].mi!=-1)
		printf("%d %d ",result[i].di,result[i].mi);
	}
	return 0;
} 

void delet(M in[],int num)
{
	int left,i,j;
	left=num;
	for(i=0;i<left;i++)
	{
		for(j=i+1;j<=left;j++)
		{
			if(in[i].mi==in[j].mi)
			{
				in[i].di+=in[j].di;
				in[j].mi=-1;
			}
		}
	}
}

void paixu(M in[],int num)
{
	M temp;
	int i,j;
	for(i=0;i<num;i++)
	{
		for(j=i+1;j<num;j++)
		{
			if(in[i].mi<in[j].mi)
			{
				temp=in[i];
				in[i]=in[j];
				in[j]=temp;
			}
		}
	}
}

