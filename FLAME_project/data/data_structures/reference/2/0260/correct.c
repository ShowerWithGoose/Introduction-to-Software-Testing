#include<stdio.h>
int main()
{
	char op[100],op1[100];
	int a[100],i,j,sum=0,k;
	op1[0]='+';
	for(i=0;op1[k]!='=';i++)
	{
			scanf("%d",&a[i]);
			for(k=0;op1[k]<'0'||op1[k]>'9';k++)
			{
				scanf("%c",&op1[k]);
				if((op1[k]=='+')||(op1[k]=='-')||(op1[k]=='*')||(op1[k]=='/')||op1[k]=='=')
				{
					op[i]=op1[k];
						break;
				}
			}
			if(op[i]=='=')
				break;
	}	
	for(j=0;j<i;j++)
	{
		if(op[j]=='*')
		{
			a[j+1]=a[j]*a[j+1];
			a[j]=0;
			if(j==0)
			op[j]='+';
			else
			op[j]=op[j-1];
		}
		else if(op[j]=='/')
		{
			a[j+1]=a[j]/a[j+1];
			a[j]=0;
			if(j==0)
			op[j]='+';
			else
			op[j]=op[j-1];
		}
	}	
	sum=a[0];
	for(j=1;j<=i;j++)
	{
		if(op[j-1]=='+')
		sum=sum+a[j];
		else if(op[j-1]=='-')
		sum=sum-a[j];
	}
	printf("%d",sum);
	return 0;
} 

