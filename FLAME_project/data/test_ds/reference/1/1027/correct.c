#include<stdio.h>
#include<string.h>
int main()
{
	int i=0,j=0,a=0;
	char n[102],m[102];
	gets(n);
	for(i=0;n[i]!='\0';i++)
	{
		if(n[i+1]=='-')
		{
			if(n[i]<n[i+2]&&((n[i]>='a'&&n[i+2]<='z')||(n[i]>='A'&&n[i+2]<='Z')||(n[i]>='0'&&n[i+2]<='9')))
			{
				for(j=n[i];j<n[i+2];j++)
				{
					printf("%c",j);
				}
				i++;
			}
			else
			{
			    printf("%c%c",n[i],n[i+1]);i++;
			}
		}
		else
		{
			printf("%c",n[i]);
		}
	}
	return 0;
}

