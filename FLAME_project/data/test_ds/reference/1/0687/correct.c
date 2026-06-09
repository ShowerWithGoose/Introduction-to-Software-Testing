#include <stdio.h>
#include <string.h>
void NewPrintf(char m,char n);
int main()
{
	char a[10000];
	while(gets(a))
	{
		int len=strlen(a);
		for(int i=0;i<len;i++)
		{
			if(a[i]=='-')
			NewPrintf(a[i-1],a[i+1]);
			else
			printf("%c",a[i]);
		}
		putchar(10);
	}
	return 0;
}

void NewPrintf(char m,char n)
{
char o;
if(m>='A'&&m<='Z'&&n>='A'&&n<='Z'&&m<n)
{
for(o=m+1;o<n;o++)
printf("%c",o);
return;
}
else if(m>='a'&&m<='z'&&n>='a'&&n<='z'&&m<n)
{
for(o=m+1;o<n;o++)
printf("%c",o);
return;
}
else if(m>='0'&&m<='9'&&n>='0'&&n<='9'&&m<n)
{
for(o=m+1;o<n;o++)
printf("%c",o);
return;
}
else
{
	printf("-");
	return;
}
}


