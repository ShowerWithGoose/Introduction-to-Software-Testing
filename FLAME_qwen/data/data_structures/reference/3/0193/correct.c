#include<stdio.h>
#include<string.h>

int main()
{
	char a[200],temp,temp1;
	int i=0,zhengshu=0;
	scanf("%s",&a);
	if(a[0]!='0')
	{
		while(a[i]!='.')
		{
			zhengshu++;
			i++;
		}
		temp=a[zhengshu];
		for(i=zhengshu;i>1;i--)
		{
			a[i]=a[i-1];
		}
		a[1]=temp;
		for(i=0;i<strlen(a);i++)
		{
			printf("%c",a[i]);
		}
		printf("e%d",zhengshu-1);
	}
	else if(a[0]=='0')
	{
		i=2;
		int j=0;
		while(a[i]=='0')
		{
			j++;
			i++;
		}
		if((j+3)==strlen(a))
		{
			printf("%ce-%d",a[j+2],j+1);
		}
		else
		{
			printf("%c.",a[j+2]);
			for(i=j+3;i<strlen(a);i++)
			{
				printf("%c",a[i]);
			}
		printf("e-%d",j+1);
		}
		
	}
	return 0;
}

