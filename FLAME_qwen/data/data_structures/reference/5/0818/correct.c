#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
struct node{
	long long ak;			 
	long long an;			
}a[10000]={0,0},b[10000]={0,0};
long long rank[10000]={0},resl[10000][3]={{0}};
int cmp(const void *a,const void *b)
{
	long long aa=*((long long *)a),bb=*((long long *)b);
	if(resl[aa][0]>resl[bb][0]) return -1;
	else if(resl[aa][0]<resl[bb][0]) return 1;
	else return 0;
}

int main(void)
{
	long long counta=0,countb=0,i=0,j,temp_ak;
	char temp;
	while(scanf("%lld%lld",&a[i].ak,&a[i].an)!=EOF)
	{	
			
		i++;
		temp=getchar();
		if(temp=='\n')
			break;
	}
	counta=i;
	i=0;
	while(scanf("%lld%lld",&b[i].ak,&b[i].an)!=EOF)	
	{
		i++;
	}	
	countb=i;
		
	for(i=0;i<counta;i++)
	{
		for(j=0;j<countb;j++)
		{
			resl[i*countb+j][0]=a[i].an+b[j].an;
			resl[i*countb+j][1]=a[i].ak*b[j].ak;
		}
	}
	i=counta*countb;
	for(j=0;j<i;j++)
	{
		rank[j]=j;
	}
	
	qsort(rank,i,sizeof(long long),cmp);	
	
	temp_ak=resl[rank[0]][1];
	for(j=0;j<i;j++)
	{
		if(j==i-1)
		{
			if(j==0)
			{
				printf("%lld %lld ",temp_ak,resl[rank[j]][0]);
				return 0;
			}				
			if(resl[rank[j]][0]==resl[rank[j-1]][0])		
				temp_ak+=resl[rank[j]][1];			
			printf("%lld %lld ",temp_ak,resl[rank[j]][0]);
		}		
		else if(resl[rank[j]][0]==resl[rank[j+1]][0]&&j!=i-1)
		{
			temp_ak+=resl[rank[j+1]][1];
			if(j==i-2)
			{
				printf("%lld %lld ",temp_ak,resl[rank[j]][0]);
				return 0;
			}
		}		
		else
		{
			printf("%lld %lld ",temp_ak,resl[rank[j]][0]);
			temp_ak=resl[rank[j+1]][1];
		}
	}			

	return 0;
} 

