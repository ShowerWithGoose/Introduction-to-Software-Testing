#include <stdio.h>
#include <string.h>
char a[10001];
char b[10001];
int main()
{
	scanf("%s",a+1);
	int shuo=strlen(a+1);
	int j=0;
	for(int i=1;i<=shuo;i++)
	{
		if(a[i]=='-')
		{
			if((a[i-1]>='a') && a[i+1]<='z')
			{
				int s=a[i+1]-a[i-1];
				for(int homo=1;homo<=s;homo++)
				{
					b[j]=a[i-1]+homo;
					j++;
				}
				i++;
			}
			else if((a[i-1]>='A') && a[i+1]<='Z')
			{
				int s=a[i+1]-a[i-1];
				for(int homo=1;homo<=s;homo++)
				{
					b[j]=a[i-1]+homo;
					j++;
				}
				i++;
			}
			else if((a[i-1]>='0') && a[i+1]<='9')
			{
				int s=a[i+1]-a[i-1];
				for(int homo=1;homo<=s;homo++)
				{
					b[j]=a[i-1]+homo;
					j++;
				}
				i++;
			}
			else 
			{
				b[j]='-';
				j++;
			}
		}
		else 
		{
			b[j]=a[i];
			j++;
		}
	}
	int homo=strlen(b);
	for(int i=0;i<=homo-1;i++) printf("%c",b[i]);
}

