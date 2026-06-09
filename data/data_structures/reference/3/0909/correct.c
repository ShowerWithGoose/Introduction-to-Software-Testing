#include <stdio.h>
#include <string.h>
char data[110];
int main()
{
	int len,i,pointloc=0,num=0,j;
	gets(data);
	len=strlen(data);
	for(i=0;i<len;i++)
	{
		if(data[i]=='.')
		{
			pointloc=i;  break;
		}
	}
	if(pointloc==1)
	{
		if(data[0]>'0')
		{
			data[len]='e';
			data[len+1]='0';
			puts(data);
			return 0;
		}
		else
		{
			num=0;
			for(i=2;i<len,data[i]=='0';i++)
			{
				num++;
			}
			printf("%c",data[i]);
			if(i+1!=len)
			    printf(".");
			for(j=i+1;j<len;j++)
			{
				printf("%c",data[j]);
			}
			printf("e-%d",num+1);
			return 0;
		}
	}
	else
	{
		num=0;
		printf("%c.",data[0]);
		for(i=1;i<pointloc;i++)
		{
			printf("%c",data[i]);
		}
		for(j=pointloc+1;j<len;j++)
		{
			printf("%c",data[j]);
		}
		printf("e%d",pointloc-1);
		return 0;
	}
}

