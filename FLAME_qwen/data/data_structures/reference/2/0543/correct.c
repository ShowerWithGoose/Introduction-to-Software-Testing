#include <stdio.h>
#include <string.h>
char cal[100]="";
void fun(char *str)
{
	char *str_c=str;
	int i,j=0;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]!=' ')
			str_c[j++]=str[i];
	}
	str_c[j]='\0';
	str=str_c;	
}
int main()
{
	gets(cal);
	int all=0,i,k,k1,k2,j=1,cals[2][50]={},nums[2][100]={};
	int len=strlen(cal);
	for(k=1;k<=len;k++)
	{
		for(i=k;i<=len;i++)
	{
		if(cal[i-1]==32)
		{
			
			for(j=i;j<len;j++)
				cal[j-1]=cal[j];
			cal[len-1]=0;
		}
		len=strlen(cal);
	}
	} 
	fun(cal);
	len=strlen(cal);
	j=1;
	for(i=1;i<=len;i++)
	{
		if(cal[i-1]=='+')
		{
			cals[0][j]=1;
			cals[1][j]=i;
			j++;
		}
		else if(cal[i-1]=='-')
		{
			cals[0][j]=2;
			cals[1][j]=i;
			j++;
		}
		else if(cal[i-1]=='*')
		{
			cals[0][j]=3;
			cals[1][j]=i;
			j++;
		}
		else if(cal[i-1]=='/')
		{
			cals[0][j]=4;
			cals[1][j]=i;
			j++;
		}
		else if(cal[i-1]=='=')
		{
			cals[0][j]=5;
			cals[1][j]=i;
			j++;
		}
	}
	cals[1][0]=0;
	j--;
	for(i=1;i<=j;i++)
	{
		for(k=cals[1][i-1]+1;k<cals[1][i];k++)
			nums[0][i-1]=10*nums[0][i-1]+cal[k-1]-'0';
	}
	int per=1;
	for(i=1;i<=j;i++)
	{
		if(cals[0][i]==3)
		{
			for(k1=i;k1<=j;k1++)
			{
				if(cals[0][k1]==3)
					nums[0][i-1]=nums[0][i-1]*nums[0][k1];
				else if(cals[0][k1]==4)
					nums[0][i-1]=nums[0][i-1]/nums[0][k1];
				else
					break;
			}
			
		}
			
		
		if(cals[0][i]==4)
		{
			for(k1=i;k1<=j;k1++)
			{
				if(cals[0][k1]==4)
					nums[0][i-1]=nums[0][i-1]/nums[0][k1];
				else if(cals[0][k1]==3)
					nums[0][i-1]=nums[0][i-1]*nums[0][k1];
				else
					break;
			}
		}
			
	}
	all=nums[0][0];
	for(i=1;i<=j;i++)
	{
		if(cals[0][i]==1)
			all=all+nums[0][i];
			
		if(cals[0][i]==2)
			all=all-nums[0][i];
	}
	
	printf("%d",all);
	return 0;
}

