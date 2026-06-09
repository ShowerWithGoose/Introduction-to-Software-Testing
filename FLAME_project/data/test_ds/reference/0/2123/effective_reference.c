#include <stdio.h>
#include <math.h>
#include <string.h>
char arr[10000];
void f(char c,char y)
{
	char x=c;
	for(int i=0;i<y-c;i++)
	{
		printf("%c",x+i);
	}
}
int main()
{
	scanf("%s",&arr);
	int n=strlen(arr);
	for(int i=0;i<n;i++)
	{
		if(arr[i+1]=='-'&&arr[i+2]-arr[i]>0&&((arr[i]>='a'&&arr[i+2]<='z')||(arr[i]>='A'&&arr[i+2]<='Z')||(arr[i]>='0'&&arr[i+2]<='9')))
		{
			f(arr[i],arr[i+2]);
			i++;
		}
		else
		{
			printf("%c",arr[i]);
		}
	}
 	return 0;
}




