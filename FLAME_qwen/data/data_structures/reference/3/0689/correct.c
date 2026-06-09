#include<stdio.h>
#include<string.h>
int main()
{
	char str[100],put[100];
	gets(str);
	int i,j=0;
	for(i=1;str[i]!='.';i++)
		j++;
	if(str[0]!='0')
	{
		put[0]=str[0];
		put[1]='.';
		int k=2;
		for(i=1;str[i]!='\0';i++)
		{
			if(str[i]!='.')
			put[k++]=str[i];
		}
		put[k]='\0';
		printf("%se%d",put,j);
	}
	else
	{
		j=0;
		for(i=2;str[i]=='0';i++)
		j++;
		int a=i,b=1;
		put[0]=str[i];
		if(str[i+1]!='\0')
		{
		put[1]='.';
		b=2;
		}
		for(i=a+1;str[i]!='\0';i++)
		put[b++]=str[i];
		put[b]='\0';
		printf("%se%d",put,-j-1);
	}
	return 0;
}

