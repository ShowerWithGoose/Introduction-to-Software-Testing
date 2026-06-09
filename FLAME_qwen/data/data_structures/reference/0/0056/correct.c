#include<stdio.h>
#include<string.h>
char a[1000000];
int main()
{
    gets(a);
    char j;
	int i;
	for(i=0;i<strlen(a);i++)
	{
		if((a[i]>='a'&&a[i]<='z')&&a[i+1]=='-'&&(a[i+2]>='a'&&a[i+2]<='z')&&a[i]<a[i+2])
		{
			for(j=a[i];j<a[i+2];j++)
			{
				printf("%c",j);
			}
			i++;
		}
		else if((a[i]>='A'&&a[i]<='Z')&&a[i+1]=='-'&&(a[i+2]>='A'&&a[i+2]<='Z')&&a[i]<a[i+2])
		{
			for(j=a[i];j<a[i+2];j++)
			{
				printf("%c",j);
			}
			i++;
	    }
	    else if((a[i]>='0'&&a[i]<='9')&&a[i+1]=='-'&&(a[i+2]>='0'&&a[i+2]<='9')&&a[i]<a[i+2])
		{
			for(j=a[i];j<a[i+2];j++)
			{
				printf("%c",j);
			}
			i++;
	    }
	    else 
		printf("%c",a[i]);
	}
	return 0;
}


