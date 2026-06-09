#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	char b[150];
	gets(a);
	int i,j=0;
	int d;
	for(i = 0;i <= strlen(a);i++)
	{
		if(a[i] == '-')
		{
			if(a[i-1] >= 'A'&&a[i-1] < 'Z'&&a[i+1] > 'A'&&a[i+1] <= 'Z'&&a[i-1] < a[i+1])
			{
				for(d = 1;d <= (a[i+1] - a[i-1]);d ++)
				{
					b[j++] = d + a[i-1];
				}
			}
			if(a[i-1] >= 'a'&&a[i-1] < 'z'&&a[i+1] > 'a'&&a[i+1] <= 'z'&&a[i-1] < a[i+1])
			{
				for(d = 1;d <= (a[i+1] - a[i-1]);d ++)
				{
					b[j++] = d + a[i-1];
				}
			}
			if(a[i-1] >= '0'&&a[i-1] < '9'&&a[i+1] > '0'&&a[i+1] <= '9'&&a[i-1] < a[i+1])
			{
				for(d = 1;d <= (a[i+1] - a[i-1]);d ++)
				{
					b[j++] = d + a[i-1];
				}
			}
		
			else if(a[i-1]>=a[i+1]||a[i-1] >= '0'&&a[i-1] <= '9'&&a[i+1] >= 'A'&&a[i+1] <= 'Z'||a[i-1] >= '0'&&a[i-1] <= '9'&&a[i+1] > 'a'&&a[i+1] <= 'z'||a[i-1] >= 'a'&&a[i-1] <= 'z'&&a[i+1] >= 'A'&&a[i+1] <= 'Z')
			{
				b[j++] = a[i];
				i--;
			}
			else if(a[i-1]>a[i+1]||a[i-1] >= 'A'&&a[i-1] <= 'Z'&&a[i+1] >= 'a'&&a[i+1] <= 'z')
			{
				b[j++] = a[i];
				i--;
			}
			else if(a[i-1]!='-' || a[i+1]!='-'||a[i]!='-')
			{
				b[j] = a[i];	
			}
			i++;
		}
		else
		{
			b[j] = a[i];
			j++;
		}	
	}
	puts(b);
	return 0;
}


