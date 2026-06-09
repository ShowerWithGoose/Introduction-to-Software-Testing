#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
char a[100000];
int i,j;
int main()
{
	gets(a);
	for(i=0;i<strlen(a);i++){
		if(a[i]!='-')
		printf("%c",a[i]);
		else
		{	
		if(a[i-1]>='0'&&a[i+1]>a[i-1]&&a[i+1]<='9')
			for(j=1;j<(a[i+1]-a[i-1]);j++)
			printf("%c",a[i-1]+j); 
		else if(a[i-1]>='a'&&a[i+1]>a[i-1]&&a[i+1]<='z')
			for(j=1;j<(a[i+1]-a[i-1]);j++)
			printf("%c",a[i-1]+j); 
		else if(a[i-1]>='A'&&a[i+1]>a[i-1]&&a[i+1]<='Z')
			for(j=1;j<(a[i+1]-a[i-1]);j++)
			printf("%c",a[i-1]+j);
		else
		printf("%c",a[i]); 
		}
	}
		
return 0;
}


