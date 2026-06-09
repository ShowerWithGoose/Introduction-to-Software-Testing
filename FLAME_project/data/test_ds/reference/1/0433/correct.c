#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
char a[999];
void out(int i)
{
	int m;
	for(m=1;a[i-1]+m!=a[i+1];m++)
	{
		printf("%c",a[i-1]+m);
	}
	return;
}
int main()
{
	gets(a);
	int i;
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]=='-')
			{
				if(a[i-1]<a[i+1]&&((isdigit(a[i-1])&&isdigit(a[i+1]))||(islower(a[i-1])&&islower(a[i+1]))||(isupper(a[i-1])&&isupper(a[i+1]))))
					out(i);
				else printf("%c",a[i]);	
			}	
		else printf("%c",a[i]);
	}
	return 0;
} 

