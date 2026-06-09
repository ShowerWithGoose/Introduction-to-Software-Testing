#include <stdio.h>
char a[1000];
void f1(char*);
void f2(char*);
void f3(char*);
int main()
{
    gets(a);
    int i=0;
    while(a[i++]!='\0')
    {
		if(a[i]=='-')
		{
			if(a[i-1]>='0'&&a[i-1]<='9')
			{
				f1(a+(i-1));
				i=i+1;
			}
			else if(a[i-1]>='a'&&a[i-1]<='z')
			{
				f2(a+(i-1));
				i=i+1;
			}
			else if(a[i-1]>='A'&&a[i-1]<='Z')
			{
				f3(a+(i-1));
				i=i+1;
			}
		}
		else
		{
			printf("%c",a[i-1]);
		}
	}
	return 0;
}
void f1(char *p)
{
	if((*(p+2)>*(p))&&(*(p+2)>='0'&&*(p+2)<='9'))
	{
		char i;
		for(i=*(p);i<*(p+2);i++)
		{
			printf("%c",i);
		}
	}
	else
	{
		printf("%c%c",*(p),'-');
	}
	return;
}
void f2(char *p)
{
	if((*(p+2)>*(p))&&(*(p+2)>='a'&&*(p+2)<='z'))
	{
		char i;
		for(i=*(p);i<*(p+2);i++)
		{
			printf("%c",i);
		}
	}
	else
	{
		printf("%c%c",*(p),'-');
	}
	return;
}
void f3(char *p)
{
	if((*(p+2)>*(p))&&(*(p+2)>='A'&&*(p+2)<='Z'))
	{
		char i;
		for(i=*(p);i<*(p+2);i++)
		{
			printf("%c",i);
		}
	}
	else
	{
		printf("%c%c",*(p),'-');
	}
	return;
}



