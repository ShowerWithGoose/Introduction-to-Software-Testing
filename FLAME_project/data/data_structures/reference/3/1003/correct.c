#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
	char a[100];
	int qian[100];
	int leng;
	gets(a);
	leng=strlen(a);
	int wei=0;
	if(a[0]-'0'!=0)
	{
		int i=0;
		while(a[i]!='.')
		{
			qian[i]=a[i]-'0';
			wei++;
			i++;
		}
		wei--;
		if(a[i]=='.')
		{
			i++;
		}
		while(i<leng)
		{
			qian[i-1]=a[i]-'0';
			i++;
		}
		int shou;
		shou=a[0]-'0';
		printf("%d",shou);
		printf(".");
		int j=1;
		while(j<i-1)
		{
			printf("%d",qian[j]);
			j++;
		}
		printf("e");
		printf("%d",wei);
				
	}
	else if(a[0]-'0'==0)
	{
		int i=2;
		int j=0;
		int shou;
		int wei=1;
		while(a[i]-'0'==0)
		{
			i++;
			wei++;
		}
		shou=a[i]-'0';
		i++;
		
		while(i<leng)
		{
			qian[j]=a[i]-'0';
			i++;
			j++;
		}
		i=0;
		if(j==0)
		{
			printf("%d",shou);
			printf("e-");	
			printf("%d",wei);
		}
		else
		{
			printf("%d",shou);
			printf(".");
			while(i<j)
			{
				printf("%d",qian[i]);
				i++;
			}	
			printf("e-");
			printf("%d",wei);	
		}

		
	}
	return 0;
}

