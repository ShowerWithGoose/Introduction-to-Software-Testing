#include<stdio.h>
#include<string.h>
int i=0,j=0,k=0;
int main()
{
	char str[1000];
	fgets(str,1000,stdin);
	if(str[0]=='0')
	{
		while(str[i+2]=='0')
		i++;
		k=i+1;
		printf("%c",str[i+2]);
		if(str[i+4]!='\0')
		printf("%c",str[1]);
		for(i=k+2;str[i]!='\n';i++)
		{
			printf("%c",str[i]);
		}
		printf("e-%d",k);
	}
	else
	{
		while(str[i]!='.')
		i++;
		k=i;//找小数点的位置为str[k]，以及e的指数 k-1
		printf("%c%c",str[0],str[k]);
		for(i=1;str[i]!='\n';i++)
		{
			if(str[i]=='.')
			continue;
			printf("%c",str[i]);
		}
		printf("e%d",k-1);
	}
	return 0;
 } 



