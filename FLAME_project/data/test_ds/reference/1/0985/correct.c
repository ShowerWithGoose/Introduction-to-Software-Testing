#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char a[5005];
char b[5005];

int check(int i)
{
	if(i==0||a[i-1]>=a[i+1])
		return 0;
	else if('a'<=a[i-1]&&a[i-1]<='z'&&'a'<=a[i+1]&&a[i+1]<='z')
		return 1;
	else if('A'<=a[i-1]&&a[i-1]<='Z'&&'A'<=a[i+1]&&a[i+1]<='Z')
		return 1;
	else if('0'<=a[i-1]&&a[i-1]<='9'&&'0'<=a[i+1]&&a[i+1]<='9')
		return 1;
	else
		return 0;
}

int main()
{
	scanf("%s",a);
	for(int i=0,k=0;i<strlen(a);i++)
	{
		if(a[i]!='-')
			b[k++]=a[i];
		if(a[i]=='-')
		{
			if(!check(i))
				b[k++]=a[i];
			else
			{
				for(char u=a[i-1]+1;u<a[i+1];u++)
					b[k++]=u;
			}
		}
	}
	printf("%s\n",b);
	return 0;
}

