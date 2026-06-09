#include<stdio.h>
#include<string.h>
int mid[100],num[100];//num为各数据，mid为多项式各项结果
int flag1[100],flag2[100]; //flag1为+、-所在位置,flag2为所有运算符号位置 

int main()
{
	char s1[100],s[100];
	int result = 0;
	int i = 0,j = 0,k = 0, flag = 0,l = 0,jj = 0,all = 0,q = 0;
	gets(s1);
	for(i = 0,j = 0;i<strlen(s1);i++)//despace
	{
		if(s1[i]!=' ')
		{
			s[j] = s1[i];
			j++;//j is all num and calculate 
		}
	}
	for(i=0;s[i]!='\0';i++)//get num
	{
		k = i; flag = 0;
		while(s[k]>=48&&s[k]<=57)
		{
			num[l]=num[l]*10+s[k]-'0';
			k++; flag++;
		}
		if(flag!=0)
		{
			l++; i=i+flag;
		}
	}
	for(i = 0;i<j;i++)//locate symbol
	{
		if(s[i]=='+'||s[i]=='-')
		{
			flag1[jj] = i;
			jj++;
		}
		if(s[i]=='*'||s[i]=='/'||s[i]=='+'||s[i]=='-')
		{
			flag2[all] = i;
			all++;
		}
	}
	flag1[jj]=flag2[all-1]+1;
	int zhong=0;
	for(i=0;i<jj+1;i++)//mid
	{
		mid[i]=num[i+zhong];
		while(flag2[q]<flag1[i]||flag2[q]==0)
		{
			if(s[flag2[q]]=='*')
			{
				mid[i]*=num[i+1+zhong]; q++;
			}
			else if(s[flag2[q]]=='/')
			{
				mid[i]/=num[i+1+zhong]; q++;
			}
			else if(flag2[q]==0) break;			
			zhong++;
		}
		q++;                                                           
	}
	result=mid[0];
	for(i=0;i<jj;i++)//finally   
	{
		if(s[flag1[i]]=='+')
			result+=mid[i+1];
		else if(s[flag1[i]]=='-')
			result-=mid[i+1];
	}
	printf("%d",result);
} 


