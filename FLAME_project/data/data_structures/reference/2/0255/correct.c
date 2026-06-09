#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
	char ex[1000]={0};
	int i,j,flag=1,cnt=0;
	int sign[1000]={0},value[1000]={0},sum=0,num[1000]={0};
	for (i=1;ex[i-1]!='=';i++)
	{
		scanf("%d",&num[i]);
		scanf("%c",&ex[i]);
		while (ex[i]==' ')
		scanf("%c",&ex[i]);
		cnt++;
	}	//录入数据 
	for (i=1;i<=cnt;i++)
	{
		if (ex[i]=='+')
		{
			sign[flag]=i;flag++;
		}
		else if (ex[i]=='-')
		{
			sign[flag]=-i;flag++;
		}
	} 
	sign[flag]=cnt;	//录入加减号
	for (i=1;i<=flag-1;i++)
	{
		value[i]=num[abs(sign[i])+1];
		for (j=abs(sign[i])+1;j<=abs(sign[i+1]);j++)
		{
			if (ex[j]=='*')
				value[i]*=(num[j+1]);
			else if (ex[j]=='/')
				value[i]/=(num[j+1]);
		}
	 } 	//区域和(除了第一段） 
	value[0]=num[1];
	for (i=1;i<=abs(sign[1]);i++)
	{
		if (ex[i]=='*')
		value[0]*=(num[i+1]);
		else if (ex[i]=='/')
		value[0]/=(num[i+1]);
	}	//第一段区域和
	sum+=value[0];
	for (i=1;i<=flag-1;i++)
	{
		if (sign[i]>0)
			sum+=value[i];
		else if (sign[i]<0)
			sum-=value[i];
	 } //求和  
	printf("%d",sum);
	return 0;
}



