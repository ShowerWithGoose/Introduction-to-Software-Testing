#include <stdio.h>
#include <string.h>
#include <math.h>
char s0[114];
char s1[114];
char fh1[114];
char fh[114];
int num1[114]={0};
int num2[114]={0};
int num[114]={0};
int main()
{
	gets(s0);
	int i=0,j=0,len0=strlen(s0);
	for(i=0;i<len0;i++)
		{
			if(s0[i]!=' ')
				{
					s1[j]=s0[i];
					j++;
				}
		}
	int len=strlen(s1);
	j=0;
	int k=1;
	for(i=0;i<len;i++)
	{
		if(s1[i]>='0'&&s1[i]<='9')
			{
				num1[j]=(int)(s1[i])-48;
				j++;
			}
		else
			{
				j--; 
				int m=0;
				for(j;j>=0;j--)
				{
					num2[k]=num2[k]+num1[j]*(int)(pow(10,m));
					m++;
					num1[j]=0;
				}
				j=0;
				fh1[k]=s1[i];
				k++;
			}
	}
	j=1;
	for(i=1;i<k;i++)
	{
		
		if(fh1[i]=='+'||fh1[i]=='-'||fh1[i]=='=')
		{
			num[j]=num2[i];
			fh[j]=fh1[i];
			j++;
		}
		else
		{
			if(fh1[i]=='*')
				num2[i+1]=num2[i]*num2[i+1];
			else if(fh1[i]=='/')
				num2[i+1]=num2[i]/num2[i+1]; 
			if(fh1[i+1]=='+'||fh1[i+1]=='-'||fh1[i+1]=='=')
				{
					num[j]=num2[i+1];
				}
		}	
	}
	for(i=1;i<j;i++)
	{
		if(fh[i]=='+')
			num[i+1]=num[i]+num[i+1];
		else if(fh[i]=='-')
			num[i+1]=num[i]-num[i+1];
		else
			{
				printf("%d",num[i]);
				break;
			}
	}
}




