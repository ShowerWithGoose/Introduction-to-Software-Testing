#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	char a[105];
	int i,j,m;
	gets(a);
	m=strlen(a);
	if(a[0]=='0')
	{
		for(i=2;i<m;i++)
		{
			if(a[i]!='0')
			break;
		}
		if(i<m-1)
		{
			printf("%c.",a[i]);
			for(j=i+1;j<m;j++)
			printf("%c",a[j]);
			printf("e-%d",i-1);	
		}
		else
		{
			printf("%ce-%d",a[i],i-1);
		}
		return 0;
	}
	else
	for(i=0;i<m;i++)
	{
		if(a[i]=='.')
		{
			printf("%c.",a[0]);
			for(j=1;j<m;j++)
			{
				if(a[j]!='.')
				printf("%c",a[j]);
			}
			printf("e%d",i-1);
			
		}
	}
	return 0;
}


