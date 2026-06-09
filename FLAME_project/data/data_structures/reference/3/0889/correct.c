#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
	int i;
	char arr[105],*p=NULL;
	scanf("%s",arr);
	if(arr[0]=='0')
	{
		for(i=2;arr[i]=='0';i++)
		;
		p=&arr[i+1];
		if(*p!='\0')
		printf("%c.%se%d\n",arr[i],p,1-i);
		else
		printf("%ce%d\n",arr[i],1-i);
	}
	else
	{
		for(i=1;arr[i]!='.';i++)
		;
		p=&arr[i+1];
		arr[i]='\0';
		char *pa;
		pa=&arr[1];
		printf("%c.%s%se%d",arr[0],pa,p,i-1);
	}
 	return 0;
}




