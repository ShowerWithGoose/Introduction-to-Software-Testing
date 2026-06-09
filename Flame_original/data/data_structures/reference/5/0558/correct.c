#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct formula{
	int coeff;
	int index;
}first[1002],second[1002],res[100002],temp;
int main()
{
	int i=0,j=0,k=0,m,n,final,tem;
	char a;
	while(scanf("%d %d",&first[i].coeff,&first[i].index))
	{
		
		i++;
		if(getchar()!=' ')break;
	}
	m=i;
	while(scanf("%d %d",&second[j].coeff,&second[j].index))
	{
		
		j++;
		if(getchar()!=' ')break;
	}
	n=j;
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			res[k].coeff=first[i].coeff*second[j].coeff;
			res[k].index=first[i].index+second[j].index;
			k++;
		}
	}
	final=k;
	for(k=0;k<final;k++)
	{
		for(tem=k+1;tem<final;tem++)
			if(res[k].index==res[tem].index)
		{
			res[k].coeff+=res[tem].coeff;
			res[tem].coeff=0;
		}
		
	
	}
    for(k=0;k<final;k++)
	{
		for(tem=k+1;tem<final;tem++)
			if(res[k].index<res[tem].index)
		{
			temp=res[k];
			res[k]=res[tem];
			res[tem]=temp;
		}
		
	
	}
	for(k=0;k<final;k++)
	{
		if(res[k].coeff!=0)
		{
			printf("%d %d ",res[k].coeff,res[k].index);
		}
	}
	return 0;
 } 

