#include<stdio.h>
#include<string.h>
int main ()
{
	char a[1000];
	char b[1000];
	gets(a);
	int x;
	x=strlen(a);
	int i=0;
	int j=0;
	int k=0;
	int point;
	for(i=0;i<x;i++)
	{
		if(a[i]=='.')
		{point=i;//i是小数点的位置 
		break;}
	}
	if(point==1) //整数部分为1个数字 
	{
		if(a[0]=='0')
		{
			for(i=2;i<x;i++)
			{
				if(a[i]!='0')
				{j=i;//a[j]是第一个非零数字 0.0021 j=4 x=6 2.0e-3
				break; }
			}
			b[0]=a[j];
			if(j!=(x-1))//不是最后一位数字 
			{
			b[1]='.';
			for(k=2,i=j+1;i<x;k++,i++)
			{
				b[k]=a[i];
			}
			for(i=0;i<k;i++)
			printf("%c",b[i]);
			printf("e-%d",j-1);	
			}
			else //是最后一位数字0.02 j=3 ，x=4 
			{
				printf("%c",b[0]);
				printf("e-%d",j-1) ;
			 } 
			
		
		}
		else//整数的那一个数字不是0 比如1.123 
		{
			for(i=0;i<x;i++)
			printf("%c",a[i]);
			printf("e0");
		}
	 } 
	 else //整数部分为多个数组 比如222.1 j=3 x=5
	 {
	 	b[0]=a[0];
	 	b[1]='.';
	 	for(k=2,i=1;i<x;k++,i++)
	 	{
	 		if(a[i]!='.')
	 		b[k]=a[i];
			 if(a[i]=='.')
			 k--;
		 }
		 for(i=0;i<x;i++)
		 printf("%c",b[i]);
		 printf("e%d",point-1);
		   } 
	
	return 0;
}

