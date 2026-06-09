#include <stdio.h>
#include <string.h>
int main()
{
	char a[100],f;
	int i=0,g=0;
	while(scanf("%c",&a[i])!=-1)
	{
		if(a[i]=='-')
		{
			scanf("%c",&a[i+1]);
			if((('0'<=a[i-1])&&(a[i-1]<='9'))&&((a[i+1]>='0')&&(a[i+1]<='9'))&&(a[i-1]<a[i+1]))
			{
				f=a[i-1]+1;
				for(g=1;a[i-1]+g<a[i+1];f++)
				{
					printf("%c",f);
					g=g+1; 
				}
				printf("%c",a[i+1]);

				
				
			}
			else if((('a'<=a[i-1])&&(a[i-1]<='z'))&&((a[i+1]>='a')&&(a[i+1]<='z'))&&(a[i-1]<a[i+1]))
			{
				f=a[i-1]+1;
				for(g=1;a[i-1]+g<a[i+1];f++)
				{
					printf("%c",f);
					g=g+1; 
				}
				printf("%c",a[i+1]);
				
				


			}
			else if((('A'<=a[i-1])&&(a[i-1]<='Z'))&&((a[i+1]>='A')&&(a[i+1]<='Z'))&&(a[i-1]<a[i+1]))
			{
				
				f=a[i-1]+1;
				for(g=1;a[i-1]+g<a[i+1];f++)
				{
					printf("%c",f);
					g=g+1; 
				}
				printf("%c",a[i+1]);
				
				

				
			}
			else
			{
			printf("-");
			printf("%c",a[i+1]);
}
			i++;
		}
		else
		printf("%c",a[i]);
		i++;
		
		
		
		
		
		
		
		
		
		
	}
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

