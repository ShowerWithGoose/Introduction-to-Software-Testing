#include <stdio.h>
#include <string.h>
char arr[105];
int main()
{
	scanf("%s",arr);
	int i=0;
	
	if(arr[0]>'0')
	{
		for(i=1;i<strlen(arr);i++)
		{
			if(arr[i]=='.')
			{
				break;
			}
		}
		printf("%d.",arr[0]-'0');
		for(int j=1;j<strlen(arr);j++)
		{
			if(arr[j]!='.')
			{
				putchar(arr[j]);
			}
		}
		printf("e%d",i-1);
		
	}
	else
		{
			for(i=1;i<strlen(arr);i++)
			{
				if(arr[i]!='0'&&arr[i]!='.')
				{
					break;
				}
			}
			if(arr[strlen(arr)-2]=='0'&&arr[strlen(arr)-2]=='.')
			{
				printf("%d",arr[i]-'0');
			}
			else
			{
				printf("%d.",arr[i]-'0');
			}
			for(int j=i+1;j<strlen(arr);j++)
			{
				if(arr[j]!='.')
				{
					putchar(arr[j]);
				}
			}
			printf("e-%d",i-1);
			
		}
	
	
	
	return 0;
}

