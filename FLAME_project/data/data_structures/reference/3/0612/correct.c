#include<stdio.h>
int main()
{
	char s[1000],a[1000];
	int i,t=0,j=0;
	gets(s);
	if(s[0]=='0')
	{
		for(i=2; s[i]!='\0'; i++)
		{
			if(s[i]=='0')
			{
				t++;
			} 
			else if(s[i]!='.') 
			{
				break; 
			}
		}
		for(i=t+2; s[i]!='\0'; i++)
		{
            a[j]=s[i];
            j++;
		}
		if(a[1]!='\0')
		{
			printf("%c.",a[0]);
			for(j=1; a[j]!='\0'; j++)
			{
				printf("%c",a[j]);
			}
		}
		else
		{
			printf("%c",a[0]);
		}
		printf("e-%d",t+1);
		return 0;
	}
	else
	{
		for(i=0;s[i]!='\0';i++)
		{
			if(s[i]!='.')
			{
				a[j]=s[i];
				j++;
				t++;
			}
			else
			{
				break;
			}
		}
		for(i=t+1;s[i]!='\0';i++)
		{
			a[j]=s[i];
			j++;
		}
		printf("%c.",a[0]);
		for(i=1;a[i]!='\0';i++)
		{
			printf("%c",a[i]);
		}
		printf("e%d",t-1);
		return 0;
	}
}



