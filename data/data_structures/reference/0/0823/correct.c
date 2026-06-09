#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int i,j,len;
	char a[1000],mid;
	scanf("%s",a);
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]!='-')
		{
			printf("%c",a[i]);
			continue;
		}
		else
		{
			if(a[i-1]<='z'&&a[i-1]>='a'&&a[i+1]<='z'&&a[i+1]>='a'&&a[i-1]<a[i+1])
			{
				for(mid=a[i-1]+1;mid<a[i+1];mid++)
				printf("%c",mid);
			}
			else if(a[i-1]<='Z'&&a[i-1]>='A'&&a[i+1]<='Z'&&a[i+1]>='A'&&a[i-1]<a[i+1])
			{
				for(mid=a[i-1]+1;mid<a[i+1];mid++)
				printf("%c",mid);
			}
			else if(a[i-1]<='9'&&a[i-1]>='0'&&a[i+1]<='9'&&a[i+1]>='0'&&a[i-1]<a[i+1])
			{
				for(mid=a[i-1]+1;mid<a[i+1];mid++)
				printf("%c",mid);
			}
			else
			{
				printf("-");
				continue;				
			}	
		}	
	}
	return 0;
}

