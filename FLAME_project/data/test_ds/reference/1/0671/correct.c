#include<stdio.h>
#include<string.h>
int f(char *q);
char a[500],answer[500];
int main()
{
	char i;
	scanf("%s",a);
	char *p;
	p=a;
	for(;p<a+strlen(a);p++)
	{
		if(*p=='-'&&f(p))
		{
			for(i=p[-1]+1;i<p[1];i++)
				printf("%c",i);
		}
		else printf("%c",*p);
	}
	return 0;
}
int f(char *q)
{
	if((*(q-1)>='a'&&*(q+1)>='a'&&*(q-1)<='z'&&*(q+1)<='z')||(*(q-1)>='A'&&*(q+1)>='A'&&*(q-1)<='Z'&&*(q+1)<='Z')||(*(q-1)>='0'&&*(q+1)>='0'&&*(q-1)<='9'&&*(q+1)<='9'))
		return 1;
	else return 0;
}



