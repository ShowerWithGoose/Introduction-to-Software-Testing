#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int i,j,n;
	int flag=0;
	char a[666]; 
	gets(a);
	n=strlen(a);
	for(i=0;i<n;i++)
	{
	
		
		if(a[0]=='0')
		{
			if(a[i]=='0'||a[i]=='.')
			flag++;
			else if(a[i]>='1'&&a[i]<='9')
			{
				if(flag==n-1)
				printf("%c",a[i]);
				else
				printf("%c.",a[i]);
				for(j=i+1;j<n;j++)
				{
				printf("%c",a[j]);
				
				}
				printf("e-%d",flag-1);
				break;
			}
		}
		else
		{
			if(a[i]=='.')
			{
				printf("%c.",a[0]);
				for(j=1;j<i;j++)
				{
					printf("%c",a[j]);
					
				} 
				for(j=i+1;j<n;j++)
				{
					printf("%c",a[j]);
					
				}
				printf("e%d",i-1);
				break;
				
			}
		}
	}
	return 0;		
}

