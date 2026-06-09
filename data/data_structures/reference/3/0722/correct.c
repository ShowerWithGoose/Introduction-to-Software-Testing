#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main ()
{
	int i,j=0,point=0,n,k=0,zero,t,m;
	char a[110];
	scanf ("%s",a);
	for (i=0;a[i]!='\0';i++) 
	{
		 if(a[i]=='.')//小数点位数 
		{
			point=i;
			k=1;//判断是否有小数点 
		}
		
	}
	while(a[j]=='0'||a[j]=='.')//第一个有效数字位数 
	{
		j++;
	}
	zero=i-1;
	while (a[zero]=='0')//除去末尾0
	{
		zero--;
	}
	printf("%c",a[j]);
	if (i>1&&zero>0&&zero!=j)
	{
		printf(".");
	}
	m=j+1;
	while (m<=zero)
	{
		if (a[m]!='.')
		{
			printf("%c",a[m]);
		}
		m++;
	}
	printf("e");
	if (point<j)
	{
		t=0;
	}
	else
	{
		t=-1;
	}
	if (k==1)//指数部分 
	{
		
		n=point-j+t;
	}
	else
	{
		n=i-1;
	}
	printf("%d",n);
	return 0;
}



