#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
	int max;//最大指数 
	int place; 
typedef struct nodes{
	int x;
	int pow;
	
}node,*pnode;
node temp[10000]; 
pnode p;	
 int a,n;
	int i=0,num1,num2,j,k=0;//项数
	int lentemp=0,flag=0; 
	char c;	
	node s[10000]; 
	node ss[10000];
	
int cmp_pow(const void *p1,const void *p2)
{		int ans;
		pnode pow1=(pnode) p1;
		pnode pow2=(pnode) p2;
		ans=(pow1->pow)-(pow2->pow);
		return ans;
}

int main()
{

	
	do
	{scanf("%d%d%c",&s[i].x,&s[i].pow,&c);
	i++;
	}
	while(c!='\n');
	
	num1=i;
	i=0;
    do
	{
		scanf("%d%d%c",&ss[i].x,&ss[i].pow,&c);
		i++;
	}
	while(c!='\n');
	num2=i;
		for(i=0;i<=num1;i++) 
		{for(j=0;j<=num2;j++)
			{	a=ss[j].x*s[i].x;//系数 
				n=ss[j].pow+s[i].pow;//指数
			
				for(k=0;k<=lentemp;k++)
				{if(temp[k].pow==n)//可以合并
				 	{temp[k].x=temp[k].x+a; 
					 flag=1;
					}
				 }
		 		if(flag==0)
				{
					temp[lentemp].pow=n;
					temp[lentemp].x=a; 
					lentemp++; 
				}
				flag=0;
			
			
			}
	
		}
		
		
	qsort(temp,lentemp+1,sizeof(node),cmp_pow);
	for(i=lentemp;i>=0;i--)
	{if(temp[i].x!=0)
	printf("%d %d ",temp[i].x,temp[i].pow);
	}
	return 0;
	
}

