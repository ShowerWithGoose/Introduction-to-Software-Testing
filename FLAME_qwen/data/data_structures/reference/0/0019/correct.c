#include<stdio.h>

int main()
{
	char a[150];
	char c,b,d;
	gets(a);
	int i,j;
	for(i = 0;a[i] != '\0';i++)
	{
//		j = a[i+1] - a[i-1];
		if(a[i] != '-')
		{
			printf("%c",a[i]);
		}
		else if(a[i] == '-')
		{
			if(a[i+1]-a[i-1] > 0)
			{
				if(a[i+1] >= 48&&a[i-1] >= 48&&a[i+1] <= 57&&a[i-1] <= 57)
				{
					
					for(c = a[i-1] + 1;c < a[i+1];c++)
						printf("%c",c);
				}
				else if(a[i+1] >= 97&&a[i-1] >= 97&&a[i+1] <= 122&&a[i-1] <= 122)
				{
					
					for(b = a[i-1] + 1;b < a[i+1];b++)
						printf("%c",b);
				}
				else if(a[i+1] >= 65&&a[i-1] >= 65&&a[i+1] <= 90&&a[i-1] <= 90)
				{
					
					for(d = a[i-1] + 1;d < a[i+1];d++)
						printf("%c",d);
				}
				else 
				printf("%c",a[i]);
			}
			
		}
		
	}
	return 0;
}

