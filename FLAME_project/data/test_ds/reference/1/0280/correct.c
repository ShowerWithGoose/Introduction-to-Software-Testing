#include<stdio.h>
#include<string.h>
int main()
{
	char a[105];
	int x;
	scanf("%s",a);
	int i,j,len,add,numb;
	len=strlen(a);
	for(i=0;i<len;i++)
	{
		if(a[i]=='-')
		{
			
			if(a[i-1]>='a'&&a[i+1]<='z'&&a[i-1]<a[i+1])
			{
				j=i;
				add=a[i+1]-a[i-1];
				for(x=0;x<add-1;x++)
				{
					
					printf("%c",a[i-1]+1+x);
				}
				
			}
			else if(a[i-1]>='A'&&a[i+1]<='Z'&&a[i-1]<a[i+1])
			{
				j=i;
				add=a[i+1]-a[i-1];
				for(x=0;x<add-1;x++)
				{
					
					printf("%c",a[i-1]+1+x);
				}
			}
			else if(a[i-1]>='0'&&a[i+1]<='9'&&a[i-1]<a[i+1])
			{
				j=i;
				add=a[i+1]-a[i-1];
				for(x=0;x<add-1;x++)
				{
					
					printf("%c",a[i-1]+1+x);
				}
				
			}
			else
			{
				printf("-");
			}
		}
		else
		{
		printf("%c",a[i]);	
		}
	}
	
		return 0;
			
			
			
			
			
			
			
					
		
					
} 		
			
			
			
			
			
			
			
			
			
			
		

