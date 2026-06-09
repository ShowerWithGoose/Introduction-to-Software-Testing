#include<stdio.h>
#include<string.h>
int main()
{
	char a[50]={0};
	int flag=0;
	scanf("%s",a);
	int i,j,la=strlen(a);
	for(i=1;i<la;i++)
	{
		if(a[i]!='-'&&flag==0)
		{ 
			printf("%c",a[i-1]);
		}
		else if(a[i]=='-')
		{
			flag=1;
			if(a[i-1]>='a'&&a[i-1]<'z'&&a[i+1]>a[i-1]+1&&a[i+1]<='z')//a-z
			{
				char temp;
				for(temp=a[i-1];temp<a[i+1];temp++) printf("%c",temp);
			}
			else if(a[i-1]>='A'&&a[i-1]<'Z'&&a[i+1]>a[i-1]+1&&a[i+1]<='Z')//A-Z
			{
				char temp;
				for(temp=a[i-1];temp<a[i+1];temp++) printf("%c",temp);
			}
			else if(a[i-1]>='0'&&a[i-1]<'9'&&a[i+1]>a[i-1]+1&&a[i+1]<='9')//0-9
			{
				char temp;
				for(temp=a[i-1];temp<a[i+1];temp++) printf("%c",temp);
			}
			else printf("%c%c",a[i-1],a[i]);
			i++;
			flag=0;
		}
	}
	printf("%c\n",a[la-1]); 
	return 0;
} 

