#include <stdio.h>
#include <string.h>
#include <ctype.h>
int tellifsame(char a,char b);
void expand(char a,char b);
int main()
{
	char a[1000];
	gets(a);
	int i,j,k;
	int length=strlen(a);
	for(i=0;i<length;i++)
	{
		if(a[i+1]!='-')
			putchar(a[i]);
		else
		{
			if(tellifsame(a[i],a[i+2]))
			{
				expand(a[i],a[i+2]);
				i++;
			}
			else
				putchar(a[i]);
		}
	}
	return 0;
}

int tellifsame(char a,char b)
{
	if(isdigit(a)&&isdigit(b)&&b>a)
		return 1;
	else if(islower(a)&&islower(b)&&b>a)
		return 1;
	else if(isupper(a)&&isupper(b)&&b>a)
		return 1;
	else 
		return 0;
}

void expand(char a,char b)
{
	int i;
	for(i=0;a+i<b;i++)
		printf("%c",a+i);
	return;
}

