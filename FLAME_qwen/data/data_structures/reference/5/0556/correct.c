#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<malloc.h>
int Num1[100][2],Num2[100][2];
int res[100][2];
char s1[100],s2[100];
void bubble(int a[][2],int n);
int main()
{
	
	int i,j,k;
	int n=0;
	int max;
	char *p1,*p2;
	int len1=0,len2=0;
	int len3=0;
	//读入第一行数据
	p1=(char *)malloc(100);
	p2=(char *)malloc(100);
	fgets(p1,100,stdin);
	fgets(p2,100,stdin);
	//将字符串中的数字两个两个提取到数组中 
	while(sscanf(p1,"%d %d",&Num1[i][0],&Num1[i][1])!=EOF)
	{
		j=0;
		i++;
		while(j<2)
		{
			p1++;
			if(*p1==' '||*p1=='\n')
				j++;
		}
	}
	len1=i;
	i=0;
//	printf("len(s1)= %d\n",len1);
	
	while(sscanf(p2,"%d %d",&Num2[i][0],&Num2[i][1])!=EOF)
	{
		j=0;
		i++;
		while(j<2)
		{
			p2++;
			if(*p2==' '||*p2=='\n')
				j++;
		}
	}
	len2=i;
//	printf("len(s1)= %d\n",len2);
	
	k=0;
	for(i=0;i<len1;i++)
	{
		for(j=0;j<len2;j++)
		{
			res[k][0]=Num1[i][0]*Num2[j][0];
			res[k++][1]=Num1[i][1]+Num2[j][1];
		}
	}
		
	
	len3=len1*len2;
	for(i=0;i<len3;i++)
	{
		for(j=i+1;j<len3;j++)
		{
			if(res[j][1]==res[i][1]&&res[i][1]!=0)
			{
				res[i][0]+=res[j][0];
				for(k=j;k<len3-1;k++)
				{
					res[k][0]=res[k+1][0];
					res[k][1]=res[k+1][1];
				
				}
				len3--;
			}
		}
	
	}
		
	bubble(res,len3);
	for(k=0;k<len3;k++)
	{
		printf("%d %d ",res[k][0],res[k][1]);
	}
	
	
	
	return 0;
}
void bubble(int a[][2],int n)
{
	int i,j,flag;
	int hold1,hold2;
	for(i=0;i<n-1;i++)
	{
		flag=0;
		for(j=0;j<n-i-1;j++)
		{
			if(res[j][1]<res[j+1][1])
			{
				hold1=res[j][1];
				res[j][1]=res[j+1][1];
				res[j+1][1]=hold1;
				
				hold2=res[j][0];
				res[j][0]=res[j+1][0];
				res[j+1][0]=hold2;
				
				flag=1;
			}
		}
		if(0==flag)
			break;
	}
}

